---
title: LAG
---

ATTENTION REECRIRE
https://learnsql.fr/blog/fonction-sql-lag/

Fonction SQL LAG()

La fonction LAG() - l'une des fonctions de fenêtre de SQL, est un outil important pour la planification et l'analyse des tendances. 

LesfonctionsSQL window, également appelées fonctions analytiques ou fonctions OVER, ajoutent une nouvelle dimension à l'analyse des données. Elles vous permettent d'inclure des agrégats ou des données provenant d'autres lignes à côté de la ligne actuelle.

La fonction LAG() vous permet de regarder "par la fenêtre" une ligne précédente et d'inclure ses données à côté de la ligne actuelle. Une fonction similaire, LEAD(), vous permet de vous projeter dans les lignes suivantes. En utilisant les fonctions LEAD() et LAG(), vous pouvez facilement inclure dans vos rapports des éléments utiles tels que des comparaisons d'une année sur l'autre.

Si l'analyse des données vous tient à cœur, vous pouvez consulter le cours LearnSQL.fr'sFonctions de fenêtrage . Vous apprendrez en résolvant plus de 200 exercices interactifs guidés à l'aide d'une base de données réelle à laquelle vous accéderez via votre navigateur. Le cours dure environ 20 heures ; lorsque vous aurez terminé, vous pourrez utiliser vos nouvelles compétences pour dynamiser vos propres projets d'analyse de données.

Que fait la fonction LAG() ?

Cette fonction vous permet d'inclure une valeur de colonne provenant d'une ligne antérieure aux côtés des données de la ligne actuelle. Elle est particulièrement utile pour analyser les tendances dans le temps, telles que les comparaisons mois par mois et année par année.

La meilleure façon d'apprendre les fonctions de fenêtrage est de les mettre en pratique. Je recommande ce cours sur Fonctions de fenêtrage. Il comporte 218 exercices interactifs, ce qui équivaut à environ 20 heures de codage.

Elle peut également être utilisée pour répondre à diverses questions. Quelle est l'ampleur de l'écart entre les résultats moyens de l'école A et de l'école B ? Dans quelle mesure l'utilisation d'une matière première différente affecte-t-elle la durée de vie d'un composant ?

Syntaxe de la fonction LAG()

Dans sa forme la plus simple, la syntaxe de la fonction SQL LAG() est ...
LAG(column_1) OVER (ORDER BY column_2)

... où :

    column_1 est le nom de la colonne que vous souhaitez inclure dans la ligne précédente.
    OVER indique que vous utilisez une fonction de fenêtre ; ce mot-clé est obligatoire.
    ORDER BY est également obligatoire lorsque vous utilisez LAG(). La séquence des lignes doit être prévisible, sinon la fonction n'a pas de sens. Toutefois, l'ordre choisi ne doit pas nécessairement être le même que celui du rapport final.
    column_2 est la colonne que vous utilisez pour ordonner les lignes. Vous pouvez spécifier plus d'une colonne ici.

SQL séquence d'abord vos données en utilisant les valeurs de la colonne_2. À chaque ligne, il revient à la ligne précédente de cette séquence et récupère la valeur de la colonne_1. Cette valeur est incluse avec toutes les autres données que vous avez demandées pour la ligne en cours.
Exemple de base de la fonction LAG()

Examinons une simple comparaison d'un mois sur l'autre. Un tableau nommé monthly_sales contient les données suivantes :
year	month	sales_qty	sales_value
2023	12	1000	7380
2024	1	800	5620
2024	2	942	6945
2024	3	1270	1745
2024	4	1520	2048
2024	5	1400	1890

Si vous voulez voir les ventes du mois dernier avec celles du mois en cours, votre requête sera la suivante :
SELECT
  year,
  month,
  sales_value,
  LAG(sales_value) OVER (ORDER BY year, month) AS last_month
FROM monthly_sales;

Le résultat ressemble à ceci :
year	month	sales_value	last_month
2023	12	7380	NULL
2024	1	5620	7380
2024	2	6945	5620
2024	3	1745	6945
2024	4	2048	1745
2024	5	1890	2048

Remarquez que la valeur des ventes du mois précédent a été ramenée dans la ligne du mois en cours :
Fonction SQL LAG()
Exemples plus complexes

Maintenant que vous avez appris à effectuer une requête simple à l'aide de la fonction SQL LAG(), examinons d'autres façons de l'utiliser dans votre analyse.
Utilisation de LAG() dans les calculs

Vous souhaiterez souvent utiliser les résultats de LAG() dans des calculs. Par exemple, vous voudrez peut-être voir la différence et le pourcentage de changement entre les mois. Modifions la requête précédente pour inclure ces calculs.

Vous pouvez utiliser le résultat d'une fonction dans des calculs comme vous le feriez pour n'importe quelle autre colonne.

La requête se présente comme suit :

