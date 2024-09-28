---
title: Graphe
---

Neo4j est une base de données orientée graphe, c'est-à-dire qu'elle est conçue pour stocker et gérer des données sous forme de graphes. Contrairement aux bases de données relationnelles traditionnelles (comme MySQL ou PostgreSQL) qui utilisent des tables, Neo4j fonctionne avec des nœuds (nodes) et des relations (relationships).

## Concepts

Nœuds (Nodes) : Les nœuds représentent des entités, comme des personnes, des objets, des lieux, etc. Chaque nœud peut avoir des propriétés (par exemple, un nœud "Personne" peut avoir un nom et un âge).

**Relations** (Relationships) : Les relations relient deux nœuds et décrivent la nature du lien entre eux (par exemple, une personne peut "CONNAÎTRE" une autre personne). Les relations peuvent aussi avoir des propriétés.

**Propriétés** (Properties) : Les nœuds et les relations peuvent avoir des propriétés, qui sont des paires clé-valeur (par exemple, "nom: Alice").

**Étiquettes** (Labels) : Les nœuds peuvent être étiquetés pour définir leur type (par exemple, un nœud peut avoir l'étiquette "Personne").

**Cypher** : Neo4j utilise le langage de requête Cypher pour interroger la base de données. C'est un langage spécifique aux graphes, qui permet de facilement décrire des relations complexes entre les nœuds.

## Avantages

Modélisation des relations complexes : Contrairement aux bases de données relationnelles, qui nécessitent souvent des jointures coûteuses pour modéliser des relations, Neo4j peut naviguer entre les nœuds et les relations de manière extrêmement efficace.

Performances pour les requêtes de graphe : Les requêtes impliquant plusieurs relations entre des entités (comme les relations sociales, les connexions entre objets, etc.) sont beaucoup plus rapides et plus intuitives à réaliser dans Neo4j.

Utilisation naturelle pour les cas d'utilisation liés aux graphes : Il est particulièrement bien adapté pour les réseaux sociaux, les moteurs de recommandation, la détection de fraudes, la gestion de réseaux, etc.

## Exercice

Ajouter le serveur Neo4J à votre environnemt Docker

```yaml
  neo4j:
    container_name: neo4j
    image: neo4j:${NEO4J_VERSION:-5.23.0-community}
    ports:
      - 7474:7474
      - 7687:7687
    volumes:
      - neo4j:/data
    environment:
      NEO4J_AUTH: neo4j/${DB_ROOT_PASSWORD}
```

Rendez vous à l'adresse : http://127.0.0.1:7474/browser/

Executer le fichier [graphe.txt](graphe.txt) dans le browser Neo4J

### Créer les contraintes

```cypher
CREATE CONSTRAINT FOR (n:Movie) REQUIRE (n.title) IS UNIQUE
```

```cypher
CREATE CONSTRAINT FOR (n:Person) REQUIRE (n.name) IS UNIQUE
```

### Créer les index

```cypher
CREATE INDEX FOR (m:Movie) ON (m.released)
```

### Les requêtes simples

#### Trouvez l'acteur nommé « Tom Hanks »

```cypher
MATCH (tom:Person {name: "Tom Hanks"}) RETURN tom
```

#### Trouvez le film intitulé « Cloud Atlas »

```cypher
MATCH (cloudAtlas:Movie {title: "Cloud Atlas"}) RETURN cloudAtlas
```
####  Trouvez 10 personnes et renvoyez leurs noms

```cypher
MATCH (people:Person) RETURN people.name LIMIT 10
```

####  Recherchez des films sortis dans les années 1990 et renvoyez leurs titres.

```cypher
MATCH (nineties:Movie) WHERE nineties.released >= 1990 
 AND nineties.released < 2000 RETURN nineties.title
```

### Les requêtes de relation

#### Dans quels films Tom Hanks a-t-il joué ?

```cypher
MATCH (tom:Person {name: "Tom Hanks"})-[:ACTED_IN]->(tomHanksMovies) RETURN tom,tomHanksMovies
```

#### Qui a réalisé « Cloud Atlas » ?

```cypher
MATCH (cloudAtlas:Movie {title: "Cloud Atlas"})<-[:DIRECTED]-(directors) RETURN directors.name
```

#### Qui étaient les co-acteurs de Tom Hanks ?

```cypher
MATCH (tom:Person {name:"Tom Hanks"})-[:ACTED_IN]->(m)<-[:ACTED_IN]-(coActors) 
RETURN DISTINCT coActors.name
```

#### Quel est le lien entre les gens et « Cloud Atlas » ?

```cypher
MATCH (people:Person)-[relatedTo]-(:Movie {title: "Cloud Atlas"}) RETURN people.name, Type(relatedTo), relatedTo.roles
```

#### Utilisez des modèles de longueur variable pour trouver des films et des acteurs jusqu'à 4 « sauts » de Kevin Bacon.

```cypher
MATCH (bacon:Person {name:"Kevin Bacon"})-[*1..4]-(hollywood)
RETURN DISTINCT hollywood
```

#### Utilisez l'algorithme shortestPath() intégré pour trouver le lien entre Kevin Bacon vers Meg Ryan.


```cypher
MATCH p=shortestPath(
(bacon:Person {name:"Kevin Bacon"})-[*]-(meg:Person {name:"Meg Ryan"})
)
RETURN p
```

#### Recommandons de nouveaux co-acteurs pour Tom Hanks

Une approche de recommandation de base consiste à trouver des connexions au-delà d'un voisinage immédiat qui sont elles-mêmes bien connectées.

Élargissez les co-acteurs de Tom Hanks pour trouver des co-co-acteurs qui n'ont pas travaillé avec Tom Hanks.

```cypher
MATCH (tom:Person {name:"Tom Hanks"})-[:ACTED_IN]->(m)<-[:ACTED_IN]-(coActors),
    (coActors)-[:ACTED_IN]->(m2)<-[:ACTED_IN]-(cocoActors)
  WHERE NOT (tom)-[:ACTED_IN]->()<-[:ACTED_IN]-(cocoActors) AND tom <> cocoActors
  RETURN cocoActors.name AS Recommended, count(*) AS Strength ORDER BY Strength DESC
```

#### Trouvez quelqu’un qui puisse présenter Tom Hanks à son potentiel co-acteur, dans ce cas Tom Cruise.

```cypher
MATCH (tom:Person {name:"Tom Hanks"})-[:ACTED_IN]->(m)<-[:ACTED_IN]-(coActors),
  (coActors)-[:ACTED_IN]->(m2)<-[:ACTED_IN]-(cruise:Person {name:"Tom Cruise"})
RETURN tom, m, coActors, m2, cruise
```

### Supprimer les données

```cypher
MATCH (n) DETACH DELETE n
```

Vérifions que tout est supprimé

```cypher
MATCH (n) RETURN n
```
