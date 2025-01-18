---
title: Universally Unique Identifiers
---

> Un identifiant unique universel est comme son nom l'indique est un identifiant qui une fois généré a une chance infinement faible d'avoir un double dans l'ensembles des systèmes du monde entier.
{ .definition }

### Inconvénients des entiers auto-incrémentés

Les entiers auto incrémentés souffrent de deux problèmes majeurs.

**Unicité** Ils sont uniques mais uniquement au sein d'une seule table ou à la rigueur au sein de la base de données. Le risque de doublon, appelé collision, est invitable si plusieurs bases de données fusionnent.

**Prédictibilité** : Lorsque l'on connait un id il est trés facile de deviner les identifiants des enregistrements adjacents. Cela peut conduire à des attaques de type "guessing". 

http://ecommerce.site.com/commande?=1512

Comment accéder à la commande suivante ?

### Avantages des UUID

**Universalité et unicité garantie** :  Les UUID sont conçus pour être universellement uniques, ce qui signifie qu'ils sont uniques non seulement au sein d'une base de données, mais également à travers différentes bases de données, serveurs et systèmes. Cela est particulièrement utile dans des environnements distribués ou des applications nécessitant la fusion de bases de données.
    
**Indépendance vis-à-vis de la base de données** : Les UUID peuvent être générés indépendamment de la base de données, souvent côté application ou middleware. Cela permet de décentraliser la création d'identifiants, ce qui est utile dans des systèmes distribués ou des architectures microservices.
  
**Sécurité par obscurcissement** : Les UUID, de par leur longueur et leur format, sont difficilement prédictibles. Cela réduit les risques d'attaques comme le scraping ou l'accès non autorisé à des enregistrements spécifiques basés sur l'identifiant.
   
**Préparation pour la scalabilité** : Les UUID sont bien adaptés aux systèmes qui doivent évoluer horizontalement, notamment dans des contextes où plusieurs instances de base de données ou serveurs peuvent créer des enregistrements simultanément. Il n'y a pas de contention ou de besoin de coordination centralisée pour garantir l'unicité.
  

### Inconvénients des UUID

Bien que les UUID aient de nombreux avantages, ils présentent aussi quelques inconvénients :

**Taille et performance** : Les UUID sont plus longs que les identifiants auto-incrémentés (128 bits soit 16 octets contre 4 ou 8 octets), ce qui peut augmenter la taille des index et peut affecter les performances.

**Lisibilité** : Les UUID sont plus difficiles à lire et manipuler pour les développeurs par rapport aux identifiants numériques simples.

**Fragmentation** : Les UUIDs sont généralement générés de manière aléatoire (surtout pour les versions 4 des UUID), ce qui signifie que les nouvelles entrées sont insérées à des positions aléatoires dans l'index. Cela entraîne une fragmentation accrue de l'index et nécessite plus de réorganisations et de rééquilibrages pour les index de type B-tree, par exemple. Cette fragmentation peut dégrader les performances des opérations de recherche et de tri.

**Tri** : En raison de leur nature aléatoire, les UUIDs ne permettent pas un tri "naturel" des données. Les opérations de tri basées sur les UUIDs peuvent être plus lentes, car les données ne sont pas insérées dans un ordre séquentiel. Cela peut affecter les performances des requêtes qui nécessitent un tri.

Les nouvelles lignes ne sont pas nécessairement stockées près des autres lignes insérées récemment, ce qui peut nuire à la localité des données. Cela signifie que l'accès aux enregistrements adjacents en termes de temps d'insertion peut nécessiter plus de sauts dans l'arborescence de l'index ou le disque.

### Versions

Version 1

La version 1 crée un UUID en se basant sur l'adresse MAC et l'horodatage. Il garantit la génération d'un identifiant unique (pour deux systèmes avec des adresses MAC différentes et agissant à plus de 0,1μs d'écart). Il permet également sur la même machine, de générer jusqu'à 10 millions d'UUID uniques par seconde.

L'adresse MAC est codée sur 48 bits. L'horodatage est codé sur 74 bits, avec un "timestamp" de 60 bits, correspondant au nombre de dixièmes de micro-secondes écoulées depuis le 15 Octobre 1582 à minuit (UTC), considérée comme le début du calendrier grégorien, suivi d'un "clockmark" de 14 bits. Certaines versions de l'algorithme de génération assurent l'unicité de plusieurs identifiants produits en parallèle par les valeurs données aux derniers bits du "clockmark".

Version 2

D'après la RFC 41221 la version 2 est une variante DCE (« Distributed Computing Environment ») qui inclut des UIDs POSIX.

Version 3

La version 3 est un hash md5 d'un nom (comme une URL ou un OID). L'UUID généré sera toujours égal pour un même nom, il ne contient donc aucun aspect temporal ou aléatoire.

Version 4

La version 4 génère un UUID totalement aléatoire.

Version 5

La version 5 est un hash sha1 d'un nom (comme une URL ou un OID). Comme pour la version 3, l'UUID généré sera toujours égal pour un même nom.

Version 6

La version 6 est identique à la version 1, sauf que tous les bits de temps sont placés dans l'ordre inverse. Cela permettra aux systèmes de trier dans l'ordre de création par UUID, ce qui n'était pas possible avec la version 1.

Version 7

L'UUIDv7 est l'une des versions de l'UUID qui est basée sur le temps, comme l'UUIDv1.

Les UUID version 7 (UUIDv7) sont conçus pour les clés des bases de données à forte charge et des systèmes distribués.

UUIDv7 inclut un composant temporel basé sur l'horodatage, comme l'UUIDv1, ce qui signifie que les identifiants générés suivent un ordre chronologique mais sans être contigues. Cela facilite les insertions séquentielles dans des bases de données, réduisant la fragmentation des index et améliorant les performances pour les opérations de tri et de recherche.

### Qui utilise les uuid ?

YouTube utilise une version spécifique d'UUID pour générer des identifiants uniques pour ses vidéos et autres ressources, souvent appelés des "YouTube IDs". Bien que ces identifiants aient une apparence similaire à des UUIDs, ils ne sont pas des UUIDs standards tels que définis par la norme RFC 4122.

Les identifiants YouTube sont des chaînes de 11 caractères, ce qui est plus court qu'un UUID standard, mais suffisamment long pour fournir une très grande plage de combinaisons possibles (64^11, soit environ 73 trillions de combinaisons). 

Base64URL Encoding : Ces identifiants utilisent un encodage spécifique basé sur une variante de Base64 appelée Base64URL. Au final l'identifiant est composé de lettres (majuscules et minuscules), de chiffres, ainsi que des caractères -, _. Par exemple : dQw4w9WgXcQ.

Les identifiants YouTube sont générés de manière pseudo-aléatoire, garantissant une unicité sans suivre un ordre séquentiel. Cela rend les identifiants difficiles à deviner et minimise le risque de collisions.

Les identifiants YouTube sont conçus pour être générés très rapidement et en grand nombre sans risque de collision, tout en restant compatibles avec les URLs. Ils ne contiennent aucune information temporelle ou spatiale, contrairement aux UUIDs version 1 ou 2.
