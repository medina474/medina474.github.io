---
title: Navigation
---

```html
<ons-navigator id="myNavigator" page="home.html" swipeable />
```

L'élément *<ons-navigator>* gère une pile de pages. Il s'agit d'un type de navigation très courant dans les applications mobiles où une page est poussée au-dessus d'une autre à l'aide d'une animation de transition.

Cet élément est invisible mais essentiel à la gestion du chargement et de l'affichage des pages d'application.

l'attribut *page* défini la page de démarrage de l'application.

l'attribut *swipeable* permet sur la plateforme iOS de revenir en arrière en effectuant un glissement avec les doigts de gauche à droite.

#### Utiliser la navigation

Pour pousser une nouvelle page en premier plan d'affichage, il faut utiliser la méthode javascript *pushPage(page, options)*.

```javascript
myNavigator.pushPage('page2.html');
```

Pour revenir en arrière il ne faut pas utiliser le bouton retour du navigateur, mais un appel à la fonction *popPage*

```javascript
myNavigator.popPage();
```
Une autre méthode consiste à utiliser l'élément *ons-back-button*. Il peut être ajouté sur le côté gauche de la barre d'outils et s'affiche sous forme de flèche.
