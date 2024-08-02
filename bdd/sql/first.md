ATTENTION REECRIRE
https://learnsql.fr/blog/fonction-sql-first-value/

Fonction SQL FIRST_VALUE

Découvrez la puissance de la fonction FIRST_VALUE, une fonction fenêtre qui renvoie la première valeur d'une partition ordonnée de l'ensemble de résultats. Cette fonction est utile à tous ceux qui effectuent des analyses de données en SQL.

Les fonctions de fenêtre sont une catégorie de fonctions puissantes qui permettent d'effectuer des analyses de données sophistiquées en SQL. Ces fonctions opèrent sur une "fenêtre" de lignes liées à la ligne actuelle, ce qui permet de préparer des rapports complexes tels que des totaux courants, des moyennes mobiles, des classements, etc. L'une des fonctions de fenêtre les plus courantes est la fonction FIRST_VALUE.

La fonction FIRST_VALUE renvoie la première valeur d'une partition ordonnée d'un ensemble de résultats. Cette fonction peut être utile dans les scénarios où vous comparez une valeur actuelle à la première valeur d'un certain ensemble :

    l'évolution du prix des actions entre le prix de la première émission et le prix actuel, ce qui donne une idée de la performance d'une action depuis ses débuts.
    l'évolution du prix d'un produit entre le prix de la première publication et le prix actuel, afin d'analyser les fluctuations de prix ou le niveau de remise par rapport au prix d'origine.
    la variation des premiers signes vitaux enregistrés (comme la tension artérielle ou le taux de glucose) d'un patient lors de sa première admission à l'hôpital, par rapport aux relevés ultérieurs.
    comparer la température actuelle à la première température enregistrée à cette date ou au cours de cette année, par exemple pour étudier les changements climatiques ou les schémas météorologiques.

La fonction FIRST_VALUE est la contrepartie double d'une autre fonction SQL window, LAST_VALUE. FIRST_VALUE renvoie la première valeur d'un ensemble de données, tandis que LAST_VALUE renvoie la dernière valeur d'un ensemble de données.

Si vous souhaitez vous familiariser avec les fonctions de fenêtre, je vous recommande notre cours interactif Fonctions de fenêtrage. Ce cours est idéal pour tous ceux qui souhaitent apprendre les fonctions de fenêtre SQL et les utiliser pour travailler plus efficacement avec les données. Le cours contient plus de 200 exercices interactifs pour vous aider à prendre confiance en vos compétences.
Comment utiliser la fonction FIRST_VALUE

La fonction FIRST_VALUE renvoie la première valeur d'une expression dans un ensemble ordonné par une autre expression. La syntaxe de FIRST_VALUE est simple :
FIRST_VALUE(expression) OVER (
    [PARTITION BY column_1, column_2, ...]
    ORDER BY expression2
    [ROWS BETWEEN range_start AND range_end]
)

La meilleure façon d'apprendre les fonctions de fenêtrage est de les mettre en pratique. Je recommande ce cours sur Fonctions de fenêtrage. Il comporte 218 exercices interactifs, ce qui équivaut à environ 20 heures de codage.

    expression - la colonne ou l'expression dont vous voulez extraire la première valeur.
    ORDER BY - définit le tri des lignes de données dans chaque partition. FIRST_VALUE l'utilise pour identifier la première ligne dont il faut extraire la valeur.
    PARTITION BY - facultatif ; divise l'ensemble des résultats en partitions auxquelles la fonction FIRST_VALUE est appliquée indépendamment. Si PARTITION BY est omis, la fonction traite l'ensemble des résultats comme une seule partition.
    ROWS BETWEEN - optional ; définit le cadre de la fenêtre, c'est-à-dire l'ensemble des lignes de chaque partition par rapport à la ligne actuelle.

Nous démontrons la fonction FIRST_VALUE à l'aide d'exemples utilisant un tableau stock_quotes. Le tableau contient les cours des actions de différentes sociétés (symboles) à différentes dates et heures. Le tableau comporte les colonnes suivantes :

    id (integer) - Un identifiant unique pour chaque enregistrement.
    symbol (text) - Le symbole de l'action.
    quote_date (timestamp) - La date et l'heure de la cotation.
    price (decimal) - Le prix de l'action à cette date.

Voici quelques exemples de lignes du tableau (avec des données fictives) :
id	symbol	quote_date	price
1	AAPL	2023-04-01 9:00	150
2	AAPL	2023-04-02 9:05	148
3	MSFT	2023-04-01 9:00	250
4	MSFT	2023-04-02 9:05	255
5	GOOGL	2023-04-01 9:00	1200
6	GOOGL	2023-04-02 9:05	1210
Exemple 1 : Utilisation simple de FIRST_VALUE - le premier cours d'une société particulière

Voici l'utilisation la plus simple de la fonction FIRST_VALUE: nous voulons trouver le premier prix enregistré pour une société particulière, comme Apple Inc. (AAPL). Nous pouvons utiliser la requête SQL suivante :
SELECT
 quote_date,
 price,
 FIRST_VALUE(price) OVER (ORDER BY quote_date) AS first_price
