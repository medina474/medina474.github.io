---
title: Travaux dirigés 5
---

> Énoncé : Lire un fichier texte contenant des valeurs numériques en colonne et effectuer une analyse.
{: .definition }

a. Créer un programme en C

b. Ouvrir le fichier [notes.tsv](notes.tsv) en mode lecture.

c. Lire la totalité du fichier, les colonnes sont séparées par le caractère tabulation (chercher le code ascii).

Pour « découper » une chaine de caractères en colonnes, il faut chercher à l'intérieur de cette chaine le « séparateur » de colonne.

Dans notre cas le séparateur est le caractère tabulation \t.

La fonction C qui permet de chercher un séparateur (appelé token) est ***strtok***.

d. Pour chaque ligne calculer la moyenne des colonnes : anglais, litterature, mathemathiques, sciences et arts.

e. Définir une structure permettant de stocker toutes les valeurs en mode « machine ». N'oubliez pas la colonne moyenne.

f. Enregistrer les données en mode binaire dans un deuxième fichier (notes.bin)

g. Les notes sont des nombres décimaux et non pas des nombres réels. Utilisez une méthode intelligente pour stocker ces nombres.

### Correction

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int main()
{
  FILE *fp = fopen("notes.tsv", "r");
  FILE *fp2 = fopen("notes.bin", "wb"); // écriture binaire

  char chaine[100];

  typedef struct {
    char nom[40];
    char telephone[20];
    float anglais;
    float litterature;
    float math;
    float sciences;
    float arts;
    float moyenne;
  } Etudiant;

  Etudiant eleve;

  while (fgets(chaine, 100, fp))
  {
    printf("%s\n", chaine);

    int c = 0;
    char *colonne = strtok(chaine, "\t");
    
    while (colonne != NULL)
    {
      printf("%s\n", colonne);
      
      switch (c)
      {
        case 0:
        strcpy(eleve.nom, colonne);
        break;
     
       case 1:
        strcpy(eleve.telephone, colonne);
        break;
      
      case 2:
        eleve.anglais = atof(colonne);
        break;

      case 3:
        eleve.litterature = atof(colonne);
        break;

      case 4:
        eleve.math = atof(colonne);
        break;

      case 5:
        eleve.sciences = atof(colonne);
        break;

      case 6:
        eleve.arts = atof(colonne);
        break;
      }
      
      colonne = strtok(NULL, "\t");
      c++;
    }

    eleve.moyenne = (eleve.anglais + eleve.litterature + eleve.math + eleve.sciences + eleve.arts) / 5.0;
    printf("%s %f\n", eleve.nom, eleve.moyenne);
    fwrite(&eleve, sizeof(Etudiant), 1, fp2);
  }
  fclose(fp2);
  fclose(fp);
}
```
