---
title: Flutter
---

## Installation

Utiliser Visual Studio Code, et installer les plugins [Dart](https://marketplace.visualstudio.com/items?itemName=Dart-Code.dart-code) et [Flutter](https://marketplace.visualstudio.com/items?itemName=Dart-Code.flutter)

Avec Visual Studio Code lancer l'outil de diagnostic **flutter doctor** à partir du menu View, Command
Palette (Ctrl Maj P)

Installer le, comme indiqué dans la documentation (mettre à jour le path)

Dans Andoid Studio assurez vous d'avoir au moins un SDK installé, le composant Android SDK Command-line Tools

Vous devez aussi avoir un téléphone relié au debuggeur ou un appareil virtuel



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
          child: Text('Hello World!'),
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

#### Statefull

Un widget Statefull est un widget avec état, ce qui signifie qu'il possède un objet State (défini ci-dessous) qui contient des champs qui **affectent** son apparence.

La classe State est la configuration de l'état. Il contient les valeurs (dans ce cas le titre) fournies par le parent (dans ce cas le widget App) et utilisées par la méthode build de l'État. Les champs d'une sous-classe de widget sont toujours marqués « final ».

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

[composants](composants)
[ui](ui)
[future](future)

[carte](carte)
[barcode](barcode)
