---
title: Carte
---

Créer une nouvelle page

Ajouter un composant carte dans le body


Tout d'abord, assurez-vous d'ajouter les dépendances nécessaires dans votre fichier `pubspec.yaml` :

flutter_map: ^3.1.0


```
FlutterMap(
      options: MapOptions(
        center: LatLng(51.5, -0.09),
        zoom: 13.0,
      ),
      layers: [
        TileLayerOptions(
          urlTemplate: 'https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png',
          subdomains: ['a', 'b', 'c'],
          tileProvider: CancellableNetworkTileProvider(),
        ),
      ],
    );
```

Ajouter un composant pour améliorer les appels réseaux flutter_map_cancellable_tile_provider

Ajouter un marqueur sur la carte

https://homework.family/google-map-dans-flutter/
