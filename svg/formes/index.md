---
title: Formes
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

## Rectangle

Le rectangle est défini par les coordonnées de son sommet en haut à gauche puis par sa largeur et sa hauteur.

<svg width="500" height="250">
  <use href="#grid"/>
  <line x1="40" y1="50" x2="60" y2="50" stroke="#f00000" stroke-width="3" />
  <line x1="50" y1="40" x2="50" y2="60" stroke="#f00000" stroke-width="3" />
  <rect x="50" y="50" width="200" height="100" fill="#3ed124" />
  <text x="125" y="45" text-anchor="middle">100</text>
  <text x="255" y="98" alignment-baseline="baseline">50</text>
</svg>

```svg
<rect x="50" y="50" width="200" height="100" fill="#3ed124" />
```

## Cercle

Le cercle est défini par les coordonnées de son centre et son rayon.

<svg width="500" height="250">
  <use href="#grid"/>
  <circle cx="100" cy="100" r="50" fill="#3ed124" />
  <line x1="100" y1="90" x2="100" y2="110" stroke="#f00000" stroke-width="3" />
  <line x1="90" y1="100" x2="150" y2="100" stroke="#f00000" stroke-width="3" />
  <text x="115" y="95" alignment-baseline="baseline">50</text>
</svg>

```svg
<circle cx="100" cy="100" r="50" fill="#3ed124" />
```

## Ellipse

L'ellipse est définie par les coordonnées de son centre et par ses deux rayons.

<svg width="500" height="250">
  <use href="#grid"/>
  <ellipse cx="150" cy="100" rx="100" ry="50" fill="#3ed124" />
  <line x1="150" y1="50" x2="150" y2="110" stroke="#f00000" stroke-width="3" />
  <line x1="140" y1="100" x2="250" y2="100" stroke="#f00000" stroke-width="3" />
  <text x="155" y="85">50</text>
  <text x="180" y="120">100</text>
</svg>

```svg
<ellipse cx="100" cy="100" rx="100" ry="50" fill="#3ed124" />
```

## Ligne droite

La ligne droite est définie par les coordonnées du point 1 de départ et les coordonnées du point 2 d'arrivée.
La ligne ne peut être remplie par une couleur. Il faut définir un contour pour la voir.

<svg width="500" height="250">
  <use href="#grid"/>
  <line x1="50" y1="50" x2="250" y2="100" stroke="#f00000" stroke-width="3" fill="#3ed124" />
  <text x="50" y="42" text-anchor="middle">50, 50</text>
  <text x="250" y="120" text-anchor="middle">250, 100</text>
</svg>

```svg
<line x1="50" y1="50" x2="250" y2="100" stroke="#f00000" stroke-width="3" />
```

## Polyligne

La polykigne est une ligne brisée, non fermée, entre plusieurs points. C'est un ensemble de segments réliés entre eux. La forme est dite ouverte car le dernier point n'est pas connecté avec le premier. Elle peut tout de même être remplie avec un couleur de fond.

<svg width="500" height="250">
  <use href="#grid"/>
  <polyline points="50,200 100,125 200,175 300,50 400, 200" stroke="#f00000" stroke-width="3" fill="#3ed124" />
  <text x="3" y="198">50, 200</text>
  <text x="100" y="120" text-anchor="middle">100, 125</text>
  <text x="200" y="190" text-anchor="middle">200, 175</text>
  <text x="300" y="45" text-anchor="middle">300, 50</text>
  <text x="400" y="220" text-anchor="middle">400, 200</text>
</svg>

```svg
<polyline points="50,200 100,125 200,175 300,50 400, 200"
    stroke="#f00000" stroke-width="3" fill="#3ed124" />
```

### liste de points

La liste de points consiste en suite de 2 nombres, le premier pour l'abscisse le deuxième pour l'ordonnée. Les points et les coordonnées sont séparés au choix par un espace ou par une virgule.

La virgule décimale est représentée par un point : 50.425

<svg width="500" height="250">
  <use href="#grid"/>
  <polyline points="50,25 100,75 200,25 300,50 400,25" stroke="#f00000" stroke-width="3" fill="none" />
  <polyline points="50 75,100 125,200 75,300 100,400 75" stroke="#f00000" stroke-width="3" fill="none" />
  <polyline points="50 125 100 175 200 125 300 150 400 125" stroke="#f00000" stroke-width="3" fill="none" />
  <polyline points="50 175,100,225,200,175 300 200 400, 175" stroke="#f00000" stroke-width="3" fill="none" />
