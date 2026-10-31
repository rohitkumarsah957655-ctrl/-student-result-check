
FROM debian:bookworm-slim

RUN apt-get update && \
    apt-get install -y --no-install-recommends apache2 gcc libc6-dev && \
    rm -rf /var/lib/apt/lists/*

RUN a2enmod cgid

COPY index.html /var/www/html/index.html
COPY style.css /var/www/html/style.css
COPY manui.png /var/www/html/manui.png

COPY result.c /tmp/result.c

RUN gcc /tmp/result.c -o /usr/lib/cgi-bin/result.exe && \
    chmod 755 /usr/lib/cgi-bin/result.exe

RUN printf 'Listen 10000\n' > /etc/apache2/ports.conf && \
    sed -i 's/<VirtualHost \*:80>/<VirtualHost *:10000>/' \
    /etc/apache2/sites-available/000-default.conf

EXPOSE 10000

CMD ["apache2ctl", "-D", "FOREGROUND"]
