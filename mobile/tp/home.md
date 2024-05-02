---
title: Page d’accueil
date: 2022-05-03T15:18:26+01:00
draft: false
---

Ajouter le logo au format svg à l'intérieur du code de la page d'accueil.

L'inclusion en ligne (inline) de fichier SVG doit toujours être préférée à l'utilisation comme une simple image avec la balise *img* ou à l'inclusion totalement obsolète avec une balise *object*.

L'avantage d'une inclusion en ligne est de pouvoir contrôler l'illustration SVG avec le CSS de la page et de le manipuler avec du javascript. Ce qui n'est pas possible avec la balise *img*.

```svg
<svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 32 32">
  <path fill="#fff"
      d="m 7.49,13.72 v 8.9 a 1.92,1.92 0 0 0 1.92,1.92 h 13.8 a 1.92,1.92 0 0 0 1.92,-1.92 v -7.93 a 1,1 0 0 0 -1,-1 H 7.49 m 10.84,5.81 -2.56,2 a 0.53,0.53 0 0 1 -0.75,0 0.51,0.51 0 0 1 -0.15,-0.37 V 17.1 a 0.52,0.52 0 0 1 0.9,-0.37 l 2.56,2 a 0.53,0.53 0 0 1 0,0.77 z" />
  <path fill="#fff"
      d="M 24.83,10.33 24.56,8.39 A 1,1 0 0 0 23.47,7.57 h -0.3 l -1,3.11 -2.79,0.39 1,-3.11 -1.07,0.15 -1.58,0.22 -1,3.11 -2.73,0.42 1,-3.1 -1.1,0.15 -1.55,0.22 -1,3.1 -2.78,0.39 1,-3.11 -1.67,0.23 a 1,1 0 0 0 -0.82,1.08 v 0 l 0.28,2 0.13,0.93 L 24,11.42 a 1,1 0 0 0 0.83,-1.08 z" />
</svg>
```

Ajouter la forme de fond.

```svg
<path fill="#663399" d="M0 0h32v30q-16 6 -32 0" />
```
