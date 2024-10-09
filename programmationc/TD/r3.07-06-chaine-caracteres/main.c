#include <stdio.h>

void test() {
  char chaine3[30];
  strcpy(chaine3, "Ciao Luigi");

  char *p = chaine3;
  p = p + 10;
  printf("%i\n", *p);

  p = p + 10;
  printf("%i\n", *p);
}

void main() {
  char chaine[] = "Bonjour Jérôme";
  
  char *p = chaine;
  printf("%c\n", *p);
  
  p = p + 5;
  printf("%c\n", *p);

  char *chaine2 = "Salut Alice";

  p = chaine2;
  printf("%c\n", *p);

  p = p + 11;
  printf("%i\n", *p);

  char chaine3[30];
  strcpy(chaine3, "Ciao Luigi");

  p = chaine3;
  p = p + 10;
  printf("%i\n", *p);

  p = p + 10;
  printf("%i\n", *p);

  test();
}
