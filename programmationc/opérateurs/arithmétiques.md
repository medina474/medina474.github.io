---
title: Opérateurs arithmétiques
---

Les opérateurs arithmétiques en C sont utilisés pour effectuer des opérations mathématiques de base telles que l'addition, la soustraction, la multiplication.

### Addition (+)

```C
int a = 5, b = 3;
int result = a + b;  // result vaut 8
```

### Soustraction (-)

```C
int a = 5, b = 3;
int result = a - b;  // result vaut 2
```

### Multiplication (*)

```C
int a = 5, b = 3;
int result = a * b;  // result vaut 15
```

### Division (/)

```C
int a = 10, b = 2;
int result = a / b;  // result vaut 5
```

#### Remarque

Lorsque les deux opérandes sont des entiers, la division entière est effectuée, ce qui signifie que toute fraction est ignorée (tronquée).

```C
int a = 10, b = 3;
int result = a / b;  // result vaut 3 (10 / 3 = 3.333, mais la partie décimale est ignorée)
```

Si l'une des valeurs est de type flottant (comme float ou double), la division produira un résultat décimal.

### Modulo (%)

L'opérateur de modulo renvoie le reste de la division entière entre deux valeurs. Cet opérateur ne peut être utilisé qu'avec des entiers.

```C
int a = 10, b = 3;
int result = a % b;  // result vaut 1 (car 10 % 3 = 1)
```

Opérateurs d'incrémentation et de décrémentation

Ces opérateurs sont des variantes des opérateurs arithmétiques, utilisés pour ajouter ou soustraire 1 à une variable.

### Incrémentation

L'opérateur d'incrémentation ajoute 1 à la valeur de la variable.

Post-incrémentation (var++) : L'opérateur incrémente la variable après que sa valeur actuelle soit utilisée dans l'expression.

```C
int a = 5;
int result = a++;  // result vaut 5, puis a devient 6
```

Pré-incrémentation (++var) : L'opérateur incrémente la variable avant que sa valeur soit utilisée dans l'expression.

```C
int a = 5;
int result = ++a;  // a devient 6, puis result vaut 6
```

### Décrémentation (--)

L'opérateur de décrémentation soustrait 1 à la valeur de la variable.

Post-décrémentation (var--) : La décrémentation est effectuée après que la valeur de la variable soit utilisée dans l'expression.

```C
int a = 5;
int result = a--;  // result vaut 5, puis a devient 4
```

Pré-décrémentation (--var) : La décrémentation est effectuée avant que la valeur soit utilisée dans l'expression.

```C
int a = 5;
int result = --a;  // a devient 4, puis result vaut 4
```
