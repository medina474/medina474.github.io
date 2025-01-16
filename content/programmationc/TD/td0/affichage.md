---
title: Affichage
---

la fonction printf est plus flexible. Elle permet de formater la sortie (comme afficher des variables, des entiers, des flottants, etc.). Elle n'ajoute pas de saut de ligne automatiquement à la fin, c'est au développeur de le faire.

```c
int jour = 9;
printf("Aujourd'hui nous sommes le %d\n", jour);
```

## Spécificateurs

### Entiers

Spécificateurs|Description
---|---
%d |  entier signé (base 10).
%i | Equivalent à %d, pour afficher un entier signé.
%u |  entier non signé (base 10).
%o |  entier non signé en base 8 (octal).
%x |  entier non signé en base 16 (hexadécimal) avec des lettres minuscules (a à f).
%X |  entier non signé en base 16 avec des lettres majuscules (A à F).
%ld ou %li |  entier signé de type long int.
%lu |  entier non signé de type long unsigned int.
%lld ou %lli |  entier signé de type long long int.
%llu |  entier non signé de type long long unsigned int.

Attention une erreur courante consiste à afficher dans le mauvais format


```c
unsigned int nombre = 4294967291;
printf("%i", nombre);
```

### Caractères

- %c : Affiche un seul caractère.
- %s : Affiche une chaîne de caractères (terminée par \0).

```c
char nom[] = "Jérôme";
printf("Bonjour %s\n", nom);
```
### Nombres à virgule flottante

Spécificateurs|Description
---|---
%f | notation décimale à virgule flottante.
%e | notation scientifique (forme exponentielle) avec un e minuscule.
%E | notation scientifique avec un E majuscule.
%g | Utilise soit la notation décimale (%f), soit la notation scientifique (%e), selon ce qui est le plus concis.
%G | Comme %g, mais avec un E majuscule pour la notation scientifique.
%lf | Affiche un double en notation décimale.
%Lf | Affiche un long double en notation décimale.

### Spécificateurs pour les pointeurs

- %p : Affiche l'adresse d'un pointeur en notation hexadécimale.

Comment afficher le caractère % si celui ci sert de spécificateur de format.
Il faut utiliser %%

## Caractères spéciaux

Spécificateurs|Description
---|---
\0 | caractère null de fin de chaine
\t | tabulation horizontale
\n | nouvelle ligne (lf : line feed)
\r | retour chariot (cr: carriage return)
\f | saut de page (ff: form feed)
\v | tabulation verticale
\a | signal d'alerte (bell)
\b | retour arrière (backspace)
\\\\ | caractère antislash \\
\" | caractère guillemet "
\' | caractère apostrophe '

### Origine des caractères \r et \n

Les caractères ***Carriage Return*** (CR) et ***Line Feed***(LF) proviennent de l'époque des machines à écrire et des téléscripteurs. Ils sont directement liés aux mouvements de la tête d'impression.

Sur les machines à écrire, un "carriage return" signifie ramener le chariot d'écriture (où se trouve le papier) au début de la ligne, sans changer de ligne.

Sur une machine à écrire ou un téléscripteur, un "line feed" signifie faire avancer le papier d'une ligne vers le haut, permettant de commencer une nouvelle ligne tout en gardant le même positionnement horizontal.

Les téléscripteurs (comme ceux de la norme Teletype) utilisaient souvent ces deux commandes ensemble pour former une nouvelle ligne complète :

CR+LF : Ramener le curseur au début de la ligne (CR) et passer à la ligne suivante (LF). Cela a été adopté comme norme dans certains systèmes dont Windows à ces début.

Unix, conçu pour simplifier, a décidé de ne garder que LF pour représenter une fin de ligne.
