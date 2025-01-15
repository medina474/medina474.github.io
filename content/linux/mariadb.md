---
title: MariaDB
---

Installer le [paquet logiciel](/linux/paquet/) `mariadb-server`.

```sh
apt install --no-install-recommends mariadb-server
```

sudo mysql_secure_installation

- Switch to unix_socket authentication [Y/n] n
- Change the root password? [Y/n] y
- Remove anonymous users? [Y/n] y
- Disallow root login remotely? [Y/n] y
- Remove test database and access to it? [Y/n] y
- Reload privilege tables now? [Y/n] y


/etc/mysql/mariadb.cnf

port = 3306

/etc/mysql/mariadb.conf.d/50-server.cnf

Mettre en commentaire

mariadb -u root -p

select user, host from mysql.user;

create user root@'%' identified by 'supermotdepasse';
