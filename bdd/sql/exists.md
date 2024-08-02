ATTENTION REECRIRE
https://learnsql.fr/blog/l-operateur-sql-exists/   

L'utilisation de la clause SQL EXISTS permet de créer des requêtes complexes de manière simple. Découvrez les avantages et les inconvénients de l'opérateur EXISTS dans cet article.

En SQL, l'opérateur EXISTS nous aide à créer des conditions logiques dans nos requêtes. Essentiellement, il vérifie s'il y a des lignes dans une sous-requête. Nous vous montrerons la syntaxe de EXISTS, nous vous donnerons quelques exemples d'utilisation et nous vous proposerons plusieurs exercices pour vous entraîner.

Si vous débutez avec SQL ou si vous avez besoin d'une remise à niveau en SQL, je vous recommande le cours SQL pour les débutants. Il comprend des sujets SQL allant des SELECT de base aux sujets complexes tels que les jointures, les agrégations et les sous-requêtes. C'est un excellent moyen d'acquérir, de rafraîchir ou d'élargir vos compétences en SQL.

Syntaxe de l'opérateur EXISTS

Vous connaissez probablement les opérateurs SQL tels que =, >, < et LIKE. Tous ces opérateurs peuvent être utilisés pour créer des conditions logiques qui renvoient TRUE ou FALSE. Voici quelques exemples de conditions courantes :
WHERE Employee_id = 10345
WHERE Price < 1000
WHERE Name LIKE ‘John%’

Les opérateurs =, <, et LIKE comparent deux éléments ou opérandes. C'est la raison pour laquelle ils sont appelés opérateurs binaires.
WHERE EXISTS ( subquery )

Voyons maintenant l'ensemble de la requête SQL pour déterminer où placer la condition EXISTS:
SELECT columns
FROM table1
WHERE EXISTS (SELECT columns FROM table2);

L'opérateur EXISTS est utilisé pour créer des conditions booléennes afin de vérifier si une sous-requête renvoie une ou plusieurs lignes ou un ensemble vide. Lorsque sa sous-requête renvoie au moins une ligne, EXISTS renvoie TRUE. Le nombre de lignes renvoyées ou le nombre de colonnes dans la liste de la sous-requête SELECT n'a pas d'importance. Ce n'est que lorsque la sous-requête renvoie 0 ligne que EXISTS renvoie FALSE. Il est important de noter qu'aucune des lignes renvoyées par la sous-requête n'apparaît dans le résultat final.
Exemple de base de données : Bateaux et voitures de luxe

Examinons plusieurs exemples de requêtes basées sur la base de données d'une entreprise qui vend des voitures et des bateaux de luxe. L'entreprise garde une trace des voitures et des bateaux dans la table product, qui comporte les colonnes product_id, product_name, product_price, product_type.
product_id	product_name	product_price	product_type
100	Ferrari F20	3000000	Car
101	Lamborghini AX	3600000	Car
102	Pagani Zonda	4300000	Car
200	VanDutch 58	2100000	Boat
201	Lamborghini B9	3400000	Boat
202	VanDutch 56	1800000	Boat
300	Boat Engine Yamei 100	1000000	Boat

La base de données comporte également une table Client avec les colonnes client_id, client_name et country.
client_id	client_name	country
10	John F.	United States
11	Samid A,	Kuwait
12	Majal H.	Brunei
13	Pierre B.	France
14	Abdul E.	Kuwait

Enfin, il y a la table sale avec les colonnes product_id, client_id, sale_date. (Par souci de simplicité, j'omets l'idée d'avoir une table pour les bons de commande ; dans ce type d'entreprise, un client n'achète normalement qu'un seul produit à la fois).
client_id	product_id	country
10	200	2020-03-05
10	101	2024-04-05
11	202	2023-03-05
12	102	2021-03-07
12	100	2023-03-05
12	202	2024-04-09
13	300	2022-03-05
10	300	2020-07-19
13	300	2023-11-25
Exemples d'utilisation de l'opérateur SQL EXISTS
Exemple 1 : Recherche des produits vendus

Pour le premier exemple de requête, supposons que le responsable du marketing veuille savoir quelles voitures et quels bateaux ont été vendus entre le 1er et le 15 avril 2024. C'est ce que fait la requête ci-dessous :
SELECT product_name
FROM product p1
WHERE EXISTS ( SELECT * FROM sale s
               WHERE  s.product_id = p1.product_id
               AND    s.sale_date >= ‘2024-04-01’
               AND    s.sale_date <= ‘2024-04-15’
             )

