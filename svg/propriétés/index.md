---
title: Propriétés
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

## Remplissage

<svg width="500" height="250">
  <use href="#grid" />
  <rect x="50" y="50" width="300" height="150"  fill="#3ed124" />
</svg>

```svg
<rect fill="#3ed124" ... />
```

La propriété fill permet de définir la couleur de remplissage.

## Contour

<svg width="500" height="250">
  <use href="#grid" />
  <rect x="50" y="50" width="300" height="150"  fill="#3ed124" stroke="red" stroke-width="20"/>
  <line x1="25" y1="50" x2="375" y2="50" stroke="black" />
  <line x1="25" y1="200" x2="375" y2="200" stroke="black" />
  <line x1="50" y1="25" x2="50" y2="225" stroke="black" />
  <line x1="350" y1="25" x2="350" y2="225" stroke="black" />
</svg>

```svg
<rect stroke="red" stroke-width="20" ... />
```

Un contour se défini par sa couleur et par sa largeur.

Le contour se situe centré sur la forme, il n'est pas possible de positionner totalement à l'extérieur ou totalement à l'intérieur.

## Opacité

<svg width="500" height="250">
  <use href="#grid"/>
  <circle cx="100" cy="100" r="60" fill="#3ed124" fill-opacity="0.5" stroke="#f00000" stroke-width="20" />
  <circle cx="250" cy="100" r="60" fill="#3ed124" stroke="#f00000" stroke-width="20" stroke-opacity="0.5" />
  <circle cx="400" cy="100" r="60" fill="#3ed124" opacity="0.5" stroke="#f00000" stroke-width="20" opacity="0.5" />
</svg>

```svg
<cicle fill-opacity="0.5" .../>
<circle stroke-opacity="0.6" .../>
<cicle opacity="0.5" ... />
```

Du fait la position du contour à cheval sur la forme, l'opacité de contour apparait différement suivant qu'elle est sur la forme ou sur le fond.

## Coins arrondis

<svg width="500" height="250">
  <use href="#grid"/>
  <rect x="50" y="50" width="100" height="150" rx="25" ry="25" fill="#3ed124" />
  <line x1="75" y1="45" x2="75" y2="75" stroke="#f00000" stroke-width="3" />
  <line x1="45" y1="75" x2="75" y2="75" stroke="#f00000" stroke-width="3" />
  <text x="75" y="90">25</text>

  <rect x="200" y="50" width="100" height="150" rx="50" ry="50" fill="#3ed124" />
  <line x1="250" y1="45" x2="250" y2="100" stroke="#f00000" stroke-width="3" />
  <line x1="195" y1="100" x2="250" y2="100" stroke="#f00000" stroke-width="3" />
  <text x="250" y="115">50</text>

  <rect x="350" y="50" width="100" height="150" rx="25" ry="50" fill="#3ed124" />
  <line x1="375" y1="45" x2="375" y2="100" stroke="#f00000" stroke-width="3" />
  <line x1="345" y1="100" x2="375" y2="100" stroke="#f00000" stroke-width="3" />
  <text x="360" y="118">25</text>
  <text x="382" y="85">50</text>
</svg>

```svg
<rect ... rx="25" ry="25" />
<rect ... rx="50" ry="50" />
<rect ... rx="25" ry="50" />
```

## Fin de ligne

<svg width="500" height="250">
  <use href="#grid"/>
  <line x1="25" y1="50" x2="300" y2="50" stroke="#3ed124" stroke-width="25" stroke-linecap="butt" />
  <line x1="25" y1="100" x2="300" y2="100" stroke="#3ed124" stroke-width="25" stroke-linecap="round"/>
  <line x1="25" y1="150" x2="300" y2="150" stroke="#3ed124" stroke-width="25" stroke-linecap="square"/>
  <line x1="25" y1="50" x2="300" y2="50" stroke="#000" stroke-width="3" stroke-linecap="butt"/>
  <line x1="25" y1="100" x2="300" y2="100" stroke="#000" stroke-width="3" stroke-linecap="butt"/>
  <line x1="25" y1="150" x2="300" y2="150" stroke="#000" stroke-width="3" stroke-linecap="butt"/>
