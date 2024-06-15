---
title: ListView
---

Une ListView est un widget qui permet d'afficher une liste de widgets enfants, défilants verticalement ou horizontalement. C'est l'un des widgets les plus utilisés pour afficher des collections d'éléments, comme une liste de contacts, des messages, des articles, etc.

Une liste est un tableau composé d'enfants.

```dart
ListView(
  children: [
    ListTile(
      title: Text('Acteur 1')
    ),
    ListTile(
      title: Text('Acteur 2')
    ),
    ListTile(
      title: Text('Acteur 3')
    ),
  ],
)
```

Passer d'un liste statique à une liste **construite** à partir de données.

```dart
List<String> acteurs = <String>['Acteur A', 'Acteur B', 'Acteur C'];

ListView.builder(
  itemCount: acteurs.length,
  itemBuilder: (context, index) {
    return ListTile(title: Text(acteurs[index]));
  }
)
```

### Optimisation

Forcer les enfants à avoir la même étendue que le widget donné dans le sens de défilement.

Spécifier un prototypeItem est plus efficace que de laisser les enfants déterminer leur propre étendue, car la machine de défilement peut utiliser la connaissance préalable de l'étendue des enfants pour économiser du travail, par exemple lorsque la position de défilement change radicalement.

```dart
ListView.builder(
  prototypeItem: ListTile(title: Text(acteurs.first)),
)
```
