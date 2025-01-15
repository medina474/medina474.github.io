---
title: Taille
---

## Écran

L'origine des coordonnées de l'écran est le coin supérieur gauche. <br>
L'axe des ordonnées est orienté vers le bas et l'axe des abscisses vers la droite.

### Taille

Distance en pixels de l'origine de cet écran depuis le haut de l'écran étendu.\
Propriété à tester dans une configuration multi-écran, sinon la valeur est égale à 0.

```javascript
window.screen.top = px;
```

Distance en pixels de l'origine de cet écran depuis le côté gauche de l'écran étendu.\
Propriété à tester dans une configuration multi-écran, sinon la valeur est égale à 0.

```javascript
window.screen.left = px;
```
Hauteur de l'écran courant en pixels.

```javascript
window.screen.height = px;
```

Largeur de l'écran courant en pixels.

```javascript
window.screen.width =  px;
```

### Taille disponible

C'est la taille de l'éran moins les éléments fixes de l'écran comme la barre de menu sous OS X et la barre des tâches sous Windows.\
Essayez de déplacer la barre des tâches de Windows à gauche ou en haut de l'écran et observez les valeurs.\
Essayez de passer le navigateur en plein écran et observez les valeurs.

```javascript
window.screen.availTop = px;
```

Ordonnée du premier pixel disponible qui n'est pas occupé par un élément d'interface permanent. Sur Windows essayez de passer la barre des tâches en haut de l'écran.

```javascript
window.screen.availLeft = px;
```

Abscisse du premier pixel disponible qui n'est pas occupé par un élément d'interface permanent. Sur Windows essayez de passer la barre des tâches en haut de l'écran.

```javascript
window.screen.availHeight = px;
```

Hauteur disponible de l'écran courant en pixels.

```javascript
window.screen.availWidth = px;
```

Largeur disponible de l'écran courant en pixels.

### Profondeur de l'écran

La quantification des pixels de l'écran, soit le nombre de bits par pixels pour représenter en autre les nuances de gris ou de couleurs.

```javascript
window.screen.pixelDepth =  bits;
```

La quantification des pixels de l'écran pour représenter les nuances de couleurs. A tester sur des écrans noir & blanc comme des liseuses.

```javascript
window.screen.colorDepth =  bits;
```

### Densité

```javascript
window.devicePixelRatio = ;
```

### Orientation

[Orientation](orientation)


## Fenêtre

Hauteur de la fenêtre du navigateur

```javascript
window.outerHeight = px;
```

Largeur de fenêtre du navigateur

```javascript
window.outerWidth = px;
```

Hauteur de fenêtre du navigateur hors bord, onglets, menus, barre d'adresse et barre de défilement

```javascript
window.innerHeight = px;
```

Largeur de fenêtre du navigateur hors bord et barre de défilement

```javascript
window.innerWidth = px;
```

## Document

Dimensions totales du document.

```javascript
document.documentElement.scrollHeight = px;
document.documentElement.scrollWidth = px;
```

Dimensions visibles du document.

```javascript
document.documentElement.clientHeight = ;
document.documentElement.clientWidth = ;
```

Défilement du document

```javascript
window.scrollY = ;
window.scrollX = ;
```

Pour des raisons de compatibilité `pageYOffset` et `pageXOffset` sont des alias de `scrollY` et `scrollX`.

```javascript
window.pageYOffset = px;
window.pageXOffset = px;
```


### Taille des éléments

<iframe src="iframe/" height="200" style="border:5px solid lightgray; margin: 9px; padding: 13px;"></iframe>

**offsetHeight** est la mesure de la hauteur en pixels CSS de l'élément, y compris la bordure, le remplissage et la barre de défilement horizontale de l'élément.

```javascript
iframe.offsetHeight = ;
iframe.offsetWidth = ;
```

La propriété **clientHeight** renvoie la hauteur visible d'un élément en pixels, y compris le remplissage, mais pas la bordure, la barre de défilement ou la marge.


```javascript
iframe.clientHeight = ;
iframe.clientWidth = ;
```

La valeur **scrollHeight** est égale à la hauteur minimale dont l'élément aurait besoin pour s'adapter à tout le contenu de la fenêtre sans utiliser une barre de défilement verticale.
La hauteur est mesurée de la même manière que clientHeight: elle inclut le remplissage de l'élément, mais pas sa bordure, sa marge ou sa barre de défilement horizontale.

```javascript
iframe.scrollHeight = ;
iframe.scrollWidth = ;
```



<div id="div1" style="overflow: scroll; height:200px; border:5px solid lightgray; margin: 9px; padding: 13px;">
  <div style="height:500px; width:2000px">Margin: 2 x 9px; padding : 2 x 13px; Hauteur de l'élément : 200px<br>

```javascript
element.offsetHeight = ;
element.offsetWidth = ;
```

```javascript
element.clientHeight = ;
element.clientWidth = ;
```

