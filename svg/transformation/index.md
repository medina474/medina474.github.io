---
layout: layouts/math.njk
title: Transformation
date: Last Modified

type: post
eleventyComputed:
  meta:
    author:
      name: "{{ metadata.author.name }}"
    published: "{{ date | iso8601 }}"
    modified: "{% if updateDate %}{{ updateDate | iso8601 }}{% endif %}"
---

## Matrice

La matrice permet d'effectuer n'importe quelle transformation en appliquant sur les coordonnées de la forme d'origine 2 équations.

$$
x' = a\times x + c\times y + e
$$

$$
y' = b\times x + d\times y + f
$$


la fonction matrice possède 6 paramètres `matrix(a b c d e f)`


<svg width="500" height="150">
  <use href="#grid"/>
  <rect x="50" y="25" width="100"  height="100" stroke="red" stroke-width="2" fill="#3ed124"  opacity= "0.5"/>
  <rect x="50" y="25" width="100"  height="100" stroke="red" stroke-width="2" fill="#3ed124" transform="matrix(0.5 0.866 -0.5 0.7 30 10)"  transform-origin="100 75"/>
</svg>

$$
Transformation = 
\begin{bmatrix}
a & c & e \\\ 
b & d & f
\end{bmatrix}
$$

## Translation

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

```svg
<rect transform="translate(30, 40)" />
<rect transform="matrix(1, 0, 0, 1, 30, 40)" />
```

$$
Translation = 
\begin{bmatrix}
1 & 0 & 30 \\\ 
0 & 1 & 40
\end{bmatrix}
$$

$$
x' = x + 30
$$

$$
y' = y + 40
$$


<svg width="500" height="150">
  <use href="#grid"/>
  <rect x="0" y="0" width="100"  height="100" stroke="red" stroke-width="2" fill="#3ed124" opacity= "0.5"/>
  <rect x="0" y="0" width="100" height="100" stroke="red" stroke-width="2" fill="#3ed124" transform="translate(50,25)"/>
</svg>

## Rotation

```svg
<rect transform="rotate(45)" />
<rect transform="matrix(cos(a), sin(a), -sin(a), cos(a), 0, 0)" />
```

$$
Rotation = \begin{bmatrix}
cos(\alpha) & -sin(\alpha) & 0 \\\ 
sin(\alpha) & cos(\alpha) & 0
\end{bmatrix}
$$

$$
x' = x\times cos(\alpha) - y\times sin(\alpha)
$$

$$
y' = x\times sin(\alpha) + y\times cos(\alpha)
$$

<svg width="500" height="150">
  <use href="#grid"/>
  <rect x="75" y="-70" width="100"  height="100" stroke="red" stroke-width="2" fill="#3ed124" opacity= "0.5"/>
  <circle r="177" fill="none" stroke="yellow"/>
  <rect x="75" y="-70" width="100" height="100" stroke="red" stroke-width="2" fill="#3ed124" transform="rotate(45)"/>
</svg>

## Échelle

```svg
<rect transform="scale(0.5)" />
<rec transform="matrix(0.5, 0, 0, 0.5, 0, 0)" />
```

$$
Échelle = 
\begin{bmatrix}
0.5 & 0 & 0 \\\ 
0 & 0.5 & 0
\end{bmatrix}
$$

$$
x' = x\times0.5
$$

$$
y' = y\times0.5
$$

<svg width="500" height="150">
  <use href="#grid"/>
  <rect x="75" y="70" width="100"  height="100" stroke="red" stroke-width="2" fill="#3ed124" opacity= "0.5"/>
  <rect x="75" y="70" width="100" height="100" stroke="red" stroke-width="2" fill="#3ed124" transform="scale(0.5)"/>
</svg>

## Inclinaison ou cisaillement

```svg
<rect transform="skewX(-15)" />
```

<svg width="500" height="150">
  <use href="#grid"/>
  <rect x="50" y="10" width="100"  height="100" stroke="red" stroke-width="2" fill="#3ed124" opacity= "0.5"/>
  <rect x="50" y="10" width="100" height="100" stroke="red" stroke-width="2" fill="#3ed124" transform="skewX(-15)"/>
