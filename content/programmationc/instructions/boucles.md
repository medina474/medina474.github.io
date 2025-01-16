---
title: Instructions conditionnelles
---

Les instructions de boucles en C permettent de répéter l'exécution d'un bloc de code tant qu'une condition donnée est vraie. Elles sont particulièrement utiles lorsque vous avez besoin d'exécuter plusieurs fois le même code ou un ensemble d'instructions. 

## while

L'instruction while exécute un bloc de code tant qu'une condition est vraie. La condition est vérifiée avant chaque itération, donc si elle est fausse au départ, le bloc de code n'est jamais exécuté.

```c
int i = 0;
while (i < 5) {
  printf("%d\n", i);
  i++;
}
```

## do-while

L'instruction do-while est similaire à while, mais la différence principale est que la condition est vérifiée **après** l'exécution du bloc de code. Cela garantit que le bloc de code est exécuté **au moins une fois**, même si la condition est fausse dès le début.

```c
int i = 0;
do {
  printf("%d\n", i);
  i++;
} while (i < 5);
```

## for

L'instruction for est souvent utilisée lorsque le nombre d'itérations est connu à l'avance. Elle permet d'initialiser une variable, de définir une condition, et d'incrémenter ou de décrémenter la variable dans une seule ligne de code.

```c
for (initialisation; condition; opération) {
    // Code à exécuter tant que la condition est vraie
}
```

## Boucle infinie

Une boucle infinie est une boucle qui ne se termine jamais parce que sa condition est toujours vraie. Les boucles infinies peuvent être utiles dans certains contextes, comme les serveurs ou les systèmes embarqués qui doivent toujours fonctionner jusqu'à ce qu'une interruption externe survienne.

```c
while (1) {
    // Cette boucle ne se terminera jamais
}
```

ou

```c
for (;;) {
    // Cette boucle ne se terminera jamais
}
```

## Sortir des boucles

Il est possible de contrôler le comportement des boucles avec les [instructions de débranchement](debranchement) :

- break : Pour sortir immédiatement de la boucle.
- continue : Pour sauter à l'itération suivante sans exécuter le reste du bloc de code.

## Boucles imbriquées

Il est possible d'imbriquer des boucles, c'est-à-dire de placer une boucle à l'intérieur d'une autre. Cela est souvent utilisé pour parcourir des structures de données en plusieurs dimensions comme des tableaux.

```c
for (int i = 0; i < 3; i++) {
  for (int j = 0; j < 3; j++) {
    printf("i = %d, j = %d\n", i, j);
  }
}
```
