#include <stdio.h>
#include <limits.h>
#include <float.h>

void main()
{
  puts("**************************************************");
  puts("Flottants");

  puts("");
  printf("Base de l'exposant (FLT_RADIX) : %d\n", FLT_RADIX);

  puts("");
  printf("float : %d octets (%d bits)\n", sizeof(float), sizeof(float) * CHAR_BIT);
  printf("double : %d octets (%d bits)\n", sizeof(double), sizeof(double) * CHAR_BIT);
  printf("long double : %d octets (%d bits)\n", sizeof(long double), sizeof(long double) * CHAR_BIT);

  puts("");
  puts("Nombre de chiffres dans la mantisse à virgule flottante.");
  puts("La base spécifiée par FLT_RADIX est 2 ; par conséquent, ces valeurs spécifient des bits.");
  printf("float : %d / %d bits\n", FLT_MANT_DIG, sizeof(float) * CHAR_BIT);
  printf("double : %d / %d bits\n", DBL_MANT_DIG, sizeof(double) * CHAR_BIT);
  printf("long double : %d / %d bits\n", LDBL_MANT_DIG, sizeof(long double) * CHAR_BIT);

  puts("");
  puts("Nombre de chiffres significatifs, q, de sorte qu'un nombre à virgule flottante avec q chiffres décimaux peut être arrondi en représentation à virgule flottante puis restauré à sa valeur initiale sans perte de précision.");
  printf("float : %d\n", FLT_DIG);
  printf("double : %d\n", DBL_DIG);
  printf("long double : %d\n", LDBL_DIG);

  puts("");
  puts("Plus petit nombre positif x de sorte que x + 1.0 n'est pas égal à 1.0");
  printf("Epsilon : %e\n", FLT_EPSILON);
  printf("Epsilon : %e\n", DBL_EPSILON);
  printf("Epsilon : %Le\n", LDBL_EPSILON);

  puts("");
  puts("Entier maximal et minimal de sorte que 2 élevé à la puissance de ce nombre est un nombre à virgule flottante qui peut être représenté.");
  printf("float : %d^%d | %d^%d\n", FLT_RADIX, FLT_MAX_EXP, FLT_RADIX, FLT_MIN_EXP);
  printf("double : %d^%d | %d^%d\n", FLT_RADIX, DBL_MAX_EXP, FLT_RADIX, DBL_MIN_EXP);
  printf("long double : %d^%d | %d^%d\n", FLT_RADIX, LDBL_MAX_EXP, FLT_RADIX, LDBL_MIN_EXP);

  puts("");
  puts("Ce qui reveint dans le système en base 10");
  printf("float : 10^%d | 10^%d\n", FLT_MAX_10_EXP, FLT_MIN_10_EXP);
  printf("double : 10^%d | 10^%d\n", DBL_MAX_10_EXP, DBL_MIN_10_EXP);
  printf("long double : 10^%d | 10^%d\n", LDBL_MAX_10_EXP, LDBL_MIN_10_EXP);

  puts("");
  puts("Valeur positive maximale.");
  printf("float : %.6e (%.0lf)\n", FLT_MAX, FLT_MAX);
  puts("");
  printf("double : %.15e (%.0lf)\n", DBL_MAX, DBL_MAX);
  puts("");
  printf("long double %.18Le (%.0Lf)\n", LDBL_MAX, LDBL_MAX);

  puts("");
  puts("Valeur positive minimale.");
  printf("float : %.6e (%.44lf)\n", FLT_MIN, FLT_MIN);
  puts("");
  printf("double : %.15e (%.323lf)\n", DBL_MIN, DBL_MIN);
  puts("");
  printf("long double %.18Le (%.4950Lf)\n", LDBL_MIN, LDBL_MIN);

  puts("");
  float r = 15 / 2;
  printf("%f\n", r);
}
