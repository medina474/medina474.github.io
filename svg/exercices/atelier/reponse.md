---
layout: layouts/page.njk
title: Atelier
---


Optimisation des fichiers SVG

```
svgo machine-1.svg -o machine-1-o.svg
```

Si vous n'arrivez pas à utiliser la commande svg vous pouvez utiliser le module Visual Studio Code `svgo`


Du fait de la projection isométrique le viewbox de l'illustration doit être plus grand que la grille.

```svg
<svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 750 420" preserveAspectRatio="xMinYMin" 
  width="1500" height="840">
```

Le motif. Seuls les côté haut et droit sont dessinés les autres sont commun au motif suivant.

```svg
<defs>
  <pattern id="tenthGrid" width="25" height="25" x="5" y="5" patternUnits="userSpaceOnUse">
    <path d="M 25 0 L 0 0 0 25" fill="none" stroke="black" stroke-width="1"/>
  </pattern>
</defs>
```

La grille et un rectangle de sélection rouge. La grille fait 400 x 400 le rectangle 25 x 25

```svg
<g id="grille" fill="none" stroke="#000">
  <rect x="5" y="5" stroke="#000" stroke-width="1" width="400" height="400" fill="url(#tenthGrid)" id="grille" />
  <rect x="5" y="5" width="25" height="25" stroke="#000" stroke-width="1" fill="red" stroke="none" id="rect" />
</g>
```

La projection isométrique

```svg
<g id="grille" fill="none" stroke="#000" transform="translate(360 0) rotate(30) skewX(-30)">
  <rect x="5" y="5" stroke="#000" stroke-width="1" width="400" height="400" fill="url(#tenthGrid)" id="grille" transform="scale(1 0.86603)"/>
  <rect x="5" y="5" width="25" height="25" stroke="#000" stroke-width="1" fill="red" stroke="none" id="rect" transform="scale(1 0.86603)"/>
</g>
```

Le groupe qui va contenir les machines

```svg
<g id="atelier"></g>
```

### le sélecteur

les différentes valeurs des machines sont stockées dans des champs data des éléments html.

```html
<select name="machine">
  <option value="1" data-width="66.860" data-height="69.700" data-scale="1.7" data-originx="14.20" data-originy="69.70">inspection</option>
  <option value="2" data-width="63.140" data-height="82.689" data-scale="1.2" data-originx="17.79" data-originy="82.689">cn</option>
  </select>
```

### Le javascript

Récupérer les coordonnées de l'illustration svg et en déduire le facteur de zoom avec le viewbox. 

Définir l'angle de projection isométrique = 30°

Récupérer le rectangle de sélection rouge

```javascript
let coord = document.getElementsByTagName("svg")[0].getBoundingClientRect();
const zoom = Math.min(750.0 / coord.width, 420.0 / coord.height);
const angle = - Math.PI / 6;
const rect = document.getElementById("rect");
```

Lorsque la souris bouge au dessus de la grille, lire les coordonnées `offsetX` et `offsetY` et les convertir dans la projection isométrique.

Fixer les coordonnées x,y  du rectangle rouge avec les coordonnées calculées, en prenant soin de faire un modulo du pas de 25 et d'inclure la marge de 5px du bord de l'écran.

```javascript
document.getElementById("grille").addEventListener("mousemove", function (evt) 
{           
  let {x, y} = planToIsometric(evt.offsetX, evt.offsetY)
  
  rect.setAttribute("x", Math.floor(x * zoom / 25) * 25 + 5);
  rect.setAttribute("y", Math.floor(y * zoom / 25) * 25 + 5);
});
```

Au clic sur la grille  lire la valeur du sélecteur

```javascript
document.getElementById("grille").addEventListener("click", async function (evt) {
  
  const m = document.getElementsByTagName("select")[0].value;
```

Récupérer le fichier svg optimisé de la machine correspondante

```javascript
const data = await fetch(`machine-${m}-o.svg`)
const str = await data.text(); 
```

Convertir le texte reçu au format xml et extraire l'élément svg.

```javascript
const xml = new window.DOMParser().parseFromString(str, "image/svg+xml");
const svg = xml.children[0];
```

Récupérer les différentes données de la machine

```javascript
const option = document.querySelector(`option[value='${m}']`)
let scale = option.dataset["scale"];
let width = option.dataset["width"];
let height = option.dataset["height"];
let originx = option.dataset["originx"];
let originy = option.dataset["originy"];
```

Ajuster la taille du svg en fonction des données
  
```javascript
svg.setAttribute("width", width * scale);
svg.setAttribute("height", height * scale);
```

Convertir les coordonnées de la souris sur la grille en coordonnées isométriques. Ajuster ces coordonnées au pas de la grille de 25 px en tenant compte de la marge de 5px avec le bord de l'écran.

```javascript
let {x, y} = planToIsometric(evt.clientX , evt.clientY);
  
x = Math.ceil(x * zoom / 25) * 25 + 5;
y = Math.ceil(y * zoom / 25) * 25 + 5;
```

Retourner les coordonnées isométrique en coordonnées réelles, car les illustrations des machines sont déja en 3D et ne doivent pas donc subir de nouvelle transformation

```javascript
({x, y} = isometricToPlan(x , y));
```

Placer l'illustration de la machine aux coordonnées trouvées en se décalant à l'origine (coin inférieur droit) de la machine et ajuster au facteur d'échelle.

```javascript
svg.setAttribute("x", x - originx * scale);
svg.setAttribute("y", y - originy * scale);

document.getElementById("atelier").appendChild(svg);
```

Fonction complète :

```javascript
document.getElementById("grille").addEventListener("click", async function (evt) {
  
  const m = document.getElementsByTagName("select")[0].value;
  
  const data = await fetch(`machine-${m}-o.svg`)
  const str = await data.text(); 
  const xml = new window.DOMParser().parseFromString(str, "image/svg+xml");
  const svg = xml.children[0];
  
  const option = document.querySelector(`option[value='${m}']`)
  let scale = option.dataset["scale"];
  let width = option.dataset["width"];
  let height = option.dataset["height"];
  let originx = option.dataset["originx"];
  let originy = option.dataset["originy"];

  svg.setAttribute("width", width * scale);
  svg.setAttribute("height", height * scale);
  
  let {x, y} = planToIsometric(evt.clientX , evt.clientY);
  
  x = Math.ceil(x * zoom / 25) * 25 + 5;
  y = Math.ceil(y * zoom / 25) * 25 + 5;
  
  ({x, y} = isometricToPlan(x , y));
  
  svg.setAttribute("x", x - originx * scale);
  svg.setAttribute("y", y - originy * scale);

  document.getElementById("atelier").appendChild(svg);
});
```

télécharger le fichier <a href="../demo/index.html" download>html</a>

