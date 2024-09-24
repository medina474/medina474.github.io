---
title: MongoDB
---

MongoDB est une base de données orientée document. Contrairement à une base de données relationnelle classique dans laquelle les données sont organisées d’après un schéma (tables, champs, types de données) et mises en relation les unes avec les autres, on stocke les données dans une base MongoDB dans un document dans le style [JSON](../../cours/json), c’est à dire sous la forme clé:valeur, tableaux, objets et sous-objets.

## Wire Protocol

Le protocole Wire de MongoDB, souvent appelé simplement le Wire Protocol, est le protocole de communication natif utilisé par MongoDB pour l'interaction entre un client (comme un driver MongoDB) et un serveur MongoDB. Il définit comment les commandes et les requêtes sont envoyées au serveur MongoDB et comment les réponses sont renvoyées au client. Le protocole Wire est basé sur un échange de messages au **format binaire**, conçu pour permettre une communication rapide et efficace entre clients et serveurs.

Il faut obligatoirement une librairie spécialisée pour communiquer.

## MongoSH

mongosh (MongoDB Shell) est un outil en ligne de commande fourni par MongoDB pour interagir directement avec les bases de données MongoDB. Il permet aux développeurs et administrateurs de base de données de se connecter à une instance MongoDB (locale ou distante) et d'exécuter des commandes pour gérer, interroger, et manipuler les données.

Interface interactive : mongosh vous permet de taper des commandes MongoDB et d'obtenir des réponses immédiates dans le shell.

Support de JavaScript : Comme MongoDB utilise une syntaxe proche de JavaScript pour ses requêtes, mongosh vous permet d'exécuter des commandes en JavaScript, ce qui est utile pour effectuer des requêtes complexes ou automatiser certaines tâches.

Administration et gestion des bases : Vous pouvez lister, créer, supprimer des bases de données et collections, ainsi qu’inspecter et modifier les documents stockés.

Connexions locales ou distantes : Vous pouvez l'utiliser pour vous connecter à une instance MongoDB locale ou à des services dans le cloud comme MongoDB Atlas.

Télécharger mongosh : https://www.mongodb.com/try/download/shell

```bash
mongosh "mongodb://admin:supermotdepasse@127.0.0.1:27017"

test>
```

Par défaut vous vous trouvez sur la base de données test

## BSON

Le BSON (Binary JSON) est un format de sérialisation binaire utilisé par MongoDB pour stocker et échanger des données. Il est conçu pour représenter des documents de manière efficace en termes d'espace et de temps de traitement. Bien qu'il soit inspiré du format JSON (JavaScript Object Notation), il est optimisé pour des performances accrues et pour prendre en charge des types de données supplémentaires qui ne sont pas nativement pris en charge par JSON.

**Binaire** et compact : Contrairement à JSON qui est un format textuel, BSON est un format binaire, ce qui le rend plus compact et plus rapide à lire et à écrire pour les machines.

Types de données supplémentaires : BSON supporte des types de données non pris en charge par JSON, tels que :

- Dates : Représentées comme des nombres de millisecondes depuis l'époque Unix.
- ObjectId : Un identifiant unique utilisé par MongoDB pour les documents.
- Entiers 32 bits et 64 bits : Pour représenter les valeurs numériques plus efficacement.
- Données binaires : Stockage de données brutes comme des fichiers ou des images.
- Boolean, null, arrays, embedded documents : Également pris en charge comme en JSON.

Optimisé pour MongoDB : BSON est spécifiquement conçu pour être utilisé avec MongoDB. Il permet un accès rapide aux documents et aux champs dans une base de données, tout en minimisant la taille des documents lorsqu'ils sont stockés ou transférés sur le réseau.

Hiérarchique : Tout comme JSON, BSON permet de stocker des documents hiérarchiques, avec des documents imbriqués (documents dans des documents).

## Commandes

### Créer une base de données

La commande `use` permet de sélectionner une base de données MongoDB déjà existante ou de créer une base de données si elle n'existe pas.

```javascript
use mabasededonnees
```

La commande db affiche quelle base de données est sélectionnée.

```javascript
db
```

Lister les bases de données 

```javascript
show dbs
```

###  Créer une collection

L’étape suivante consiste à créer une première collection, c’est-à-dire un dossier pour vos différents documents BSON, dans lequel les données seront enregistrées ultérieurement. La syntaxe de base ressemble à ceci :

```
db.createCollection(<name>, { options } )
```

La commande create compte deux paramètres. Tout d’abord, le paramètre name (nom de la collection) et options (options pour configurer la collection). 

Dans les options, vous pouvez définir par exemple si les documents d’une collection doivent posséder une taille précise (capped: true) ou s’ils doivent avoir une quantité restreinte de Bytes (size: <number>) ou encore une quantité limitée de documents (max: <number>). Une collection nommée macollection, une limitation à 6.142.800 Bytes et un maximum de 10 000 documents seraient définis à titre d’exemple avec la commande suivante :

