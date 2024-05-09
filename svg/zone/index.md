---
title: Zone d'affichage et zone de travail
---

## Zone d'affichage
Le **viewport** est la zone d'affichage visible d'une illustration SVG.
Le viewport est défini grâce aux propriétés `height` et `width` de l’élément racine `<svg>`.

> Le ***viewport*** est la fenêtre d'affichage ouverte sur le svg. Seule une partie de l'illustration est visible à travers cette fenêtre.
{:.definition}

## Zone de travail

Le **viewBox** est la zone de travail de l'ensemble de l'illustration SVG.

Créer un élément svg et ajouter un cercle de rayon 30px dont le centre est situé à 330px à gauche et à 180px du haut.

```svg
<svg>
  <circle cx="330" cy="180" r="30" fill="#3ed124">
</svg>
```

<svg>
  <circle cx="330" cy="180" r="30" fill="#3ed124" />
</svg>

Que se passe-t-il ? 

Le cercle n’est pas visible car il est **en dehors du viewport**.

>Le viewport par défaut d'un élément svg est de **300px / 150px**.
{:.definition}

Changer le viewport de l’élément svg en  360px de large et 210px de haut en utilisant les attributs `width` et `height` de l'élément `<svg>`. 

```svg
<svg width="360" height="210">
```

<svg width="360" height="210">
  <circle cx="330" cy="180" r="30" fill="#3ed124" />
</svg>

La taille de SVG est agrandie, le cercle est maintenant visible.

## Mise à l'échelle

Une illustration SVG peut logiquement être aussi large et haute que vous le souhaitez. Mais comment redimensionner la taille de l'image resultante dans la page html sans masquer les éléments en dehors du viewport ?

Pour cela nous allons définir la taille du plan de travail, le navigateur se charge ensuite de mettre à l'échelle l'illustration pour que le plan de travail corresponde à la fenêtre d'affichage.

Définir un plan de travail très large de 3000px / 2000px. Tracer un cercle de rayon 200 à 2500px/1500px. Régler la fenêtre d'affichage sur 150px/100px.

Le **viewbox** est défini par 4 nombres, les coordonnées de l'origine sa largeur et sa hauteur qui marquent les limites de la zone de travail.

```svg
<svg width="150" height="100" viewbox="0 0 3000 2000">
<circle cx="2500" cy="1500" r="200" fill="#3ed124" />
</svg>
```

<svg width="150" height="100" viewbox="0 0 3000 2000">
<circle cx="2500" cy="1500" r="200" fill="#3ed124" />
</svg>

L'illustration est mise à l'échelle (zoom) pour faire correspondre le viewport avec le viewbox. Dans ce cas, la mise à l'échelle est de 150/3000 soit 1/20.
L'image est enfin réduite mais sans perdre les éléments de l'illustration.

## Ratio / correpondance

Que se passe-t-il maintenant si la proportion hauteur/largeur du viewport ne correspond pas à la proportion du viewbox ? L'image est-elle déformée ?

Créer une illustration de 3000/2000.
- Ajouter un rectangle A plein de 4000/2000.
- Ajouter un carré B de 200 de côté situé à 1400/900.
- Ajouter un cercle C de rayon 200 situé à 3000/1800.
- Ajouter un triangle D de sommets -750/500 -1000/1000 -500/1000
- Ajouter le contour E d'un rectangle de taille 3000/2000.

Afficher l'illustration dans une image (viewport) de taille 450/60

Premières constations :
- Le rectangle A est plus large que le plan de travail (viewbox)
- Le cercle C est à moitié en dehors du plan de travail
- Le triangle D est totalment en dehors du plan de travail 
- Échelle en x = 450 / 3000 = 1 / 6.66666 
- Échelle en y = 60 / 2000 = 1 / 33.33333

<svg width="450" height="60" viewbox="0 0 3000 2000">
<use href="#illustration" />
</svg>

L'illustration est mise à l'échelle au plus petit ratio pour que l'ensemble du viewbox soit contenu dans le viewport. L'illustration est centrée dans le viewport sans déformation. Des marges vides ont été ajoutées à gauche et à droite de l'image. Les éléments qui sont en dehors du viewbox se retrouvent affichés

