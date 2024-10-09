---
title: Travaux dirigés
----

### Exercice 1 : Premier programme

La fonction puts en C est utilisée pour afficher une chaîne de caractères (_string_) sur la sortie standard, généralement la console.

Une particularité de puts est qu'après avoir affiché la chaîne, elle ajoute automatiquement un caractère de nouvelle ligne (\n). Cela signifie que le curseur passe à la ligne suivante après l'affichage du texte.

```c
#include <stdio.h>

void main() {
  puts("Bonjour Jérôme");
}
```

#### Sortie formatée

la fonction printf est plus flexible. Elle permet de formater la sortie (comme afficher des variables, des entiers, des flottants, etc.). Elle n'ajoute pas de saut de ligne automatiquement à la fin, c'est au développeur de le faire.

```c
int jour = 9;
printf("Aujourd'hui nous sommes le %d\n", jour);
```

##### Spécificateurs pour les entier

- %d : Affiche un entier signé (base 10).
- %i : Equivalent à %d, pour afficher un entier signé.
- %u : Affiche un entier non signé (base 10).
- %o : Affiche un entier non signé en base 8 (octal).
- %x : Affiche un entier non signé en base 16 (hexadécimal) avec des lettres minuscules (a à f).
- %X : Affiche un entier non signé en base 16 avec des lettres majuscules (A à F).
- %ld ou %li : Affiche un entier signé de type long int.
- %lu : Affiche un entier non signé de type long unsigned int.
- %lld ou %lli : Affiche un entier signé de type long long int.
- %llu : Affiche un entier non signé de type long long unsigned int.

Attention une erreur courante consiste à afficher dans le mauvais format


```c
unsigned int nombre = 4294967291;
printf("%i", nombre);
```

##### Spécificateurs pour les caractères

- %c : Affiche un seul caractère.
- %s : Affiche une chaîne de caractères (terminée par \0).

```c
char nom[] = "Jérôme";
printf("Bonjour %s\n", nom);
```
##### Spécificateurs pour les nombres à virgule flottante

- %f : Affiche un nombre en notation décimale à virgule flottante.
- %e : Affiche un nombre en notation scientifique (forme exponentielle) avec un e minuscule.
- %E : Affiche un nombre en notation scientifique avec un E majuscule.
- %g : Utilise soit la notation décimale (%f), soit la notation scientifique (%e), selon ce qui est le plus concis.
- %G : Comme %g, mais avec un E majuscule pour la notation scientifique.
- %lf : Affiche un double en notation décimale.
- %Lf : Affiche un long double en notation décimale.

##### Spécificateurs pour les pointeurs

- %p : Affiche l'adresse d'un pointeur en notation hexadécimale.

Comment afficher le caractère % si celui ci sert de spécificateur de format.
Il faut utiliser %%

### Retour de la fonction main

La fonction main en C retourne généralement une valeur entière, et ce retour a une signification particulière. Le retour de la fonction main est utilisé pour indiquer à l'environnement d'exécution du programme (comme le système d'exploitation) si le programme s'est terminé correctement ou s'il a rencontré une erreur. 

Signification des valeurs de retour

0 : En C, retourner 0 dans la fonction main signifie que le programme s'est exécuté avec succès et sans erreurs. Cela est considéré comme un "statut de succès" ou un "code de sortie" indiquant que tout s'est déroulé correctement.

Valeurs non-nulles (typiquement positives) : Si le programme rencontre une erreur, vous pouvez retourner une valeur différente de 0 (souvent une petite valeur positive comme 1). Cela signifie qu'il y a eu une erreur ou une condition particulière. Les systèmes d'exploitation ou d'autres programmes qui appellent ce programme peuvent interpréter cette valeur pour comprendre la nature de l'erreur.

```c
#include <stdio.h>

int main() {
  puts("Bonjour Jérôme");
  return 0;  // Indique une exécution réussie
}
```

Pour quitter le programme prématurément sans attendre la fin de la fonction main, il faut utiliser la fonction exit

```c
exit(1);
```

##### Lire le retour de la fonction 

Sous Windows, vous pouvez lire la valeur de sortie d'un programme de plusieurs façons, notamment via l'invite de commandes (cmd) ou un script batch. Le code de retour d'un programme est appelé code d'erreur ou exit code et peut être capturé avec la variable spéciale %ERRORLEVEL%.


```batch
@echo off
mon_programme.exe

if %ERRORLEVEL% equ 0 (
  echo Programme exécuté avec succès !
) else (
  echo Le programme a échoué avec le code de retour %ERRORLEVEL%.
)
```

### Les entiers

```c
puts("");
puts("Entiers");

puts("");
printf("char  : %d octet (%d bits)\n", sizeof(unsigned char), CHAR_BIT);
printf("Non signé : 0 / %d\n", UCHAR_MAX);
printf("Signé : %d / %d\n", SCHAR_MIN, SCHAR_MAX);
```

```c
puts("");
printf("short int : %d octets (%d bits)\n", sizeof(unsigned short int), __SHRT_WIDTH__);
printf("Valeur maximale : %d\n", USHRT_MAX);
printf("Signé : %d / %d\n", SHRT_MIN, SHRT_MAX);
```

```c
puts("");
printf("int   : %d octets (%d bits)\n", sizeof(int), __INT_WIDTH__);
printf("Valeur maximale : %u\n", UINT_MAX);
printf("Signé : %d / %d\n", INT_MIN, INT_MAX);
```

```c
puts("");
puts("Un long peut être 32 bits ou 64 bits selon le système");
printf("long int : %d octets (%d bits)\n", sizeof(long int), __LONG_WIDTH__);
printf("Valeur maximale : %lu\n", ULONG_MAX);
printf("Signé : %ld / %ld\n", LONG_MIN, LONG_MAX);
```

```c
puts("");
puts("Un long long int est garanti d'être au moins de 64 bits");
printf("long long int : %d octets (%d bits)\n", sizeof(long long int), __LONG_LONG_WIDTH__);
printf("Valeur maximale : %llu\n", ULLONG_MAX);
printf("Signé : %lld / %lld\n", LLONG_MIN, LLONG_MAX);
```

```c
```

```c
```

```c
```
