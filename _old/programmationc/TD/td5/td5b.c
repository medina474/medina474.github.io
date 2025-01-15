#include <stdio.h>

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

int main() {
  FILE *fp = fopen("notes.bin", "rb"); // lecture binaire

  Etudiant eleve;
  int nombre = 0;
  float somme = 0.0;
  while(fread(&eleve, sizeof(Etudiant), 1, fp)) 
  {
    printf("%s %f %f %f %f %f\n", eleve.nom, eleve.moyenne, eleve.anglais, eleve.litterature, eleve.math, eleve.sciences);
    somme = somme + eleve.moyenne;
    nombre++;
  }
  printf("Moyenne générale : %f", somme / nombre);

}
