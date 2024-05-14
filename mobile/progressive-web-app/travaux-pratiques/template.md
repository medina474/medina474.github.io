---
title: Template
----

Quelles sont les méthodes pour insérer du nouveau code html dans une page à l'aide de JavaScript ?

### innerHTML

Le première pensée est d'utiliser **innerHTML** qui permet de définir un bloc de code html à insérer dans la page.

#### Inconvénients de l’utilisation de la propriété innerHTML en JavaScript :

Voici la réponse de ChatGPT à la question : _Pourquoi ne faut il pas utiliser innerHTML ?_

L'utilisation de `innerHTML` n'est pas recommandée pour plusieurs raisons :

1. **Sécurité** : L'utilisation de `innerHTML` peut entraîner des problèmes de sécurité, en particulier si vous insérez du contenu utilisateur non filtré. Si vous utilisez `innerHTML` pour injecter du contenu fourni par des utilisateurs sans le filtrer correctement, vous pourriez exposer votre application à des attaques par injection de code malveillant, comme les attaques par injection de script (XSS).

2. **Performance** : Lorsque vous utilisez `innerHTML`, le contenu HTML entier de l'élément cible est re-analysé et re-construit, ce qui peut être coûteux en termes de performances. Si vous utilisez `innerHTML` pour modifier un petit morceau de contenu, cette opération est plus lente et moins efficace que d'utiliser des méthodes spécifiques pour manipuler les éléments DOM.

3. **Perte d'état** : Lorsque vous utilisez `innerHTML` pour modifier le contenu d'un élément, le navigateur détruit tous les éléments DOM enfants existants à l'intérieur de cet élément et recrée les nouveaux éléments à partir de la chaîne HTML fournie. Cela signifie que tout état, événements ou liens attachés aux anciens éléments seront perdus. Cela peut causer des problèmes si vous avez déjà attaché des gestionnaires d'événements ou des références à des éléments spécifiques.

4. **Accessibilité** : `innerHTML` ne tient pas compte de l'accessibilité lorsqu'il recrée les éléments DOM. Si vous utilisez `innerHTML` pour mettre à jour le contenu d'un élément, vous risquez de compromettre l'accessibilité de votre application, car les attributs et les informations nécessaires pour les technologies d'assistance peuvent ne pas être correctement associés aux nouveaux éléments créés.

Il est préférable d'utiliser les méthodes DOM spécifiques pour manipuler les éléments et leur contenu, comme `createElement`, `appendChild`, `removeChild`, `setAttribute`, etc. Ces méthodes offrent un meilleur contrôle sur le DOM, améliorent la sécurité et les performances, et préservent l'état existant et l'accessibilité de votre application.

Pour en savoir plus lire : https://stacklima.com/quel-est-l-inconvenient-d-utiliser-innerhtml-en-javascript/


### createElement

### template

Une des fonctions méconnue d'html 5 est l'utilisation de modèles (template).
Un template est un fragment de code html, non rendu par le navigateur donc totalement invisible et inexistant vis-à-vis de l'utilisateur.

#### Ce que dit ChatGPT à propos des templates

L'utilisation de templates présente plusieurs avantages par rapport à l'utilisation de `createElement` pour générer du contenu dynamique dans le DOM :

1. Syntaxe plus concise : Les templates permettent de définir des structures HTML plus complexes de manière déclarative et facile à lire. Au lieu de construire manuellement chaque élément avec `createElement`, vous pouvez utiliser une syntaxe HTML familière pour définir le contenu du template.

2. Clarté du code : L'utilisation de templates améliore la lisibilité du code en séparant clairement la structure HTML du code JavaScript. Cela facilite la compréhension du code, en particulier pour les développeurs front-end qui sont familiers avec la syntaxe HTML.

3. Réutilisabilité : Les templates peuvent être définis une fois et réutilisés plusieurs fois dans différentes parties de l'application. Cela permet de créer des composants modulaires et d'éviter la duplication de code. Les templates peuvent également être utilisés pour générer des listes d'éléments en liant des données à des modèles.

4. Manipulation simplifiée : Les templates offrent des mécanismes intégrés pour manipuler le contenu généré. Par exemple, vous pouvez utiliser des sélecteurs CSS pour cibler des éléments spécifiques à l'intérieur du template, ajouter des classes, des attributs ou des gestionnaires d'événements aux éléments, le tout de manière plus intuitive et pratique.

5. Performances améliorées : Les templates permettent d'optimiser les performances en évitant la répétition d'opérations coûteuses, comme la modification du DOM à chaque création d'élément. Vous pouvez créer un template une seule fois, cloner ce template et mettre à jour les données liées, ce qui réduit les opérations coûteuses de modification du DOM.

En utilisant des templates, vous pouvez simplifier et améliorer la génération de contenu dynamique dans le DOM, en favorisant une syntaxe plus concise, une meilleure lisibilité du code, une réutilisabilité accrue et des performances optimisées.

Jusqu'au moment ou ce fragment est récupéré, cloné et inséré dans la page comme nouvel élément. C'est ce principe qui est utilisé par Onsen UI que l'on va réutiliser.

```html
<template id="ligne_personne">
  <ons-list-item modifier="chevron" tappable>
    <div class="left">
      <img class="list-item__thumbnail" src="photos/_default.jpg">
    </div>
    <div class="center">
      <span class="list-item__title">
        <span class="prenom"></span>&nbsp;<strong class="nom"></strong>
      </span>
      <span class="list-item__subtitle">
        <span class="naissance"></span>&nbsp;
        <span class="deces"></span>
      </span>
    </div>
  </ons-list-item>
</template>
```

### Définitions

XSS
: Cross-Site Scripting consiste à utiliser une plateforme web vulnérable pour introduire un script malveillant aux internautes. Les cybercriminels injectent leur code malveillant au site web légitime, escroquant ainsi les navigateurs pour que le malware s'active lors de chaque visite du site.

DOM 
: Le Document Object Model est une interface de programmation normalisée par le W3C, qui permet à des scripts d'examiner et de modifier le contenu d'un document HTML. Les éléments de la page sont représentés sous forme d'une liste d'objets reliés selon une structure en arbre..
