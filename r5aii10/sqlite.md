---
title: SQLite
---

> Créer un programme C qui lit et écrit une base de données SQLite.
{: .objectif}

- Demander à l'utilisateur d'entrer les données d'un véhicule (marque, immatriculation, poids maxi)
- Afficher la liste des véhicules

Pour Windows il faut télécharger les sources de SQLite sur le [site officiel](https://www.sqlite.org/download.html). Prendre la version amalgamtion.

### Ouvrir la base de données SQLite

Déclarer un pointeur de type ***sqlite3***, utiliser ensuite la fonction ***sqlite3_open***.

```c
sqlite3* db;
sqlite3_open("vehicules.db", &db);
```


### Créer les tables 

Créer la table en préparant une requête de type *CREATE TABLE* puis en l'executant avec la fonction ***sqlite3_step***

```c
const char* sql = "CREATE TABLE vehicules (marque text, immatriculation text, poids int)";
sqlite3_prepare_v2(db, sql, strlen(sql), &requete, NULL);
sqlite3_step(requete);
sqlite3_finalize(requete);
```

- sqlite3_prepare_v2 : traduit le langage SQL de la requête en blocs de code exécutables.
- sqlite3_step : exécute la requête.
- sqlite3_finalize : supprime une instruction préparée.


### Écrire des données

Demander à l'utilisateur les données à insérer. Puis utiliser les fonctions ***sqlite3_prepare_v2*** et ***sqlite3_step***.

Construire la chaine de caractère contenant la requête. Utiliser la fonction ***sprintf***. 
La fonction sprintf est équivalente à la fonction bien connue ***printf*** mais à la place d'afficher la chaine à l'écran elle est copié dans une variable. 
La variante ***snprintf*** permet de limiter la taille des variables insérées, en effet nous ne savons pas à l'avance ce que l'utilisateur va écrire. 
Il est possible que le texte final fasse plus que la longueur prévue (dans notre cas ici 200 caractères).

```c
char sql2[200];
snprintf(sql2, 200, "INSERT INTO vehicules (marque, immatriculation, poids) VALUES ('%s', '%s', %d)", marque, immatriculation, poids);
sqlite3_prepare_v2(db, sql2, 200, &requete, NULL);

printf("Vous allez exécuter la requête : %s", sql2);
```

Attention ne pas oublier les guillemets simples autour des valeurs de type texte.


Déclarer une pointeur de type ***sqlite3_stmt*** et utiliser les fonctions ***sqlite3_prepare_v2*** qui prépare une requête.
Lire le résultat de la requête avec ***sqlite3_step***

Écrire une fonction qui teste l'existence de la table que vous voulez créer.

Tous les éléments d'une base de données (tables, colonnes, index) sont stockés dans les *tables systèmes* (sqlite_master).


Si la création échoue sortir du programme.


### Lire des données

Afficher les données de la table en utilisant les fonctions ***sqlite3_prepare_v2*** et ***sqlite3_step***.
