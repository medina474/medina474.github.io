Qu'est-ce qu'un fichier ?
Un fichier est un ensemble d'informations stockées sur une
mémoire de masse (disque dur, CD-ROM, mémoire flash...)
En C, un fichier est une suite d'octets. Les informations
contenues dans un fichier ne sont pas forcément de même
type (char, int, float structure...)
L'adresse d'une information dans le fichier est donnée par
un pointeur.
Deux types de fichier:
 Les binaires : Dans un fichier dit "binaire", les
informations sont codées telles que comme en mémoire.
Se sont généralement des nombres.
 Les fichiers texte : Dans un fichier dit "texte", les
informations sont codées en ASCII. Ces fichiers sont
visualisable facilement avec un simple éditeur de texte. Le

Manipulation des fichiers
La lecture ou l'écriture dans un fichier n'est pas directe, mais
utilise une zone mémoire tampon.
Une structure spécifique gère ce tampon et d'autre variables
nécessaires à la gestion du processus.
typdef struct
{
char *buffer; // pointeur vers le tampon
char *ptr; // pointeur vers le caractère suivant dans le tampon
int cnt; // nombre de caractères dans le tampon
int flag; // bits donnant l'état du fichier
int fd; // descripteur (identifiant de fichier)
} FILE;

Ouverture des fichiers
Avant qu'un programme puisse manipuler un fichier, il doit
commencer par l'ouvrir.
FILE * fopen( char *nom_fichier, char *mode_acces);
Exemple:
#include <stdio.h>
void main(void)
{
FILE *fp;
fp = fopen("nomdufichier.dat","r"); // Ouverture du fichier en mode lecture
if (fp==NULL)
{
printf("Erreur d'ouverture de fichier\n");
}
...
...
}

Ouverture des fichiers
Les différents modes d'accès aux fichiers texte.
Pour les fichiers binaires, les modes d'accès sont: "rb","wb", "ab", "rb+",
"wb+", "ab+".
Mode
d'accè
s
cible résultat
"r" Ouvrir le fichier en lecture (read) fopen retourne NULL si le fichier
n'existe pas
"w" Ouvrir le fichier en écriture
(write)
Le fichier est créé s'il n'existe
pas. S'il existe le contenu est
écrasé et perdu
"a" Ajouter des données (append).
Ouverture en écriture à la fin du
fichier
Le fichier est créé s'il n'existe
pas
"r+" Ouvrir le fichier en lecture et en
écriture
Fopen retourne NULL si le fichier
n'existe pas
"w+" Ouvrir le fichier en lecture et en
écriture
Le fichier est créé s'il n'existe
pas. S'il existe le contenu est
écrasé et perdu
"a+" Ouvrir le fichier en lecture et en Le fichier est créé s'il n'existe

Fermeture des fichiers
Quand un fichier n'est plus utilisé, on le ferme. Cela annule sa
liaison avec le pointeur FILE correspondant.
Attention il ne faut pas oublier de fermer un fichier après
utilisation, car le nombre de fichiers susceptibles d'être ouverts
simultanément est limité (nombre de pointeurs FILE limité).
int fclose( FILE *pointeur_fichier);
Exemple:
#include <stdio.h>
void main(void)
{
FILE *fp;
...
...
fclose(fp); // Fermeture du fichier, retourne 0 si pas d'erreur sinon EOF
}

Les fichiers
Lecture et écriture en mode caractère:
Lecture :
int fgetc( FILE *pointeur_fichier);
La fonction fgetc retourne le caractère lu sous la forme d'un int.
Si la valeur retourné est EOF ( EOF = -1), c'est que la fin de
fichier a été atteinte ou qu'il y a eu une erreur.
Exemple:
int c;
c = fgetc(fp);
Ecriture :
int fputc( int caractere, FILE *pointeur_fichier);
La fonction fputc transfère un caractère dans le fichier pointé par
pointeur_fichier. La fonction retourne le caractère écrit si pas
d'erreur, et EOF s'il y a une erreur.
Exemple:
fputc( 'A', fp);

