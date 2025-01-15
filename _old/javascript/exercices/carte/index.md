---
title: Carte
---

> Leaflet est un bibliothèque Javascript optimisée pour afficher des cartes géographiques adaptées aux mobiles.

Télécharger la bibliothèque [https://leafletjs.com/](https://leafletjs.com/)

Créer un page HTML\
Ajouter le lien vers le fichier CSS et vers le fichier JS dans cet ordre.

```html
<link rel="stylesheet" href="dossier/leaflet.css" />
<script src="dossier/leaflet.js"></script>
```

Ajouter 

```html
<div id="macarte"></div>
```

Soyez bien sûr d'avoir ajouté une dimension à la zone `macarte` 

```css
#macarte { height: 180px; }
```

Configurer la carte avec comme source OpenStreetMap

```javascript
var map = L.map('macarte').setView([47.0, 6.8], 13);

L.tileLayer('https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png', {
   attribution: '&copy; <a href="https://www.openstreetmap.org/copyright">OpenStreetMap</a> contributors'
}).addTo(map);
``` 

Faites un appel à l'adresse https://workshop.neotechweb.net/ws/skimap/1.0.0/stations.php?massif=2

Décoder la réponse JSON

filtrer les stations qui n'ont pas de coordonnées

Afficher les marqueurs

Recentrer la carte sur la sélection de marqueurs
