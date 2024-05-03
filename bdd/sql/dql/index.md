---
title: "Langage de requête de données"
date: 2023-08-26T13:15:51+02:00
published: true
---

DQL pour Data Query Language est le sous-langage responsable de la lecture, ou de l'interrogation, des données d'une base de données.

En SQL, cela correspond à la commande **select**

## Source

Dans une commande **select** il convient de définir les colonnes que l'on veut obtenir ainsi que la source des données définie par le mot clé `from`

```sql
select FirstName, LastName, City from customers;
```

## Filtre

La clause `where` permet de spécifier une condition qui doit être satisfaite pour qu'une ligne soit incluse dans le résultat de la requête.

```sql
select FirstName, LastName, City
from customers
where Country = 'France';
```

FirstName|LastName|City
---|---|---
Camille|Bernard|Paris
Dominique|Lefebvre|Paris
Marc|Dubois|Lyon
Wyatt|Girard|Bordeaux
Isabelle|Mercier|Dijon

### Opérateurs

Opérateur|Description
---|---
=|égal
<>|différent
&gt;|supérieur
&gt;=|supérieur ou égal
&lt;|inférieur
&lt;=|inférieur ou égal

#### between

Détermine si une valeur se trouve entre deux limites inclusives. `between` peut être précédé du mot clé `not` pour inverser la condition.

```sql
where total between 10.0 and 20.0
```


between [lowerbound] and [upperbound]

#### in

détermine si une valeur est présente dans un ensemble de valeurs.

```sql
"costs"."unit_cost" in (200, 600, 'a')
```

#### like

détermine si une valeur correspond à tout ou partie d'une chaîne. souvent utilisé avec caractères génériques pour indiquer toute correspondance de chaîne de caractères avec zéro ou plusieurs caractères (%) ou une correspondance à caractère unique (_).

```sql
"products"."prod_name" like 'prod%'
```
### Conditions multiples

## Tri

## Pagination

Si un nombre limite est donné, pas plus de ce nombre de lignes sera renvoyé (mais peut-être moins, si la requête elle-même génère moins de lignes). LIMIT ALL revient à omettre la clause LIMIT, tout comme LIMIT avec un argument NULL.

OFFSET dit de sauter autant de lignes avant de commencer à renvoyer des lignes. OFFSET 0 revient à omettre la clause OFFSET, tout comme OFFSET avec un argument NULL.

Si OFFSET et LIMIT apparaissent, les lignes OFFSET sont ignorées avant de commencer à compter les lignes LIMIT renvoyées.

Lors de l'utilisation de LIMIT, il est important d'utiliser une clause ORDER BY qui contraint les lignes de résultats dans un ordre unique. Sinon, vous obtiendrez un sous-ensemble imprévisible des lignes de la requête. Vous demandez peut-être les lignes du dixième au vingtième, mais du dixième au vingtième dans quel ordre ? L'ordre est inconnu, sauf si vous avez spécifié ORDER BY.

L'optimiseur de requêtes prend en compte LIMIT lors de la génération des plans de requête, vous obtiendrez donc très probablement différents plans (générant différents ordres de lignes) en fonction de ce que vous donnez pour LIMIT et OFFSET. Ainsi, l'utilisation de différentes valeurs LIMIT/OFFSET pour sélectionner différents sous-ensembles d'un résultat de requête donnera des résultats incohérents à moins que vous n'appliquiez un classement prévisible des résultats avec ORDER BY. Ce n'est pas un bug; c'est une conséquence inhérente du fait que SQL ne promet pas de fournir les résultats d'une requête dans un ordre particulier à moins que ORDER BY ne soit utilisé pour contraindre l'ordre.

Les lignes ignorées par une clause OFFSET doivent toujours être calculées à l'intérieur du serveur ; par conséquent, un OFFSET important pourrait être inefficace.
