---
title: Stateful Widget
---

## Stateful

### Future

Convertir un JSON en Model

https://javiercbk.github.io/json_to_dart/

## Routes

Nommer des routes dans l'application

```dart
routes: {
  'ActeursPage': (BuildContext context) => const ActeursPage(title:"Acteurs"),
}
```

Appeler la route

```dart
Navigator.pushNamed(context, 'FilmPage', arguments: {
    'id': webdata[index]['id'],
    'nom': webdata[index]['name']
});
```