```sql
SELECT
  year,
  month,
  sales_value,
  LAG(sales_value) OVER (ORDER BY year, month) AS last_month,
  sales_value - LAG(sales_value) OVER (ORDER BY year, month) AS change,
  ((sales_value - LAG(sales_value) OVER (ORDER BY year, month)) * 100)
   / (LAG(sales_value) OVER (ORDER BY year, month)) AS percentage
FROM monthly_sales;
```

Les résultats sont les suivants :
year	month	sales_value	last_month	change	percentage
2023	12	7380	NULL	NULL	NULL
2024	1	5620	7380	-1760	-23.85
2024	2	6945	5620	1325	23.58
2024	3	1745	6945	-5200	-74.87
2024	4	2048	1745	303	17.36
2024	5	1890	2048	-158	-7.71
Utilisation de LAG() avec un décalage

Dans les exemples que nous avons examinés, la requête a récupéré les données de la ligne précédente de l'ensemble. C'est le comportement par défaut. Cependant, vous pouvez revenir en arrière de plus d'une ligne en spécifiant un décalage.

La syntaxe pour spécifier un décalage est la suivante :
LAG(column_1, offset) OVER (ORDER BY column_2)

Le offset est un nombre entier indiquant combien de lignes la requête doit remonter pour trouver les données. Si vous n'indiquez pas de décalage, la base de données suppose un décalage de 1.

Supposons que vous souhaitiez voir côte à côte les ventes de ce mois-ci, les ventes du mois dernier et les ventes du mois précédent. La requête est la suivante :
SELECT
  year,
  month,
  sales_value,
  LAG(sales_value) OVER (ORDER BY year, month) AS last_month,
  LAG(sales_value,2) OVER (ORDER BY year, month) AS prev_month
FROM monthly_sales;

Les résultats sont les suivants :
year	month	sales_value	last_month	prev_month
2023	12	7380	NULL	NULL
2024	1	5620	7380	NULL
2024	2	6945	5620	7380
2024	3	1745	6945	5620
2024	4	2048	1745	6945
2024	5	1890	2048	1745
Y compris une valeur par défaut

Dans les résultats que nous avons examinés, la fonction LAG() a renvoyé NULL dans la première ligne parce qu'il n'y avait pas de ligne précédente. Ce n'est pas toujours le cas.

Par exemple, supposons qu'une entreprise ait ouvert ses portes en décembre 2023. Vous voudrez peut-être le montrer en mettant zéro dans les ventes du mois dernier pour décembre, afin qu'il soit évident que les ventes sont passées de rien à 7380 au cours de ce mois.

Le zéro est appelé valeur par défaut - une valeur affichée lorsqu'il n'y a pas de chiffres.

Pour inclure une valeur par défaut dans votre requête, la syntaxe est la suivante :
LAG(column_1, offset, default) OVER (ORDER BY column_2)

Notez que vous devez toujours spécifier un décalage si vous incluez une valeur par défaut. Le décalage sera de 1 si vous souhaitez consulter la ligne précédant immédiatement la ligne actuelle.

La requête pour l'exemple ci-dessus est: :
SELECT
  year,
  month,
  sales_value,
  LAG(sales_value, 1, 0) OVER (ORDER BY year, month) AS last_month
FROM monthly_sales;

Les résultats sont les suivants :
year	month	sales_value	last_month
2023	12	7380	0
2024	1	5620	7380
2024	2	6945	5620
2024	3	1745	6945
2024	4	2048	1745
2024	5	1890	2048
Utilisation de LAG() avec PARTITION BY

Supposons que les données d'origine aient été étendues pour inclure plus d'un département :
department	year	month	sales_qty	sales_value
Electrical	2023	12	1000	7380
Electrical	2024	1	800	5620
Electrical	2024	2	942	6945
Electrical	2024	3	1270	1745
Electrical	2024	4	1520	2048
Electrical	2024	5	1400	1890
Hardware	2023	12	6400	9000
Hardware	2024	1	4000	6520
Hardware	2024	2	7000	10300
Hardware	2024	3	8000	12000
Hardware	2024	4	8050	14000
Hardware	2024	5	6000	9000

Vous voudrez probablement que chaque département soit séparé dans votre comparaison. C'est ce qu'on appelle le partitionnement. La syntaxe pour diviser vos résultats en partitions est la suivante : ...
LAG(column_1) OVER (PARTITION BY column_2 ORDER BY column_3)

... où column_2 est la colonne que vous souhaitez utiliser pour le partitionnement.

Essayons une requête qui divise le rapport par département tout en classant les lignes par année et par mois au sein de chaque département :
SELECT
  department,
  year,
  month,
  sales_value,
  LAG(sales_value) OVER (PARTITION BY department ORDER BY year, month) AS last_month
FROM monthly_sales;

Les résultats ressemblent à ceci :
department	year	month	sales_value	last_month
Electrical	2023	12	7380	NULL
Electrical	2024	1	5620	7380
Electrical	2024	2	6945	5620
Electrical	2024	3	1745	6945
Electrical	2024	4	2048	1745
Electrical	2024	5	1890	2048
Hardware	2023	12	9000	NULL
Hardware	2024	1	6520	9000
Hardware	2024	2	10300	6520
Hardware	2024	3	12000	10300
Hardware	2024	4	14000	12000
Hardware	2024	5	9000	14000

