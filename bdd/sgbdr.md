---
title: Système de gestion de bases de données relationnelles
---

Les bases de données relationnelles sont un élément clé de la gestion de données dans de nombreuses applications informatiques. Elles fournissent une structure organisée pour stocker, gérer et récupérer des informations. 

### Qu'est-ce qu'une base de données relationnelle ?

Une base de données relationnelle est une collection de données structurées, organisées en tables. Chaque table est composée de lignes (enregistrements) et de colonnes (champs). Chaque ligne représente une entité unique, comme un client, un produit ou une commande, tandis que chaque colonne représente un attribut de ces entités.

### Terminologie clé

- **Table :** Une structure qui stocke des données sous forme de lignes et de colonnes.
- **Ligne :** Aussi appelée enregistrement ou entrée, elle représente une instance spécifique d'une entité (par exemple, un client).
- **Colonne :** Aussi appelée champ, elle représente un attribut spécifique des entités (par exemple, le nom ou l'âge d'un client).
- **Clé primaire :** Une colonne (ou un groupe de colonnes) qui identifie de manière unique chaque enregistrement dans une table.
- **Clé étrangère :** Une colonne dans une table qui établit une relation avec la clé primaire d'une autre table, créant ainsi un lien entre les tables.

### Exemple

Prenons un exemple simple d'une base de données relationnelle pour une librairie :

**Table "Livres" :**

| ID | Titre            | Auteur         | Année |
|----|------------------|----------------|-------|
| 1  | Fondation        | Isaac Asimov   | 1951  |
| 2  | 1984             | George Orwell  | 1949  |
| 3  | Le Seigneur des Anneaux | J.R.R. Tolkien | 1954 |

**Table "Emprunts" :**

| ID | LivreID | Emprunteur   | Date       |
|----|---------|--------------|------------|
| 1  | 2       | Alice Dupont | 2023-05-15 |
| 2  | 1       | Marc Martin  | 2023-06-02 |

Ici, la table "Emprunts" a une clé étrangère "LivreID" qui est liée à la clé primaire "ID" de la table "Livres", établissant une relation entre les deux tables.

### Avantages des bases de données relationnelles

- **Structure organisée :** Les données sont organisées en tables, ce qui permet une gestion efficace.
- **Relations :** Les bases de données relationnelles peuvent gérer des relations entre différentes entités, assurant l'intégrité des données.
- **Flexibilité :** Les requêtes SQL (Structured Query Language) permettent de récupérer des données complexes en utilisant des jointures, des filtrages et des regroupements.
- **Sécurité :** Les systèmes de gestion de bases de données (SGBD) offrent des mécanismes de contrôle d'accès pour protéger les données sensibles.

En résumé, les bases de données relationnelles offrent une manière robuste et efficace de stocker et gérer des données dans une variété d'applications, allant des systèmes d'inventaire aux applications bancaires en passant par les sites web dynamiques.

## Schéma entité-relation (ER)

