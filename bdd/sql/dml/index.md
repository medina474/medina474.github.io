---
title: "DML"
date: 2023-08-26T13:15:51+02:00
published: true
---

Langage de manipulation des données (DML) - Le langage de manipulation des données est le sous-langage qui permet d'ajouter, de modifier ou de supprimer des données dans une base de données. En SQL, il correspond aux langages INSERT, UPDATE et DML. DELETE

## Insérer des données

Lorsqu'une table est créée, elle ne contient aucune donnée. La première chose à faire avant qu’une base de données puisse être d’une grande utilité est d’insérer des données. Il n'est pas possible d'insérer quelque chose qui ne soit pas une ligne complète. Même si vous ne connaissez que quelques valeurs de colonnes, une ligne complète doit être créée.

L’insertion de données dans une table s’effectue à l’aide de la commande **insert into**. Cette commande permet au choix d’inclure une seule ligne dans la table existante ou plusieurs lignes en une seule commande.

Insertion d’une ligne à la fois
Pour insérer des données dans une base, il y a 2 syntaxes principales :

- Insérer une ligne en indiquant les informations pour chaque colonne existante (en respectant l’ordre)
- Insérer une ligne en spécifiant les colonnes que vous souhaiter compléter. Il est possible d’insérer une ligne renseignant seulement une partie des colonnes

Vous pouvez insérer plusieurs lignes dans une seule commande :

```sql
insert into produits (produit_no, nom, prix) values
    (1, 'Cheese', 9.99),
    (2, 'Bread', 1.99),
    (3, 'Milk', 2.99);
```

## Supprimer des données

La commande **delete** en SQL permet de supprimer des lignes dans une table. En utilisant cette commande associé à **where** il est possible de sélectionner les lignes concernées qui seront supprimées.

Attention
Avant d’essayer de supprimer des lignes, il est recommandé d’effectuer une sauvegarde de la base de données, ou tout du moins de la table concernée par la suppression. Ainsi, s’il y a une mauvaise manipulation il est toujours possible de restaurer les données.

## Modifier des données


## Upsert

## Renvoyer des données à partir de lignes modifiées

Il est parfois utile d'obtenir des données à partir de lignes modifiées pendant leur manipulation. Les commandes INSERT, UPDATE et DELETE ont toutes une clause RETURNING facultative qui prend en charge cela. L'utilisation de RETURNING évite d'effectuer une requête supplémentaire dans la base de données pour collecter les données et s'avère particulièrement utile lorsqu'il serait autrement difficile d'identifier de manière fiable les lignes modifiées.

Le contenu autorisé d'une clause RETURNING est le même que celui de la liste de sortie d'une commande SELECT (voir Section 7.3). Il peut contenir des noms de colonnes de la table cible de la commande ou des expressions de valeurs utilisant ces colonnes. Un raccourci courant est RETURNING *, qui sélectionne toutes les colonnes de la table cible dans l'ordre.

Dans un INSERT, les données disponibles pour RETURNING sont la ligne telle qu'elle a été insérée. Ce n'est pas très utile dans les insertions triviales, car cela répéterait simplement les données fournies par le client. Mais cela peut être très pratique lorsque l’on s’appuie sur des valeurs par défaut calculées. Par exemple, lorsque vous utilisez une colonne série pour fournir des identifiants uniques, RETURNING peut renvoyer l'ID attribué à une nouvelle ligne :
