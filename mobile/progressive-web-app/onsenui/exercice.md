---
title: Onsenui
---


Rendez vous sur le site [https://onsen.io/](https://onsen.io/)

Utiliser Onsen UI pour créer une progressive web app de gestion des pistes de ski

https://onsen.io/v2/guide/pwa/tutorial.html

Ajouter 2 template de pages contenant chacune une liste.

Onsen UI redéfinit des élément à la place des élément html. Le framework se charge de transformer les éléments Onsen en éléments HTML.

```html
<template id="main-page">
  <v-ons-page>
```

Rendez-vous dans la partie guide du site https://onsen.io/v2/guide


### Première page

Charger la première liste avec les massifs .

https://workshop.neotechweb.net/ws/skimap/1.0.0/massifs.php

Lorsque l'on clique sur un massif on passe à la deuxième page pour afficher la liste des stations.

### Deuxième page

Afficher la liste des stations

https://workshop.neotechweb.net/ws/skimap/1.0.0/stations.php?massif=2


### Troisième page : la station

Ajouter un menu contenant quatre onglet "Tab"
- Dans le premier onglet un slider de photo.
- Dans le deuxième onglet des cartes (card) pour afficher les prévision météo des 5 prochains jours.
- Dans le troisième onglet une carte (map) avec les pistes.
- Dans le quatrième onglet un plan svg (https://github.com/bumbu/svg-pan-zoom#readme).

Ajouter une gestion des cartes de la station pour afficher les pistes
Utiliser la bibliothèque Leaflet

https://workshop.neotechweb.net/ws/skimap/1.0.0/pistes.php?station=83
