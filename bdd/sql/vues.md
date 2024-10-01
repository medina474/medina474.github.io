---
title: Vues
---

Les vues (*view*) sont des représentations particulières et personnalisées des données contenues dans les tables. Les vues sont des requêtes (*query*) stockées dans la base de données. Elles sont vues comme des tables par les outils externes. Ce sont donc des **tables virtuelles** représentant le résultat d'une requête sur la base de données.

Les avantages des vues sont multiples :

- **Sécurité** et **fiabilité** : les requêtes ne sont pas écrites dans des scripts externes à la base de données. Elles ne peuvent pas être lues par les personnes ayant accès à ces scripts. Elles ne peuvent pas non plus être modifiées accidentellement par des personnes extérieures.
- **Sécurité** : les vues sont exécutées sous le contrôle des accès utilisateurs à la base de données, elles sont disponibles uniquement aux utilisateurs autorisés.
- **Robustesse** : les vues sont développées avec les autres objets de la base de données, les risques d'erreurs de syntaxes sont moindres, surtout avec un <abbr title="Integrated Development Environment">ide</abbr> performant.
- **Réusabilité** : les vues sont centralisées dans la base de données et peuvent remplacer des requêtes écrites dans plusieurs endroits d'une application. Cela facilite la maintenance.
- **Réusabilité** : les vues étant considérées comme des tables elles peuvent être utilisées elle-même dans d'autres vues. Une requête complexe peut être écrite avec plusieurs vues imbriquées. Une vue élémentaire peut être utilisées dans plusieurs autres vues.
- **Indépendance** : les requêtes sont modifiées dans la base de données sans modification des applications. L'indépendance st plus grande entre les données et la logique de l'application.
- **Portabilité** : Une seule vue peut être utilisée par tous les dispositifs se connectant à la base de données : application desktop, application mobile, site web, tableur, export pdf sans écrire les requêtes spécifiques à chaque application.
- **Rapidité et modularité du développement** : les requêtes sont développées par l'administrateur de la base de données avant l'écriture des applications par les autres membres de l'équipe de développement.
- **Facilité d'utilisation** : les requêtes complexes sont écrites par l'administrateur de la base de données, les utilisateurs finaux, notamment ceux qui utilisent des tableurs pour visualiser les données, n'ont pas besoin de connaitre le langage sql.
- **Performance** : Les vues sont exécutées et testées dans la base de données. On peut concevoir des tests unitaires et des tests de performance des requêtes directement dans la base de données.

Une vue est une requête SQL sauvegardée qui permet de créer une sorte de table virtuelle. Une vue affiche les résultats d'une requête sous la forme d'une table, mais contrairement à une table, elle ne stocke pas physiquement les données. Elle est générée dynamiquement à chaque fois qu'elle est utilisée, ce qui permet de simplifier des requêtes complexes ou de masquer certaines colonnes sensibles

```sql
CREATE VIEW view_name AS
SELECT column1, column2, ...
FROM table_name
WHERE condition;
```

Dans la plupart des bases de données, il est généralement déconseillé de trier une vue pour plusieurs raisons techniques et conceptuelles :

#### 1. Les vues ne garantissent pas d'ordre spécifique

Une vue en SQL est essentiellement une table virtuelle qui stocke une requête. Lorsque vous exécutez une requête sur une vue, le système de gestion de base de données (SGBD) traite cette vue comme une sous-requête, et les résultats des vues ne sont pas garantis d'être renvoyés dans un ordre particulier. Cela signifie que même si vous avez inclus une clause ORDER BY dans la définition de la vue, le SGBD peut ignorer cet ordre lorsqu'il réécrit ou optimise la requête au moment de son exécution.

#### 2. Optimisation par le SGBD

Le SGBD, y compris SQLite, optimise les requêtes de manière dynamique. Si vous définissez une vue avec un ordre particulier (via ORDER BY), cela peut limiter les optimisations que le SGBD peut appliquer à la requête qui interagit avec la vue. Par exemple, si une requête finale qui utilise la vue nécessite un tri différent, la clause ORDER BY dans la vue pourrait contrecarrer cette optimisation.

#### 3. Le tri est mieux géré dans la requête finale

L'ordre dans lequel vous souhaitez afficher les résultats dépend souvent du contexte d'utilisation de la vue. Ainsi, il est préférable de laisser la tâche de tri à la requête qui interroge la vue, plutôt que de forcer un ordre dans la définition de la vue elle-même. En ne spécifiant pas de tri dans la vue, vous gardez la flexibilité de choisir l'ordre qui convient lors de l'exécution de la requête finale.
