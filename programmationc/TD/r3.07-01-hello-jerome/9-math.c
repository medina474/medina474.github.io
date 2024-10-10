#include <stdio.h>

void main() {

  int a = 5;
  const char *chaine1 = "Bonjour";
  int b = 5;
  char chaine2[] = "Bonjour";
  int c = 5;

  //chaine1[3] = 'T';
  chaine2[3] = 'T';
  printf("%s", chaine2);

  printf("%p %p %p %p %p", chaine1, chaine2, &a, &b, &c);
}
