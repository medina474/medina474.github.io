---
title: MariaDB
---

```
mariadb-secure-installation
```

- Switch to unix_socket authentication [Y/n] n
- Change the root password? [Y/n] y
- Remove anonymous users? [Y/n] y
- Disallow root login remotely? [Y/n] n
- Remove test database and access to it? [Y/n] y
- Reload privilege tables now? [Y/n] y


The default password is empty. More accurately, you don't even NEED a password to login as root on the localhost. You just need to BE root. But if you need to set the password the first time (if you allow remote access to root), you need to use this command

sudo mariadb_secure_installation

select user, host from mysql.user;

## Créer un utilisateur et la base de données associée

``` sql
create user root@'%' identified by 'supermotdepasse';
create database iutsd;
grant all privileges on iutsd.* to 'iutsd'@'%';
```
WITH GRANT OPTION
