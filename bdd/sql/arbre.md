https://learnsql.fr/blog/comment-interroger-un-arbre-parent-enfant-en-sql/

Comment interroger un arbre parent-enfant en SQL

Qu'est-ce qu'une arborescence parent-enfant en SQL ? Dans cet article, nous répondons à cette question, nous parlons de la hiérarchie des requêtes et nous démontrons les cinq requêtes SQL les plus courantes dont vous aurez besoin pour ces structures de données.

Oui, vous pouvez utiliser SQL sur une structure arborescente parent-enfant. Je vous montrerai comment dans cet article. En cours de route, je vous présenterai cinq exemples de requêtes, en commençant par la plus simple et en terminant par la plus complexe. Ces exemples utilisent des expressions de table commune récursives (CTE).

Si vous n'êtes pas familiarisé avec les CTE, je vous recommande notre cours interactif Requêtes récursives cours interactif. Il contient plus de 100 exercices qui vous apprennent à utiliser les CTE en SQL, en commençant par les bases et en progressant vers des sujets avancés comme les CTE récursifs.

Avant de nous plonger dans le code, examinons la structure de l'arbre parents-enfants et la manière dont elle est stockée dans une base de données relationnelle.
Qu'est-ce qu'un arbre parents-enfants ?

Si vous comprenez les données hiérarchiques, vous savez probablement qu'il s'agit d'un synonyme de structure parent-enfant. Ces deux noms sont très logiques : une arborescence parent-enfant est un ensemble de données structurées de manière hiérarchique. En d'autres termes, il existe des relations hiérarchiques entre les éléments de données. Cela signifie qu'un élément de données peut être le parent d'un autre élément de données, qui est alors appelé enfant. Les éléments sont également appelés niveaux ou nœuds de l'arbre et peuvent prendre trois formes principales :

Apprenez notre cours interactif le mieux noté, SQL Requêtes récursives, et devenez un spécialiste SQL professionnel !

    Nœud racine - Le premier nœud, où commence l'arbre parent-enfant.
    Nœud parent - Il s'agit de tout nœud ayant un ou plusieurs nœuds descendants (ou nœuds enfants).
    Nœud enfant - Tout nœud ayant un prédécesseur ou un nœud parent.

Qu'est-ce qu'un arbre parents-enfants ?

