---
title: JavaScript Object Notation
---

Le JSON (JavaScript Object Notation) est un format léger d’échange de données, facile à lire et à écrire pour les humains car en texte, et facile à analyser et à générer pour les machines. Il est couramment utilisé dans les applications web pour transmettre des données entre un client (navigateur) et un serveur. Bien qu'il soit dérivé de JavaScript, il est maintenant largement adopté par un grand nombre de langages de programmation et de systèmes.

## Structure de base du JSON

Le JSON repose sur deux structures principales :

- **Objets** : Ils sont composés de paires clé-valeur, encadrées par des accolades {}.
- **Tableaux** : Ils sont constitués de valeurs séparées par des virgules et encadrées par des crochets [].

```json
{
  "nom": "Albert",
  "age": 34,
  "email": "albert@emc2.com",
  "nationalites": ["Suisse", "Américain", "Allemand"]
}
```

Dans cet exemple, l’objet contient quatre paires clé-valeur :

- "nom" (clé) : "Albert" (valeur de type chaîne de caractères)
- "age" (clé) : 34 (valeur de type nombre)
- "email" (clé) : "albert@emc2.com" (valeur de type chaîne de caractères)
- "nationalites" (clé) : un tableau de valeurs chaîne de caractères

#### Types de données JSON

Le JSON supporte les types de données suivants :

- Chaînes de caractères (string) : Délimitées par des guillemets doubles. Exemple : "texte"
- Nombres (number) : Entiers ou décimaux. Exemple : 42, 3.14
- Booléens (boolean) : true ou false
- Tableaux (array) : Une liste ordonnée de valeurs, encadrée par des crochets []
- Objets (object) : Paires clé-valeur, encadrées par des accolades {}
- Null : Représente une valeur nulle. Exemple : null

### Règles à respecter

- Les clés doivent toujours être des chaînes de caractères entourées de guillemets doubles.
- Les valeurs peuvent être de différents types (chaînes de caractères, nombres, booléens, tableaux, objets, null).
- Chaque paire clé-valeur dans un objet est séparée par une virgule.
- Les éléments d'un tableau sont également séparés par des virgules.
- Il ne doit pas y avoir de virgule après le dernier élément

Typage limité : Le JSON ne prend pas en charge des types de données plus complexes comme les dates, les fonctions, ou les références circulaires d'objets.

https://jsonformatter.curiousconcept.com/

insert into velos values ("Trek Fuel EX 9.9 Sram XX1", "{""coloris"":""Bleu"",""poids"":14.11,""taille cadre"":""XS"",""taille des roues"":27.5,""matière"":""Carbone"",""groupe"":""Sram"",""offres"":[{""vendeur"":""Vélomania"",""stock"":7,""prix"":12749},{""vendeur"":""CycloSport"",""stock"":3,""prix"":11999},{""vendeur"":""Freedom Wheels"",""stock"":0,""prix"":9990}]}");
insert into velos values ("Giant TG 9.9 Sram XX1", "{""coloris"":""Rouge"",""poids"":13.54,""taille cadre"":""L"",""taille des roues"":26,""matière"":""Aluminium"",""groupe"":""Sram"",""offres"":[{""vendeur"":""Vélomania"",""stock"":3,""prix"":7580},{""vendeur"":""CycloSport"",""stock"":8,""prix"":7770},{""vendeur"":""Freedom Wheels"",""stock"":1,""prix"":7649}]}");

select nom, json_extract(caracteristiques,'$.coloris') from velos
select nom, caracteristiques->'$.coloris' from velos
select nom, caracteristiques->>'$.coloris' from velos