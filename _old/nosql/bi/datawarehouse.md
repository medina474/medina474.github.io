---
title: Entrepôts de données
---

Un data warehouse, ou entrepôt de données, est un système de gestion de base de données conçu pour stocker, consolider et organiser de grandes quantités de données provenant de sources multiples en vue d’une analyse et d’un reporting. Il sert de référentiel centralisé où les données sont structurées de manière à faciliter la prise de décision et les analyses historiques dans les entreprises.

- **Centralisation des données** : Un data warehouse intègre des données provenant de différentes sources (bases de données opérationnelles, ERP, CRM, fichiers externes, etc.). Ces données sont rassemblées dans un seul et même endroit pour un accès facilité et une vision globale des informations.
- **Historisation des données** : Contrairement aux bases de données transactionnelles, qui stockent des données en temps réel ou à court terme, un data warehouse contient des données historiques. Il permet donc d’analyser des tendances et d’effectuer des prévisions basées sur plusieurs années d’informations.
- **Optimisation pour l'analyse** : Les données dans un data warehouse sont structurées de manière à faciliter les requêtes analytiques complexes. Elles sont souvent organisées selon un modèle multidimensionnel (modèle étoile ou flocon) pour permettre une analyse rapide et facile à travers divers axes (produits, clients, régions, temps, etc.).
- **Extraction, Transformation, Chargement (ETL)** : Les données intégrées dans un data warehouse passent par un processus ETL :
  - **Extraction** : Les données sont extraites des différentes sources.
  - **Transformation** : Les données sont nettoyées, agrégées et transformées pour être cohérentes entre elles.
  - **Chargement** : Les données transformées sont ensuite chargées dans le data warehouse.
- **Non volatile** : Une fois les données intégrées dans l’entrepôt de données, elles ne sont pas modifiées ou mises à jour, contrairement aux bases de données opérationnelles. Cela permet d'assurer une intégrité historique des informations pour des analyses fiables.
- **Orienté sujet**: Les data warehouses sont souvent organisés par thème ou sujet d’intérêt. Par exemple, un entrepôt de données peut avoir des sections dédiées aux ventes, aux finances, ou à la logistique. Cela permet aux utilisateurs d'accéder directement aux données pertinentes pour leurs besoins.

## Architecture d'un data warehouse

### Sources de données
Des données proviennent de différentes applications et bases de données (systèmes transactionnels, feuilles Excel, ERP, CRM, etc.).

### Processus ETL
Ce processus assure la transformation et l’intégration des données. Il comprend l’extraction des données des systèmes sources, leur nettoyage, la gestion des incohérences, l’intégration et le chargement dans l’entrepôt.

### Entrepôt de données
Il s'agit de la base de données centralisée où les données sont stockées de manière structurée pour faciliter l’analyse.

### Outils d'accès et d'analyse
Les utilisateurs peuvent accéder aux données du data warehouse via des outils de Business Intelligence (BI) comme des tableaux de bord, des rapports, ou des outils de requête SQL.

## Avantages d'un data warehouse

- Consolidation des données : Il centralise les données provenant de diverses sources, ce qui permet une vision globale et cohérente de l'entreprise.
- Analyse historique : Les données historiques stockées dans le data warehouse permettent d'identifier des tendances et de prendre des décisions stratégiques éclairées.
- Amélioration des performances analytiques : Les entrepôts de données sont conçus pour optimiser les requêtes analytiques complexes, ce qui les rend plus rapides et efficaces que les bases de données transactionnelles.
- Fiabilité et intégrité des données : Les processus ETL garantissent que les données sont nettoyées, transformées et harmonisées avant d’être chargées dans l’entrepôt, réduisant ainsi les risques d’erreurs.

## Exemples d'utilisation d'un data warehouse

- Analyse des ventes : Une entreprise peut utiliser un data warehouse pour analyser les tendances de vente sur plusieurs années, en segmentant les données par produit, région, ou période.
- Prévision financière : Un entrepôt de données peut aider à compiler et à analyser des données financières provenant de différents services pour prévoir les performances futures.
- Optimisation des opérations : En agrégeant des données de production, de logistique et de ventes, un data warehouse permet d’optimiser les chaînes d'approvisionnement et les processus opérationnels.

Dans le cadre de la Business Intelligence (BI) et plus précisément dans la conception des entrepôts de données, les tables de faits et les tables de dimensions sont des concepts centraux du modèle en étoile ou modèle multidimensionnel.

## Tables de faits

Une table de faits est au cœur d'un entrepôt de données. Elle stocke des données **quantitatives** ou **mesurables** liées aux événements d'une entreprise. Ces événements sont souvent des transactions ou des interactions importantes que l'entreprise souhaite analyser. Les données de la table de faits représentent des **mesures chiffrées** (par exemple, ventes, revenus, quantité vendue, etc.), qui sont généralement utilisées pour l'analyse et l'évaluation des performances.

Caractéristiques d'une table de faits :

- **Granularité** : Chaque ligne de la table représente un événement unique ou une transaction. La granularité définit le niveau de détail des faits (par exemple, un enregistrement par jour, par produit, par client, etc.).
- **Mesures** : Les colonnes de la table de faits contiennent les mesures numériques (chiffres de vente, quantités, coûts, bénéfices, etc.).
- **Clés étrangères** : Les tables de faits contiennent des clés étrangères qui se réfèrent aux clés primaires des tables de dimensions. Ces clés permettent de relier les faits aux informations contextuelles (produit, temps, client).

## Tables de dimensions

Les tables de dimensions fournissent des informations **qualitatives** ou **descriptives** qui donnent un contexte aux données stockées dans les tables de faits. Elles ne contiennent généralement pas de mesures, mais des **attributs** qui décrivent les faits. Par exemple, dans une analyse des ventes, les dimensions pourraient être le produit, le client, ou le temps.

## Relation entre les tables de faits et les tables de dimensions

La relation entre les tables de faits et de dimensions se fait par des clés étrangères. Par exemple, une vente spécifique (enregistrée dans la table de faits) est liée à un produit précis, un client spécifique et une date donnée (enregistrés dans les tables de dimensions correspondantes). Cela permet de construire des analyses détaillées, telles que les ventes par produit, par période de temps ou par région.

Les tables de dimensions apportent le **contexte descriptif** nécessaire pour analyser ces données. 
