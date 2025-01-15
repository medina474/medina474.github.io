---
title: Installation de MongoDB
---

## Installation

Ajouter la clé gpg  `https://www.mongodb.org/static/pgp/server-4.4.asc`dans le porte-clé du système.

```shell
wget -qO /usr/local/share/keyrings/mongodb-org-4_4.asc https://www.mongodb.org/static/pgp/server-4.4.asc
```

```shell
echo "deb [arch=amd64,arm64 signed-by=/usr/local/share/keyrings/mongodb-org-4_4.asc] https://repo.mongodb.org/apt/ubuntu focal/mongodb-org/4.4 multiverse" | sudo tee /etc/apt/sources.list.d/mongodb-org-4.4.list
```

```shell
apt update
```

Installer le [paquet logiciel](/linux/paquet/) `mongodb-org-server`.

paquet mongodb-org pour l'ensemble des outils client/serveur


service mongod

Si accès depuis l'extérieur
[Éditer](/linux/nano) le fichier de configuration `/etc/mongod.conf` pour écouter sur toutes les interfaces réseau 0.0.0.0

mongod 	Le serveur de base de données MongoDB
mongo 	Client. Permet d’exécuter toutes les commandes Mongo depuis un Shell
mongostat, mongotop 	Utilitaires de monitoring
mongodump, mongorestore, mongoexport, mongoimport 	Utilitaires d’import / export
bsondump, mongofiles, mongooplog, mongoperf 	Utilitaires divers
