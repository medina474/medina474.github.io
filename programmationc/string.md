---
title: "String"
date: 2022-11-30T13:44:30+01:00
draft: true
---

## Saisie de chaine de caractères

La fonction scanf est prévue pour faire de la saisie de valeurs formatée. C’est à dire que l’on précise dans quel format doivent être saisies les variables.

```C
# include < stdio .h >
int main (int argc , char *argv[])
{
i n t nombre ,* pNombre ;
pNombre = ( i n t *) malloc ( s i z e o f ( i n t ) ) ;
scanf ("%d" ,& nombre ) ;
scanf ("%d",pNombre ) ;
printf (" Nombre 1 : %d\ nNombre 2 : %d",nombre ,* pNombre ) ;
}
```


Pour que la fonction scanf puisse s’occuper de la saisie des chaînes de caractères, il faut utiliser le format %s.
Une chaîne de caractères étant définie comme un pointeur, on ne met pas le
& devant la variable à saisir.

```C
# include < stdio .h >
int main (int argc , char *argv[])
{
  char texte[20];
  scanf ("%s",texte ) ;
  printf (" Texte saisi : %s",texte ) ;
}
```

A la fin de la saisie, le caractère ’\0’ est ajouté automatiquement.


Pour que le fonction scanf puisse s’occuper de la saisie des chaînes de caractères, il faut utiliser le format %s.

Une chaîne de caractères étant déja définie comme un pointeur, on ne met pas l'opérateur `&` devant la variable à saisir.

```C
# include < stdio .h >
int main (int argc , char *argv[])
{
  char texte[20];
  scanf ("%s",texte ) ;
  printf (" Texte saisi : %s",texte ) ;
}
```

> ATTENTION : scanf ne permet pas la saisie d'une chaîne comportant des espaces.
⇒ Les caractères saisis à partir de l’espace ne sont pas pris en compte mais restent rangés dans le tampon
d’entrée.
{.warning}

A la fin de la saisie, le caractère ’\0’ est ajouté automatiquement.

M’sieur, c’est quoi le tampon d’entrée ?

Lorsque vous tapez au clavier, chaque caractère est écrit dans un tampon (buffer en anglais). C’est dans ce tampon que scanf ira lire ;

Tout ce qui n’est pas lu
sera lu au prochain appel d’une fonction de lecture. Ainsi, si le tampon est plein, le scanf
prend le contenu commeci cela venait d’une saisie
opérateur ;

Le buffer d’entrée en langage C se nomme stdin.
Tampon
”Bonjour je m’appelle Bernard”
Mémoire
”Bonjour\0”
Le tampon est géré par le système d’exploitation
La mémoire est géré par le programme. Elle ne
contient que ce qui est lu
par le scanf scanf va lire le tampon et placer ce qu’elle a lu en mémoire.

 : Comment on fait alors m’sieur ?
On utilise un format particulier de la fonction scanf
On peut faire suivre le symbole % d’une liste de caractères entre crochets à la
place du s. Celle-ci peut être une liste de caractères interdits.
Ainsi, scanf lit alors jusqu’à ce qu’elle tombe sur un caractère interdit. Ce
caractère est principalement le retour chariot.

```C
# include < stdio .h >
int main (int argc , char *argv[])
{
c h a r nom [20];
scanf (" %[ˆ\ n]",nom) ; // lecture des caractères ( espace compris ) jusqu ’au retour chariot
}
```


On peut aussi ajouter une plage de caractères autorisés.
c h a r formule [];
scanf (" %[[0123456789/* -+=() ]ˆ\n]",formule ) ; // pour saisir des formules
c h a r voyelles [];
scanf ("%[[ aeiouy ]ˆ\n]",voyelles ) ; // pour saisir uniquement des voyelles
c h a r nom [];
scanf ("%[[a-z]ˆ\n]",voyelles ) ; // les lettres de l’alphabet en minuscule
c h a r nom [];
scanf ("%[[A-Z]ˆ\n]",voyelles ) ; // les lettres de l’alphabet en majuscule
int main (int argc , char *argv[])
Dans ce cas, la saisie s’arrête avec le retour chariot mais la phrase mise en
mémoire par le scanf sera stoppée au premier caractère en dehors de la plage.
Exemple avec les voyelles


## Manipulation

Pour manipuler les chaînes de caractères et faire les opérations courantes de traitement, il existe des fonctions prédéfinies qui nécessitent des inclusions de bibliothèques.
Les principales fonctions standards sont les suivantes :

string.h : fonctions pour calculer la longueur des chaînes, gérer la concaténation, la copie, la recherche et la comparaison ;

