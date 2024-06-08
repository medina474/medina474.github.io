---
title: Flutter
---

Flutter est un **framework**, un ensemble d'outil pour développer des applications Web, Windows, Android et iOS à partir d'un socle commun.

Flutter est développé par Google c'est donc une alternative sérieuse et crédible aux développements d'applications natives.

Le langage utilisé est **[Dart](dart)**, une tentative de remplacement de javascript qui utilise un **typage fort**.

Flutter reprend des concepts de React tout en les améliorant. Toute l'application est pensée en forme de Widget qui vont vivre et se rafraîchir de manière indépendante.

Les **widgets** : ils permettent de décrire simplement le rendu final. Chaque objet est défini indépendamment des contraintes parentes. C’est son emplacement dans le code qui permettra de définir ses contraintes extérieures. Cela permet de construire facilement son interface ; le code est alors plus facilement lisible et maintenable.

Les **composants** : ils ont été recréés par Google. Les développeurs disposent d’une galerie de composants s’adaptant à IOS comme Android, et aux différentes versions d’OS. Cependant une pléthore de composants hétéroclites quelque fois pas maintenu et conçus pour le même objectif ne rendent pas la tâche du développeur facile.


## Installation

[installation](installation)


**Flutter Packages :** Utilisez des packages Flutter tiers provenant de pub.dev pour ajouter des fonctionnalités à votre application. Assurez-vous de vérifier la qualité et la popularité des packages avant de les intégrer dans votre projet.

[https://flutter.dev/](https://flutter.dev/)

Installer l'extension Flutter pour VS Code

Flutter: New Project

choisir Empty Application, puis le dossier, puis le nom de l'application (cinema_flutter)

Anatomie d'un projet Flutter

- .dart_tool
- .idea
- android
- ios
- lib
- linux
- macos
- web
- windows
- .gitignore
- .metadata
- analysis_options.yaml
- cinema_flutter.iml
- pubspec.lock
- pubspec.yaml
- README.md

fichier `lib/main.dart`

```dart
import 'package:flutter/material.dart';

void main() {
  runApp(const MainApp());
}

class MainApp extends StatelessWidget {
  const MainApp({super.key});

  @override
  Widget build(BuildContext context) {
    return const MaterialApp(
      home: Scaffold(
        body: Center(
          child: Text('Cinéma'),
        ),
      ),
    );
  }
}
```

[dart](../../../langage/dart/)


### Widget

Les **Widgets** sont les éléments de base de toute interface utilisateur Flutter. Il est recommandé d'utiliser les widgets fournis par Flutter autant que possible pour créer une interface utilisateur efficace et réactive.

#### Stateless


### Widget MaterialApp

### Widget Scaffold


### Widget Center

### Widget Text


Créer un Widget pour la liste des acteurs
nouveau fichier lib/acteurs.dart

Déclarer la classe

```dart
import 'package:flutter/material.dart';

class ActeursWidget extends StatefulWidget {
}
```

Il manque le constructeur

```dart
const ActeursWidget({super.key});
```

Ajoutons un titre

```dart
class ActeursWidget extends StatefulWidget {
  const ActeursWidget({super.key, required this.title});

  final String title;
}
```

C'est un Widget statefull il manque donc la méthode createState


```dart
@override
  State<ActeursWidget> createState() => _ActeursWidgetState();
```

Maintenant il faut écire la classe _ActeursWidgetState

```dart
class _ActeursWidgetState extends State<ActeursWidget> {}
```

il manque la méthode build

```dart
@override
  Widget build(BuildContext context) {
    return Scaffold()
  }
```



Que faut-il


builder qui est un widget

[introduction](introduction)

[stateful](stateful)
[composants](composants)
[ui](ui)
[future](future)

[carte](carte)
[barcode](barcode)
