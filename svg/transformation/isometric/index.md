---
title: Projection isométrique
---

La perspective isométrique est une méthode de représentation en perspective (3D) dans laquelle les trois directions de l'espace sont représentées avec la même importance, d'où le terme. Les lignes parallèles le restent il n'y a pas de point de fuite comme dans la perspective cavalière.

### Méthode 1

<svg xmlns="http://www.w3.org/2000/svg" width="600" height="300" viewBox="0 0 400 200">
<rect x="150" y="50" width="50" height="50" fill="red" />
<rect x="150" y="100" width="50" height="50" fill="blue" />
<rect x="200" y="50" width="50" height="50" fill="green" />
<circle cx="200" cy="100" r="3"/>
</svg>

1ère étape : **Rotation de 45°**

<svg xmlns="http://www.w3.org/2000/svg" width="600" height="300" viewBox="0 0 400 200">
<g transform="rotate(45)" transform-origin="200 100">
<rect x="150" y="50" width="50" height="50" fill="red" />
<rect x="150" y="100" width="50" height="50" fill="blue" />
<rect x="200" y="50" width="50" height="50" fill="green" />
</g>
<circle cx="200" cy="100" r="3"/>
<circle cx="200" cy="64.6447" r="3"/>
<circle cx="164.6447" cy="100" r="3"/>
<circle cx="235.3553" cy="100" r="3"/>
</svg>

2e étape : **Déformation**

Pièce|X %|Y %
---|--:|--:
Rouge|100|57.73
Bleu|57.73|100
Vert|57.73|100

Il faut prendre soin d'appliquer la transformation depuis le centre des pièces. Sachant qu'après la rotation de 45°, ce sont les diagonales qui sont suivant les axes de X et Y.\
Le centre est situé à côté * √2 / 2

<svg xmlns="http://www.w3.org/2000/svg" width="600" height="300" viewBox="0 0 400 200">
<g transform="scale(1 0.5773)" transform-origin="200 64.6447">
<rect x="150" y="50" width="50" height="50" fill="red" transform="rotate(45)" transform-origin="200 100" />
</g>
<g transform="scale(0.5773 1)" transform-origin="164.6447 100">
<rect x="150" y="100" width="50" height="50" fill="blue" transform="rotate(45)" transform-origin="200 100" />
</g>
<g transform="scale(0.5773 1)" transform-origin="235.3553 0">
<rect x="200" y="50" width="50" height="50" fill="green" transform="rotate(45)" transform-origin="200 100" />
</g>
<circle cx="235.3553" cy="64.6447" r="3"/>
<circle cx="164.6447" cy="64.6447" r="3"/>
</svg>

3e étape : **Rotation**

Pièce|Angle
---|--:
Rouge|0 °
Bleu|-30 °
Vert|30 °

La encore il faut choisir avec soin  l'origine de la transformation. il faut sélectionner les points en commun avec 2 côtés.

<svg xmlns="http://www.w3.org/2000/svg" width="600" height="300" viewBox="0 0 400 200">
<g transform="scale(1 0.5773)" transform-origin="0 64.6447">
<rect x="150" y="50" width="50" height="50" fill="red" transform="rotate(45)" transform-origin="200 100" />
</g>
<g transform="rotate(-30)" transform-origin="164.6447 64.6447">
<g transform="scale(0.5773 1)" transform-origin="164.6447 0">
<rect x="150" y="100" width="50" height="50" fill="blue" transform="rotate(45)" transform-origin="200 100" />
</g>
</g>
<g transform="rotate(30)" transform-origin="235.3553 64.6447">
<g transform="scale(0.5773 1)" transform-origin="235.3553 0">
<rect x="200" y="50" width="50" height="50" fill="green" transform="rotate(45)" transform-origin="200 100" />
</g>
</g>
</svg>

```svg
<svg xmlns="http://www.w3.org/2000/svg" width="600" height="300" viewBox="0 0 400 200">

<g transform="scale(1 0.5773)" transform-origin="0 64.6447">
  <rect x="150" y="50" width="50" height="50" fill="red" 
    transform="rotate(45)" transform-origin="200 100" />
</g>

<g transform="rotate(-30)" transform-origin="164.6447 64.6447">
  <g transform="scale(0.5773 1)" transform-origin="164.6447 0">
    <rect x="150" y="100" width="50" height="50" fill="blue" 
      transform="rotate(45)" transform-origin="200 100" />
</g>
</g>

<g transform="rotate(30)" transform-origin="235.3553 64.6447">
  <g transform="scale(0.5773 1)" transform-origin="235.3553 0">
    <rect x="200" y="50" width="50" height="50" fill="green" 
      transform="rotate(45)" transform-origin="200 100" />
  </g>
</g>

</svg>
``` 

http://www.enjoythisbeautifulday.com/how-to/isometric/

### Méthode 2

Cette méthode est un peu plus simple car il n'y a qu'une seule origine pour toute les transformations.

