---
title: QR Code
---

Utilisez le package qr_code_scanner pour lire les QR codes.

Lire des coordonnées contenues dans le qr code et afficher un marqueur correspondant.

Dans ce cas l'affichage du Widget va dépendre de l'action de l'utilisateur. Nous ne sommes plus dans le cas d'un statelessWidget mais d'un Widget avec état un statefullWidget

```dart
class CarteWidget extends StatefulWidget {
  @override
  _CarteWidgetState createState() => _CarteWidgetState();
}
```

Lorsqu'une variable ou une fonction commence par un underscore, elle est privée à la bibliothèque dans laquelle elle est définie. Cela signifie qu'elle ne peut pas être accédée en dehors du fichier où elle a été définie.

```dart
class _FlutterMapWidgetState extends State<FlutterMapWidget> {
  final List<Marker> _markers = [];
```

```dart
@override
  void dispose() {
    controller?.dispose();
    super.dispose();
  }
```

En Flutter, une classe qui étend StatefulWidget est généralement vide ou ne contient que des informations de configuration parce que le véritable travail de gestion de l'état et de construction du widget est délégué à une classe séparée qui étend State. Cette séparation permet une gestion plus claire et plus modulaire de l'état et de l'interface utilisateur.
Structure d'un StatefulWidget

Un StatefulWidget est composé de deux parties principales :

La classe StatefulWidget :
Cette classe est généralement utilisée pour passer des paramètres de configuration et pour créer une instance de la classe State.
Elle est souvent concise et contient uniquement des informations nécessaires pour initialiser l'état du widget.

La classe State :
Cette classe contient l'état mutable du widget et la logique de rendu.
C'est dans cette classe que vous gérez l'état et définissez la méthode build qui retourne l'interface utilisateur du widget.
