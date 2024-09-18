---
title: Déclencheurs
---

Un déclencheur (ou trigger en anglais) est un type de mécanisme dans une base de données relationnelle qui permet d'exécuter automatiquement une série d'actions ou de requêtes SQL lorsqu'un événement particulier se produit sur une table donnée. Les déclencheurs sont souvent utilisés pour appliquer des règles métier, maintenir l'intégrité des données ou générer des audits automatiquement.

Un déclencheur est associé à une table (ou une vue) et se déclenche en réponse à des événements spécifiques comme :

- INSERT : Lorsqu'une nouvelle ligne est insérée dans la table.
- UPDATE : Lorsqu'une ou plusieurs lignes de la table sont modifiées.
- DELETE : Lorsqu'une ou plusieurs lignes de la table sont supprimées.

```sql
CREATE TRIGGER nom_declencheur
{ BEFORE | AFTER } { INSERT | UPDATE | DELETE }
ON nom_table
FOR EACH ROW
BEGIN
  -- Actions à exécuter lorsque le déclencheur est activé
END;
```
