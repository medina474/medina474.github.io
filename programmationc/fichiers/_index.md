---
title: Fichiers
--- 

Les fichiers texte : Dans un fichier dit texte, les informations sont codées en ASCII. Ces fichiers sont éditables. Le dernier octet de ces fichiers est EOF (End Of File : caractère ASCII spécifique).

Lorsqu'un programme doit lire ou écrire des données dans un fichier, le chemin pris par ces données pour arriver à leur destination passe par un tampon. Ce tampon est une zone de mémoire RAM dans laquelle sont temporairement stockées les données.
Cette zone tampon est gérée par une structure de type FILE. On l'utilise en déclarant un pointeur sur cette structure.

### Ouvrir un fichier


Mode d'accès | Cible | Résultat
---|---|---
"r"  | Ouvrir le fichier en lecture (read).         | fopen retourne NULL si le fichier n'existe pas.
"w"  | Ouvrir le fichier en écriture (write).       | Le fichier est crée s'il n'existe pas. S'il existe le contenu est écrasé et perdu.
"a"  | Ajouter des données (append). C.a.d ouvrir en écriture à la fin du fichier. | Le fichier est crée s'il n'existe pas.
"r+" | Ouvrir le fichier en lecture et en écriture. | fopen retourne NULL si le fichier n'existe pas.
"w+" | Ouvrir le fichier en lecture et en écriture. | Le fichier est crée s'il n'existe pas. S'il existe le contenu est écrasé et perdu.
"a+" | Ouvrir le fichier en lecture et en ajout.    | Le fichier est crée s'il n'existe pas.

Pour les fichiers binaires, les modes d'accès sont : "rb", "wb", "ab", "rb+", "wb+", "ab+".

### Fermer un fichier

Quand un fichier ne sert plus, on le ferme. Cela annule sa liaison avec le pointeur FILE correspondant. La fonction retourne 0 si pas d'erreur, sinon elle retourne `EOF`.

```
int fclose(FILE *pointeurFichier);
```

```C
#include <stdio .h>

void main(int argc, char *argv[])
{
  FILE *fp;
  fp = fopen ("donnes.dat", "r");
  ...
  fclose (fp);
}
```



### Lecture en mode caractère (fichiers ASCII)

```C
int fgetc(FILE *pointeurFichier);
```

La fonction fgetc retourne le caractère lu sous la forme d'un entier (int). Si la valeur retournée est EOF, c'est que la fin de fichier a été atteinte ou qu'il y a eu une erreur.

```C
#include <stdio .h>

void main(int argc, char *argv[])
{
  FILE *fp;
  int c;
  fp = fopen("donnes.rxr", "r");
  ...
  c = fgetc(fp);
  printf ("Caractere lu dans le fichier : %c", c) ;
  ...
  fclose (fp);
}
```

### Écriture en mode caractère (fichiers ASCII)


```C
char *fgets(char *pointeurTampon, int nombre, FILE *pointeurFichier);
```

La fonction fgets lit dans un fichier, à partir de la position courante, un certain nombre de caractères et les range à l'emplacement pointé par pointeur Tampon.
La fonction s'arrête si un saut de ligne '\n' a été lu, si nombre − 1 caractères ont été lus, ou si la fin de fichier a été atteinte.

```C
# include <stdio .h>

void main(int argc, char *argv[])
{
  FILE *fp;
  char stringbuffer [81];
  fp = fopen("donnees.dat ", "r") ;
  ...
  fgets(stringbuf, 81, fp);
  ...
  fclose(fp);
}
```

```C
char *fputs(char *pointeurTampon, FILE *pointeurFichier);
```

La fonction fputs écrit une chaîne de caractères dans un fichier à partir de la position courante. La fonction retourne une valeur positive si pas d'erreur, et EOF s'il y a eu une erreur.

