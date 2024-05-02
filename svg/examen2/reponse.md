---
layout: layouts/page.njk
title: Évaluation 2
---

Le symbole, utilisation de **currentColor** pour gérer la deuxième couleur de remplissage.

```svg
<symbol id="siege">
  <rect fill="currentColor" stroke-width=".7" width="20.749941" 
    height="26.691616" x="2.7700462" y="0.35027146" ry="2.9567075"/>
  <path stroke-width=".7" d="M 2.5722259,2.8124281 A 2.2184138,2.2184138 0 0 0 z"/>
</symbol>
```

Les classes

```css
.occupe { fill:#ba6b6c; color: #ef9a9a; stroke:#ececec }
.reserve { fill:#5d99c6; color: #90caf9; stroke:#ececec }
.libre { fill:#75a478; color: #a5d6a7; stroke:#ececec }
```

```svg
<g id="cabine" transform="translate(200 280)">
</g>
```

Le champ de saisie et le bouton

```html
<input id="rangees">
<button onclick="Appliquer()">Appliquer</button>
```

Effacer les éléments de la cabine avec un nouveau remplissage

```javascript
let cabine = document.getElementById("cabine");
  while (cabine.lastChild)
    cabine.removeChild(cabine.lastChild);
```

Ajouter les sièges en rangées et en colonnes

```javascript
const colonnes = [0, 28, 87, 115];
let rangees = document.getElementById("rangees").value;

for (let i = 0 ; i < rangees; i++)
{
  for (let col = 0 ; col < colonnes.length; col++)
    {
      let siege = document.createElementNS("http://www.w3.org/2000/svg", "use");
      siege.setAttribute("href", "#siege");
      siege.setAttribute("y", i * 40);
      siege.setAttribute("x", colonnes[col]);
      siege.setAttribute("class", "libre");
      siege.addEventListener("click", (evt) => { 
        let siege = evt.currentTarget;
        if (siege.classList.contains("libre"))
          siege.setAttribute("class", "reserve");
        else if (siege.classList.contains("reserve"))
          siege.setAttribute("class", "occupe");
      })
      cabine.appendChild(siege);
    }
  }
}
```