---
title: Opérateurs bit-à-bit
---

Les opérateurs bit-à-bit travaillent sur chacun des bits des opérandes.

## Inversion bit-à-bit

L'opérateur `~` retourne 0 pour un bit à 1 et 1 pour un bit à 0. C'est un opérateur unaire

 v   | r   | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0
-----|----:|--:|--:|--:|--:|--:|--:|--:|--:
a    |  73 | 0 | 1 | 0 | 0 | 1 | 0 | 0 | 1
~a   | 182 | 1 | 0 | 1 | 1 | 0 | 1 | 1 | 0


## ET bit-à-bit

L'opérateur `&` retourne 1 si les deux bits de même poids sont à 1

 v    | r |  7  | 6  | 5  | 4  | 3  | 2  | 1 | 0
------|--:|--:|--:|--:|--:|--:|--:|--:|--:
a     | 73 | 0  | 1  | 0  | 0  | 1  | 0  | 0  | 1
b     | 15 | 0  | 0  | 0  | 0  | 1  | 1  | 1  | 1
a & b |  9 | 0  | 0  | 0  | 0  | 1  | 0  | 0  | 1


## OU bit-à-bit

L'opérateur `|` retourne 1 si l'un ou l'autre des deux bits de même poids est à 1 (ou les deux).

 v | r |  7  | 6  | 5  | 4  | 3  | 2  | 1 | 0
---|--:|--:|--:|--:|--:|--:|--:|--:|--:
a      | 73 | 0  | 1  | 0  | 0  | 1  | 0  | 0  | 1
b      | 15 | 0  | 0  | 0  | 0  | 1  | 1  | 1  | 1
a \| b | 79 | 0  | 1  | 0  | 0  | 1  | 1  | 1  | 1


## OU exclusif bit-à-bit

L'opérateur `^` retourne 1 si un seul des deux bits de même poids est à 1.

 v | r |  7  | 6  | 5  | 4  | 3  | 2  | 1 | 0
---|--:|--:|--:|--:|--:|--:|--:|--:|--:
a      | 73 | 0  | 1  | 0  | 0  | 1  | 0  | 0  | 1
b      | 15 | 0  | 0  | 0  | 0  | 1  | 1  | 1  | 1
a ^ b  | 70 | 0  | 1  | 0  | 0  | 0  | 1  | 1  | 0


## Décalage à droite

Un décalage à droite revient à efectuer un division entière par 2.

 v | r |  7  | 6  | 5  | 4  | 3  | 2  | 1 | 0
---|--:|--:|--:|--:|--:|--:|--:|--:|--:
a      | 73 | 0  | 1  | 0  | 0  | 1  | 0  | 0  | 1
a >> 2 | 18 | 0  | 0  | 0  | 1  | 0  | 0  | 1  | 0


## Décalage à gauche

Un décalage à gauche revient à efectuer une multiplication par 2.

 v | r |  7  | 6  | 5  | 4  | 3  | 2  | 1 | 0
-------|--:|--:|--:|--:|--:|--:|--:|--:|--:
a      |  9 | 0  | 0  | 0  | 0  | 1  | 0  | 0  | 1
a << 2 | 36 | 0  | 0  | 1  | 0  | 0  | 1  | 0  | 0
