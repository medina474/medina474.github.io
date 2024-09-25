---
title: Graphe
---

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

Executer le fichier graphe.txt dans le browser Neo4J

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
