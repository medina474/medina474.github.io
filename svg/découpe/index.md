---
title: Découpe et masquage
---

## Découpage

Le découpage (clipping) agit comme un pochoir. les éléments sont découpés par les bords de la forme.

L'élement clipPath est défini à l'intérieur d'une zone de définition. Il contient le tracé personalisé de ce qui va servir à découper.

```svg
<defs>
  <clipPath id="pochoir">
    <rect x="0" y="0" width="230" height="80" />
  </clipPath>
</defs>
```
Pour découper une illustration il faut faire référence à la définition du clipPath

```svg
<g clip-path="url(#pochoir)" />
```

## Découpages simples

Lorsque le découpage est une forme simple il est possible d'utiliser des raccourcis.

### Rectangle intérieur

`inset` défini les marges enhaut à droite, en bas et à gauche d'un rectangle. Les marges sont exprimés en px ou en pourcentage.

```svg
<g clip-path="inset(5% 30px 50px 8%)">
```

<svg xmlns="http://www.w3.org/2000/svg" width="500" height="260" viewBox="0 0 500 260">
  <image x="20" y="3" href="panda.webp" height="250" clip-path="inset(5% 30px 50px 8%)" />
  <rect x="20" y="3" width="375" height="250" stroke-width="5" stroke="red" fill="none" />
</svg>


### Cercle

```svg
<g clip-path="circle(30% at 45% 40%)">
```

<svg xmlns="http://www.w3.org/2000/svg" width="500" height="260" viewBox="0 0 500 260">
  <image x="20" y="3" href="panda.webp" height="250" clip-path="circle(30% at 45% 40%)" />
  <rect x="20" y="3" width="375" height="250" stroke-width="5" stroke="red" fill="none" />
</svg>

### Ellipse

```svg
<g clip-path="ellipse(100px 60px at 45% 35%)">
```

<svg xmlns="http://www.w3.org/2000/svg" width="500" height="260" viewBox="0 0 500 260">
  <image x="20" y="3" href="panda.webp" height="250" clip-path="ellipse(100px 60px at 45% 35%)" />
  <rect x="20" y="3" width="375" height="250" stroke-width="5" stroke="red" fill="none" />
</svg>

### Polygone

```svg
<g clip-path="polygon(175px 10px, 90% 70%, 20% 80%)">
```

<svg xmlns="http://www.w3.org/2000/svg" width="500" height="260" viewBox="0 0 500 260">
  <image x="20" y="3" href="panda.webp" height="250" clip-path="polygon(175px 10px, 90% 70%, 20% 80%)" />
  <rect x="20" y="3" width="375" height="250" stroke-width="5" stroke="red" fill="none" />
</svg>

### Chemin

```svg
<g clip-path="path('M213.1,6.7c-32.4-14.4-73.7,0-88.1,30.6C110.6,4.9,67.5-9.5,36.9,6.7C2.8,22.9-13.4,62.4,13.5,110.9 C33.3,145.1,67.5,170.3,125,217c59.3-46.7,93.5-71.9,111.5-106.1C263.4,64.2,247.2,22.9,213.1,6.7z'">
```

<svg xmlns="http://www.w3.org/2000/svg" width="500" height="260" viewBox="0 0 500 260">
  <image x="20" y="3" href="panda.webp" height="250" clip-path="path('M213.1,6.7c-32.4-14.4-73.7,0-88.1,30.6C110.6,4.9,67.5-9.5,36.9,6.7C2.8,22.9-13.4,62.4,13.5,110.9 C33.3,145.1,67.5,170.3,125,217c59.3-46.7,93.5-71.9,111.5-106.1C263.4,64.2,247.2,22.9,213.1,6.7z'" />
  <rect x="20" y="3" width="375" height="250" stroke-width="5" stroke="red" fill="none" />
</svg>

[https://bennettfeely.com/clippy/](https://bennettfeely.com/clippy/)

## Masquage

Le masquage permet des effets plus fins. Les élements apparaissent progressivement en transparence suivant l'intensité de noir ou blanc de la forme.

L'intérêt du masquage est d'utiliser des dégradés.

```svg
 <defs>
 <linearGradient id="Gradient">
    <stop offset="0" stop-color="white" stop-opacity="0" />
    <stop offset="1" stop-color="white" stop-opacity="1" />
</linearGradient>
<mask id="masque">
  <rect x="0" y="0" width="200" height="200" fill="url(#Gradient)" />
</mask>
 </defs>
```

Comme le découpage il faut faire référnce à la définition du masque

```svg
<g mask="url(#masque)" />
```
