ATTENTION REECRIRE
https://learnsql.fr/blog/10-exercices-sur-les-sous-requetes-correlees-avec-solutions/

10 Exercices sur les sous-requêtes corrélées avec solutions

Les sous-requêtes corrélées sont une fonctionnalité SQL puissante essentielle pour l'analyse avancée des données. Cet article propose 10 exercices pratiques pour vous aider à maîtriser les sous-requêtes corrélées.

Le langage SQL est une compétence fondamentale pour toute personne travaillant avec des données, que ce soit en tant qu'analyste de données, développeur SQL, ingénieur de données ou toute autre profession connexe. La maîtrise du langage SQL ne se limite pas à la compréhension des bases. Elle nécessite également l'apprentissage de fonctionnalités SQL avancées, telles que les sous-requêtes.

Une sous-requête est une requête SQL imbriquée dans une requête plus importante. Il existe de nombreux types de sous-requêtes. Une sous-requête corrélée est un type de sous-requête qui fait référence à la requête externe et ne peut pas être exécutée indépendamment. Les sous-requêtes, et en particulier les sous-requêtes corrélées, peuvent être un sujet difficile pour les apprenants de SQL.

Si vous aimez apprendre SQL à l'aide d'exercices pratiques, vous devez essayer LearnSQL.fr.

Précédemment, nous avons fourni une collection d'exercices de sous-requêtes dans notre article : Pratique des sous-requêtes SQL : 15 exercices avec solutions. Dans cet article, nous vous proposons un ensemble d'exercices d'entraînement portant spécifiquement sur les sous-requêtes corrélées. Les exercices de cet article sont tirés de nos cours interactifs Basic SQL Practice: A Store et Pratique SQL : Université. Ces deux cours font partie de la filière "La pratique du SQL", qui propose plusieurs cours de pratique SQL. Tous les cours de la piste sont basés sur des scénarios réels et sont organisés par thèmes SQL pour vous aider à vous concentrer sur votre domaine d'intérêt.
Exercices sur une base de données de magasin

La première série d'exercices est basée sur la base de données d'une boutique en ligne. Ces exercices sont tirés de notre cours Basic SQL Practice: A Store. Nous commencerons par travailler avec seulement deux tables : product et category.

La table product contient la liste des produits disponibles dans le magasin.

    product_id - l'ID du produit.
    product_name - le nom du produit.
    category_id - l'identifiant de la catégorie du produit. Elle vous aide à vous connecter à la table des catégories.
    quantity_per_unit - la quantité d'articles du produit dans une unité.
    unit_price - le prix du produit
    discontinued - l'information indiquant si le produit est toujours disponible dans le magasin (valeur FALSE) ou s'il a été supprimé (valeur TRUE).

Le tableau category contient des informations sur les catégories de produits :

    category_id - l'ID de la catégorie.
    name - le nom de la catégorie
    description - la description facultative de la catégorie

Exercice 1 : Produits chers dans chaque catégorie

Exercice : Trouvez les produits qui sont plus chers que le prix moyen des produits de leur propre catégorie. Incluez le nom de la catégorie, le nom du produit et le prix unitaire dans le résultat.

Solution :
SELECT
  c.name,
  p.product_name,
  p.unit_price
FROM category AS c
JOIN product AS p
  ON c.category_id = p.category_id
WHERE p.unit_price > (
  SELECT AVG(unit_price)
  FROM product
  JOIN category
    ON product.category_id = category.category_id
  WHERE category.category_id = c.category_id
  );

Explication de la solution :

Dans la solution, nous utilisons une sous-requête corrélée pour calculer le prix unitaire moyen des produits appartenant à la même catégorie que le produit traité par la requête externe. Cette sous-requête fait référence à la catégorie, désignée par c, de la requête externe. Elle identifie les produits de cette catégorie et calcule leur prix moyen. Les produits dont le prix est supérieur à la moyenne de leur catégorie sont filtrés à l'aide de cette moyenne. La requête externe récupère et affiche ensuite le nom de la catégorie, le nom du produit et le prix unitaire de ces produits.
Exercice 2 : Le nombre de produits chers dans chaque catégorie

