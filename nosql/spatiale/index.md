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
SROD

ESPG


4.3.3. When to use the Geography data type

The geography data type allows you to store data in longitude/latitude coordinates, but at a cost: there are fewer functions defined on GEOGRAPHY than there are on GEOMETRY; those functions that are defined take more CPU time to execute.

The data type you choose should be determined by the expected working area of the application you are building. Will your data span the globe or a large continental area, or is it local to a state, county or municipality?

    If your data is contained in a small area, you might find that choosing an appropriate projection and using GEOMETRY is the best solution, in terms of performance and functionality available.

    If your data is global or covers a continental region, you may find that GEOGRAPHY allows you to build a system without having to worry about projection details. You store your data in longitude/latitude, and use the functions that have been defined on GEOGRAPHY.

    If you don't understand projections, and you don't want to learn about them, and you're prepared to accept the limitations in functionality available in GEOGRAPHY, then it might be easier for you to use GEOGRAPHY than GEOMETRY. Simply load your data up as longitude/latitude and go from there.

:SIG
  Système d'information géographique contient des données alphanumériques et des données spatiales.
