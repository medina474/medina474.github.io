---
title: MEAD
---

ATTENTION REECRIRE
https://learnsql.fr/blog/fonction-sql-lead/

Fonction SQL LEAD


La fonction SQL LEAD est une fonction de fenêtre SQL très importante et utile. Les fonctions SQL window sont essentielles pour effectuer des analyses de données efficaces. Elles vous permettent de travailler avec des groupes de lignes et des lignes individuelles en même temps. Elles facilitent la rédaction de rapports complexes. Elles sont utiles pour préparer des classements, comparer différentes périodes de temps, calculer des totaux courants, des moyennes mobiles, la longueur de la série, et bien d'autres choses encore.

Si vous souhaitez vous familiariser avec les fonctions SQL window, consultez notre cours Fonctions de fenêtrage . Il comprend plus de 200 exercices détaillés et pratiques. Vous pouvez également utiliser notre feuille de contrôle SQL Fonctions de fenêtrage pour une référence rapide. 

Qu'est-ce que la fonction SQL LEAD ?

La fonction SQL LEAD est une fonction SQL window qui vous permet d'accéder aux données d'une ligne ultérieure et de les comparer à la ligne actuelle. Cette fonction est particulièrement utile lorsque vous devez travailler avec des séquences de données. Par exemple, si vous examinez des données de vente, LEAD peut vous montrer les ventes de demain à côté de celles d'aujourd'hui, le tout sur une seule ligne. Il est ainsi facile de voir immédiatement les changements ou les tendances.

Vous pouvez utiliser la fonction LEAD pour

    Comparer les chiffres de vente d'une période à l'autre.
    Calculer la différence entre les niveaux de stock d'un jour à l'autre.
    Estimer les valeurs futures à des fins de budgétisation ou de prévision.

LEAD Cette fonction est similaire à LAG, une autre fonction de fenêtre SQL. La principale différence est que LEAD examine les lignes à venir, tandis que LAG examine les lignes précédentes. Utilisez LEAD lorsque vous souhaitez voir ce qui va se passer et LAG lorsque vous souhaitez revoir ce qui s'est passé auparavant. Les deux sont utiles pour comparer les données avec les lignes voisines.

Pour des exemples d'utilisation des fonctions LEAD et LAG, et pour une comparaison de leurs capacités, voir notre guide Les fonctions LAG et LEAD dans SQL.

Syntaxe de base de la fonction SQL LEAD

La façon la plus simple d'utiliser la fonction LEAD est de n'utiliser qu'un seul argument, qui spécifie la colonne que vous souhaitez consulter :

LEAD(column1) OVER (ORDER BY column2)

Voici une description de cette syntaxe :

  column1: Il s'agit de la colonne à partir de laquelle vous souhaitez accéder aux données de la ligne suivante.
    OVER: Cette clause fait partie de la syntaxe des fonctions de fenêtre. Vous devez l'utiliser avec toutes les fonctions de fenêtre. Elle permet de définir la fenêtre sur laquelle la fonction LEAD fonctionnera.
    ORDER BY column2: Cette clause spécifie l'ordre dans lequel les lignes doivent être traitées et détermine la ligne suivante à partir de laquelle les données doivent être extraites. La clause ORDER BY est obligatoire pour LEAD.

Cette syntaxe permet d'obtenir la valeur de la colonne spécifiée (column1) dans la ligne suivante, en fonction de l'ordre (ORDER BY column2) défini. S'il n'y a pas de ligne suivante, la fonction renvoie NULL.

Exemple 1 : Utilisation de base de la fonction SQL LEAD

Voyons un exemple de base de l'utilisation de la fonction LEAD. Supposons que vous ayez une table nommée production_schedule avec des colonnes pour la date et la quantité de produits requis :
production_date	quantity_required
2024-04-01 	150
2024-04-02 	180
2024-04-03 	200

Si vous souhaitez connaître la quantité requise pour le jour suivant, vous utilisez la fonction LEAD comme suit:

```sql
SELECT
  production_date,
  quantity_required,
  LEAD(quantity_required) OVER (ORDER BY production_date) AS next_day_quantity
FROM
  production_schedule;
```

Cette requête ajoutera une colonne indiquant les quantités requises pour le jour suivant à côté de celles d'aujourd'hui.

production_date 	quantity_required 	next_day_quantity
2024-04-01 	150 	180
2024-04-02 	180 	200
2024-04-03 	200 	null

Dans notre requête OVER(ORDER BY production_date), les lignes sont classées par date de production. La fonction LEAD examine la ligne qui suit la ligne actuelle et en tire la valeur quantity_required. La ligne qui suit 2024-04-01 est celle de 2024-04-02. La quantité requise pour 2024-04-02 est de 180, et c'est ce que LEAD renvoie. S'il n'y a pas de ligne suivante, la fonction LEAD renvoie NULL: il n'y a pas de ligne suivante pour 2024-04-03, donc next_day_quantity est NULL.
LEAD - exemple

