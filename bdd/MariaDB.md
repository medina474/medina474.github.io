---
title: MariaDB
---

Installer le [paquet logiciel](/linux/paquet/) `mariadb-server`.

 mariadb-secure-installation

The default password is empty. More accurately, you don't even NEED a password to login as root on the localhost. You just need to BE root. But if you need to set the password the first time (if you allow remote access to root), you need to use this command

## Créer un utilisateur et la base de données associée

``` sql
create user iutsd@'%' identified by 'supermotdepasse';
create database iutsd;
grant all privileges on iutsd.* to 'iutsd'@'%';
```
