
[schéma](schema)

types de données

index

contraintes

vues

trigger


## Tablespaces


## Schémas

Un schéma est un ensemble logique d'objets (des tables en autre), ce qui permet de diviser une seule base de données en plusieurs groupes fonctionnels.

On peut ainsi étendre une base de données avec des applications tierces sans interférer avec les objets existants.

Il existe par défaut un schéma qui est le schéma **public**.

<span syntax="sql">CREATE SCHEMA nom;</span>

2 tables avec le même noms peuvent exister si elles se trouvent dans 2 schémas différents.La syntaxe pour accéder aux tables dans un schéma est : *schema.table*. si le schéma n'est pas spécifié cela signifie que l'on se trouve dans le schéma *public*.

## Tables

## Colonnes

## Requêtes

## Vues


## Vues matérialisées

Une vue matérialisée est une vue dont le résultat est stockées physiquement dans la base de données. On l'utilise dans le cas où la requête associées à la vue est particulièrement complexe et lourde, ceci à des fins d'optimisation et de performance. La vue matérialisée est un système de cache physique pour les requêtes, la fréquence de mise à jour de la vue matérialisée par rapport aux données des tables qu'elle utilise est variable et paramétrable  cela peut être nul (rafraîchissement synchrone) ou d'une durée planifiée. La mise à jour est optimisée car le système de base de données s'arrange pour que cela ne concerne que les données modifiées depuis la dernière mise à jour.

Les vues matérialisées sont appelées vues indexées par Microsoft SQL Server.

## Vues paramétrées

Les vues paramétrées n'existent pas avec PostgreSQL.

## Procédures stockées

Les procédures stockées ne sont pas des vues paramétrées.

Les procédures stockées sont appelées **fonctions** par PostGreSQL.

## Contraintes

## Déclencheurs

Les déclencheurs sont des événements qui exécutent des fonctions à des moments particuliers.

### Déclencheurs sur des vues (instead of)

Il est possible de définir des déclencheurs sur des vues. Comme un vue peut contenir plusieurs tables la fonction déclenchées prend en charge les opérations sur les tables membres.

## Index

## Utilisateurs

## Opérateurs

## Agrégats

## Domaines

Un domaine est un type de données avec des contraintes optionnelles sur les valeurs utilisées.

Les domaines permettent de centraliser des contraintes communes à plusieurs tables et de les regrouper en un seul emplacement, ce qui en facilite la maintenance. Par exemple, plusieurs tables pourraient contenir des colonnes *code postal*, toutes nécessitant la même contrainte de vérification (*CHECK*) permettant de vérifier que le contenu de la colonne est bien un code postal valide.

```sql
create domain mois as integer
  constraint mois_check
  check (value > 0 and value <= 12);
```

## Tables systèmes

L'intégralité de ces objets sont enregistrés dans des tables dites tables systèmes.  Par exemples dans MySQL les définitions des colonnes de toutes les tables sont stockés dans une table appelée `COLUMNS` de la base de données `INFORMATION_SCHEMA`