Exercice : Affichez les noms des catégories et le nombre de produits de cette catégorie dont le prix unitaire est supérieur au prix moyen d'un produit de cette catégorie. Ne montrez que les catégories qui ont ce(s) produit(s). Affichez deux colonnes : name (le nom de la catégorie) et expensive_products (le nombre de produits dont le prix est supérieur au prix moyen d'un produit de cette catégorie).

La solution :
SELECT
  c.name,
  COUNT(*) AS expensive_products
FROM category AS c
JOIN product AS p
  ON c.category_id = p.category_id
WHERE p.unit_price > (
  SELECT
    AVG(unit_price)
  FROM product
  JOIN category
    ON product.category_id = category.category_id
  WHERE category.category_id = c.category_id
  )
GROUP BY
  c.category_id,
  c.name;

Explication de la solution :

Cet exercice est similaire au précédent. Nous devons également trouver des produits dont le prix unitaire est supérieur au prix moyen de leur catégorie. Cependant, cette fois-ci, nous voulons compter les produits dans chaque catégorie.

Dans la solution, nous utilisons la même sous-requête corrélée que précédemment : nous calculons le prix unitaire moyen des produits de la même catégorie que le produit traité par la requête externe. Cette moyenne est ensuite utilisée dans la requête principale pour filtrer uniquement les produits dont le prix unitaire est supérieur à la moyenne de la catégorie. La requête principale compte ces produits à l'aide de COUNT(*) et regroupe les résultats par catégorie avec GROUP BY. Le résultat final affiche le nom de la catégorie et le nombre de produits.
Exercice 3 : produits abandonnés, produits poursuivis et tous les produits d'une catégorie

Exercice : Pour chaque catégorie, affichez son name, le nombre de produits abandonnés dans cette catégorie (discontinued_products), le nombre de produits maintenus dans cette catégorie (continued_products), et le nombre de tous les produits dans cette catégorie (all_products).

Solution :
SELECT
  c.name,
  (SELECT COUNT(*) FROM product WHERE category_id = c.category_id AND discontinued IS TRUE) AS discontinued_products,
  (SELECT COUNT(*) FROM product WHERE category_id = c.category_id AND discontinued IS FALSE) AS continued_products,
  (SELECT COUNT(*) FROM product WHERE category_id = c.category_id) AS all_products
FROM category c;

Explication de la solution :

Nous utilisons ici trois sous-requêtes corrélées dans l'instruction SELECT pour obtenir le nombre de produits en fonction de leur statut continué/abandonné pour chaque catégorie. Chaque sous-requête est corrélée à la requête principale par l'intermédiaire de category_id afin que les comptages soient corrects pour chaque catégorie.

La première sous-requête compte le nombre de produits dans une catégorie où l'indicateur discontinued est TRUE. Nous obtenons ainsi le nombre total de produits qui ne sont plus disponibles dans chaque catégorie. La deuxième sous-requête compte le nombre de produits encore actifs dans chaque catégorie, en utilisant une méthode similaire. La troisième sous-requête compte simplement le nombre de tous les produits d'une catégorie.

Cet exercice pourrait également être résolu sans sous-requêtes, en utilisant une combinaison de CASE WHEN avec SUM et GROUP BY. En guise d'exercice alternatif : pouvez-vous résoudre cet exercice des deux façons ?
Autres tables de la base de données du magasin : Tables des clients et des achats

Dans les exercices suivants, nous travaillerons avec des tables supplémentaires de la base de données du magasin liées aux achats : customer, purchase, et purchase_item.

La table customer contient les informations sur les clients. Elle comporte les colonnes suivantes

    customer_id - l'ID du client.
    contact_name - le nom complet du client.
    contact_email - l'adresse électronique du client.

Le tableau purchase contient les informations relatives à chaque commande :

    purchase_id - l'ID de l'achat.
    customer_id - l'ID du client.
    total_price - le prix total de la commande.
    purchase_date - l'horodatage de l'achat.

La table purchase_item relie les achats aux produits. Le tableau contient les colonnes suivantes

    purchase_id - l'ID de l'achat.
    product_id - l'ID du produit acheté.
    unit_price - le prix d'une unité d'un produit
    quantity - le nombre d'unités achetées d'un produit.

