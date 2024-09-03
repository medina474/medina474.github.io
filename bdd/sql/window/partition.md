ATTENTION REECRIRE
https://learnsql.fr/blog/comment-utiliser-la-clause-sql-partition-by-avec-over/

Comment utiliser la clause SQL PARTITION BY avec OVER

Au cœur de chaque appel de fonction fenêtre se trouve une clause OVER qui définit comment les fenêtres des enregistrements sont construites. Dans la clause OVER, il peut y avoir une sous-clause facultative PARTITION BY qui définit les critères d'identification des enregistrements à inclure dans chaque fenêtre. Poursuivez votre lecture et franchissez une étape importante dans le développement de vos compétences en SQL !
Qu'est-ce que la clause PARTITION BY en SQL ?

L'expression SQL PARTITION BY est une sous-clause de la clause OVER, qui est utilisée dans presque toutes les invocations de fonctions de fenêtre comme AVG(), MAX() et RANK(). Comme de nombreux lecteurs le savent probablement, les fonctions de fenêtre opèrent sur des cadres de fenêtre qui sont des ensembles de lignes qui peuvent être différents pour chaque enregistrement du résultat de la requête. C'est là qu'intervient la sous-clause SQL PARTITION BY: elle permet de définir les enregistrements qui doivent faire partie du cadre de fenêtre associé à chaque enregistrement du résultat.

Cet article explique le SQL PARTITION BY et ses utilisations avec des exemples. Comme il est profondément lié aux fonctions de fenêtre, vous pouvez d'abord lire certains articles sur les fonctions de fenêtre, comme "SQL Window Function Example With Explanations", où vous trouverez de nombreux exemples. Si vous souhaitez en savoir plus sur les fonctions de fenêtre, il existe également un article intéressant contenant de nombreux pointeurs vers d'autres articles sur les fonctions de fenêtre.

La première chose à laquelle il faut s'intéresser est la syntaxe. Voici comment utiliser la clause SQL PARTITION BY:

```sql
SELECT
    <column>,
    <window function=""> OVER(PARTITION BY <column> [ORDER BY <column>])
FROM table;
</column></column></window></column>
```

Examinons un exemple qui utilise une clause PARTITION BY. Nous allons utiliser la table suivante appelée car_list_prices:
car_make	car_model	car_type	car_price
Ford	Mondeo	premium	18200
Renault	Fuego	sport	16500
Citroen	Cactus	premium	19000
Ford	Falcon	low cost	8990
Ford	Galaxy	standard	12400
Renault	Megane	standard	14300
Citroen	Picasso	premium	23400

Pour chaque voiture, nous voulons obtenir la marque, le modèle, le prix, le prix moyen sur l'ensemble des voitures, et le prix moyen sur le même type de voiture (pour avoir une meilleure idée de la façon dont le prix d'une voiture donnée se compare aux autres voitures). Voici la requête :
SELECT
    car_make,
    car_model,
    car_price,
    AVG(car_price) OVER() AS "overall average price",
    AVG(car_price) OVER (PARTITION BY car_type) AS "car type average price"
FROM car_list_prices

Le résultat de la requête est le suivant :
car_make	car_model	car_price	overall average price	car type average price
Ford	Mondeo	18200	16112.85	8990.00
Renault	Fuego	16500	16112.85	20200.00
Citroen	Cactus	19000	16112.85	20200.00
Ford	Falcon	8990	16112.85	20200.00
Ford	Galaxy	12400	16112.85	16500.00
Renault	Megane	14300	16112.85	13350.00
Citroen	Picasso	23400	16112.85	13350.00

La requête ci-dessus utilise deux fonctions de fenêtre. La première est utilisée pour calculer le prix moyen de toutes les voitures de la liste de prix. Elle utilise la fonction fenêtre AVG() avec une clause OVER vide comme nous le voyons dans l'expression suivante :
AVG(car_price) OVER() AS "overall average price"

La deuxième fonction de fenêtre est utilisée pour calculer le prix moyen d'un car_type spécifique comme standard, premium, sport, etc. C'est ici que nous utilisons une clause OVER avec une sous-clause PARTITION BY comme nous le voyons dans cette expression :
AVG(car_price) OVER (PARTITION BY car_type) AS "car type average price"

Les fonctions de fenêtre sont assez puissantes, non ? Si vous souhaitez en apprendre davantage en faisant des exercices bien préparés, je vous suggère le cours Fonctions de fenêtragequi vous permettra d'apprendre et de vous familiariser avec l'utilisation des fonctions de fenêtre dans les bases de données SQL.
Approfondir la clause SQL PARTITION BY

