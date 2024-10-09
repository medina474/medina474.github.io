#include <stdio.h>

void main() {
  int myNumbers[] = {25, 50, 75, 100};

  printf("%d\n", myNumbers[0]);

  myNumbers[1] = 33;
  printf("%d\n", myNumbers[1]);

  int *p = myNumbers;
  printf("%d %p\n", *p, p);
  p = p + 1;
  printf("%d %p\n", *p, p);
  p = p + 1;
  printf("%d %p\n", *p, p);

  *p = 60;
  printf("%d\n", myNumbers[2]);

  int matrix[2][3] = { {1, 4, 2}, {3, 6, 8} };
  p = matrix[0];

  p = p + 5;
  printf("%d %p\n", *p, p);
}
