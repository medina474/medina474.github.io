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


ogr2ogr -append -lco GEOMETRY_NAME=the_geom -lco SCHEMA=public -f "PostgreSQL" PG:"host=atelier.neotechweb.net port=5432 user=i2m dbname=i2m password=iutstdie18" -a_srs "EPSG:4326" -nln bound FRA_adm.gpkg

https://guides.codepath.com/android/Genymotion-2.0-Emulators-with-Google-Play-support
http://opengapps.org/

SROD

ESPG
