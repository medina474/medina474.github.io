---
title: Nginx
---


Installer le [paquet logiciel](/linux/paquet/) `nginx`.

Vérifier le fonctionnement de Nginx

```shell-session
systemctl status nginx
```

Éditer le fichier de configuration de nginx `/etc/nginx/nginx.conf`.

Retirer les protocoles TLSv1 TLSv1.1 qui sont obsolètes en 2020.

```
ssl_protocols  TLSv1.2; # Dropping SSLv3, TLSv1 TLSv1.1 ref: POODLE
```

Les serveurs web actuels sont capables de gérer plusieurs sites web sur une même machine en se basant sur le nom d'hôte.

## site virtuel

Nous n'allons pas acheter des noms de domaines et ne pouvons pas rediriger les communications à l'intérieur de l'IUT.
Pour gérer viruellement plusieurs sites et noms de domaines, nous allons installer une extension Chrome.

Installer l'extension [LiveHosts](https://chrome.google.com/webstore/detail/livehosts/hdpoplemgeaioijkmoebnnjcilfjnjdi) pour Chrome

Ajouter un site client.cinema.org -> 192.168.1.17

Créer un fichier de configuration `/etc/nginx/sites-available/cinema.conf` pour le site

```
server {
  listen 80;
  server_name client.cinema.org;
  root /home/cinema/public_html;
}
```

Activer la configuration en créant un lien de de fichier dans le dossier `sites-enabled`

```shell-session
ln -s /etc/nginx/sites-available/cinema.conf /etc/nginx/sites-enabled/cinema.conf
```

Redémarrer nginx

```shell-session
systemctl restart nginx
```

## Communication sécurisée

Lire le chapitre sur les [certificats](/security/Certificat)

```
server {
  listen 443 ssl http2;
  ssl_certificate /etc/ssl/cinema.cert;
  ssl_certificate_key /etc/ssl/cinema.key;
  ssl_stapling on;

#  server_name client.cinema.org;
#  root /home/cinema/public_html;
}
```

### Proxy vers l'application NodeJS

```
location /api/ {
  proxy_set_header   X-Forwarded-For $remote_addr;
  proxy_set_header   Host $http_host;
  proxy_pass         http://127.0.0.1:3000;
}
```


### Rediriger de façon permanente les connexion non sécurisée vers la version sécurisée avec TLS

```
rewrite ^ https://client.cinema.org$request_uri? permanent;
```

## Liste de contrôle

|application|commande|version|
|-|-|-|
|nginx|nginx -v|1.14.2


https://www.nginx.com/blog/deploying-nginx-plus-as-an-api-gateway-part-1/
