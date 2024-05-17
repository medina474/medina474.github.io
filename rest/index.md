---
title: API REST
---

Ouvrir un dossier por votre application

Initialiser un dépot git

```>shell
$ git init
```

Créer un fichier `.gitignore`. pour spécifier les dossiers et fichiers qui ne doivent pas être pris en compte par git.

```
package-lock.json
node_modules
```

Initialiser l'application

```
npm init
```

## Environnement

L'environnement permet de spécifier les particularités des différents systèmes où s'executera l'application.
Adresse du serveur de la base de donées, mot de passe.

```>shell
$ npm install --save-dev dotenv
```

Créer à la racine un fichier `.env`

```
PORT=3000
POSTGRES_HOST=192.168.1.30
POSTGRES_PORT=5432
POSTGRES_DB=iutsd
POSTGRES_USER=iutsd
POSTGRES_PASSWORD=***
```

Comme les informations qui y sont stockées sont sensibles et spécifiques à une machine le fichier ne doit surtout pas être inclus dans le dépôt et publié. !

Ajouter dans le fichier .gitignore

```
.env
```

Créer un fichier index.js

```javascript
"use strict";

require('dotenv').config();
```

Lire le paramètre PORT du fichier d'environnement ou affecter 3000 si le paramètre n'existe pas.

```javascript
const port = process.env.PORT || 3000;
```

## Serveur ExpressJS

```>shell
$ npm install --save-dev express
```

Déclarer et démarrer le serveur

```javascript
const express = require('express');
const app = express();

app.listen(port, () => {
  console.log(`Server is running on ${port} port.`);
})
```

Démarrer le serveur

```>shell
$ nodemon index.js
```

## Routes

Ajouter un fichier `main.js`

Déclarer 2 routes sur les méthodes `GET`. Pour chacune des routes retourner le code http 200 (Ok). Pour la première un json contenant un texte et pour la deuxième un texte simple.

```javascript
module.exports = () => {

  const router = require('express').Router();

  router.get('/', async (req, res) => {
    res.status(200).json("Application Cinéma");
  });

  router.get('/version', async (req, res) => {
    res.status(200).send("1.0");
  });

  return router;
}
```

Dans le fichier index.js importer le fichier main et utiliser le avec express à la racine.

```javascript
const main = require("./main");
app.use('/', main());
```

## base de données

```>shell
$ npm install --save-dev pg-promise
```

Ajouter un fichier `db.js` qui gère la connexion à la base de données.

```javascript
require('dotenv').config();

// Empty object {} means no additional config required
const pgp = require('pg-promise')({});

const config = {
  host: process.env.POSTGRES_HOST,
  port: process.env.POSTGRES_PORT,
  database: process.env.POSTGRES_DB,
  user: process.env.POSTGRES_USER,
  password: process.env.POSTGRES_PASSWORD
};

exports.db = pgp(config);
```

```
const { db } = require("./db")
```


Dans un dossier `api` créer un fichier `movie.js`

```javascript
module.exports = (db) => {

  const router = require('express').Router();

  router.get('/', async (req, res) => {
    const data = await db.any("SELECT * from cinema.movie")
    res.status(200).json({ status: 'success', data: data });
  });

  return router;
}
```

Dans Visual Studio Code Ajouter l'extension `REST Client`

Créer un fichier `test.rest`

```
GET http://127.0.0.1:3000/actor/ HTTP/1.1
```

Cliquer sur le lien `send request` au dessus de la ligne

### Route d'ajout

Cette fois ci il va falloir lire les données envoyées par la requête. Cela peut être effectué avec le module body parser.

```>shell
npm install --save body-parser
```

```javascript
const bodyParser = require('body-parser');

app.use(bodyParser.json());
```

```javascript
router.put('/', (req, res) => {

  db.one("insert into cinema.person (firstname, lastname, dob) VALUES ($1, $2, $3) RETURNING id",
  [req.body.firstname, req.body.lastname, req.body.dob])
    .then(function(data) {
      res.status(201).json({ status: 'success', data: data });
    })
    .catch(function(reason) {
      res.status(500).json(reason);
    });
});
```

### Route de suppression

```javascript
router.delete('/:id', (req, res) => {
    db.one("delete from person where id = $1", req.params.id)
      .then(function(data) {
        res.status(200).json({ status: 'success', data: data });
      })
      .catch(function(reason) {
        res.status(500).json(reason);
      })
  });
```


```javascript
const main = require("./main"),
  movie = require('./api/movie');

app.use('/movie', movie(db));
```

Ajouter dans le fichier test.rest

```
###
PUT http://127.0.0.1:3000/actor/ HTTP/1.1
content-type: application/json

{
  "lastname": "Couchard",
  "firstname": "Jean-Luc",
  "dob": "1969-07-14"
}

###
DELETE http://127.0.0.1:3000/actor/e4127954-3cc1-41a5-bff6-a4c5141e85f2 HTTP/1.1

```

## Définition

CRUD
: Create, Retrieve, Update, Delete
