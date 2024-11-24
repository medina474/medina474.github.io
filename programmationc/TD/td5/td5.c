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
