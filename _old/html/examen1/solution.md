---

title: Solution
---

### Stocker les données

Premièrement stocker le prix des différents véhicules directement dans le code tablea html 

```html
<td class="violet">THDI</td>
    <td class="prix" data-prix="30000"></td>
```

Faire de même pour les options

Première approche stocker la liste des options disponibles. Mais cela ne règle pas le cas des prix différenciés.

```html
<td class="violet" data-options="multimédia">THDI</td>
  <td class="prix" data-prix="30000" data-options="multimédia,sécurité"></td>
```

Le plus simple est de stocker le prix de l'option directement dans la cellule

```html
<tr>
        <td class="violet">THDI</td>
        <td class="prix" data-prix="30000" data-multimedia="900" data-securite="800"></td>
```

Prendre toutes les cellules

```js
let cellules = document.querySelectorAll("td[data-prix]")
```

Recopier le prix initial dans un dataset `calcul` car nous allons le modifier pour ajouter les options. Il faut pouvoir y revenir.

```js
cellules.forEach(cell => cell.dataset.calcul = cell.dataset.prix);
```

Pour chaque case qui est cochée

```js
document.querySelectorAll("form[name='ex1'] input[type='checkbox']:checked").forEach(check => 
```

si le data option n'est pas présent, le prix doit être désactivé

```js
document.querySelectorAll(`td.prix:not([data-${check.name}])`).forEach(cell => cell.dataset.calcul = -1); 
```

si le data option est présent et que le prix n'est pas désactivé par une précédente option

```js
document.querySelectorAll(`td.prix[data-${check.name}]:not([data-calcul='-1'])`)
```

Ajouter le prix de l'option au calcul du prix

```js
.forEach(td => td.dataset.calcul = Number(td.dataset.calcul) + Number(td.dataset[check.name]) );
```

Pour toute les cellules recopier le prix ou effacer la cellule si le prix est désactivé

```js
cellules.forEach(cell => cell.innerHTML = cell.dataset.calcul == -1 ? "" : Number(cell.dataset.calcul).toLocaleString('fr-FR'));
```

Attacher la méthode de Calcul sur l'événement click des cases à cocher 

```js
document.querySelectorAll("form[name='ex1'] input[type='checkbox']").forEach(elt => elt.addEventListener("click", Calcul));
```

Résultat en 19 lignes de codes !

```js
function Calcul()
{ 
  let cellules = document.querySelectorAll("td[data-prix]")
    
  cellules.forEach(cell => cell.dataset.calcul = cell.dataset.prix);

  document.querySelectorAll("form[name='ex1'] input[type='checkbox']:checked").forEach(check => 
  {
    document.querySelectorAll(`td.prix:not([data-${check.name}])`).forEach(cell => cell.dataset.calcul = -1);
    document.querySelectorAll(`td.prix[data-${check.name}]:not([data-calcul='-1'])`)
        .forEach(td => td.dataset.calcul = Number(td.dataset.calcul) + Number(td.dataset[check.name]) );
  });

  cellules.forEach(cell => cell.innerHTML = cell.dataset.calcul == -1 ? "" : Number(cell.dataset.calcul).toLocaleString('fr-FR'));
}

document.querySelectorAll("form[name='ex1'] input[type='checkbox']").forEach(elt => elt.addEventListener("click", Calcul));

Calcul();
```
