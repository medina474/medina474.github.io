---
layout: layouts/page.njk
title: Fragments SVG
date: Last Modified
---

Les fichiers svg peuvent être utilisé comme source pour les balises images `<img>`. Il sont considérés comme des fichiers classiques jpg ou png.

Créer un fichier svg appelé `sprite.svg`

Ajouter ces 3 formes au fichier SVG

```svg
<path d="M 16,0 C 7.163,0 0,7.163 0,16 0,24.837 7.163,32 16,32 24.837,32 32,24.837 32,16 32,7.163 24.837,0 16,0 Z m 0,29 C 8.82,29 3,23.18 3,16 3,8.82 8.82,3 16,3 23.18,3 29,8.82 29,16 29,23.18 23.18,29 16,29 Z M 12,9 24,16 12,23 Z" />
<path d="M 48,0 C 39.163,0 32,7.163 32,16 32,24.837 39.163,32 48,32 56.837,32 64,24.837 64,16 64,7.163 56.837,0 48,0 Z m 0,29 C 40.82,29 35,23.18 35,16 35,8.82 40.82,3 48,3 55.18,3 61,8.82 61,16 61,23.18 55.18,29 48,29 Z M 42,10 h 4 v 12 h -4 z m 8,0 h 4 v 12 h -4 z" />
<path d="M 80,0 C 71.163,0 64,7.163 64,16 64,24.837 71.163,32 80,32 88.837,32 96,24.837 96,16 96,7.163 88.837,0 80,0 Z m 0,29 C 72.82,29 67,23.18 67,16 67,8.82 72.82,3 80,3 87.18,3 93,8.82 93,16 93,23.18 87.18,29 80,29 Z M 74,10 H 86 V 22 H 74 Z" />
```

Ajouter dans une page html une image avec le fichier svg comme source. Visualiser la page : Nous avons 3 icônes l'une à côté de l'autre.

```html
<img src="sprite.svg">
```

<img src="sprite.svg">



Récupérer qu'un fragment du svg en définissant un viewbox personnalisé dans l'url

```html
<img src="sprite.svg#svgView(viewBox(64, 0, 32, 32))"
    alt="stop" width="64" height="64">
```

<img src="sprite.svg#svgView(viewBox(64, 0, 32, 32))" alt="pause" width="64" height="64">

Ou en définissant des viewbox prédéfinis dans le svg.

```svg
<defs>
  <view id="icon-play" viewBox="0 0 32 32" />
  <view id="icon-pause" viewBox="32 0 32 32" />
  <view id="icon-stop" viewBox="64 0 32 32" />
</defs>
```

Et en appelant directement avec l’identifiant `ìd`

```html
<img src="sprite.svg#icon-pause"
    alt="pause" width="64" height="64">
```

<img src="sprite.svg#icon-pause" alt="pause" width="64" height="64">
