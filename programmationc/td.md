---
title: Travaux dirigés
----

### Exercice 1 : Installation de l'environnement de développement

Télécharger W64DevKit pour Windows

[https://github.com/skeeto/w64devkit](https://github.com/skeeto/w64devkit)

Dans la rubrique Releases (bandeau à droite)

Prendre l'executable pour 64 bits

Installer sur la partition D:\

Modifier les variables d'environnement pour votre compte

Dans la variable Path ajouter D:\w64devkit\bin

Lancer VSCode

Ajouter l'extension C/C++ de Microsoft

Créer un dossier TP dans D:\

Ouvrir ce dossier avec VSCode

### Exercice 2 : Premier programme

La fonction puts en C est utilisée pour afficher une chaîne de caractères (_string_) sur la sortie standard, généralement la console.

Une particularité de puts est qu'après avoir affiché la chaîne, elle ajoute automatiquement un caractère de nouvelle ligne (\n). Cela signifie que le curseur passe à la ligne suivante après l'affichage du texte.

Créer un fichier main.c

```c
#include <stdio.h>

void main() {
  puts("Bonjour Jérôme");
}
```

Cliquer sur l'icone de menu Run & Debug

Créer 2 fichier dans le dossier .VSCode


tasks.json

```json
{
  "tasks": [
    {
      "type": "cppbuild",
      "label": "Compilation",
      "command": "D:/w64devkit/bin/gcc.exe",
      "args": [
        "-fdiagnostics-color=always",
        "-g",
        "${workspaceFolder}${pathSeparator}main.c",
        "-o",
        "${workspaceFolderBasename}.exe"
      ],
      "options": {
        "cwd": "D:/w64devkit/bin"
      },
      "problemMatcher": [
        "$gcc"
      ],
      "group": {
        "kind": "build",
        "isDefault": true
      },
      "presentation": {
        "reveal": "silent",
        "revealProblems": "onProblem",
        "close": true
      }
    }
  ],
  "version": "2.0.0"
}
```

launch.json

```json
{
  // Use IntelliSense to learn about possible attributes.
  // Hover to view descriptions of existing attributes.
  // For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387
  "version": "0.2.0",
  "configurations": [
    {
      "name": "Lancer",
      "type": "cppdbg",
      "request": "launch",
      "program": "${workspaceFolder}${pathSeparator}${workspaceFolderBasename}.exe",
      "args": [],
      "stopAtEntry": false,
      "cwd": "${workspaceFolder}",
      "environment": [],
      "externalConsole": false,
      "MIMode": "gdb",
      "miDebuggerPath": "gdb",
      "setupCommands": [
        {
            "description": "Enable pretty-printing for gdb",
            "text": "-enable-pretty-printing",
            "ignoreFailures": true
        },
        {
            "description": "Set Disassembly Flavor to Intel",
            "text": "-gdb-set disassembly-flavor intel",
            "ignoreFailures": true
        }
      ],
      "preLaunchTask": "Compilation"
    }
  ]
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

### Lecture clavier

La fonction scanf en C est utilisée pour lire des entrées formatées depuis l'entrée standard (généralement le clavier). Elle permet de capturer des valeurs saisies par l'utilisateur et de les stocker dans des variables. Son fonctionnement repose sur des spécificateurs de format, similaires à ceux utilisés avec la fonction printf, mais dans ce cas, pour la lecture.

Pour stocker la valeur lue, scanf a besoin de connaître l'adresse de la variable où stocker la donnée. Cela signifie que vous devez passer les adresses des variables à scanf (à l'aide de l'opérateur **&** pour obtenir l'adresse d'une variable).

Si vous oubliez le &, cela causera un comportement indéfini, car scanf essaiera de modifier une adresse mémoire incorrecte.

```c
int age;

printf("Entrez votre âge : ");
scanf("%d", &age);  // Lire un entier
```

Cas particulier des chaines de caractères.

La variable _nom_ est déja un pointeur il ne faut pas utiliser l'opérateur &

```c
char nom[50];
scanf("%s", nom); 
```

Le spécificateur %s lit une chaîne de caractères jusqu'à un espace ou une nouvelle ligne. Pour lire une phrase entière avec des espaces, vous devez utiliser une autre approche comme fgets.

#### fgets

La fonction fgets en C est utilisée pour lire une ligne de texte (ou une partie de ligne) depuis un flux d'entrée (comme le clavier ou un fichier), ce qui la rend idéale pour lire des chaînes de caractères qui peuvent contenir des espaces ou des caractères spéciaux. Contrairement à scanf, qui s'arrête à un espace, fgets continue à lire jusqu'à ce qu'elle rencontre un saut de ligne (\n), une fin de fichier ou le nombre maximal de caractères spécifié.

```c
char buffer[100];
fgets(buffer, 100, stdin);
```

### Tableaux

```c
void main() {
  int tableau[] = {25, 50, 75, 100};

  printf("%d\n", tableau[0]);

  tableau[1] = 33;
  printf("%d\n", tableau[1]);

  int *p = tableau;
  printf("%d %p\n", *p, p);
  p = p + 1;
  printf("%d %p\n", *p, p);
  p = p + 1;
  printf("%d %p\n", *p, p);

  *p = 60;
  printf("%d\n", tableau[2]);

  int matrix[2][3] = { {1, 4, 2}, {3, 6, 8} };
  p = matrix[0];

  p = p + 5;
  printf("%d %p\n", *p, p);
}
```

## Bitwise

```c
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

  printf("OPTION_CAMERA | OPTION_ABS %d\n",   vehicule1);
  vehicule1 |= OPTION_ESP;

  printf("OPTION_CAMERA | OPTION_ABS OPTION_ESP %d\n", vehicule1);

  int z = 13; // 1101
  printf("GPS %d\n", (z >> 0 & 1));
  printf("CAMERA %d\n", (z >> 1 & 1));
  printf("z est il en mode %d\n", (z >> 2 & 1));
  printf("z est il en acces %d\n", (z >> 3 & 1));

  puts("Retirer l'accLa fonction fgets en C est utilisée pour lire une ligne de texte (ou une partie de ligne) depuis un flux d'entrée (comme le clavier ou un fichier), ce qui la rend idéale pour lire des chaînes de caractères qui peuvent contenir des espaces ou des caractères spéciaux. Contrairement à scanf, qui s'arrête à un espace, fgets continue à lire jusqu'à ce qu'elle rencontre un saut de ligne (\n), une fin de fichier ou le nombre maximal de caractères spécifié.és si il existe déja. Le remet sinon");
  z ^= OPTION_RADAR; // z = z XOR 0b1000;
  printf("GPS %d\n", (z >> 0 & 1));
  printf("CAMERA %d\n", (z >> 1 & 1));
  printf("OPTION_RADAR %d\n", (z >> 2 & 1));
  printf("OPTION_ABS %d\n", (z >> 3 & 1));

  z = 13;
  puts("Retirer l'accès dans tous les cas");
  z &= ~OPTION_RADAR; // ! inversion logique uniquement 0 ou 1
                      // ~ inversion bits à bits
  printf("GPS %d\n", (z >> 0 & 1));
  printf("CAMERA %d\n", (z >> 1 & 1));
  printf("OPTION_RADAR %d\n", (z >> 2 & 1));
  printf("OPTION_ABS %d\n", (z >> 3 & 1));
}
```
