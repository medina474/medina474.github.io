---
title: "Dart"
date: 2023-01-18T23:30:01+01:00
draft: false
---



```
dart create -t console-full tutoriel
```

```
cd tutoriel

dart run
```

Hello world: 42!


## Paramètres nommés


## Première application


```dart
import 'package:flutter/material.dart';
```

```dart
void main() {
  runApp(MonApplication());
}
```

## Material

```dart
class MonApplication extends StatelessWidget {

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Cinéma',
      theme: ThemeData(
        primarySwatch: Colors.red,
      ),
      home: Material(
        child: Center(
          child: Text(
            'Application Cinéma',
            style: TextStyle(fontSize: 40),
      ))),
    );
  }
}
```


## Routes

Ensuite, définissez les routes en fournissant des propriétés supplémentaires au constructeur MaterialApp: l'initialRoute et les routes elles-mêmes.

La propriété initialRoute définit l'itinéraire par lequel l'application doit commencer. La propriété routes définit les routes nommées disponibles et les widgets à créer lors de la navigation vers ces routes.


Chaque application a une fonction main(). Pour afficher du texte sur la console, vous pouvez utiliser la fonction print() de niveau supérieur :

## Variables

Même dans le code Dart de type sécurisé, la plupart des variables n'ont pas besoin de types explicites, grâce à l'inférence de type :

```dart
var name = 'Voyager I';
var year = 1977;
var antennaDiameter = 3.7;
var flybyObjects = ['Jupiter', 'Saturn', 'Uranus', 'Neptune'];
var image = {
  'tags': ['saturn'],
  'url': '//path/to/saturn.jpg'
};
```

### Final and const

Si vous n'avez jamais l'intention de modifier une variable, utilisez final ou const, soit à la place de var, soit en plus d'un type. Une variable finale ne peut être définie qu'une seule fois ; une variable const est une constante de compilation. (Les variables const sont implicitement finales.)

## Classes

Here’s an example of a class with three properties, two constructors, and a method. One of the properties can’t be set directly, so it’s defined using a getter method (instead of a variable).

```dart
class Spacecraft {
  String name;
  DateTime? launchDate;

  // Read-only non-final property
  int? get launchYear => launchDate?.year;

  // Constructor, with syntactic sugar for assignment to members.
  Spacecraft(this.name, this.launchDate) {
    // Initialization code goes here.
  }

  // Named constructor that forwards to the default one.
  Spacecraft.unlaunched(String name) : this(name, null);

  // Method.
  void describe() {
    print('Spacecraft: $name');
    // Type promotion doesn't work on getters.
    var launchDate = this.launchDate;
    if (launchDate != null) {
      int years = DateTime.now().difference(launchDate).inDays ~/ 365;
      print('Launched: $launchYear ($years years ago)');
    } else {
      print('Unlaunched');
    }
  }
}
```
