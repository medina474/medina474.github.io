---
layout: layouts/page.njk
title: Interaction en javascript - Solution
---

### Etats

Pour commencer nous allons stocker dans un tableau javascript les états des cuves

Chaque cuve possède 3 propriétés : son nom pour l'identifier, l'état du robinet (ouvert ou fermé) et enfin le niveau dans la cuve de 1 à 0.

```javascript
const etats = [
  { nom: "rouge", robinet: false, niveau: 1 },
  { nom: "vert",  robinet: false, niveau: 1 },
  { nom: "bleu",  robinet: false, niveau: 1 },
  
];
```

### Robinets

Ajouter un symbole pour le robinet dans la partie définition du svg

```svg
<symbol id="robinet" viewBox="-28 -28 56 56">
  <circle r="12" />
  <line y2="-24" y1="24" stroke-width="8" stroke="black" stroke-linecap="round"/>
</symbol>
```

Le robinet est centré sur 0,0 et est placé dans un groupe pour son placement dans l'illustration. Cela permet de s'affranchir de l'origine de la tranformation

```svg
<g transform="translate(300 152)">
  <use href="#robinet" data-nom="rouge" width="56" height="56" />
</g>
<g transform="translate(300 372)">
  <use href="#robinet" data-nom="vert" width="56" height="56" />
</g>
<g transform="translate(300 572)">
  <use href="#robinet" data-nom="bleu" width="56" height="56" />
</g>
```

Code javascript pour faire tourner le robinet

1. Sélection tous les éléments qui utilise un robinet `document.querySelectorAll("use[href='#robinet']")`
2. Pour chaque élement faire `.forEach((robinet) =>`
3. Ajouter une fonction à l'événement au clic de souris `robinet.addEventListener("click", function (event) {`
4. Lors du clic
5. Chercher dans le tableau des états à quel cuve correspond le robinet. La propriété `data-nom`du robinet permet d'identifier la ligne d'état. `let cuve = etats.find((elt) => elt.nom == event.currentTarget.dataset["nom"]);`
propriété data-nom de l'élement à l'origine de l'événement `event.currentTarget.dataset["nom"]`
6. Une fois identifié inversé l'état du robinet. Passer d'ouvert à fermé ou de fermé à ouvert. `cuve.robinet = !cuve.robinet;`
7. Appliquer une rotation de 90° `event.currentTarget.style.transform="rotate(90deg)"` ou l'annuler `null` suivant l'état du robinet.

```javascript
document.querySelectorAll("use[href='#robinet']").forEach((robinet) =>
  robinet.addEventListener("click", function (event) {
      let cuve = etats.find((elt) => elt.nom == event.currentTarget.dataset["nom"]);
      cuve.robinet = !cuve.robinet;
      event.currentTarget.style.transform = cuve.robinet ? "rotate(90deg)" : null;
    })
  );
``` 

### Cuves

Ajouter un symbole pour la cuve

```svg
<symbol id="cuve">
  <g transform="translate(2 21)">
    <rect width="200" style="height: calc(calc(var(--niveau) * var(--hauteur)) * 1px); 
      y: calc(calc(var(--hauteur) * 1px) * calc(1 - var(--niveau)));" x="1" fill-opacity="0.6" />
    <ellipse rx="100" ry="20" cx="100" 
      style="cy: calc(calc(var(--hauteur) * 1px) * calc(1 - var(--niveau)));" class="surface" />
    <ellipse rx="100" ry="20" cx="100" fill="none" stroke="black" stroke-width="2" />
    <ellipse rx="100" ry="20" cx="100" filter="brightness(75%)" style="cy: calc(var(--hauteur) * 1px)" stroke="black" stroke-width="2"/>
    <g style="transform: scaleY(calc(var(--hauteur) / 100))" vector-effect="non-scaling-stroke">
      <line x1="0" y1="0" x2="0" y2="100px" stroke="black" stroke-width="2"/>
      <line x1="200"  y1="0" x2="200"  y2="100px" stroke="black"  stroke-width="2"/>
    </g>
  </g>
</symbol>
```

Les éléments personnalisables de la cuve sont controlé par des variables css.

