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

#### rang relatif

La fonction fenêtre PERCENT_RANK() en SQL calcule le rang relatif d'une ligne par rapport à l'ensemble des résultats, sous forme de pourcentage. Elle attribue une valeur comprise entre 0 et 1, qui indique où se situe la ligne dans l'ensemble trié. Le premier élément a toujours une valeur de 0 et le dernier une valeur proche de 1 (mais jamais exactement 1, sauf dans certains cas spécifiques).

#### distribution cumulative

La fonction de fenêtrage CUME_DIST() (cumulative distribution) est une fonction analytique SQL qui calcule la distribution cumulative d'une ligne dans un ensemble de résultats. Elle renvoie la fraction ou le pourcentage des lignes d'un ensemble de données qui ont une valeur inférieure ou égale à celle de la ligne actuelle, en fonction d'un certain ordre.

(number of partition rows preceding or peers with current row) / (total partition rows). The value thus ranges from 1/N to 1.

### Fonctions analytiques

#### valeur suivante

La fonction de fenêtrage LEAD() en SQL est utilisée pour accéder à la valeur d’une ligne suivante par rapport à la ligne actuelle dans un ensemble de résultats, sans avoir à écrire une sous-requête complexe. Elle permet de "regarder" en avant dans les données d'une fenêtre pour obtenir une valeur future, ce qui peut être utile pour comparer des enregistrements successifs.

#### valeur précédente

La fonction de fenêtrage LAG() en SQL permet d'accéder à la valeur d’une ligne précédente par rapport à la ligne actuelle dans un ensemble de résultats. Cela est utile pour comparer des enregistrements successifs ou calculer des différences entre la valeur actuelle et une valeur passée. C'est l'inverse de la fonction LEAD(), qui accède aux lignes suivantes.

#### ntile()

La fonction fenêtre NTILE() en SQL divise un ensemble de résultats en un nombre spécifié de groupes égaux (ou presque égaux) et attribue un numéro de groupe à chaque ligne. Cela permet de classer les lignes dans des partitions, souvent appelées "quartiles", "quintiles" ou autres, selon le nombre de groupes que vous spécifiez.

#### première valeur
first_value()

#### dernière valeur
last_value()

#### nième valeur 
nth_value()