</svg>

```svg
<line ... stroke-linecap="butt" />
<line ... stroke-linecap="round" />
<line ... stroke-linecap="square" />
```

## Jointure de l'angle

<svg width="500" height="250">
<use href="#grid" />
  <polyline points="30.25 150 50 50 69.75 150" stroke="#f00000" stroke-width="15" stroke-linejoin="round" fill="none"/>
  <polyline points="130.25 150 150 50 169.75 150" stroke="#f00000" stroke-width="15" stroke-linejoin="miter" stroke-miterlimit="10" fill="none"/>
  <polyline points="330.25 150 350 50 369.75 150" stroke="#f00000" stroke-width="15" stroke-linejoin="bevel" fill="none"/>

  <polyline points="230.25 150 250 50 269.75 150" stroke="#f00000" stroke-width="15" stroke-linejoin="miter-clip" stroke-miterlimit="5" fill="none"/>
  <polyline points="430.25 150 450 50 469.75 150" stroke="#f00000" stroke-width="15" stroke-linejoin="arcs" fill="none"/>
</svg>

```svg
<polyline stroke-linejoin="round" />
<polyline stroke-linejoin="miter" />
<polyline stroke-linejoin="bevel" />
<polyline stroke-linejoin="miter-clip" />
<polyline stroke-linejoin="arcs" />
```

round
: Un coin arrondi est utilisé pour joindre les segments

miter
: Les segments sont prolongés pour former une pointe. La prolongation s'effectue en ligne droite.

bevel
: Le sommet est biseauté au point de jonction des 2 segments.

miter-clip
: Compromis entre le biseau et la pointe. Si celle-ci est trop grande et dépasse la limite acceptable (voir la propriété `stroke-miterlimit` plus bas)
Un biseau est appliqué à mi-hauteur, et non pas à l'intersection. Cette propriétés n'est pas encore implémentée dans les navigateurs.

arcs
: Les segments sont prolongés pour former une pointe. La prolongation prend en compte les rayons des segments courbes. Cette propriétés n'est pas encore implémentée dans les navigateurs.

## Limitation des angles aigus

La propriété `stroke-miterlimit` définit la limite de la pointe d'un angle aigu. Quand la limite est dépassée, le sommet est converti en biseau.

La taille de la pointe est calculée à partir du point de jonction intérieur jusqu'au sommet, la taille est exprimée en fonction de l'épaisseur du contour.

Proportion de la pointe = 1 / sin( &Theta; / 2)

Épaisseur = 40\
Points : 50,75 250,125 et 50,175\
Demi angle = ArcTan( (125-75) / (250-50) ) = **14°**\
Pointe = 1 / (sin (14)) = **4.12**\
Longeur de la pointe = 4.12 x 40 = **165**

Dans ce cas la taille de la pointe est légèrment supérieure à **4x** l'épaisseur du contour.
Si nous définissions la limite à 4 alors la pointe se transforme en biseau.

```svg
<polyline stroke-miterlimit="4" />
```

