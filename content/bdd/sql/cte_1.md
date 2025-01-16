ATTENTION REECRIRE
https://learnsql.fr/blog/11-exercices-d-expression-de-table-commune-sql/

11 Exercices d'expression de table commune SQL

Dans cet article, nous vous proposons 11 exercices d'entraînement qui vous permettront de mettre en pratique vos connaissances des expressions de tableaux communs (ETC). Chaque exercice CTE est accompagné d'une solution et d'une explication détaillée.

Comme le dit le proverbe, "un petit progrès chaque jour donne de grands résultats". Et c'est sans doute vrai pour la maîtrise de SQL. De la même manière qu'il faut aller régulièrement à la salle de sport pour garder ses muscles toniques, il faut faire souvent des exercices d'expressions de tables communes pour garder ses compétences en matière d'interrogation toniques pour des travaux d'analyse de données lourds.

Les CTE, ou expressions de table commune, sont des instructions puissantes du langage SQL. Elles vous permettent de définir temporairement une sous-requête dans une requête SQL et de lui attribuer un nom. Cela signifie que l'ETC peut être référencée par son nom dans la requête, comme s'il s'agissait d'une table.

La valeur des ETC

Outre les noms, il existe d'autres différences importantes entre les ETC et les sous-requêtes. Les ETC sont pratiques pour structurer des requêtes complexes, ce qui facilite leur lecture, leur compréhension et leur débogage. Les ETC peuvent également être utilisés à plusieurs reprises dans la même requête, ce qui la rend plus concise. Ces qualités des ETC les rendent idéaux pour les travaux d'analyse de données, car il est courant que les requêtes d'analyse de données mélangent des SELECT de données simples et des SELECT groupés avec des totaux, des moyennes et d'autres fonctions d'agrégation. Sans les ETC, les requêtes complexes pourraient devenir pratiquement impossibles à lire ou nécessiter la création de tables ou de vues temporaires qui peuplent inutilement la base de données avec de nombreux objets.

LearnSQL.fr est une plateforme en ligne conçue pour vous aider à maîtriser SQL. LearnSQL.fr vous permet de choisir entre un programme d'apprentissage complet, des mini-programmes pour affiner des compétences ciblées et des cours individuels. Vous pouvez également sélectionner le dialecte SQL (Standard SQL, Microsoft SQL Server ou PostgreSQL) qui correspond le mieux à vos besoins.

Les ETC sont également très utiles pour effectuer des analyses de données très complexes sans avoir recours à d'autres langages de programmation. L'utilisation de la récursivité pour trouver des chemins critiques ou pour parcourir des types de données abstraits (tels que les arbres et les graphes) sont des exemples qui démontrent l'utilité des ETC. Il en va de même pour la possibilité de créer des requêtes imbriquées, qui réduisent progressivement la complexité d'un problème jusqu'à ce qu'il devienne un simple SELECT.

La capacité des ETC à rendre les requêtes plus lisibles et plus concises est quelque chose que vous apprécierez si vous devez revoir une longue requête des années après l'avoir écrite. Heureusement, la plupart des systèmes modernes de gestion de bases de données relationnelles (SGBDR) - y compris PostgreSQL, MySQL, SQL Server et Oracle - autorisent l'utilisation des ETC.

Tous les exercices compilés dans cet article sont tirés de notre cours. Requêtes récursives cours. Il s'agit d'un tutoriel approfondi sur les expressions de tables communes dans l'analyse des données. Les 114 exercices interactifs couvrent les CTE simples, les CTE imbriqués et les CTE récursifs dans un temps total estimé à 18 heures. Vous pouvez également en apprendre davantage sur les ETC en lisant Les ETC expliqués à l'aide d'exemples.

Un autre sujet important que tout analyste de données devrait maîtriser est celui des fonctions SQL window. Vous pouvez consulter cet ensemble d'exercices pratiques sur les fonctions SQL window pour mettre vos compétences à l'épreuve.

