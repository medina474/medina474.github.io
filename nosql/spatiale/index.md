---
title: Base de données spatiales
---

> **définition :** Une base de données spatiale est une base de données optimisée pour stocker, interroger et manipuler des données géométriques en 3 dimensions (spatiales) et par extension des données géographiques. 

Contrairement aux bases de données traditionnelles qui gèrent des données textuelles, numériques et autres types de données alphanumériques, une base de données spatiale est spécifiquement conçue pour gérer des données de type géométrique (points, lignes, polygones) et des informations spatiales (coordonnées géographiques, systèmes de projection, etc.).

Une base de données spatiales est une base de données optimisée pour stocker et interroger des données reliées à des objets référencés géographiquement, y compris des points, les lignes et des polygones. 

Alors que les bases de do
:SIG
  Système d'information géographique contient des données alphanumériques et des données spatiales.
nnées classiques peuvent comprendre différents types de données numériques et caractères, des fonctions additionnelles ont besoin d'être ajoutées pour traiter les types de données spatiales. Celles-ci sont typiquement appelées géométrie ou caractère. L'Open Geospatial Consortium a créé les spécifications des caractéristiques simples et les standards pour compléter les systèmes de gestion de bases de données avec les fonctionnalités de gestion de données spatiales1.

Well-Known Text (WKT) 
Well-Known Binary (WKB)

Systèmes de Référence de Coordonnées :

Elles supportent divers systèmes de projection et de référence de coordonnées (SRID - Spatial Reference System Identifier).
Les données peuvent être transformées d'un système de référence à un autre pour l'analyse et la visualisation.

Types de Données Spatiales :

Points : Représentent des emplacements précis (ex. emplacements de capteurs, adresses).
    
Lignes : Représentent des entités linéaires (ex. routes, rivières).
    
Polygones : Représentent des surfaces (ex. limites de villes, zones de conservation).



### Quand utiliser le type de données Géographie

Le type de données géographie permet de stocker des données en coordonnées longitude/latitude, mais à un coût : il y a moins de fonctions définies sur GEOGRAPHY que sur GEOMETRY ; les fonctions qui sont définies demandent plus de temps de traitement CPU pour être exécutées.

Le type de données que vous choisissez doit être déterminé par la zone de travail prévue de l'application que vous développez. Vos données couvriront-elles le globe ou une grande région continentale, ou sont-elles locales à un État, un comté ou une municipalité ?

- Si vos données sont contenues dans une petite zone, vous pourriez constater que choisir une projection appropriée et utiliser GEOMETRY est la meilleure solution en termes de performance et de fonctionnalités disponibles.

- Si vos données sont globales ou couvrent une région continentale, vous pourriez constater que GEOGRAPHY vous permet de construire un système sans avoir à vous soucier des détails de projection. Vous stockez vos données en longitude/latitude et utilisez les fonctions définies sur GEOGRAPHY.

- Si vous ne comprenez pas les projections et que vous ne voulez pas en apprendre davantage, et que vous êtes prêt à accepter les limitations des fonctionnalités disponibles dans GEOGRAPHY, il pourrait être plus simple pour vous d'utiliser GEOGRAPHY plutôt que GEOMETRY. Il vous suffit de charger vos données en longitude/latitude et de partir de là.

:SIG
  Système d'information géographique contient des données alphanumériques et des données spatiales.

SROD

ESPG

### Exercices

Créer un table aeroports contenant un nom une colonne de type point

Ajouter les éléments suivant
A  Point(5, 6)
B  Point(9, 17)
C  Point(13, 4)
D  Point(8, 11)
E  Point(1, 4)

Quelles est la distance entre chaque points ?
