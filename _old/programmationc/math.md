---
title: Fonctions mathématiques
---

### Arrondi

3 déclinaisons de la fonction ***round*** en fonction du type de données utilisé pour le paramètre et la valeur de retour : double, float ou long double.

```c
double      round(double)fichie;
float       roundf(float);
long double roundl(long double);
```

Ces trois fonctions renvoient l'arrondi entier au plus proche de la valeur spécifiée en paramètre.

### Ceil : Arrondi supérieur

3 déclinaisons de la fonction ***ceil*** en fonction du type de données utilisé pour le paramètre et la valeur de retour : double, float ou long double.

```c
double      ceil(double);
float       ceilf(float);
long double ceill(long double);
```

Ces trois fonctions retournent l'arrondi entier supérieur (en anglais ceil signifiant plafond) de la valeur spécifiée en paramètre.

>Attention aux valeurs négatives ! La valeur plafond de -5.82 est -5 car -5 est supérieur à -5.42.
{:.warning}

### Floor : Arrondi inférieur

3 déclinaisons de la fonction ***floor*** en fonction du type de données utilisé pour le paramètre et la valeur de retour : double, float ou long double.

```c
double      floor(double);
float       floorf(float);
long double floorl(long double);
```

Ces trois fonctions retournent l'arrondi entier inférieur (en anglais floor signifiant plancher) de la valeur spécifiée en paramètre.

>Attention aux valeurs négatives ! La valeur plancher de -5.21 est -6 car -6 est inférieure à -5.21.
{:.warning}
