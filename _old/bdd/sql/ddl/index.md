---
title: Data Definition Language
---

Langage de définition des données (DDL) - Le langage de définition des données est le sous-langage chargé de définir la manière dont les données sont structurées dans une base de données. En SQL, cela correspond à la manipulation des tables par l'intermédiaire de *create table*, *alter table*, et *drop table*.

## Créer une table

La commande CREATE TABLE permet de créer une table en SQL. Un tableau est une entité qui est contenu dans une base de données pour stocker des données ordonnées dans des colonnes. La création d’une table sert à définir les colonnes et le type de données qui seront contenus dans chacun des colonne (entier, chaîne de caractères, date, valeur binaire …).

```sql
CREATE TABLE chauffeur;
```

## Supprimer une table

La commande DROP TABLE en SQL permet de supprimer définitivement une table d’une base de données. Cela supprime en même temps les éventuels index, trigger, contraintes et permissions associées à cette table.

Attention : il faut utiliser cette commande avec attention car une fois supprimée, les données sont perdues. Avant de l’utiliser sur une base importante il peut être judicieux d’effectuer un backup (une sauvegarde) pour éviter les mauvaises surprises.

```sql
DROP TABLE chauffeur;
```

## Modifier une table

La commande ALTER TABLE en SQL permet de modifier une table existante. Idéal pour ajouter une colonne, supprimer une colonne ou modifier une colonne existante, par exemple pour changer le type.

```sql
ALTER TABLE chauffeur;
```
