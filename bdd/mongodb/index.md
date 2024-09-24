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

## Commandes

### Créer une base de données

Dès lors que MongoDB et le client sont exécutés, vous pouvez passer à la gestion et au traitement des données. Mais il convient tout d’abord de créer une base de données. A contrario, les collections et les documents seront sauvegardés dans la base de données test créée par défaut.

Pour créer une base de données, utilisez la commande use. Si vous désirez par exemple créer une base de données appelée mabasededonnées, la commande sera la suivante :

```
use mabasededonnees
```

La commande use permet de sélectionner une base de données MongoDB déjà existante que vous pourrez utiliser pour le traitement des données. A l’aide de la commande db, vous pouvez vérifier quelle base de données est sélectionnée.

###  Créer une collection

L’étape suivante consiste à créer une première collection, c’est-à-dire un dossier pour vos différents documentsBSON, dans lequel les données seront enregistrées ultérieurement. La syntaxe de base ressemble à ceci :

```
db.createCollection(<name>, { options } )
```

La commande create compte deux paramètres. Tout d’abord, le paramètre name (nom de la collection) et options (options pour configurer la collection). Dans les options, vous pouvez définir par exemple si les documents d’une collection doivent posséder une taille précise (capped: true) ou s’ils doivent avoir une quantité restreinte de Bytes (size: <number>) ou encore une quantité limitée de documents (max: <number>). Une collection nommée macollection, une limitation à 6.142.800 Bytes et un maximum de 10 000 documents seraient définis à titre d’exemple avec la commande suivante (les espaces entre les éléments ont uniquement été insérés pour assurer une meilleure lisibilité) :

```
db.createCollection ("macollection", { capped: true,
          size: 6142800,
          max: 10000 } )
```

### Ajouter des documents dans la collection

Après création du dossier, vous pouvez y insérer des documents. Trois méthodes différentes sont à votre disposition :

    .insertOne()

    .insertMany()

    .insert()

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

Etape 7 : gestion des documents

La dernière étape de notre tutoriel MongoDB porte sur la gestion de base des documents déposés dans le dossier. Avant de pouvoir effectuer des modifications, il faut tout d’abord trouver votre dossier avec la commande find. Le paramètre optionnel query filter (filtre de recherche) et projection (spécification des résultats d’affichage) peuvent être utilisés également. Pour ouvrir et trouver le dossier souhaité, effectuez la commande suivante :

```javascript
db.macollection.find( { Nom: "Name", Age: 28 } )
```

Si vous souhaitez actualiser ce document, vous aurez recours à la fonction update. Celle-ci permet de définir les valeurs à changer. Choisissez un update operator (commande de mises à jour) et saisissez la nouvelle valeur à modifier. Si vous souhaitez par exemple changer le champ « âge », vous aurez recours à l’opérateur $set :

```javascript
db.macollection.update(
  { Age: 28 },
  {
    $set: { Age: 30 }
  }
)
```

Découvrez d’autres opérateurs de mises à jour sur la page de MongoDB.

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

Vous trouverez des informations sur l’administration, les paramètres de sécurité, la distribution des données sur plusieurs systèmes d’autres documentations utiles sur mongodb.com et dans le tutotiel MongoDB sur tutorialspoint.com.
