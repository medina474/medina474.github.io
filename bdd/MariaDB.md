---
title: MariaDB
---

Installer le [paquet logiciel](/linux/paquet/) `mariadb-server`.


## Créer un utilisateur et la base dedonnées associées

``` sql
create user iutsd@'%' identified by 'supermotdepasse';
create database iutsd;
grant all privileges on iutsd.* to 'iutsd'@'%';
```
