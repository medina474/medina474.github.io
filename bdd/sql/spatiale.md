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
<br>

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

ogr2ogr -append -lco GEOMETRY_NAME=the_geom -lco SCHEMA=public -f "PostgreSQL" PG:"host=atelier.neotechweb.net port=5432 user=i2m dbname=i2m password=iutstdie18" -a_srs "EPSG:4326" -nln bound FRA_adm.gpkg

https://guides.codepath.com/android/Genymotion-2.0-Emulators-with-Google-Play-support
http://opengapps.org/
