---
title: Travaux dirigés
---

> Lancer VSCode uniquement depuis l'icône sur le BUREAU.
{:.danger}

> NE jamais travailler sur Espace Personnel. Uniquement sur le disque D:
{:.danger}





### Lecture clavier

La fonction scanf en C est utilisée pour lire des entrées formatées depuis l'entrée standard (généralement le clavier). Elle permet de capturer des valeurs saisies par l'utilisateur et de les stocker dans des variables. Son fonctionnement repose sur des spécificateurs de format, similaires à ceux utilisés avec la fonction printf, mais dans ce cas, pour la lecture.

Pour stocker la valeur lue, scanf a besoin de connaître l'adresse de la variable où stocker la donnée. Cela signifie que vous devez passer les adresses des variables à scanf (à l'aide de l'opérateur **&** pour obtenir l'adresse d'une variable).

Si vous oubliez le &, cela causera un comportement indéfini, car scanf essaiera de modifier une adresse mémoire incorrecte.

```c
int age;

printf("Entrez votre âge : ");
scanf("%d", &age);  // Lire un entier
```

Cas particulier des chaines de caractères.

La variable _nom_ est déja un pointeur il ne faut pas utiliser l'opérateur &

```c
char nom[50];
scanf("%s", nom); 
```

Le spécificateur %s lit une chaîne de caractères jusqu'à un espace ou une nouvelle ligne. Pour lire une phrase entière avec des espaces, vous devez utiliser une autre approche comme fgets.

#### fgets

La fonction fgets en C est utilisée pour lire une ligne de texte (ou une partie de ligne) depuis un flux d'entrée (comme le clavier ou un fichier), ce qui la rend idéale pour lire des chaînes de caractères qui peuvent contenir des espaces ou des caractères spéciaux. Contrairement à scanf, qui s'arrête à un espace, fgets continue à lire jusqu'à ce qu'elle rencontre un saut de ligne (\n), une fin de fichier ou le nombre maximal de caractères spécifié.

```c
char buffer[100];
fgets(buffer, 100, stdin);
```

### Bitwise

Définir des constantes

```c
#define OPTION_GPS 0b000001
#define OPTION_CAMERA 0b000010
#define OPTION_AUTOMATIQUE 0b000100
#define OPTION_RADAR 0b001000
#define OPTION_ABS 0b010000
#define OPTION_ESP 0b100000
```

```c
#include <stdio.h>

void affiche(int valeur) {
  printf("GPS %d\n", (valeur >> 0 & 1));
  printf("CAMERA %d\n", (valeur >> 1 & 1));
  printf("AUTOMATIQUE %d\n", (valeur >> 2 & 1));
  printf("RADAR %d\n", (valeur >> 3 & 1));
  printf("ABS %d\n", (valeur >> 4 & 1));
  printf("ESP %d\n", (valeur >> 5 & 1));
}

void main() {

  int vehicule1 = OPTION_CAMERA | OPTION_ABS;

  if (vehicule1 & OPTION_CAMERA)
  {
    printf("CAMERA OUI %d\n", vehicule1 & OPTION_CAMERA);
  }
  else
  {
    printf("CAMERA NON %d\n", vehicule1 & OPTION_CAMERA);
  }

  printf("OPTION_CAMERA | OPTION_ABS %d\n",   vehicule1);
  vehicule1 |= OPTION_ESP;

  printf("OPTION_CAMERA | OPTION_ABS OPTION_ESP %d\n", vehicule1);

  int z = 13; // 1101
  affiche(z);

  puts("Retirer l'accés si il existe déja. Le remet sinon");
  z ^= OPTION_RADAR; // z = z XOR 0b1000;
  affiche(z);

  z = 13;
  puts("Retirer l'accès dans tous les cas");
  z &= ~OPTION_RADAR; // ! inversion logique uniquement 0 ou 1
                      // ~ inversion bits à bits
  affiche(z);
}
```

### Tableaux

Un tableau = un pointeur

```c
void main() {
  
  int tableau[] = {25, 50, 75, 100};

  // Accès par indice
  printf("%d\n", tableau[0]);

  tableau[1] = 33;
  printf("%d\n", tableau[1]);

  // Utilisation d'un pointeur
  int *p = tableau;
  printf("%d %p\n", *p, p);

  p = p + 1;
  printf("%d %p\n", *p, p);
  
  p = p + 1;
  printf("%d %p\n", *p, p);

  *p = 60;
  printf("%d\n", tableau[2]);

  int matrix[2][3] = { {1, 4, 2}, {3, 6, 8} };
  p = matrix[0];

  p = p + 5;
  printf("%d %p\n", *p, p);
}
```