La clause GROUP BY regroupe un ensemble d'enregistrements en fonction de critères. Cela nous permet d'appliquer une fonction (par exemple, AVG() ou MAX()) à des groupes d'enregistrements pour obtenir un résultat par groupe.

La meilleure façon d'apprendre les fonctions de fenêtrage est de les mettre en pratique. Je recommande ce cours sur Fonctions de fenêtrage. Il comporte 218 exercices interactifs, ce qui équivaut à environ 20 heures de codage.

Par exemple, supposons que nous voulions obtenir le prix moyen et le prix le plus élevé pour chaque marque. Utilisez la requête suivante :
SELECT car_make,
       AVG(car_price) AS average_price,
       MAX(car_price) AS top_price
FROM   car_list_prices
GROUP BY car_make

Voici le résultat de cette requête :
car_make	average_price	top_price
Ford	13196	18200
Renault	15400	16500
Citroen	21200	23400

Par rapport aux fonctions de fenêtre, GROUP BY réduit les enregistrements individuels en un groupe. Par conséquent, vous ne pouvez pas faire référence à un champ d'enregistrement individuel, c'est-à-dire que seules les colonnes de la clause GROUP BY peuvent être référencées.

Par exemple, supposons que vous souhaitiez créer un rapport contenant le modèle, le prix et le prix moyen de la marque. Vous ne pouvez pas le faire en utilisant GROUP BY, car les enregistrements individuels de chaque modèle sont réduits en raison de la clause GROUP BY car_make. Pour ce genre de chose, vous devez utiliser les fonctions de fenêtre, comme nous le voyons dans l'exemple suivant :
SELECT car_make,
       car_model,
       car_price,
       AVG(car_price) OVER (PARTITION BY car_make) AS average_make
FROM   car_list_prices

Le résultat de cette requête est le suivant :
car_make	car_model	car_price	average_make
Citroen	Picasso	23400	21200
Citroen	Cactus	19000	21200
Ford	Galaxy	12400	13196
Ford	Falcon	8990	13196
Ford	Mondeo	18200	13196
Renault	Megane	14300	15400
Renault	Fuego	16500	15400

Pour ceux qui veulent aller plus loin, je suggère l'article ""Quelle est la différence entre un GROUP BY et un PARTITION BY ?" avec de nombreux exemples utilisant les fonctions agrégat et fenêtre.

En plus de la clause PARTITION BY, il existe une autre clause appelée ORDER BY qui établit l'ordre des enregistrements dans le cadre de la fenêtre. Certaines fonctions de fenêtre nécessitent une clause ORDER BY. Par exemple, les fonctions de fenêtre LEAD() et LAG() ont besoin que la fenêtre d'enregistrement soit ordonnée car elles accèdent à l'enregistrement précédent ou suivant à partir de l'enregistrement actuel.

Un cadre de fenêtre est composé de plusieurs lignes définies par les critères de la clause PARTITION BY. Cependant, nous pouvons spécifier des limites ou des bornes au cadre de la fenêtre comme nous le voyons dans l'image suivante :
Comment utiliser la méthode SQL PARTITION BY avec OVER

Les limites inférieures et supérieures de la clause OVER peuvent être :

    UNBOUNDED PRECEDING
    n PRECEDING
    CURRENT ROW
    n FOLLOWING
    UNBOUNDED FOLLOWING

Lorsque nous ne spécifions aucune limite dans une clause OVER, son cadre de fenêtre est construit sur la base de certaines valeurs limites par défaut. Elles dépendent de la syntaxe utilisée pour appeler la fonction de fenêtre. Le tableau suivant montre les limites par défaut du cadre de la fenêtre.
Syntax used	First Row in Window	Last Row in Window
Just empty OVER() clause	UNBOUNDED PRECEDING	UNBOUNDED FOLLOWING
OVER(PARTITION BY …)	UNBOUNDED PRECEDING	UNBOUNDED FOLLOWING
OVER(PARTITION BY … ORDER BY …)	UNBOUNDED PRECEDING	CURRENT ROW

Il existe un article détaillé intitulé "SQL Fonctions de fenêtrage Cheat Sheet" dans lequel vous trouverez de nombreux détails syntaxiques et exemples concernant les différentes limites du cadre de fenêtre.
La clause SQL PARTITION BY en action

Dans cette section, nous présentons quelques exemples de la clause SQL PARTITION BY. Tous sont basés sur la table paris_london_flights utilisée par une compagnie aérienne pour analyser les résultats commerciaux de cette route pour les années 2018 et 2019. Voici un sous-ensemble de ces données :

