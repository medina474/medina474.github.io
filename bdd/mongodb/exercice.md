---
title: MongoDB
---



Telécharger Compass l'outil d'administration de MogoDB

## Trouver des restaurants avec des requêtes géospatiales

L'indexation géospatiale de MongoDB vous permet d'exécuter efficacement des requêtes spatiales sur une collection contenant des formes et des points géospatiaux. Pour présenter les capacités des fonctionnalités géospatiales et comparer différentes approches, ce didacticiel vous guidera tout au long du processus d'écriture de requêtes pour une application géospatiale simple.

Téléchargez les exemples de jeux de données depuis 
- https://raw.githubusercontent.com/mongodb/docs-assets/geospatial/neighborhoods.json 
- https://raw.githubusercontent.com/mongodb/docs-assets/geospatial/restaurants.json

Ceux-ci contiennent respectivement les collections restaurantset neighborhoods.

Un index géospatial améliore presque toujours les performances des fonctions _$geoWithinrequêtes_ et _$geoIntersects_.



```bash
mongosh "mongodb://admin:supermotdepasse@127.0.0.1:27017"

test>
```

Par défaut vous vous trouvez sur la base de données test

Lister les bases de données : 

```javascript
show dbs
```

Changer de base de données

```javascript
use sample_restaurants
```

Lister les collections de la base de données

```javascript
show collections
```

## Exercice

#### Exploration des données

restaurants

Inspecter une entrée dans la collection restaurants :

```javascript
db.restaurants.findOne()
```

Inspectez maintenant une entrée dans la collection neighborhoods :

```javascript
db.neighborhoods.findOne()
```

#### Création des index spatiaux

Parce que ces données sont géographiques, créez un 2dsphereindex sur chaque collection en utilisant mongosh:

```javascript
db.restaurants.createIndex({ coord: "2dsphere" })
db.neighborhoods.createIndex({ geometry: "2dsphere" })
```


#### Trouver le quartier actuel

En supposant que l'appareil mobile de l'utilisateur puisse donner une localisation raisonnablement précise pour l'utilisateur, il est simple de trouver le quartier actuel de l'utilisateur avec $geoIntersects.

Supposons que l'utilisateur se trouve à -73,93414657 de longitude et 40,82302903 de latitude. Pour trouver le voisinage actuel, vous devez spécifier un point à l'aide du $geometrychamp spécial au format GeoJSON :

```javascript
db.neighborhoods.findOne({ geometry: { $geoIntersects: { $geometry: { type: "Point", coordinates: [ -73.93, 40.82 ] } } } })
```

#### Trouver tous les restaurants du quartier

Vous pouvez également effectuer une requête pour trouver tous les restaurants contenus dans un quartier donné. Exécutez la commande suivante pour trouver le quartier contenant l'utilisateur, puis comptez les restaurants dans ce quartier :

```javascript
var neighborhood = db.neighborhoods.findOne( { geometry: { $geoIntersects: { $geometry: { type: "Point", coordinates: [ -73.93414657, 40.82302903 ] } } } } )

db.restaurants.find( { coord: { $geoWithin: { $geometry: neighborhood.geometry } } } ).count()
```

Trouver des restaurants à proximité

Pour trouver des restaurants à une distance spécifiée d'un point, vous pouvez utiliser soit $geoWithinavec $centerSphere pour renvoyer les résultats dans un ordre non trié, soit $nearSphere avec $maxDistance si vous avez besoin de résultats triés par distance.

Non trié avec $geoWithin

Pour trouver des restaurants dans une région circulaire, utilisez $geoWithinwith $centerSphere. $centerSphereest une syntaxe spécifique à MongoDB pour désigner une région circulaire en spécifiant le centre et le rayon en radians.

$geoWithinne renvoie pas les documents dans un ordre spécifique, il peut donc montrer à l'utilisateur les documents les plus éloignés en premier.

Les éléments suivants trouveront tous les restaurants dans un rayon de cinq miles de l'utilisateur :

```javascript
db.restaurants.find({ location:
   { $geoWithin:
      { $centerSphere: [ [ -73.93414657, 40.82302903 ], 5 / 3963.2 ] } } })
```

$centerSphereLe deuxième argument de accepte le rayon en radians, vous devez donc le diviser par le rayon de la Terre en miles. Pour plus d'informations sur la conversion entre les unités de distance, consultez Convertir la distance en radians pour les opérateurs sphériques .

Trié avec$nearSphere

Vous pouvez également utiliser $nearSphereet spécifier un $maxDistanceterme en mètres. Cela renverra tous les restaurants situés à moins de cinq miles de l'utilisateur, triés du plus proche au plus éloigné :

```javascript
var METERS_PER_MILE = 1609.34
db.restaurants.find({ location: { $nearSphere: { $geometry: { type: "Point", coordinates: [ -73.93414657, 40.82302903 ] }, $maxDistance: 5 * METERS_PER_MILE } } })
```
