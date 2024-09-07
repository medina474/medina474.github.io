---
title: Fonctions d'agrégation
---

En SQL, une agrégation est une opération qui permet de combiner plusieurs valeurs de données en une seule valeur résumée. Les opérations d'agrégation sont souvent utilisées en combinaison avec la clause GROUP BY pour regrouper les données selon des critères spécifiques avant de les résumer.

### Compter

Compte le nombre d'enregistrements dans un ensemble de données.

```sql
SELECT COUNT(*) FROM utilisateurs;
```

On peut compter sur n'importe quelle colonne, dans ce cas pour ne pas avoir à choisir on utilise le caractère joker *.

### Somme

Calcule la somme des valeurs d'une colonne numérique.

```sql
SELECT SUM(salaire) FROM employes;
```

### Moyenne 

Calcule la moyenne des valeurs d'une colonne numérique.

```sql
SELECT AVG(salaire) FROM employes;
```

### Maximum

Retourne la valeur maximale dans une colonne.

```sql
SELECT MAX(age) FROM utilisateurs;
```

### Minimum

Retourne la valeur minimale dans une colonne.

```sql
SELECT MIN(age) FROM utilisateurs;
```

### Filtre après aggrégation

HAVING est emblable à WHERE, mais utilisé pour filtrer les résultats après un GROUP BY, sur les résultats des fonctions d'agrégation.
