---
title: GraphQL
---

GraphQL (pour Graph Query Language) est un langage de requêtes et un environnement d'exécution, créé par Facebook en 2012, avant d'être publié comme projet open-source en 2015. Inscrit dans le modèle Client-Serveur, il propose une alternative aux API REST. La requête du client définit une structure de données, dont le stockage est éventuellement distribué, et le serveur suit cette structure pour retourner la réponse. Fortement typé, ce langage évite les problèmes de retour de données insuffisants (under-fetching) ou surnuméraires (over-fetching). 

```json
{
  user(id: "123") {
    name
    email
    posts {
      title
      content
      publishedAt
    }
  }
}
```

#### Over-fetching (récupération excessive)

L'over-fetching se produit lorsque l'API renvoie plus de données que nécessaire. Cela survient souvent dans des API REST où une requête à un endpoint retourne un ensemble de données prédéfini, même si vous n'avez besoin que de quelques champs ou informations spécifiques.

#### Under-fetching (récupération insuffisante)

L'under-fetching se produit lorsqu'une seule requête ne fournit pas toutes les données nécessaires, vous obligeant à faire plusieurs requêtes pour obtenir toutes les informations dont vous avez besoin. Cela est souvent dû à des API fragmentées où chaque ressource doit être récupérée via des endpoints différents.
