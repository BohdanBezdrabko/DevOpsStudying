FROM alpine
WORKDIR /home/Desktop/DevOpsStudying
COPY ./funca /home/optima
RUN apk add libstdc++
RUN apk add libc6-compat
ENTRYPOINT ["./funca"]
