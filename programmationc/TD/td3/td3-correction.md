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
