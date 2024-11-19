---
title: Les fichiers
---

Un fichier est un ensemble d'informations stockées sur une mémoire de masse (disque dur, CD-ROM, mémoire flash...)

En C, un fichier est une suite d'octets. Les informations contenues dans un fichier ne sont pas forcément de même type (char, int, float structure...)

Le positionnement dans un fichier est donnée par un pointeur.

### Types de fichier

Les **binaires** : Dans un fichier dit "binaire", les informations sont codées telles que, comme en mémoire. Ce sont généralement des nombres. Ils ne sont pas lisibles sauf avec un éditeur hexadécimal ou le programme qui l'a écrit.

Les fichiers **texte** : Dans un fichier dit "texte", les informations sont codées en ASCII. Ces fichiers sont visualisable facilement avec un simple éditeur de texte.

### Manipulation des fichiers

La lecture ou l'écriture dans un fichier n'est pas directe, mais utilise une zone mémoire tampon.

Une structure spécifique gère ce tampon et d'autre variables nécessaires à la gestion du processus.

```C
typdef struct
{
  char *buffer; // pointeur vers le tampon
  char *ptr;    // pointeur vers le caractère suivant dans le tampon
  int cnt;   // nombre de caractères dans le tampon
  int flag;  // bits donnant l'état du fichier
  int fd;    // descripteur (identifiant de fichier)
} FILE;
```

#### Ouverture des fichiers

Avant qu'un programme puisse manipuler un fichier, il faut commencer par l'ouvrir.

Le but est d'accéder aux données, de stocker les informations dans une structure FILE afin de les réutiliser plus tard pour une lecture ou une écriture.

```C
// Déclaration
FILE * fopen(char *nom_fichier, char *mode_acces);
```

```C
#include <stdio.h>

void main(void)
{
  FILE *fp;
  fp = fopen("nomdufichier.dat","r"); // Ouverture du fichier en mode lecture
  if (fp==NULL)
  {
    puts("Erreur d'ouverture de fichier");
  }
...
...
}
```

##### Les différents modes d'accès aux fichiers.


|Mode|Description|
|---|---|
r  | Ouvre un fichier en lecture seule. Le fichier doit exister. Si le fichier n'existe pas, fopen retourne NULL.
w  | Ouvre un fichier en écriture seule. Si le fichier existe, son contenu est effacé. Si le fichier n'existe pas, il est créé.
a  | Ouvre un fichier en mode ajout. Si le fichier existe, les données sont ajoutées à la fin du fichier. Si le fichier n'existe pas, il est créé.
r+ | Ouvre un fichier en lecture et écriture. Le fichier doit exister.
w+ | Ouvre un fichier en lecture et écriture. Si le fichier existe, son contenu est effacé. Si le fichier n'existe pas, il est créé.
a+ | Ouvre un fichier en lecture et écriture. Si le fichier existe, les données sont ajoutées à la fin du fichier. Si le fichier n'existe pas, il est créé.


En C, les fichiers peuvent être ouverts en mode texte ou en mode binaire. Par défaut, les modes ci-dessus ouvrent les fichiers en mode texte, ce qui signifie que certaines conversions peuvent être effectuées (par exemple, la conversion des sauts de ligne entre les systèmes). Si vous travaillez avec des fichiers binaires (comme des images ou des fichiers exécutables), vous devez spécifier que vous ouvrez le fichier en mode binaire en ajoutant b au mode d'ouverture.

Pour les fichiers binaires, les modes d'accès sont: "rb","wb", "ab", "rb+", "wb+", "ab+".

#### Remarques

