---
title: Séance 1
---

Pour accélérer le développement nous allons utiliser le framework [OnsenUI](../onsenui/) qui permet d'utiliser des composants prédéfinis et obtenir un affichage semblable à ce que l'on trouve dans les applications natives.

## Single Page Application

Le point départ est donc tout naturellement **une** page **html**.

```html
<!DOCTYPE html>
<html lang="fr">
<head>
  <meta charset="UTF-8">
  <title>Cinéma</title>
</head>

<body>
</body>
</html>
```

Ajouter dans l'entête html les liens vers les librairies Onsen (CSS et javascript).

Vous pouvez télécharger les librairies ou utiliser celle disponible sur les CDNs. Dans le cas d'un téléchargement local il faut aussi télécharger les packs d’icônes.

```html
<link rel="stylesheet" href="/onsenui@2.12.8/css/onsenui.css">
<link rel="stylesheet" href="/onsenui@2.12.8/css/onsen-css-components.min.css">
<script src="/onsenui@2.12.8/js/onsenui.min.js"></script>
```

## Page d'accueil

```svg
<svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 32 35">
  <path fill="#663399" d="M 0 0 h 32 v 30 q -16 5 -32 0" />
  <text fill="#fff" x="16" y="5" font-size="3" text-anchor="middle">Cinéma</text>
  <path fill="#fff"
    d="m 7.49,13.72 v 8.9 a 1.92,1.92 0 0 0 1.92,1.92 h 13.8 a 1.92,1.92 0 0 0 1.92,-1.92 v -7.93 a 1,1 0 0 0 -1,-1 H 7.49 m 10.84,5.81 -2.56,2 a 0.53,0.53 0 0 1 -0.75,0 0.51,0.51 0 0 1 -0.15,-0.37 V 17.1 a 0.52,0.52 0 0 1 0.9,-0.37 l 2.56,2 a 0.53,0.53 0 0 1 0,0.77 z" />
  <path fill="#fff"
    d="M 24.83,10.33 24.56,8.39 A 1,1 0 0 0 23.47,7.57 h -0.3 l -1,3.11 -2.79,0.39 1,-3.11 -1.07,0.15 -1.58,0.22 -1,3.11 -2.73,0.42 1,-3.1 -1.1,0.15 -1.55,0.22 -1,3.1 -2.78,0.39 1,-3.11 -1.67,0.23 a 1,1 0 0 0 -0.82,1.08 v 0 l 0.28,2 0.13,0.93 L 24,11.42 a 1,1 0 0 0 0.83,-1.08 z" />
</svg>
```

<svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 32 35" width="320" height="480">
  <path fill="#663399" d="M0 0h32v30q-16 5 -32 0" />
  <text fill="#fff" x="16" y="5" font-size="3" text-anchor="middle">Cinéma</text>
  <path fill="#fff"
    d="m 7.49,13.72 v 8.9 a 1.92,1.92 0 0 0 1.92,1.92 h 13.8 a 1.92,1.92 0 0 0 1.92,-1.92 v -7.93 a 1,1 0 0 0 -1,-1 H 7.49 m 10.84,5.81 -2.56,2 a 0.53,0.53 0 0 1 -0.75,0 0.51,0.51 0 0 1 -0.15,-0.37 V 17.1 a 0.52,0.52 0 0 1 0.9,-0.37 l 2.56,2 a 0.53,0.53 0 0 1 0,0.77 z" />
  <path fill="#fff"
    d="M 24.83,10.33 24.56,8.39 A 1,1 0 0 0 23.47,7.57 h -0.3 l -1,3.11 -2.79,0.39 1,-3.11 -1.07,0.15 -1.58,0.22 -1,3.11 -2.73,0.42 1,-3.1 -1.1,0.15 -1.55,0.22 -1,3.1 -2.78,0.39 1,-3.11 -1.67,0.23 a 1,1 0 0 0 -0.82,1.08 v 0 l 0.28,2 0.13,0.93 L 24,11.42 a 1,1 0 0 0 0.83,-1.08 z" />
</svg>

#### Icônes

fa-map-marker, fa-theater-masks, fa-ticket

```html
<div style="display: flex; justify-content: space-evenly">
  <div class="icone"><ons-icon icon="fa-map-marker" size="9vw"
      onclick="onsenNavigator.pushPage('carte.html')" />
  </div>
  <div class="icone">
    <ons-icon icon="fa-theater-masks" size="9vw"
      onclick="onsenNavigator.pushPage('acteurs.html')" />
  </div>
  <div class="icone">
    <ons-icon icon="fa-ticket" size="9vw"
      onclick="onsenNavigator.pushPage('ticket.html')" />
  </div>
</div>
```

```css
<style>
  .icone {
    background-color: #663399;
    color: #fff;
    border-radius: 50%;
    width: 18vw;
    height: 18vw;
    display: flex;
    justify-content: center;
    align-items: center;
  }
</style>
```
