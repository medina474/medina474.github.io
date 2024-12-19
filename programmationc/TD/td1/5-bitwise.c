#include <stdio.h>

#define OPTION_GPS 0b000001
#define OPTION_CAMERA 0b000010
#define OPTION_AUTOMATIQUE 0b000100
#define OPTION_RADAR 0b001000
#define OPTION_ABS 0b010000
#define OPTION_ESP 0b100000

void affiche(int valeur) {
  printf("%d = %d %d %d %d %d %d\n", valeur,
   (valeur >> 5 & 1),
   (valeur >> 4 & 1),
   (valeur >> 3 & 1),
   (valeur >> 2 & 1),
   (valeur >> 1 & 1),
   (valeur >> 0 & 1));
}

void main() {

  int vehicule1 = OPTION_CAMERA | OPTION_ABS;
  affiche(vehicule1);

  // Test simple
  puts("");
  if (vehicule1 & OPTION_CAMERA)
  {
    printf("CAMERA OUI %d\n", vehicule1 & OPTION_CAMERA);
  }
  else
  {
    printf("CAMERA NON (%d)\n", vehicule1 & OPTION_CAMERA);
  }

  puts("");
  printf("Ajout de l'option ESP %d\n",   vehicule1);
  vehicule1 |= OPTION_ESP;
  affiche(vehicule1);

  puts("");
  puts("Retirer l'option RADAR si il existe déja. Le remet sinon");
  vehicule1 ^= OPTION_RADAR; // z = z XOR 0b1000;
  affiche(vehicule1);
  vehicule1 ^= OPTION_RADAR; // z = z XOR 0b1000;
  affiche(vehicule1);
  vehicule1 ^= OPTION_RADAR; // z = z XOR 0b1000;
  affiche(vehicule1);

  puts("");
  puts("Retirer l'option RADAR dans tous les cas");
  vehicule1 &= ~OPTION_RADAR; // ~ inversion bits à bits
                      // ! inversion logique uniquement 0 ou 1
  affiche(vehicule1);
}
