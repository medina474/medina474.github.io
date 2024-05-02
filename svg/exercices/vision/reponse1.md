---
layout: layouts/page.njk
title: SVG - Exercice - Filtre
---


SVG couvrant toute la page

```html
<svg height="100%" width="100%">
</svg>
```

Photo et rectangle noir par dessus

```svg
<image href="street1.jpg" height="100%" width="100%" />
<rect width="100%" height="100%" />
```

Dégrédé radial

```svg
<radialGradient id="Gradient" r="0.4">
  <stop offset="0%" stop-color="white"/>
  <stop offset="20%" stop-color="white"/>
  <stop offset="100%" stop-color="black"/>
</radialGradient>

```

```svg
<mask id="masque">
  <circle id="centre" r="2%" fill="url(#Gradient)" />
</mask>
```

Ajouter le masque sur le rectangle noir

```svg
<rect width="100%" height="100%" mask="url(#masque)" />
```

Code javascript pour suivre la souris

```javascript
document.body.onmousemove = event => 
{
  document.getElementById("centre").setAttribute("cx", event.clientX );
  document.getElementById("centre").setAttribute("cy", event.clientY );
}
```

Code complet

```html
<svg height="100%" width="100%">
  <defs>
    <radialGradient id="Gradient" r="0.4">
      <stop offset="0%" stop-color="white"/>
      <stop offset="20%" stop-color="white"/>
      <stop offset="100%" stop-color="black"/>
    </radialGradient>
    <mask id="masque">
      <circle id="centre" cx="512" cy="342" r="20%" fill="url(#Gradient)" />
    </mask>
  </defs>
  <image href="street1.jpg" x="0" y="0" height="100%" width="100%" />
  <rect width="100%" height="100%" mask="url(#masque)" />
</svg>
<script>
document.body.onmousemove = event => 
{
  document.getElementById("centre").setAttribute("cx", event.clientX );
  document.getElementById("centre").setAttribute("cy", event.clientY );
}
</script>
``` 

Voir la [solution](solution) 