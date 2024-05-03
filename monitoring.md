---
title: Surveiller votre système
---

> ***Objectif :*** Mesurer différentes valeurs de notre système. Utilisation du proceseur, occupation de la mémoire, traffic réseau ... afin d'anticiper la résolution de problèmes
{: .objectif}

## Stocker les données

Les différentes mesures seront colectées à intervalle régulier et les valeurs sotckées dans une [base de données de mesures chronologiques](../bdd/influxdb/).

sur votre PC à l'aide de Docker :

Installer [InfluxDB](../bdd/influxdb)

ou

Installer [Prometheus](../bdd/prometheus)



## Agent de collecte

Un agent de collecte est un programme qui récupère des données de différentes sources, les centralise et les transfert à la base de données suivant 2 méthodes possibles.

Méthode **Push** Un service sur le client se connecte au serveur et envoi les données.

Méthode **Pull** Un service sur le client expose par le biais d'un serveur web les données. Le serveur se connecte sur le client et récupère les données.

L'avantage est que plusieurs serveurs peuvent se connecter à des fréquences variables.

L'agent de collecte assiocé à une base de données InfluxDB est le programme Telegraf. Il fonctionne en mode Push des données.



## Visualiser les données

Lorsque les données sont présentes dans la base de données, il faut pouvoir intérroger et visualiser les données.

Le logiciel Grafana présente les données sous forme de graphique. Il peut se connecter à plusieurs source de données et pas seulement InfluxDB

Installer [Grafana](../bdd/grafana) sur votre PC à l'aide de Docker
