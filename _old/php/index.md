---
title: PHP
---

Installer le [paquet logiciel](/linux/paquet/) php-8


curl https://packages.sury.org/php/apt.gpg -o /usr/share/keyrings/deb.sury.org-php.gpg
echo "deb [signed-by=/usr/share/keyrings/deb.sury.org-php.gpg] https://packages.sury.org/php/ $(lsb_release -sc) main" > /etc/apt/sources.list.d/php-sury.list
apt update

apt install php8.2
apt install libapache2-mod-php

https://vsys.host/how-to/how-to-install-php-8-2-7-4-5-6-on-debian-11

### Composer

php -r "copy('https://getcomposer.org/installer', 'composer-setup.php');"
php -r "if (hash_file('sha384', 'composer-setup.php') === 'dac665fdc30fdd8ec78b38b9800061b4150413ff2e3b6f88543c636f7cd84f6db9189d43a81e5503cda447da73c7e5b6') { echo 'Installer verified'; } else { echo 'Installer corrupt'; unlink('composer-setup.php'); } echo PHP_EOL;"
php composer-setup.php
php -r "unlink('composer-setup.php');"

mv composer.phar /usr/local/bin/composer

## Laravel

apt install --no-install unzip
apt install --no-install-recommends php-xml
apt install --no-install-recommends php-curl

https://www.phptutorial.net/php-tutorial/php-remember-me/
  https://paragonie.com/blog/2015/04/secure-authentication-php-with-long-term-persistence
