---
title: Schémas
---

Un cluster de bases de données PostgreSQL contient une ou plusieurs bases de données nommées. Les rôles et quelques autres types d'objets sont partagés dans l'ensemble du cluster. Une connexion client au serveur ne peut accéder qu'aux données d'une seule base de données, celle spécifiée dans la demande de connexion.

Il existe plusieurs raisons pour lesquelles on peut vouloir utiliser des schémas :

- Permettre à de nombreux utilisateurs d’utiliser une base de données sans interférer les uns avec les autres.
- Organiser les objets de la base de données en groupes logiques pour les rendre plus faciles à gérer.
- Les applications tierces peuvent être placées dans des schémas distincts afin qu'elles n'entrent pas en conflit avec les noms d'autres objets.

Les schémas sont analogues aux répertoires au niveau du système d'exploitation, sauf que les schémas ne peuvent pas être imbriqués.