FROM stock_quotes
WHERE symbol = 'AAPL';

Cette requête ne sélectionne que les cours de l'action Apple Inc. (symbole AAPL). Elle sélectionne la date de cotation et le prix à cette date. Elle utilise la fonction FIRST_VALUE pour sélectionner le premier cours enregistré pour la société. Tous les cours de l'action Apple sont triés par OVER (ORDER BY quote_date). La fonction FIRST_VALUE renvoie le prix de la première ligne de ce tri, c'est-à-dire le premier prix jamais enregistré pour Apple.
Exemple 2 : FIRST_VALUE avec PARTITION BY - Premier cours pour tous les symboles

Vous utilisez généralement FIRST_VALUE avec PARTITION BY. De cette façon, la fonction FIRST_VALUE est appliquée séparément dans chaque partition définie par PARTITION BY. Supposons que vous ayez besoin de trouver le premier prix pour chaque société. Voici la requête que vous devez écrire :
SELECT
  symbol,
  quote_date,
  price,
  FIRST_VALUE(price) OVER (PARTITION BY symbol ORDER BY quote_date) AS first_price
FROM stock_quotes;

Dans cette requête, nous partitionnons les données par symbol (PARTITION BY symbol). Cela crée une partition distincte pour chaque entreprise (symbole). La fonction FIRST_VALUE est appliquée à chaque partition séparément. Comme dans l'exemple précédent, nous classons les données par date de cotation. La fonction FIRST_VALUE renvoie le prix de la première ligne de chaque partition. La requête renvoie donc le symbole, la date de cotation, le prix à cette date et le premier prix enregistré pour ce symbole.

Nous pouvons utiliser la valeur de la fonction FIRST_VALUE pour calculer le pourcentage de croissance du prix actuel par rapport au premier prix enregistré, comme suit :
SELECT
  symbol,
  quote_date,
  price,
  FIRST_VALUE(price) OVER (
    PARTITION BY symbol
    ORDER BY quote_date) AS first_price,
  100.0 * (price - FIRST_VALUE(price) OVER (
         PARTITION BY symbol
         ORDER BY quote_date))
   / FIRST_VALUE(price) OVER (
         PARTITION BY symbol
         ORDER BY quote_date) AS perc_growth
FROM stock_quotes;
Exemple 3. Première valeur de chaque jour pour chaque entreprise

Vous pouvez utiliser la fonction FIRST_VALUE pour calculer le prix d'ouverture (le premier prix du jour) pour chaque date, comme suit :
SELECT DISTINCT
  symbol,
  CAST(quote_date AS DATE) AS date,
  FIRST_VALUE(price) OVER (
    PARTITION BY symbol, CAST(quote_date AS DATE)
    ORDER BY quote_date) AS opening_price
FROM stock_quotes;

Ici, nous partitionnons les données par symbole (entreprise) et par date. Nous transformons la colonne quote_date en DATE pour extraire uniquement la valeur de la date. Comme précédemment, nous utilisons ORDER BY quote_date pour trier les valeurs par date. Nous utilisons la fonction FIRST_VALUE qui sélectionne la première ligne de chaque partition, c'est-à-dire le premier prix de chaque date pour chaque société. Nous obtenons ainsi le prix d'ouverture pour chaque jour : le premier prix enregistré à cette date. Nous utilisons également DISTINCT pour n'obtenir qu'une seule ligne pour chaque date et chaque symbole.

Pour d'autres exemples pratiques de fonctions SQL window, consultez notre article : SQL Fonctions de fenêtrage Exemples. Vous pouvez également consulter notre article 11 SQL Fonctions de fenêtrage Exercices avec solutions qui contient des exercices d'entraînement pour les fonctions de fenêtre.
FIRST_VALUE et autres Fonctions de fenêtrage

FIRST_VALUE est similaire aux autres fonctions de fenêtre.

Si vous aimez apprendre SQL à l'aide d'exercices pratiques, vous devez essayer LearnSQL.fr.
FIRST_VALUE vs LAST_VALUE

La fonction FIRST_VALUE a son équivalent double, LAST_VALUE. Comme son nom l'indique, la fonction LAST_VALUE renvoie la dernière valeur de la partition ordonnée d'un ensemble de résultats. Avec FIRST_VALUE, vous comparez la valeur actuelle au point de départ des données, tandis qu'avec LAST_VALUE, vous la comparez au point d'arrivée.

Lorsque vous utilisez la fonction LAST_VALUE, vous devez vous rappeler de définir le cadre de la fenêtre sur RANGE BETWEEN UNBOUNDED PRECEDING AND UNBOUNDED FOLLOWING pour vous assurer qu'il inclut les lignes de la ligne actuelle jusqu'à la fin de la partition. Sinon, OVER() utilise le cadre de fenêtre par défaut pour ORDER BY et LAST_VALUE renvoie la valeur de la ligne actuelle.