Exercice 4 : Produits dans les catégories

Exercice : Pour chaque produit acheté, affichez le nom du produit, la quantité maximale dans laquelle il a été acheté et le nombre de ces achats (de ce produit dans cette quantité maximale). Affichez trois colonnes : product_name, quantity, et purchases_number.

Solution :
SELECT
  product_name,
  quantity,
  COUNT(purchase_id) AS purchases_number
FROM purchase_item pi
JOIN product p
  ON pi.product_id = p.product_id
WHERE quantity = (SELECT MAX(quantity) FROM purchase_item WHERE product_id = pi.product_id)
GROUP BY
  pi.product_id,
  product_name,
  quantity;

Explication de la solution :

Nous voulons trouver la quantité maximale dans laquelle chaque produit a été acheté et le nombre de fois où de tels achats ont eu lieu. Nous utilisons une sous-requête corrélée et GROUP BY pour obtenir ce résultat.

Tout d'abord, nous utilisons une sous-requête corrélée dans WHERE pour déterminer la quantité maximale dans laquelle chaque produit a été acheté. Ensuite, dans la requête externe, nous utilisons cette valeur pour trouver les achats dont la quantité est égale à cette quantité maximale. Enfin, la requête externe regroupe les résultats par product_id, product_name et quantity et utilise la fonction d'agrégation COUNT(purchase_id) pour calculer le nombre d'achats pour chaque produit à la quantité maximale.

Vous souhaitez mettre en pratique vos compétences SQL ? C'est parfait ! Découvrez notre programme de La pratique du SQL.
Exercice 5 : Pourcentage de l'argent dépensé par le client pour l'achat

Exercice : Pour chaque client ayant effectué un achat, affichez l'ID de chaque achat effectué par ce client, le pourcentage de l'argent dépensé pour cet achat par rapport à l'ensemble de l'argent dépensé par ce client. Arrondissez les pourcentages à des nombres entiers. Affichez trois colonnes : contact_name purchase_id et percentage.

Solution :
SELECT
  contact_name,
  purchase_id,
  ROUND(total_price * 100.0 / (SELECT SUM(total_price) FROM purchase WHERE customer_id = p.customer_id)) AS percentage
FROM purchase p
JOIN customer
  ON p.customer_id = customer.customer_id;

Explication de la solution :

Dans la requête externe, nous dressons la liste de tous les achats effectués par chaque client. Nous joignons les tables purchase et customer pour afficher le nom du contact du client et l'identifiant de l'achat. Nous utilisons une sous-requête corrélée pour connaître le montant total dépensé par le client actuel. Nous utilisons le montant trouvé par la sous-requête pour calculer le pourcentage des dépenses totales que représente l'achat en cours.
Exercice 6 : Clients dont les achats sont supérieurs au montant moyen de leurs achats

Exercice : Recherchez les clients dont le dernier achat a été supérieur au montant moyen de leurs achats. Affichez le nom du client et le dernier montant d'achat.

Solution :
SELECT
  c.contact_name,
  p.total_price AS last_purchase_total
FROM purchase p
JOIN customer c
ON p.customer_id = c.customer_id
WHERE p.purchase_date = (
    SELECT MAX(lp.purchase_date)
    FROM purchase lp
    WHERE lp.customer_id = p.customer_id
  )
AND p.total_price > (
    SELECT AVG(ap.total_price)
    FROM purchase ap
    WHERE ap.customer_id = p.customer_id
);

Explication de la solution :

Cet exercice nécessite deux sous-requêtes. La première sous-requête est utilisée pour trouver la date de l'achat le plus récent de chaque client, comme dans l'exercice 4, mais en se concentrant sur la date de la transaction plutôt que sur les quantités. La deuxième sous-requête calcule le prix total moyen des achats du client et est utilisée pour filtrer les achats dont le prix est supérieur à la moyenne. Les deux sous-requêtes sont combinées dans la clause WHERE à l'aide d'un opérateur AND.
Exercices sur le modèle de données de l'université

La deuxième série d'exercices de cet article est basée sur la base de données d'une université. Ces exercices sont tirés de notre cours Pratique SQL : Université. La base de données de l'université comporte 4 tables.