Passons la taille du viewport à 110 / 60.

<svg width="110" height="60" viewbox="0 0 3000 2000">
<use href="#illustration" />
</svg>

Les éléments qui sont en dehors du viewbox se retrouvent affichés si possible sans garantie !

Passons la taille du viewport à 100 / 160.

<svg width="100" height="160" viewbox="0 0 3000 2000">
<use href="#illustration" />
</svg>

Le ratio est inversé les marges sont maintenant en haut et en bas.

> Seuls les éléments à l'intérieur du viewbox sont affichés avec garantie.
{:.info}

### Alignement

Ajouter la propriété `preserveAspectRatio` avec la valeur **xMinYMid** à l'illustration.

```svg
<svg viewbox="0 0 3000 2000" preserveAspectRatio="xMinYMid">
```

<svg width="450" height="60" viewbox="0 0 3000 2000"  preserveAspectRatio="xMinYMid">
<use href="#illustration" />
</svg>

Avec la valeur **xMaxYMid**

<svg width="450" height="60" viewbox="0 0 3000 2000"  preserveAspectRatio="xMaxYMid">
<use href="#illustration" />
</svg>
 
Le plan de travail est aligné à gauche ou à droite suivant la valeur. Ce qui est en dehors du viewbox du côté de l'alignement n'est pas affiché.

La propriété preserveAspectRatio permet de définir comment sera aligné le viewbox à l’intérieur du viewport et où se trouverons les marges du fait de la non-correspondance du ratio hauteur/largeur.

<table>
<tr><th></th><th>xMin</th> <th>xMid</th>	<th>xMax</th></tr>
<tr><th>yMin</th><td>xMinYMin</td> <td>xMidYMin</td>	<td>xMaxYMin</td></tr>
<tr><th>yMid</th><td>xMinYMid</td> <td>xMidYMid</td>	<td>xMaxYMid</td></tr>
<tr><th>xMax</th><td>xMinYMax</td> <td>xMidYMax</td>	<td>xMaxYMax</td></tr>
</table>

## remplissage

Si nous voulons remplir complétement le viewport sans ajouter aucune marge il faut ajouter le mot clé `slice` au viewbox. La forme est coupée au besoin, et l'ensemble du viewport est rempli par la zone du viewbox sans aucune marge.

Dans ce cas c'est le facteur d'échelle le plus grand qui est pris en compte.  

Le placement s'effectue avec les mots clés xM..yM.. qui permettent de choisir la zone à sélectionner et celle à évacuer.

```svg
<svg viewbox="0 0 3000 2000" preserveAspectRatio="xMidYMid slice">
```

<svg width="450" height="60" viewbox="0 0 3000 2000"  preserveAspectRatio="xMidYMid slice">
<use href="#illustration" />
</svg>

```svg
<svg viewbox="0 0 3000 2000" preserveAspectRatio="xMidYMax slice">
```

<svg width="450" height="60" viewbox="0 0 3000 2000"  preserveAspectRatio="xMidYMax slice">
<use href="#illustration" />
</svg>

meet
: le viewbox est contenu complètement dans le viewport. Des marges apparaissent pour combler l'espace.

slice
: le viewbox rempli entièrement le viewport. L'illustration n'est pas completement visible, des éléments peuvent se retrouver en dehors de l'affichage.

A noter : 

<svg viewbox="0 0 3000 2000">
<use href="#illustration" />
</svg>

<style>svg { border: 1px solid black }</style>
<svg width="0" height="0" style="dislay:none;border:0">
<g id="illustration">
<rect width="4000" height="2000" fill="#e0ffff"/>
<rect x="1400" y ="900" width="200" height="200"  fill="red" />
<circle cx="3000" cy="1800" r="200" fill="#f00000" />
<polygon points="-750 500, -1000 1000 -500 1000" fill="red"/>
<rect width="3000" height="2000" stroke="#000" stroke-width="30" fill="none"/>
</g>
</svg>
