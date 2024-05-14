---
---

```html
<ons-list>
          <ons-lazy-repeat></ons-lazy-repeat>
        </ons-list>
```javascript

```javascript
let personnes = [];

personnes = await data.json();
        
        var infiniteList = page.querySelector('ons-lazy-repeat');
        infiniteList.delegate = {
          createItemContent: createItemActeur,
          countItems: () => personnes.length
        };

function createItemActeur(index) {
      const acteur = personnes[index];
      var nouvelElement = document.getElementById("item_acteur").content.cloneNode(true);
      nouvelElement.querySelector(".list-item__title").textContent = acteur.nom;
      nouvelElement.querySelector(".list-item__subtitle").textContent = acteur.age??"décédé"
            
      loadImage(nouvelElement.querySelector(".list-item__thumbnail"),
        `https://morseweiswlpykaugwtd.supabase.co/storage/v1/object/public/personnes/${acteur.personne_id}.jpg`);      
    
      return nouvelElement.firstElementChild;
    }

infinite scroll
: En informatique, le défilement infini de contenus - en anglais : infinite scroll, ou infinite scrolling - est une fonctionnalité utilisée en particulier par les interfaces des sites de réseaux sociaux tels que Facebook ou Twitter, qui permet d'afficher automatiquement de nouveaux contenus à la fin de la lecture d'une page sans que l'utilisateur ait besoin d'appuyer sur un bouton Page suivante, ni utiliser un ascenseur de défilement.


lazy load
: Le chargement différé (lazy loading en anglais) est une stratégie d'identification des ressources non bloquantes (non critiques) afin de ne les charger qu'au moment où elles sont utiles. C'est une façon de raccourcir le chemin critique de rendu, ce qui se traduit par une réduction du temps de chargement de la page.
