#include <stdio.h>
#include <limits.h>

int main()
{
  puts("**************************************************");
  puts("Entiers");

  puts("");
  printf("char  : %d octet (%d bits)\n", sizeof(unsigned char), CHAR_BIT);
  printf("Non signé :    0 / %d\n", UCHAR_MAX);
  printf("Signé     : %d / %d\n", SCHAR_MIN, SCHAR_MAX);

  puts("");
  printf("short int : %d octets (%d bits)\n", sizeof(unsigned short int), __SHRT_WIDTH__);
  printf("Valeur maximale : %d\n", USHRT_MAX);
  printf("Signé : %d / %d\n", SHRT_MIN, SHRT_MAX);

  puts("");
  printf("int   : %d octets (%d bits)\n", sizeof(int), __INT_WIDTH__);
  printf("Valeur maximale : %u\n", UINT_MAX);
  printf("Signé : %d / %d\n", INT_MIN, INT_MAX);

  puts("");
  puts("Un long peut être 32 bits ou 64 bits selon le système");
  printf("long int : %d octets (%d bits)\n", sizeof(long int), __LONG_WIDTH__);
  printf("Valeur maximale : %lu\n", ULONG_MAX);
  printf("Signé : %ld / %ld\n", LONG_MIN, LONG_MAX);

  puts("");
  puts("Un long long int est garanti d'être au moins de 64 bits");
  printf("long long int : %d octets (%d bits)\n", sizeof(long long int), 64);
  printf("Valeur maximale : %llu\n", ULLONG_MAX);
  printf("Signé : %lld / %lld\n", LLONG_MIN, LLONG_MAX);
}
