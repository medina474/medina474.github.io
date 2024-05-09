---
title: Les opérateurs logiques
---

Ces opérateurs permetent de vérifier si plusieurs conditions sont vraies. Les valeurs renvoyés sont 0 pour faux et 1 pour vrai. 

A noter : Par économie de moyens, le langage C travaille avec des entiers en utilisant la convention suivante : la valeur 0 représente la valeur booléenne faux ou false, et toute autre valeur sera assimilée à la valeur vrai ou true.

### NON logique

L'opérateur `!` inverse l'état d'une variable booléenne. Retourne la valeur 1 si la variable vaut 0 et 0 si elle vaut 1 (ou tout nombre différent de 0).

```C
a = !b;
```

a  | !a
--:|--:
0  | 1
1  | 0

### OU logique 	

> L'opérateur **OU logique** vérifie qu'au moins **une** des conditions est réalisée. 
{:.definition}

L'opérateur `||` retourne 1 si une des deux conditions a la valeur 1 (ou tout nombre différent de 0).

L'opérateur `||` retourne 0 seulement si les deux conditions ont la valeur 0.

```C
condition1 || condition2;
```

a  | b  | a && b
--:|--:|--:
0  | 0 |  0
1  | 0 |  1
0  | 1 |  1
1  | 1 |  1


### ET logique 	

> L'opérateur **ET logique** vérifie que **toutes** les conditions sont vraies. 
{:.definition}

L'opérateur `&&` retourne 1 seulement si les deux conditions ont la valeur 1 (ou tout nombre différent de 0).

L'opérateur `&&` retourne 0 si **une seule** des deux conditions possède la valeur 0 et quelque soit la valeur de l'autre condition.

```C
resultat = condition1 && condition2;
```

a  | b  | a && b
--:|--:|--:
0  | 0 |  0
1  | 0 |  0
0  | 1 |  0
1  | 1 |  1


### Short-circuit evaluation

Short-circuit evaluation (court-circuit d'évaluation) ou lazy evaluation (évaluation paresseuse) ou appel par nécessité ou évaluation retardée est un mécanisme d'optimisation de l'éxecution du programme. Les expressions ne sont évaluées que si c'est nécessaire au résultat final. 

Si le résultat est irrémédiablement connu à une étape alors la suite n'est pas évaluée car cela ne pourra faire changer le résultat.

Soit les 3 fonctions suivantes

```C
int FonctionV()
{
  puts("Execution de V");
  return 1;
}

int FonctionF()
{
  puts("Execution de F");
  return 0;
}

int FonctionA()
{
  puts("Execution de A");
  return 0;
}
```

```C
FonctionV() && FonctionA();
```

`FonctionA` est appelée car la seule évaluation de `FonctionV` qui retourne vrai ne permet pas de conclure au résultat.

```C
FonctionF() && FonctionA();
```

Il n'est pas nécessaire d'appeler `FonctionA` car de toute façon avec `FonctionF` qui retourne faux le résultat final sera faux quelque soit le résultat de `FonctionA`. 

Le court-circuit d'évaluation peut remplacer une syntaxe utilisant `if` 

```C
if (FonctionB())
{
  FonctionA();
} 
```

```C
FonctionB() && FonctionA();
```
