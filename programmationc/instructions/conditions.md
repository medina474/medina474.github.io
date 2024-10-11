---
title: Instructions conditionnelles
---

> Les instructions conditionnelles en C permettent d'exécuter des blocs de code spécifiques en fonction de conditions. Elles permettent de prendre des décisions logiques dans un programme.

## if

L'instruction _if_ permet d'exécuter un bloc de code uniquement si une condition est vraie.

```C
int a = 10;

if (a > 5) {
  printf("a est supérieur à 5.\n");
}
```

## else

L'instruction _else_ permet de définir un bloc de code qui sera exécuté si la condition du if est fausse.

```C
int a = 3;

if (a > 5) {
  printf("a est supérieur à 5.\n");
} else {
  printf("a est inférieur ou égal à 5.\n");
}
```

## else if

L'instruction _else if_ permet de tester une nouvelle condition si la première _if_ est fausse.

```C
int a = 8;

if (a > 10) {
  printf("a est supérieur à 10.\n");
} else if (a > 5) {
  printf("a est supérieur à 5 mais inférieur ou égal à 10.\n");
} else {
  printf("a est inférieur ou égal à 5.\n");
}

```

Voir les [opérateurs de comparaison](../operateurs/comparaison) et les [opérateurs logiques](../operateurs/logique).

## switch 

L'instruction switch est une alternative aux multiples else if. Elle compare une variable avec différentes valeurs possibles et exécute le code correspondant.

```C
switch (variable) {
case valeur1:
  // Code si variable == valeur1
  break;
case valeur2:
  // Code si variable == valeur2
  break;
default:
  // Code si aucune correspondance
}
```
