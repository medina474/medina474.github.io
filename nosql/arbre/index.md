---
title: Arbres
---


En théorie des graphes, un **arbre** est un type de graphe particulier qui possède les propriétés suivantes :

1. **Connexité** : Un arbre est un graphe connexe, c'est-à-dire qu'il existe un chemin entre chaque paire de sommets.

2. **Acyclicité** : Un arbre ne contient aucun cycle, c'est-à-dire qu'il n'y a pas de chemin fermé dans lequel on peut revenir au même sommet sans retraverser une arête.

3. **Nombre de sommets et d'arêtes** : Pour un graphe avec \( n \) sommets, un arbre possède exactement \( n - 1 \) arêtes.

Les propriétés ci-dessus impliquent que tout arbre est un graphe connexe minimal (on ne peut pas retirer une arête sans rendre le graphe déconnecté) et un graphe acyclique maximal (ajouter une arête créerait un cycle).

Voici quelques concepts et propriétés additionnelles liées aux arbres :

- **Arbre enraciné (ou arbre racinaire)** : Un arbre avec un sommet désigné appelé "racine". Ce type d'arbre a une hiérarchie et on peut parler de parent, enfant, ancêtre, descendant, etc.

- **Feuille** : Un sommet d'un arbre qui a un degré (nombre d'arêtes incidentes) de 1.

- **Arbre binaire** : Un arbre enraciné dans lequel chaque sommet a au plus deux enfants.

Les arbres sont des structures fondamentales en informatique et en mathématiques discrètes, utilisés dans de nombreuses applications comme les structures de données (par exemple, les arbres binaires de recherche, les tas), les algorithmes de recherche et de tri, et bien plus encore.

Arbre orienté

Avez-vous déjà travaillé avec des données hiérarchiques ? Je parie que oui, même si vous ne savez pas encore ce que cela signifie. Dans le contexte des bases de données SQL, nous définissons le modèle de données hiérarchique comme un modèle dans lequel les données sont stockées sous forme d'arborescence, ce qui signifie que chaque enregistrement enfant n'a qu'un seul parent. Les hiérarchies de rôles dans l'entreprise, les structures de dossiers et les taxonomies (biologie) répondent toutes à cette définition. Le développeur doit résoudre quelques problèmes lorsqu'il travaille avec ces données dans des bases de données SGBDR. Dans le passé, il nous manquait des outils intégrés dans la plupart des serveurs SQL pour interroger efficacement les structures récursives qui sont naturellement utilisées pour représenter ces données. Quelle est la situation actuelle en 2024 dans PostgreSQL et quels modèles pouvons-nous utiliser ?

La liste des problèmes et des contiguïtés

Imaginez que nous ayons une structure semblable à un dossier. Nous devons stocker l'arborescence entière avec un nom de fichier et un type MIME dans une base de données relationnelle. La première opinion naturelle pour la modélisation SGBDR est d'utiliser une seule table avec une clé étrangère faisant référence à elle-même (parent_id). Cette approche simple est connue sous le nom de liste de contiguïté. 

L'utilisation de la liste de contiguïté est très simple. Nous pouvons ajouter un nouveau fichier dans un dossier avec une simple insertion dans la base de données, connaissant le parent_id. La suppression d'un dossier entier peut être réalisée en utilisant l' option CASCADE sur la clé étrangère. 

Le déplacement d'un dossier vers un autre peut être effectué avec simplement une mise à jour de la colonne parent_id. Le véritable défi vient des requêtes. Afficher le contenu d'un seul dossier est simple avec une seule instruction Where, mais disons que nous voulons avoir un fil d'Ariane sympa sur notre site Web qui affichera le chemin complet d'un dossier racine au fichier. Cela signifie que nous devons effectuer une requête qui obtiendra tous les ancêtres d'un fichier avec un ID donné. Avec un modèle de base de données de liste de contiguïté, nous devons effectuer une requête multi-jointure basée sur le nombre d'ancêtres de l'élément. C'est là que les anciens systèmes de bases de données atteignaient une limite car il n'existait pas de moyen simple d'effectuer cette requête avec du SQL standard. PostgreSQL à partir de la version 8.2 propose des requêtes récursives qui peuvent être utilisées pour y parvenir. La requête pour notre modèle de base de données peut ressembler à ceci :