Parmi les exemples réels de structures parents-enfants, on peut citer les structures organisationnelles des entreprises (une entreprise se compose de départements, les départements se composent d'équipes et les équipes se composent d'employés), les arbres généalogiques (il y a des parents, des enfants, des petits-enfants, des arrière-petits-enfants, etc.) et les taxonomies naturelles (les êtres vivants appartiennent à un domaine, un royaume, un phylum, une classe, un ordre, une famille, un genre et une espèce). Même les dossiers informatiques (disque C, Program Files, Microsoft SQL Server...), les menus (boissons, boissons non alcoolisées, thé...), les genres artistiques et musicaux (par exemple, il y a eu le blues, qui a développé le rhythm and blues, qui a conduit à la soul, au funk, etc.) et les projets (un projet a des sous-projets, qui ont des tâches, des sous-tâches, etc.
Structure arborescente parents-enfants dans les bases de données relationnelles

Pour que SQL puisse en faire quelque chose, une arborescence parent-enfant doit être stockée dans une base de données relationnelle.

Ces structures sont généralement stockées dans une table avec deux colonnes ID, dont l'une fait référence à l'ID de l'objet parent. Cela nous permet de déterminer la hiérarchie entre les données. En d'autres termes, nous savons quel nœud est un nœud parent de quel nœud enfant et vice versa.

Cela peut sembler un peu abstrait, c'est pourquoi je vais vous montrer comment cela fonctionne à l'aide d'un exemple simple. Et je vais être littéral avec ça ! Mon arborescence parent-enfant affichera des données sur les parents et leurs enfants. Jetez un coup d'œil :
id	first_name	last_name	parent_id
1	Jim	Cliffy	NULL
2	Mark	Cliffy	1
3	Veronica	Cliffy	2

Ici, la colonne id indique l'identifiant de l'enfant. Pour savoir qui est le parent de cet enfant, vous devez consulter la colonne parent_id, trouver le même numéro d'identification dans la colonne id et rechercher le nom du parent dans cette ligne.

En d'autres termes, Jim Cliffy n'a pas de parents dans ce tableau ; la valeur de sa colonne parent_id est NULL. Cela signifie qu'il est le nœud racine de cette arborescence.

Mark Cliffy est le fils de Jim Cliffy. Comment le sais-je ? Parce que Mark est parent_id = 1, qui est l'identifiant de Jim Cliffy. Mark Cliffy est un nœud enfant, mais il est aussi un nœud parent. Pourquoi ? Parce que Veronica Cliffy est la fille de Mark Cliffy. Je le sais parce que son parent a parent_id = 2, et la table m'indique qu'il s'agit de Mark Cliffy. Veronica Cliffy est strictement un nœud enfant ; elle a un nœud parent, mais aucun nœud enfant ne se ramifie à partir d'elle.
Requêtes typiques exécutées sur une arborescence parents-enfants

J'utiliserai le même tableau pour chacune de ces requêtes. Il comporte les mêmes colonnes que celles présentées ci-dessus, mais avec plus de lignes et des valeurs différentes.
Présentation des données d'exemple

Le tableau s'appelle parent_child et comporte les colonnes suivantes :

    id - L'ID de l'enfant et la clé primaire (PK) de la table.
    first_name - Le prénom de l'enfant.
    last_name - Le nom de famille de l'enfant.
    parent_id - L'identifiant du parent de l'enfant.

Voici le tableau complet :
id	first_name	last_name	parent_id
1	Rosa	Wellington	NULL
2	Jon	Wellington	1
3	Joni	Wellington	1
4	Marge	Wellington	1
5	Mary	Dijkstra	2
6	Frank	Wellington	2
7	Jason	Wellington	3
8	Bobby	Wellington	4
9	Sammy	Wellington	4
10	Sarah	Wellington	4
11	Sam Francis	Dijkstra	5
12	Stephen	Wellington	6
13	Trent	Wellington	6
14	June	Wellington	9
15	Josephine	Wellington	9
16	Suzy	Wellington	9

Vous pouvez utiliser ce tableau pour vérifier si les requêtes que je vais vous présenter produisent des résultats corrects.
Exemple 1 : Liste de tous les enfants d'un parent

Il s'agit de la requête la plus simple, je vais donc l'utiliser pour vous familiariser avec l'arborescence. Ici, je veux trouver tous les enfants d'un parent spécifié. Dans ce cas, je souhaite trouver tous les enfants d'une personne appelée Marge Wellington, dont l'ID est 4.

Voici la petite requête :
SELECT first_name,
     last_name
FROM parent_child
WHERE parent_id = 4;

J'ai simplement sélectionné le prénom et le nom de famille dans la table et j'ai utilisé la clause WHERE pour n'afficher que les lignes où il y a un 4 dans la colonne parent_id.

Le résultat affiche trois lignes :
first_name	last_name
Bobby	Wellington
Sammy	Wellington
Sarah	Wellington

Cela m'indique que Bobby, Sammy et Sarah Wellington sont tous les enfants de Marge Wellington. Jetez un coup d'œil au tableau original et vous verrez que c'est vrai.

Ce n'était qu'un échauffement ! Passons au suivant.
Exemple 2 : Lister un nœud parent pour un nœud enfant

Le résultat de l'exemple précédent était un peu, eh bien, basique. Je n'ai listé que les noms des enfants. Il pourrait être très utile d'afficher également le nom du parent. C'est exactement ce que je vais faire. J'afficherai à la fois le prénom et le nom de famille de l'enfant et du parent.

Au lieu de chercher les enfants d'un parent, je chercherai maintenant les parents de l'enfant. Je veux savoir qui est le parent de Sam Francis Dijkstra. Outre les noms, je veux aussi voir les identifiants.

La requête pour cela est la suivante :
SELECT child.id AS child_id,
     child.first_name AS child_first_name,
     child.last_name AS child_last_name,
     parent.first_name AS parent_first_name,
     parent.last_name AS parent_last_name,
     parent.id AS parent_id
FROM parent_child child
JOIN parent_child parent
  ON child.parent_id = parent.id
WHERE child.id = 11;

Le concept principal que j'introduis ici est l'auto-jointure. J'ai donné l'alias child à la table parent_child et je l'ai jointe à elle-même en utilisant l'alias parent alias. Ce faisant, j'agis comme si je travaillais avec deux tables différentes. L'une contient les données relatives aux enfants ; c'est pourquoi je l'ai nommée child. L'autre contient les données relatives aux parents, c'est pourquoi je l'ai appelée parent.

Les colonnes sélectionnées en témoignent. Les noms et les identifiants des enfants sont sélectionnés dans le "premier" tableau. Les noms et les identifiants des parents sont sélectionnés dans la "deuxième" table. Les "tables" sont jointes lorsque parent_id est égal à id.

La table originale m'indique que l'ID de Sam Francis Dijkstra est 11. J'ai utilisé la clause WHERE pour filtrer les données et n'afficher que le parent de Sam Francis. Vous pouvez également utiliser la clause WHERE sur les colonnes child.first_name et child.last_name. J'ai choisi de filtrer les données en utilisant l'ID car la requête est un peu plus courte de cette façon.

Voici le résultat :
child_id	child_first_name	child_last_name	parent_first_name	parent_last_name	parent_id
11	Sam Francis	Dijkstra	Mary	Dijkstra	5

La mère de Sam Francis est Mary Dijkstra, ce qui est vrai.

Tout est clair jusqu'à présent ? Oui, bien sûr. Passons à la suite !
Exemple 3 : Obtenir un numéro de génération (ou niveau de l'arbre) pour chaque nœud

Dans cet exemple, je veux lister chaque personne du tableau et montrer à quelle génération elle appartient. Quel est l'objectif de cette opération ? Lorsque j'obtiens ces données, je peux facilement voir qui appartient à quelle génération : parents, enfants, petits-enfants, etc.

Pour ce faire, j'utiliserai un CTE - pas un CTE ordinaire, mais un CTE récursif. Si vous avez besoin de rafraîchir vos connaissances en matière d'ETC, voici un article expliquant ce qu'est un ETC.

Voici ma requête :
WITH RECURSIVE generation AS (
    SELECT id,
        first_name,
        last_name,
        parent_id,
        0 AS generation_number
    FROM parent_child
    WHERE parent_id IS NULL
 
UNION ALL
 
    SELECT child.id,
        child.first_name,
        child.last_name,
        child.parent_id,
        generation_number+1 AS generation_number
    FROM parent_child child
    JOIN generation g
      ON g.id = child.parent_id
)
 
SELECT first_name,
     last_name,
     generation_number
FROM generation;

Comme tout ETC récursif, le mien commence par deux mots-clés : WITH RECURSIVE. J'ai nommé la génération CTE. Dans la première instruction SELECT, je sélectionne les ID et les noms. De plus, il y a une nouvelle colonne appelée generation_number avec un 0 pour toutes les lignes où parent_id = NULL. Pourquoi NULL? Parce que je sais que la personne qui est le prédécesseur de toutes les autres n'a pas de parent dans la table. Par conséquent, la valeur doit être NULL.

J'utilise UNION ALL pour fusionner le résultat de cette instruction SELECT avec la seconde, qui sera responsable de la récursivité. Pour que UNION ALL fonctionne, le nombre de colonnes et les types de données doivent être identiques dans les deux instructions SELECT.

Le membre récursif sélectionne à nouveau les ID et les noms. Il y a également la colonne generation_number avec la valeur generation_number+1. À chaque récursivité, 1 sera ajouté à la valeur précédente de cette colonne. Comme la requête commence par 0, la première récursion aboutira à un 1 dans la colonne generation_number, la deuxième à un 2, et ainsi de suite.

Pour que tout cela fonctionne, j'ai joint la table parent_child avec l'ETC lui-même où id = parent_id. Le principe est le même que pour les tables auto-jointes : la table sert de données sur les enfants, l'ETC sert de données sur les parents.

Après avoir écrit l'ETC, je dois utiliser ses données. Pour ce faire, j'ai écrit une simple instruction SELECT qui renvoie les noms et les numéros de génération de l'ETC. Bien joué, n'est-ce pas ?

Voici à quoi ressemble le résultat :
first_name	last_name	generation_number
Rosa	Wellington	0
Jon	Wellington	1
Joni	Wellington	1
Marge	Wellington	1
Mary	Dijkstra	2
Frank	Wellington	2
Jason	Wellington	2
Bobby	Wellington	2
Sammy	Wellington	2
Sarah	Wellington	2
Sam Francis	Dijkstra	3
Stephen	Wellington	3
Trent	Wellington	3
June	Wellington	3
Josephine	Wellington	3
Suzy	Wellington	3

Avec ce résultat, je vois que Rosa Wellington est le nœud racine parce que son numéro de génération est 0. Toutes les personnes ayant la valeur 1 sont ses enfants, la valeur 2 sont ses petits-enfants et la valeur 3 sont ses arrière-petits-enfants. Si vous vérifiez cela dans le tableau source, vous constaterez que tout ce que j'ai dit est vrai.

Vous souhaitez apprendre les requêtes récursives SQL ? Consultez notre cours interactif.
Exemple 4 : Liste de tous les descendants

Cet exemple est une extension du précédent. Je veux vous montrer comment lister tous les descendants d'un parent et afficher à la fois les noms des parents et des enfants.

Voici la requête :
WITH RECURSIVE generation AS (
    SELECT id,
         first_name,
         last_name,
         parent_id,
         0 AS generation_number
    FROM parent_child
    WHERE parent_id IS NULL
 
UNION ALL
 
    SELECT child.id,
         child.first_name,
         child.last_name,
         child.parent_id,
         generation_number+1 AS generation_number
    FROM parent_child child
    JOIN generation g
      ON g.id = child.parent_id
 
)
 
SELECT  g.first_name AS child_first_name,
        g.last_name AS child_last_name,
        g.generation_number,
        parent.first_name AS parent_first_name,
        parent.last_name AS parent_last_name
FROM generation g
JOIN parent_child parent
ON g.parent_id = parent.id
ORDER BY generation_number;

Si vous comparez cette requête avec la précédente, vous verrez que la partie CTE est identique. Il n'est pas nécessaire que je la reprenne.

Ce qui est différent, c'est l'instruction SELECT qui fait référence à l'ETC. Mais il n'y a pas de nouveaux concepts SQL ici non plus. La requête sélectionne les noms des enfants et des parents ainsi que leur numéro de génération. Pour ce faire, j'ai à nouveau joint le CTE à la table parent_child. Le CTE contient les données relatives aux enfants, tandis que la table contient les données relatives aux parents. La dernière ligne de code ordonne le résultat en fonction du numéro de génération.

La requête renvoie exactement ce que je voulais :
child_first_name	child_last_name	generation_number	parent_first_name	parent_last_name
Marge	Wellington	1	Rosa	Wellington
Joni	Wellington	1	Rosa	Wellington
Jon	Wellington	1	Rosa	Wellington
Frank	Wellington	2	Jon	Wellington
Mary	Dijkstra	2	Jon	Wellington
Jason	Wellington	2	Joni	Wellington
Sarah	Wellington	2	Marge	Wellington
Sammy	Wellington	2	Marge	Wellington
Bobby	Wellington	2	Marge	Wellington
Sam Francis	Dijkstra	3	Mary	Dijkstra
Trent	Wellington	3	Frank	Wellington
Stephen	Wellington	3	Frank	Wellington
Suzy	Wellington	3	Sammy	Wellington
Josephine	Wellington	3	Sammy	Wellington
June	Wellington	3	Sammy	Wellington

Ou bien est-ce le cas ? Bien sûr, elle affiche chaque enfant et le nom de son parent. Mais Rosa Wellington, le nœud racine et la matriarche de cette famille, est absente. Et je n'ai appliqué aucun filtre pour l'exclure.

Que s'est-il passé ? En fait, j'ai appliqué un filtre en utilisant JOIN dans la dernière instruction SELECT. N'oubliez pas que JOIN ne renvoie que les lignes correspondantes des tables jointes. Rosa Wellington est absente parce qu'elle n'a pas de données sur son parent ; dans son cas, il n'y a pas de données où id peut correspondre à parent_id. Si vous souhaitez l'inclure également, utilisez le LEFT JOIN dans le dernier SELECT:
…
FROM generation g LEFT JOIN parent_child parent ON g.parent_id = parent.id
…

Le résultat complet se trouve ici :
child_first_name	child_last_name	generation_number	parent_first_name	parent_last_name
Rosa	Wellington	0	NULL	NULL
Joni	Wellington	1	Rosa	Wellington
Jon	Wellington	1	Rosa	Wellington
Marge	Wellington	1	Rosa	Wellington
Mary	Dijkstra	2	Jon	Wellington
Jason	Wellington	2	Joni	Wellington
Sarah	Wellington	2	Marge	Wellington
Sammy	Wellington	2	Marge	Wellington
Bobby	Wellington	2	Marge	Wellington
Frank	Wellington	2	Jon	Wellington
Trent	Wellington	3	Frank	Wellington
Stephen	Wellington	3	Frank	Wellington
Suzy	Wellington	3	Sammy	Wellington
Josephine	Wellington	3	Sammy	Wellington
June	Wellington	3	Sammy	Wellington
Sam Francis	Dijkstra	3	Mary	Dijkstra

Si vous souhaitez en savoir plus sur cette requête complexe, voici un article consacré à cet exemple.
Exemple 5 : Générer une vue arborescente de données hiérarchiques

Le dernier exemple est le plus complexe, mais aussi le plus amusant. Du moins, son résultat l'est. Il serait dommage d'interroger des structures arborescentes sans pouvoir afficher les données sous la forme d'une sorte d'arbre.

Ici, il s'agit d'afficher chaque personne du tableau. De plus, chaque descendant doit être représenté de manière à ce qu'il soit graphiquement évident de savoir de quel enfant il s'agit et à quelle génération il appartient. Il s'agit d'une vue arborescente. Je pense qu'il est préférable que vous attendiez que je passe à la sortie de la requête pour voir ce que je veux dire par là.

Au travail ! Une fois de plus, l'ETC récursif nous sauve la mise :
WITH RECURSIVE tree_view AS (
    SELECT id,
         parent_id,
         first_name,
         last_name,
         0 AS level,
         CAST(id AS varchar(50)) AS order_sequence
    FROM parent_child
    WHERE parent_id IS NULL
     
UNION ALL
 
    SELECT parent.id,
         parent.parent_id,
         parent.first_name,
         parent.last_name,
         level + 1 AS level,
         CAST(order_sequence || '_' || CAST(parent.id AS VARCHAR (50)) AS VARCHAR(50)) AS order_sequence
    FROM parent_child parent
    JOIN tree_view tv
      ON parent.parent_id = tv.id
)
 
SELECT
   RIGHT('------------',level*3) || first_name || ' ' || last_name
     AS parent_child_tree
FROM tree_view
ORDER BY order_sequence;

Vous savez déjà comment fonctionnent les requêtes récursives. Cette fois-ci, l'ETC s'appelle tree_view. La première instruction SELECT sélectionne des données dans la table où parent_id est NULL. Il y a la colonne level avec la valeur 0. J'ai utilisé la fonction CAST() pour changer le type de données id en VARCHAR ; vous verrez pourquoi j'en ai besoin.

Nous utilisons à nouveau UNION ALL pour fusionner les résultats de deux requêtes. La deuxième instruction SELECT sélectionne à nouveau des données, avec la table parent_child jointe à l'ETC lui-même. Ce qui est important, c'est qu'à chaque récursion, 1 sera ajouté au niveau précédent. De plus, le trait de soulignement et la valeur de la colonne id seront ajoutés à chaque récursion. J'ai besoin de cette petite astuce parce que j'utiliserai cette colonne plus tard pour trier la sortie. De cette façon, j'afficherai l'arborescence correctement. Pour vous assurer que vous avez bien compris, voici une ligne du tableau :
id	first_name	last_name	parent_id	order_sequence
1	Rosa	Wellington	NULL	1
2	Jon	Wellington	1	1_2
6	Frank	Wellington	2	1_2_6

La valeur de la colonne pour Frank Wellington sera 1_2_6. Pourquoi ? Parce que Rosa, en tant que premier niveau, obtient la valeur 1. Jon Wellington est son fils ; son numéro d'identification est inscrit à l'adresse order_sequence, qui devient 1_2. L'identifiant de Frank est ensuite ajouté et devient 1_2_6. En procédant ainsi dans toute la structure hiérarchique, j'obtiens la colonne que je peux utiliser pour afficher le résultat de la manière souhaitée.

Revenons à la requête. Pour obtenir le résultat, vous avez besoin d'une adresse SELECT qui utilise les données de l'ETC. J'utilise ici la fonction RIGHT(). Elle extrait un nombre spécifié de caractères de la droite. Dans mon cas, elle supprime le nombre de tirets du niveau*3 pour chaque niveau. J'ai également concaténé ces tirets avec le nom et le prénom. Le résultat est trié par order_sequence.

Êtes-vous prêt à voir l'arborescence ? La voici :
parent_child_tree
Rosa Wellington
---Jon Wellington
------Mary Dijkstra
---------Sam Francis Dijkstra
------Frank Wellington
---------Stephen Wellington
---------Trent Wellington
---Joni Wellington
------Jason Wellington
---Marge Wellington
------Sarah Wellington
------Bobby Wellington
------Sammy Wellington
---------June Wellington
---------Josephine Wellington
---------Suzy Wellington

Cette représentation graphique simple montre clairement les niveaux générationnels et qui est qui dans cet arbre généalogique. Par le nombre de tirets, vous pouvez facilement voir que Jon, Joni et Marge Wellington sont les enfants de Rosa. Mary Dijkstra, Frank, Jason, Sarah, Bobby et Sammy Wellington sont les petits-enfants de Rosa. Il est également facile de voir qui sont leurs parents. Vous pouvez également voir qui sont les arrière-petits-enfants, mais je vous laisse le soin de le faire.

Avant de terminer, j'aimerais également vous recommander cet article sur le fonctionnement de l'interrogation des structures arborescentes dans Oracle.
L'interrogation des arbres parents-enfants devient de plus en plus intéressante

Les arborescences parents-enfants sont très intéressantes. Il s'agit d'un ensemble de données complètement différent de celui que vous interrogez habituellement dans les bases de données relationnelles. Je vous ai montré ce que sont ces structures hiérarchiques et comment elles sont représentées dans une table.

Plus important encore, je vous ai montré cinq requêtes que vous pouvez utiliser pour résoudre certains des problèmes les plus courants concernant les données hiérarchiques. Comme vous l'avez vu, les ETC et les ETC récursifs sont essentiels pour interroger les arbres parents-enfants.

Si vous aimez apprendre SQL à l'aide d'exercices pratiques, vous devez essayer LearnSQL.fr.

Je suis sûr que vous avez déjà rencontré des données hiérarchiques dans le cadre de votre travail. Vous avez probablement réalisé que vous deviez vous équiper de connaissances approfondies en matière de requêtes récursives pour traiter ce type de données. Nous avons un coursRequêtes récursives qui vous guidera systématiquement à travers les ETC en général, les requêtes récursives et la façon dont les requêtes sur les données hiérarchiques et les graphiques fonctionnent en SQL.

Bonne chance dans votre apprentissage ! Et n'hésitez pas à utiliser toutes les requêtes que je vous ai montrées et à les adapter à vos besoins professionnels.