</svg>

```svg
<polyline points="50,25 100,75 200,25 300,50 400,25" ... />
<!-- Les points sont séparés par une virgule les coordonnées par un espace -->

<polyline points="50 75,100 125,200 75,300 100,400 75" ... />
<!-- Les points sont séparés par un espace les coordonnées par une virgule -->

<polyline points="50 125 100 175 200 125 300 150 400 125" ... />
<!-- Les points et les coordonnées sont séparées par un espace -->

<polyline points="50 175,100,225,200,175 300 200 400, 175" ... />
<!-- Les points et les coordonnées sont séparées par un espace ou ue virgule.
     Le chemin est valide mais la relecture est difficile. -->
```

## Polygone

Le polygone est une polyligne dont le dernier point est connecté avec le premier. La forme est automatiquement fermée.

<svg width="500" height="250">
  <use href="#grid"/>
  <polygon points="50,150 150,200 250,100 200,50" stroke="#f00000" stroke-width="3" fill="#3ed124" />
  <text x="30" y="140" text-anchor="middle">50, 150</text>
  <text x="150" y="215" text-anchor="middle">150, 200</text>
  <text x="253" y="98">250, 100</text>
  <text x="198" y="46" text-anchor="middle">200, 50</text>
</svg>

```svg
<polygon points="50 150, 150 205, 250 100, 350 120"
    fill="#3ed124" stroke="#f00000" stroke-width="3" />
```

### Règle de remplissage

Dans le cas où les segments se croisent, l'attribut fill-rule définit l'algorithme à utiliser pour déterminer les parties qui sont considérées à l'intérieur de la forme.

<svg width="500" height="250">
  <use href="#grid"/>
  <polygon points="100,25 50,125 175,50 25,50 150,125"
    stroke="#f00000" stroke-width="3" fill="#3ed124" fill-rule="nonzero" />
  <polygon points="300,25 250,125 375,50 225,50 350,125"
    stroke="#f00000" stroke-width="3" fill="#3ed124" fill-rule="evenodd" />
</svg>


```svg
<polygon points="100,25 50,125 175,50 25,50 150,125" stroke="#f00000" stroke-width="3" fill="#3ed124" fill-rule="nonzero" />
<polygon points="300,25 250,125 375,50 225,50 350,125" stroke="#f00000" stroke-width="3" fill="#3ed124" fill-rule="evenodd" />
```
evenodd
fill-rule est un attribut de présentation vous pouvez l'utiliser dans un feuille de style CSS.


## Les chemins

Les chemins sont plus compliqués, ils intègrent des portions en ligne ou en courbe. Des commandes permettent de savoir comment dessiner chaque portion.

<svg width="500" height="250">
  <use href="#grid"/>
  <path d="M 208.2973,14.715129 A 59.083692,63.810728 0 0 0 154.73861,51.247982 59.083692,63.810728 0 0 0 41.983458,78.647627 c 0,66.976923 112.755152,155.264663 112.755152,155.264663 0,0 112.75513,-88.28774 112.75513,-155.264663 A 59.196446,63.932505 0 0 0 208.2973,14.715129 Z" fill="#3ed124" />
  <path d="M 50,150
    C 100,50 225,100 350,150
    Z" fill="#3ed124"/>
  <line x1="50" y1="150" x2="100" y2="50" stroke="#f00000" stroke-width="3"  />
  <line x1="350" y1="150" x2="225" y2="100" stroke="#f00000" stroke-width="3"  />
</svg>

```svg
<path d="M 208.2973,14.715129 A 59.083692,63.810728 0 0 0 154.73861,51.247982 59.083692,63.810728 0 0 0 41.983458,78.647627 c 0,66.976923 112.755152,155.264663 112.755152,155.264663 0,0 112.75513,-88.28774 112.75513,-155.264663 A 59.196446,63.932505 0 0 0 208.2973,14.715129 Z" fill="#3ed124">
```

Les commandes sont définies par des lettres, les lettres majuscules prennent en compte des coordonnées absolues tandis que les lettres minuscules travaillent en coordonnées relativement au point précédent.

