---
title: CouchDB
---

> CouchDB est un système de gestion de bases de données NoSQL, **orienté document**, développé par la fondation Apache. Il stocke les données sous forme de documents JSON et offre une architecture distribuée, conçue pour être tolérante aux pannes et hautement disponible. 

### Stockage de documents JSON

Les données sont stockées sous forme de documents au format JSON, ce qui permet de représenter des structures complexes et de stocker des informations non structurées.

### API RESTful

CouchDB expose une interface HTTP, permettant d’interagir avec la base de données via des requêtes HTTP standard (GET, POST, PUT, DELETE). Chaque document peut être accédé directement par son URL.

### Replication et synchronisation

CouchDB est conçu pour fonctionner dans des environnements distribués. Il prend en charge la réplication bidirectionnelle entre différents serveurs CouchDB, permettant la synchronisation des bases de données à travers plusieurs machines ou centres de données. l'architecture et de type "multi-maîtres", où chaque instance peut lire et écrire des données. Cela permet de maintenir des copies synchronisées dans différents endroits, avec une tolérance aux défaillances.

### ACID

Contrairement à d'autres bases NoSQL, CouchDB est conforme aux propriétés ACID (Atomicité, Cohérence, Isolation, Durabilité) pour les transactions à l'échelle d’un seul document.

### Gestion des conflits

Lors de la réplication, s'il y a des conflits entre différentes versions d'un même document, CouchDB garde les versions en conflit et permet à l'utilisateur de les résoudre manuellement.

### Mobile

Il existe des solutions adaptées pour le contexte mobile. 

#### Couchbase Lite

Couchbase Lite est une base de données NoSQL embarquée pour les appareils mobiles (iOS, Android) et les ordinateurs de bureau, qui est basée sur la technologie CouchDB.

Elle fonctionne de manière autonome sur l'appareil mobile, permettant de stocker des données localement sous forme de documents JSON.

Synchronisation automatique : Couchbase Lite peut être synchronisée avec un serveur CouchDB ou Couchbase Server via Sync Gateway, permettant une synchronisation bidirectionnelle. Cela est particulièrement utile pour les applications mobiles fonctionnant en mode hors ligne et nécessitant une mise à jour des données une fois la connexion rétablie.

#### PouchDB

PouchDB est une base de données JavaScript qui fonctionne dans le navigateur ou sur mobile. Elle est compatible avec CouchDB et peut synchroniser les données avec une instance CouchDB distante.

Vous pouvez utiliser PouchDB dans une application mobile (via un framework comme Cordova ou Ionic, ou même dans des Progressive Web Apps) pour stocker des données localement et les synchroniser avec CouchDB lorsque l'appareil est en ligne.

Exercice

Ajouter un conteneur CouchDB à votre composition Docker

```yml
  couchdb:
    container_name: r5a10-couchdb
    image: couchdb:${COUCH_DB_VERSION:-3.3}
    environment:
      COUCHDB_PASSWORD: ${DB_ROOT_PASSWORD}
      COUCHDB_USER: ${COUCHDB_USER:-admin}
    volumes:
      - couchdb:/opt/couchdb/data
    ports:
      - 3007:5984
```

```http
@p={{$dotenv DB_ROOT_PASSWORD}}
@baseUrl = http://admin:{{p}}@localhost:3007

### Welcome
GET {{baseUrl}}
```

### Ajouter une base
```http
PUT {{baseUrl}}/clients
```

### Ajouter un document
```http
POST {{baseUrl}}/clients
Content-Type: application/json

{ 
  "Nom": "Einstein",
  "Prenom": "Albert",
  "Adresse": {
    "voie": "3 rue de l'Atome",
    "codepostal": "65650",
    "ville": "Zurich",
    "pays": "Suisse"
  }
}
```

### CHERCHER
```
POST {{baseUrl}}/clients/_find
Content-Type: application/json

{
    "selector": {
        "Nom" : { "$eq": "Einstein" }
    },
    "fields": ["_id", "Nom", "Prenom"]
}
```

```
###
PUT {{baseUrl}}/velo
```

```
### Ajouter un document
POST {{baseUrl}}/velo
Content-Type: application/json

< 2488980.json
```

```
### Lister les documents
GET {{baseUrl}}/velo/_all_docs
```

### CHERCHER les vélos dont une des offres est inférieure à 3000 €

``` http
POST {{baseUrl}}/velo/_find
Content-Type: application/json

{
  "selector": {
    "offres" : { 
      "$elemMatch" : 
          { 
            "prix": {
                "$lt": 3000
            } 
          }
      }
  },
  "fields": ["_id", "name"]
}
``` 
