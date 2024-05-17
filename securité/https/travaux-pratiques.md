---
title: Travaux pratiques
---

### Générer la demande de certificat

```>shell
openssl req -new -sha256 -newkey rsa:2048 -nodes -utf8 -days 70 -keyout https.key -out https.csr
```
2 fichiers générés la clé secrète et la demande de certificat

### Envoyer la demande à une autorité de certification

### Configurer le serveur web

Copier le fichier retourné et la clé dans `/etc/ssl/`

Modifier le fichier de configuration `/etc/nginx/site-available/default`

```apacheconf
server {
  listen   443;
  ssl       on;
  ssl_certificate       /etc/ssl/your_domain_name.pem;
  ssl_certificate_key   /etc/ssl/your_domain_name.key;
```

### LibreSSL

```>shell
libressl ^
req -new -sha256 -nodes -utf8 -newkey rsa:2048 -days 700 ^
-keyout keys\https.key ^
-config https.cnf ^
-out https.csr

```
### Accepter la demande

```>shell
libressl ^
x509 -req -sha256 ^
-in requetes\%1%.csr ^
-CA autorite\autority.crt ^
-CAkey autorite\autority.key ^
-CAcreateserial ^
-extensions v3_req ^
-extfile %1%.extensions.cnf ^
-out certificats\%1%.crt
```

```>shell
libressl req -in https.csr -noout -text
```
