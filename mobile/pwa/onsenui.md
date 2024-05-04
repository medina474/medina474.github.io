---
title: Onsen UI
date: 2022-05-03T15:18:26+01:00
draft: false
---

Onsen UI est un framework Javascript qui permet de réaliser des applications web ou hybrides très facilement.

Onsen UI peut s'utiliser avec du javascript classique, avec Angular, VueJS ou ReactJS


### Les éléments Onsen-UI

En html 5 il est possible de déclarer ses propres éléments et balises. C'est ce qui est fait avec OnsenUI qui définit un bon nombre de nouveau élément combinés avec le CSS et le javascript.

Parmi ces nouveaux éléments il y a : alert-dialog, action-sheet, dialog, popover, modal, splitter, list, toolbar-button, tab, tabbar, search-input, page, ...

### Les pages

Onsenu UI est ce que appelle une **SPA** (Single Page Application). Tout ce passe dans une seule page html. La navigation se fait en javascript en chargeant dynamiquement des **fragments** de page qui remplace le contenu actuel.

### La navigation

```html
<ons-navigator id="myNavigator" page="home.html" swipeable />
```

L'élément *&lt;ons-navigator&gt;* gère une pile de pages. Il s'agit d'un type de navigation très courant dans les applications mobiles où une page est poussée au-dessus d'une autre à l'aide d'une animation de transition.

Cet élément est invisible mais essentiel à la gestion du chargement et de l'affichage des pages.

>On appelle à partir de maintenant *page* les pages d'application à ne pas confondre avec la *page* html qui sert de support à l'application.
{.warning}

l'attribut *page* défini la page de démarrage de l'application.

l'attribut *swipeable* permet sur la plateforme iOS de revenir en arrière en effectuant un glissement avec les doigts de gauche à droite.
