---
title: Maintenance d'un serveur PostgreSQL
---

## Sauvegarder la base de données iutsd

```shell-session
$ pg_dump iutsd > iutsd.out
```

## restaurer la sauvegarde

```shell-session
$ psql -d iutsd -v ON_ERROR_STOP=1  -f /var/lib/postgresql/iutsd.out
```

ou l'outil spécifique _pg_restore_.

```shell-session
pg_restore iutsd.backup --clean
```

### scripts de maintenance et de sauvegarde automatique

[pgbackup.sh](pgbackup.sh)

## Tâche de maintenance

Pour effectuer des tâches automatisées de maintenance il va falloir plusieurs fichiers :

* Le script à exécuter ;
* Le fichier "*service*" qui va dire **quel** script exécuter et comment ;
* Le fichier "*timer*" qui va indiquer **quand** il doit être exécuté.

Pour simplifier, les fichiers service et timer doivent avoir le même nom, mais ce n'est pas obligatoire.

[Éditer](/linux/nano) /etc/systemd/system/pgbackup.service

voir le fichier [pgbackup.service](pgbackup.service)

[Éditer](/linux/nano) /etc/systemd/system/pgbackup.timer

voir le fichier [pgbackup.timer](pgbackup.timer)


```shell-session
$ systemctl enable --now mybackup.timer
```

```shell-session
$ systemctl list-timers --all
```
