---
title: Couleurs
---
<svg width="0" height="0">
  <defs>
    <pattern id="tenthGrid" width="25" height="25" patternUnits="userSpaceOnUse">
      <path d="M 25 0 L 0 0 0 25" fill="none" stroke="gray" stroke-width="0.5"/>
    </pattern>
    <pattern id="fiftygrid" width="50" height="50" patternUnits="userSpaceOnUse">
      <rect width="50" height="50" fill="url(#tenthGrid)"/>
      <path d="M 50 0 L 0 0 0 50" fill="none" stroke="gray" stroke-width="1"/>
    </pattern>
    <symbol id="grid">
      <rect width="100%" height="100%" fill="url(#fiftygrid)"/>
      <path d="M 500 0 L 500 250 0 250" fill="none" stroke="gray" stroke-width="1"/>
    </symbol>
  </defs>
</svg>

## Couleurs simples

Le SVG utilise le même système de couleur que les feuilles de style css à savoir les couleurs nommées (black, white, red, ...) les couleurs hexadécimale, les couleur rgb et hsl

## Dégradé linéaire 

Le gradient est défini à l'intérieur d'une zone d'1px de longueur. Une mise à l'échelle est opérée pour remplir ensuite la zone de remplissage.

Trés souvent les coordonnées s'expriment en pourcentage

<svg width="500" height="250">
  <use href="#grid"/>
  <defs>
    <linearGradient id="degrade">
    <stop offset="0" stop-color="red"/>
    <stop offset="0.1357" stop-color="orange"/>
    <stop offset="0.2959" stop-color="yellow"/>
    <stop offset="0.4686" stop-color="green"/>
    <stop offset="0.6501" stop-color="blue"/>
    <stop offset="0.8364" stop-color="indigo"/>
    <stop offset="1" stop-color="violet"/>
    </linearGradient>
  </defs>
    <rect x="50" y="50" width="400" height="150" fill="url(#degrade)" />
</svg>

```svg
<defs>
<linearGradient id="degrade">
  <stop  offset="0" stop-color="red"/>
  <stop  offset="0.1357" stop-color="orange"/>
  <stop  offset="0.2959" stop-color="yellow"/>
  <stop  offset="0.4686" stop-color="green"/>
  <stop  offset="0.6501" stop-color="blue"/>
  <stop  offset="0.8364" stop-color="indigo"/>
  <stop  offset="1" stop-color="violet"/>
</linearGradient>
</defs>
<rect ... fill="url(#degrade)" />
```

Les propriétés x1 y1 ; x2 y2 définissent un vecteur de direction pour le dégradé

```svg
<linearGradient id="degrade" x1="0" x2="1" y1="0" y2="1">
``` 

## Dégradé radial 

Le dégradé se propage depuis le centre d'un cercle vers l'extérieur.

<svg width="500" height="250">
  <use href="#grid"/>
  <defs>
    <radialGradient id="degrade2">
    <stop  offset="0" stop-color="red"/>
    <stop  offset="0.5" stop-color="orange"/>
    <stop  offset="1" stop-color="yellow"/>
    </radialGradient>
  </defs>
    <rect x="50" y="50" width="400" height="150" fill="url(#degrade2)" />
</svg>

```svg
<defs>
<radialGradient id="degrade2">
  <stop offset="0" stop-color="red"/>
  <stop offset="0.5" stop-color="orange"/>
  <stop offset="1" stop-color="yellow"/>
</radialGradient>
</defs>
<rect ... fill="url(#degrade2)" />
</svg>
```

## gradientUnits

`userSpaceOnUse` le dégradé s'étend sur toute la surface de l'illustration. La couleur à l'intérieur des objets dépend de leur position

<svg width="550" height="250">
<defs>
  <linearGradient id="userSpaceOnUse" gradientUnits="userSpaceOnUse">
    <stop  offset="0" style="stop-color:red"/>
    <stop  offset="1" style="stop-color:green;"/>
  </linearGradient>
</defs>
  <rect width="100" height="195" fill="url(#userSpaceOnUse)" />
  <rect x="150" width="100" height="195" fill="url(#userSpaceOnUse)" />
  <rect x="300" width="100" height="195" fill="url(#userSpaceOnUse)" />
  <rect x="450" width="100" height="195" fill="url(#userSpaceOnUse)" />
  <rect x=0 y="200" width="550" height="50" fill="url(#userSpaceOnUse)" />
</svg>

`objectBoundingBox` le dégradé s'etend dans les limites de l'objet

<svg width="550" height="250">
<defs>
  <linearGradient id="objectBoundingBox" gradientUnits="objectBoundingBox">
    <stop  offset="0" style="stop-color:red"/>
    <stop  offset="1" style="stop-color:green;"/>
  </linearGradient>
</defs>
  <rect width="100" height="195" fill="url(#objectBoundingBox)" />
  <rect x="150" width="100" height="195" fill="url(#objectBoundingBox)" />
  <rect x="300" width="100" height="195" fill="url(#objectBoundingBox)" />
  <rect x="450" width="100" height="195" fill="url(#objectBoundingBox)" />
</svg>

## Motifs

Pour le remplissage en plus de la couleur il est possible d'utliser un motif qui servira à remplir la forme

<svg width="600" height="300">
  <defs>
    <pattern id="star" viewBox="271 443 12240 12005" width="0.2" height="0.2" x="0.13" y="0">
  <path d="M6760 12443 c-137 -26 -302 -163 -453 -375 -207 -293 -384 -645 -802
    -1598 -347 -790 -486 -1070 -667 -1337 -211 -311 -357 -373 -878 -374 -303 0
    -573 22 -1315 106 -310 36 -666 73 -930 97 -191 17 -792 17 -905 0 -359 -56
    -525 -174 -538 -382 -7 -128 43 -265 161 -442 197 -294 514 -612 1317 -1323
    955 -845 1247 -1174 1290 -1452 37 -234 -95 -656 -453 -1458 -364 -816 -430
    -963 -490 -1110 -252 -611 -352 -998 -318 -1236 31 -222 145 -333 357 -346
    311 -21 768 169 1699 704 749 431 885 508 1051 596 451 240 718 338 924 341
    121 1 161 -10 310 -84 265 -133 574 -380 1300 -1040 1006 -916 1405 -1206
    1752 -1276 102 -21 173 -13 255 27 103 50 160 135 204 304 21 81 23 111 23
    315 0 125 -5 267 -12 320 -51 379 -107 674 -253 1335 -229 1034 -279 1327
    -279 1647 0 162 16 260 55 346 101 221 462 490 1275 952 661 375 831 473 1005
    578 739 446 1065 761 1065 1027 0 155 -96 273 -306 378 -300 150 -748 236
    -1764 342 -1052 108 -1334 148 -1637 225 -387 100 -514 201 -648 515 -117 276
    -211 629 -391 1482 -135 644 -212 973 -289 1237 -115 398 -240 668 -380 824
    -94 105 -221 156 -335 135z"/>
    </pattern>
  </defs>
  <rect x="0"  y="0" width="250" height="200" fill="url(#star)"/>
  <rect x="300"  y="0" width="250" height="200" stroke-width="20" stroke="url(#star)" fill="none"/>
</svg>

```svg
<defs>
  <pattern id="star" viewBox="271 443 12240 12005" width="0.2" height="0.2" x="0.13" y="0">
  <path d="M6760 ..." /> 
</pattern>
```