<svg width="500" height="250">
  <use href="#grid"/>
  <path d="M 50 125
    C 100 50 225 50 350 100
    V 200
    H 250
    Q 200 125 50 175
    Z"
    fill="#3ed124"/>
    <text x="26" y="100" text-anchor="middle">M</text>
    <text x="26" y="118" text-anchor="middle">50, 125</text>
    <text x="190" y="63" text-anchor="middle">C</text>
    <text x="360" y="90" text-anchor="middle">350, 100</text>
    <text x="360" y="145" text-anchor="middle">V</text>
    <text x="300" y="218" text-anchor="middle">H</text>
    <text x="160" y="170" text-anchor="middle">Q</text>
    <text x="38" y="147" text-anchor="middle">Z</text>
</svg>

```svg
<path d="M 50 125
  C 100 50 225 50 350 100
  V 200
  H 250
  Q 200 125 50 175
  Z" />
```

Si une plusieurs commandes identiques se suivent il n'est pas nécessaire de répéter la lettre de la commande. Il suffit de mettre les points les uns à la suite des autres comme pour une polyligne.

### Commande M, m
`Move to` : se rendre à un point sans dessiner. Toujours pour le premier point. Ensuite si la forme complexe est consititué de plusieurs parties.

### Commande Z, z
`ClosePath` Fermer le tracé : Se rendre au premier point en ligne droite.  Il n’y a pas de différence entre la commande en majuscule et en minuscule.

### Commande L, l
`Line to` : Line droite vers le point. Identique à polyline

### Commande H, h
`Horizontal line to` : Ligne Horizontale

### Commande V, v
`Vertical line to` : Ligne Verticale

<svg width="500" height="250">
  <use href="#grid"/>
  <path d="M 50 50
    V 200
    H 100
    L 150 150 200 200 250 150
    v -50
    h -50
    Z"
    fill="#3ed124"/>
    <text x="40" y="117" text-anchor="middle">V</text>
    <text x="70" y="218" text-anchor="middle">H</text>
    <text x="180" y="198" text-anchor="middle">L</text>
    <text x="258" y="137" text-anchor="middle">v</text>
    <text x="225" y="96" text-anchor="middle">h</text>
    <circle cx="150" cy="150" r="5" fill="#0000c0" />
    <circle cx="200" cy="200" r="5" fill="#0000c0" />
    <circle cx="250" cy="150" r="5" fill="#0000c0" />
</svg>

```svg
<path d="M 50 50
  V 200
  H 100
  L 150 150 200 200 250 150
  v -50
  h -50
  Z" />
```

### Commande A, a
`Arc` : Arc elliptique 7 nombres sont nécessaires : rayon x, rayon y, inclinaison de l'axe x en dégrés, grand côté ou petit côté, angle positif ou négatif, coordonnées du point d'arrivé.

Les cordonnées du centre de l'ellipse et les rayons réels sont calculés pour satisfaire les conditions des points d'arrivée.

Pour un rayon rx et un rayon ry donnés, il existe deux ellipses A et B pouvant connecter deux points quelconques.

Pour chacune des deux ellipses, il existe deux chemins possibles, ce qui donne quatre arcs possibles.

`large-arc-flag` (0 ou 1) détermine si l’arc doit être supérieur ou inférieur à 180 degrés ; au final, il détermine dans quelle direction l’arc va parcourir une ellipse donnée.

`sweep-flag` (0 ou 1) détermine si l’arc doit commencer son mouvement à un angle négatif ou positif, permettant ainsi de choisir lequel des deux cercles est parcouru.

<svg width="500" height="250">
  <use href="#grid"/>
  <path d="M 100 100, A 100 50, 30 1 1, 250 150"
    stroke="red" stroke-width="6" fill="#3ed124" />
  <path d="M 100 100, A 100 50, 30 0 1, 250 150"
     fill="none" stroke="#00f" stroke-width="2" />
  <path d="M 100 100, A 100 50, 30 0 0, 250 150"
     fill="none" stroke="#f0f" stroke-width="2" />
  <path d="M 100 100, A 100 50, 30 1 0, 250 150"
     fill="none" stroke="#663600" stroke-width="2" />
  <text x="180" y="30" text-anchor="middle">A</text>
  <text x="180" y="95" text-anchor="middle">B</text>
  <text x="180" y="170" text-anchor="middle">C</text>
  <text x="180" y="230" text-anchor="middle">D</text>
  <circle cx="100" cy="100" r="5" fill="#0000c0" />
  <circle cx="250" cy="150" r="5" fill="#0000c0" />
</svg>