```
db.createCollection ("macollection", { capped: true,
  size: 6142800,
  max: 10000 
} )
```

### Ajouter des documents dans la collection

Après création du dossier, vous pouvez y insérer des documents. Trois méthodes différentes sont à votre disposition : insertOne(), insertMany() et  insert()

Les commandes vous permettent d’insérer un seul document (.insertOne), plusieurs documents (.insertMany) ou un ou plusieurs documents (.insert). L’exemple suivant permet un simple ajout dans la base de données qui regroupe trois informations (nom, âge, sexe) et s’effectue dans le dossier macollection de l’étape 5 :

```javascript
db.macollection.insertOne(
  {
    Nom: "Albert",
    Age: 28,
    Sexe: "masculin"
  }
)
```

MongoDB crée automatiquement une collection avec un identifiant unique. Cet identifiant est strictement incremental.

### Recherche

La recherche s'effectue avec la commande find. Le paramètre optionnel query filter (filtre de recherche) et projection (spécification des résultats d’affichage) peuvent être également utilisés.

La commande findOne() retourne un seul document qui correspond à la requête. Si plusieurs documents correspondent, MongoDB renverra le premier trouvé en fonction de l'ordre d'insertion.

```javascript
db.macollection.find( { Nom: "Name", Age: 28 } )
```

### Pipline d'aggrégation

Le pipeline d'agrégation dans MongoDB est une fonctionnalité puissante pour effectuer des opérations de traitement de données complexes directement dans la base de données. C'est souvent l'alternative recommandée à MapReduce en raison de sa performance et de sa flexibilité.

Le pipeline d'agrégation fonctionne en plusieurs étapes, où chaque étape applique une opération spécifique sur les documents, et passe les résultats à l'étape suivante. Ces étapes peuvent filtrer, trier, regrouper, transformer les données, etc.

Un pipeline d'agrégation est constitué de plusieurs étapes sous la forme d'un tableau d'objets. Chaque étape applique une opération particulière.

```javascript
db.collection.aggregate([
   { stage1: {...} },
   { stage2: {...} },
   ...
])
```

$match : Filtre les documents selon des critères (équivalent de find()).

$group : Regroupe les documents par clé(s) et effectue des calculs agrégés sur chaque groupe.

$project : Restructure les documents, en choisissant quels champs inclure/exclure, ou en créant de nouveaux champs.

$sort : Trie les documents selon un ou plusieurs critères.

$limit : Limite le nombre de documents renvoyés.

$skip : Ignore un nombre défini de documents avant de renvoyer le reste.

$lookup : Effectue des jointures entre collections.

$unwind : Décompose un tableau en plusieurs documents, un pour chaque élément du tableau.

```javascript
db.sales.aggregate([
   {
      $match: {
         date: { $gte: ISODate("2023-09-01") }
      }
   },
   {
      $group: {
         _id: "$product", // Grouper par produit
         totalSales: { $sum: { $multiply: ["$quantity", "$price"] } }, // Calculer la somme des ventes
         totalQuantity: { $sum: "$quantity" } // Calculer la quantité totale vendue
      }
   },
   {
      $sort: { totalSales: -1 } // Trier par total des ventes décroissant
   },
   {
      $project: {
         _id: 0, // Masquer l'_id
         product: "$_id", // Afficher le produit
         totalSales: 1,
         totalQuantity: 1
      }
   }
])
```

### Modification

Si vous souhaitez actualiser ce document, vous aurez recours à la fonction update. Celle-ci permet de définir les valeurs à changer. Choisissez un update operator (commande de mises à jour) et saisissez la nouvelle valeur à modifier. Si vous souhaitez par exemple changer le champ « âge », vous aurez recours à l’opérateur $set :

```javascript
db.macollection.update(
  { Age: 28 },
  {
    $set: { Age: 30 }
  }
)
```

### Suppression

Pour supprimer les documents d’une collection, utilisez la commande remove :

```javascript
db.macollection.remove();
```

Il est également possible de supprimer un seul document de la collection, en sélectionnant des critères comme l’ID ou en définissant des valeurs précises afin de signaler à MongoDB de quels éléments il s’agit dans la base de données. Plus vous serez précis, plus le système de base de données sera spécifique au cours du processus de suppression.

```javascript
db.macollection.remove( { Age: 28 } )
```

La commande supprimera toutes les saisies dont le champ « âge » a une valeur égale à 28. Vous pouvez aussi définir la suppression du premier élément concerné avec le paramètre justOne-Parameter (1) :

```javascript
db.macollection.remove( { Age: 28 }, 1);
```
