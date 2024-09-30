---
title: Système de gestion de bases de données relationnelles
---

Les bases de données relationnelles sont un élément clé de la gestion de données dans de nombreuses applications informatiques. Elles fournissent une structure organisée pour stocker, gérer et récupérer des informations. 

### Qu'est-ce qu'une base de données relationnelle ?

> Une base de données relationnelle est une collection de données structurées, organisées en tables. Chaque table est composée de lignes (enregistrements) et de colonnes (champs). Chaque ligne représente une entité unique, comme un client, un produit ou une commande, tandis que chaque colonne représente un attribut de ces entités.
{.definition}

### Terminologie clé

- **Table :** Une structure qui stocke des données sous forme de lignes et de colonnes.
- **Ligne :** Aussi appelée enregistrement ou entrée, elle représente une instance spécifique d'une entité (par exemple, un client).
- **Colonne :** Aussi appelée champ, elle représente un attribut spécifique des entités (par exemple, le nom ou l'âge d'un client).
- **Clé primaire :** Une colonne (ou un groupe de colonnes) qui identifie de manière **unique** chaque enregistrement dans une table.
- **Clé étrangère :** Une colonne dans une table qui établit une relation avec la clé primaire d'une autre table, créant ainsi un lien entre les tables.

### Exemple

Prenons un exemple simple d'une base de données relationnelle pour une librairie :

**Table "Livres" :**

| ID | Titre                  | Auteur         | Année |
|----|------------------------|----------------|------:|
| 1  | La planète des singes  | Pierre Boulle  | 1963  |
| 2  | 1984                   | George Orwell  | 1949  |
| 3  | Le meilleur des mondes | Aldous Huxley  | 1932  |

**Table "Emprunts" :**

| ID | LivreID | Emprunteur   | Date       |
|----|---------|--------------|------------|
| 1  | 2       | Alice Dupont | 2024-05-15 |
| 2  | 1       | Marc Martin  | 2024-06-02 |

Ici, la table "Emprunts" a une clé étrangère "LivreID" qui est liée à la clé primaire "ID" de la table "Livres", établissant une relation entre les deux tables.

### Avantages des bases de données relationnelles

- **Structure organisée :** Les données sont organisées en tables, ce qui permet une gestion efficace.
- **Relations :** Les bases de données relationnelles peuvent gérer des **relations** entre différentes entités, assurant l'intégrité des données.
- **Flexibilité :** Les requêtes SQL (Structured Query Language) permettent de récupérer des données complexes en utilisant des jointures, des filtrages et des regroupements.
- **Sécurité :** Les systèmes de gestion de bases de données (SGBD) offrent des mécanismes de contrôle d'accès pour protéger les données sensibles.

En résumé, les bases de données relationnelles offrent une manière robuste et efficace de stocker et gérer des données dans une variété d'applications, allant des systèmes d'inventaire aux applications bancaires en passant par les sites web dynamiques.

## Schéma entité-relation (ER)