```svg
<path d="M 100 100, A 100 50, 30 1 1, 250 150" class="A" />
<path d="M 100 100, A 100 50, 30 0 1, 250 150" class="B" />
<path d="M 100 100, A 100 50, 30 0 0, 250 150" class="C" />
<path d="M 100 100, A 100 50, 30 1 0, 250 150" class="D" />
```

L'illustration dans cette page ne fonctionne pas avec Firefox.

### Commande Q, q, T, t
Courbe quadratique : coordonnées du point de contrôle et coordonnées du point d'arrivée

<svg width="500" height="250">
  <use href="#grid"/>
  <path d="M 25 150
    Q 275 75, 325 150
    Z" fill="#3ed124"/>
  <line x1="25" y1="150" x2="275" y2="75" stroke="#f00000" stroke-width="3"  />
  <line x1="275" y1="75" x2="325" y2="150" stroke="#f00000" stroke-width="3"  />
  <circle cx="275" cy="75" r="5" fill="#0000c0" />
</svg>

```svg
<path d="M 0, 150
  Q 250 75, 300 150
  Z" />
```

T : Prolongation d'une courbe quadratique : Seules les coordonnées du point d'arrivée sont renseignés. Le point de contrôle de la commande T est le symétrique de la commande Q précédente.

<svg width="500" height="250">
  <use href="#grid"/>
  <line x1="25" y1="150" x2="275" y2="75" stroke="#f00000" stroke-width="3"  />
  <line x1="275" y1="75" x2="325" y2="150" stroke="#f00000" stroke-width="3"  />
  <line x1="325" y1="150" x2="375" y2="225" stroke="#f00000" stroke-width="3"  />
  <line x1="475" y1="150" x2="375" y2="225" stroke="#f00000" stroke-width="3"  />
  <path d="M 25 150
    Q 275 75, 325 150
    T 475 150
    Z" fill="#3ed124"/>
  <circle cx="275" cy="75" r="5" fill="#0000c0" />
  <circle cx="375" cy="225" r="5" fill="#00ffff" />
</svg>

```svg
<path d="M 0, 150
  Q 250 75, 300 150
  T 450 150
  Z" />
```


### Commande C, c, S, s
C `CurveTo` :  Courbe cubique (ou courbe de Bézier) : 2 points de contrôle et un point d'arrivée

<svg width="500" height="250">
  <use href="#grid"/>
  <path d="M 50,150
    C 100 50, 225 100, 350 150
    Z" fill="#3ed124"/>
  <line x1="50" y1="150" x2="100" y2="50" stroke="#f00000" stroke-width="3" />
  <line x1="350" y1="150" x2="225" y2="100" stroke="#f00000" stroke-width="3" />
  <circle cx="100" cy="50" r="5" fill="#0000c0" />
  <circle cx="225" cy="100" r="5" fill="#0000c0" />
</svg>

```svg
<path d="M 0, 150
  C 100 50, 225 100, 350 150
  T 450 150
  Z" />
```

S `Shorthand CuveTo` : Prolongation d'une courbe de Bézier cubique, le premier point d'inflexion est le symétrique du point d'inflexion de la courbe précédente

<svg width="500" height="250">
  <use href="#grid"/>
  <path d="M 50 150
    C 100 50, 200 100, 250 150
    S 400 225 450 150
    Z" fill="#3ed124"/>
  <line x1="50" y1="150" x2="100" y2="50" stroke="#f00000" stroke-width="3"  />
  <line x1="250" y1="150" x2="200" y2="100" stroke="#f00000" stroke-width="3"  />
  <line x1="250" y1="150" x2="300" y2="200" stroke="#f00000" stroke-width="3"  />
  <line x1="450" y1="150" x2="400" y2="225" stroke="#f00000" stroke-width="3"  />
  <circle cx="100" cy="50" r="5" fill="#0000c0" />
  <circle cx="200" cy="100" r="5" fill="#0000c0" />
  <circle cx="300" cy="200" r="5" fill="#00ffff" />
  <circle cx="400" cy="225" r="5" fill="#0000c0" />
</svg>

```svg
<path d="M 0, 150
  C 50 50, 150 100, 200 150
  S 350 225, 400 150
  Z" />
```

L'utilisation d'un logiciel comme inkscape n'optimise pas forcement les commandes, mais cela est bien plus pratique pour dessiner des formes complexes.

[Exercice](exercice)
