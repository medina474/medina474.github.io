---
title: Travaux dirigés 3
---

> Énoncé : Lire un fichier texte contenant des valeurs numériques et effctuer une analyse.
{: .definition }

a. Ouvrir le fichier [observations.csv](observations.csv) en mode lecture

b. Lire la totalité du fichier 

c. Afficher la plus grande valeur (maximim), la plus petite (minimum).

d. Afficher la moyenne des valeurs lues.

e. Pour chaque ligne lue afficher la moyenne depuis le début de la série et la moyenne glissante sur les 5 dernières valeurs.


#### a. Ouvrir le fichier

La fonction ***fopen*** ouvre le fichier. si le retour est NULL alors c'est qu'il y a eu un problème. la fonction ***perror*** permet d'afficher le détail de l'erreur, pour en savoir un peu plus.

```c
#include <stdio.h>

void main() 
{
  FILE *fp;
  fp = fopen("observations.csv", "r");
  
  if (fp == NULL) {
    puts("Erreur de l'ouverture du fichier");
    perror("Error");
    return;
  }
}
```
#### b. Lire la totalité du fichier 

La lecture d'une ligne se fait avec la fonction ***fgets***

```c
char chaine[10];
char *result;

while (1) {
  result = fgets(chaine, 10, fp);
  if (result == NULL) 
  {
    break;
  }
}
```

En plus compact 

```c
char chaine[10];

while (fgets(chaine, 10, fp) != NULL) {
}
```

La conversion s'effectue à l'aide la fonction ***atof**

```c
#include <stdlib.h>

while (fgets(chaine, 10, fp) != NULL) {
  double nombre;
  nombre = atof(chaine);
}
```

```c
if (nombre > maxi) maxi = nombre;
if (nombre < mini) mini = nombre;
```


```c
#include <stdio.h>
#include <stdlib.h>

void main() 
{
  FILE *fp;
  fp = fopen("observations.csv", "r");
  if (fp == NULL) {
    puts("Erreur de l'ouverture du fichier");
    perror("Error");
    return;
  }

  char chaine[10];
  char *result;

  double mini = __DBL_MAX__;
  double maxi = 0.0;
  double moyenne;
  double somme = 0.0;

  int ligne_mini = 0;
  int ligne_maxi = 0;
  int ligne = 0;

  while (1) {
    result = fgets(chaine, 10, fp);
    if (result == NULL) 
    {
      break;
    }

    ligne++;
    
    //printf("%s", chaine);

    double nombre;
    nombre = atof(chaine);
    //printf("%f", nombre);

    if (nombre > maxi) { 
      maxi = nombre;
      ligne_maxi = ligne;
    }

    if (nombre < mini) {
      mini = nombre;
      ligne_mini = ligne;
    }

    somme += nombre;
  }

  printf("minimum: %f ligne %d \n", mini, ligne_mini);
  printf("maximum: %f ligne %d \n", maxi, ligne_maxi);
  printf("moyenne %f sur %d valeurs\n", somme / ligne, ligne);
}
```