**--hauteur** = hauteur totale de la cuve\n
**--niveau** = niveau à l'intérieur de la cuve

Pour l'ellipse représentant le niveau, l'ordonnée du centre est contrôlé par le style cy. La multiplication par 1px permet de donner l'unité à la valeur sinon elle est ignorée.

```css
cy: calc(var(--hauteur) * 1px)
```

Les 2 lignes de chaque côté sont agrandies par un effet d'échelle scaleY. Pour une hauteur de 100 scaleY = 1, pour 200 scaleY = 2 (sans unité).

vector-effect="non-scaling-stroke" permet de ne pas agrandir l'épaisseur du contour lors de l'agrandissement.

```svg
<g style="transform: scaleY(calc(var(--hauteur) / 100))" vector-effect="non-scaling-stroke">
```

La hauteur du rectangle de remplissage est controlé aussi avec une variable css. Attention dans une illustration svg l'origine est en haut donc en diminuant la hauteur du rectangle il va se réduire vers le haut. Il faut donc aussi bouger l'origine pour que celle ci soit toujours en bas de la cuve.
Une autre solution consisterais à appliquer une transformation de symétrie verticale pour inverser le sens de la réduction.

pour faire une opération à plusieurs termes en css il est nécessaire d'utiliser plusieurs fonctions calc imbriquées.

hauteur du remplissage = 200 ; niveau = 0.4 ; hauteur du rectangle = 0.4 * 200 = 80. La multiplication par 1px permet de donner l'unité à la valeur sinon elle est ignorée.

origine du remplissage = 200 * 1px * ( 1 - 0.4) = 120px

```svg
style="height: calc(calc(var(--niveau) * var(--hauteur)) * 1px); 
  y: calc(calc(var(--hauteur) * 1px) * calc(1 - var(--niveau)));" x="1"
```

La couleur de l'ellipse du dessous à sa luminosité qui est baissée à 75% pour un effet d'assobrissement.

```
filter="brightness(75%)"
```

Le remplissage a une opacité de 0.6 pour un effet de transparence

```
fill-opacity="0.6"
```

```svg
<use href="#cuve" transform="translate(40 50)" class="cuve" data-nom="rouge" fill="red" style='--niveau:1;--hauteur:150;' />
<use href="#cuve" transform="translate(40 280)" class="cuve" data-nom="vert" fill="green" style='--niveau:1;--hauteur:150;' />
<use href="#cuve" transform="translate(40 520)" class="cuve" data-nom="bleu" fill="blue" style='--niveau:1;--hauteur:150;' />
<use href="#cuve" transform="translate(498 200)" class="cuve" data-nom="destination" fill="white" style='--niveau:0;--hauteur:450' />
```

## Javascript

## fonction principale

Déclarer une fonction qui devra gérer le changement de niveau `function remplir() {`
1. Filtrer les états pour sélectionner ceux dont le robinet est ouvert et la cuve non vide `.filter((cuve) => cuve.robinet == true && cuve.niveau > 0)`
2. Pour chaque cuve (dont le robinet est ouvert) `.forEach((cuve) => {`
3. Faire baisser le niveau de la cuve en question `cuve.niveau -= 0.005;`
4. Augmenter le niveau dans la cuve de destination `destination[cuve.nom] += 0.005;`
5. Mettre à jour le niveau de la cuve en agissant sur la variable css `document.querySelector('.cuve[data-nom='${cuve.nom}']').style.setProperty('--niveau', cuve.niveau);`. Attention à l'interpolation de la chaine, il faut utiliser les back quote (Alt Gr 7)
6. Calculer le niveau dans la cuve de destination `destination.niveau = (destination.rouge + destination.vert + destination.bleu) / 3;`
7. Mettre à jour le niveau de la cuve de destination en agissant sur la variable css  `document.querySelector('.cuve[data-nom='destination']').style.setProperty('--niveau', destination.niveau);`
8. Calculer la couleur de destination. Il faut se rapporter à la couleur la plus présente et calculer la proportion des 2 autres en fonction. `destination.total = Math.max(destination.rouge, destination.vert, destination.bleu);` puis 
`destination.couleur = 'rgb( ${(destination.rouge / destination.total) * 255} ${(destination.vert / destination.total) * 255} ${(destination.bleu / destination.total) * 255})'`
9. Mettre à jour la couleur de remplissage `document.querySelector('.cuve[data-nom='destination']').setAttribute("fill", destination.couleur);`
10. Allumer le feu rouge lorsqu'une cuve est vide `document.getElementById("feu-rouge").style.fillOpacity = etats.some((cuve) => cuve.hauteur == 0) ? 1: 0;`
11. Allumer le feu vert lorsqu'au moins un robinet est ouvert. `document.getElementById("feu-vert").style.fillOpacity = etats.some((cuve) => cuve.robinet) ? 1 : 0;`