```javascript
element.scrollHeight = ;
element.scrollWidth = ;
```

```javascript
element.scrollTop = ;
element.scrollLeft = ;
```
  </div>
</div>


<script type="application/javascript">
function Load()
{
  console.log(window);
  console.log(window.screen);

  let i = 0;
  let operators = document.querySelectorAll("code .o");
  let message;

  operators[i++].nextSibling.textContent  = ` ${window.screen.top}`;
  operators[i++].nextSibling.textContent  = ` ${window.screen.left}`;
  operators[i++].nextSibling.textContent  = ` ${window.screen.height}`;
  operators[i++].nextSibling.textContent  = ` ${window.screen.width}`;

  operators[i++].nextSibling.textContent = ` ${window.screen.availTop}`;
  operators[i++].nextSibling.textContent = ` ${window.screen.availLeft}`;

  message = ` ${window.screen.availHeight}px`;
  message += (window.screen.height - window.screen.availHeight) ? ` (${window.screen.availHeight - window.screen.height}px)` : '';
  operators[i++].nextSibling.textContent = message;

  message = ` ${window.screen.availWidth}px`;
  message += (window.screen.width - window.screen.availWidth) ? ` (${window.screen.availWidth - window.screen.width}px)` : '';
  operators[i++].nextSibling.textContent = message;

  operators[i++].nextSibling.textContent = ` ${window.screen.pixelDepth}bits`;
  operators[i++].nextSibling.textContent = ` ${window.screen.colorDepth}bits`;

  operators[i++].nextSibling.textContent = ` ${window.devicePixelRatio}`;

  operators[i++].nextSibling.textContent = ` ${window.outerHeight}px`;
  operators[i++].nextSibling.textContent = ` ${window.outerWidth}px`;

  message = ` ${window.innerHeight}px`;
  message += (window.outerHeight - window.innerHeight) ? ` (${window.innerHeight - window.outerHeight}px)` : '';
  operators[i++].nextSibling.textContent = message;

  message = ` ${window.innerWidth}px`;
  message += (window.outerWidth - window.innerWidth) ? ` (${window.innerWidth - window.outerWidth}px)` : '';
  operators[i++].nextSibling.textContent = message;

  operators[i++].nextSibling.textContent = ` ${document.documentElement.scrollHeight}px`;
  operators[i++].nextSibling.textContent = ` ${document.documentElement.scrollWidth}px`;
  operators[i++].nextSibling.textContent = ` ${document.documentElement.clientHeight}px`;
  operators[i++].nextSibling.textContent = ` ${document.documentElement.clientWidth}px`;

  operators[i++].nextSibling.textContent = ` ${window.pageYOffset}px`;
  operators[i++].nextSibling.textContent = ` ${window.pageXOffset}px`;
  operators[i++].nextSibling.textContent = ` ${document.body.scrollTop}px`;
  operators[i++].nextSibling.textContent = ` ${document.body.scrollLeft}px`;


  let iframe = document.querySelector("iframe");

  operators[i++].nextSibling.textContent = ` ${iframe.offsetHeight}px (200 + 2 x 5 + 2 x 13)`;
  operators[i++].nextSibling.textContent = ` ${iframe.offsetWidth}px`;
  operators[i++].nextSibling.textContent = ` ${iframe.clientHeight}px (200 + 2 x 13)`;
  operators[i++].nextSibling.textContent = ` ${iframe.clientWidth}px`;
  operators[i++].nextSibling.textContent = ` ${iframe.scrollHeight}px`;
  operators[i++].nextSibling.textContent = ` ${iframe.scrollWidth}px`;


  let elt = document.querySelector("#div1");

  operators[i++].nextSibling.textContent = ` ${elt.offsetHeight}px`;
  operators[i++].nextSibling.textContent = ` ${elt.offsetWidth}px`;
  operators[i++].nextSibling.textContent = ` ${elt.clientHeight}px`;
  operators[i++].nextSibling.textContent = ` ${elt.clientWidth}px`;
  operators[i++].nextSibling.textContent = ` ${elt.scrollHeight}px`;
  operators[i++].nextSibling.textContent = ` ${elt.scrollWidth}px`;

  Scroll();
}

function Scroll() {
  let operators = document.querySelectorAll("code .o");
  let elt = document.querySelector("#div1");
  operators[19].nextSibling.textContent = ` ${window.scrollY}px`;
  operators[20].nextSibling.textContent = ` ${window.scrollX}px`;
  operators[21].nextSibling.textContent = ` ${window.pageYOffset}px`;
  operators[22].nextSibling.textContent = ` ${window.pageXOffset}px`;
  operators[35].nextSibling.textContent = ` ${elt.scrollTop}px`;
  operators[36].nextSibling.textContent = ` ${elt.scrollLeft}px`;

}

window.addEventListener("load", Load);
window.addEventListener("scroll", Scroll);
document.querySelector("#div1").addEventListener("scroll", Scroll);
</script>
