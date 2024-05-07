---
title: Les pointeurs
---

Qu'est-ce qu'un
pointeur?
C'est une variable qui
contient l'adresse d'une
autre variable.
On dit que le pointeur pointe
sur la variable.

L'opérateur &.
L'opérateur adresse & retourne l'adresse d'une variable en mémoire.

Exemple :
int i = 5;
printf'(" Voici i: %d\n",i);
printf'(" Voici son adresse : %p\n",&i);

Pour afficher l'adresse d'une variable ont utilise généralement %p qui affiche l'adresse en hexadécimal (4 octets).
L'adresses d'une variable correspond à l'adresse de début de la variable dans la mémoire.

Déclaration d'un pointeur.
Une variable de type pointeur se déclare à l'aide de l'objet
pointé précédé du symbole * (opérateur d'indirection).
Exemple :
int *pi; // pi est un pointeur pointant sur un entier
char *pc; // pc est un pointeur pointant sur un char
float *pf; // pf est un pointeur pointant sur un float
L'opérateur * désigne le contenu de l'adresse,
Exemple :
int *pi,X; // pi est un pointeur pointant sur un entier
pi = &X; // on initialise le pointeur pi
*pi = 5; // On charge l'entier pointé par pi avec la // valeur 5,
c'est en fait X

L'arithmétique des pointeurs.
On déplace un pointeur dans la mémoire à l'aide des opérateurs d'addition, de soustraction, d'incrémentation, de décrémentation.
On ne peut le déplacer que d'un nombre de cases mémoire multiple de la taille de la variable en mémoire.
Exemple :
int *pi;
char *pc;
*pi = 5;
*pc = 'A';

L'arithmétique des pointeurs.
Exemple :
int *pi; // pi pointe sur un objet de type entier (4 octets)
char *pc; // pc pointe sur un objet de type char (1 octet)
float *pf; // pf pointe sur un objet de type float (4 octets)
*pi = 145; // 145 est le contenu de la case mémoire pi
*pi+1 = 200; // 200 est de contenu des cases mémoires 4 cases
// après pi
*pi+2 = 500; // 500 est le contenu des cases mémoires 8 cases
// après pi
*pc = 'A'; // la case mémoire pc contient le code ASCII de A = 65
pc--; // on décrémente la valeur du pointeur pc de 1
*pf = 1.5; // 1,5 est stocké dans la case mémoire pf et les 4
// suivantes
pf++; // on incrémente la valeur du pointeur pf de 4 cases
//mémoires qui correspond à la taille d'un float

L'arithmétique des pointeurs.
Exemple :
int *pi,*qi,i;
pi = qi; // autorisé
i = pi + qi; // interdit : on ne peut pas additionner deux pointeurs
// ça n'a pas de sens
i = pi-qi; // autorisé : donne le nombre d'objets entre les deux
// pointeurs
I = pi*qi; // interdit : on ne peut pas multiplier deux pointeurs
// ça n'a pas de sens

Les pointeurs avec une fonction.
Exemple : Fonction qui prend un pointeur en paramètre d'entrée
int carre(int *A)
{
int Res;
Res = (*A) * (*A); // équivalent à : *A**A ou * A * * A
return (Res);
}
Void main(void)
{
int *X,Y;
X = (int*)malloc(1*sizeof(int)); // initialisation du pointeur sur le tas
// (heap) zone mémoire réservée aux
// données
*X = 2;
Y = carre(X);
}

Les pointeurs avec une fonction.
Exemple : Fonction qui prend un pointeur en paramètre d'entrée et retourne un pointeur.

```C
int *carre(int *A)
{
int *Res;
Res = (int*)malloc(1*sizeof(int));
*Res = (*A) * (*A); // équivalent à : *A**A ou * A * * A
return (Res);
}
Void main(void)
{
int *X,*Y;
X = (int*)malloc(1*sizeof(int));
Y = (int*)malloc(1*sizeof(int));
*X = 2;
Y = carre(X);
free(X);free(Y); // on libère la mémoire allouées aux pointeurs
}
```

Les pointeurs avec une fonction.
Solution plus efficace : on passe en paramètre deux pointeurs.

```C
void carre(int *A, int *Res)
{
*Res = (*A) * (*A); // équivalent à : *A**A ou * A * * A
}
void main(void)
{
int *X,*Y;
X = (int*)malloc(1*sizeof(int));
Y = (int*)malloc(1*sizeof(int));
*X = 2;
carre(X,Y);
free(X);free(Y); // on libère la mémoire allouées aux pointeurs
```

## Les pointeurs et les tableaux.

Le langage C gère un tableau comme un pointeur à la différence près qu'il réserve un emplacement dimensionné
par la déclaration.
Exemple : int T[50];
int i, *pi, T[10];
pi = &i; // *pi représente i car pi pointe sur i
*pi = 0; // c'est équivalent à i = 0
pi = &T[0]; // pi pointe maintenant sur le premier élément du tableau T
// *pi représente T[0]
*pi = 0; // équivalent à T[0] = 0;

Les pointeurs et les tableaux.
La déclaration de T[50] réserve en mémoire 50 entiers,
mais nous avons en même temps un nouveau pointeur
initialisé sur le début du tableau.
Exemple :
int *pi, T[10],X;
pi = T; // pi pointe sur le début du tableau soit le premier élément
*T = 0; // c'est équivalent à T[0] = 0
*(T+2) = 5; // c'est équivalent à T[2] = 5
*(pi+5) = 0; // équivalent à T[5] = 0;

Les tableaux en mémoire : Tableaux de
pointeurs
Exemple : tableau 1 dimension
char Tab1D[5];
Exemple : tableau 2 dimensions avec des chaines de caractères
char Tab2D [5][7] ={"UN","DEUX","TROIS","QUATRE","CINQ"};
On alloue le maximum pour ne pas avoir de problèmes de débordement.
Zones Mémoire Perdues

Les tableaux en mémoire : Tableaux de pointeurs

On déclare un tableau de pointeurs dans lequel chaque pointeur désigne l'adresse d'un autre tableau
Exemple : tableau 2 dimensions avec des chaines de caractères
char *Tab2D [5] ; 

Les tableaux en mémoire : Tableaux de
pointeurs

```C
char *Tab[] = { "UN" , "DEUX", "TROIS", "QUATRE", "CINQ"} ;
Tab[0]  pointe sur "UN"
Tab[1]  pointe sur "DEUX"
*Tab[0]  retourne sur 'U' de "UN"
*( Tab[0] + 1)  retourne sur 'N' de "UN"
*( Tab[1] + 2)  retourne sur 'U' de "DEUX"
```

Attention:
*Tab[4] + 1  retourne 'D' car *Tab[4]  'C' et 'C' + 1  'D'

Pointeur de pointeur:
Un pointeur de pointeur est un pointeur pointant sur un pointeur, pointant sur
un pointeur, . . . , pointant sur une variable. Cela permet de gérer des
tableaux sans aucune dimension prédéfinie.
Exemple : tableau de chaine de caractère
char *Tab[] = { "UN" , "DEUX", "TROIS", "QUATRE", "CINQ"} ;
char **p // déclaration d'un pointeur de pointeur
p = &Tab[0] // p pointe sur le début du tableau de chaines de caractères
// *  chaine **  caractère
*p  pointe sur "UN"
*(p+1)  pointe sur "DEUX"
**p  retourne sur 'U' de "UN"
*(*p + 1)  retourne sur 'N' de "UN"
*( *(p+1) + 2)  retourne sur 'U' de "DEUX"

## Allocation dynamique des pointeurs:

La déclaration d'un pointeur n'engendre pas de réservation en mémoire.
Si on ne réserve pas d'emplacement mémoire, le pointeur risque de pointer
sur d'autres variables : débordement de pointeur.

La réservation ou allocation mémoire pour les pointeurs est réalisée généralement dans une zone réservé appelé le tas (heap). On parle alors
d'allocation dynamique (modifiable à tout moment par programme).

On gère l'allocation dynamique de la mémoire avec les fonctions suivantes:
- malloc()
- calloc()
- realloc()
- free()


### malloc
La fonction malloc : void *malloc(taille);
 Elle alloue un bloc de mémoire de taille octets sur le tas
 Elle renvoie un pointeur sur la zone de type void (valable pour tous les
types) qu'il faut donc convertir en un type adapté aux données.
 Si l'allocation réussit, malloc renvoi un pointeur sur le bloc, elle échoue si
taille = 0 ou s'il n'y a pas assez de place en mémoire. Dans ce cas elle
retourne un pointeur nul : NULL
Ex:
int *p;
p = (int *) malloc(10 * sizeof(int) ); // réservation pour 10 entiers
if ( p== NULL) // test création du pointeur
{
printf("erreur d'allocation mémoire !!!");
// ici traitement de l'erreur ...
}

### calloc
La fonction calloc : void *calloc(nombre,taille);

Elle alloue un bloc de mémoire de (nombre x taille) octets sur le tas

Elle renvoie un pointeur sur la zone de type void (valable pour tous les
types) qu'il faut convertir en un type adapté aux données.

Si l'allocation réussit, calloc renvoi un pointeur sur le bloc, elle échoue si
taille = 0 ou s'il n'y a pas assez de place en mémoire. Dans ce cas elle
retourne un pointeur nul : NULL
Ex:
int *p;
p = (int *) calloc(10 , sizeof(int) ); // réservation pour 10 entiers
if ( p== NULL) // test création du pointeur
{
printf("erreur d'allocation mémoire !!!");
// ici traitement de l'erreur ...
}

### realloc
La fonction realloc : void *realloc( pointeur , newtaille );
Elle permet de changer la taille d'un bloc déjà alloué. Elle gère l'aspect
dynamique des pointeurs. Utilisable à tous moment dans le programme

Elle renvoie un pointeur sur la zone de type void (valable pour tous les
types) qu'il faut convertir en un type adapté aux données.

Si l'allocation réussit, calloc renvoi un pointeur sur le bloc, elle échoue si
taille = 0 ou s'il n'y a pas assez de place en mémoire. Dans ce cas elle
retourne un pointeur nul : NULL
Ex:int *p;
...
p = (int *) realloc( p , 20 * sizeof(int) );// réservation pour 10 entiers supplémentaires
if ( p== NULL) // test création du pointeur
{
printf("erreur d'allocation mémoire !!!");
// ici traitement de l'erreur ...
} !!! ATTENTION, les données peuvent être déplacées si l'espace n'est pas suffisant !!!

Allocation dynamique des pointeurs:
La fonction free : free ( pointeur );
 Elle permet de libérer l'espace mémoire alloué par les fonctions malloc(),
calloc() realloc()
Il est très important de libérer l'espace mémoire après utilisation, sinon
celui-ci devient inutilisable pour la suite du programme
Ex:
int *p;
p = (int *) malloc( 10 * sizeof(int) ); // réservation pour 10 entiers
if ( p== NULL) // test création du pointeur
{
printf("erreur d'allocation mémoire !!!");
// ici traitement de l'erreur ...
}
...
...
Free(p); // on libère la mémoire
