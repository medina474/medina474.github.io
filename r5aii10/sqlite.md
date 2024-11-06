---
title: SQLite
---

> Créer un programme C qui lit et écrit une base de données SQLite.
{: .objectif}

- Demander à l'utilisateur d'entrer les données d'un véhicule (marque, immatriculation, poids maxi)
- Afficher la liste des véhicules

Pour Windows il faut télécharger les sources de SQLite sur le [https://www.sqlite.org/download.html](site officiel). Prendre la version amalgamtion.

### Ouvrir la base de données SQLite

Créer un nouveau fichier *base.db* si il n'existe pas.

Déclarer un pointeur de type ***sqlite3***, ensuite utiliser la fonction ***sqlite3_open***.


### Créer les tables 

Écrire une fonction qui teste l'existence de la table que vous voulez créer.

Tous les éléments d'une base de données (tables, colonnes, index) sont stockés dans les *tables systèmes* (sqlite_master).

Déclarer une pointeur de type ***sqlite3_stmt*** et utiliser les fonctions ***sqlite3_prepare_v2*** qui prépare une requête.
Lire le résultat de la requête avec ***sqlite3_step***

Créer la table en préparant une requête puis en l'executant avec la fonction ***sqlite3_finalize***

Si la création échoue sortir du programme.


### Lire des données

Afficher les données de la table en utilisant les fonctions ***sqlite3_prepare_v2*** et ***sqlite3_step***.


### Écrire des données

Demander à l'utilisateur les données à insérer. Puis utiliser les fonctions ***sqlite3_prepare_v2*** et ***sqlite3_finalize***.
