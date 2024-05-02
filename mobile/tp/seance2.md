---
title: Onsen UI
date: 2022-05-03T15:18:26+01:00
draft: false
---

Pour accélérer le développement nous allons utiliser un framework qui permet d'utiliser des composants prédéfinis et obtenir un affichage semblable à ce que l'on trouve dans les applications.



### OnsenUI

Le moyen le plus rapide de développer de belles applications Web HTML5 hybrides et mobiles.

Faites l'expérience d'un développement rationalisé avec une configuration sans délai, en utilisant les technologies que vous connaissez et aimez déjà - Javascript, HTML et CSS.

[https://onsen.io/](https://onsen.io/)



### Bootstrap

Bootstrap est une collection d'outils utiles à la création du design de sites et d'applications web. C'est un ensemble qui contient des codes HTML et CSS, des formulaires, boutons, outils de navigation et autres éléments interactifs, ainsi que des extensions JavaScript en option.

Universel l'aspect application mobile n'est pas prioritaire. Par rapport aux autres framework, le résultat ne tend pas à imiter une application.

[https://getbootstrap.com/](https://getbootstrap.com/)

### React Native

React Native combine les meilleures parties du développement natif avec React, une bibliothèque JavaScript de premier ordre pour la création d'interfaces utilisateur.

Utilisez-en un peu ou beaucoup. Vous pouvez utiliser React Native aujourd'hui dans vos projets Android et iOS existants ou vous pouvez créer une toute nouvelle application à partir de zéro.

Beaucoup de liberté est laissé à au développeur, le rendu est donc fortement dépendant son niveau. React Native de part sa complexité est déconseillé aux débutants.

[https://reactnative.dev/](https://reactnative.dev/)

## Onsen UI

Pour ce développement nous allons utiliser Onsen UI qui semble être le meilleur choix entre rapidité de développement et rendu final.

OnsenUI peut être utilisé en combinaison avec **JQuery** (déconseillé pour les nouveaux développement), **Angular**, **React** (peu pertinent d'utiliser React avec OnsenUI alors que React Native existe), **Vue JS**, du javascript classique (appelé **Vanilla JS** ou JS nature) ou uniquement du CSS.

Ajouter dans l'entête html les liens vers les librairies Onsen (CSS et javascript).

Vous pouvez télécharger les librairie ou utiliser celle disponible sur les CDNs. Dans le cas d'un téléchargement local il faut aussi télécharger les packs d’icônes.

```html
<link rel="stylesheet" href="/onsenui@2.12.8/css/onsenui.css">
<link rel="stylesheet" href="/onsenui@2.12.8/css/onsen-css-components.min.css">
<script src="/onsenui@2.12.8/js/onsenui.min.js"></script>
```


### Définir les pages

Les pages d'application peuvent être définies à 2 endroits :
- dans des fichiers .html. Dans ce cas ce sont des fichier html incomplets car rappelez vous les pages d'application ne sont pas des pages html.
- dans le fichier .html principal en tant que **template**.

#### Fichier .html

Fichier *home.html*, fragment de page .html, contient une page d'application *ons-page*

```html
<ons-page id="home">
  Bienvenue
<ons-page>
```

#### Template

Un *template* html est un fragment de code html totalement invisible. Il est possible d'y accéder avec du code javascript, le cloner et l'ajouter dans la page en cours.

```html
<template id="home.html">
  <ons-page id="home">
    Bienvenue
  <ons-page>
</template>
```

Lors de la navigation vers la page home.html, OnsenUI regarde d'abord si un template avec l'identifiant home.html existe dans la page courante. Si c'est la cas clone le contenu du template et remplace le contenu actuel par celui-ci. Si aucun template n'est trouve OnsenUI charge par la méthode AJAX le fichier *home.html* et remplace le contenu de la page actuel par celui cloné.

En aucun cas il y a une navigation classique vers le fichier home.html mais une substitution du contenu de la page par un contenu chargé par programmation.

Du fait des 2 méthodes de chargement (fichier par ajax ou template), il est conseillé de nommer les template comme des noms de fichiers .html. D'où l'identifiant *home.html*

![Navigation](xhr.png)

Notez le chargement xhr de la page *home.html*

### Utiliser la navigation

Pour pousser une nouvelle page en premier plan d'affichage, il faut utiliser la méthode javascript *pushPage(page, options)*.

```javascript
myNavigator.pushPage('page2.html');
```

Pour revenir en arrière il ne faut pas utiliser le bouton retour du navigateur, mais un appel à la fonction *popPage*

```javascript
myNavigator.popPage();
```
Une autre méthode consiste à utiliser l'élément *ons-back-button*. Il peut être ajouté sur le côté gauche de la barre d'outils et s'affiche sous forme de flèche.

<!--
Nous pouvons maintenant définir notre [page d'accueil](../home/)
-->

Nous pouvons maintenant définir notre [première page](../seance3/)