Résultats :
Product_name
Lamborghini AX
VanDutch 56

Il existe d'autres façons d'écrire cette requête sans utiliser l'opérateur EXISTS. Cependant, pour expliquer le fonctionnement de l'opérateur EXISTS, il s'agit d'un bon exemple d'entrée en matière.

La requête principale SELECT est très simple ; elle va à la table product pour obtenir la colonne product_name. Cependant, nous ne voulons pas tous les product_names dans la table. Nous ne voulons que les produits qui renvoient TRUE pour la condition suivante :
WHERE EXISTS ( SELECT * FROM sale s
               WHERE  s.product_id = p1.product_id
               AND     s.sale_date >= ‘2024-04-01’
               AND     s.sale_date <= ‘2024-04-15’
             )

Si nous analysons la condition, la sous-requête renvoie tous les enregistrements de ventes pour un produit donné (p1.product_id) et pour une période spécifique (2024-04-01 à 2024-04-15). Si la sous-requête renvoie des enregistrements, alors EXISTS renverra TRUE. Si la sous-requête ne renvoie aucun enregistrement, EXISTS renverra FALSE. Notez que la sous-requête est exécutée plusieurs fois - une fois pour chaque ligne lue par la requête externe.

Ces types de sous-requêtes qui sont exécutées une fois pour chaque ligne traitée dans la requête principale sont appelées "sous-requêtes corrélées" et ont leurs particularités. Si vous souhaitez approfondir ce sujet, je vous suggère l'article Correlated Subquery in SQL : Un guide pour les débutants.
Exemple 2 : Utilisation de l'opérateur NOT EXISTS

Supposons maintenant que le responsable veuille connaître les noms des véhicules qui n'ont pas été vendus au cours de la même période. Ce type de requête - où nous recherchons des enregistrements qui n'existent pas dans la base de données - est excellent pour l'opérateur NOT EXISTS. En effet, nous recherchons des éléments qui n'existent pas dans la base de données. La requête est la suivante :
SELECT * FROM product p1
WHERE p1.product_type = ‘Car’
AND   NOT EXISTS ( SELECT * FROM sale s
                   WHERE s.product_id = p1.product_id
                   AND   s.sale_date >= ‘2024-04-01’
                   AND   s.sale_date <= ‘2024-04-15’
                 )

Résultats :
Product_id	Product_name	Product_price	Product_type
100	Ferrari F20	3000000	Car
102	Pagani Zonda	4300000	Car

Une fois que nous avons compris comment l'opérateur EXISTS fonctionne en SQL, il est très simple de comprendre NOT EXISTS; c'est l'inverse. Si EXISTS renvoie TRUE, alors NOT EXISTS renvoie FALSE et vice versa.

Dans cet exemple, la requête principale comporte une clause WHERE avec deux conditions. La première condition consiste à rechercher des produits du type "véhicule". La deuxième condition utilise NOT EXISTS pour ne conserver que les produits qui n'ont pas été vendus pendant la période allant du 2024-04-01 au 2024-04-15. En d'autres termes, nous recherchons les produits pour lesquels la sous-requête renvoie un ensemble de résultats vide, c'est-à-dire pour lesquels il n'y a pas eu de ventes au cours de cette période.

Dans certains cas, nous pouvons résoudre ce type de requête en utilisant NOT IN avec une sous-requête. Dans cette requête particulière, nous pouvons insérer la clause WHERE:
WHERE p1.product_type = ‘Car’
AND   p1.product_id NOT IN (SELECT s.product_id
                            FROM  sale s
               WHERE s.sale_date >= ‘2024-04-01’
                            AND   s.sale_date <= ‘2024-04-15’
                           )

Cependant, il y a une différence dans la manière dont la requête est exécutée en interne dans la base de données. La condition de la sous-requête NOT IN est exécutée une fois, tandis que la condition de la sous-requête NOT EXISTS est exécutée une fois par ligne. En effet, NOT EXISTS est une sous-requête corrélée. Pour en savoir plus sur ces opérateurs, lisez les articles 5 exemples de sous-requêtes SQL et Opérateur IN SQL.
Exemple 3 : Utilisation de EXISTS avec NOT EXISTS

