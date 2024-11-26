---
title: SQLite
---

> **Objectif :** Créer un programme C qui lit et écrit des données dans une base de données SQLite.
{: .objectif}

- Demander à l'utilisateur d'entrer les données d'un véhicule (marque, immatriculation, poids).
- Insérer ces données dans une table de base de données.
- Récupérer les données et afficher la liste des véhicules à l'écran.

Télécharger les sources de SQLite sur le [site officiel](https://www.sqlite.org/download.html). Pour Windows prendre la version amalgamtion.

### Ouvrir la base de données SQLite

Déclarer un pointeur de type ***sqlite3***, utiliser ensuite la fonction ***sqlite3_open***.

```c
sqlite3* db;
sqlite3_open("vehicules.db", &db);
```

Si le fichier n'existe pas, il est créé.

### Créer les tables

Créer la table en préparant une requête SQL de type *CREATE TABLE* puis en l'executant avec la fonction ***sqlite3_step***.
Déclarer d'abord une pointeur de type ***sqlite3_stmt***

```c
const char* sql = "CREATE TABLE vehicules (marque text, immatriculation text, poids int)"; // Le texte de la requête SQL

sqlite3_stmt *requete;
sqlite3_prepare_v2(db, sql, strlen(sql), &requete, NULL); // Traduction du SQL en code
sqlite3_step(requete); // Execution
sqlite3_finalize(requete); // Suppression du code
```

- sqlite3_prepare_v2 : traduit le langage SQL de la requête en blocs de code exécutables.
- sqlite3_step : exécute la requête.
- sqlite3_finalize : supprime une instruction préparée.


### Écrire des données

Demander à l'utilisateur les données à insérer. Puis utiliser les fonctions ***sqlite3_prepare_v2*** et ***sqlite3_step*** pour les enregistrer dans la base de données.

Construire la chaine de caractère contenant la requête SQL. Utiliser la fonction ***sprintf***.
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

Utiliser de nouveau les fonctions ***sqlite3_prepare_v2*** et ***sqlite3_step*** pour préparer et exécuter la requête.

```c
sqlite3_prepare_v2(db, sql2, 200, &requete, NULL);
sqlite3_step(requete);
sqlite3_finalize(requete);
```

Attention : Cette méthode pour construire une requête en insérant les données de l'utilisateur dans la requête d'exécution fonctionne, cependant ce n'est pas considéré comme une bonne pratique. Il y a deux problèmes, une problème grave de sécurité d'une part et de performance d'autre part

#### Sécurité

```c
snprintf(sql2, 200, "INSERT INTO vehicules (marque, immatriculation, poids) VALUES ('%s', '%s', %d)", marque, immatriculation, poids);
```

La fonction remplace le %s par la chaine que rentre l'utilisateur pour créer la requête finale. Que se passe t il  si l'utilisateur (mal intentionné) ne renseigne pas une marque mais une portion de code SQL ?

```c
marque = "PIRATE', '', 0); DELETE FROM vehicules; --"
snprintf(sql2, 200, "INSERT INTO vehicules (marque, immatriculation, poids) VALUES ('%s', '%s', %d)", marque, immatriculation, poids);
```

L'utilisation d'un guillement simple permet de fermer le premier guillement autour de %s; La parenthèse et le point virgule permettent de terminer la requête et d'en commencer une autre. Le double tiret permet de mettre le code restant en commentaire.
Le résultat final de la fusion avec la variable marque est le code suivant. Ce n'est pas du tout ce qu'avait prévu le programmeur.

```sql
INSERT INTO vehicules (marque, immatriculation, poids) VALUES ('PIRATE', '', 0); DELETE FROM vehicules; --', 'AA12', 99)
```

#### performance

lors de l'éxécution de cette requête dans une boucle. La préparation ***sqlite3_prepare_v2*** et la destruction ***sqlite3_finalize*** vont être appelé à chaque itération. Ce sont des opérations gourmandes en ressources mémoire et en temps processeur.

La solution est de passer par une requête paramétrée. La requête est préparée UNE seule fois, avant la boucle. Commme nous ne connaissons pas encore les valeurs à mettre à l'intérieur nous utilisons des paramètres symbolisés par un ?

```c
char sql2[200] = "INSERT INTO vehicule (immatriculation, marque, poids) VALUES (?, ?, ?)";
sqlite3_prepare_v2(db, sql2, 200, &requete, NULL);

do {
```

Lors de l'exécution les valeurs des variables sont liées (bind) aux paramètres ? de la requête. A cet instant précis le code de la requête est déja préparé et ne peut plus être modifié par les valeurs.

Chaque variable est liée respectivement avec le premier, le deuxième et le troisième ? suivant le bon type.

```c
sqlite3_bind_text(requete, 1, immatriculation, -1, NULL);
sqlite3_bind_text(requete, 2, marque, -1, NULL);
sqlite3_bind_int(requete, 3, poids);

sqlite3_step(requete);
sqlite3_reset(requete);
```

Utiliser **sqlite3_reset** pour réinitialiser les valeurs liées.
Détruire le code de la requête seulement à la sortie de la boucle

```
} while (1);

sqlite3_finalize(requete);
```



### Lire des données

Afficher les données de la table en utilisant la fonction ***sqlite3_step*** autant de fois qu'il y a de lignes à lire.

```c
sqlite3_stmt *requete;
const char sql3[200] = "SELECT * FROM vehicule ORDER BY poids";
sqlite3_prepare_v2(db, sql3, strlen(sql3), &requete, NULL);

do
{
  int result = sqlite3_step(requete);
  if (result != SQLITE_ROW) break; // Si le résultat de la lecture n'est pas une ligne de données alors sortir

  char marque[20];
  strcpy(marque, (const char *)sqlite3_column_text(requete, 0));

  char immatriculation[20];
  strcpy(immatriculation, (const char *)sqlite3_column_text(requete, 1));


  int poids;
  poids = sqlite3_column_int(requete, 2);

  printf("%s %s %d\n", marque, immatriculation, poids);

} while (1);
```

Que se passe t il si dans la base de données une des valeurs est NULL ? Le programme plante. Il faut tester d'abord le type de la colonne retournée avec la fonction ***sqlite3_column_type***.

```c
char marque[20];
if (sqlite3_column_type(requete, 0) != SQLITE_NULL)
{
  strcpy(marque, (const char *)sqlite3_column_text(requete, 0));
}
else
{
  strcpy(marque, "(vide)");
}
```

### Table système

Cooment faire pour ne pas essayer de créer la table à chaque fos que le programme démarre ?

Il faut interroger la table *sqlite_master* qui est la table système de sqlite. Cette table contient la définition des tables que l'utilisateur à créer.

```c
const char *sql4 = "SELECT name, type FROM sqlite_master WHERE name = 'vehicule' AND type = 'table'";
result = sqlite3_prepare_v2(db, sql4, strlen(sql4), &requete, NULL);
result = sqlite3_step(requete);
if (result == SQLITE_ROW)
{
  puts("Table vehicule existante");
}
else
{
  // Créer la table véhicule
```