Syntaxe de la fonction LEAD Suite : Paramètres facultatifs Offset et Default

La syntaxe complète de la fonction LEAD prend deux autres arguments facultatifs, offset et default. Ils permettent de mieux contrôler le comportement de LEAD.

LEAD(column1, offset, default) OVER (... ORDER BY column2)

Voici la décomposition de cette syntaxe :

column1: Il s'agit de la colonne à partir de laquelle vous souhaitez accéder aux données d'une ligne ultérieure.

    offset: Cet argument entier facultatif spécifie le nombre de lignes qui précèdent la ligne actuelle que vous souhaitez consulter. Si vous omettez ce paramètre, la valeur par défaut est 1, ce qui permet de récupérer les données de la ligne suivante.
    
    default: Cet argument facultatif fournit une valeur par défaut que la fonction renverra si le décalage spécifié dépasse les limites de l'ensemble de résultats. S'il est omis, la valeur de retour par défaut est NULL.
    OVER: Ce mot-clé introduit la spécification de la fenêtre, définissant la manière dont les lignes sont regroupées et ordonnées dans le but de LEAD.

ORDER BY column2: Cette clause spécifie l'ordre dans lequel les lignes sont traitées. Elle détermine la ligne "suivante" dont il faut extraire les données pour chaque ligne de l'ensemble de résultats de la requête en cours.

Exemple 2 : Arguments de décalage et de défaut

Prenons l'exemple de offset et default. En utilisant la même table production_schedule, supposons que vous souhaitiez connaître la quantité requise non seulement pour le lendemain, mais aussi pour les deux jours suivants, et que vous souhaitiez éviter les valeurs de NULL en utilisant plutôt 0:
SELECT
  production_date,
  quantity_required,
  LEAD(quantity_required, 2, 0) OVER (ORDER BY production_date) AS two_days_later_quantity
FROM
  production_schedule;

production_date 	quantity_required 	two_days_later_quantity
2024-04-01 	150 	200
2024-04-02 	180 	0
2024-04-03 	200 	0

Ici, vous donnez 2 comme argument de décalage. Cela indique à la fonction LEAD de regarder deux lignes plus loin, au lieu de la ligne suivante. Vous donnez également 0 comme argument par défaut. Cela permet à la fonction LEAD d'afficher 0 au lieu de NULL lorsqu'il n'y a pas de ligne suivante à partir de laquelle extraire des données.
LEAD - exemple 2

Exemple 3 : Fonction LEAD avec PARTITION BY

Il est évident que vous pouvez utiliser la syntaxe des fonctions de la fenêtre complète avec la fonction LEAD. Par exemple, vous pouvez la combiner avec PARTITION BY. Supposons que votre table production_schedule contienne des données sur plusieurs produits. Vous souhaitez effectuer des prévisions séparément pour chaque produit.

production_date 	product_id 	quantity_required
2024-04-01	101	150
2024-04-02	101	180
2024-04-03	101	200
2024-04-01	102	90
2024-04-02	102	110
2024-04-03	102	120

Vous pouvez partitionner vos données sur OVER(), comme suit :

SELECT
  production_date,
  product_id,
  quantity_required,
  LEAD(quantity_required) OVER (PARTITION BY product_id ORDER BY production_date) AS next_day_quantity
FROM
  production_schedule;

Cette requête vous donne les besoins de production du lendemain pour chaque produit, en séparant les calculs pour chaque product_id.
production_date 	product_id 	quantity_required 	next_day_quantity
2024-04-01 	101 	150 	180
2024-04-02 	101 	180 	200
2024-04-03 	101 	200 	null
2024-04-01 	102 	90 	110
2024-04-02 	102 	110 	120
2024-04-03 	102 	120 	null
Exemples pratiques de la fonction LEAD

Dans cette section, nous examinerons des exemples pratiques d'utilisation de la fonction LEAD dans des situations réelles. La fonction LEAD est particulièrement utile dans des domaines tels que l'analyse des ventes, la gestion des stocks et la planification de la production.

LearnSQL.fr est une plateforme en ligne conçue pour vous aider à maîtriser SQL. LearnSQL.fr vous permet de choisir entre un programme d'apprentissage complet, des mini-programmes pour affiner des compétences ciblées et des cours individuels. Vous pouvez également sélectionner le dialecte SQL (Standard SQL, Microsoft SQL Server ou PostgreSQL) qui correspond le mieux à vos besoins.
Exemple pratique 1 : Planification des commandes de farine pour la production d'une boulangerie

