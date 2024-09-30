---
title: Data Control Language
---

Le langage de contrôle des données est le sous-langage responsable des tâches administratives de contrôle de la base de données elle-même, plus particulièrement de l'octroi et de la révocation des autorisations d'accès à la base de données pour les utilisateurs. 

Le DCL est utilisé principalement par les administrateurs de bases de données (DBA) pour s'assurer que seuls les utilisateurs autorisés peuvent accéder ou modifier les données, garantissant ainsi la sécurité des informations.

### Grant

Cette commande permet d'accorder des privilèges à des utilisateurs ou des rôles. Par exemple, elle peut autoriser un utilisateur à lire, modifier ou supprimer des données dans une table spécifique.

```sql
GRANT SELECT ON livres TO albert;
```

### Revoke

Cette commande permet de retirer des privilèges précédemment accordés à un utilisateur ou un rôle

```sql
REVOKE SELECT ON livres FROM albert;
```

### Deny

Cette coomande est utilisée dans certains systèmes, comme Microsoft SQL Server, pour refuser explicitement des privilèges à un utilisateur ou un rôle, même si celui-ci a reçu des permissions via la commande GRANT

```sql
DENY SELECT ON table_name TO user_name;
```

#### Pourquoi utiliser Deny ?

REVOKE supprime simplement un privilège accordé, mais si l'utilisateur appartient à un groupe qui a ce privilège, il pourrait toujours l'utiliser.

DENY, en revanche, a un effet prioritaire. Il bloque explicitement l'accès, et même si un utilisateur ou un rôle dispose du privilège via d'autres sources (comme des groupes), DENY prévaudra sur les autres permissions.