Commençons maintenant nos exercices sur les expressions de tables communes. Nous commencerons par les CTE simples, puis nous passerons aux CTE imbriquées et récursives.

Exercices sur les ETC simples

Pour ces exercices d'ETC, nous utiliserons une base de données conçue pour gérer des projets de crowdfunding. Ce schéma est composé de trois tables :

    supporter contient des informations sur les supporters, qui sont ceux qui donnent de l'argent pour les projets.
    project contient des informations sur les projets qui reçoivent des dons de la part des supporters.
    donation enregistre les dons des supporters aux projets.

Le tableau supporter stocke les adresses id, first_name et last_name de chaque sympathisant dans le système. Voyons quelques-unes de ses lignes :
id	first_name	last_name
1	Marlene	Wagner
2	Lonnie	Goodwin
3	Sophie	Peters
4	Edwin	Paul
5	Hugh	Thornton

Le tableau project stocke id, category, author_id, et minimal_amount nécessaires au démarrage de chaque projet. Voici quelques-unes de ses lignes :
id	category	author_id	minimal_amount
1	music	1	1677
2	music	5	21573
3	traveling	2	4952
4	traveling	5	3135
5	traveling	2	8555

Les données de la colonne author_id relient chaque projet de la table à une ligne de la base de données des projets. project à une ligne du tableau supporter tableau. Chaque supporter lié à un projet par la colonne author_id est l'auteur de ce projet.

Enfin, le tableau donation contient id, supporter_id, le montant du don, et la colonne donated, qui indique la date à laquelle chaque don a été effectué.
id	project_id	supporter_id	amount	donated
1	4	4	928.40	2016-09-07
2	8	18	384.38	2016-12-16
3	6	12	367.21	2016-01-21
4	2	19	108.62	2016-12-29
5	10	20	842.58	2016-11-30
Exercice 1 : Utilisation d'un CTE pour obtenir des données totalisées

Exercice : Obtenir l'ID du projet, le montant minimal et le total des dons pour les projets qui ont reçu des dons supérieurs au montant minimal.

Solution :
WITH project_revenue AS (
  SELECT
    project_id,
    SUM(amount) AS sum_amount
  FROM donation
  GROUP BY project_id
)
SELECT project.id, minimal_amount, sum_amount
FROM project_revenue
INNER JOIN project ON
project.id = project_revenue.project_id
WHERE sum_amount >= minimal_amount;

Explication : Pour résoudre cet exercice, nous utilisons un CTE appelé project_revenue qui totalise les dons de chaque projet. Cet ETC a deux colonnes : id et sum_amount, cette dernière étant la somme calculée des dons pour chaque project_id. Après la définition de l'ETC, nous utilisons une instruction SELECT qui joint la table avec l'ETC. project avec l'ETC. Pour chaque projet ayant reçu des dons, l'ETC renvoie les informations suivantes : id, minimal_amount, et le total des dons (sum_amount) qu'il a reçus.

L'ETC project_revenue n'inclut que les lignes des projets qui ont reçu des dons, car il obtient les données de la table des dons. Le site SELECT situé sous la définition de l'ETC n'affiche également que les projets qui ont reçu des dons en raison du lien INNER JOIN entre l'ETC et la table project table. Enfin, la condition WHERE garantit que nous n'obtiendrons que les projets pour lesquels le montant des dons dépasse le montant minimum.

Si vous avez besoin de vous entraîner à grouper des données en SQL, consultez cette série de 10 exercices GROUP BY. Essayez ces exercices d'entraînement SQL avancés pour accélérer votre progression vers la maîtrise du langage SQL.

Exercice 2 : Utilisation de plusieurs CTE dans la même instruction

Exercice : Sélectionner les donateurs qui ont donné plus de 200 $ au total ou qui ont donné au moins deux fois.