Remarquez que les ventes du mois dernier reviennent à NULL sur la première ligne du nouveau département.

Si vous aimez apprendre SQL à l'aide d'exercices pratiques, vous devez essayer LearnSQL.fr.

SQL utilise department comme clé de tri primaire parce qu'elle a été spécifiée dans la clause PARTITION BY. À l'intérieur de department, il ordonne les données par year, puis par month, conformément à la clause ORDER BY.

Pour chaque ligne, il vérifie s'il existe une ligne précédente appartenant au même department. Si c'est le cas, il récupère le contenu de la colonne sales_value de la ligne précédente. Ce contenu est inclus dans la ligne actuelle en tant que last_month. S'il n'y a pas de ligne précédente, last_month prend la valeur NULL.
Utilisation des résultats de LAG() pour ordonner un rapport

L'ordre final du rapport ne doit pas nécessairement être le même que l'ordre utilisé dans la clause OVER. Vous pouvez utiliser la clause normale ORDER BY à la fin de votre requête pour spécifier un ordre différent.

Supposons que vous souhaitiez afficher les résultats dans l'ordre de l'augmentation de la valeur des ventes entre les mois.

Votre requête pourrait ressembler à ceci :
SELECT
  department,
  year,
  month,
  sales_value,
  sales_value - LAG(sales_value) OVER (PARTITION BY department ORDER BY year, month) AS change
FROM monthly_sales
ORDER BY
  department,
  sales_value - LAG(sales_value) OVER (PARTITION BY department ORDER BY year, month);

Les résultats se présentent comme suit :
department	year	month	sales_value	change
Electrical	2023	12	7380	NULL
Electrical	2024	3	1745	-5200
Electrical	2024	1	5620	-1760
Electrical	2024	5	1890	-158
Electrical	2024	4	2048	303
Electrical	2024	2	6945	1325
Hardware	2023	12	9000	NULL
Hardware	2024	5	9000	-5000
Hardware	2024	1	6520	-2480
Hardware	2024	3	12000	1700
Hardware	2024	4	14000	2000
Hardware	2024	2	10300	3780

Cela peut s'avérer utile si vous souhaitez savoir quand l'entreprise se portait mal et quand elle se portait bien. Ces informations peuvent vous aider à remonter à la source d'éventuels problèmes.
Pour en savoir plus sur la fonction SQL LAG()

Si vous souhaitez en savoir plus sur la fonction LAG() - et sur les fonctions de fenêtre en général - voici quelques articles qui vous fourniront des informations complémentaires :

    Les fonctions LAG() et LEAD() en SQL
    Fonction SQL LEAD()
    Comment calculer les différences d'une année sur l'autre en SQL

Si vous avez besoin de vous rafraîchir la mémoire sur les fonctions de fenêtre, ces ressources peuvent vous aider :

    Cette feuille d'aideFonctions de fenêtrage est idéale pour vous aider à écrire des requêtes.
    Si vous êtes novice en la matière, ces exemples de fonctions de fenêtre vous seront très utiles.
    Si vous êtes à la recherche d'un emploi, voici quelques questions d'entretien surFonctions de fenêtrage . Étudiez-les et elles vous aideront à réussir l'entretien SQL.

Comme je l'ai déjà mentionné, si vous voulez vraiment devenir un expert, je vous recommande le coursFonctions de fenêtrage de LearnSQL.fr. Vous apprendrez exactement comment utiliser toute la puissance des fonctions de fenêtre de SQL. Et vous gagnerez en confiance en résolvant de nombreux exercices pratiques.

LearnSQL.fr est une plateforme en ligne conçue pour vous aider à maîtriser SQL. LearnSQL.fr vous permet de choisir entre un programme d'apprentissage complet, des mini-programmes pour affiner des compétences ciblées et des cours individuels. Vous pouvez également sélectionner le dialecte SQL (Standard SQL, Microsoft SQL Server ou PostgreSQL) qui correspond le mieux à vos besoins.

Il n'y a rien de tel que la pratique pour améliorer vos connaissances et vos compétences. Si vous souhaitez obtenir des exemples guidés pour travailler par vous-même, voici quelques ressources :

    L'article Fonctions de fenêtrage Practice Exercises contient 11 exercices avec leurs solutions.
    Ce Fonctions de fenêtrage Practice Set est une piste d'apprentissage contenant plus de 100 exercices pratiques. Vous travaillerez sur trois bases de données différentes pour apprendre à résoudre différents types de problèmes.

La fonction LAG() de SQL est un outil formidable pour analyser vos données afin d'identifier rapidement les tendances et de maintenir la compétitivité de votre organisation. En tant qu'analyste de données, il vaut la peine de consacrer du temps à devenir un expert de la fonction window !
