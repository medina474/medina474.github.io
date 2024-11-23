---
title: Travaux dirigés 3
---

> Énoncé : Lire un fichier texte contenant des valeurs numériques et effectuer une analyse.
{: .definition }

a. Ouvrir le fichier [observations.csv](observations.csv) en mode lecture

b. Lire la totalité du fichier 

c. A la fin de la lecture, afficher la plus grande valeur (maximim) et la plus petite (minimum).

d. Afficher la moyenne des valeurs lues.

e. Pour chaque ligne lue afficher la moyenne depuis le début de la série et la moyenne glissante sur les 5 dernières valeurs. (voir [td2](td2))

f. Enregistrer dans un nouveau fichier 

#### a. Ouvrir le fichier

La fonction ***[fopen](../../fichiers)*** ouvre le fichier. si le retour est NULL alors c'est qu'il y a eu un problème. la fonction ***perror*** permet d'afficher le détail de l'erreur, pour en savoir un peu plus.


#### b. Lire la totalité du fichier 

La lecture d'une ligne se fait avec la fonction ***fgets***

La conversion s'effectue à l'aide la fonction ***atof*** de la bibliothèque ***stdlib.h***.

Répeter l'opération tant qu'il y a des lignes

#### c. Calculer à chaque ligne le maximum et le minimum


## Correction

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
