FROM alpine:latest AS build

# Встановлюємо всі необхідні пакети
RUN apk add --no-cache build-base automake autoconf

WORKDIR /home/optima

# Копіюємо всі файли проекту
COPY . .

# Запускаємо autoreconf для створення всіх необхідних файлів
RUN autoreconf -i

# Налаштовуємо проект
RUN ./configure

# Компілюємо проект
RUN make

# Створюємо мінімальний образ для запуску
FROM alpine:latest
COPY --from=build /home/optima/funca /usr/local/bin/funca
ENTRYPOINT ["/usr/local/bin/funca"]
