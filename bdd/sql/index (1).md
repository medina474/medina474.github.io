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

Les vues (*view*) sont des représentations particulières et personnalisées des données contenues dans les tables. Les vues sont des requêtes (*query*) stockées dans la base de données. Elles sont vues comme des tables par les outils externes. Ce sont donc des **tables virtuelles** représentant le résultat d'une requête sur la base de données.

Les avantages des vues sont multiples :

- **Sécurité** et **fiabilité** : les requêtes ne sont pas écrites dans des scripts externes à la base de données. Elles ne peuvent pas être lues par les personnes ayant accès à ces scripts. Elles ne peuvent pas non plus être modifiées accidentellement par des personnes extérieures.
- **Sécurité** : les vues sont exécutées sous le contrôle des accès utilisateurs à la base de données, elles sont disponibles uniquement aux utilisateurs autorisés.
- **Robustesse** : les vues sont développées avec les autres objets de la base de données, les risques d'erreurs de syntaxes sont moindres, surtout avec un <abbr title="Integrated Development Environment">ide</abbr> performant.
- **Réusabilité** : les vues sont centralisées dans la base de données et peuvent remplacer des requêtes écrites dans plusieurs endroits d'une application. Cela facilite la maintenance.
- **Réusabilité** : les vues étant considérées comme des tables elles peuvent être utilisées elle-même dans d'autres vues. Une requête complexe peut être écrite avec plusieurs vues imbriquées. Une vue élémentaire peut être utilisées dans plusieurs autres vues.
- **Indépendance** :  les requêtes sont modifiées dans la base de données sans modification des applications. L'indépendance st plus grande entre les données et la logique de l'application.
- **Portabilité** : Une seule vue peut être utilisée par tous les dispositifs se connectant à la base de données : application desktop, application mobile, site web, tableur, export pdf sans écrire les requêtes spécifiques à chaque application.
- **Rapidité et modularité du développement** : les requêtes sont développées par l'administrateur de la base de données avant l'écriture des applications par les autres membres de l'équipe de développement.
- **Facilité d'utilisation** : les requêtes complexes sont écrites par l'administrateur de la base de données, les utilisateurs finaux, notamment ceux qui utilisent des tableurs pour visualiser les données,  n'ont pas besoin de connaitre le langage sql.
- **Performance** : Les vues sont exécutées et testées dans la base de données. On peut concevoir des tests unitaires et des tests de performance des requêtes directement  dans la base de données.


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
