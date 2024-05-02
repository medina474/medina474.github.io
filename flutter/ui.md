---
title: "Ui"
date: 2023-01-18T21:50:14+01:00
draft: false
---

## Commencez par penser de manière déclarative

Si vous êtes habitué à des langages et frameworks impératifs (tel que Android SDK ou iOS UIKit), vous devez commencer à penser au développement d'applications sous un nouvel angle.

De nombreuses hypothèses que vous pourriez avoir ne s'appliquent pas à Flutter. Par exemple, dans Flutter, vous pouvez reconstruire des parties de votre interface utilisateur à partir de zéro au lieu de la modifier. Flutter est assez rapide pour le faire, même sur chaque image si nécessaire.

Flutter est **déclaratif**. Cela signifie que Flutter construit son interface utilisateur pour refléter l'état actuel de votre application :

UI = f(state)

Lorsque l'état de votre application change (par exemple, l'utilisateur actionne un interrupteur dans l'écran des paramètres), vous modifiez l'état, ce qui déclenche un rafraîchissement de l'interface utilisateur. Il n'y a pas de changement impératif de l'interface utilisateur elle-même (comme widget.setText) - vous modifiez l'état et l'interface utilisateur se reconstruit **à partir de zéro**.

En savoir plus sur l'approche déclarative de la programmation de l'interface utilisateur dans le guide de démarrage.

Le style déclaratif de la programmation de l'interface utilisateur présente de nombreux avantages. Remarquablement, il n'y a **qu'un seul chemin de code** pour n'importe quel état de l'interface utilisateur. Vous décrivez à quoi devrait ressembler l'interface utilisateur pour un état donné, une fois, et c'est tout.

Au début, ce style de programmation peut ne pas sembler aussi intuitif que le style impératif.

## Scaffold

La classe Scaffold (échafaudage) est un widget extensible qui remplit tout l'espace disponible ou l'écran. Il fournit des propriétés pour afficher les widgets utiles à une application tels que AppBar, Drawer, SnackBar, Bottom-Sheet, FloatingActionButton et BottomNavigationBar.

```dart
Widget build(BuildContext context) {
  return Scaffold(
    appBar: AppBar(
      title: const Text('Cinéma'),
    ),
    body: Center(child: Text(
      'Application Cinéma',
      style: TextStyle(fontSize: 40),)
    ),
    backgroundColor: Colors.blueGrey.shade200,
  );
}
```

**AppBar**, qui est une barre horizontale généralement affichée en haut d'une application à l'aide de la propriété appBar.

**BottomAppBar**, est une barre horizontale généralement affichée au bas d'une application à l'aide de la propriété bottomNavigationBar.

**FloatingActionButton**, qui est un bouton circulaire généralement affiché dans le coin inférieur droit de l'application à l'aide de la propriété floatingActionButton.

**Drawer**, qui est un panneau vertical généralement affiché à gauche du corps (et souvent masqué sur les téléphones) à l'aide de la propriété drawer.

**BottomNavigationBar**, qui est un tableau horizontal de boutons généralement affichés en bas de l'application à l'aide de la propriété bottomNavigationBar.

**SnackBar**, qui est une notification temporaire généralement affichée près du bas de l'application à l'aide de la méthode ScaffoldState.showSnackBar.

**BottomSheet**, qui est une superposition généralement affichée près du bas de l'application. Une feuille du bas peut être persistante, auquel cas elle est affichée à l'aide de la méthode ScaffoldState.showBottomSheet, ou modale, auquel cas elle est affichée à l'aide de la fonction showModalBottomSheet.

ScaffoldState, qui est l'état associé à ce widget.

## Menu Tiroir

Dans un widget Scaffold la propriété drawer permet d'ajouter un objet widget de type menu tiroir.

Ajoutez maintenant un tiroir à l'échafaudage. Un tiroir peut être n'importe quel widget, mais il est souvent préférable d'utiliser le widget Tiroir de la bibliothèque de matériaux, qui respecte les spécifications de Material Design.

Maintenant que vous avez un tiroir en place, ajoutez-y du contenu. Pour cet exemple, utilisez un ListView. Bien que vous puissiez utiliser un widget Colonne, ListView est pratique car il permet aux utilisateurs de faire défiler le tiroir si le contenu prend plus d'espace que l'écran ne le prend en charge.

Remplissez le ListView avec un DrawerHeader et deux widgets ListTile. Pour plus d'informations sur l'utilisation des listes, consultez les recettes de listes.

## Widgets Stateless / Stateful

L'état d'une application peut très simplement être défini comme tout ce qui existe dans la mémoire de l'application pendant que l'application est en cours d'exécution. Cela inclut tous les widgets qui maintiennent l'interface utilisateur de l'application, y compris les boutons, les polices de texte, les icônes, les animations, etc. Alors maintenant que nous savons quels sont ces états, plongeons directement dans notre sujet principal, à savoir quels sont ces widgets avec et sans état et comment diffèrent-ils les uns des autres.

**State** : l'état est l'information qui peut être lue de manière synchrone lorsque le widget est construit et qui peut **changer** pendant la durée de vie du widget.

En d'autres termes, l'état du widget est la donnée des objets que ses propriétés (paramètres) entretiennent au moment de sa création (lorsque le widget est peint à l'écran). L'état peut également changer lorsqu'il est utilisé, par exemple lorsqu'un widget CheckBox est cliqué, une coche apparaît sur la case.

Un Widget **Stateless** : les widgets dont l'état **ne peut pas** être modifié une fois construits sont appelés widgets sans état. Ces widgets sont immuables une fois qu'ils sont construits, c'est-à-dire que tout changement dans les variables, les icônes, les boutons ou la récupération de données ne peut pas changer l'état de l'application. Vous trouverez ci-dessous la structure de base d'un widget sans état. Le widget sans état remplace la méthode build () et renvoie un widget. Par exemple, nous utilisons Text or the Icon est notre application flutter où l'état du widget ne change pas dans le runtime. Il est utilisé lorsque l'interface utilisateur dépend des informations contenues dans l'objet lui-même. D'autres exemples peuvent être Text, RaisedButton, IconButtons.

```
class _MyWidgetState extends State<MyWidget>
```

La classe du Widget doit dériver de la classe `State` mais en reprenant

```dart
import 'package:flutter/material.dart';

//This function triggers the build process
void main() => runApp(const MyApp());

// StatefulWidget
class MyApp extends StatefulWidget {
const MyApp({Key? key}) : super(key: key);

@override
// ignore: library_private_types_in_public_api
_MyAppState createState() => _MyAppState();
}

class _MyAppState extends State<MyApp> {
@override
Widget build(BuildContext context) {
	return MaterialApp(
	debugShowCheckedModeBanner: false,
	home: Scaffold(
		backgroundColor: Color.fromARGB(255, 230, 255, 201),
		appBar: AppBar(
		leading: const Icon(Icons.menu),
		backgroundColor: Colors.green,
		title: const Text(
			"GeeksforGeeks",
			textAlign: TextAlign.start,
		),
		), // AppBar
		body: const Center(
		child: Text(
			"StateFul Widget",
			style: TextStyle(color: Colors.black, fontSize: 30),
		),
		), // Container
	), // Scaffold
	); // MaterialApp
}
}
```
