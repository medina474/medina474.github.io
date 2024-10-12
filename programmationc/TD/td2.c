#include <stdio.h>

float calculMoyenne(int tab[5]) {
  int somme = 0;
  for (int i = 0 ; i < 5 ; i++) {
    somme = somme + tab[i];
  }
  //return somme / 5; // 2 entiers -> entiers
  //return somme / 5.0; // 1 entier 1 float -> float
  return (float)somme / 5;  // cast conversion de type
}

float calculMoyenneN(int tab[], int nb) {
  int somme = 0;
  for (int i = 0 ; i < nb ; i++) {
    somme = somme + tab[i];
  }
  return (float)somme / nb;  // cast conversion de type
}

void main() {

  puts("Test de la fonction calculMoyenne");
  int t1[5] = { 1, 1, 1, 1, 1 };
  float r1 = calculMoyenne(t1);
  printf("Attendu 1 ; calculé %f\n", r1); 

  int t2[5] = { 1, 2, 3, 4, 5 };
  float r2 = calculMoyenne(t2);
  printf("Attendu 3 ; calculé %f\n", r2);

  int t3[5] = { 11, 8, 7, 13, 3 };
  float r3 = calculMoyenne(t3);
  printf("Attendu 8,4 ; calculé %f\n", r3);

  //exit(0);

  puts("Quelle est la taille du tableau");
  int taille;
  scanf("%d", &taille);
  int tableau[taille]; // variable-length array (VLA)
  // fonctionne que sur les versions récentes des compilateurs

  int *tableauP; // Un pointeur = une entrée sur une zone mémoire
  tableauP = malloc(taille * sizeof(int));
  // sizeof(int) = 4 octets
  // tableau 5 cases x 4 = 20 octets

  puts("Bonjour entrer des valeurs :");

  int p = 0;
  int q = 1;

  for (int i = 0 ; i < taille ; i++) {
    tableau[i] = 0;
  }

  while (1) {
    int valeur;
    scanf("%d", &valeur);
    if (valeur < 0) break;
    printf("valeur saisie = %d\n", valeur);
    tableau[p] = valeur;
    p++;
    if (p == taille) p = 0;

    float moyenne = calculMoyenneN(tableau, q);
    if (q < taille) q++;
    printf("Moyenne = %f\n", moyenne);
  }

  free(tableauP);
}
