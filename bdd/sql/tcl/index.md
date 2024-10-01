---
title: Transaction Control Language
---

Le TCL (Transaction Control Language) est utilisé pour gérer les transactions dans la base de données. Les transactions sont un ensemble d'instructions SQL qui sont exécutées comme une seule unité logique. Si une partie de la transaction échoue, tout l'ensemble peut être annulé pour garantir l'intégrité des données.

Les commandes principales de TCL sont :

- BEGIN TRANSACTION : Démarre une transaction.
- COMMIT : Valide la transaction, enregistrant toutes les modifications apportées.
- ROLLBACK : Annule la transaction, rétablissant la base de données à son état précédent, avant la transaction.

### SAVEPOINTS

La commande SAVEPOINT dans le langage SQL (et plus spécifiquement dans SQLite) est utilisée pour marquer un point intermédiaire au sein d'une transaction en cours. Cela permet de créer des points de contrôle où l'on peut revenir en cas d'erreur, sans avoir à annuler toute la transaction. C'est très utile pour gérer les transactions complexes où plusieurs étapes doivent être validées ou annulées séparément.

Les SAVEPOINTS permettent de diviser une transaction en plusieurs étapes plus petites et réversibles. Si une partie d'une transaction échoue, on peut annuler uniquement cette partie sans avoir à revenir en arrière sur l'ensemble de la transaction. Cela est particulièrement utile dans des scénarios complexes où des sous-opérations doivent être validées ou annulées de manière indépendante.

- SAVEPOINT savepoint_name : Crée un point de sauvegarde avec un nom spécifique.
- ROLLBACK TO savepoint_name : Annule toutes les modifications effectuées après le point de sauvegarde désigné, mais ne termine pas la transaction complète.
- RELEASE savepoint_name : Supprime le point de sauvegarde et valide toutes les modifications effectuées depuis ce point.

#### RELEASE

La commande RELEASE permet de libérer un point de sauvegarde une fois que vous êtes sûr que vous n'avez plus besoin de revenir à ce point. Quand vous libérez un SAVEPOINT, les modifications effectuées depuis ce point sont confirmées, mais la transaction reste ouverte jusqu'à ce qu'un COMMIT soit exécuté. Si vous n'utilisez pas RELEASE, un ROLLBACK complet de la transaction pourra toujours revenir à ce point de sauvegarde.

##### Différence entre ROLLBACK et ROLLBACK TO SAVEPOINT

ROLLBACK : Si vous utilisez cette commande sans spécifier de SAVEPOINT, elle annule toute la transaction depuis le début.

ROLLBACK TO SAVEPOINT : Permet d'annuler les changements seulement jusqu'au point de sauvegarde désigné, en maintenant les modifications précédentes intactes. Cela est particulièrement utile pour éviter de refaire complètement une transaction complexe.
