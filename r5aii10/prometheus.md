---
title: Prometheus
---

> Prometheus est une plateforme open-source de stockage de données temporelles, de surveillance et d'alerte conçue pour collecter, traiter et afficher des métriques de systèmes. 

### Caractéristiques d'une base de données timeseries

Stockage structuré autour du temps

Les données sont organisées en séries temporelles, où chaque point de données a un horodatage, une valeur, et un identifiant unique basé sur des étiquettes (labels).

#### Labels pour contextualiser les séries

Chaque série temporelle est identifiée par un nom et un ensemble de labels (clés-valeurs).

Les labels permettent de distinguer des séries ayant le même nom mais des contextes différents 

#### Stockage optimisé pour les métriques

Les données sont compressées pour gérer efficacement un grand volume de séries.

Les valeurs proches dans le temps sont souvent organisées en blocs pour faciliter les requêtes rapides.

#### Mode d'écriture en "append-only"

Les nouvelles données sont ajoutées chronologiquement à la fin des séries existantes. Ce modèle simplifie l'indexation et optimise les performances.

#### Limitation du stockage dans le temps

Prometheus supprime automatiquement les données anciennes (par défaut 15 jours, configurable). Les utilisateurs qui veulent un archivage à long terme doivent exporter les données vers un autre système.


```shell
sudo apt-get install --no-install-recommends prometheus
```

## Node

```shell
sudo apt-get install --no-install-recommends prometheus-node-exporter
```

## Type des données

Les compteurs, gauges et histogrammes sont des types de métriques utilisés dans Prometheus (et d'autres systèmes similaires) pour représenter différentes natures de données. 

## Compteurs

Un compteur est une métrique cumulative qui augmente seulement ou se réinitialise à zéro (par exemple, au redémarrage d'un système).

### Caractéristiques :
- Toujours croissant : Les valeurs ne diminuent jamais.
-  Représente des événements : Idéal pour des mesures de choses qui ne peuvent pas être inversées (ex. : nombre de requêtes HTTP, erreurs, tâches accomplies).
- Reset : Un compteur peut être réinitialisé (par exemple, après un redémarrage).


## Gauges

Une gauge est une métrique qui peut augmenter ou diminuer, représentant une valeur instantanée.


### Caractéristiques :

- Varie dans les deux sens : Contrairement aux compteurs, une gauge peut augmenter, diminuer ou rester stable.
- Représente un état : Mesure des valeurs "instantanées" qui changent au fil du temps (ex. : température, utilisation mémoire).

## Histogrammes

Un histogramme permet de mesurer la distribution de valeurs observées, divisées en buckets (tranches d’intervalle).

### Caractéristiques :

Mesure des fréquences : Compte combien de fois des valeurs tombent dans des plages définies (buckets).
Calcule des métriques dérivées : Permet d'estimer des percentiles comme le 95e ou le 99e.
Fournit deux types de métriques :
  Histogramme cumulative : Pour chaque bucket, montre le nombre d’observations inférieures ou égales à la borne supérieure du bucket.
  Somme totale des observations : La somme des valeurs de toutes les observations.
