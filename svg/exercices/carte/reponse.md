---
title: Colorier une carte
---

### La feuille de style

```css
 <style>
  .niveau1 { fill: #fff7f3; }
  .niveau2 { fill: #fde0dd; }
  .niveau3 { fill: #fcc5c0; }
  .niveau4 { fill: #fa9fb5; }
  .niveau5 { fill: #f768a1; }
  .niveau6 { fill: #dd3497; }
  .niveau7 { fill: #ae017e; }
  .niveau8 { fill: #7a0177; }
  .niveau9 { fill: #49006a; }
</style>
```

### Le tableau

```javascript
<script>
const tableau = [
{ nom:"Auvergne-Rhône-Alpes", code: "FR-ARA", taux: 21 },
{ nom:"Bourgogne-Franche-Comté", code:"FR-BFC", taux: 31},
{ nom:"Bretagne", code:"FR-BRE", taux: 33},
{ nom:"Corse", code:"FR-COR", taux: 12},
{ nom:"Centre-Val de Loire", code:"FR-CVL", taux: 18},
{ nom:"Grand Est", code:"FR-GES", taux: 22},
{ nom:"Hauts-de-France", code:"FR-HDF", taux: 38},
{ nom:"Île-de-France", code:"FR-IDF", taux: 34},
{ nom:"Normandie", code:"FR-NOR", taux: 4},
{ nom:"Nouvelle-Aquitaine", code:"FR-NAQ", taux: 17},
{ nom:"Occitanie", code:"FR-OCC", taux: 28},
{ nom:"Pays de la Loire", code:"FR-PDL", taux: 30},
{ nom:"Provence-Alpes-Côte d'Azur", code:"FR-PAC", taux: 9}
]
</script>
``` 
### Le bouton

```html
<button onclick="colorier()">Colorier</button>
```
### La fonction colorier

```javascript
function colorier()
{
  for(const region of tableau)
  {
    if (region.taux <= 5.0)
      document.getElementById(region.code).classList.add("niveau1")
    else if (region.taux <= 10.0)
      document.getElementById(region.code).classList.add("niveau2")
    else if (region.taux <= 15.0)
      document.getElementById(region.code).classList.add("niveau3")
    else if (region.taux <= 19.0)
      document.getElementById(region.code).classList.add("niveau4")
    else if (region.taux <= 23.0)
      document.getElementById(region.code).classList.add("niveau5")
    else if (region.taux <= 27.0)
      document.getElementById(region.code).classList.add("niveau6")
    else if (region.taux <= 31.0)
      document.getElementById(region.code).classList.add("niveau7")
    else if (region.taux <= 35.0)
      document.getElementById(region.code).classList.add("niveau8")
    else if (region.taux <= 40.0)
      document.getElementById(region.code).classList.add("niveau9")
  }
}
</script>
```

Voir la [solution](../solution)

Télécharger la <a href="../solution" download>solution</a>
