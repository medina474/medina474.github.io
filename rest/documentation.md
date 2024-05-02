---
title: Documentation
---

```shell-session
$ npm install --save swagger-ui-express
$ npm install --save yamljs
```

``` javascript
const YAML = require('yamljs');

const swaggerUI = require('swagger-ui-express');
const swaggerDocument = YAML.load('./swagger.yaml');
```

``` javascript
app.use('/api-docs', swaggerUI.serve, swaggerUI.setup(swaggerDocument));
```

description du service dans le fichier swagger.yaml

``` yaml
openapi: 3.0.1
info:
  title: Cinema
  description: 'Application pour trouver des séances de vos films préférés'
  contact:
    email: emmanuel.medina@univ-lorraine.fr
  version: 1.0.0
servers:
- url: http://192.168.1.16:3000

tags:
- name: acteur
  description: Personne travaillant dans des films

paths:
  /actor:
    get:
      tags:
      - acteur
      summary: Liste des acteurs
      responses:
        200:
          description: successful operation
          content:
            application/json:
              schema:
                type: array
                items:
                  $ref: '#/components/schemas/Acteur'
components:
  schemas:
    Acteur:
      required:
      - lastname
      type: object
      properties:
        id:
          type: integer
          format: int64
        lastname:
          type: string
          example: Stallone
        firstname:
          type: string
          example: Sylvester
        naissance:
          type: datetime
```

Il est possible d'écrire la définition des méthodes dans un commentaire de documentation avant chaque méthode. Un outil se charge concatener tous les commentaires trouvés dans un fichier final.

Installer l'outil en global avec l'utilisateur root

```shell-session
npm install swagger-jsdoc --save
```

Lancer la commande pour générer le fichier swagger.yaml à partir des fichier *.js trouvés dans le dossier api.

```shell-session
node node_modules/swagger-jsdoc/bin/swagger-jsdoc.js -d swagger.yaml api/*.js
```
