---
title: Les pointeurs
---



Exemple :
int i = 5;
printf'(" Voici i: %d\n",i);
printf'(" Voici son adresse : %p\n",&i);

Pour afficher l'adresse d'une variable ont utilise généralement %p qui affiche l'adresse en hexadécimal (4 octets).


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