<svg width="500" height="250">
<marker id="arrow" viewBox="0 0 10 10" refX="5" refY="5"
  markerWidth="6" markerHeight="6"
  orient="auto-start-reverse">
  <path d="M 0 0 L 10 5 L 0 10 z" fill="#00f" />
 </marker>
 <use href="#grid"/>
 <polyline points="50 75 250 125 50 175" stroke="#f00000" stroke-width="40" stroke-miterlimit="4.13" opacity="0.1" fill="none"/>
 <polyline points="50 75 250 125 50 175" stroke="#f00000" stroke-width="40" stroke-miterlimit="4.12" fill="none"/>
 <polyline points="50 75 250 125 50 175" stroke="#000000" stroke-width="4" stroke-miterlimit="1" fill="none"/>
 <polyline points="55.137845,55.451128 332.0802,125.62657 54.511277,194.54887" fill="none" stroke="#00f" stroke-width="2"/>
 <line x1="165" x2="165" y1="50" y2="200" stroke="#00f" stroke-width="2"/>
 <line x1="205" x2="205" y1="50" y2="200" stroke="#00f" stroke-width="2"/>
 <line x1="245" x2="245" y1="50" y2="200" stroke="#00f" stroke-width="2"/>
 <line x1="285" x2="285" y1="50" y2="200" stroke="#00f" stroke-width="2"/>
 <line x1="325" x2="325" y1="50" y2="200" stroke="#00f" stroke-width="2"/>
 <line x1="365" x2="365" y1="50" y2="200" stroke="#00f" stroke-width="2"/>
 <text x="205" y="225" font-size="16" text-anchor="middle">1x</text>
 <text x="245" y="225" font-size="16" text-anchor="middle">2x</text>
 <text x="285" y="225" font-size="16" text-anchor="middle">3x</text>
 <text x="325" y="225" font-size="16" text-anchor="middle">4x</text>
 <text x="365" y="225" font-size="16" text-anchor="middle">5x</text>
 <line x1="168" y1="25" x2="324" y2="25" stroke="#00f" stroke-width="2" marker-start="url(#arrow)" marker-end="url(#arrow)"/>
 <text x="250" y="18" font-size="16" text-anchor="middle">165</text>
 <text x="40" y="130" font-size="16" text-anchor="middle">&Theta;</text>
</svg>

### Fonction de l'angle

<svg width="500" height="250">
  <use href="#grid"/>
  <polyline points="30 150 50 50 70 150" stroke="#f00000" stroke-width="15" stroke-miterlimit="2.6" fill="none"/>
  <text x="50" y="175" font-size="16" text-anchor="middle">23°</text>
  <polyline points="120 150 150 50 180 150" stroke="#f00000" stroke-width="15" stroke-miterlimit="2.6" fill="none"/>
  <text x="150" y="175" font-size="16" text-anchor="middle">33°</text>
  <polyline points="200 150 250 50 300 150" stroke="#f00000" stroke-width="15" stroke-miterlimit="2.6" fill="none"/>
  <text x="250" y="175" font-size="16" text-anchor="middle">53°</text>
  <polyline points="330 150 400 50 480 150" stroke="#f00000" stroke-width="15" stroke-miterlimit="2.6" fill="none"/>
  <text x="400" y="175" font-size="16" text-anchor="middle">70°</text>
</svg>

```svg
<polyline stroke-miterlimit="2.6" />
```

Une limite à 2,6 correspond à un angle inférieur ou égal à ArcSin(1 / 2.6) soit 45°

## Pointillés

<svg width="500" height="250">
<use href="#grid"/>
<line x1="50" y1="25" x2="50" y2="75" stroke="#0df" stroke-width="3" />
<line x1="450" y1="25" x2="450" y2="75" stroke="#0df" stroke-width="3" />
<line x1="20" y1="50" x2="50" y2="50" stroke="red" opacity="0.30"
  stroke-width="20"/>
<line x1="450" y1="50" x2="470" y2="50" stroke="red" opacity="0.30"
  stroke-width="20"/>
<line x1="50" y1="50" x2="450" y2="50" stroke="black"
  stroke-dasharray="90 30"
  stroke-dashoffset="30"
  stroke-width="20"/>
<text x="65" y="25" font-size="16" text-anchor="middle">90</text>
<text x="125" y="25" font-size="16" text-anchor="middle">30</text>
<text x="185" y="25" font-size="16" text-anchor="middle">90</text>
<text x="245" y="25" font-size="16" text-anchor="middle">30</text>
<text x="305" y="25" font-size="16" text-anchor="middle">90</text>
<text x="365" y="25" font-size="16" text-anchor="middle">30</text>
<text x="425" y="25" font-size="16" text-anchor="middle">90</text>
<line x1="50" y1="125" x2="50" y2="175" stroke="#0df" stroke-width="3" />
<line x1="450" y1="125" x2="450" y2="175" stroke="#0df" stroke-width="3" />
<line x1="50" y1="150" x2="450" y2="150" stroke="black"
  stroke-dasharray="90 30 30 60"
  stroke-dashoffset="-30"
  stroke-width="20"/>
