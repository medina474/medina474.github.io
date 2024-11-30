#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int identifiant;
  int code_postal;
  char presence[2];
  char adresse[31];
  char commune[31];
  int automate; // Non = 0 ; Oui = 1
  char mise_a_jour[11];
  double prix_Gazole;
  double prix_SP95;
  double prix_SP98;
  double prix_GPLc;
  double prix_E10;
  double prix_E85;
  char marque[21];
  char geo_point[21];
  int code;
} PrixCarburant;

void RemplacerVirgule(char *nombre) {
  char *p = strchr(nombre, ',');
  if (p != NULL) p[0] = '.';
}

// * Etoile pointeur sur donnees
void RemplirDonnees(PrixCarburant *d, char valeur[100], int colonne) {

  switch (colonne)
  {
  case 0:
    // ->    (*d).identifiant
    d->identifiant = atoi(valeur);
    break;

  case 1:
    d->code_postal = atoi(valeur);
    break;

  case 2:
    strcpy(d->presence, valeur);
    break;
  
  case 3:
    strcpy(d->adresse, valeur);
    break;

  case 4:
    strcpy(d->commune, valeur);
    break;

  case 5:
    d->automate = strcmp("Oui",valeur);
    break;

  case 6:
    strcpy(d->mise_a_jour, valeur);
    break;

  case 7:
    RemplacerVirgule(valeur);
    d->prix_Gazole = atof(valeur);
    break;

  case 8:
    RemplacerVirgule(valeur);
    d->prix_SP95 = atof(valeur);
    break;

  case 9:
    RemplacerVirgule(valeur);
    d->prix_SP98 = atof(valeur);
    break;

  case 10:
    RemplacerVirgule(valeur);
    d->prix_GPLc = atof(valeur);
    break;

  case 11:
    RemplacerVirgule(valeur);
    d->prix_E10 = atof(valeur);
    break;
  
  case 12:
    RemplacerVirgule(valeur);
    d->prix_E85 = atof(valeur);
    break;

  case 13:
    strcpy(d->marque, valeur);
    break;

  case 14:
    strcpy(d->geo_point, valeur);
    break;

  case 15:
    d->code = atoi(valeur);
    break;

  default:
    break;
  }

}

void AfficherDonnees(PrixCarburant *d) {
  printf("%s %s\n", d->marque, d->commune);
  printf("***** PRIX\n");
  printf("%f %f %f %f %f %f\n", d->prix_Gazole, d->prix_SP98, d->prix_SP95, d->prix_GPLc, d->prix_E85, d->prix_E10);
}

int main() {
  FILE *fp = fopen("prix-des-carburants.csv", "r");
  if (fp == NULL) {
    perror("Error"); // print error
    exit(-1); // J'ai décidé que -1 est un code erreur
  }

  int ncolonne = 0, nligne = 0, ncaractere = 0;
  int drapeau_apostrophe = 0; // flag

  char buffer[100];
  PrixCarburant donnees;

  int caractere;
  // EOF : End Of File - fin du fichier
  while ((caractere = fgetc(fp)) != EOF) {
    putchar(caractere); // Afficher le caratère

    if (caractere == '\'') {
      drapeau_apostrophe = !drapeau_apostrophe;
    }
    else if (caractere == ',' && drapeau_apostrophe == 0) {
      // Nouvelle colonne
      buffer[ncaractere] = 0; // 0 A la fin pour spécifier 
      //de ne pas continuer sur les 100 caractères de buffer
      if (nligne > 0) RemplirDonnees(&donnees, buffer, ncolonne);
      ncolonne++;
      ncaractere=0;
      printf("colonne %d trouvée\n", ncolonne);
    }
    else if (caractere == '\n' && drapeau_apostrophe == 0) {
      // Nouvelle ligne
      AfficherDonnees(&donnees);
      ncolonne = 0;
      ncaractere=0;
      nligne++;
      printf("== ligne %d\n", nligne);
    } else {
      buffer[ncaractere] = caractere;
      ncaractere++;
    }
  }

  fclose(fp);
}
