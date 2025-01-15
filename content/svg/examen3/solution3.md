---
title: Solution de l'évaluation SVG n° 3
---

Ajouter le svg de la carte de l'Europe dans la page. Ajouter une propriété `viewbox` pour [recadrer](../../zone/) la carte.

```svg
<svg width="990.133" height="797.822" xmlns="http://www.w3.org/2000/svg" viewbox="155 215 445 380">
```

Ajouter un [symbole](../../bibliotheque/) dans un bloc de définition `defs`ne pas oublier le `viewbox` pour pouvoir le redimensionner plus tard

```svg
<defs>
<symbol id="plane" viewBox="0 0 800 800">
  <path  d="m 800,41.803859 q 0,49.821051 Z"/>
</symbol>
</defs>
```

Ajouter le symbole dans l'illustration. Appliquer deux [transformations](../../transformation) : une rotation de 45° et une translation pour aligner le nez de l'avion avec l'abscisse x=0

```svg
<use id="avion" x="0" href="#plane" width="10" height="10" transform="rotate(45) translate(-9 0)" />
```
Ajouter le [chemin](../../formes). Pour l'instant il ne contient qu'un point d'origine. 

```svg
<path id="trajectoire" d="M0,0" fill="none" stroke-dasharray="5 5" 
  stroke-width="2" stroke="red"></path>
```

Attacher un événement `clic` sur les cercles.

```javascript
document.querySelectorAll("circle").forEach(ville => ville.addEventListener("click", evt => {
```

La fonction pour calculer la distance euclidienne entre 2 points

```javascript
function getDistance(x1, y1, x2, y2) {
   return Math.sqrt( Math.pow(x2 - x1, 2) + Math.pow(y2 - y1, 2) );
}
```

Déclaration des variables globales. L'élément svg avion, le cercle de départ, le chemin tel qu'il sera construit et la durée totale de l'animation

```javascript
let avion = document.querySelector("#avion");
let depart;
let path = "";
let dur = 0;
```

Lors du clic, si le départ n'est pas encore défini, le définir et commencer le chemin par une commande **M** suivi d'une commande **L** pour les segments à venir

```javascript
if (depart) 
{ }
else {
  depart = evt.currentTarget; 
  path = `M${depart.getAttribute("cx")},${depart.getAttribute("cy")}L` ;
}
```

Si il y a deja un départ. Prendre le point d'arrivée, calculer la longueur du segment (depart et arrivée). Calculer la durée totale en divisant par 20 le nombre de pixels de distance. Ajouter le point d'arrivée au chemin. Fixer l'arrivée comme le _prochain_ départ. 

```javascript
if (depart) 
{ 
  let arrivee = evt.currentTarget; 
  let longueur = getDistance(arrivee.getAttribute("cx"), arrivee.getAttribute("cy"), 
                             depart.getAttribute("cx"), depart.getAttribute("cy"));
  dur += longueur / 20;
  path += ` ${arrivee.getAttribute("cx")},${arrivee.getAttribute("cy")}`; 
  depart = arrivee;
}
```

Ajouter une [animation](../../animation) de chemin `animateMotion` avec comme référence la trajectoire.

```svg
<use id="avion" x="0" href="#plane" width="10" height="10" transform="rotate(45) translate(-9 0)" >
  <animateMotion dur="5s" repeatCount="1" restart="whenNotActive" rotate="auto" fill="freeze">
    <mpath href="#trajectoire"/>
  </animateMotion>
</use>
```

Si une durée a été calculée. Appliquer le chemin `path` construit à l'élément trajectoire. Fixer aussi la durée de l'animation et démarrer l'animation

```javascript
if (dur)
{
  let trajectoire = document.querySelector("#trajectoire");
  trajectoire.setAttribute("d", path);

  let anim = avion.querySelector("animateMotion");
  anim.setAttribute("dur", `${dur}s`);
  anim.beginElement();
}
```

Si il n'y a pas encore de durée, stopper l'animation.

```javascript
else
{
  let anim = avion.querySelector("animateMotion");
  anim.endElement();
}
```

<a href="../reponse3" download>télécharger</a> la solution

Voir la [solution](../reponse3)
