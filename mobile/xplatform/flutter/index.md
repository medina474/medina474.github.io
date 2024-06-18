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


[dart](../../../langage/dart/)


### Widget

Les **Widgets** sont les éléments de base de toute interface utilisateur Flutter. Il est recommandé d'utiliser les widgets fournis par Flutter autant que possible pour créer une interface utilisateur efficace et réactive.

#### Stateless

Les widgets sans état sont idéaux pour représenter des parties de votre interface utilisateur qui ne changent pas en fonction des interactions des utilisateurs ou des mises à jour des données. Ils sont couramment utilisés pour afficher du contenu statique, tel que des en-têtes, des étiquettes, des icônes ou des images. Des exemples de widgets sans état incluent Text, Icon et Image.

Les widgets staleless sont sans état. Cela ne veut pas dire qu'ils ne sont pas complexes. Les widgets staleless ne sont pas interractifs mais ils peuvent contenir des widget stateful qui eux sont interractifs.

#### Stateful

D'un autre côté, un widget Stateful représente une partie de l'interface utilisateur qui peut changer au fil du temps ou en réponse aux interactions de l'utilisateur. Ces widgets sont mutables et peuvent être mis à jour dynamiquement.

Caractéristiques des widgets avec état :

État mutable : les widgets avec état peuvent maintenir un état interne mutable, qui peut changer au fil du temps. Cet état est généralement stocké dans un objet distinct appelé objet « State ».

Méthode de construction (build) : comme les widgets sans état, les widgets avec état ont également une méthode de construction. Cette méthode définit l’apparence et la structure initiales du widget.

Objet d'état : les widgets avec état sont associés à un objet d'état mutable. Cet objet State est responsable du stockage et de la gestion de l’état interne du widget.

Capacité de reconstruction : les widgets avec état peuvent demander une reconstruction de leur interface utilisateur lorsque leur état interne change. Cela les rend adaptés aux composants dynamiques de l’interface utilisateur.

### Widget MaterialApp

### Widget Scaffold


### Widget Center

### Widget Text



Créer un Widget pour la liste des acteurs
nouveau fichier lib/acteurs.dart

Déclarer la classe avec le mot clé `class`

```dart
import 'package:flutter/material.dart';

class ActeursWidget extends StatefulWidget {
}
```

Déclarer le constructeur c'est une fonction avec le même nom que la classe

```dart
ActeursWidget({super.key});
```

Ajoutons un titre

Les variables ou fonctions qui commencent avec un _underscore_ _ sont **privés** à la classe

```dart
class ActeursWidget extends StatefulWidget {
  const ActeursWidget({super.key, required this.title});

  final String _title;
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

La méthode build créé et retourne l'interface utilisateur du widget

```dart
@override
  Widget build(BuildContext context) {
    return Scaffold()
  }
```

La fonction `setState` indique à la classe que l'état a changé est qu'il faut reconstruire (build) l'interface utilisateur


[introduction](introduction)

[stateful](stateful)
[composants](composants)
[ui](ui)
[future](future)

[carte](carte)
[barcode](barcode)
