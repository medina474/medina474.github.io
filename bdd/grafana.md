---
title: Grafana
---

>Grafana est un outil web de visualisation de données. Il fournit des diagrammes, des graphiques, des alertes depuis des sources de données auquel il est connecté.
{.definition}

Pour le visualeur de données nous allons utiliser plutôt Grafana, qui permet de visualiser des données d'autres sources que InfluxDB.

## Intallation

### Sur PC avec Docker

```shell-session
docker pull grafana/grafana

docker run --name=lpamio-grafana -p 9005:3000 -d grafana/grafana:latest
```

### Sur Raspberry

Ajout de la clé du dépôt

```shell-session
$ wget -q -O - https://packages.grafana.com/gpg.key | sudo apt-key add -
```

Ajout du dépôt pour apt

```shell-session
$ echo "deb https://packages.grafana.com/oss/deb stable main" | tee -a /etc/apt/sources.list.d/grafana.list
```

Mise à jour du catalogue des paquets disponibles depuis les dépôts

```shell-session
$ apt update
```

Installation

Installer le [paquet logiciel](/linux/paquet/) `grafana`.


Activation du service

```shell-session
$ systemctl enable --now grafana-server
```

Ouvrir avec un navigateur l'adresse suivante :
[http://iutsd-raspberry30-896.ad.univ-lorraine.fr:3000/](http://iutsd-raspberry30-896.ad.univ-lorraine.fr:3000/)

utilsateur : `admin`\
Mot de passe : `admin`

Stocker le nouveau mot de passe dans KeePass.


### Plugins

```shell-session
$ grafana-cli plugins install grafana-worldmap-panel
$ grafana-cli plugins install simpod-json-datasource
```

## Ajouter une source de données

Ajouter Prometheus

Ajouter InfluxDB

## Ajouter un tableau de bord

Importer un dashoboard : 1860

Dashboard pour une source Telegraf : 928