---
title: DML
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

La commande UPDATE en SQL permet de modifier des données existantes dans une table. Elle est utilisée pour mettre à jour une ou plusieurs lignes d'une table en modifiant les valeurs de colonnes spécifiques, selon des conditions données.

```sql
UPDATE nom_table
SET colonne1 = nouvelle_valeur1, colonne2 = nouvelle_valeur2, ...
WHERE condition;
```

Il est toujours recommandé d’utiliser une condition WHERE appropriée pour éviter des modifications involontaires.