- Si fopen ne parvient pas à ouvrir le fichier (par exemple, si le fichier n'existe pas en mode lecture), il retourne NULL. Il est donc essentiel de vérifier le retour de fopen avant de procéder à toute autre opération.
- Après avoir terminé les opérations sur le fichier, il est important de fermer le fichier à l'aide de fclose(FILE *file) pour libérer les ressources.
- Le fichier est créé s'il n'existe pas. S'il existe le contenu est écrasé et perdu

#### Fermeture des fichiers

Quand un fichier n'est plus utilisé, on le ferme. Cela annule sa liaison avec le pointeur FILE correspondant.

Attention il ne faut pas oublier de fermer un fichier après utilisation, car le nombre de fichiers susceptibles d'être ouverts simultanément est limité (nombre de pointeurs FILE limité).

```c
// Déclaration
int fclose( FILE *pointeur_fichier);
```

```C
#include <stdio.h>

void main(void)
{
  FILE *fp;
  ...
  ...
  fclose(fp); // Fermeture du fichier, retourne 0 si pas d'erreur sinon EOF
}
```

Il ne faut pas oublier de fermer un fichier après utilisation car le nombre de fichiers susceptibles d'être ouverts simultanément est limité (nombre de pointeurs FILE limité).

### Lecture et écriture en mode caractère

#### Lecture :

```c
// Déclaration
int fgetc(FILE *pointeur_fichier);
```

La fonction fgetc retourne le caractère lu sous la forme d'un int.

Si la valeur retourné est EOF ( EOF = -1), c'est que la fin de fichier a été atteinte ou qu'il y a eu une erreur.

```C
int c;
c = fgetc(fp);
```

#### Ecriture :

```c
// Déclaration
int fputc(int caractere, FILE *pointeur_fichier);
```

La fonction fputc transfère un caractère dans le fichier pointé par pointeur_fichier. La fonction retourne le caractère écrit si pas d'erreur, et EOF s'il y a une erreur.

```C
fputc('A', fp);
```

### Lecture et écriture en mode chaine

#### Lecture :

```c
// Déclaration
char *fgets(char *pointeur_tampon, int nombre, FILE *pointeur_fichier);
```

La fonction fgets lit dans le fichier à partir de la position courante, nombre caractères et les range à l'emplacement pointé par pointeur_tampon. La fonction s'arrête si un saut de ligne '\n' a été lu ou si nombre-1 caractères ont été lu ou si c'est la fin de fichier.

```C
char stringbuf[81];
fgets(stringbuf, 81 , fp);
```

#### Ecriture :

```c
// Déclaration
char * fputs( char *pointeur_tampon, FILE *pointeur_fichier);
```

La fonction fputs écrit une chaine de caractère dans un fichier à partir de la position courante.la fonction retourne une valeur positive si pas d'erreur, et EOF s'il y a une erreur.

### Lecture et écriture formatées

#### Lecture :

```c
// Déclaration
char *fscanf(FILE *pointeur_fichier,char *chaine_formatee, variables,..,..);
```

La fonction fscanf lit des données dans un fichier en les formatant. Elle retourne le nombre de données correctement lues si pas d'erreur. La valeur EOF signifie fin de fichier ou erreur.

```C long num;
char nom[30];
char prenom[30];
...
fscanf(fp, "%ld %s %s",&num, nom, prenom);
```

#### Ecriture :

```c
// Déclaration
int * fprintf(FILE * pointeur_fichier,char *chaine_formatee, variables,..,..);
```

La fonction fprintf écrit des données dans un fichier en les formatant, elle retourne le nombre de données correctement écrites si pas d'erreur, et EOF s'il y a une erreur.

### Lecture et écriture en bloc:

#### Lecture :

```c
// Déclaration
int *fread(void *pointeur_Tampon,size-t taille,size_t nombre,FILE *point_fic);
```

La fonction fread lit un bloc de données de taille x nombre octets et le range à l'emplacement référencé par pointeur_tampon. Elle retourne le nombre d'octets lus. Si la valeur est inférieur à
nombre alors erreur.

```C
struct client k[5];
...
fread(k, sizeof(struct client), 5, fp);
```

#### Ecriture :

```c
// Déclaration
int * fwrite(void *pointeur_Tampon,size-t taille,size_t nombre,FILE *point_fic);
```

La fonction fwrite écrit un bloc de données de taille x nombre octets rangé à l'emplacement référencé par pointeur_tampon dans

le fichier pointé par point_fic. Elle retourne le nombre d'objets complétement écrits. Si la valeur est inférieur à nombre alors erreur.

### Positionnement dans un fichier:

Jusqu'à présent on a supposé un accès séquentiel aux données

Si on veut accéder à la valeur C5 : il faut un accès direct aux données donc positionner le pointeur de fichier au bon endroit

Positionnement dans un fichier:

```c
// Déclaration
int fseek(FILE *pointeur_fichier, long offset, int base);
```

La fonction fseek permet de placer le pointeur de position sur un octet quelconque d'un fichier. Le paramètre offset impose le nombre d'octets dont il faut décaler le pointeur relativement à la base. Si l'offset est négatif le déplacement s'effectue vers le début du fichier. base précise l'origine du déplacement dans le fichier.

La fonction retourne 0 si pas d'erreur sinon un nombre non nul.

```C
fseek(fp,0,0); // on se place au début du fichier
fseek(fp,0,SEEK_END); // on se place à la fin du fichier
fseek(fp,-3,SEEK_END); // on se place 3 octets avant la fin du fichier
```

#### Lecture de la position du pointeur dans un fichier

```c
// Déclaration
long ftell(FILE *pointeur_fichier);
```

La fonction ftell permet de connaitre l'octet du fichier sur lequel pointe le pointeur de fichier. 

La fonction retourne dans un entier long la position courante dans le fichier à partir du début du fichier. Retourne -1 en cas d'erreur.

```C
long position ;
position = ftell(fp);
```

Exemple recherche de la taille d'un fichier (on considère le fichier ouvert)

```C
long taille;
fseek(fp, 0, SEEK_END); // on se place en fin de fichier
taille = ftell(fp); // lecture de la position dans le fichier
```