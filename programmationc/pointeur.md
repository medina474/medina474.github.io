---
title: Les pointeurs
---

Les pointeurs avec une fonction.
Solution plus efficace : on passe en paramètre deux pointeurs.

```c
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
  free(X);
  free(Y); // on libère la mémoire allouées aux pointeurs
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