Solution :
WITH rich AS (
  SELECT
    s.id,
    first_name,
    last_name
  FROM supporter s
  JOIN donation d
    ON d.supporter_id = s.id
  GROUP BY s.id, first_name, last_name
  HAVING SUM(amount) > 200
),
frequent AS (
  SELECT
    s.id,
    first_name,
    last_name
  FROM supporter s
  JOIN donation d
    ON d.supporter_id = s.id
  GROUP BY s.id, first_name, last_name
  HAVING COUNT(d.id) > 1
)
SELECT
  id,
  first_name,
  last_name
FROM rich
UNION ALL
SELECT
  id,
  first_name,
  last_name
FROM frequent;

Explication : Cet exercice nous demande de combiner deux résultats différents que nous devons obtenir en récupérant des informations dans les champs donation et supporter soit les donateurs dont le total des dons dépasse 200 $ et les donateurs qui ont fait plus d'un don. Cette situation est idéale pour être résolue en écrivant deux CTE, l'un pour obtenir le premier ensemble de données (rich) et l'autre pour obtenir le second ensemble (frequent).

La syntaxe SQL permet d'écrire plusieurs ETC dans la même commande, ce dont nous avons profité pour résoudre cet exercice. En plaçant chaque sous-requête dans un ETC différent, le site SELECT final est simplement l'union de deux SELECTsimples - chacun d'entre eux récupérant les données directement à partir d'un ETC.
ETC imbriqués

Bien qu'aucun SGBDR ne permette la création d'un ETC à l'intérieur d'un autre ETC, ils autorisent les ETC imbriqués, c'est-à-dire lorsqu'un ETC fait référence à un ETC précédemment défini comme s'il s'agissait d'une table. De cette manière, les ETC créent différents niveaux d'abstraction. La requête finale est ainsi simple et concise : SELECT.

Pour nos exercices sur les ETC imbriqués, nous utiliserons le schéma de table d'une société de vente au porte-à-porte. Ce schéma comporte trois tables : salesman, daily_sales, et city. La table salesman comprend les données id, first_name, last_name, et city_id pour chaque vendeur. Voici quelques-unes de ses lignes :
id	first_name	last_name	city_id
1	Frederick	Webster	1
2	Casey	Santiago	2
3	Cindy	Fields	3
4	Timothy	Pratt	4
5	Susan	Rose	5

Le tableau daily_sales représente les ventes totalisées par jour et par vendeur. Il comporte les colonnes day, salesman_id, items_sold, amount_earned, distance, et customers. Les deux dernières colonnes indiquent la distance parcourue et le nombre de clients servis par chaque vendeur chaque jour. Il s'agit de quelques-unes de ses lignes :
day	salesman_id	items_sold	amount_earned	distance	customers
2017-01-15	1	0	1673.20	302	0
2017-01-15	2	16	2288.49	136	13
2017-01-15	3	17	1232.78	129	14
2017-01-15	4	2	1496.88	251	2
2017-01-15	5	22	1384.13	340	18

Enfin, nous avons le tableau city qui contient les adresses id, name, country et region de chaque ville :
id	name	country	region
1	Chicago	USA	Americas
2	New York	USA	Americas
3	Mexico City	Mexico	Americas
4	Rio de Janeiro	Brasil	Americas
5	Paris	France	Europe
Exercice 3 : Utilisation d'ETC imbriquées pour progresser vers un résultat

Exercice : Obtenir la date, l'identifiant de la ville, le nom de la ville et le montant total de toutes les ventes quotidiennes - groupées par date et par ville - qui dépassent les ventes quotidiennes moyennes pour toutes les villes et tous les jours.

Solution :
WITH earnings_per_day_city AS (
  SELECT
    ds.day,
    c.id,
    c.name,
    SUM(amount_earned) AS total_earnings
  FROM salesman s
  JOIN daily_sales ds
    ON s.id = ds.salesman_id
  JOIN city c
    ON s.city_id = c.id
  GROUP BY ds.day, c.id, c.name
),
overall_day_city_avg AS (
  SELECT
    AVG(total_earnings) AS avg_earnings
  FROM earnings_per_day_city
)
SELECT
  day,
  id,
  name,
  total_earnings
