---
title: Base de données spatiales
---

> **définition :** Une base de données spatiale est une base de données optimisée pour stocker, interroger et manipuler des données géométriques en 3 dimensions (spatiales) et par extension des données géographiques.

Contrairement aux bases de données traditionnelles qui gèrent des données textuelles, numériques et autres types de données alphanumériques, une base de données spatiale est spécifiquement conçue pour gérer des données de type géométrique (points, lignes, polygones) et des informations spatiales (coordonnées géographiques, systèmes de projection, etc.).

Une base de données spatiales est une base de données optimisée pour stocker et interroger des données reliées à des objets référencés géographiquement, y compris des points, les lignes et des polygones. 

Alors que les bases de données classiques peuvent comprendre différents types de données numériques et caractères, des fonctions additionnelles ont besoin d'être ajoutées pour traiter les types de données spatiales. Celles-ci sont typiquement appelées géométrie ou caractère. L'Open Geospatial Consortium a créé les spécifications des caractéristiques simples et les standards pour compléter les systèmes de gestion de bases de données avec les fonctionnalités de gestion de données spatiales.


### Types de données spatiales :

- **Points** : Représentent des emplacements précis (ex. emplacements de capteurs, adresses).
- **Lignes** : Représentent des entités linéaires (ex. routes, rivières).
- **Polygones** : Représentent des surfaces (ex. limites de villes, zones de conservation).


### POINT

Le type POINT représente un point unique défini par ses valeurs de ***latitude*** et de ***longitude***.

#### mariadb

```sql
select ST_PointFromText('POINT(15 5)');
```

#### postgresql

```sql
select ST_MakePoint(12, 3);

select ST_PointFromText('POINT(15 5)');
```

ST_MakePoint n'est pas conforme au standard mais il a l'avantage d'être rapide et de travailler sur des nombres à la place du texte.

<svg>
  <circle cx="150" cy="50" r="5" />
</svg>

### LINESTRING

Le type LINESTRING représente une ligne constituée de points.

```sql
select GeomFromText('LINESTRING(3 5,6 7,8 2,12 1)');
```


### POLYGON

Le type POLYGON est une ligne fermée qui représente une surface. Les coordonnées du dernier point sont égales aux coordonnées du premier point. Chaque point est séparé par une virgule (attention au format décimal français qui utilise aussi la virgule) et les coordonnées sont séparées par des espaces.

```sql
select GeomFromText('POLYGON((2 2, 4 3, 5 7, 3 8, 1 9, 2 2))')
```

### GEOMETRY

Le type geometry représente indifféremment un point, une ligne ou un polygone. Les lignes de la table sont constituées d'un mélange de points, de lignes et de polygones.

```sql
select ST_GeomFromText('LINESTRING(3 5,6 7,8 2,12 1)');
```

### MULTIPOINT

Le type MULTIPOINT représente une collection de points.

```sql
select MultiPointFromText('MULTIPOINT(0 0,10 10,10 20,20 20)')
```

### MULTILINESTRING

Le type MULTILINESTRING représente une collection de lignes.

```sql
select MultiLineStringFromText('MULTILINESTRING((10 48,10 21,10 0),(16 0,16 23,16 48))');
```


### MULTIPOLYGON

Le type MULTIPOLYGON représente une collection de polygones.

```sql
select MultiPolygonFromText('MULTIPOLYGON(
  ((28 26,28 0,84 0,84 42,28 26),(52 18,66 23,73 9,48 6,52 18)),
  ((59 18,67 18,67 13,59 13,59 18)))');
```

### GEOMETRYCOLLECTION

Le type GEOMETRYCOLLECTION représente une collection d'objets géométriques points lignes ou polygones.

```sql
INSERT INTO
```

## Exercices

-A  Point(12, 3)
-B  Point(2, 7)
-C  Point(13, 4)
-D  Point(8, 11)
-E  Point(1, 4)

truncate table newtable;
truncate table newtable2
;
insert into newtable VALUES ('A', st_makepoint(12, 3));
insert into newtable VALUES ('B', st_makepoint(2, 7));
insert into newtable VALUES ('C', st_makepoint(15, 12));
insert into newtable VALUES ('D', st_makepoint(17, 4));
insert into newtable VALUES ('E', st_makepoint(7, 6));
insert into newtable VALUES ('F', st_makepoint(10, 11));

insert into newtable2 VALUES ('Z', st_makepolygon(ST_GeomFromText('LINESTRING(18 10, 13 15, 6 10, 8 8, 18 10)')));
insert into newtable2 VALUES ('Y', st_makepolygon(ST_GeomFromText('LINESTRING(5 5, 7 8, 12 4, 5 5)')));
insert into newtable2 VALUES ('X', st_makepolygon(ST_GeomFromText('LINESTRING(8 3, 14 2, 12 6, 8 3)')));


select * from newtable n union all
select * from newtable2;
