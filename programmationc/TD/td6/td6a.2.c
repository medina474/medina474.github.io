#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int identifiant;
  int code_postal;
  char presence[1];
  char adresse[30];
  char commune[30];
  int automate; // Non = 0 ; Oui = 1
  char mise_a_jour[10];
  double prix_Gazole;
  double prix_SP95;
  double prix_SP98;
  double prix_GPLc;
  double prix_E10;
  double prix_E85;
  char marque[20];
  char geo_point[20];
  int code;
} PrixCarburant;

int main() {
  FILE *fp = fopen("prix-des-carburants.csv", "r");
  if (fp == NULL) {
    perror("Error"); // print error
    exit(-1); // J'ai décidé que -1 est un code erreur
  }

  int ncolonne = 0, nligne = 0;
  int drapeau_apostrophe = 0; // flag

  int caractere;
  // EOF : End Of File - fin du fichier
  while ((caractere = fgetc(fp)) != EOF) {
    putchar(caractere); // Afficher le caratère

    if (caractere == '\'') {
      drapeau_apostrophe = !drapeau_apostrophe;
    }

    if (caractere == ',' && drapeau_apostrophe == 0) {
      ncolonne++;
      printf("colonne %d trouvée\n", ncolonne);
    }
    else if (caractere == '\n' && drapeau_apostrophe == 0) {
      ncolonne = 0;
      nligne++;
      printf("== ligne %d\n", nligne);
    }
  }

  fclose(fp);
}
