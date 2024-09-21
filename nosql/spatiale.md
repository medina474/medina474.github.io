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

## Types des données

### POINT

Le type POINT représente un point unique défini par ses valeurs de ***latitude*** et de ***longitude***.

```sql
INSERT INTO `points` (`data`) VALUES (GeomFromText('POINT(5 9)',0));
```

### LINESTRING

Le type LINESTRING représente une ligne constituée de points.

```sql
INSERT INTO `linestrings` (`data`) VALUES (GeomFromText('LINESTRING(3 5,6 7,8 2,12 1)',0));
```

### POLYGON

Le type POLYGON est une ligne fermée qui représente une surface. Les coordonnées du dernier point sont égales aux coordonnées du premier point. Chaque point est séparé par une virgule (attention au format décimal français qui utilise aussi la virgule) et les coordonnées sont séparées par des espaces.

```sql
INSERT INTO `polygons` (data) VALUES (GeomFromText('POLYGON((2 2, 4 3, 5 7, 3 8, 1 9, 2 2))',0))
```


### GEOMETRY

Le type geometry représente indifféremment un point, une ligne ou un polygone. Les lignes de la table sont constituées d'un mélange de points, de lignes et de polygones.

```sql
INSERT INTO
```


### MULTIPOINT

Le type MULTIPOINT représente une collection de points.

```sql
INSERT INTO
```

### MULTILINESTRING

Le type MULTILINESTRING représente une collection de lignes.

```sql
INSERT INTO
```


### MULTIPOLYGON

Le type MULTIPOLYGON représente une collection de polygones.

```sql
INSERT INTO
```

### GEOMETRYCOLLECTION

Le type GEOMETRYCOLLECTION représente une collection d'objets géométriques points lignes ou polygones.

```sql
INSERT INTO
```

### Quand utiliser le type de données Géographie

Le type de données géographie permet de stocker des données en coordonnées longitude/latitude, mais à un coût : il y a moins de fonctions définies sur GEOGRAPHY que sur GEOMETRY ; les fonctions qui sont définies demandent plus de temps de traitement CPU pour être exécutées.

Le type de données que vous choisissez doit être déterminé par la zone de travail prévue de l'application que vous développez. Vos données couvriront-elles le globe ou une grande région continentale, ou sont-elles locales à un État, un comté ou une municipalité ?

- Si vos données sont contenues dans une petite zone, vous pourriez constater que choisir une projection appropriée et utiliser GEOMETRY est la meilleure solution en termes de performance et de fonctionnalités disponibles.

- Si vos données sont globales ou couvrent une région continentale, vous pourriez constater que GEOGRAPHY vous permet de construire un système sans avoir à vous soucier des détails de projection. Vous stockez vos données en longitude/latitude et utilisez les fonctions définies sur GEOGRAPHY.

- Si vous ne comprenez pas les projections et que vous ne voulez pas en apprendre davantage, et que vous êtes prêt à accepter les limitations des fonctionnalités disponibles dans GEOGRAPHY, il pourrait être plus simple pour vous d'utiliser GEOGRAPHY plutôt que GEOMETRY. Il vous suffit de charger vos données en longitude/latitude et de partir de là.

:SIG
  Système d'information géographique contient des données alphanumériques et des données spatiales.



### Exercices

Créer un table aeroports contenant un nom une colonne de type point

Ajouter les éléments suivant

- A  Point(5, 6)
- B  Point(9, 17)
- C  Point(13, 4)
- D  Point(8, 11)
- E  Point(1, 4)

Quelles est la distance entre chaque points ?

Créer une table perimetre contenant un nom et une colonne de type polygon

A 8,9 10,12 7,6

Quels sont les aéroports dans la zone ?