WITH RECURSIVE folders AS (
   SELECT *, 0 AS "depth"
   SELECT *, 0 AS "depth"
       FROM files
       WHERE id = :id
   UNION;
   SELECT parents.*, folders."depth" + 1 AS "depth"
       FROM folders
       JOIN files parents ON (folders.parent_id = parents.id)
) SELECT * FROM folders ORDER BY "depth" DESC;

PostgreSQL remplacera à plusieurs reprises notre expression de recherche dans la première union par le nouveau résultat et réalisera l'union de tous les résultats à la fin. En théorie, cela signifie toujours que la base de données utilise plusieurs opérations de jointure et d'union pour récupérer ces résultats. Cela peut poser un problème dans un grand ensemble de données comportant des centaines de lignes imbriquées. PostgreSQL essaie d'optimiser ces requêtes autant que possible, mais il existe encore des approches de modélisation plus efficaces que vous pouvez adopter au cas où les requêtes ancêtres et descendants (recherche de tous les enfants du fichier x) seraient votre application principale.

Lorsque l’indexation dans un SGBDR ne fournit pas de résultats satisfaisants, la solution dominante de nos jours est la duplication de données. Cette approche est également possible avec la modélisation hiérarchique des données. Nous pouvons créer un champ calculé pour chaque nœud qui nous donnera tous les parents et le réaliser avec un déclencheur, mais la solution générale peut être obtenue avec une « table de clôture ».

Ce tableau doit concerner toutes les relations de l’arborescence, y compris la profondeur de la relation. Nous stockerons non seulement les relations directes parent-enfant, mais toutes dans un seul arbre. Par exemple, pour qu'un fichier « C » soit dans un dossier « B » qui se trouve dans un dossier « A », nous devons stocker ces relations :

Vous pouvez imaginer que l'espace requis pour stocker la table de fermeture augmentera rapidement à chaque niveau supplémentaire de l'arbre. Cela entraîne également un impact négatif important sur les requêtes de modification de données avec des index sur des clés étrangères. Le gros avantage de cette approche réside dans les performances optimales des requêtes basées sur les ancêtres, les descendants et les niveaux. La requête pour notre fichier fil d'Ariane peut ressembler à ceci :

SELECT folders.*, fc."depth"
FROM files folders 
JOIN files_folders fc ON folders.id = fc.parent_id
WHERE fc.child_id = :id 
ORDER BY fc."depth" DESC;

Chemin matérialisé

Avez-vous déjà travaillé avec des fournisseurs de stockage de fichiers cloud comme Google Storage ou AWS S3 ? Alors vous savez probablement que la plupart d’entre eux utilisent des préfixes de chaîne de base pour stocker les informations sur les dossiers, mais physiquement, tous vos fichiers sont stockés au même endroit. C'est une autre approche de modélisation que vous pouvez utiliser lorsque vous travaillez avec des données hiérarchiques. Au lieu d'utiliser la clé étrangère parent_id comme dans la liste de contiguïté, nous stockerons la chaîne représentant le chemin vers ce nœud.

Cela ne nous garantira pas à lui seul une amélioration des performances par rapport à la liste de contiguïté. Nous devons introduire une indexation supplémentaire pour effectuer des requêtes efficaces. Le type d'extension PostgreSQL ltree nous aidera avec cela. En plus de bonnes performances, nous recevrons également une puissance de requête supplémentaire, qui ne se limite pas uniquement aux ancêtres et descendants utilisant lquery. Jetons un coup d'œil à la requête pour notre fil d'Ariane :

SELECT * FROM files WHERE path @> (
   SELECT path FROM file WHERE id = :id
) ORDER BY path;

Cela semble élégant, mais le principal problème de cette modélisation dans PostgreSQL est que l' index GIST utilisé pour ltree nécessite une limitation de taille , nous ne pouvons donc pas l'utiliser pour des arbres vraiment imbriqués. Le déplacement d'un sous-arbre dans un autre est également plus complexe puisqu'il faut mettre à jour tout l'intérieur du dossier.

Ensemble imbriqué et intervalles

