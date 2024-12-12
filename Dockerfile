FROM alpine
WORKDIR /home/optima
COPY ./function .
RUN apk add libstdc++
RUN apk add libc6-compat
ENTRYPOINT ["./function"]
