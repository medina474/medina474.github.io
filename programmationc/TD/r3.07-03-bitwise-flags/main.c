#include <stdio.h>

#define OPTION_GPS 0b000001
#define OPTION_CAMERA 0b000010
#define OPTION_AUTOMATIQUE 0b000100
#define OPTION_RADAR 0b001000
#define OPTION_ABS 0b010000
#define OPTION_ESP 0b100000

void main() {

  int vehicule1 = OPTION_CAMERA | OPTION_ABS;

  if (vehicule1 & OPTION_CAMERA)
  {
    printf("CAMERA OUI %d\n", vehicule1 & OPTION_CAMERA);
  }
  else
  {
    printf("CAMERA NON %d\n", vehicule1 & OPTION_CAMERA);
  }

  printf("lecture et écriture %d\n",   vehicule1);
  vehicule1 |= OPTION_ESP;

  printf("lecture et accès %d\n", vehicule1);

  int z = 13; // 1101
  printf("GPS %d\n", (z >> 0 & 1));
  printf("CAMERA %d\n", (z >> 1 & 1));
  printf("z est il en mode %d\n", (z >> 2 & 1));
  printf("z est il en acces %d\n", (z >> 3 & 1));

  puts("Retirer l'accés si il existe déja. Le remet sinon");
  z ^= OPTION_RADAR; // z = z XOR 0b1000;
  printf("GPS %d\n", (z >> 0 & 1));
  printf("CAMERA %d\n", (z >> 1 & 1));
  printf("z est il en mode %d\n", (z >> 2 & 1));
  printf("z est il en acces %d\n", (z >> 3 & 1));

  z = 13;
  puts("Retirer l'accès dans tous les cas");
  z &= ~OPTION_RADAR; // ! inversion logique uniquement 0 ou 1
                      // ~ inversion bits à bits
  printf("GPS %d\n", (z >> 0 & 1));
  printf("CAMERA %d\n", (z >> 1 & 1));
  printf("z est il en mode %d\n", (z >> 2 & 1));
  printf("z est il en acces %d\n", (z >> 3 & 1));
}
