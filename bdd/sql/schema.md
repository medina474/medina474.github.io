---
title: "Schémas"
date: 2023-08-26T13:15:51+02:00
published: true
---

A PostgreSQL database cluster contains one or more named databases. Roles and a few other object types are shared across the entire cluster. A client connection to the server can only access data in a single database, the one specified in the connection request.

Il existe plusieurs raisons pour lesquelles on peut vouloir utiliser des schémas :

- Permettre à de nombreux utilisateurs d’utiliser une base de données sans interférer les uns avec les autres.
- Organiser les objets de la base de données en groupes logiques pour les rendre plus faciles à gérer.
- Les applications tierces peuvent être placées dans des schémas distincts afin qu'elles n'entrent pas en conflit avec les noms d'autres objets.

Les schémas sont analogues aux répertoires au niveau du système d'exploitation, sauf que les schémas ne peuvent pas être imbriqués.
