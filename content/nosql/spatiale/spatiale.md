Qu'est-ce qu'une base de données géographique ?

Une base de données géographique (BDG), également connue sous le nom de Système de Gestion de Bases de Données Géographiques (SGBDG), est un système conçu pour gérer, stocker, et interroger des données spatiales et géographiques. Contrairement aux bases de données traditionnelles, les BDG sont spécialisées dans la manipulation de données qui sont liées à des emplacements géographiques. Ces données peuvent inclure des points, des lignes, des polygones, et d'autres types de représentations spatiales.

#### Représentation des données spatiales

Vecteur : Représentation des données sous forme de points, lignes et polygones.
    
Raster : Représentation des données sous forme de grille, où chaque cellule a une valeur correspondant à une caractéristique géographique.

Analyse spatiale

Géocodage : Transformation des adresses en coordonnées géographiques.

Topologie : Étude des relations spatiales entre les objets géographiques (adjacence, connectivité).

Requêtes spatiales : Recherche de proximité, intersection, inclusion, etc.

Outils et technologies

    Logiciels SIG (Systèmes d'Information Géographique) : QGIS, ArcGIS, etc.
    Bases de données spatiales : PostgreSQL/PostGIS, MySQL avec support spatial, etc.
    Langages de programmation : Python (avec bibliothèques comme GeoPandas, Shapely), R (avec bibliothèques comme sf, sp), etc.

## SRID

## Représentation des données

<p style="margin-bottom: 0cm;"><b>WKT</b> (<i>Well Known Text</i>)  est destiné à être <i>lu par des </i><i><b>humains</b></i>.</p>

<p><b>WKB</b> (<i>Well Known Binary</i>) est utilisé pour assurer l' <i><b>import/export/échange</b></i> de données entre différentes plate-formes, sans risque.</p>


ogr2ogr -append -lco GEOMETRY_NAME=the_geom -lco SCHEMA=public -f "PostgreSQL" PG:"host=atelier.neotechweb.net port=5432 user=i2m dbname=i2m password=iutstdie18" -a_srs "EPSG:4326" -nln bound FRA_adm.gpkg

https://guides.codepath.com/android/Genymotion-2.0-Emulators-with-Google-Play-support
http://opengapps.org/

Well-Known Text (WKT) 
Well-Known Binary (WKB)

Systèmes de Référence de Coordonnées :

Elles supportent divers systèmes de projection et de référence de coordonnées (SRID - Spatial Reference System Identifier).
Les données peuvent être transformées d'un système de référence à un autre pour l'analyse et la visualisation.

SROD

ESPG

:SIG
Système d'information géographique contient des données alphanumériques et des données spatiales.

:OGC
l'Open Geospatial Consortium est une organisation international pour développer et promouvoir des standards ouverts, les spécifications OpenGIS, afin de garantir l'interopérabilité des contenus, des services et des échanges dans les domaines de la géomatique et de l'information géographique. 

### Quand utiliser le type de données Géographie

Le type de données géographie permet de stocker des données en coordonnées longitude/latitude, mais à un coût : il y a moins de fonctions définies sur GEOGRAPHY que sur GEOMETRY ; les fonctions qui sont définies demandent plus de temps de traitement CPU pour être exécutées.

Le type de données que vous choisissez doit être déterminé par la zone de travail prévue de l'application que vous développez. Vos données couvriront-elles le globe ou une grande région continentale, ou sont-elles locales à un État, un comté ou une municipalité ?

- Si vos données sont contenues dans une petite zone, vous pourriez constater que choisir une projection appropriée et utiliser GEOMETRY est la meilleure solution en termes de performance et de fonctionnalités disponibles.

- Si vos données sont globales ou couvrent une région continentale, vous pourriez constater que GEOGRAPHY vous permet de construire un système sans avoir à vous soucier des détails de projection. Vous stockez vos données en longitude/latitude et utilisez les fonctions définies sur GEOGRAPHY.

- Si vous ne comprenez pas les projections et que vous ne voulez pas en apprendre davantage, et que vous êtes prêt à accepter les limitations des fonctionnalités disponibles dans GEOGRAPHY, il pourrait être plus simple pour vous d'utiliser GEOGRAPHY plutôt que GEOMETRY. Il vous suffit de charger vos données en longitude/latitude et de partir de là.

:SIG
  Système d'information géographique contient des données alphanumériques et des données spatiales.


- 


Créer un table aeroports contenant un nom une colonne de type point

Ajouter les éléments suivant



Quelles est la distance entre chaque points ?

Créer une table perimetre contenant un nom et une colonne de type polygon

Z 8,9 10,12 7,6

Quels sont les aéroports dans la zone ?
