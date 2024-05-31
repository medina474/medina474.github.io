---
title: Symfony
---

curl https://get.symfony.com/cli/installer | bash
mv /root/.symfony5/bin/symfony /usr/local/bin/symfony

apt install --no-install-recommends php8.2-xml

Warning
apt install --no-install-recommends php8.2-mbstring
apt install --no-install-recommends php8.2-intl
apt install --no-install-recommends php8.2-mysql
apt install --no-install-recommends php8.2-zip


symfony check:requirements

symfony new jardins --webapp

cd jardins

php bin/console about

### CA

symfony server:ca:install


curl.cainfo="C:\Users\user\.symfony5\certs\rootCA.pem"
openssl.cafile="C:\Users\user\.symfony5\certs\rootCA.pem"

symfony server:start

php bin/console debug:router

### Home
symfony console make:controller HomeController

#### tailwindcss

https://tailwindcss.com/docs/guides/symfony

composer require symfonycasts/tailwind-bundle
php bin/console tailwind:init

php bin/console tailwind:build --watch

### Sécurité

https://symfony.com/doc/current/security.html

composer require symfony/security-bundle
php bin/console make:user

php bin/console make:entity
User
Ajouter email ascii_string
firstName
lastName

changer le fichier .env

php bin/console make:migration
php bin/console doctrine:migrations:migrate

composer require symfonycasts/verify-email-bundle
php bin/console make:registration-form




php bin/console make:security:form-login

composer require symfony/rate-limiter
