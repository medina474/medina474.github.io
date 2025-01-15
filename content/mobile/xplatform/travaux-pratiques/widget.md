---
title: 
---


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

Découper la partie body en 2 zones suivant l'axe vertical.

Dans la première mettre le titre Cinéma et dan la deuxième mettre 3 icones.

```dart
Column(mainAxisAlignment: MainAxisAlignment.spaceEvenly, children: [
    const Center(
      child: Text('Cinema',
          style: TextStyle(color: Colors.white, fontSize: 40)),
    ),
    Row(mainAxisAlignment: MainAxisAlignment.spaceEvenly, children: [
      Icon(Icons.map_sharp, size: 50, color: Colors.white),
      Icon(Icons.theater_comedy, size: 50, color: Colors.white),
      Icon(Icons.airplane_ticket, size: 50, color: Colors.white),
    ])
  ])
```