Lecture et écriture en mode chaine:
Lecture :
char *fgets(char *pointeur_tampon,int nombre, FILE
*pointeur_fichier);
La fonction fgets lit dans le fichier à partir de la position
courante, nombre caractères et les range à l'emplacement pointé
par pointeur_tampon. La fonction s'arrête si un saut de ligne '\n'
a été lu ou si nombre-1 caractères ont été lu ou si c'est la fin de
fichier.
Exemple:
char stringbuf[81];
fgets(stringbuf, 81 , fp);
Ecriture :
char * fputs( char *pointeur_tampon, FILE *pointeur_fichier);
La fonction fputs écrit une chaine de caractère dans un fichier à
partir de la position courante.la fonction retourne une valeur
positive si pas d'erreur, et EOF s'il y a une erreur.

Lecture et écriture formatées:
Lecture :
char *fscanf(FILE *pointeur_fichier,char *chaine_formatee,
variables,..,..);
La fonction fscanf lit des données dans un fichier en les
formatant. Elle retourne le nombre de données correctement lues
si pas d'erreur. La valeur EOF signifie fin de fichier ou erreur.
Exemple: long num;
char nom[30];
char prenom[30];
...
fscanf(fp, "%ld %s %s",&num, nom, prenom);
Ecriture :
int * fprintf(FILE * pointeur_fichier,char *chaine_formatee,
variables,..,..);
La fonction fprintf écrit des données dans un fichier en les
formatant, elle retourne le nombre de données correctement
écrites si pas d'erreur, et EOF s'il y a une erreur.

Lecture et écriture en bloc:
Lecture :
int *fread(void *pointeur_Tampon,size-t taille,size_t nombre,FILE
*point_fic);
La fonction fread lit un bloc de données de taille x nombre octets
et le range à l'emplacement référencé par pointeur_tampon. Elle
retourne le nombre d'octets lus. Si la valeur est inférieur à
nombre alors erreur.
Exemple: struct client k[5];
...
fread(k, sizeof(struct client),5,fp);
Ecriture :
int * fwrite(void *pointeur_Tampon,size-t taille,size_t nombre,FILE
*point_fic);
La fonction fwrite écrit un bloc de données de taille x nombre
octets rangé à l'emplacement référencé par pointeur_tampon dans
le fichier pointé par point_fic. Elle retourne le nombre d'objets
complétement écrits. Si la valeur est inférieur à nombre alors
erreur.

Positionnement dans un fichier:
Jusqu'à présent on a supposé un accès séquentiel aux données
Si on veut accéder à la valeur C5 : il faut un accès direct aux données
donc positionner le pointeur de fichier au bon endroit

Positionnement dans un fichier:
int fseek(FILE *pointeur_fichier, long offset, int
base);
La fonction fseek permet de placer le pointeur de position sur un
octet quelconque d'un fichier. Le paramètre offset impose le
nombre d'octets dont il faut décaler le pointeur relativement à la
base. Si l'offset est négatif le déplacement s'effectue vers le début
du fichier. base précise l'origine du déplacement dans le fichier.
La fonction retourne 0 si pas d'erreur sinon un nombre non nul.
Exemple: fseek(fp,0,0); // on se place au début du fichier
fseek(fp,0,SEEK_END); // on se place à la fin du fichier
fseek(fp,-3,SEEK_END); // on se place 3 octets avant la fin du fichier

Lecture de la position du pointeur dans un
fichier:
long ftell(FILE *pointeur_fichier);
La fonction ftell permet de connaitre l'octet du fichier sur lequel
pointe le pointeur de fichier. La fonction retourne dans un entier
long la position courante dans le fichier à partir du début du
fichier. Retourne -1 en cas d'erreur.
Exemple:
long position ;
position = ftell(fp);
Exemple recherche de la taille d'un fichier (on considère le fichier ouvert)
long Taille;
fseek(fp,0,SEEK_END); // on se place en fin de fichier
Taille = ftell(fp); // lecture de la position dans le fichier