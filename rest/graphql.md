---
title: GraphQL
---

## Définitions

Over-fetching 
: Fait de récupérer trop d'information, lors d'un appel à une API.

Under-fetching
: Fait de récupérer trop peu d'information, lors d'un appel à une API. Ce qui oblige à effectuer des appels supplémentaires. 


GraphQL (Graph Query Language) est un langage de requêtes créé par Facebook en 2012. C'est une alternative auw Web Services REST. Le client définit dans la requête la structure de données qu'il veut que le serveur leui envoi. Ce langage évite les problèmes de retour de données insuffisants (under-fetching) ou surnuméraires (over-fetching). 

## Exercice

Installer les dépendances au projet avec npm install

- dotenv : lecture des paramètres du fichier .env
- pg-promise : pilote asynchrone pour la base de données PostgreSQL
- express : framework pour appllications web.
- graphql : moteur de requêtes GraphQL.
- graphql-tools : outils pour GraphQL.
- express-graphql : extension GraphQL pour Express.


```js
const { graphqlHTTP } = require("express-graphql");
const { makeExecutableSchema } = require("graphql-tools");
const { typeDefs, resolvers } = require("./queries");

const schema = makeExecutableSchema({ typeDefs: typeDefs, resolvers: resolvers });

app.use('/graphql', graphqlHTTP({
  schema: schema,
  graphiql: true
}));
```

Dans le fichier `queries.js` définir 2 objets à exporter : 
-typeDefs un texte contenant la description de l'ensemble du service
-resolvers un objet comprenant un ensemble de fonctions qui vont résoudre les requêtes.

### La définition des données

- Déclarer les types correspondants aux objets de la base de données.
- Déclarer l'objet Query racine qui comportent les requêtes que l'on peut faire

```js
exports.typeDefs = `

scalar Date

type Movie {
  id: ID!,
  title: String!,
  year: Int,
  actors: [Actor]
}

type Query {
  version: String,
  movie( id: String!): Movie,
  movies: [Movie],
  actor( id: String!): Actor,
  actors (nb: Int): [Actor!],
}
```

### Les resolvers

Liste des acteurs


```js
exports.resolvers = {

  Date: DateType,

  Query: {
    version: () => 'Cinema 1.0',

    actors: (obj, args) => {

      let query = `SELECT * from actor ORDER BY movie_count desc`;
      
      return db
        .manyOrNone(query)
        .then(res => res)
        .catch(err => err);
    },
```

Ajouter un pamètre à la requête, pour limiter le nombre d'enregistrements en retour.

```
if (args && args.nb) {
  query += ` LIMIT ${args.nb}`
}
```

### Les modifications

Dans la définition

```
type Mutation {
  addActor (firstname: String, lastname: String, dob: Date): Actor
}
```

Dans le resolver

```javascript
 Mutation: {
    addActor: (obj, args) => {

      const query = `INSERT INTO cinema.person (firstname, lastname, dob) VALUES ($1, $2, $3) RETURNING *`;
      const values = [args.firstname, args.lastname, args.dob];

      return db.one(query, values)
        .then(res => res)
        .catch(err => err);
    }
  }
```


## PostGraphile

PostGraphile est une solution qui détecte automatiquement les tables, les colonnes, les relations, les vues d'une base de données Posgresql. Elle expose ensuite ces éléments dans un service GraphQL. 

```shell-session
npx postgraphile -c 'postgres://musique:rJ0NARPxpZQyilfovnHlKxf0@localhost/192.168.1.20' --watch --enhance-graphiql --dynamic-json
```

## Liens externes

- [Une API GraphQL de zéro en NodeJS](https://medium.com/wecraftapps/une-api-graphql-de-z%C3%A9ro-en-nodejs-8396dc652fb4)
- [Rest or GraphQL ? That is the question …](https://www.peaks.fr/fr/community/rest-or-graphql-that-is-the-question/)
- [Sources](https://gitlab.com/lpamio-webservice/graphql-server) complète du TP.