FROM earnings_per_day_city, overall_day_city_avg
WHERE total_earnings > avg_earnings;

Explication : Les CTE imbriqués nous permettent de diviser un problème en plusieurs parties et de nous approcher progressivement de la solution. Dans cet exercice, nous devons d'abord totaliser les ventes par jour et par ville. C'est ce que nous faisons avec le premier ETC, earnings_per_day_city.

Ensuite, nous devons obtenir une moyenne de toutes les ventes totalisées par jour et par ville. Nous y parvenons avec l'ETC overall_day_city_avg, qui utilise à son tour les résultats précédemment totalisés par l'ETC earnings_per_day_city. Ce deuxième ETC renvoie une seule ligne contenant la moyenne des ventes pour tous les jours et toutes les villes.

Dans la version finale de SELECT, nous reprenons simplement les données des deux CTE (il n'est pas nécessaire de les combiner avec JOIN, puisque earnings_per_day_city renvoie une seule ligne) et nous ajoutons la condition WHERE selon laquelle le total des ventes du jour et de la ville doit être supérieur à la moyenne globale.
Exercice 4 : Combinaison de requêtes et de sous-requêtes imbriquées

Exercice : Obtenez la date à laquelle le nombre moyen de clients servis par région était le plus bas de tous, en affichant cette moyenne avec la date.

Solution :
WITH sum_region AS (
  SELECT
    day,
    region,
    SUM(customers) AS sum_customers
  FROM salesman s
  JOIN daily_sales ds
    ON s.id = ds.salesman_id
  JOIN city c
    ON s.city_id = c.id
  GROUP BY day, region
),
avg_region AS (
  SELECT
    day,
    AVG(sum_customers) AS avg_region_customers
  FROM sum_region
  GROUP BY day
)
SELECT
  day,
  avg_region_customers
FROM avg_region
WHERE avg_region_customers = (SELECT
  MIN(avg_region_customers)
  FROM avg_region);

Explication : Pour résoudre cette requête, nous utilisons la même approche successive de la solution que dans l'exercice précédent, en créant d'abord un CTE pour obtenir le nombre total de clients servis par jour et par région, puis un autre CTE basé sur le précédent pour obtenir les moyennes quotidiennes des clients servis par jour. Ensuite, dans la version finale de SELECT, nous utilisons une sous-requête pour obtenir le minimum du nombre moyen de clients par jour et l'utiliser dans la clause WHERE comme valeur de comparaison, de sorte que la requête renvoie le jour qui correspond à ce minimum.

Vous souhaitez apprendre les requêtes récursives SQL ? Consultez notre cours interactif.

Si vous souhaitez décomposer davantage le résultat final SELECT, vous pouvez ajouter un troisième CTE au lieu d'une sous-requête. De cette manière, la version finale de SELECT est encore plus simple. Voici le nouvel (troisième) ETC et la requête extérieure SELECT:
min_avg_region as (
  SELECT
    MIN(avg_region_customers) as min_avg_region_customers
  FROM avg_region
  )
SELECT
  day,
  avg_region_customers
FROM avg_region, min_avg_region
WHERE avg_region_customers = min_avg_region_customers;
Exercice 5 : Utilisation d'ETC imbriqués pour calculer des statistiques complexes

Exercice : Pour chaque ville, calculez la distance totale moyenne parcourue par chaque vendeur. Calculez également une moyenne globale de toutes les moyennes des villes.

Solution :
WITH distance_salesman_city AS (
  SELECT
    city_id,
    salesman_id,
    SUM(distance) AS sum_distance
  FROM daily_sales d
  JOIN salesman s
    ON d.salesman_id = s.id
  GROUP BY city_id, salesman_id
),
city_average AS (
  SELECT
    city_id,
    AVG(sum_distance) AS city_avg
  FROM distance_salesman_city
  GROUP BY city_id
)
SELECT AVG(city_avg)
FROM city_average;

Explication : Les avantages des CTE imbriqués sont perceptibles lorsque vous devez effectuer des calculs statistiques composés de plusieurs étapes successives.

Dans ce cas, le résultat final est une moyenne totale des moyennes par ville des sommes des distances pour chaque ville et chaque vendeur. Il s'agit donc d'une moyenne de moyennes de sommes. Les ETC nous permettent d'effectuer une approximation progressive du résultat, de manière analogue à ce que ferait un scientifique des données avec des formules statistiques.
Exercice 6 : Utilisation d'ETC imbriqués pour comparer des ensembles d'éléments

Exercice : Comparez les ventes moyennes de tous les vendeurs aux États-Unis avec les ventes moyennes de tous les vendeurs dans le reste du monde.

Solution :
WITH cities_categorized AS (
  SELECT
    id AS city_id,
    CASE WHEN country = 'USA' THEN country ELSE 'Rest of the World' END AS category
  FROM city
),
sales_category AS (
  SELECT
    category,
    salesman_id,
    SUM(items_sold) total_sales
  FROM daily_sales ds
  JOIN salesman s
    ON s.id = ds.salesman_id
  JOIN cities_categorized
    ON cities_categorized.city_id = s.city_id
  GROUP BY category, salesman_id
)
 
SELECT
  category,
  AVG(total_sales)
FROM sales_category
GROUP BY category;

Explication : Dans le premier ETC (cities_categorized), nous avons séparé les villes en deux groupes : les villes des États-Unis et les villes du reste du monde.

Dans la deuxième ETC, nous combinons les informations de l'ETC cities_categorized avec celles de daily_sales et du vendeur pour obtenir des totaux de ventes groupés par les deux catégories de villes et par vendeur.

Dans l'ETC final SELECT, nous regroupons simplement par catégorie de villes et obtenons les ventes moyennes pour chacune des deux catégories (villes des États-Unis et villes du reste du monde).
CTE récursifs

Dans la programmation SQL, les CTE récursives sont des expressions de table commune qui se référencent elles-mêmes. Comme les fonctions récursives utilisées dans d'autres langages de programmation, les CTE récursives reposent sur le principe suivant : on prend les données résultant d'une exécution précédente, on les ajoute ou on les modifie, et on transmet les résultats à l'exécution suivante. On continue à faire de même jusqu'à ce qu'une condition d'arrêt soit remplie, c'est-à-dire jusqu'à ce que le résultat final soit obtenu.

Les ETC récursifs doivent comporter le mot RECURSIVE après le mot WITH. La meilleure façon de comprendre le fonctionnement des ETC récursifs est d'utiliser un exemple simple, comme dans l'exercice suivant.
Exercice 7 : utilisation d'ETC récursifs pour générer des séquences

Exercice : Utilisez la récursivité pour énumérer tous les nombres entiers de 1 à 10.

Solution :
WITH RECURSIVE ten_numbers(prev_number) AS (
  SELECT 1
  UNION ALL
  SELECT ten_numbers.prev_number + 1
  FROM ten_numbers
  WHERE prev_number < 10
)
 
SELECT *
FROM ten_numbers;

Explication : Cette requête adopte la notation CTEs récursive de PostgreSQL, qui comporte quatre parties :

    Membre d'ancrage : C'est ici que nous définissons le point de départ de la récursion. Cette partie de la requête doit pouvoir être résolue de manière autonome, sans qu'il soit nécessaire d'utiliser les résultats des itérations précédentes de la même ETC.
    Membre récursif : Cette partie est répétée autant de fois que nécessaire, en utilisant les résultats de l'itération précédente comme base.
    Condition de fin : Cette condition est évaluée après chaque répétition du membre récursif ; lorsqu'elle est remplie, la boucle récursive se termine. Si cette condition n'était pas présente ou si elle donnait toujours un résultat vrai, la boucle récursive se poursuivrait indéfiniment.
    Invocation : La principale différence entre cette requête SELECT et les autres requêtes principales CTE est que SELECT sert de déclencheur au cycle d'exécutions récursives.

Dans cet exercice, le membre d'ancrage renvoie simplement une ligne avec le numéro 1. Le membre récursif prend la ou les lignes de l'exécution précédente et ajoute (via la clause UNION) une nouvelle ligne avec la valeur précédente incrémentée de 1. La condition de terminaison stipule que la requête continuera à itérer jusqu'à ce que la valeur obtenue soit égale à 10.
Exercice 8 : Utiliser un ETC récursif pour parcourir une structure de données hiérarchique (arbre)

Pour cet exercice, nous utiliserons la table employee qui possède les colonnes id, first_name, last_name, et superior_id. Ses lignes contiennent les données suivantes :
id	first_name	last_name	superior_id
1	Madeline	Ray	null
2	Violet	Green	1
3	Alton	Vasquez	1
4	Geoffrey	Delgado	1
5	Allen	Garcia	2
6	Marian	Daniels	2
 

Exercice : Affichez toutes les données relatives à chaque employé, ainsi qu'un texte indiquant le chemin qui, dans la hiérarchie de l'organisation, sépare chaque employé de son supérieur hiérarchique (identifié par la valeur littérale "Patron").

Solution :
WITH RECURSIVE hierarchy AS (
  SELECT
    id,
    first_name,
    last_name,
    superior_id,
    'Boss' AS path
  FROM employee
  WHERE superior_id IS NULL
  UNION ALL
  SELECT
    employee.id,
    employee.first_name,
    employee.last_name,
    employee.superior_id,
    hierarchy.path || '->' || employee.last_name
  FROM employee JOIN hierarchy
  ON employee.superior_id = hierarchy.id
)
 
SELECT *
FROM hierarchy;

Explication : Les données du tableau employee représentent une structure hiérarchique ou arborescente, où chaque ligne possède une colonne qui la relie à son supérieur (une autre ligne dans le même tableau). La ligne correspondant au chef d'entreprise (le nœud racine de l'arbre) est celle dont la colonne superior_id contient une valeur nulle. Il s'agit donc de notre membre d'ancrage pour construire cet ETC récursif. Le chemin de ce membre d'ancrage porte simplement la valeur littérale "Boss".

