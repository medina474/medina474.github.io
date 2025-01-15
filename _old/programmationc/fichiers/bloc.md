---
title: Les fichiers blocs
---

### Lecture :

```c
// Déclaration
int *fread(void *pointeur_Tampon,size-t taille,size_t nombre,FILE *point_fic);
```

La fonction fread lit un bloc de données de taille x nombre octets et le range à l'emplacement référencé par pointeur_tampon. Elle retourne le nombre d'octets lus. Si la valeur est inférieur à
nombre alors erreur.

```c
struct client k[5];
...
fread(k, sizeof(struct client), 5, fp);
```

### Ecriture :

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

```c
fseek(fp,0,0); // on se place au début du fichier
fseek(fp,0,SEEK_END); // on se place à la fin du fichier
fseek(fp,-3,SEEK_END); // on se place 3 octets avant la fin du fichier
```

### Lecture de la position du pointeur dans un fichier

```c
// Déclaration
long ftell(FILE *pointeur_fichier);
```

La fonction ftell permet de connaitre l'octet du fichier sur lequel pointe le pointeur de fichier. 

La fonction retourne dans un entier long la position courante dans le fichier à partir du début du fichier. Retourne -1 en cas d'erreur.

```c
long position ;
position = ftell(fp);
```

Exemple recherche de la taille d'un fichier (on considère le fichier ouvert)

```c
long taille;
fseek(fp, 0, SEEK_END); // on se place en fin de fichier
taille = ftell(fp); // lecture de la position dans le fichier
```
