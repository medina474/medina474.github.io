#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
  int identifiant;
  char code_postal[6];
  char presence[2];
  char adresse[31];
  char ville[31];
  short automate;
  int date_mise_a_jour;
  int Gazole;
  int SP95;
  int SP98;
  int GPLc;
  int E10;
  int E85;
  char marque[21];
  char geo_point[31];
  char code[6];
} PrixCarburant;

int ConvertirNombreVirgule(char *valeur) {
  char *virgule = strstr(valeur, ","); // Cherche la virgule
  if (virgule != NULL) virgule[0] = '.'; // Remplace la virgule par point
  return (int)(atof(valeur) * 1000);
  // Convertir en float (nombre à virgule) 
  // multiplié par mille et conversion entière
}

// * pointeur . On ne travaille sur une copie de PrixCarburant
// mais sur la variable d'origine du pointeur
void RemplirStructure(PrixCarburant *prix, char *valeur, int ncolonne) {

  switch (ncolonne)
  {
  case 0:
    // -> Equivalent à (*prix).identifiant
    prix->identifiant = atoi(valeur);
    break;
  
  case 1:
    strcpy(prix->code_postal, valeur);
    break;

  case 2:
    strcpy(prix->presence, valeur);
    break;

  case 3:
    strcpy(prix->adresse, valeur);
    break;

  case 4:
    strcpy(prix->ville, valeur);
    break;

  case 5:
    prix->automate = strcmp("Oui", valeur); // string compare
    break;

  case 6:
    prix->date_mise_a_jour = 0;
    break;

  case 7:
    prix->Gazole = ConvertirNombreVirgule(valeur);
    break;

  case 8:
    prix->SP95 = ConvertirNombreVirgule(valeur);
    break;

  case 9:
    prix->SP98 = ConvertirNombreVirgule(valeur);
    break;

  case 10:
    prix->GPLc = ConvertirNombreVirgule(valeur);
    break;

  case 11:
    prix->E10 = ConvertirNombreVirgule(valeur);
    break;

  case 12:
    prix->E85 = ConvertirNombreVirgule(valeur);
    break;

  case 13:
    strcpy(prix->marque, valeur);
    break;  

  case 14:
    strcpy(prix->geo_point, valeur);
    break;

  case 15:
    strcpy(prix->code, valeur);
    break;
  
  default:
    break;
  }
}

void AfficherStructure(PrixCarburant prix) 
{
  printf("**********\n");
  printf("%s (%d)\n", prix.marque, prix.identifiant);
  printf("%.3f %.3f %.3f %.3f %.3f %.3f\n", prix.Gazole / 1000.0, prix.SP95 / 1000.0, prix.SP98 / 1000.0, prix.GPLc / 1000.0, prix.E10 / 1000.0, prix.E85 / 1000.0);
  printf("%s %s %s\n", prix.adresse, prix.code_postal, prix.ville);
}

int main() {

  FILE *fp = fopen("prix-des-carburants.csv", "r");
  if (fp == NULL) {
    perror("Error");
    return -1; // Code de retour choisi arbitrairement
               // Par convention les nombres négatifs
               // signalent des erreurs
  }

  FILE *fp2 = fopen("carburant.bin", "wb");

  int ncaractere = 0;
  int ncolonne = 0;
  int nligne = 0;

  int caractere;
  int drapeau_apostrophe = 0;   //flag en anglais

  char buffer[200];

  PrixCarburant prix;

  // EOF : End Of File (fin du fichier)
  while ((caractere = fgetc(fp)) != EOF) 
  {
    if (caractere == '\'') {
      drapeau_apostrophe = !drapeau_apostrophe;
    }
    else if (caractere == ',' && !drapeau_apostrophe) {
      buffer[ncaractere] = 0;
      if (nligne >  0) RemplirStructure(&prix, buffer, ncolonne);
      ncolonne++;
      ncaractere = 0;
      //printf("nouvelle colonne %d\n", ncolonne);
    } 
    else if (caractere == '\n' && !drapeau_apostrophe) {
      AfficherStructure(prix);
      fwrite(&prix, sizeof(PrixCarburant), 1, fp2);
      ncolonne = 0;
      ncaractere = 0;
      nligne++;
    } 
    else {
      buffer[ncaractere] = caractere;
      ncaractere++;
    } 

    //putchar(caractere); // Ecrire à l'écran le caractère
  }


  fclose(fp);
  fclose(fp2);
}
