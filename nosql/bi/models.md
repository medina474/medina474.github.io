---
title: Modèles de données
---

Il existe deux modèles principaux, le modèle étoile (star) et le modèle flocon (snowflake). Ils sont utilisés dans les entrepôts de données pour organiser les données de manière à **faciliter** les analyses multidimensionnelles, particulièrement dans les systèmes de Business Intelligence (BI). Ces modèles se distinguent par la manière dont les tables de faits et les tables de dimensions sont structurées et reliées entre elles.

##  Modèle étoile (Star Schema)

Le modèle en étoile est une structure simple où une table de faits est reliée **directement** à plusieurs tables de dimensions. Il est appelé "étoile" parce que la table de faits est au centre, et les tables de dimensions sont organisées autour d’elle, formant ainsi une structure qui ressemble à une étoile.

### Caractéristiques du modèle étoile :

- **Simplicité** : Les tables de dimensions ne sont pas normalisées, c’est-à-dire qu’elles peuvent contenir des données redondantes ou dupliquées.
- **Accès rapide** : Comme les tables de dimensions sont dénormalisées (les données sont centralisées et répétées), les requêtes sont plus simples et plus rapides à exécuter. Il y a moins de jointures à réaliser
- **Lisibilité** : Le modèle est simple à comprendre et à concevoir, car il n'y a qu'une seule relation directe entre la table de faits et chaque table de dimension. Idéal pour des besoins analytiques simples avec de grandes quantités de données.

## Modèle flocon (Snowflake Schema)

Le modèle flocon est une extension du modèle étoile. Dans ce modèle, certaines ou toutes les tables de dimensions sont **normalisées**, c’est-à-dire qu'elles sont subdivisées en plusieurs sous-tables pour éliminer les redondances. Le modèle est appelé "flocon" parce que la structure résultante a une forme plus complexe, semblable à celle d'un flocon de neige.
    
### Caractéristiques du modèle flocon :

- **Normalisation** : Les tables de dimensions sont divisées en plusieurs sous-tables pour éliminer les données redondantes. Chaque sous-table représente une dimension spécifique.
- **Complexité** : Les requêtes sont plus complexes à écrire et prennent plus de temps à s'exécuter car elles impliquent plusieurs jointures entre les tables de dimensions et sous-tables.
- **Réduction de la redondance** : Le modèle flocon réduit la redondance des données dans les dimensions. Les tables étant normalisées, les données redondantes sont éliminées, ce qui réduit la taille des tables.

#### Inconvénients :

- **Requêtes plus lentes** : Le modèle flocon nécessite des jointures supplémentaires entre les tables, ce qui peut ralentir l’exécution des requêtes.
- **Complexité accrue** : La structure est plus complexe à comprendre et à concevoir par rapport au modèle étoile.
