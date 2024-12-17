#!/bin/bash

# Docker image name
IMAGE="bohdanbezdrabko/httpserver"

# Container names
SRV1="srv1"
SRV2="srv2"
SRV3="srv3"

# CPU cores
CORE0="0"
CORE1="1"
CORE2="2"

# Thresholds for idle and busy checks
BUSY_THRESHOLD=50        # CPU usage percentage
IDLE_THRESHOLD=10
CHECK_INTERVAL=10        # Interval for checks (in seconds)
CONSECUTIVE_COUNT=2      # Consecutive checks count to confirm state
UPDATE_INTERVAL=600      # Update interval in seconds (10 minutes)

# Function to monitor CPU usage of a container
check_container_cpu() {
    local container_name=$1
    docker stats --no-stream --format "{{.CPUPerc}}" "$container_name" | tr -d '%' || echo "0"
}

# Function to update containers with the new image
update_containers() {
    echo "Checking for updates..."
    docker pull "$IMAGE"

    for container in $SRV1 $SRV2 $SRV3; do
        if docker ps | grep -q "$container"; then
            echo "Updating $container..."
            TEMP_CONTAINER="${container}_temp"
            docker run -d --name "$TEMP_CONTAINER" --cpuset-cpus="${!container^^_CORE}" "$IMAGE"

            docker stop "$container"
            docker rm "$container"
            docker rename "$TEMP_CONTAINER" "$container"
            echo "$container updated successfully."
        fi
    done
    echo "Containers updated successfully."
}

# Start srv1 on CPU core 0
echo "Starting $SRV1 on core $CORE0..."
docker run -d --name "$SRV1" --cpuset-cpus="$CORE0" "$IMAGE"

# Counters for busy and idle states
busy_srv1=0
busy_srv2=0
idle_srv2=0
idle_srv3=0
last_update_time=$(date +%s)

while true; do
    current_time=$(date +%s)

    # Monitor srv1
    if docker ps | grep -q "$SRV1"; then
        cpu_srv1=$(check_container_cpu "$SRV1")
        echo "CPU usage of $SRV1: $cpu_srv1%"

        if (( $(echo "$cpu_srv1 > $BUSY_THRESHOLD" | bc -l) )); then
            ((busy_srv1++))
            idle_srv2=0
            echo "$SRV1 is busy for $busy_srv1 consecutive checks."

            if [[ $busy_srv1 -ge $CONSECUTIVE_COUNT && ! $(docker ps -q -f name=$SRV2) ]]; then
                echo "Starting $SRV2 on core $CORE1..."
                docker run -d --name "$SRV2" --cpuset-cpus="$CORE1" "$IMAGE"
            fi
        else
            busy_srv1=0
        fi
    fi

    # Monitor srv2
    if docker ps | grep -q "$SRV2"; then
        cpu_srv2=$(check_container_cpu "$SRV2")
        echo "CPU usage of $SRV2: $cpu_srv2%"

        if (( $(echo "$cpu_srv2 > $BUSY_THRESHOLD" | bc -l) )); then
            ((busy_srv2++))
            idle_srv3=0
            echo "$SRV2 is busy for $busy_srv2 consecutive checks."

            if [[ $busy_srv2 -ge $CONSECUTIVE_COUNT && ! $(docker ps -q -f name=$SRV3) ]]; then
                echo "Starting $SRV3 on core $CORE2..."
                docker run -d --name "$SRV3" --cpuset-cpus="$CORE2" "$IMAGE"
            fi
        else
            busy_srv2=0
            ((idle_srv2++))
            if [[ $idle_srv2 -ge $CONSECUTIVE_COUNT && $(docker ps -q -f name=$SRV3) ]]; then
                echo "Stopping $SRV3 as $SRV2 is idle."
                docker stop "$SRV3"
                docker rm "$SRV3"
            fi
        fi
    fi

    # Monitor srv3 for idleness
    if docker ps | grep -q "$SRV3"; then
        cpu_srv3=$(check_container_cpu "$SRV3")
        echo "CPU usage of $SRV3: $cpu_srv3%"

        if (( $(echo "$cpu_srv3 < $IDLE_THRESHOLD" | bc -l) )); then
            ((idle_srv3++))
            if [[ $idle_srv3 -ge $CONSECUTIVE_COUNT ]]; then
                echo "Stopping $SRV3 as it is idle."
                docker stop "$SRV3"
                docker rm "$SRV3"
            fi
        else
            idle_srv3=0
        fi
    fi

    # Check for updates every 10 minutes
    if (( current_time - last_update_time >= UPDATE_INTERVAL )); then
        update_containers
        last_update_time=$(date +%s)
    fi

    sleep "$CHECK_INTERVAL"
done