<text x="125" y="125" font-size="16" text-anchor="middle">90</text>
<text x="185" y="125" font-size="16" text-anchor="middle">30</text>
<text x="215" y="125" font-size="16" text-anchor="middle">30</text>
<text x="260" y="125" font-size="16" text-anchor="middle">60</text>
<text x="335" y="125" font-size="16" text-anchor="middle">90</text>
<text x="395" y="125" font-size="16" text-anchor="middle">30</text>
<text x="425" y="125" font-size="16" text-anchor="middle">30</text>
</svg>

```svg
<line x1="50" y1="50" x2="450" y2="50" stroke="black"
  stroke-dasharray="90 30"
  stroke-dashoffset="30"
  stroke-width="20"/>

<line x1="50" y1="150" x2="450" y2="150" stroke="black"
  stroke-dasharray="90 30 30 60"
  stroke-dashoffset="-30"
  stroke-width="20"/>
```

`stroke-dasharray` défini le motif à répeter en alternant les pleins et les vides

`stroke-dashoffset` défini le départ du motif. Un nombre positif indique que l'on va commencer plus loin dans le motif, donc on aura l'impression que celui-ci se décale vers la gauche. A l'inverse un nombre négatif indique que l'on va commencer le motif en avance, celui-ci va se décaler vers la droite.

## Marqueurs

Les marqueurs sont des éléments graphiques qui seront ajoutés sur les segments au début à la fin ou sur les point intermédiaires.

<svg width="500" height="250">
<defs>
  <marker id="square" viewBox="0 0 10 10" refX="5" refY="5"
      markerWidth="4" markerHeight="4" fill="red"
      orient="auto-start-reverse">
    <path d="M 0 0 h 10 v 10 h -10 v -10 z" />
  </marker>
  <marker id="arrow2" viewBox="0 0 10 10" refX="5" refY="5"
      markerWidth="6" markerHeight="6" fill="red"
      orient="auto-start-reverse">
    <path d="M 0 0 L 10 5 L 0 10 z" />
  </marker>
  <marker id="dot" viewBox="0 0 10 10" refX="5" refY="5"
      markerWidth="3.5" markerHeight="3.5">
    <circle cx="5" cy="5" r="5" fill="#f00000" />
  </marker>
  </defs>
 <use href="#grid"/>
 <polyline points="50,50 100,100 150,75 200,150 250,125 300,200" fill="none" stroke="red" stroke-width="3"
   marker-start="url(#square)" marker-mid="url(#dot)"  marker-end="url(#arrow2)" />
</svg>

```svg
<defs>
  <marker id="square"
    viewBox="0 0 10 10"
    refX="5" refY="5"
    markerWidth="4" markerHeight="4"
    fill="red"
    orient="auto-start-reverse">
    <path d="M 0 0 h 10 v 10 h -10 v -10 z" />
  </marker>

  <marker id="dot" viewBox="0 0 10 10" refX="5" refY="5"
    markerWidth="3.5" markerHeight="3.5">
    <circle cx="5" cy="5" r="5" fill="#f00000" />
  </marker>
</defs>
```

Dans un bloc de définition (voir ...) on défini
- Un marqueur en attribuant un id pour pouvoir y faire référence dans les autres éléments
- Une zone de travail (viewBox)
- Un point central de référence
- Une taille d'affichage (viewport)
- Une orientation suivant si l'n se trouve au début ou à la fin du chemin
- Et enfin des éléments graphiques (chemins, lignes, cercles, ...) pour dessiner le marqueur.

```svg
<polyline points="50,50 100,100 150,75 200,150 250,125 300,200"
   marker-start="url(#square)"
   marker-mid="url(#dot)"
   marker-end="url(#fleche)" />
```