```C
#include <stdio .h>

void main(int argc, char *argv[])
{
  FILE *fp;
  char *stringbuffer = " Coucou ";
  fp = fopen("donnees.txt", "w") ;
  ...
  fputs(stringbuf ,fp);
  ...
  fclose(fp);
}
```

```C
int fscanf(FILE *pointeurFichier, char *chaineFormatee);
```

La fonction fscanf lit des données dans un fichier en les formatant. Elle retourne le nombre de données correctement lues si pas d'erreur. La valeur de retour EOF signifie fin de fichier ou erreur.

```C
#include <stdio .h>

void main(int argc, char *argv[])
{
  FILE *fp;
  long numero ;
  char nom[30];
  long cp;
  char ville[30];
  fp = fopen("donnees.txt", "r");
  ...
  fscanf(fp ,"%ld %s %ld %s" ,&numero ,nom ,&cp , ville );
  ...
  fclose(fp);
}
```

int fprintf(FILE *pointeurFichier, char *chaineFormatee);

La fonction fprintf écrit des données dans un fichier en les formatant. Elle retourne le nombre de données correctement écrites si pas d'erreur. La valeur de retour EOF signifie erreur.

```C
#include <stdio .h>

void main(int argc, char *argv[])
{
  FILE *fp;
  long numero = 1253;
  char nom [] = "Dupont ";
  long cp = 88100;
  char ville [] = "Saint Die";
  fp = fopen("donnees.dat", "w");
  ...
  fprintf (fp ,"%ld %s %ld %s", numero ,nom , cp, ville) ;
  ...
  fclose (fp);
}
```

int fread(void *pointeurTampon, size t taille, size t nombre, FILE *pointeurFichier);

La fonction fread lit un bloc de données de taille x nombre octets et le range à l'emplacement référencé par pointeurTampon. Elle retourne le nombre d'objets complètement lus. Si la valeur est inférieure à nombre, alors il y a une erreur.

```C
#include <stdio .h>

void main(int argc, char *argv[])
{
  FILE *fp;
  struct client k[5];
  fp = fopen("donnees.dat", "rb") ;
  ...
  fread (k, sizeof(struct client), 5 ,fp);
  ...
  fclose(fp);
}
```

int fwrite(void *pointeurTampon, size t taille, size t nombre,
FILE *pointeurFichier);

La fonction fwrite écrit un bloc de données de taille x nombre octets rangé à l'emplacement référencé par pointeurTampon dans le fichier pointé par pointeur Fichier. Elle retourne le nombre d'objets complètement écrits.

Si la valeur est inférieure à nombre, alors il y a une erreur.

```C
#include <stdio .h>

void main(int argc, char *argv[])
{
  FILE *fp;
  struct client k[5];
  fp = fopen("donnees.dat", "wb") ;
  ...
  fwrite (k, sizeof ( struct client ), 5, fp) ;
  ...
  fclose (fp);
```

Jusqu'à présent, nous avons supposé un accès séquentiel au données.

int fseek(FILE *pointeurFichier, long offset, int base);

La fonction fseek permet de placer le pointeur de fichier sur un octet quelconque du fichier.

Le paramètre offset impose le nombre d'octets dont il faut décaler le pointeur relativement à base. Si offset est négatif, le déplacement s'effectue vers le début du fichier. base précise l'origine du déplacement dans le fichier.

Valeur de base Constante symbolique Signification
0 SEEK SET Début du fichier.
1 SEEK CUR Position actuelle dans le fichier.
2 SEEK END Fin du fichier.

fseek (fp ,0 ,0) ; /* on se place au début du fichier */
...
fseek (fp , -3 , SEEK_END ) ; /* on se place 3 octets avant la fin du fichier */

```C
#include <stdio .h>

void main(int argc, char *argv[])
{
  FILE *fp;
  long position ;
  fp = fopen("donnees.dat ", "r") ;
  ...
  position = ftell(fp) ;
  printf("La position actuelle dans le fichier est : %ld",position ) ;
  ...
  fclose(fp);
}
```
