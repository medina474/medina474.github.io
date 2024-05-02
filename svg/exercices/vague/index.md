---
layout: layouts/page.njk
title: Animation - Exercice
---

Créer une `vague` à l'aide d'un chemin.

<svg xmlns="http://www.w3.org/2000/svg" width="700" height="100" viewBox="0 0 700 100">
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
   <use href="#grid"/>
<path fill="red" opacity="0.5"
 d="M0,25
 C 50 25, 50 40, 100 40
 C 180 40 200 10 300 10
 S 400 40 500 40
 C 535 40 550 25 600 25
 C 650 25, 650 40, 700 40
 V 100 H 0 Z
 H 0 Z" />
  <circle cx="0" cy="25" r="3" fill="black" />
  <text x="5" y="20" fill="#000">A</text>
  <circle cx="100" cy="40" r="3" fill="black" />
  <text x="100" y="30" fill="#000" text-anchor="middle">B</text>
  <circle cx="300" cy="10" r="3" fill="black" />
  <text x="300" y="30" fill="#000" text-anchor="middle">C</text>
  <circle cx="500" cy="40" r="3" fill="black" />
  <text x="500" y="30" fill="#000" text-anchor="middle">D</text>
  <circle cx="600" cy="25" r="3" fill="black" />
  <text x="600" y="20" fill="#000" text-anchor="middle">E</text>
  <circle cx="700" cy="40" r="3" fill="black" />
  <text x="695" y="30" fill="#000" text-anchor="middle">F</text>
  <line x1="0" y1="25" x2="50" y2="25" stroke="blue" stroke="1" />
  <line x1="50" y1="40" x2="180" y2="40" stroke="blue" stroke="1" />
  <line x1="200" y1="10" x2="400" y2="10" stroke="blue" stroke="1" />
  <line x1="400" y1="40" x2="535" y2="40" stroke="blue" stroke="1" />
  <line x1="550" y1="25" x2="650" y2="25" stroke="blue" stroke="1" />
  <line x1="650" y1="40" x2="700" y2="40" stroke="blue" stroke="1" />
</svg>

Coordonnées des points :
- **A** : 0, 25
- **B** : 100, 40
- **C** : 300, 10
- **D** : 500, 40
- **E** : 600, 25
- **F** : 700, 40

Points d'inflexion :
- [AB] : 50,25 et 50,40
- [BC] : 180,40 et 200,10
- [CD] : symétrique de 200, 10 par raport à C et 400, 40 pour D
- [DE] : 535,40 et 550,25
- [EF] : 650,25 et 650,40

Il est important que la portion de courbe [EF] soit identique à [AB],

Terminer par des segment verticaux et horizontaux pour compléter la forme par en dessous et revenir à l'origine.

La forme fait 700px de large et nous allons créer une fenètre de 100 px de large.
Les 100px de la fin de la courbe sont identique aux 100px du début, c'est important pour avoir une transition fluide lorsque l'animation va repartir au début.

```svg
<svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 100 150">
</svg>
```

Ajouter une animation de transformation pour décaler la forme vers la gauche (déplacement négatif) de 600 px. Recommencer l'animation à l'infini.

```svg
<animateTransform attributeName="transform"
  attributeType="XML"
  type="translate"
  from="-600"
  to="0"
  dur="9s"
  repeatCount="indefinite"/>
```

Répéter la forme 3 fois en modifiant la vitesse de l'animation. Appliquer une opacité différente sur les 3 formes.

<div style="width:100%;height:200px;background:url(wave.svg) no-repeat; background-size: cover;background-position:bottom"></div>
