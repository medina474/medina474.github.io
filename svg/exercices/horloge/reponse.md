---
layout: layouts/page.njk
title: Horloge
---

Les heures

```svg
<line x1="0" y1="95" x2="0" y2="78" stroke-width="3.8" stroke="#111" id="heure"/>
```

Les minutes

```svg
<line x1="0" y1="95" x2="0" y2="90" stroke-width="1.2" stroke="#333" id="minute"/>
```

Le bloc, chaque minute représente 6° (360 / 60)

```svg
<g id="bloc" viewbox="-100 -100 200 200">
  <use href="#heure"/>
  <use href="#minute" transform="rotate( 6)"/>
  <use href="#minute" transform="rotate(12)"/>
  <use href="#minute" transform="rotate(18)"/>
  <use href="#minute" transform="rotate(24)"/>
</g>
```

Le viewBox permet de centrer sur le centre de l'horloge ou sur le bloc de 5 minutes
Attention si on utilise un symbole tous les éléments dans les coordonnées négatives ne sont pas affichés.


Chaque bloc de 5 minutes représente 30° (360 / 12)

```svg
<use href="#bloc" transform="rotate(  0)"/>
<use href="#bloc" transform="rotate( 30)"/>
<use href="#bloc" transform="rotate( 60)"/>
...
<use href="#bloc" transform="rotate(300)"/>
<use href="#bloc" transform="rotate(330)"/>
```

### Les aiguilles

```svg
<line x1="0" y1="-80" x2="0" y2="0" stroke-width="2.8" stroke="#F07882" id="aiguillem" transform="rotate(192)"/>
<line x1="0" y1="-50" x2="0" y2="0" stroke-width="5" stroke="#0092d4" id="aiguilleh" transform="rotate(76)"/>
```

### Le texte

Il convient de redresser le texte après la rotation pour l'amener à sa position sur le cercle.

```svg
<g transform="rotate(240)">
  <text y="70" transform="rotate(-240 0 65)">2</text>
</g>
<g transform="rotate(210)">
  <text y="115" transform="rotate(-210 0 110)">5</text>
</g>
```

### Les sliders

```html
Heures : <input type="range" min="0" max="12" value="2" class="slider heure" /><br/>
Minutes : <input type="range" min="0" max="60" value="32" class="slider minute" />
```

Télécharger le fichier <a href="../solution.svg" download>svg</a>

### Le code javascript

Récupérer les éléments

```javascript
const inputh = document.querySelector("input.heure");
const inputm = document.querySelector("input.minute");
const aiguilleh = document.getElementById("aiguilleh");
const aigiullem = document.getElementById("aiguillem");
```

La fonction pour afficher les aiguilles dans la bonne position

```javascript
function Show() {
  aiguilleh.style.transform = `rotate(${360.0 / 12.0 * inputh.value + 30 / 60 * inputm.value}deg)`;
  aiguillem.style.transform = `rotate(${360.0 / 60.0 * inputm.value}deg)`;
}
```

Attacher la fonctions aux événements `input` des sliders.

```javascript
inputm.oninput = Show;
inputh.oninput = Show;
```

Télécharger le fichier <a href="../solution/index.html" download>html</a>


