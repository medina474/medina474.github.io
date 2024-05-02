---
layout: layouts/page.njk
title: Interaction en javascript
---

Cibler un élément svg et changer la classe qui lui est appliquée
document.getElementById("soleil2").classList.toggle("gris")

Remarque 1 : Attention au poids des styles, dans l'application en cascade, le style inline a le plus de poids. Pour changer un style il faut que celui-ci se trouve au même niveau.

Cibler un élément contenant un symbole.

Utiliser currentColor pour appliquer la bonne couleur,  Cela fonctionne à condition d'utiliser un nombre restreint de couleur.
Les variables css