Ensuite, nous avons besoin d'une liste des clients qui n'ont pas acheté de bateau pendant l'été 2023 mais qui ont acheté un bateau pendant l'hiver précédent (c'est-à-dire de décembre 2022 à mars 2023). La requête permettant d'obtenir ce rapport est la suivante :
SELECT *
FROM   client c1
WHERE  EXISTS ( SELECT * FROM sale s1
                JOIN  product p1 ON p1.product_id = s1.product_id
                WHERE c1.client_id = s1.client_id
                AND p1.product_type = 'Boat'
                AND s1.sale_date >= '2022-12-21'
                AND s1.sale_date <= '2023-03-20' -- winter
              )
AND    NOT EXISTS ( SELECT * FROM sale s2
                   JOIN  product p1 ON p1.product_id = s2.product_id
                   WHERE c1.client_id = s2.client_id
                   AND p1.product_type = 'Boat'
                   AND s2.sale_date >= '2023-6-21'
                   AND s2.sale_date <= '2023-09-20' -- summer
                  ) ;

Résultats :
client_id	Client_name	Country
11	Samid A.	Kuwait

Après les deux exemples précédents, cet exemple ne devrait pas être trop difficile à comprendre ; il s'agit d'une combinaison des deux. L'idée est de sélectionner l'enregistrement entier (SELECT *) dans la table client puis d'utiliser EXISTS pour vérifier qu'un bateau a été acheté l'hiver dernier. Ensuite, nous utilisons NOT EXISTS pour vérifier qu'un bateau n'a pas été acheté l'été dernier. Notez que les deux sous-requêtes comportent une adresse JOIN entre les balises sale et product car nous devons utiliser les colonnes product_type et sale_date dans les conditions WHERE.

Vous souhaitez mettre en pratique vos compétences SQL ? C'est parfait ! Découvrez notre programme de La pratique du SQL.

À ce stade, j'aimerais clarifier un point concernant les sous-requêtes corrélées. Nous avons mentionné que les sous-requêtes corrélées sont exécutées une fois pour chaque ligne candidate. Ce fait peut avoir un impact sur les performances de l'ensemble de la requête, en particulier lorsque nous travaillons avec de grandes tables.

En résumé, l'opérateur EXISTS (et les sous-requêtes corrélées) est une ressource SQL puissante pour certains types de requêtes. Cependant, nous devrions éviter les sous-requêtes corrélées si nous travaillons avec de grandes tables.
Pratiquer l'opérateur EXISTS

Comme pour beaucoup d'autres langages informatiques, apprendre le langage SQL en faisant des exercices est l'une des meilleures façons d'acquérir des compétences. Dans cette section, je vais donc présenter trois exercices de l'opérateur EXISTS de complexités différentes.
Exercice 1 : Anciennes commandes

Exercice : Le propriétaire de l'entreprise veut savoir quels produits (voitures ou bateaux) n'ont pas été commandés au cours des 365 derniers jours.

Solution :
SELECT p1.product_name
  FROM  product p1
  WHERE NOT EXISTS ( SELECT 1 FROM sale s
                     WHERE  s.product_id = p1.product_id
                     AND    s.sale_date >= CURRENT_DATE - 365
                   );

Résultats :
Product_name
Ferrari F20
Pagani Zonda
Lamborghini B9
VanDutch 58

Explication : La requête principale utilise la table product pour obtenir la colonne product_name. La clause WHERE de cette requête est la partie clé. Elle comporte une condition NOT EXISTS qui est évaluée à TRUE pour les produits qui n'ont pas été vendus au cours de l'année écoulée. La condition s.sale_date >= CURRENT_DATE - 365 dans la sous-requête permet d'obtenir toutes les lignes de l'année dernière.

Notez que la sous-requête renvoie une constante ( 1 ). En effet, l'important pour la sous-requête est le nombre de lignes qu'elle renvoie, et non le contenu des lignes renvoyées ; nous pouvons donc utiliser une colonne ou une constante telle que 1.
Exercice 2 : Acheteurs de moteurs de bateaux

Exercice : Notre entreprise est connue pour la fabrication d'un moteur de bateau et nous avons quelques clients qui n'achètent que ce produit. Le service marketing souhaite identifier les clients qui n'achètent que des moteurs de bateaux afin de pouvoir les cibler dans une campagne de marketing.

Solution :
SELECT * FROM client c1
WHERE EXISTS ( SELECT * FROM sale s1  -- they buy boat engines
           JOIN  product p1 ON p1.product_id = s1.product_id
                WHERE c1.client_id = s1.client_id
                AND   p1.product_name = 'Boat engine'  
               )
AND NOT EXISTS ( SELECT * FROM sale s2  -- they never buy other product
                 JOIN  product p2 ON p2.product_id = s2.product_id
            WHERE c1.client_id = s2.client_id
                 AND p2.product_name <> 'Boat engine'
                );

Résultats :
client_id	Client_name	Country
13	Pierre B.	France
14	Abdul E.	Kuwait

Explication : Cet exercice comporte une clause WHERE avec deux conditions. La première condition utilise un opérateur EXISTS pour vérifier que le client sélectionné par la requête externe a acheté un moteur de bateau. La seconde condition WHERE utilise NOT EXISTS pour vérifier que le même client (le client sélectionné par la requête externe) n'a jamais acheté un autre type de produit.

Si vous souhaitez explorer d'autres exercices sur les sous-requêtes, je vous recommande l'article Pratique des sous-requêtes SQL : 15 exercices avec solutions.
Exercice 3 : Jamais acheté

Exercice : Le propriétaire de l'entreprise veut un rapport " Jamais acheté" . Le rapport ne doit comporter que deux colonnes : client_name et product_name. Le contenu du rapport doit être le complément de la table sale tableau. En d'autres termes, si un client n'a jamais acheté un produit, la paire formée par ce client_name et ce product_name doit figurer dans le rapport.

Solution : Il existe deux approches pour résoudre cet exercice :

    En utilisant NOT EXISTS.
    En utilisant l'opérateur d'ensemble EXCEPT (ou MINUS).

Nous montrerons les deux approches.

Solution en utilisant NOT EXISTS:
SELECT c1.client_name, p1.product_name
FROM client c1, product p1
WHERE NOT EXISTS ( SELECT 1 FROM sale s
                   WHERE c1.client_id = s.client_id
                   AND   p1.product_id = s.product_id 
                 )

Résultats partiels de la requête :
Client_name	Product_name
John F.	Ferrari F20
John F.	Pagani Zonda
John F.	Lamborghini B9
John F.	VanDutch 56
Samid A.	Lamborghini AX
Samid A.	Pagani Zonda
Samid A.	VanDutch 56
Samid A.	Lamborghini B9
Samid A.	Boat Engine Yamei 100
Samid A.	Ferrari F20

Explication : Le premier point à comprendre est le résultat de cette partie de la requête :
SELECT c1.client_name, p1.product_name
FROM client c1, product p1

Comme nous ne joignons pas correctement les tables client et productle résultat est un produit cartésien - un ensemble de toutes les paires <client_name, product_name> possibles.

Une fois que nous avons toutes les paires possibles, nous procédons à l'élimination de ces paires dans le tableau à l'aide de l'opérateur . sale à l'aide de l'opérateur NOT EXISTS.

Solution en utilisant EXCEPT:
SELECT c1.client_name, p1.product_name
FROM client c1, product p1
EXCEPT
SELECT client_name, product_name
FROM sale s
JOIN product p ON p.product_id  = s.product_id
JOIN client c ON c.client_id = s.client_id

Explication : La première partie de cette approche est similaire à la solution précédente ; nous créons toutes les paires client-produit possibles. Ensuite, à l'aide de l'opérateur EXCEPT, nous supprimons les paires qui se trouvent dans le tableau. sale tableau. Nous obtenons ainsi les paires que nous recherchons.

Voici la différence : Dans la deuxième partie de EXCEPT, nous devons JOIN le tableau sale à l'aide de l'opérateur product et client tables.
Continuez à développer vos compétences en matière d'opérateurs SQL EXISTS

Dans cet article, nous avons abordé les opérateurs EXISTS et NOT EXISTS à l'aide de plusieurs exemples. Nous avons également expliqué les avantages et les inconvénients des sous-requêtes corrélées. Pour les lecteurs qui souhaitent améliorer leurs compétences en SQL, je recommande la piste La pratique du SQL piste. Vous y trouverez des centaines d'exercices sur des sujets SQL comme les JOIN, GROUP BY, HAVING, les sous-requêtes et même l'opérateur EXISTS.

Si vous aimez apprendre SQL à l'aide d'exercices pratiques, vous devez essayer LearnSQL.fr.

Si vous débutez avec SQL ou si vous avez besoin d'une remise à niveau, je vous recommande notre cours de SQL pour les débutants cours. Lorsque vous améliorez vos compétences en SQL, vous investissez en vous !
