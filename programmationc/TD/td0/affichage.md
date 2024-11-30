---
title: Affichage
---

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
