---
title: MongoDB
---

## Requêtes simples

### Q1 Afficher le premier document de la collection restaurant.

### Q2 Afficher tous les documents de la collection restaurants.

### Q3 Afficher les champs restaurant_id, nom, arrondissement et cuisine pour tous les documents de la collection restaurant

### Q4 Afficher les 5 premiers documents de la collection restaurants. Utiliser la projection de Q3

### Q5 Afficher la liste des boroughs

```
Bronx
Brooklyn
Manhattan
Missing
Queens
Staten Island
```

### Q6 Quel est le nombre de cuisine différentes dans le Bronx ? à Manhattan ?

### Q7 Afficher les champs restaurant_id, nom, arrondissement et cuisine, mais exclure le champ id pour les restaurants servant de la cuisine française.

### Q8 Afficher les champs restaurant_id, nom, arrondissement et code postal, mais exclure le champ id pour les restaurant servant des Pizzas.

### Q9 Afficher tous les restaurants qui se trouvent dans l'arrondissement de Brooklyn.

### Q10 Afficher les 5 premiers restaurants de l'arrondissement Bronx

### Q11 afficher les 5 prochains restaurants après avoir sauté les 5 premiers dans l'arrondissement du Bronx.

### Q12 Retrouvez les restaurants qui ont obtenu une note supérieure à 90.

???

### Q13 Retrouvez les restaurants qui ont obtenu une note supérieure à 80 mais inférieure à 100.

### Q14 Retrouver les restaurants qui se situent à une latitude inférieure à -95.75

### Q15 trouvez les restaurants qui ne préparent aucune cuisine « américaine » et dont la note est supérieure à 70 et leur latitude inférieure à -65,754168.

### Q16 trouvez les restaurants qui ne préparent aucune cuisine « américaine » et qui ont obtenu un score supérieur à 70 et sont situés dans une longitude inférieure à -65,754168. (Remarque : effectuez cette requête sans utiliser l'opérateur $and )

### Q17 trouvez les restaurants qui ne préparent aucune cuisine « américaine » et qui ont obtenu un score « A » n'appartenant pas à l'arrondissement de Brooklyn. Le document doit être affiché selon la cuisine par ordre décroissant.

### Q18 trouvez l'identifiant du restaurant, le nom, le quartier et la cuisine des restaurants qui contiennent « Wil » comme les trois premières lettres de leur nom.

### Q19 Trouvez l'identifiant du restaurant, le nom, l'arrondissement et la cuisine des restaurants qui contiennent « ces » comme les trois dernières lettres de leur nom.

### Q20 recherchez l'identifiant du restaurant, le nom, l'arrondissement et la cuisine des restaurants qui contiennent « Reg » comme trois lettres quelque part dans leur nom.

### Q21 Trouver les restaurants qui appartiennent à l'arrondissement de Staten Island et préparent des plats américains ou chinois.

### Q22 recherchez l'identifiant du restaurant, le nom, le quartier et la cuisine des restaurants qui ont obtenu un score ne dépassant pas 10.

### Q23 recherchez l'identifiant du restaurant, le nom, le quartier et la cuisine des restaurants qui ont préparé des plats sauf « Américain » et « Chinois » ou le nom du restaurant commence par la lettre « Wil ».

### Q24 recherchez l'identifiant, le nom et les notes du restaurant qui ont obtenu la note « A » et obtenu un score de 11 à une date ISO » 2014-08-11T00:00:00Z » parmi de nombreuses dates d'enquête.

### Q25 organisez le nom des restaurants par ordre croissant avec toutes les colonnes.

### Q26 organisez le nom des restaurants par ordre décroissant avec toutes les colonnes.

### Q27 classez le nom de la cuisine par ordre croissant et pour cette même cuisine, le arrondissement doit être par ordre décroissant.

### Q28 savoir si toutes les adresses contiennent la rue ou non.

### Q29 sélectionnez tous les documents de la collection du restaurant dont la valeur du champ de coordonnées est Double.

### Q30 Écrivez une requête MongoDB qui sélectionnera l'identifiant du restaurant, le nom et les notes des restaurants qui ont un score multiple de 7.

## Trouver des restaurants avec des requêtes géospatiales

L'indexation géospatiale de MongoDB vous permet d'exécuter efficacement des requêtes spatiales sur une collection contenant des formes et des points géospatiaux. Pour présenter les capacités des fonctionnalités géospatiales et comparer différentes approches, ce didacticiel vous guidera tout au long du processus d'écriture de requêtes pour une application géospatiale simple.

Téléchargez les exemples de jeux de données depuis 
- https://raw.githubusercontent.com/mongodb/docs-assets/geospatial/neighborhoods.json 
- https://raw.githubusercontent.com/mongodb/docs-assets/geospatial/restaurants.json

Ceux-ci contiennent respectivement les collections restaurantset neighborhoods.

Un index géospatial améliore presque toujours les performances des fonctions _$geoWithinrequêtes_ et _$geoIntersects_.


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

db.restaurants.find( { _coordonnees_: { $geoWithin: { $geometry: neighborhood.geometry } } } ).count()
```

Trouver des restaurants à proximité

Pour trouver des restaurants à une distance spécifiée d'un point, vous pouvez utiliser soit $geoWithin avec $centerSphere pour renvoyer les résultats dans un ordre non trié, soit $nearSphere avec $maxDistance si vous avez besoin de résultats triés par distance.

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

Trié avec $nearSphere

Vous pouvez également utiliser $nearSphereet spécifier un $maxDistanceterme en mètres. Cela renverra tous les restaurants situés à moins de cinq miles de l'utilisateur, triés du plus proche au plus éloigné :

```javascript
var METERS_PER_MILE = 1609.34
db.restaurants.find({ location: { $nearSphere: { $geometry: { type: "Point", coordinates: [ -73.93414657, 40.82302903 ] }, $maxDistance: 5 * METERS_PER_MILE } } })
```
