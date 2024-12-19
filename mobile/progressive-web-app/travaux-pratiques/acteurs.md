---
title: Page des acteurs
---

## Création de la page

```html
<ons-navigator id="myNavigator" page="acteurs.html" swipeable />
    
<template id="acteurs.html">
  <ons-page id="page_acteurs">
    <ons-toolbar>
      <div class="center">Acteurs</div>
    </ons-toolbar>
    <ons-list>
    </ons-list>
  </ons-page>    
</template>
```

## Peuplement de la liste

[voir](../../../langage/javascript/fetch) le chargement des données en JavaScript

Charger  l'élément onst-list avec les données de la requête : https://morseweiswlpykaugwtd.supabase.co/rest/v1/acteur?select=*


![liste des acteurs](acteurs.png)


#### Appel du web service

```javascript
async function getActeurs(page) {

  const data = await fetch('https://morseweiswlpykaugwtd.supabase.co/rest/v1/acteur?select=*',
    { headers: 
      { apikey: 'xxx'}
    }
  );
  const acteurs = await data.json();
}
```

#### Parcours de la liste

```javascript
for(acteur of acteurs) {
  var nouvelElement = document.createElement('ons-list-item');
  nouvelElement.innerHTML = `
      <div class="left">
        <img class="list-item__thumbnail" src="https://placekitten.com/g/40/40">
      </div>
      <div class="center">
        <span class="list-item__title">${acteur.nom}</span>
        <span class="list-item__subtitle">${acteur.age??'décédé'}</span>
      </div>`;
  page.querySelector('ons-list').appendChild(nouvelElement);
}
```

### Définition

Populate : En français peupler, remplir des éléments (cellules, etc.) initialement vides dans une liste, une collection ou une base de données.