La table course contient des informations sur les cours offerts à l'université et les parcours d'apprentissage auxquels ils sont associés :

    id - Un identifiant unique pour chaque cours.
    title - Le nom du cours.
    lecture_hours - Le nombre total d'heures de cours magistraux dans le cours.
    tutorial_hours - Le nombre total d'heures de tutorat dans le cours.

La table student contient toutes les informations relatives à chaque étudiant de l'université :

    id - Un identifiant unique pour chaque étudiant.
    first_name - Le prénom de l'étudiant.
    last_name - Le nom de famille de l'étudiant.

La table course_edition contient des informations sur les professeurs qui enseignent chaque cours au cours de chaque semestre :

    id - L'ID de l'édition du cours.
    course_id - L'identifiant du cours.
    academic_semester - L'année civile et le trimestre (automne ou printemps) du semestre.
    lecturer - le nom du professeur qui enseigne le cours.

La table course_enrollment contient les informations relatives aux étudiants inscrits dans une édition de cours :

    course_edition_id - L'identifiant de l'édition du cours.
    student_id - l'identifiant de l'étudiant.
    midterm_grade - La note de mi-parcours que l'étudiant a reçue.
    final_grade - La note finale obtenue par l'étudiant.
    course_letter_grade - La note du cours, sous forme de lettre (A+, A, A-, B+, B, B-, C+, C, C-, D+, D, D-, ou F).
    passed - Si l'étudiant a réussi (TRUE) ou échoué (FALSE) le cours.

Si l'étudiant n'a pas encore passé son examen, le tableau peut contenir des champs NULL.
Exercice 7 : étudiants ayant obtenu une note supérieure à la moyenne

Exercice : Trouvez les étudiants qui ont obtenu une note finale supérieure à la moyenne dans l'une des éditions de cours auxquelles ils ont assisté. Afficher : le nom et le prénom de l'étudiant, le titre du cours et son adresse final_grade. N'affichez que les étudiants dont la note finale dans cette édition du cours était supérieure à la note finale moyenne dans cette édition du cours.

Solution :
SELECT
  first_name,
  last_name,
  title,
  final_grade
FROM course_enrollment AS c_en
JOIN student AS s
  ON c_en.student_id = s.id
JOIN course_edition AS c_ed
  ON c_en.course_edition_id = c_ed.id
JOIN course AS c
  ON c_ed.course_id = c.id
WHERE final_grade > (
  SELECT AVG(final_grade)
  FROM course_enrollment AS c_e
  WHERE c_e.course_edition_id = c_en.course_edition_id
);

Explication de la solution :

La solution utilise une seule requête corrélée. Dans la sous-requête corrélée, nous trouvons la note finale moyenne pour l'édition de cours traitée dans la requête principale. Nous utilisons ensuite la moyenne trouvée dans la sous-requête pour filtrer les inscriptions aux cours pour lesquels la note finale de l'étudiant était supérieure à la moyenne. Dans la requête principale, nous joignons les tables course_enrollment, student, course_edition et course pour combiner le nom et le prénom de l'étudiant avec l'intitulé du cours et la note qu'il a obtenue.
Exercice 8 : Nombre d'étudiants ayant obtenu la même note ou une note supérieure

Exercice :Pour chaque note finale du tableau course_enrollment, comptez le nombre d'étudiants qui ont obtenu exactement cette note ou une note supérieure. Affichez deux colonnes : final_grade et students_number.

Solution :
SELECT DISTINCT
  final_grade,
  (SELECT COUNT (student_id)
   FROM course_enrollment
   WHERE final_grade >= c.final_grade) AS students_number
FROM course_enrollment c;

Explication de la solution :

La requête principale sélectionne chaque note finale unique (distincte) dans la table course_enrollment. Pour chacune de ces notes, la sous-requête corrélée compte le nombre d'étudiants dont les notes finales sont égales ou supérieures à la note traitée par la requête externe. Le résultat est affiché dans deux colonnes : final_grade students_number , qui indique le nombre d'étudiants ayant obtenu cette note ou une note supérieure.
Exercice 9 : Les étudiants qui ont réussi et ceux qui n'ont pas réussi

