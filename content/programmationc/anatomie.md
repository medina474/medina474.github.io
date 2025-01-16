---
title: Anatomie d'un programme en C
---

Un programme en langage C est constitué des éléments suivants :

- Directives de préprocesseur
- Fonctions
- Déclarations de variables
- Instructions
- Structures de contrôle
- Commentaires

### Exemple minimaliste

```c
#include <stdio.h>    // Directive de préprocesseur

int main() {          // Début de la fonction principale
  puts("Bonjour.");   // Instruction
  return 0;           // Retourne le code 0 pour indiquer la fin du programme
}
```

### Directives de préprocesseur

Les directives de préprocesseur commencent par le symbole # et sont traitées avant la compilation. Elles servent principalement à inclure des bibliothèques ou définir des constantes.

Inclure la bibliothèque d'entrées/sorties standard (stdio : standard input output)

```c
#include <stdio.h>
```

Déclarer une constante

```c
#define PI 3.1415
```

### Fonctions

La fonction main est le point d’entrée de tout programme C. Elle retourne un code numérique pour spécifier si le traitement (quelqu'il soit) s'est bien déroulé.

### Variables

Une variable doit être déclarée avant utilisation, en précisant son type.

```c
int age = 25;          // variable de type nombre entier (integer)
float taille = 1.75;   // variable de type nombre réel à virgule flottante
char initiale = 'A';   // variable de type caractère (character)
```

### Instructions 

Les instructions sont des opérationsqui sont exécutées par le programme elle peuvent iclure des tests, des opérations mathématiques ou des appels de fonctions.

Chaque instruction en C se termine par un point-virgule ;.

### Commentaires

Il existe deux manières d'écrire des commentaires : en-ligne ou en bloc.
 
Les commentaires en-ligne Doivent obligatoirement tenir sur une ligne. Ils Peuvent se trouver à la suite d'une instruction.

```c
// Calcul du discriminant
delta = b * b - 4 * a * c; // Δ = b² - 4ac
```

Les commentaires en bloc peuvent s’étendre sur plusieurs lignes. Ils sont délimités par /* et */

```c
/* Résolution d'une équation du 2nd degré
Auteur: Emmanuel Medina */
```

## Bibliothèques

### stdio

La bibliothèque standard d'entrée/sortie ***stdio.h***, est essentielle pour interagir avec les flux d'entrée et de sortie. Elle fournit des fonctions pour lire et écrire des données, ainsi que pour manipuler les fichiers.

### stdlib

La bibliothèque standard ***stdlib.h*** (standard library) fournit des fonctions essentielles pour la gestion de la mémoire, le contrôle des processus, le tri des données, les fonctions mathématiques simples et les conversions de texte en nombre. 

### string

La bibliothèque ***string.h*** fournit des fonctions pour manipuler les chaînes de caractères et les blocs mémoire.

### ctype

La bibliothèque ***ctype.h*** fournit des fonctions pour tester et manipuler des caractères.

### math

La bibliothèque ***math.h*** , permet de définir les principales fonctions usuelles mathématiques.
