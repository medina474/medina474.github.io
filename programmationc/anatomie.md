---
title: Anatomie d'un programme en C
---


```C
```

### Commentaires

Il existe deux formats: en-ligne ou en bloc.
 
 Commentaires en-ligne: Doit obligatoirement tenir sur une ligne. Peut se trouver à la suite d'une instruction.

```C
//Calcul du discriminant
delta = b * b - 4 * a * c; // Δ = b² - 4ac
```

Commentaire en bloc: Peuvent s’étendre sur plusieurs lignes, sont délimités par /* et */

```C
/* Résolution d'une équation du 2nd degré
Auteur: Emmanuel Medina */
```

### Librairies

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
