---
layout: layouts/page.njk
title: SVG - Exercice - Filtre
---

SVG couvrant toute la page

```html
<svg height="100%" width="100%">
</svg>
```

Le filre flou

```svg
<feGaussianBlur in="SourceGraphic" stdDeviation="8" result="flou"/>
```

Le filtre baisse de contraste

```svg
<feColorMatrix  type="matrix" values="0.8 0.1 0.1 0 0
0.1 0.8 0.1 0 0
0.1 0.1 0.8 0 0
0 0 0  0.8 0" 
in="flou"">
</feColorMatrix>
```

Les 2 combinés 

```svg
<filter id="flou">
  <feGaussianBlur in="SourceGraphic" stdDeviation="8" result="flou"/>
  <feColorMatrix  type="matrix" values="0.8 0.1 0.1 0 0
    0.1 0.8 0.1 0 0
    0.1 0.1 0.8 0 0
    0 0 0  0.8 0" 
    in="flou"">
</feColorMatrix>
</filter>
```

Le dégradé

```svg
<radialGradient id="Gradient" cx="0.5" cy="0.5" r="0.5">  
  <stop offset="0%" stop-color="white"/>
  <stop offset="100%" stop-color="black"/>
</radialGradient>
```

Le masque

```svg
<mask id="masque">
  <circle id="centre" cx="512" cy="342" r="40%" fill="url(#Gradient)" />
</mask>
```

La première photo avec le flou

```svg
<image href="street2.jpg" height="100%" width="100%" filter="url(#flou)" />
```

La deuxième photo nette mais avec un masquage

```svg
<image href="street2.jpg" height="100%" width="100%" mask="url(#masque)" />
```

### Le suivi par la souris

```javascript
document.body.onmousemove = event => 
{
  document.getElementById("centre").setAttribute("cx", event.clientX );
  document.getElementById("centre").setAttribute("cy", event.clientY );
}
```

### Le code complet

```html
<svg height="100%" width="100%">
  <defs>
    <filter id="flou">
      <feGaussianBlur in="SourceGraphic" stdDeviation="8" result="flou"/>
      <feColorMatrix  type="matrix" values="0.8 0.1 0.1 0 0
        0.1 0.8 0.1 0 0
        0.1 0.1 0.8 0 0
        0 0 0  0.8 0" in="flou"">
      </feColorMatrix>
    </filter>
    <radialGradient id="Gradient" cx="0.5" cy="0.5" r="0.5">
      <stop offset="0%" stop-color="white"/>
      <stop offset="100%" stop-color="black"/>
    </radialGradient>
    <mask id="masque">
      <circle id="centre" cx="512" cy="342" r="40%" fill="url(#Gradient)" />
    </mask>
  </defs>
  <image href="street2.jpg" height="100%" width="100%" filter="url(#flou)" />
  <image href="street2.jpg" height="100%" width="100%" mask="url(#masque)" />
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