Pour vous souvenir de ce détail et d'autres nuances des fonctions de fenêtre SQL, nous vous recommandons notre feuille de contrôle SQL Fonctions de fenêtrage . Il s'agit d'un guide de référence rapide téléchargeable pour les fonctions de fenêtre.
MIN vs FIRST_VALUE

La fonction FIRST_VALUE peut facilement être confondue avec la fonctionMIN . La fonction MIN renvoie la plus petite valeur de l'ensemble de données. La fonction FIRST_VALUE trouve la valeur d'une expression pour la plus petite ligne sur la base de l'expression donnée dans ORDER BY.

Vous utilisez généralement la fonction FIRST_VALUE avec deux expressions différentes en tant qu'argument de la fonction FIRST_VALUE et dans ORDER BY. Cette requête, comme nous l'avons vu à plusieurs reprises dans cet article, renvoie le premier prix enregistré d'Apple, Inc.
SELECT
   quote_date,
   price, 
   FIRST_VALUE(price) OVER(ORDER BY quote_date) AS first_price
FROM stock_quotes
WHERE symbol = 'AAPL';

Si vous utilisez la colonne prix comme argument de la fonction FIRST_VALUE et dans ORDER BY, la requête renvoie également le plus petit prix d'Apple, Inc.
SELECT
   FIRST_VALUE(price) OVER(ORDER BY price) AS first_price
FROM stock_quotes
WHERE symbol = 'AAPL';

Cette requête renvoie plusieurs lignes, une pour chaque ligne contenant le cours de l'action Apple.

Cette requête renvoie le prix minimum d'Apple, Inc :
SELECT
  MIN(price)
FROM stock_quotes
WHERE symbol = 'AAPL';

La requête ne renvoie qu'une ligne avec une seule valeur : le prix minimum enregistré pour Apple.

Vous pouvez utiliser la fonction MIN comme fonction de fenêtre :
SELECT
  quote_date,
  price, 
  MIN(price) OVER(ORDER BY quote_date) AS min_price
FROM stock_quotes
WHERE symbol = 'AAPL';

Cette requête renvoie le minimum courant de la colonne price ordonné par quote_date. En d'autres termes, elle renvoie le prix le plus bas rencontré depuis le début de l'ensemble de données jusqu'à cette ligne incluse, lorsqu'elle est classée par quote_date.
FIRST_VALUE par rapport à LEAD et LAG

FIRST_VALUE est également similaire aux fonctions LEAD et LAG. LEAD et LAG renvoient la valeur des lignes suivantes ou précédentes, tandis que FIRST_VALUE renvoie la valeur de la première ligne de la partition. LEAD et LAG conviennent mieux lorsque vous devez comparer une séquence de valeurs, par exemple comparer les ventes d'un mois à l'autre. FIRST_VALUE est utilisé dans les scénarios où vous faites référence à l'entrée initiale d'un ensemble de données.

Pour une vue d'ensemble des sujets les plus importants concernant les fonctions SQL window, consultez notre article Top 10 SQL Fonctions de fenêtrage Interview Questions
Conclusion et lectures complémentaires

La fonction FIRST_VALUE est une fonction SQL window importante. Elle est utile pour analyser les tendances dans le temps, par exemple pour voir comment les prix des actions ou les chiffres de vente évoluent sur une période donnée. Apprendre à utiliser FIRST_VALUE peut améliorer votre capacité à analyser des séries de données temporelles.

Si vous souhaitez améliorer votre utilisation des fonctions SQL window, nous vous recommandons notre cours interactif Fonctions de fenêtrage. Il contient 218 exercices pratiques pour vous aider à apprendre les fonctions de fenêtre par la pratique. Si vous connaissez déjà les fonctions de fenêtre et que vous souhaitez vous entraîner davantage, consultez notre kit de pratique Fonctions de fenêtrage qui contient 100 exercices pour vous aider à pratiquer les fonctions de fenêtre sur des scénarios du monde réel.

LearnSQL.fr est une plateforme en ligne conçue pour vous aider à maîtriser SQL. LearnSQL.fr vous permet de choisir entre un programme d'apprentissage complet, des mini-programmes pour affiner des compétences ciblées et des cours individuels. Vous pouvez également sélectionner le dialecte SQL (Standard SQL, Microsoft SQL Server ou PostgreSQL) qui correspond le mieux à vos besoins.

Pour un guide rapide sur les fonctions de fenêtre SQL, consultez l'aide-mémoire SQL Fonctions de fenêtrage . Il s'agit d'un guide de référence rapide pour les fonctions de fenêtre qui est disponible en ligne et peut être téléchargé au format PDF.

Tous nos cours, y compris Fonctions de fenêtrage et Fonctions de fenêtrage Practice Set, sont disponibles seuls ou dans le cadre de notre Tout à vie SQL Package. Ce package vous donne un accès à vie à tous les cours SQL actuels et futurs sur notre plateforme avec un paiement unique. Que vous soyez débutant ou que vous souhaitiez améliorer vos compétences en SQL, ce package vous accompagne à chaque étape de votre parcours d'apprentissage. Inscrivez-vous dès aujourd'hui pour améliorer en permanence votre expertise SQL.