Ensuite, le membre de la requête récursive joint l'itération précédente de la hiérarchie avec employeeen posant la condition que les patrons des employés de l'itération actuelle (superior_id) sont déjà dans la hiérarchie. Cela signifie qu'à chaque itération, nous ajoutons une nouvelle couche à la hiérarchie. Cette couche est formée par les subordonnés des employés qui ont été ajoutés à l'itération précédente. La condition de jonction est donc employee.superior_id = hierarchy.id.

Si vous aimez apprendre SQL à l'aide d'exercices pratiques, vous devez essayer LearnSQL.fr.

Le chemin de chaque employé est assemblé en concaténant le chemin de leur patron (hierarchy.path, qui va jusqu'à 'Boss') avec le nom de famille de l'employé de l'itération courante, joint par une chaîne représentant une flèche (hierarchy.path || '->' || employee.last_name).
Exercice 9 : Montrer le chemin d'un arbre à partir du nœud racine

Exercice : Affichez une liste contenant le nom et le prénom de chaque employé (y compris le grand patron), ainsi qu'un texte (le champ path) montrant le chemin de l'arbre entre chaque employé et le grand patron. Dans le cas du grand patron, la colonne chemin doit indiquer le site last_name du patron.

Solution :
WITH RECURSIVE hierarchy AS (
  SELECT
    first_name,
    last_name,
    CAST(last_name AS text) AS path
  FROM employee
  WHERE superior_id IS NULL
  UNION ALL
  SELECT
    employee.first_name,
    employee.last_name,
    hierarchy.path || '->' || employee.last_name AS path
  FROM employee, hierarchy
  WHERE employee.superior_id = hierarchy.id
)
 
SELECT *
FROM hierarchy;

Explication : La solution de cet exercice est très similaire à celle de l'exercice précédent, à la seule exception que la valeur du chemin pour le nœud racine n'est pas une valeur littérale de type TEXTE ; c'est une valeur last_name dans la table employee dans la table. Cela nous oblige à effectuer une conversion de données pour éviter d'obtenir une erreur lors de l'exécution de cette requête.

Puisque l'ETC effectue une UNION entre les données renvoyées par le composant d'ancrage et les données renvoyées par le composant récursif, il est impératif que les deux ensembles de résultats aient le même nombre de colonnes et que les types de données des colonnes correspondent.

La colonne last_name de la table employee (appelée chemin dans le membre d'ancrage CTE) est de type VARCHAR, tandis que la concaténation hierarchy.path || '->' || employee.last_name (appelée chemin dans le membre récursif) produit automatiquement une colonne TEXT. Pour que UNION ne provoque pas d'erreur d'incompatibilité de type, il est nécessaire d'inclure CAST(last_name AS text) dans le membre d'ancrage. De cette façon, les colonnes path des deux parties de l'ETC seront TEXT.
Exercice 10 : utilisation de plusieurs colonnes récursives

Exercice : Dressez la liste de toutes les données relatives à chaque employé, ainsi que le chemin parcouru dans la hiérarchie jusqu'à ce que l'on atteigne le supérieur hiérarchique, en incluant une colonne appelée distance qui indique le nombre de personnes dans la hiérarchie depuis le supérieur hiérarchique jusqu'à l'employé. Pour le grand patron, la distance est de 0 ; pour ses subordonnés, elle est de 1 ; pour les subordonnés de ses subordonnés, elle est de 2, et ainsi de suite.

Solution :
WITH RECURSIVE hierarchy AS (
  SELECT
    id,
    first_name,
    last_name,
    superior_id,
    'Boss' AS path,
    0 AS distance
  FROM employee
  WHERE superior_id IS NULL
  UNION ALL
  SELECT
    employee.id,
    employee.first_name,
    employee.last_name,
    employee.superior_id,
    hierarchy.path || '->' || employee.last_name,
    hierarchy.distance + 1
 FROM employee, hierarchy
 WHERE employee.superior_id = hierarchy.id
)
SELECT *
FROM hierarchy;

Explication : Comme il y a deux colonnes récursives dans l'ETC, il est nécessaire d'indiquer une valeur initiale pour chacune d'entre elles dans le membre d'ancrage. Dans ce cas, la colonne chemin a la valeur initiale "Boss" (comme dans l'exercice 8) et la colonne distance a la valeur 0. Ensuite, dans le membre récursif, la valeur de la distance résulte de l'ajout de 1 à la distance de l'itération précédente.
Exercice 11 : Utilisation d'ETC récursifs pour parcourir des structures de données de type réseau

Pour cet exercice, nous utilisons deux tables : une table destination (composée des colonnes id et name) et une table ticket (composée des colonnes city_from, city_to, et cost ). Le tableau destination contient les identifiants et les noms d'un groupe de villes, tandis que le tableau indique le coût des billets entre les villes. ticket tableau indique le coût des billets entre les paires de villes du tableau (lorsque de telles connexions existent). destination (lorsque de telles connexions existent).

Voici un exemple de données provenant des deux tableaux (d'abord destinationpuis ticket) :
id	name
1	Warsaw
2	Berlin
3	Bucharest
4	Prague
city_from	city_to	cost
1	2	350
1	3	80
1	4	220
2	3	410
2	4	230
3	2	160
3	4	110
4	2	140
4	3	75

Exercice : Trouvez l'itinéraire le moins cher pour voyager entre toutes les villes du tableau, en partant de Varsovie. destination en partant de Varsovie. La requête doit contenir les colonnes suivantes :

    path - Les noms des villes sur le chemin, séparés par '->'.
    last_id - L'identifiant de la ville finale de ce voyage.
    total_cost - La somme des coûts des billets.
    count_places - Le nombre de villes visitées. Ce nombre doit être égal au nombre total de villes en destinationsoit 4.

Solution :
WITH RECURSIVE travel(path, last_id,
    total_cost, count_places) AS (
  SELECT
    CAST(name as text),
    Id,
    0,
    1
  FROM destination
  WHERE name = 'Warsaw'
  UNION ALL
  SELECT
    travel.path || '->' || c2.name,
    c2.id,
    travel.total_cost + t.cost,
    travel.count_places + 1
  FROM travel
  JOIN ticket t
    ON travel.last_id = t.city_from
  JOIN destination c1
    ON c1.id = t.city_from
  JOIN destination c2
    ON c2.id = t.city_to
  WHERE position(c2.name IN travel.path) = 0
)
SELECT *
FROM travel
WHERE count_places = 4
ORDER BY total_cost ASC;

Explication : La méthode de résolution de cet exercice est similaire à celle de l'exercice précédent. Dans ce cas, cependant, il n'y a pas d'ordre direct dans la relation entre les éléments d'un même tableau. Au lieu de cela, les relations entre les éléments du destination sont exprimées dans le tableau ticket en reliant chaque paire de villes connectées.

La première ligne des résultats de la requête ci-dessus indique l'itinéraire le moins coûteux. Cela est possible parce que la partie extérieure SELECT de la requête trie les résultats dans l'ordre croissant par total_cost. À son tour, le membre externe SELECT s'assure que le nombre de villes parcourues est de 4 en posant la condition que count_places soit égal à 4.

LearnSQL.fr est une plateforme en ligne conçue pour vous aider à maîtriser SQL. LearnSQL.fr vous permet de choisir entre un programme d'apprentissage complet, des mini-programmes pour affiner des compétences ciblées et des cours individuels. Vous pouvez également sélectionner le dialecte SQL (Standard SQL, Microsoft SQL Server ou PostgreSQL) qui correspond le mieux à vos besoins.

Le membre récursif s'assure que chaque itération ajoute une nouvelle ville à l'itinéraire en posant la condition que le nom de la ville ne figure pas déjà dans le chemin (position(c2.name IN travel.path) = 0).

Le point de départ du voyage étant la ville de Varsovie, le membre d'ancrage de l'ETC récursif est la ligne de la table destination dont le nom est égal à "Varsovie". Notez que nous convertissons la colonne nom en type de données TEXT (comme dans l'exercice 9) afin que le type de données corresponde à la colonne correspondante dans le membre de l'ETC récursif.
Besoin d'autres exercices sur les expressions de tableau communes ?

Si vous avez travaillé sur les exercices SQL de cet article, vous savez maintenant comment utiliser les expressions de table communes. Et vous savez à quel point les CTE peuvent être utiles. Ces exercices proviennent de notre cours Requêtes récursives et il y a encore plus d'exercices comme ceux-ci dans le cours complet.

Pour devenir vraiment bon en analyse de données avec SQL, pensez à joindre LearnSQL.fr. Nous vous recommandons de jeter un coup d'œil au package SQL deTout à vie . Il vous donne un accès à vie à tous les cours SQL que nous proposons actuellement, ainsi qu'à tous les nouveaux cours que nous ajouterons ultérieurement. Ainsi, vous pouvez continuer à acquérir de nouvelles compétences pour toujours. Rejoignez LearnSQL.fr dès aujourd'hui et commencez à vous construire un bel avenir dans le domaine de l'analyse des données !
