---
title: Variables
---

>Une variable est un élément qui associe un **identifiant** à une **valeur**.
{:.definition}

### Caractéristiques

Une variable possède plusieurs caractéristiques ou propriétés.

La **déclaration**, c'est l'endroit dans le code qui défini l'existence de la variable.

```c
int age = 19;
```

Un **nom** sous lequel la variable est déclarée. Dans cette déclaration le nom de la variable est `age`.

Un **type**. Dans la mémoire d'un ordinateur, toute information est stockée sous forme d'éléments binaires appelés `bit` (en: binary digit, nombre binaire). Un même ensemble de bits peut être représenté sous différentes aspects : nombre entier, nombre réel, texte, photo, vidéo, audio, ... C'est la convention d'interprétation du type qui défini la valeur de la variable.

Dans cette déclaration le type de la variable `age` est un entier `int`.

La **taille** associée au type. Dans le cas des types fixe, le type de la variable spécifie aussi le nombre de bits ou le nombre de mots (en: bytes, octets) utilisés.

Dans cette déclaration la taille de la variable `age` est de 4 octets ou 32 bits, qui est la taille associée à un type `int`.

La **valeur**, c'est la valeur intrasèque des bits suivant la représentation associée au type;

Dans cet exemple la valeur de la variable `age` est `10`.

L'**adresse**, c'est l'endroit dans la mémoire de l'ordinateur où est stockée physiquement la variable.

La **portée**, c'est la portion de code où la variable est utilisable. Une variable est accessible depuis sa définition jusqu'à la fin du bloc où elle est déclarée.

Sa **durée de vie**, c'est le temps d'exécution pendant laquelle la variable existe. Il est possible de masquer une variable par une autre en utilisant un même identifiant. La première variable est hors de portée mais existe toujours. Une variable `static` est utilisable que dans la fonction dans laquelle elle a été déclarée, cependant sa durée de vie s'étend sur l'intégralité de l'éxécution du programme.

Sa **visibilité**, dans un langage évolué comme le C++, le C# ou Java, c'est un ensemble de règles qui fixe qui peut utiliser la variable.

### Règles

#### Déclaration

>Les variables doivent être déclarées **avant** d'être utilisées.
{:.warning}

```c
#include <stdio.h>

void main()
{
  printf("%d", age);
  int age = 10;
}
```

Ce code provoque une erreur : la variable est non déclarée avant sont utilisation !

```
error: ‘age’ undeclared (first use in this function)
```

Voici le code correct

```c
#include <stdio.h>

void main()
{
  int age = 10;
  printf("%d", age);
}
```

## Expressions littérales

Dans un programme il est possible de manipuler des valeurs sans pour autant les avoir déclarées avant. Ces valeurs existent de manières littérales à l'intérieur même du code du programme.

>Attention, dans le cas des chaines de caractères, il ne faut pas confondre le nom de la variable avec sa valeur.
{: .warning}

```c
char joueur[10] = "Alice";

printf("%s\n", "joueur");
printf("%s\n", joueur);
```

`"joueur"` avec des guillemets est une valeur littérale. On peut considérer, sans que cela soit le cas, que c'est une variable sans nom, qui possède la valeur `joueur`.