``` javascript
function remplir() {
  etats
    .filter((cuve) => cuve.robinet == true && cuve.niveau > 0)
    .forEach((cuve) => {
      cuve.niveau -= 0.005;
      destination[cuve.nom] += 0.005;            
      document.querySelector(`.cuve[data-nom='${cuve.nom}']`).style.setProperty('--niveau', cuve.niveau);
  });

  destination.niveau = (destination.rouge + destination.vert + destination.bleu) / 3;
  document.querySelector(`.cuve[data-nom='destination']`).style.setProperty('--niveau', destination.niveau);
  
  destination.total = Math.max(destination.rouge, destination.vert, destination.bleu);
  destination.couleur = `rgb( ${(destination.rouge / destination.total) * 255} ${(destination.vert / destination.total) * 255} ${(destination.bleu / destination.total) * 255})`;
  document.querySelector(`.cuve[data-nom='destination']`).setAttribute("fill", destination.couleur);

  document.getElementById("feu-rouge").style.fillOpacity = etats.some((cuve) => cuve.hauteur == 0) ? 1: 0;
  document.getElementById("feu-vert").style.fillOpacity = etats.some((cuve) => cuve.robinet) ? 1 : 0;
}
``` 

Répéter la fonction remplir tant qu'un robinet est ouvert et de manière continue

1. déclarer une variable globale permettant d'agir sur le timer `var timer;`.
2. Dan la fonction clic des robinets, tester si au moins un robinet est ouvert. `if (etats.some((elt) => elt.robinet))` Déclencher la fonction remplir toutes les 50ms, sauvegarder le handle de la fonction dans la variable timer. `timer = setInterval(remplir, 50) `\
Si aucun robinet n'est ouvert annuler la répétition de la fonction `clearInterval(timer);`

```javascript
var timer;

 ...    

if (etats.some((elt) => elt.robinet)) 
  timer = setInterval(remplir, 50) 
else
  clearInterval(timer);

```

## Javscript complet

```javascript
<script>
const etats = [
  { nom: "rouge", robinet: false, niveau: 1 },
  { nom: "vert", robinet: false, niveau: 1 },
  { nom: "bleu", robinet: false, niveau: 1 },
];

const destination = { rouge: 0, vert: 0, bleu: 0 };

var timer;

document.querySelectorAll("use[href='#robinet']").forEach((robinet) =>
  robinet.addEventListener("click", function (event) {
    let cuve = etats.find(
      (elt) => elt.nom == event.currentTarget.dataset["nom"]
    );
    cuve.robinet = !cuve.robinet;
    event.currentTarget.style.transform = cuve.robinet ? "rotate(90deg)" : null;

    if (etats.some((elt) => elt.robinet)) 
    timer = setInterval(remplir, 50) 
  else
    clearInterval(timer);
  })
);

function remplir() {
  etats
    .filter((cuve) => cuve.robinet == true && cuve.niveau > 0)
    .forEach((cuve) => {
      cuve.niveau -= 0.005;
      destination[cuve.nom] += 0.005;            
      document.querySelector(`.cuve[data-nom='${cuve.nom}']`).style.setProperty('--niveau', cuve.niveau);
  });

  destination.niveau = (destination.rouge + destination.vert + destination.bleu) / 3;
  document.querySelector(`.cuve[data-nom='destination']`).style.setProperty('--niveau', destination.niveau);
  
  destination.total = Math.max(destination.rouge, destination.vert, destination.bleu);
  destination.couleur = `rgb( ${(destination.rouge / destination.total) * 255} ${(destination.vert / destination.total) * 255} ${(destination.bleu / destination.total) * 255})`;
  document.querySelector(`.cuve[data-nom='destination']`).setAttribute("fill", destination.couleur);

  document.getElementById("feu-rouge").style.fillOpacity = etats.some((cuve) => cuve.hauteur == 0) ? 1: 0;
  document.getElementById("feu-vert").style.fillOpacity = etats.some((cuve) => cuve.robinet) ? 1 : 0;
}
</script>
```