stdlib.h : fonctions pour gérer la conversion de type numérique en chaîne de caractères et vice-versa.

Longueur d’une chaîne de caractères
size t strlen(const char *str);
Cette fonction va nous permettre de récupérer la taille de n’importe quelle chaîne de caractères sans compter le ’\0’ final.
La fonction retourne un size t (entier long non signé) et prend en paramètre une chaîne de caractères.
Exemple
  char chaine[] = " toto va au bresil ";
i n t longueur ;
longueur = strlen ( chaine ) ;
printf (" Taille de la chaîne = %d\n", longueur ) ;

Copie de chaînes de caractères
char *strcpy(char *dest, const char *src);
Cette fonction copie une chaîne dans une autre chaîne et renvoie un pointeur
sur cette dernière. Elle copie tous les caractères, y compris le ’\0’.
Le problème est qu’elle ne fait aucune vérification sur les longueurs des chaînes
source et destination.
Exemple
c h a r chaineSrc [20] , chaineDest [20];
scanf (" %[ˆ\ n]",chaineSrc ) ;
chaineDest = strcpy ( chaineDest , chaineSrc ) ;
printf (" Chaîne 1 : %s - Chaîne 2 : %s\n",chaineSrc , chaineDest ) ;

Comparaison de chaînes de caractères
int strcmp(const char *chaine1, const char *chaine2);
Cette fonction permet de comparer deux chaînes de caractères, lettre par lettre.
Elle renvoie un entier qui sera :
I positif si chaine1 est supérieure à chaine2 (au sens de lexicographique) ;
I négatif si chaine1 est inférieure à chaine2 ;
I nul si les chaînes sont identiques.

Comparaison de chaînes de caractères

```C
char chaine1 [] = " Bonjour ";
char chaine2 [] = " Bonsoir ";
if ( strcmp ( chaine1 , chaine2 ) == 0)
{
printf ("Les chaines sont identiques .") ;
}
e l s e
{
printf ("Les chaines sont differentes .") ;
}
```

Concaténation de chaînes de caractères
char *strcat(char *dest, const char *src);
Cette fonction sert à concaténer deux chaînes, c’est à dire simplement coller
deux chaînes l’une à la suite de l’autre. Elle renvoie un pointeur sur la nouvelle
chaîne ainsi construite.
Pour éviter les problèmes, il faut s’assurer que la chaîne destination soit suffisamment grande (taille de dest + taille de src).

```C
c h a r dest [50] = "bon ";
c o n s t c h a r *src = " jour ";
printf (" Avant : %s\n", dest ) ;
dest = strcat (dest , src ) ;
printf (" Apres : %s\n", dest ) ;
```

Recherche dans les chaînes de caractères
Ces fonctions renvoient l’adresse de l’information recherchée en cas de succès,
sinon le pointeur NULL.
I char *strchr(const char *s, int c); : elle permet de rechercher
un caractère dans une chaîne. Elle renvoie un pointeur sur ce caractère.
Si le caractère est présent plusieurs fois, elle renvoie un pointeur sur la première occurrence ;
I char *strrchr(const char *s, int c); : la même que
précédemment mais retourne un pointeur sur la dernière occurrence ;
I char *strstr(const char *s1, const char *s2); : elle permet de savoir si s2 est inclue dans s1. Si elle trouve elle renvoie un pointeur sur la position dans s1. Son rˆole est donc de rechercher des sous-chaînes.

Conversion de chaîne de caractères en valeur numérique

I int atoi(const char *s); : conversion d’une chaîne de caractères en entier ;

I long atol(const char *s); : conversion d’une chaîne de caractères en entier long ;

double atof(const char *s); : conversion d’une chaîne de caractère en double.

Conversion de chaîne de caractères en valeur numérique

```C
#include <stdlib.h>
#include <stdio.h>

int main (int argc , char *argv[])
{
  char chaine[20];
  int conv ;
  printf ("\n\n\ nSaisir un entier : ") ;
  scanf (" %[[0123456789]ˆ\ n]",chaine ) ;
  conv = atoi ( chaine ) ;
  printf (" chiffre saisie : %d\n\n\n",conv ) ;
}
```

Conversion de valeur numérique en chaîne de caractères
int sprintf(char *str, const char *format, ...);
Cette fonction crée une chaîne de caractères qui sera stockée dans la variable str. La constitution de cette chaîne reprend le fonctionnement de printf, c’est à dire une chaîne formatée avec insertion des valeurs numériques.

```C
int main (int argc , char *argv[])
{
  char chaine[20];
  int chiffre = 145;
  sprintf (chaine ,"%d",chiffre ) ;
  sprintf (chaine ," repeat %d times ",chiffre ) ;
}
```