Un schéma entité-relation (ER) est un modèle de données utilisé en conception de bases de données pour représenter la structure et les relations entre les données. Il est particulièrement utile pour décrire comment les entités (c'est-à-dire les objets, les concepts ou les éléments du monde réel) interagissent les unes avec les autres au sein d'un système d'information. Le schéma entité-relation repose sur deux principaux composants : les entités et les relations.

Voici une explication plus détaillée des composants du schéma entité-relation :

### Entités

Les entités représentent des objets, des concepts ou des éléments du monde réel qui sont importants pour le système d'information. Par exemple, dans un système de gestion de bibliothèque, les entités pourraient être "Livres", "Auteurs", "Emprunteurs" et "Bibliothèques". Chaque entité est décrite par un ensemble d'attributs qui capturent ses caractéristiques. Par exemple, l'entité "Livres" pourrait avoir des attributs tels que "Titre", "Auteur", "Année de publication" et "ISBN".

### Relations

Les relations représentent les liens et les interactions entre les entités. Elles décrivent comment les entités sont connectées les unes aux autres. Par exemple, une relation "Emprunt" pourrait lier l'entité "Livres" à l'entité "Emprunteurs" pour indiquer qu'un emprunteur a emprunté un livre à une certaine date. Les relations peuvent avoir des attributs qui décrivent davantage les détails de l'interaction.

###  Cardinalité

La cardinalité d'une relation définit combien d'entités d'un côté de la relation sont associées à combien d'entités de l'autre côté. Par exemple, une relation "Un à Un" signifie qu'une entité d'un côté est associée à une entité de l'autre côté, tandis qu'une relation "Un à Plusieurs" signifie qu'une entité d'un côté est associée à plusieurs entités de l'autre côté.

### Modèle conceptuel

Le schéma entité-relation est souvent considéré comme un modèle conceptuel, car il se concentre sur la représentation abstraite des données et de leurs relations sans se préoccuper des détails d'implémentation. Il s'agit d'une étape importante dans la conception d'une base de données, car elle permet de visualiser la structure des données et les interactions entre elles avant de passer à la création physique de la base de données.

Une fois le schéma entité-relation créé, il peut servir de base pour la conception et la création de la base de données réelle à l'aide d'un système de gestion de base de données (SGBD) tel que MySQL, PostgreSQL, Oracle Database, etc. Le schéma entité-relation est un outil précieux pour communiquer avec les parties prenantes du projet, comprendre les besoins en matière de données et s'assurer que la base de données est conçue de manière appropriée pour prendre en charge les opérations et les requêtes requises.

### Formes normales

Les formes normales sont des règles ou des critères utilisés dans la conception de bases de données relationnelles pour organiser les données de manière à réduire la redondance et améliorer l'intégrité des données. Elles permettent de structurer une base de données de façon à minimiser les anomalies de mise à jour, d'insertion et de suppression. Il existe plusieurs formes normales, chacune apportant des améliorations spécifiques par rapport à la précédente. 

#### 1NF Première forme normale

La première forme normale impose les conditions suivantes :

- **Atomicité** : Chaque colonne d'une table doit contenir des valeurs atomiques, c'est-à-dire indivisibles. Par exemple, une colonne ne doit pas contenir une liste de valeurs ou une valeur composite.
- **Absence de répétition** : Les enregistrements doivent être uniques, et chaque colonne doit contenir un seul type de données.

|Immatriculation | Modèle  | Caractéristiques
|----------------|---------|--------------
| TT-802-AX      | Nissan  | 4 roues motrices, ABS, toit ouvrant, peinture verte, 65 l, 140 cv
| QS-123-DB      | Peugeot | jantes aluminium, peinture bleu, 50 l, 110 cv

| ID | Produit       | Ingrédients      
|----|---------------|--------------
| 1  | Sun Secure    | octocrylène, dioxyde de titane 
| 2  | UV Screen     | acide para-aminobenzoïque, taurate copolymer, ceteareth-20 

#### 2NF Deuxième forme normale

La deuxième forme normale est basée sur la première et ajoute les conditions suivantes :

- **Dépendance fonctionnelle totale** : Tous les attributs non clés doivent dépendre **entièrement** de la clé primaire. En d'autres termes, il ne doit pas y avoir de dépendances partielles entre les colonnes. Si une colonne dépend seulement d'une partie de la clé primaire (dans le cas où celle-ci est composée), la table n'est pas en 2NF.

| N° Commande | N° Produit | NomClient | AdresseClient      | Quantité
|-------------|------------|-----------|--------------------|---------
| 1	          | 101        | Dupont    | 10 rue du Marché   | 	2
| 1	          | 102        | Dupont    | 10 rue du Marché   | 	1
| 2	          | 103        | Martin    | 22 avenue de Paris | 	5
| 3	          | 102        | Grosjean  | 10 place Bleue     | 	3

La clé primaire de la table est composée de CommandeID et ProduitID

NomClient et AdresseClient dépendent uniquement de CommandeID, ce qui signifie qu'ils ne dépendent pas entièrement de la clé primaire composée (CommandeID, ProduitID). Ils dépendent seulement de la partie CommandeID.

#### 3NF Troisième forme normale

La troisième forme normale repose sur la deuxième et impose :

- **Absence de dépendance transitive** : Aucune colonne non clé ne doit dépendre d'une autre colonne non clé. Autrement dit, chaque colonne non clé doit dépendre directement de la clé primaire.

|EmployéID	  | NomEmployé	| Poste	    | Salaire	| DépartementID |	NomDépartement
|-------------|-------------|-----------|---------|---------------|---------------
|1|	Dupont|	Ingénieur|	60000	|101	|Informatique
|2|	Martin|	Chef de projet|	75000	|102|	Gestion
|3|	Durand|	Technicien|	45000	|101|	Informatique

Dans cette table, l'attribut NomDépartement dépend de DépartementID, qui lui-même dépend de EmployéID. Cette situation crée une dépendance transitive : EmployéID → DépartementID → NomDépartement. Par conséquent, la table ne respecte pas la 3NF, car NomDépartement dépend indirectement de la clé primaire EmployéID via une autre colonne non clé (DépartementID).

#### BCNF Forme normale de Boyce-Codd

La forme normale de Boyce-Codd est une extension de la 3NF et traite certains cas particuliers où la 3NF ne suffit pas. Elle impose :

- **Dépendance fonctionnelle stricte** : Pour chaque dépendance fonctionnelle, l'ensemble des attributs sur lequel une colonne dépend doit être une super-clé de la table.

#### 4NF Quatrième forme normale

La quatrième forme normale traite des dépendances multivaluées :

- **Aucune dépendance multivaluée** : Si un attribut dans une table dépend de la clé primaire, il ne doit pas y avoir de dépendance entre cet attribut et un autre ensemble d'attributs indépendant.

#### 5NF Cinquième forme normale

La cinquième forme normale traite de la décomposition en respectant les jointures :

- **Aucune dépendance de jointure** : Une table doit être décomposable en plus petites tables sans perte d'informations lors des jointures.

#### 6NF Sixième forme normale

La sixième forme normale, rarement utilisée, est destinée aux bases de données temporelles et impose une décomposition encore plus fine pour gérer les variations dans le temps.
