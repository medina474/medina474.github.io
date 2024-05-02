---
title: Services
---

L'outil systemctl permet de configurer les services qui sont lancés au démarrage de l'appareil


```shell-session
$ systemctl list-units --type=service
```

```shell-session
$ systemctl list-units --type=service --state=running
```



Détail d'un service (`q` pour quitter)

```shell-session
$ systemctl status service
```

Active un service

```shell-session
$ systemctl enable service
```

Active et démarre un service

```shell-session
$ systemctl enable --now service
```

Démarrer un service

```shell-session
$ systemctl start service
```

Arrête un service

```shell-session
$ systemctl stop service
```

systemctl unmask name.service

Recharge la configuration

```shell-session
$ systemctl reload service
```

Arrête et redémarre un service

```shell-session
$ systemctl restart service
```

## Timer

```shell-session
$ systemctl list-units --type=timer
```