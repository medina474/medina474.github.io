---
title: HTTPS
---

**Secure Sockets Layer (SSL)**, et son successeur **Transport Layer Security (TLS)**, sont des protocoles de sécurisation des échanges sur Internet. Le protocole SSL a été développé à l'origine par Netscape. L'IETF (_Internet Engineering Task Force_) en a poursuivi le développement en le rebaptisant Transport Layer Security (TLS). On parle parfois de SSL/TLS pour désigner indifféremment SSL ou TLS.

## Protocole SSL

SSL 2.0 est la première version parue, elle possédait un certain nombre de défauts de sécurité, parmi lesquels la possibilité de forcer l'utilisation d'algorithmes de chiffrement plus faibles, ou bien une absence de protection pour la prise de contact et la possibilité pour un attaquant d'exécuter des attaques par troncature. Les protocoles PCT 1.0, puis SSL 3.0, furent développés pour résoudre la majeure partie de ces problèmes, SSL 3.0 devenant rapidement le protocole le plus populaire pour sécuriser les échanges sur Internet.

- **SSL 1.0**. Cette première spécification du protocole développé en 1994 par Netscape resta théorique et ne fut jamais mise en œuvre.
- La première version de SSL réellement utilisée est la **2.0** publiée en 1995. Elle fût également la première implémentation de SSL bannie, en 2011.
-Novembre 1996 : **SSL 3.0**, la dernière version de SSL, qui inspirera son successeur TLS. Ses spécifications sont rééditées en août 2008. Le protocole est banni en 2014, à la suite de la publication de la faille _POODLE_.

> Le SSL n’est théoriquement plus utilisé car toutes ses versions sont bannies, néanmoins le mot reste d’usage dans le langage courant.

## Missions

Le protocole SSL/TLS a plusieurs missions :

>Garantir la **confidentialité** des données échangées\
Assurer l'**intégrité** de ces données\
**Authentifier** le serveur\
Optionnellement authentifier le client via l'utilisation d'un certificat numérique

Le protocole SSL crée un canal de communication entre le client et le serveur **indépendamment du protocole** utilisé, il sécurise ainsi les transactions sur le web (protocole HTTP) ou les connexions via protocole FTP, IMAP ou POP, etc...

Ce canal de communication est un **tunnel opaque** qui empêche quiconque de voir ce qui y transite.

Il fonctionne sur l'établissement de clés privées et publiques qui s'apparentent à l'utilisation d'une serrure et de sa clé :
- La clé privée est enregistrée sur le serveur et connue de lui seul.
- La clé publique, connue de tous, crypte les données à envoyer, qui, une fois réceptionnées par le serveur, sont décryptées au moyen de la clé privée.
- La clé publique est authentifiée par une **autorité de certification** par le biais du certificat.

## Travaux pratiques

### Préparer la demande


```shell-session
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



```shell-session
libressl ^
req -new -sha256 -nodes -utf8 -newkey rsa:2048 -days 700 ^
-keyout keys\https.key ^
-config https.cnf ^
-out https.csr

```
### Accepter la demande

```shell-session
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

```shell-session
libressl req -in https.csr -noout -text
```

CA
: Certificate Authority ou Autorité de certification. Agence notariale reconnue pour son honnêteté et sa rigueur.

CSR
: Certificate Signing Request. C'est un fichier de demande de certificat. Il est envoyé aux autorités de certification. Cette demande signée par l'autorité revient sous forme de certificat.

.key
: Fichier pem contenant uniquement la clé privée.
