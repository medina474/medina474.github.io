#include <stdio.h>
#include <string.h> 

int main()
{
  FILE *fp = fopen("notes.tsv", "r");

  char chaine[100];

  char nom[40];
  char telephone[20];
  float anglais;
  float litterature;
  float math;
  float sciences;
  float arts;

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
        strcpy(nom, colonne);
        break;
     
       case 1:
        strcpy(telephone, colonne);
        break;
      
      case 2:
        anglais = atof(colonne);
        break;

      case 3:
        break;

      case 4:
        break;

      case 5:
        break;
      }
      
      colonne = strtok(NULL, "\t");
      c++;
    }
  }
}