<svg xmlns="http://www.w3.org/2000/svg" width="600" height="300" viewBox="0 0 400 200">
<rect x="150" y="50" width="50" height="50" fill="red" />
<rect x="150" y="100" width="50" height="50" fill="blue" />
<rect x="200" y="100" width="50" height="50" fill="green" />
<circle cx="200" cy="100" r="3"/>
</svg>

1ère étape : **Déformation** de 86.603% (cos(30°)) en hauteur

<svg xmlns="http://www.w3.org/2000/svg" width="600" height="300" viewBox="0 0 400 200">
<g transform="scale(1 0.86603)">
<rect x="150" y="50" width="50" height="50" fill="red" />
<rect x="150" y="100" width="50" height="50" fill="blue" />
<rect x="200" y="100" width="50" height="50" fill="green" />
</g>
<circle cx="200" cy="86.603" r="3"/>
</svg>

2e étape : **cisaillement** de 30°

Pièce|Angle
---|--:
Rouge|-30 °
Bleu|30 °
Vert|-30 °

<svg xmlns="http://www.w3.org/2000/svg" width="600" height="300" viewBox="0 0 400 200">
<g transform="skewX(-30)" transform-origin="0 86.603">
<rect x="150" y="50" width="50" height="50" fill="red" transform="scale(1 0.86603)" />
</g>
<g transform="skewX(30)" transform-origin="0 86.603" >
<rect x="150" y="100" width="50" height="50" fill="blue" transform="scale(1 0.86603) " />
</g>
<g transform="skewX(-30)" transform-origin="0 86.603">
<rect x="200" y="100" width="50" height="50" fill="green" transform="scale(1 0.86603)" />
</g>
<circle cx="200" cy="86.603" r="3"/>
</svg>

3e étape : **rotation**

Pièce|Angle
---|--:
Rouge|30 °
Bleu|30 °
Vert|-30 °

<svg xmlns="http://www.w3.org/2000/svg" width="600" height="300" viewBox="0 0 400 200">
<g transform="rotate(30) skewX(-30)" transform-origin="200 86.603">
<rect x="150" y="50" width="50" height="50" fill="red" transform="scale(1 0.86603)" />
</g>
<g transform="rotate(30) skewX(30)" transform-origin="200 86.603" >
<rect x="150" y="100" width="50" height="50" fill="blue" transform="scale(1 0.86603) " />
</g>
<g transform="rotate(-30) skewX(-30)" transform-origin="200 86.603">
<rect x="200" y="100" width="50" height="50" fill="green" transform="scale(1 0.86603)" />
</g>

<circle cx="200" cy="86.603" r="3"/>
</svg>

```svg
<svg xmlns="http://www.w3.org/2000/svg" width="600" height="300" viewBox="0 0 400 200">

<g transform="rotate(30) skewX(-30)" transform-origin="200 86.603">
  <rect x="150" y="50" width="50" height="50" fill="red" 
    transform="scale(1 0.86603)" />
</g>

<g transform="rotate(30) skewX(30)" transform-origin="200 86.603" >
  <rect x="150" y="100" width="50" height="50" fill="blue" 
    transform="scale(1 0.86603)" />
</g>

<g transform="rotate(-30) skewX(-30)" transform-origin="200 86.603">
  <rect x="200" y="100" width="50" height="50" fill="green" 
    transform="scale(1 0.86603)" />
</g>

</svg>
```

https://nicoguaro.github.io/posts/isometric_inkscape2/



### Méthode 3

En combinant les transformations successives dans une matrice résultantes

matrix(1 0.5 -1 0.5 0 -50)\
matrix(1 0.5 0 1 -100 -100)\
matrix(1 -0.5 0 1 -100 100)

<svg xmlns="http://www.w3.org/2000/svg" width="600" height="300" viewBox="0 0 400 200">
<rect x="150" y="50" width="50" height="50" fill="red" 
  transform="matrix(1 0.5 -1 0.5 0 -50)" />
<rect x="150" y="100" width="50" height="50" fill="blue" 
  transform="matrix(1 0.5 0 1 -100 -100)" />
<rect x="200" y="100" width="50" height="50" fill="green" 
  transform="matrix(1 -0.5 0 1 -100 100)" />
</svg>

```svg
<svg xmlns="http://www.w3.org/2000/svg" width="600" height="300" viewBox="0 0 400 200">
<rect x="150" y="50" width="50" height="50" fill="red" 
  transform="matrix(1 0.5 -1 0.5 0 -50)" />
<rect x="150" y="100" width="50" height="50" fill="blue" 
  transform="matrix(1 0.5 0 1 -100 -100)" />
<rect x="200" y="100" width="50" height="50" fill="green" 
  transform="matrix(1 -0.5 0 1 -100 100)" />
</svg>
```

https://bl.ocks.org/helderdarocha/8b28505082bf1c81977d7dec797686c7

https://design.tutsplus.com/tutorials/how-to-create-advanced-isometric-illustrations-using-the-ssr-method--vector-1058
 

https://design.tutsplus.com/fr/tutorials/quick-tip-how-to-create-an-isometric-grid-in-less-than-2-minutes--vector-3831
