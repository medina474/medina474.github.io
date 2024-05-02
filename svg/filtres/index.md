---
layout: layouts/page.njk
title: Filtres
---

### Flou

feGaussianBlur

<svg width="240" height="120" xmlns="http://www.w3.org/2000/svg">
 <filter id="blur">
   <feGaussianBlur stdDeviation="5"/>
 </filter>
 <circle cx="60" cy="60" r="50" fill="#3ed124" />
 <circle cx="180" cy="60" r="50" fill="#3ed124" filter="url(#blur)" />
</svg>

### Ombre

feDropShadow

<svg width="250" height="130" xmlns="http://www.w3.org/2000/svg">
 <filter id="shadow">
   <feDropShadow dx="4" dy="4" stdDeviation="2" flood-color="darkgreen"/>
 </filter>
 <circle cx="60" cy="60" r="50" fill="#3ed124" />
 <circle cx="180" cy="60" r="50" fill="#3ed124" filter="url(#shadow)" />
</svg>



<svg width="250" height="130" xmlns="http://www.w3.org/2000/svg">
 <filter id="light">
   <feDiffuseLighting in="SourceGraphic" result="light" lighting-color="white">
      <fePointLight x="150" y="60" z="20" />
    </feDiffuseLighting>
 </filter>
 <circle cx="60" cy="60" r="50" fill="#3ed124" />
 <circle cx="180" cy="60" r="50" fill="#3ed124" filter="url(#light)" />
</svg>

<filter id="lightMe1">
    