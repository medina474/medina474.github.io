---
title: Travaux pratiques - La carte
---

### 1. Ajouter un nouveau gabarit (template) de page.

```html
```

### 2. Librairie de cartographie

Sur cette page ajouter une carte à l'aide de la librairie [Leaflet](https://leafletjs.com/).

<img src="leaflet.png" class="h-8">

```html
<link rel="stylesheet" href="leaflet/leaflet.css"
  integrity="sha256-p4NxAoJBhIIN+hmNHrzRCf9tD/miZyoHS5obTRR9BMY=" crossorigin="" />
<script src="leaflet/leaflet.js"
  integrity="sha256-20nQCchB9co0qIjJZRGuk2/Z9VM+kNiyxNV1lvTlZBo=" crossorigin=""></script>
```

```javascript
const map = L.map('map').setView([45, 0], 13);

L.tileLayer('https://tile.openstreetmap.org/{z}/{x}/{y}.png', {
  maxZoom: 17,
  attribution: '&copy; <a href="http://www.openstreetmap.org/copyright">OpenStreetMap</a>'
}).addTo(map);
```

### 3. Chargement des données

Faire un appel au webservice pour récupérer l'ensemble des établissements dans une zone donnée.

```javascript
async function getCinemas(map) {
  const b = map.getBounds();

  const data = await fetch("https://morseweiswlpykaugwtd.supabase.co/rest/v1/rpc/etablissements_in_view", {
    method: "POST",
    headers: {
      "content-type": "application/json",
      "apikey": "..."
    },
    body: JSON.stringify({ 
        "min_lat": b._southWest.lat, 
        "min_long": b._southWest.lng, 
        "max_lat": b._northEast.lat, 
        "max_long": b._northEast.lng 
      })
  });

  const etablissements = await data.json();
```

Ajouter des marqueurs pour chaque établissement.

```javascript
for (let e of etablissements) {
  clusters.addLayer(L.marker([e.lat, e.long])
    .bindPopup(`<strong>${e.nom}</strong><br>${e.ville}`));
}
```  

### 3. Géolocalisation

Faire un appel à l'API de géolocalisation du navigateur.

Déplacer la carte pour la centrer sur la position de l'utilisateur.

```javascript
map.locate({ setView: true, maxZoom: 15 });
```

Mettre à jour la liste des établissements avec la nouvelle zone.

```javascript
map.addEventListener("moveend", function () {
  getCinemas(map);
});
```

Attention : si la nouvelle zone recouvre en partie la précédente, il ne faut pas ajouter les établissements déjà présents !

```javascript
for (let e of etablissements) {

  if (listeMarqueurs.has(e.etablissement_id)) continue;

  clusters.addLayer(L.marker([e.lat, e.long]);

  listeMarqueurs.add(e.etablissement_id);
}
```

Ajouter un popup sur chaque marqueur, indiquer le nom et la ville de l'établissement

```javascript
clusters.addLayer(L.marker([e.lat, e.long])
  .bindPopup(`<strong>${e.nom}</strong><br>${e.ville}`));
```

### 4. Cluster
