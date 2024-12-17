#!/bin/bash

# Infinite loop to make HTTP requests
while true; do
    # Generate a random number between 3 and 5 (seconds)
    sleep_time=$((RANDOM % 3 + 3))

    # Display sleep time for debugging
    echo "Waiting $sleep_time seconds before the next request..."

    # Sleep for the generated random time
    sleep $sleep_time

    # Perform an HTTP GET request asynchronously
    curl -i -X GET "127.0.0.1/compute" &

    # Print status after starting the request
    echo "HTTP GET request sent asynchronously."
done
