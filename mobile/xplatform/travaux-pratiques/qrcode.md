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
