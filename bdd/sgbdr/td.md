---
title: Travaux dirigés
---

## Schéma entités-relations

Le schéma entité-relation est l'étape préparatoire à la réalisation d'une base de données. il modélise sous forme graphique un problème réel.


### Exercice 1. Société de transport

Une société de transport possède une flotte de camion et plusieurs entrepots. 

Cette société embauche des chauffeurs. Les camions sont basés à des entrepôts. Les camions sont affectés aux chauffeurs au jour le jour.

La nature du permis limite les camions que le chauffeur peut conduire.

### Exercice 2. système de maintenance

Une société possède un parc de machine. Ces machines sont placés dans des ateliers et les ateliers appartiennent à des sites (lieux) de fabrication. Une machine est caractérisée par sa marque et sa date d'achat. Les opérations de maintenance sont des cycles d'opérations à effectuer régulièrement sur une machine. Des opérateurs conduisent ces opérations et notent les résultats.

### Exercice 3. ERP (Enterprise resource planning)

Uns société achète des articles pour fabriquer des produits finis. 

Un entrepôt permet de stocker à la fois les articles et les produits finis.

Les produits finis sont créés à partir des articles suivant une gamme de fabrication.

*****
Articles       Produits Finis        Gamme de fabrication     Production       Stockage
Nom            Nom                   Nom Article              Produit Fini     Article
Prix d'achat   Prix vente            Nom Produit Fini         Quantite         Produit f
                                     Quantité                 Date

******       
Produit          Gamme de fabrication      Production         Stockage
Nom              Produit                   Produit            Produit
Prix             Produit                   Quantité           Quantité     
fini (o/n)       Quantité                  Date

Activer les contraintes dans SQLite
PRAGMA foreign_keys = ON;

vous ne pouvez pas ajouter directement une contrainte de clé primaire à une table existante dans SQLite après sa création. Contrairement à certaines autres bases de données relationnelles, SQLite ne permet pas de modifier une table pour ajouter ou supprimer des contraintes de clé primaire après que la table a été créée.

- 1. Créez la nouvelle table avec la contrainte de clé primaire
CREATE TABLE new_table (
    id INTEGER PRIMARY KEY,
    column1 TEXT,
    column2 INTEGER
);

-- 2. Copiez les données de l'ancienne table vers la nouvelle
INSERT INTO new_table (id, column1, column2)
SELECT id, column1, column2 FROM old_table;

-- 3. Supprimez l'ancienne table
DROP TABLE old_table;

-- 4. Renommez la nouvelle table avec le nom de l'ancienne table
ALTER TABLE new_table RENAME TO old_table;
