---
title: PostgreSQL
---

> Avant d'installer vérifier bien les paramètres linguistiques du système. Ils conditionnent le formatages des données (date, heure, monnaie, tri des caractère accentués) de la base.
{: .warning}

Installer le [paquet logiciel](/linux/paquet/) `postgresql`.

Éditer le fichier de configuration pour écouter sur toutes les interfaces réseaux, sinon les connexions ne sont possibles que depuis la machine locale (`localhost`)

[Éditer](/linux/nano) /etc/postgresql/11/main/postgresql.conf

Changer la ligne en enlevant le caractère de commentaire #

```
listen_addresses = '*'
```

## Administration
L'administration du serveur PostgreSQL se fait à l'aide du l'utilisateur `postgres` (équivalent de root).

```shell
$ su --login postgres
```

### Créer des utilisateurs

Créer un utilisateur simple `iutsd` ainsi qu'une base de données associée.

```shell
$ createuser --pwprompt iutsd
$ createdb iutsd -O iutsd
```

Changer le mot de passe de l'utilisateur (si pas défini lors de la création)

```shell
$ psql

ALTER USER iutsd WITH password 'supermotdepasse';
exit
```

### Commandes utiles psql

```
\du : liste des utilisateurs
\l+ : liste des bases de données
\c  : mydatabase : se connecter à mydatabase
\q  : quitter psql
```
Retourner à l'utilisateur root.

```shell
exit
```

Autoriser l'utilisateur à se connecter à distance

```shell
$ nano /etc/postgresql/11/main/pg_hba.conf
```

Ajouter la ligne

```
#       database    user     address           method
host    sameuser    iutsd    0.0.0.0/0         md5
```

Redémarrer PostgreSql

```shell
$ systemctl restart postgresql
```

## Administration à distance

Télécharger l'outil d'administration graphique [pgAdmin](https://www.pgadmin.org/)

```shell
$ docker pull dpage/pgadmin4
```

Se connecter avec l'utilisateur iutsd à la base de données iutsd (Maintenance database)

```shell
docker run --env-file ./pgadmin4.env dpage/pgadmin4
```

## SIG

> ***SIG (Système d'Information Géographique)*** : est un système d'information conçu pour recueillir, stocker, traiter, analyser, gérer et présenter tous les types de données spatiales (objet dans des coordonnées spatiales xyz), dont des données géographiques (longitude, latitude, altitude).

Les outils SIG permettent aux utilisateurs de créer des requêtes et d’analyser l’information spatiale, de modifier et d’éditer de visualiser des données par le biais de cartes.

PostGIS est une extension spatiale, elle ajoute le support d'objets géographiques au serveur PostgreSQL.

Installer le [paquet logiciel](/linux/paquet/) `postgis`.

Dans psql avec l'utilisateur postgres

```sql
\c iutsd
CREATE EXTENSION postgis;
```
### Maintenance

[Maintenance](maintenance)


### Trigger

Enregister la date et l'heure dans le champ updated_at de l'enregustrement courant qui est actuellement modifier (NEW)

```sql
CREATE OR REPLACE FUNCTION trigger_set_timestamp()
RETURNS TRIGGER AS $$
BEGIN
  NEW.updated_at = NOW();
  RETURN NEW;
END;
$$ LANGUAGE plpgsql;
```

Assigner la fonction lors de la mise à jour de la table `person`

```sql
CREATE TRIGGER set_timestamp
BEFORE UPDATE ON person
FOR EACH ROW
EXECUTE PROCEDURE trigger_set_timestamp();
```

## Liste de contrôle

|application|commande|version|
|-|-|-:|
postgresql|psql --version|11.9
