---
title: table temporelle
---

> Une table temporelle (ou table temporelle système) est un type spécial de table de base de données qui permet de suivre l'historique des modifications des données au fil du temps. Ce type de table est utilisé pour conserver non seulement l'état actuel des données, mais aussi les versions passées, permettant ainsi de revenir à un moment spécifique ou d'analyser l'évolution des données.
{ .definition }

```sql
 CREATE TABLE Article
 (
  id int not null auto_increment,
  nom varchar(50) not null,
  prix decimal(5,2) not null,
  primary key(id)
 ) WITH SYSTEM VERSIONING;
 ```
