---
title: Services
---

L'outil systemctl permet de configurer les services qui sont lancés au démarrage de l'appareil


```shell
$ systemctl list-units --type=service
```

```shell
$ systemctl list-units --type=service --state=running
```



Détail d'un service (`q` pour quitter)

```shell
$ systemctl status service
```

Active un service

```shell
$ systemctl enable service
```

Active et démarre un service

```shell
$ systemctl enable --now service
```

Démarrer un service

```shell
$ systemctl start service
```

Arrête un service

```shell
$ systemctl stop service
```

systemctl unmask name.service

Recharge la configuration

```shell
$ systemctl reload service
```

Arrête et redémarre un service

```shell
$ systemctl restart service
```

## Timer

```shell
$ systemctl list-units --type=timer
```
