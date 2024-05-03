---
title: Flutter
---

Flutter est un SDK (Kit de Développement Logiciel) open-source créé par Google. Il est utilisé pour développer des applications multiplateformes pour Android, iOS, Linux, Mac, Windows et le web à partir d'une seule base de code. Le langage utilisé est le **Dart** qui peut être compilé en langage natif ou en Javascript.



**Flutter Packages :** Utilisez des packages Flutter tiers provenant de pub.dev pour ajouter des fonctionnalités à votre application. Assurez-vous de vérifier la qualité et la popularité des packages avant de les intégrer dans votre projet.



<img src="flutter.png" height="64">

[https://flutter.dev/](https://flutter.dev/)

Installer l'extension Flutter pour VS Code

Flutter: New Project

choisir Empty Application, puis le dossier, puis le nom de l'application (cinema_flutter)

Anatomie d'un projet Flutter


.dart_tool
.idea
android
ios
lib
linux
macos
web
windows
.gitignore
.metadata
analysis_options.yaml
cinema_flutter.iml
pubspec.lock
pubspec.yaml
README.md

lib/main.dart

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

[dart](dart)


### Widget

Les **Widgets** sont les éléments de base de toute interface utilisateur Flutter. Il est recommandé d'utiliser les widgets fournis par Flutter autant que possible pour créer une interface utilisateur efficace et réactive.

#### Stateless

#### Statefull

  // This widget is the home page of your application. It is stateful, meaning
  // that it has a State object (defined below) that contains fields that affect
  // how it looks.

  // This class is the configuration for the state. It holds the values (in this
  // case the title) provided by the parent (in this case the App widget) and
  // used by the build method of the State. Fields in a Widget subclass are
  // always marked "final".

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
