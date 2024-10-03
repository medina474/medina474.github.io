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

### Mettre à jour la date de modification lorsqu'un client (customer) est modifié

```sql
CREATE TRIGGER MAJCustomer
AFTER UPDATE ON customers
FOR EACH ROW
BEGIN
	UPDATE customers SET DateModification = datetime();
END;
```

### Ajouter un enregistrement dans la table Message lorsque le nom du client change

```sql
CREATE TRIGGER NomCustomer
AFTER UPDATE ON customers 
FOR EACH ROW WHEN OLD.LastName <> NEW.LastName
BEGIN
	INSERT INTO Messages (Texte) 
     VALUES ('Changement de nom ' ||  OLD.LastName || ' devient ' || NEW.LastName);
END;
```

### Interdir la suppression d'une ligne de facture

```sql
CREATE TRIGGER SuppressionItems
BEFORE DELETE ON invoice_items
FOR EACH ROW
BEGIN
	SELECT RAISE(ABORT, 'Interdit');
END;
```
