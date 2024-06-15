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


Future<void> _getPosition() async {
    bool serviceEnabled;
    LocationPermission permission;

    // Vérifiez si les services de localisation sont activés
    serviceEnabled = await Geolocator.isLocationServiceEnabled();
    if (!serviceEnabled) {
      // Les services de localisation ne sont pas activés, ne poursuivez pas
      return;
    }

    // Vérifiez les permissions
    permission = await Geolocator.checkPermission();
    if (permission == LocationPermission.denied) {
      permission = await Geolocator.requestPermission();
      if (permission == LocationPermission.denied) {
        // Les permissions sont refusées, ne poursuivez pas
        return;
      }
    }

    if (permission == LocationPermission.deniedForever) {
      // Les permissions sont refusées de façon permanente, ne poursuivez pas
      return;
    }

    Position position = await Geolocator.getCurrentPosition(
        desiredAccuracy: LocationAccuracy.high);

    setState(() {
      _positionUtilisateur = LatLng(position.latitude, position.longitude);
      _mapController.move(_positionUtilisateur, 14.0);
    });
  }

Ajouter un marqueur sur la carte

https://homework.family/google-map-dans-flutter/