aircraft_make	aircarft_model	flight_number	scheduled_departure	real_departure	scheduled_arrival	num_of_passengers	total_revenue
Boeing	757 300	FLP003	2019-01-30 15:00:00	2019-01-30 15:00:00	2019-01-30 15:00:00	260	82630.10
Boeing	737 200	FLP003	2019-02-01 15:00:00	2019-02-01 15:10:00	2019-02-01 15:55:00	195	58459.34
Airbus	A500	FLP003	2019-02-01 15:00:00	2019-02-01 15:03:00	2019-02-01 15:03:55	312	91570.87
Airbus	A500	FLP001	2019-10-28 05:00:00	2019-10-28 05:04:00	2019-10-28 05:55:00	298	87943.00
Boeing	737 200	FLP002	2019-10-28 09:00:00	2019-10-28 09:00:00	2019-10-28 09:55:00	178	56342.45

Exemple 1

La première requête génère un rapport comprenant le site flight_number, aircraft_model avec la quantité de passagers transportés, et le revenu total. La requête est présentée ci-dessous :

```sql
SELECT DISTINCT
       flight_number,
       aircraft_model,
    SUM(num_of_passengers) 
        OVER (PARTITION BY flight_number, aircraft_model)
        AS total_passengers,
    SUM(total_revenue) 
        OVER (PARTITION BY flight_number, aircraft_model)
        AS total_revenue
FROM paris_london_flights
ORDER BY flight_number, aircraft_model;
```
Puisque le nombre total de passagers transportés et le revenu total sont générés pour chaque combinaison possible de flight_number et aircraft_model, nous utilisons la clause suivante PARTITION BY pour générer un ensemble d'enregistrements avec le même numéro de vol et le même modèle d'avion :
OVER (PARTITION BY flight_number, aircraft_model)

Ensuite, pour chaque ensemble d'enregistrements, nous appliquons les fonctions de fenêtre SUM(num_of_passengers) et SUM(total_revenue) pour obtenir les métriques total_passengers et total_revenue présentées dans l'ensemble de résultats suivant.
flight_number	aircraft_model	total_passengers	total_revenue

FLP001	737 200	20481	6016060.82
FLP001	757 300	18389	5361126.23
FLP001	Airbus A500	53872	15892165.58
FLP002	737 200	21660	6297197.71
FLP002	757 300	16869	4951475.86
FLP002	Airbus A500	54627	16004812.16
FLP003	737 200	20098	5874892.44
FLP003	757 300	15708	4573379.28
FLP003	Airbus A500	57533	16712475.04

Exemple 2

Dans la requête suivante, nous montrons l'évolution de l'activité en comparant les mesures d'un mois à celles du mois précédent. Nous créons un rapport utilisant des fonctions de fenêtre pour montrer la variation mensuelle du nombre de passagers et des recettes.

```sql
WITH year_month_data AS (
  SELECT DISTINCT
       EXTRACT(YEAR FROM scheduled_departure) AS year,
       EXTRACT(MONTH FROM scheduled_departure) AS month,
       SUM(number_of_passengers)
              OVER (PARTITION BY EXTRACT(YEAR FROM scheduled_departure),
                                  EXTRACT(MONTH FROM scheduled_departure)
                   ) AS passengers
   FROM  paris_london_flights
  ORDER BY 1, 2
)
SELECT  year,
        month,
     passengers,
     LAG(passengers) OVER (ORDER BY year, month) passengers_previous_month,
     passengers - LAG(passengers) OVER (ORDER BY year, month) AS passengers_delta
FROM year_month_data;
```
Dans la requête ci-dessus, nous utilisons une clause WITH pour générer une CTE (CTE signifie common table expressions et est un type de requête permettant de générer une table virtuelle qui peut être utilisée dans le reste de la requête). Nous introduisons des données dans une table virtuelle appelée year_month_dataqui comporte 3 colonnes : year, month, et passengers avec le total des passagers transportés au cours du mois.



Ensuite, la deuxième requête (qui prend le CTE year_month_data en entrée) génère le résultat de la requête. La colonne passagers contient le total des passagers transportés associé à l'enregistrement actuel. Avec la fonction fenêtre LAG(passenger), nous obtenons la valeur de la colonne passagers de l'enregistrement précédent à l'enregistrement courant. Nous ORDER BY year and month :
LAG(passengers) OVER (ORDER BY year, month)
passengers_previous_month

