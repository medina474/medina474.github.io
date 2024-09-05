---
title: fonction de fenêtrage
---

En SQL, une fonction de fenêtrage ou fonction analytique est une fonction qui utilise les valeurs d'une ou de plusieurs lignes pour renvoyer une valeur pour chaque ligne. (Cela contraste avec une fonction d'agrégation, qui renvoie une valeur unique pour plusieurs lignes.) Les fonctions de fenêtrage ont une clause _OVER_.

Toute fonction sans clause _OVER_ n'est pas une fonction de fenêtrage, mais plutôt une fonction d'[agrégation](../agrégation) ou à ligne unique (scalaire).

### Implémentation

- PostgreSQL - version 8.4 en 2009.
- MariaDB - version 10.2 en 2016.
- MySQL - version 8 en 2018.

### Ranking Functions

#### row_number()

#### rank()

#### dense_rank()


### Distribution Functions

#### percent_rank()

#### cume_dist()


### Analytic Functions

#### lead()

#### lag()

#### ntile()

#### first_value()

#### last_value()

#### nth_value()



[first](first)

[lead](lead)

[lag](lag)

[partition](partition)


row_number ()

Returns the number of the current row within its partition, counting from 1.

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