La dernière approche dont nous devrions discuter est le modèle d’ensembles imbriqués. Il est basé sur le principe du parcours d’arbres. Nous commençons au nœud racine de l’arbre et allons au nœud feuille le plus à gauche. Une fois que nous l'atteignons, nous revenons en arrière jusqu'à ce que nous atteignions un nœud qui a plusieurs enfants, passons au prochain enfant non visité le plus à gauche et répétons le processus jusqu'à ce que nous visitions tous les nœuds. Comptons toutes les visites des nœuds de l'arborescence dans chaque magasin de nœuds, ce compte deux fois :

    Gauche : Le décompte lorsque nous visitons le nœud pour la première fois (en descendant)
    À droite : Le décompte lorsque nous visitons le nœud pour la dernière fois (en hausse)

Ce processus est illustré dans l'image ci-dessous.

Ces nombres peuvent être utilisés pour effectuer très efficacement des requêtes sur les descendants et les ancêtres sans augmenter considérablement la taille de la base de données. Nous avons juste besoin de connaître les valeurs de gauche et de droite.


/ Descendants
SELECT * FROM files WHERE
"left" > :left AND WHERE "right" < :right
// Ancestors
SELECT * FROM files WHERE
"left" < :left AND "right" > :right

Cette solution suppose que nous n'avons qu'un seul arbre dans notre base de données. Nous pouvons également stocker un identifiant du nœud racine dans tous les enfants pour nous assurer que nous prenons uniquement les nœuds de la bonne arborescence. Ce champ peut également être utile dans différentes requêtes (par exemple trouver la racine du nœud actuel).

Nous avons obtenu de très bonnes performances en matière d'ancêtres, mais nous avons perdu les options permettant d'interroger les ancêtres directs et les descendants directs, ce qui signifie que nous avons un fil d'Ariane rapide, mais nous ne sommes pas en mesure d'afficher simplement le contenu d'un seul dossier. Nous avons également augmenté la complexité des opérations d'insertion, de suppression et de déplacement car nous devons recalculer tous les nombres de droite et de gauche dans les sous-arbres de droite du même arbre. Cette opération peut être coûteuse, mais il existe des moyens de recalculer toutes les valeurs assez rapidement, certains d'entre eux sont mentionnés dans le blog Hierarchies on Steroids #1 de Jeff Moden.

La solution pour les requêtes de modification est l'utilisation d'intervalles au lieu d'entiers pour les valeurs gauche et droite. Nous pouvons simplement insérer le nœud dans le sous-arbre en utilisant des décimales. La solution simple utilisant la réduction de moitié des valeurs gauche et droite peut échouer très rapidement et durement en termes de précision décimale, c'est pourquoi il existe plusieurs approches pour coder les intervalles imbriqués. Si vous êtes curieux de connaître certaines des méthodes de base, je peux vous recommander de lire Nested Intervals Tree Encoding in SQL par Vadim Tropashko .

Résumé

Il existe plusieurs façons de modéliser des données hiérarchiques dans SQL. PostgreSQL prend en charge la plupart d'entre eux. Une bonne recommandation est de toujours commencer par la solution de liste de contiguïté car elle est simple, peu encombrante et peut être facilement combinée avec toute autre solution mentionnée ci-dessus. Les solutions de table de fermeture et de chemin matérialisé offrent de bonnes performances et également une utilisation supplémentaire avec plus que de simples requêtes ancêtres et descendants, mais ce ne sont que des avantages que vous paierez avec les limitations de la taille de l'arborescence.

Si vous rencontrez des difficultés pour interroger votre grand ensemble de données hiérarchiques avec des sous-arbres profonds pour les descendants et les ancêtres, n'oubliez jamais les solutions d'ensembles imbriqués et d'intervalles imbriqués. Nous pouvons les utiliser simplement comme index pour les requêtes puisque les besoins en espace sont équivalents à la solution de liste de contiguïté et nous pouvons les reconstruire rapidement. La liste de contiguïté peut prendre le reste du travail à votre place.

https://www.ackee.agency/blog/hierarchical-models-in-postgresql