Il obtient le nombre de passagers de l'enregistrement précédent, correspondant au mois précédent. Ensuite, nous avons le nombre de passagers pour le mois en cours et le mois précédent. Enfin, dans la dernière colonne, on calcule la différence entre les deux valeurs pour obtenir la variation mensuelle des passagers.
year	month	passengers	passengers_previous_month	passengers_delta
2018	12	11469	null	null
2019	1	24723	11469	13254
2019	2	22536	24723	-2187
2019	3	24994	22536	2458
2019	4	24408	24994	-586
2019	5	23998	24408	-410
2019	6	23793	23998	-205
2019	7	24816	23793	1023
2019	8	24334	24816	-482
2019	9	23719	24334	-615
2019	10	24989	23719	1270
2019	11	24371	24989	-618
2019	12	1087	24371	-23284

Troisième exemple

Pour notre dernier exemple, intéressons-nous aux retards des vols. Nous voulons obtenir différentes moyennes de retards pour expliquer les raisons de ces retards.

Nous utilisons un CTE pour calculer une colonne appelée month_delay avec le retard moyen pour chaque mois et obtenir le modèle d'avion. Ensuite, dans la requête principale, nous obtenons les différentes moyennes comme nous le voyons ci-dessous :

```sql
WITH paris_london_delays AS (
  SELECT DISTINCT
       aircraft_model,
       EXTRACT(YEAR FROM scheduled_departure) AS year,
       EXTRACT(MONTH FROM scheduled_departure) AS month,
       AVG(real_departure - scheduled_departure) AS month_delay
   FROM  paris_london_flights
   GROUP BY 1, 2, 3
)
SELECT  DISTINCT
     aircraft_model,
     year,
     month,
     month_delay AS monthly_avg_delay,
     AVG(month_delay) OVER (PARTITION BY aircraft_model, year) AS year_avg_delay,
     AVG(month_delay) OVER (PARTITION BY year) AS year_avg_delay_all_models,
     AVG(month_delay) OVER (PARTITION BY aircraft_model, year
                               ORDER BY month
                               ROWS BETWEEN 3 PRECEDING AND CURRENT ROW
                            ) AS rolling_average_last_4_months
 
FROM paris_london_delays
ORDER BY 1,2,3
```

Cette requête calcule plusieurs moyennes. La première est la moyenne par modèle d'avion et par année, ce qui est très clair. La seconde est la moyenne par année pour tous les modèles d'avions. Notez que nous utilisons uniquement la colonne année dans la clause PARTITION BY. La troisième et dernière moyenne est la moyenne glissante, où nous utilisons les 3 mois les plus récents et le mois en cours (c'est-à-dire la ligne) pour calculer la moyenne avec l'expression suivante :

```sql
AVG(month_delay) OVER (PARTITION BY aircraft_model, year
                               ORDER BY month
                               ROWS BETWEEN 3 PRECEDING AND CURRENT ROW
                           ) AS rolling_average_last_4_months
```

La clause ROWS BETWEEN 3 PRECEDING AND CURRENT ROW du site PARTITION BY restreint le nombre de lignes (c'est-à-dire de mois) à inclure dans la moyenne : les 3 mois précédents et le mois en cours. Vous pouvez voir un résultat partiel de cette requête ci-dessous :
aircraft_model	year	month	month_delay	year_avg_delay	year_avg_delay_all_models	rolling_average_last_4_months
737 200	2018	12	00:02:13.84	00:02:13.84	00:03:13.70	00:02:13.84
737 200	2019	1	00:02:16.80	00:02:36.59	00:02:34.12	00:02:16.80
737 200	2019	2	00:02:35.00	00:02:36.59	00:02:34.12	00:02:25.90
737 200	2019	3	00:01:38.40	00:02:36.59	00:02:34.12	00:02:10.06
737 200	2019	4	00:04:00.00	00:02:36.59	00:02:34.12	00:02:37.55
737 200	2019	5	00:03:12.72	00:02:36.59	00:02:34.12	00:02:51.53
737 200	2019	6	00:02:21.42	00:02:36.59	00:02:34.12	00:02:48.13

L'article "The RANGE Clause in SQL Fonctions de fenêtrage: 5 Practical Examples" explique comment définir un sous-ensemble de lignes dans le cadre de la fenêtre en utilisant RANGE au lieu de ROWS, avec plusieurs exemples. Un autre article intéressant est "Common SQL Fonctions de fenêtrage: Using Partitions With Ranking Functions" dans lequel la clause PARTITION BY est traitée en détail.
La puissance de Fonctions de fenêtrage et de la clause SQL PARTITION BY

Les fonctions de classement sont une ressource très puissante du langage SQL, et la clause SQL PARTITION BY joue un rôle central dans leur utilisation. Dans cet article, nous avons couvert le fonctionnement de cette clause et montré plusieurs exemples utilisant différentes syntaxes.