Un schéma entité-relation (ER) est un modèle de données utilisé en conception de bases de données pour représenter la structure et les relations entre les données. Il est particulièrement utile pour décrire comment les entités (c'est-à-dire les objets, les concepts ou les éléments du monde réel) interagissent les unes avec les autres au sein d'un système d'information. Le schéma entité-relation repose sur deux principaux composants : les entités et les relations.

### Entités

Les entités représentent des objets, des concepts ou des éléments du monde réel qui sont importants pour le système d'information. Par exemple, dans un système de gestion de bibliothèque, les entités pourraient être "Livres", "Auteurs", "Emprunteurs" et "Bibliothèques". Chaque entité est décrite par un ensemble d'attributs qui capturent ses caractéristiques. Par exemple, l'entité "Livres" pourrait avoir des attributs tels que "Titre", "Auteur", "Année de publication" et "ISBN".

### Relations

Les relations représentent les liens et les interactions entre les entités. Elles décrivent comment les entités sont connectées les unes aux autres. Par exemple, une relation "Emprunt" pourrait lier l'entité "Livres" à l'entité "Emprunteurs" pour indiquer qu'un emprunteur a emprunté un livre à une certaine date. Les relations peuvent avoir des attributs qui décrivent davantage les détails de l'interaction.

###  Cardinalité

La cardinalité d'une relation définit combien d'entités d'un côté de la relation sont associées à combien d'entités de l'autre côté. Par exemple, une relation "Un à Un" signifie qu'une entité d'un côté est associée à une entité de l'autre côté, tandis qu'une relation "Un à Plusieurs" signifie qu'une entité d'un côté est associée à plusieurs entités de l'autre côté.

### Modèle conceptuel

Le schéma entité-relation est souvent considéré comme un modèle conceptuel, car il se concentre sur la représentation abstraite des données et de leurs relations sans se préoccuper des détails d'implémentation. Il s'agit d'une étape importante dans la conception d'une base de données, car elle permet de visualiser la structure des données et les interactions entre elles avant de passer à la création physique de la base de données.

Une fois le schéma entité-relation créé, il peut servir de base pour la conception et la création de la base de données réelle à l'aide d'un système de gestion de base de données (SGBD) tel que MySQL, PostgreSQL, Oracle Database, etc. Le schéma entité-relation est un outil précieux pour communiquer avec les parties prenantes du projet, comprendre les besoins en matière de données et s'assurer que la base de données est conçue de manière appropriée pour prendre en charge les opérations et les requêtes requises.

<svg width="627" height="263" viewBox="0 0 700 280" xmlns="http://www.w3.org/2000/svg">

<!-- Association DIRIGER -->
<g>
	<line x1="205" y1="127" x2="205" y2="43" stroke="#66bd63" stroke-width="2"/>
	<line x1="325" y1="127" x2="205" y2="43" stroke="#66bd63" stroke-width="2"/>
	<g>
		<path d="M225 18 a14 14 90 0 1 14 14 V43 h-68 V32 a14 14 90 0 1 14 -14" fill="#a6d96a" stroke="#a6d96a" stroke-width="0"/>
		<path d="M239 43 v11 a14 14 90 0 1 -14 14 H185 a14 14 90 0 1 -14 -14 V43 H68" fill="#d9ef8b" stroke="#d9ef8b" stroke-width="0"/>
		<rect x="171" y="18" width="68" height="50" fill="none" rx="14" stroke="#66bd63" stroke-width="2"/>
		<line x1="171" y1="43" x2="239" y2="43" stroke="#66bd63" stroke-width="1"/>
		<text x="178" y="35.75" fill="#000000" font-family="Verdana" font-size="12">DIRIGER</text>
	</g>
	<text x="210" y="85" fill="#d73027" font-family="Verdana" font-size="12">0,N</text>
	<text x="258" y="109.97" fill="#d73027" font-family="Verdana" font-size="12">0,1</text>
</g>

<!-- Association REQUERIR -->
<g>
	<line x1="325" y1="127" x2="325" y2="43" stroke="#66bd63" stroke-width="2"/>
	<line x1="449" y1="43" x2="325" y2="43" stroke="#66bd63" stroke-width="2"/>
	<g>
		<path d="M353 18 a14 14 90 0 1 14 14 V43 h-84 V32 a14 14 90 0 1 14 -14" fill="#a6d96a" stroke="#a6d96a" stroke-width="0"/>
		<path d="M367 43 v11 a14 14 90 0 1 -14 14 H297 a14 14 90 0 1 -14 -14 V43 H84" fill="#d9ef8b" stroke="#d9ef8b" stroke-width="0"/>
		<rect x="283" y="18" width="84" height="50" fill="none" rx="14" stroke="#66bd63" stroke-width="2"/>
		<line x1="283" y1="43" x2="367" y2="43" stroke="#66bd63" stroke-width="1"/>
		<text x="293" y="35.75" fill="#000000" font-family="Verdana" font-size="12">REQUÉRIR</text>
		<text x="290" y="60.8" fill="#000000" font-family="Verdana" font-size="12">qté requise</text>
	</g>
	<text x="330" y="85" fill="#d73027" font-family="Verdana" font-size="12">1,N</text>
	<text x="381" y="60" fill="#d73027" font-family="Verdana" font-size="12">0,N</text>
</g>

<!-- Association COMPOSER -->
<g>
	<path d="M449 43 C483.67 9.67 525 9.67 573 43" fill="none" stroke="#66bd63" stroke-width="2"/>
	<path d="M449 43 C483.67 76.33 525 76.33 573 43" fill="none" stroke="#66bd63" stroke-width="2"/>
	<g>
		<path d="M601 18 a14 14 90 0 1 14 14 V43 h-84 V32 a14 14 90 0 1 14 -14" fill="#a6d96a" stroke="#a6d96a" stroke-width="0"/>
		<path d="M615 43 v11 a14 14 90 0 1 -14 14 H545 a14 14 90 0 1 -14 -14 V43 H84" fill="#d9ef8b" stroke="#d9ef8b" stroke-width="0"/>
		<rect x="531" y="18" width="84" height="50" fill="none" rx="14" stroke="#66bd63" stroke-width="2"/>
		<line x1="531" y1="43" x2="615" y2="43" stroke="#66bd63" stroke-width="1"/>
		<text x="538" y="35.75" fill="#000000" font-family="Verdana" font-size="12">COMPOSER</text>
		<text x="538" y="60.8" fill="#000000" font-family="Verdana" font-size="12">quantité</text>
	</g>
	<text x="495" y="37" fill="#d73027" font-family="Verdana" font-size="12">0,N</text>
	<text x="495" y="58" fill="#d73027" font-family="Verdana" font-size="12">0,N</text>
</g>

<!-- Association DF0 -->
<g>
	<line x1="71" y1="43" x2="71" y2="127" stroke="#66bd63" stroke-width="2"/>
	<line x1="205" y1="127" x2="71" y2="127" stroke="#66bd63" stroke-width="2"/>
	<g>
		<circle cx="71" cy="127" r="16" stroke="#66bd63" stroke-width="2" fill="#a6d96a"/>
		<text x="62" y="131" fill="#000000" font-family="Verdana" font-size="12">DF</text>
	</g>
	<text x="76" y="94" fill="#d73027" font-family="Verdana" font-size="12">1,1</text>
	<line x1="76" y1="96" x2="97" y2="96" stroke="#d73027" stroke-width="1"/>
	<text x="131" y="144" fill="#d73027" font-family="Verdana" font-size="12">0,N</text>
</g>

<!-- Association FOURNIR -->
<g>
	<line x1="325" y1="127" x2="449" y2="127" stroke="#66bd63" stroke-width="2"/>
	<line x1="449" y1="43" x2="449" y2="127" stroke="#66bd63" stroke-width="2"/>
	<line x1="449" y1="220" x2="449" y2="127" stroke="#66bd63" stroke-width="2"/>
	<g>
		<path d="M476 102 a14 14 90 0 1 14 14 V127 h-82 V116 a14 14 90 0 1 14 -14" fill="#a6d96a" stroke="#a6d96a" stroke-width="0"/>
		<path d="M490 127 v11 a14 14 90 0 1 -14 14 H422 a14 14 90 0 1 -14 -14 V127 H82" fill="#d9ef8b" stroke="#d9ef8b" stroke-width="0"/>
		<rect x="408" y="102" width="82" height="50" fill="none" rx="14" stroke="#66bd63" stroke-width="2"/>
		<line x1="408" y1="127" x2="490" y2="127" stroke="#66bd63" stroke-width="1"/>
		<text x="421" y="119.75" fill="#000000" font-family="Verdana" font-size="12">FOURNIR</text>
		<text x="415" y="144.8" fill="#000000" font-family="Verdana" font-size="12">qté fournie</text>
	</g>
	<text x="371" y="144" fill="#d73027" font-family="Verdana" font-size="12">1,N</text>
	<text x="454" y="94" fill="#d73027" font-family="Verdana" font-size="12">1,N</text>
	<text x="454" y="178" fill="#d73027" font-family="Verdana" font-size="12">1,N</text>
</g>

<!-- Association EMPLOYER -->
<g>
	<line x1="205" y1="127" x2="205" y2="220" stroke="#66bd63" stroke-width="2"/>
	<line x1="71" y1="220" x2="205" y2="220" stroke="#66bd63" stroke-width="2"/>
	<g>
		<path d="M231 195 a14 14 90 0 1 14 14 V220 h-80 V209 a14 14 90 0 1 14 -14" fill="#a6d96a" stroke="#a6d96a" stroke-width="0"/>
		<path d="M245 220 v11 a14 14 90 0 1 -14 14 H179 a14 14 90 0 1 -14 -14 V220 H80" fill="#d9ef8b" stroke="#d9ef8b" stroke-width="0"/>
		<rect x="165" y="195" width="80" height="50" fill="none" rx="14" stroke="#66bd63" stroke-width="2"/>
		<line x1="165" y1="220" x2="245" y2="220" stroke="#66bd63" stroke-width="1"/>
		<text x="173" y="212.75" fill="#000000" font-family="Verdana" font-size="12">EMPLOYER</text>
	</g>
	<text x="179" y="178" fill="#d73027" font-family="Verdana" font-size="12">1,1</text>
	<text x="138" y="237" fill="#d73027" font-family="Verdana" font-size="12">1,N</text>
</g>

<!-- Association TRAVAILLER -->
<g>
	<line x1="205" y1="127" x2="325" y2="220" stroke="#66bd63" stroke-width="2"/>
	<line x1="325" y1="127" x2="325" y2="220" stroke="#66bd63" stroke-width="2"/>
	<g>
		<path d="M356 195 a14 14 90 0 1 14 14 V220 h-90 V209 a14 14 90 0 1 14 -14" fill="#a6d96a" stroke="#a6d96a" stroke-width="0"/>
		<path d="M370 220 v11 a14 14 90 0 1 -14 14 H294 a14 14 90 0 1 -14 -14 V220 H90" fill="#d9ef8b" stroke="#d9ef8b" stroke-width="0"/>
		<rect x="280" y="195" width="90" height="50" fill="none" rx="14" stroke="#66bd63" stroke-width="2"/>
		<line x1="280" y1="220" x2="370" y2="220" stroke="#66bd63" stroke-width="1"/>
		<text x="287" y="212.75" fill="#000000" font-family="Verdana" font-size="12">TRAVAILLER</text>
	</g>
	<text x="227.68" y="178" fill="#d73027" font-family="Verdana" font-size="12">0,N</text>
	<text x="330" y="178" fill="#d73027" font-family="Verdana" font-size="12">1,N</text>
</g>

<!-- Association CONTROLER -->
<g>
	<path d="M449 220 C491.67 186.67 533 186.67 573 220" fill="none" stroke="#66bd63" stroke-width="2"/>
	<polygon points="528.0 196.68 515.02 200.08 520.17 195.03 517.5 188.33" fill="#66bd63" stroke-width="0"/>
	<path d="M449 220 C491 253.33 532.33 253.33 573 220" fill="none" stroke="#66bd63" stroke-width="2"/>
	<g>
		<path d="M604 195 a14 14 90 0 1 14 14 V220 h-90 V209 a14 14 90 0 1 14 -14" fill="#a6d96a" stroke="#a6d96a" stroke-width="0"/>
		<path d="M618 220 v11 a14 14 90 0 1 -14 14 H542 a14 14 90 0 1 -14 -14 V220 H90" fill="#d9ef8b" stroke="#d9ef8b" stroke-width="0"/>
		<rect x="528" y="195" width="90" height="50" fill="none" rx="14" stroke="#66bd63" stroke-width="2"/>
		<line x1="528" y1="220" x2="618" y2="220" stroke="#66bd63" stroke-width="1"/>
		<text x="535" y="212.75" fill="#000000" font-family="Verdana" font-size="12">CONTRÔLER</text>
	</g>
	<text x="501" y="214" fill="#d73027" font-family="Verdana" font-size="12">0,N</text>
	<text x="501" y="235" fill="#d73027" font-family="Verdana" font-size="12">0,1</text>
</g>

<!-- Entity AYANT_DROIT -->
<g>
	<g>
		<rect x="16" y="9" width="110" height="25" fill="#fdae61" stroke="none" stroke-width="0" opacity="1"/>
		<rect x="16" y="34" width="110" height="43" fill="#fee08b" stroke="none" stroke-width="0" opacity="1"/>
		<rect x="16" y="9" width="110" height="68" fill="none" stroke="#f46d43" stroke-width="2" opacity="1"/>
		<line x1="16" y1="34" x2="126" y2="34" stroke="#f46d43" stroke-width="1"/>
	</g>
	<text x="28" y="26.75" fill="#000000" font-family="Verdana" font-size="12">AYANT&#45;DROIT</text>
	<text x="21" y="51.8" fill="#000000" font-family="Verdana" font-size="12">nom ayant&#45;droit</text>
	<line x1="21" y1="54" x2="120" y2="54" stroke="#000000" stroke-width="1" stroke-dasharray="4"/>
	<text x="21" y="68.8" fill="#000000" font-family="Verdana" font-size="12">lien</text>
</g>

<!-- Entity PIECE -->
<g>
	<g>
		<rect x="408" y="9" width="82" height="25" fill="#fdae61" stroke="none" stroke-width="0" opacity="1"/>
		<rect x="408" y="34" width="82" height="43" fill="#fee08b" stroke="none" stroke-width="0" opacity="1"/>
		<rect x="408" y="9" width="82" height="68" fill="none" stroke="#f46d43" stroke-width="2" opacity="1"/>
		<line x1="408" y1="34" x2="490" y2="34" stroke="#f46d43" stroke-width="1"/>
	</g>
	<text x="431" y="26.75" fill="#000000" font-family="Verdana" font-size="12">PIÈCE</text>
	<text x="413" y="51.8" fill="#000000" font-family="Verdana" font-size="12">réf. pièce</text>
	<line x1="413" y1="54" x2="470" y2="54" stroke="#000000" stroke-width="1"/>
	<text x="413" y="68.8" fill="#000000" font-family="Verdana" font-size="12">libellé pièce</text>
</g>

<!-- Entity EMPLOYE -->
<g>
	<g>
		<rect x="158" y="93" width="94" height="25" fill="#fdae61" stroke="none" stroke-width="0" opacity="1"/>
		<rect x="158" y="118" width="94" height="43" fill="#fee08b" stroke="none" stroke-width="0" opacity="1"/>
		<rect x="158" y="93" width="94" height="68" fill="none" stroke="#f46d43" stroke-width="2" opacity="1"/>
		<line x1="158" y1="118" x2="252" y2="118" stroke="#f46d43" stroke-width="1"/>
	</g>
	<text x="177" y="110.75" fill="#000000" font-family="Verdana" font-size="12">EMPLOYÉ</text>
	<text x="163" y="135.8" fill="#000000" font-family="Verdana" font-size="12">matricule</text>
	<line x1="163" y1="138" x2="220" y2="138" stroke="#000000" stroke-width="1"/>
	<text x="163" y="152.8" fill="#000000" font-family="Verdana" font-size="12">nom employé</text>
</g>

<!-- Entity PROJET -->
<g>
	<g>
		<rect x="284" y="93" width="82" height="25" fill="#fdae61" stroke="none" stroke-width="0" opacity="1"/>
		<rect x="284" y="118" width="82" height="43" fill="#fee08b" stroke="none" stroke-width="0" opacity="1"/>
		<rect x="284" y="93" width="82" height="68" fill="none" stroke="#f46d43" stroke-width="2" opacity="1"/>
		<line x1="284" y1="118" x2="366" y2="118" stroke="#f46d43" stroke-width="1"/>
	</g>
	<text x="302" y="110.75" fill="#000000" font-family="Verdana" font-size="12">PROJET</text>
	<text x="289" y="135.8" fill="#000000" font-family="Verdana" font-size="12">num. projet</text>
	<line x1="289" y1="138" x2="361" y2="138" stroke="#000000" stroke-width="1"/>
	<text x="289" y="152.8" fill="#000000" font-family="Verdana" font-size="12">nom projet</text>
</g>

<!-- Entity DEPARTEMENT -->
<g>
	<g>
		<rect x="9" y="186" width="124" height="25" fill="#fdae61" stroke="none" stroke-width="0" opacity="1"/>
		<rect x="9" y="211" width="124" height="43" fill="#fee08b" stroke="none" stroke-width="0" opacity="1"/>
		<rect x="9" y="186" width="124" height="68" fill="none" stroke="#f46d43" stroke-width="2" opacity="1"/>
		<line x1="9" y1="211" x2="133" y2="211" stroke="#f46d43" stroke-width="1"/>
	</g>
	<text x="26" y="203.75" fill="#000000" font-family="Verdana" font-size="12">DÉPARTEMENT</text>
	<text x="14" y="228.8" fill="#000000" font-family="Verdana" font-size="12">num. département</text>
	<line x1="14" y1="231" x2="128" y2="231" stroke="#000000" stroke-width="1"/>
	<text x="14" y="245.8" fill="#000000" font-family="Verdana" font-size="12">nom département</text>
</g>

<!-- Entity SOCIETE -->
<g>
	<g>
		<rect x="402" y="186" width="94" height="25" fill="#fdae61" stroke="none" stroke-width="0" opacity="1"/>
		<rect x="402" y="211" width="94" height="43" fill="#fee08b" stroke="none" stroke-width="0" opacity="1"/>
		<rect x="402" y="186" width="94" height="68" fill="none" stroke="#f46d43" stroke-width="2" opacity="1"/>
		<line x1="402" y1="211" x2="496" y2="211" stroke="#f46d43" stroke-width="1"/>
	</g>
	<text x="422" y="203.75" fill="#000000" font-family="Verdana" font-size="12">SOCIÉTÉ</text>
	<text x="407" y="228.8" fill="#000000" font-family="Verdana" font-size="12">num. société</text>
	<line x1="407" y1="231" x2="486" y2="231" stroke="#000000" stroke-width="1"/>
	<text x="407" y="245.8" fill="#000000" font-family="Verdana" font-size="12">raison sociale</text>
</g>
</svg>

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
