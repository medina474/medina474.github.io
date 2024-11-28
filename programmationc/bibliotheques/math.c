#include <stdio.h>
#include <math.h>

int main() {
  printf("cos(π/3) = %f (1/2)\n", cos(3.141592 / 3));
  printf("sin(π/3) = %f (√3/2)\n", sin(3.141592 / 3));
  printf("tan(π/3) = %f (√3)\n", tan(3.141592 / 3));

  printf("acos(√3/2) = %f (π/6)\n", acos(0.866025));
  printf("asin(1) = %f (π/2)\n", asin(1));
  printf("atan(1) = %f (π/4)\n", atan(1));
  printf("atan2(-1, -1) = %f (-3π/4)\n", atan2(-1, -1));
}
