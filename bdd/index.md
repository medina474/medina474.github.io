---
title: Ressource R5.07 - Base de données
---

### Contenu

Les thèmes recommandés à développer pour atteindre les acquis d’apprentissage visés sont :

- Bases de données :
- Introduction aux bases de données relationnelles ;
- Tables, schémas relationnels ;
- Requêtes SQL de base ;
- Base de données noSQL.
- Introduction à l’IoT :
- Architectures IoT (Extreme edge/edge/mist/fog/cloud, passerelle) ;
- Communication indirecte orientée message (Publier/Souscrire, broker, MQTT) ;
- Gestion de la qualité de service (QoS) ;
- Notions d’API (déclaration, appel de services) ;
- Tableau de bord (node-red, grafana...).

### Volume horaire

Volume horaire défini nationalement : 14 heures dont 8 heures de TP

## Introduction

Dans toutes applications il est important de stocker et d'exploiter les données recoltées.

Le premier support pour le stockage des données est bien entendu le système de fichiers (fs). Le disque dur d'une machine est organisé en une arborescence de répertoire, sous-répertoire et de fichiers.

L'inconvénient de ce système est qu'i faut tout organiser soi même : la structure et le format des fichiers. Il n'y a aucun outil pour analyser et exploiter les données et surtout il n'existe aucun moyen d'assurer une cohérence entre les différents fichiers.

Au fil du temps des logiciels spécialisés ont vu le jour permettant d'apporter des solutions à différents cas d'utilisation.

Il existe plusieurs types de bases de données, chacun conçu pour répondre à des besoins spécifiques en matière de stockage, de gestion et de récupération de données. Voici quelques-uns des types de bases de données les plus couramment utilisés :

### Base de données relationnelle (SGBDR - RDBMS)

Les bases de données relationnelles stockent les données dans des tables avec des lignes et des colonnes. Elles utilisent un langage appelé SQL (Structured Query Language) pour gérer et interroger les données. Les exemples de systèmes de gestion de bases de données relationnelles (SGBDR) incluent MySQL, PostgreSQL, Oracle Database, Microsoft SQL Server, et SQLite. Ce modèle est le plus ancien et le plus répendu des systèmes de base de données.


### Base de données NoSQL

Les bases de données NoSQL (Not Only SQL) sont conçues pour gérer des données non structurées ou semi-structurées, ainsi que des volumes de données massifs. Elles sont utilisées dans des applications telles que le Big Data, le stockage de documents, les réseaux sociaux, et plus encore. Les types de bases de données NoSQL comprennent les bases de données de document, les bases de données clé-valeur, les bases de données orientées colonnes, et les bases de données graphe. Exemples : MongoDB, Cassandra, Redis.

### Bases de données orientées graphe

Les bases de données orientées graphe sont conçues pour stocker et gérer des données sous forme de graphes, avec des nœuds et des arêtes représentant des entités et leurs relations. Elles sont particulièrement utiles pour les applications nécessitant une analyse de réseau, telles que les réseaux sociaux, la recommandation de produits et la détection d'anomalies. Exemples : Neo4j, Amazon Neptune.

### Base de données temps réel en mémoire

Bases de données temps réel (in-memory) : Ces bases de données stockent les données en mémoire vive (RAM) au lieu de les stocker sur des disques. Elles sont utilisées pour des applications nécessitant une très faible latence, telles que la cotation boursière en temps réel, la surveillance des systèmes et les applications de jeu en ligne. Exemples : Redis, Memcached.

### Base de données géospatiale

Les bases de données géospatiales sont spécialement conçues pour stocker et gérer des données spatiales, telles que des informations de localisation, des cartes, des coordonnées GPS, etc. Elles sont couramment utilisées dans les systèmes d'information géographique (SIG) et les applications de navigation.

### Bases de données temps réel et de streaming

Ces bases de données sont conçues pour gérer des flux de données en temps réel, tels que des données de capteurs, des journaux d'événements, des données de médias sociaux en temps réel, etc. Exemples : Apache Kafka, Amazon Kinesis.

### Bases de données embarquées

Ces bases de données sont intégrées directement dans des applications ou des dispositifs matériels. Elles sont utilisées lorsque l'espace de stockage est limité et que des fonctionnalités de base de données locales sont nécessaires. Exemples : SQLite, Berkeley DB.

Chaque type de base de données a ses avantages et ses inconvénients, et le choix dépendra des besoins spécifiques de l'application. De nombreuses applications modernes utilisent également une combinaison de différents types de bases de données pour répondre à leurs exigences en matière de stockage et de traitement de données.

## Définitions

fs
: File System, Système de fichiers est une façon de stocker de façon permanente les informations et de les organiser dans des fichiers sur un disque dur, 


SGBDR
: Système de Gestion de Bases de Données Relationnelles 

RDBMS
: Relational DataBase Management System

## Programme

- [Base de données relationnelle](sgbdr)
- [Travaux dirigés 1](sgbdr/td)
- Le [langage SQL](sql)
- Les [jointures](sql/jointure)
