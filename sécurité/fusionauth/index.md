---
title: FusionAuth
---

> FusionAuth est une solution permettant de gérer l'identification des clients.


Installer FusionAuth sur votre PC à l'intérieur d'un conteneur Docker

```shell
curl -o docker-compose.yml https://raw.githubusercontent.com/FusionAuth/fusionauth-containers/master/docker/fusionauth/docker-compose.yml && curl -o .env https://raw.githubusercontent.com/FusionAuth/fusionauth-containers/master/docker/fusionauth/.env
```

```shell
docker-compose up -d
```

```shell
docker ps -a
```

Nous avons en fait 2 conteneurs. Un avec PostgreSql pour la base de données et l'autre pour la solution FusionAuth.
Notez le port d'écoute et ouvrir un navigateur à cette adresse.

http://127.0.0.1:9011/

Renseigner les informations pour la création du compte administrateur et accepter la licence.

## Tenant

Changer le nom du tenant.

Créer une clé dans Settings / Key master

## Application

Créer une application : Cinema

Créer 3 roles : manager, employé et utilisateur

## Ajouter des utilisateurs

En vous servant d'un générateur d'identité ajouter une dizaine d'utilisateurs
https://fr.fakenamegenerator.com/

Ajouter les utilisateurs à l'application Cinema en utilisant les 3 rôles.

## JWT

Activer JWT pour l'application Cinema

Désactiver API Key

Créer un fichier pour tester le login

```http
POST http://127.0.0.1:9011/api/login
content-type: application/json
Authorization: API Token

{
  "loginId": "aeinstein",
  "password": "supermotdepasse",
  "applicationId": "1d0e4a7b-27d5-4751-b530-3146726c934d",
  "noJWT" : false
}
```

Vérifier le token sur https://jwt.io/

### Application serveur

Installer ***jsonwebtoken***

```javascript
var jwt = require('jsonwebtoken');
```

```javascript
var cert = fs.readFileSync('public.pem');  // get public key
jwt.verify(token, cert, function(err, decoded) {
  console.log(decoded.foo) // bar
});
```

tester la validité du jeton, renvoyer un code 401 ou poursuivre le traitement
