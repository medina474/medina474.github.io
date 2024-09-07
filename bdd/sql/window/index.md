---
title: Fonctions de fenêtrage
---

En SQL, une fonction de fenêtrage ou fonction analytique est une fonction qui utilise les valeurs d'une ou de plusieurs lignes pour renvoyer une valeur pour chaque ligne. Cela contraste avec une fonction d'agrégation, qui renvoie une valeur unique pour plusieurs lignes. Les fonctions de fenêtrage ont une clause _OVER_.

Toute fonction sans clause _OVER_ n'est pas une fonction de fenêtrage, mais plutôt une fonction d'[agrégation](../agrégation) ou à ligne unique (scalaire).

### Implémentation

- PostgreSQL - version 8.4 en 2009.
- MariaDB - version 10.2 en 2016.
- MySQL - version 8 en 2018.

### Fonctions de classement

#### row_number()

La fonction fenêtre ROW_NUMBER() en SQL attribue un numéro de ligne unique et consécutif à chaque ligne d'un ensemble de résultats, selon l'ordre spécifié.

ROW_NUMBER() attribue un numéro unique à chaque ligne, même si les valeurs sont identiques dans la colonne de tri.

#### rang

En SQL, la fonction fenêtre RANK() attribue un rang à chaque ligne dans un ensemble de résultats, basé sur l'ordre spécifié. Le rang commence à 1 pour la première ligne. Contrairement à la fonction ROW_NUMBER(), qui attribue des numéros de ligne consécutifs, RANK() attribue le même rang à des lignes ayant des valeurs égales dans la colonne utilisée pour le tri, mais laisse des "trous" dans la numérotation.

#### rang dense

La fonction fenêtre DENSE_RANK() en SQL attribue un rang à chaque ligne dans un ensemble de résultats, tout en attribuant le même rang aux lignes ayant des valeurs identiques, sans sauter de rangs dans la numérotation (contrairement à RANK() qui laisse des "trous").


### Fonctions de distribution

#### renag relatif

La fonction fenêtre PERCENT_RANK() en SQL calcule le rang relatif d'une ligne par rapport à l'ensemble des résultats, sous forme de pourcentage. Elle attribue une valeur comprise entre 0 et 1, qui indique où se situe la ligne dans l'ensemble trié. Le premier élément a toujours une valeur de 0 et le dernier une valeur proche de 1 (mais jamais exactement 1, sauf dans certains cas spécifiques).

#### distribution cumulative


### Analytic Functions

#### lead()

#### lag()

#### ntile()

La fonction fenêtre NTILE() en SQL divise un ensemble de résultats en un nombre spécifié de groupes égaux (ou presque égaux) et attribue un numéro de groupe à chaque ligne. Cela permet de classer les lignes dans des partitions, souvent appelées "quartiles", "quintiles" ou autres, selon le nombre de groupes que vous spécifiez.


#### première valeur
first_value()

#### dernière valeur
last_value()

#### nième valeur 
nth_value()



[first](first)

[lead](lead)

[lag](lag)

[partition](partition)


row_number ()



rank ()

Returns the rank of the current row, with gaps; that is, the row_number of the first row in its peer group.

dense_rank () → bigint

Returns the rank of the current row, without gaps; this function effectively counts peer groups.

percent_rank () → double precision

Returns the relative rank of the current row, that is (rank - 1) / (total partition rows - 1). The value thus ranges from 0 to 1 inclusive.

cume_dist () → double precision

Returns the cumulative distribution, that is (number of partition rows preceding or peers with current row) / (total partition rows). The value thus ranges from 1/N to 1.

ntile ( num_buckets integer ) → integer

Returns an integer ranging from 1 to the argument value, dividing the partition as equally as possible.

lag ( value anycompatible [, offset integer [, default anycompatible ]] ) → anycompatible

Returns value evaluated at the row that is offset rows before the current row within the partition; if there is no such row, instead returns default (which must be of a type compatible with value). Both offset and default are evaluated with respect to the current row. If omitted, offset defaults to 1 and default to NULL.

lead ( value anycompatible [, offset integer [, default anycompatible ]] ) → anycompatible

Returns value evaluated at the row that is offset rows after the current row within the partition; if there is no such row, instead returns default (which must be of a type compatible with value). Both offset and default are evaluated with respect to the current row. If omitted, offset defaults to 1 and default to NULL.

first_value ( value anyelement ) → anyelement

Returns value evaluated at the row that is the first row of the window frame.

last_value ( value anyelement ) → anyelement

Returns value evaluated at the row that is the last row of the window frame.

nth_value ( value anyelement, n integer ) → anyelement

Returns value evaluated at the row that is the n'th row of the window frame (counting from 1); returns NULL if there is no such row.