### SVG Complet

```svg
<svg xmlns="http://www.w3.org/2000/svg" width="0" height="0">
  <defs>
    <symbol id="robinet" viewBox="-28 -28 56 56">
      <circle r="12" />
      <line y2="-24" y1="24" stroke-width="8" stroke="black" stroke-linecap="round"/>
    </symbol>

    <symbol id="cuve">
      <g transform="translate(2 21)">
      <rect width="200" style="height: calc(calc(var(--niveau) * var(--hauteur)) * 1px); 
      y: calc(calc(var(--hauteur) * 1px) * calc(1 - var(--niveau)));" x="1" fill-opacity="0.6" />
      <ellipse rx="100" ry="20" cx="100" style="cy: calc(calc(var(--hauteur) * 1px) * calc(1 - var(--niveau)));" class="surface" />
      <ellipse rx="100" ry="20" cx="100" fill="none" stroke="black" stroke-width="2" />
      <ellipse rx="100" ry="20" cx="100" filter="brightness(75%)" style="cy: calc(var(--hauteur) * 1px)" stroke="black" stroke-width="2"/>
      <g style="transform: scaleY(calc(var(--hauteur) / 100))" vector-effect="non-scaling-stroke">
        <line x1="0" y1="0" x2="0" y2="100px" stroke="black" stroke-width="2"/>
        <line x1="200"  y1="0" x2="200"  y2="100px" stroke="black"  stroke-width="2"/>
      </g>
      </g>
    </symbol>
  </defs>
</svg>
```

```svg
<svg xmlns="http://www.w3.org/2000/svg" width="500" height="500" viewBox="0 0 700 800">
  <g id="feu" transform="translate(440 25)">
    <rect width="50" height="107.5" stroke-width="2" stroke="black" fill="white" rx="5" ry="5"/>
    <circle id="feu-rouge" cx="25" cy="27.5" r="20" fill="red" stroke="black" stroke-width="0.5" fill-opacity="1" class="feu"/>
    <circle id="feu-vert" cx="25" cy="80" r="20" fill="green" stroke="black" stroke-width="0.5" class="feu"/>
  </g>

  <use href="#cuve" transform="translate(40 50)" class="cuve" data-nom="rouge" fill="red" style='--niveau:1;--hauteur:150;' />
  <use href="#cuve" transform="translate(40 280)" class="cuve" data-nom="vert" fill="green" style='--niveau:1;--hauteur:150;' />
  <use href="#cuve" transform="translate(40 520)" class="cuve" data-nom="bleu" fill="blue" style='--niveau:1;--hauteur:150;' />
  <use href="#cuve" transform="translate(498 200)" class="cuve" data-nom="destination" fill="white" style='--niveau:0;--hauteur:450' />

  <polyline points="240 180 400 180 400 500 500 500" stroke="black" stroke-width="4" fill="none" />
  <polyline points="240 400 400 400 400 500 500 500" stroke="black" stroke-width="4" fill="none" />
  <polyline points="240 600 400 600 400 500 500 500" stroke="black" stroke-width="4" fill="none" />

  <g transform="translate(300 152)">
    <use href="#robinet" data-nom="rouge" width="56" height="56" />
  </g>
  <g transform="translate(300 372)">
    <use href="#robinet" data-nom="vert" width="56" height="56" />
  </g>
  <g transform="translate(300 572)">
    <use href="#robinet" data-nom="bleu" width="56" height="56" />
  </g>
</svg>
```

### Feuille de style

```css
<style>
use[href="#robinet"] {
  transform-origin: 28px 28px;
  transition: 1s transform;
}

.feu {
  transition: fill-opacity 1s;
}
</style>
```

Voir la [solution](solution).