</svg>

$$
Inclinaison = 
\begin{bmatrix}
1 & tan(\alpha) & 0 \\\ 
0 & 1 & 0
\end{bmatrix}
$$

$$
x' = x + y\times tan(\alpha)
$$

$$
y' = y
$$

### Y

$$
Inclinaison = 
\begin{bmatrix}
1 & 0 & 0 \\\ 
tan(\alpha) & 1 & 0
\end{bmatrix}
$$

$$
x' = x + y\times tan(\alpha)
$$

$$
y' = y
$$

## Multiples transformations

Les transformations peuvent être combinés en les ajoutant les unes à la suite des autres.

Attention toutefois le système de coordonnées tout entier est transformé lui aussi 

```svg
<rect transform="rotate(30) translate(0, 40) " />
```

<svg width="500" height="150">
  <use href="#grid"/>
  <rect x="75" y="-70" width="100"  height="100" stroke="red" stroke-width="2" fill="#3ed124" transform="rotate(30)" opacity= "0.5"/>
  <rect x="75" y="-70" width="100"  height="100" stroke="red" stroke-width="2" fill="#3ed124" transform="rotate(30) translate(40,0)"/>
</svg>

Le déplacement en x de 40px s'effectue suivant le nouvel axe x qui a subit lui aussi une rotation de 30°

### Multiplication de matrice

La multiplication de matrice s'effectue en 

$$
Resultant = 
\begin{bmatrix}
a & c & e \\\ 
b & d & f \\\ 
0 & 0 & 1
\end{bmatrix}
\times
\begin{bmatrix}
a' & c' & e' \\\ 
b' & d' & f' \\\ 
0 & 0 & 1
\end{bmatrix} = 
\begin{bmatrix}
a\times a' + c \times b' & 
a \times c' + c \times d' & 
a \times e' + c \times f' + e \\\ 
b\times a' + d \times b' & 
b \times c' + d \times d' & 
b \times e' + d \times f' + f \\\ 
0 & 0 & 1
\end{bmatrix}
$$

$$
Transformation = \begin{bmatrix}
cos(30) & -sin(30) & 0 \\\  
sin(30) & cos(30) & 0 \\\ 
0 & 0 & 1
\end{bmatrix}
\times
\begin{bmatrix}
1 & 0 & 40 \\\ 
0 & 1 & 0 \\\ 
0 & 0 & 1
\end{bmatrix} = \begin{bmatrix}
cos(30)  & 
-sin(30) & 
cos(30) \times 40 \\\ 
sin(30) & 
cos(30) & 
sin(30) \times 40 \\\ 
0 & 0 & 1\end{bmatrix}
$$

<svg width="500" height="150">
  <use href="#grid"/>
  <rect x="75" y="-70" width="100"  height="100" stroke="red" stroke-width="2" fill="#3ed124" transform="rotate(30)" opacity= "0.5"/>
  <rect x="75" y="-70" width="100"  height="100" stroke="red" stroke-width="2" fill="#3ed124" transform="matrix(0.866 0.5 -0.5 0.866 34.64 20)"/>
</svg>

## Origine de la transformation

la propriété `transform-origin` permet de sélectionner l'origine de la transformation. C'est très utile dans le cas des rotations.

```svg
<rect x="50" y="25"  width="100" height="100"
transform="rotate(45)"  transform-origin="100 75"/>
```

L'origine de la transformation est située au milieu du carré.

<svg width="500" height="150">
  <use href="#grid"/>
  <rect x="50" y="25" width="100"  height="100" stroke="red" stroke-width="2" fill="#3ed124"  opacity= "0.5"/>
  <rect x="50" y="25" width="100"  height="100" stroke="red" stroke-width="2" fill="#3ed124" transform="rotate(45)"  transform-origin="100 75"/>
</svg>

[Projection isométrique](isometric)