Scénario : Une boulangerie doit planifier la quantité de farine à commander pour chaque production de pain. Il est important d'avoir suffisamment d'ingrédients sans surstocker. Les données relatives à la production planifiée de pain sont stockées dans le tableau daily_bread_production.

production_date 	batches_planned
2024-04-01 	20
2024-04-02 	25
2024-04-03 	30

Nous savons que chaque fournée nécessite 2 kg de farine. Nous voulons connaître la demande de farine pour aujourd'hui et pour demain. Voici la requête que nous pourrions utiliser :
SELECT
  production_date,
  batches_planned * 2 AS flour_needed_today_kg,
  LEAD(batches_planned * 2, 1, 0) OVER (ORDER BY production_date) AS flour_needed_tomorrow_kg
FROM
  daily_bread_production;

La requête calcule la quantité de farine nécessaire pour le jour en cours et le besoin pour le jour suivant à l'aide de la fonction LEAD.

Voici le résultat de la requête :
production_date 	flour_needed_today_kg 	flour_needed_tomorrow_kg
2024-04-01 	40 	50
2024-04-02 	50 	60
2024-04-03 	60 	null

Bien sûr, il s'agit d'un exemple simplifié, mais vous pouvez facilement imaginer comment ce type de requête pourrait être utilisé dans un contexte réel pour prévoir les ressources nécessaires sur la base du calendrier de production prévu.
Exemple pratique 2 : Différence entre deux lignes

Scénario : dans le cadre d'une analyse financière, la fonction LEAD (ou LAG) est utilisée pour calculer la variation des ventes d'un jour à l'autre. Les données relatives aux ventes quotidiennes sont stockées dans le tableau daily_sales.
sales_date 	total_sales
2024-04-01 	100
2024-04-02 	110
2024-04-03 	90
2024-04-04 	150

Cette requête calculera les ventes du jour suivant, l'augmentation entre les ventes d'aujourd'hui et celles du jour suivant, ainsi que le pourcentage de croissance d'un jour à l'autre :

SELECT
  sales_date,
  total_sales,
  LEAD(total_sales) OVER (ORDER BY sales_date) AS next_day_sales,
  LEAD(total_sales) OVER (ORDER BY sales_date) - total_sales AS increase,
  ROUND(((LEAD(total_sales) OVER (ORDER BY sales_date) - total_sales) / total_sales) * 100, 1) AS percentage_growth
FROM
  daily_sales;

Cette requête utilise LEAD pour trouver les ventes du jour suivant. Elle utilise ensuite LEAD et la valeur du jour pour calculer l'augmentation. Enfin, elle utilise LEAD et les ventes du jour pour calculer le pourcentage de croissance quotidien.

Voici le résultat :

sales_date 	total_sales 	next_day_sales 	increase 	percentage_growth
2024-04-01 	100 	110 	10 	10.0
2024-04-02 	110 	90 	-20 	-18.2
2024-04-03 	90 	150 	60 	66.7
2024-04-04 	150 	null 	null 	null

Pour plus d'exemples et une utilisation plus détaillée des fonctions de fenêtre, consultez l'article SQL Fonctions de fenêtrage Examples, qui offre une perspective plus large et des scénarios supplémentaires. Cette ressource peut vous aider à approfondir votre compréhension et à améliorer votre capacité à mettre en œuvre les fonctions de fenêtre SQL de manière efficace.
Conclusion et autres ressources

Nous avons exploré la fonction SQL LEAD, une fonction de fenêtre SQL puissante qui permet aux analystes de consulter les lignes suivantes de leurs ensembles de données. Nous avons abordé la syntaxe de base de la fonction LEAD et nous avons montré son application dans divers scénarios tels que les tendances des ventes, la gestion des stocks et la planification de la production.


Pour ceux qui débutent avec les fonctions de fenêtre, je recommande notre cours Fonctions de fenêtrage . Il s'agit d'un programme de formation interactif et pratique conçu pour vous familiariser avec la syntaxe complète et les applications des fonctions SQL à fenêtre. Il comprend 218 exercices pratiques qui vous aideront à maîtriser les détails des fonctions SQL window.

Si vous cherchez à vous entraîner sur les fonctions SQL window pour consolider votre compréhension, notre kit d'entraînement Fonctions de fenêtrage propose 100 exercices pratiques qui mettront à l'épreuve et consolideront vos connaissances. En outre, notre article SQL Fonctions de fenêtrage Practice Exercises fournit un ensemble d'exercices sélectionnés dans nos cours pour tester vos compétences en matière de fonctions de fenêtre et vous donner un avant-goût de ce que sont nos cours.