En informatique, l'imbrication d'ensembles, nested sets en anglais, est une technique pour représenter des données hiérarchisées dans une base de données relationnelle. En substance, elle consiste à attribuer à chaque nœud deux bornes, dite gauche et droite, qui permettent de statuer sur les liens de parentés entre les différents nœuds. 

L'utilisation d'une approche de parcours récursif pour représenter des structures hiérarchiques comme l'arbre de Calkin-Wilf dans une base de données relationnelle présente plusieurs avantages et inconvénients par rapport à l'approche des ensembles imbriqués (nested sets).

### Avantages de la méthode récursive (modèle parent-enfant)

1. **Simplicité de mise à jour** :
   - **Insertion de nœuds** : Ajouter un nouveau nœud est simple, il suffit de spécifier son parent.
   - **Suppression de nœuds** : Supprimer un nœud et ses descendants directs est également simple, car chaque nœud connaît son parent.
   - **Déplacement de nœuds** : Changer la position d’un nœud dans l’arbre en modifiant simplement sa référence parentale est également relativement simple.

2. **Facilité de compréhension** :
   - Le modèle est intuitif et facile à comprendre. Chaque nœud a une référence à son parent direct, ce qui correspond bien à la manière dont les gens pensent des hiérarchies.

3. **Souplesse** :
   - Les modifications de la hiérarchie peuvent être réalisées sans nécessiter de recalculer les valeurs de gauche et de droite pour l’ensemble des nœuds comme dans le modèle des ensembles imbriqués.

### Inconvénients de la méthode récursive

1. **Performances de lecture** :
   - Les requêtes pour récupérer tous les descendants ou pour déterminer la profondeur peuvent être moins performantes, nécessitant des requêtes récursives qui peuvent devenir coûteuses en termes de temps d'exécution et de ressources.

### Avantages du modèle des ensembles imbriqués (nested sets)

1. **Performances de lecture** :
   - Les requêtes pour récupérer tous les descendants d’un nœud sont très efficaces et peuvent être effectuées avec une seule requête SQL sans récursion.
   - Les requêtes pour déterminer la profondeur et la position d’un nœud dans la hiérarchie sont également très efficaces.

2. **Représentation compacte** :
   - Le modèle des ensembles imbriqués permet une représentation compacte et ordonnée des hiérarchies, facilitant certaines opérations de lecture et de reporting.

### Inconvénients du modèle des ensembles imbriqués

1. **Complexité de mise à jour** :
   - Ajouter, supprimer ou déplacer des nœuds nécessite souvent des mises à jour complexes et coûteuses des valeurs de gauche et de droite pour de nombreux nœuds.
   - Ces opérations peuvent devenir inefficaces et complexes à gérer, en particulier pour les grandes hiérarchies avec des mises à jour fréquentes.

### Conclusion

Le choix entre utiliser une méthode récursive ou un modèle des ensembles imbriqués dépend des exigences spécifiques de votre application :

- **Utilisez la méthode récursive (modèle parent-enfant)** si :
  - Les mises à jour (ajout, suppression, déplacement de nœuds) sont fréquentes.
  - La hiérarchie est relativement simple ou peu profonde.
  - Vous préférez une solution plus intuitive et facile à comprendre.

- **Utilisez le modèle des ensembles imbriqués** si :
  - Les lectures et les requêtes hiérarchiques sont fréquentes et doivent être très performantes.
  - La hiérarchie est relativement stable et ne nécessite pas de mises à jour fréquentes.
  - Vous avez besoin de requêtes efficaces pour récupérer des sous-arbres entiers ou pour effectuer des analyses complexes de la hiérarchie.

### Exemple de requête efficace avec les ensembles imbriqués

Pour illustrer l'efficacité des lectures avec les ensembles imbriqués, voici comment vous pouvez récupérer tous les enfants d'un nœud donné :

```sql
SELECT * FROM nested_sets
WHERE left_value BETWEEN parent_left_value AND parent_right_value;
```

Cette requête est très rapide car elle utilise une seule opération de comparaison sur les valeurs de gauche et de droite, ce qui est souvent beaucoup plus performant que les requêtes récursives nécessaires avec le modèle parent-enfant.

En fin de compte, le choix de la méthode dépend des besoins spécifiques de votre application en termes de performances de lecture et de mise à jour, de complexité et de facilité de gestion.