Exercice : Divisez les étudiants de chaque édition de cours en deux groupes: ceux qui ont réussi le cours et ceux qui ne l'ont pas réussi. Pour chaque groupe, affichez les colonnes suivantes :

    course_edition_id
    passed
    average_final_grade - La moyenne des étudiants de ce groupe (reçus ou non reçus), arrondie à la deuxième décimale.
    average_edition_grade - La moyenne générale des étudiants de ce cours, arrondie à la deuxième décimale.

Solution :
SELECT
  course_edition_id,
  passed,
  ROUND(AVG(final_grade), 2) AS average_final_grade,
  (SELECT ROUND(AVG(final_grade), 2)
         FROM course_enrollment
         WHERE course_edition_id = c_e.course_edition_id) AS average_edition_grade
FROM course_enrollment c_e
GROUP BY
  course_edition_id,
  passed;

Explication de la solution :

La requête externe sélectionne l'identifiant de l'édition du cours, la valeur passed et la note finale moyenne pour ce groupe d'étudiants (soit "réussi", soit "non réussi") à l'aide de la clause régulière GROUP BY. Elle utilise également une sous-requête corrélée pour trouver la note finale moyenne globale pour l'édition de cours traitée dans la requête externe et ajoute cette moyenne au résultat de la requête. De cette façon, vous pouvez comparer la note finale de chaque groupe avec la moyenne générale.
Exercice 10 : nouvelles moyennes

Exercice : Pour chaque édition de cours, présentez les données suivantes :

    title
    average_result - La moyenne des notes finales des étudiants ayant une note finale supérieure à la moyenne de l'édition du cours. Arrondissez le résultat à 0 décimale (c'est-à-dire un nombre entier).
    results_better_than_average - Le nombre d'étudiants dont la note finale est supérieure à la note finale moyenne pour cette édition du cours.

Solution :
SELECT
  c.title,
  ROUND(AVG(final_grade)) AS average_result,
  COUNT (student_id) AS results_better_than_average
FROM course_enrollment AS c_en
JOIN course_edition AS c_ed
  ON c_en.course_edition_id = c_ed.id
JOIN course AS c
  ON c_ed.course_id = c.id
WHERE final_grade > (
  SELECT AVG(final_grade)
  FROM course_enrollment AS c_en2
  WHERE c_en2.course_edition_id = c_en.course_edition_id
)
GROUP BY
  c.id,
  c.title;

Explication de la solution :

Dans la sous-requête corrélée, nous calculons la note finale moyenne pour l'édition de cours traitée par la requête externe. Nous avons ensuite utilisé cette valeur pour filtrer les étudiants dont la note finale dans cette édition du cours était supérieure à la moyenne. Dans la requête externe, nous affichons le titre du cours, le nombre d'étudiants dont la note finale est supérieure à la moyenne et la note finale moyenne pour ce groupe d'étudiants.
Conclusion et prochaines étapes

Dans cet article, nous avons exploré plusieurs exercices de sous-requêtes corrélées pour améliorer votre compréhension de cette fonctionnalité SQL importante. Pour ceux qui souhaitent développer davantage leurs compétences en SQL, nous recommandons notre piste "La pratique du SQL". Elle comprend 10 cours de pratique SQL différents. Chaque cours est rempli d'exercices pratiques basés sur des scénarios réels et est organisé par thèmes SQL pour vous aider à vous concentrer sur votre domaine d'intérêt

LearnSQL.fr est une plateforme en ligne conçue pour vous aider à maîtriser SQL. LearnSQL.fr vous permet de choisir entre un programme d'apprentissage complet, des mini-programmes pour affiner des compétences ciblées et des cours individuels. Vous pouvez également sélectionner le dialecte SQL (Standard SQL, Microsoft SQL Server ou PostgreSQL) qui correspond le mieux à vos besoins.

En outre, nous vous recommandons de consulter notre pack Tout à vie SQL - l'offre ultime pour les apprenants SQL. Cette offre de paiement unique fournit un accès à vie à tous les cours actuels et futurs de notre catalogue, y compris tout ce qui se trouve dans la piste 'La pratique du SQL'. Il s'agit d'une ressource inestimable pour toute personne désireuse de devenir un expert en SQL.
