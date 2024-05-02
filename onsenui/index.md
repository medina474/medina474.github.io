---
title: "Onsenui"
date: 2023-01-18T21:49:32+01:00
draft: false
---


Pour eux, accéder à internet sur un appareil mobile, c’est soit ouvrir un site web via un navigateur,
soit télécharger une application sur sa tablette ou son smartphone. Dans le premier cas, et à
condition que le site en question ait été conçu en responsive design, il y a de fortes chances qu’il
mette du temps à se charger. Or une page qui met plus de 3 secondes à apparaître sur un écran est
abandonnée par plus de la moitié des internautes. Autres problèmes propres aux sites web,
l’impossibilité d’avoir un affichage hors connexion et la nécessité de faire une recherche ou de saisir
une URL lorsque l’on veut y accéder.

Les applications sont-elles mieux loties ? Pas forcément. Entre le moment où elle est trouvée dans la
jungle des stores et celui où elle est effectivement ouverte, une application perd en moyenne 20% de
ses utilisateurs et autant de clients potentiels.
Pour une entreprise, la technologie Progressive web apps offre deux avantages principaux : elle lui
apporte une présence sur mobile qui sera repérée et référencée par Google ; et elle offre à ses
prospects une expérience utilisateur inédite.

Pour faire simple, les PWA combinent les meilleures fonctionnalités des pages web et des applis.
Pour les propriétaires d’appareils mobiles, elles ne se téléchargent pas : nul besoin d’aller fouiner
dans l’AppStore ou le Play Store pour les trouver. En revanche, elles vont visuellement apparaître sur
l’écran avec une icône ressemblant à celle d’une appli : inutile de rentrer l’URL à chaque fois que l’on
souhaite se connecter. Le navigateur web s'ouvre en plein écran sans barre d'adresse, ni boutons, ni
menus. L'expérience utilisateur est très proche d'une vraie application.

## Onsen UI

Onsen UI est un framework Javascript qui permet de réaliser des applications web ou hybrides très facilement.

Onsen UI peut s'utiliser avec du javascript classique, avec Angular, VueJS ou ReactJS

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
Utiliser la librairie Leaflet

https://workshop.neotechweb.net/ws/skimap/1.0.0/pistes.php?station=83


## Lighthouse

## Web Worker

[Web Worker](webworker)
