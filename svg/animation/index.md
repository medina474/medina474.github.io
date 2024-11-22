---
title: Animation
---

Il exite plusieurs méthodes pour animer des éléments SVG.

### Javascript
Il est possible d'agir avec du javascript sur les propriétés des éléments. Il est nécessaire d'utiliser des bibliothèques tierces pour faciliter la programmation des animations (Comme JQuery par exemple). Cette méthode n'est pas la plus simple, ni la plus rapide à mettre en oeuvre.

### CSS
Les animations en CSS ont l'avantage de pouvoir être utilisées sur n'importe quel élement d'une page html. C'est la méthode la plus utilisée car elle est versatile et elle est la seule à pouvoir être utilisée sur des éléments aussi bien html que SVG.

### SMIL

Le SMIL (Synchronized Multimedia Integration Language) est un langage de description au format xml Il définit des balises pour synchroniser, animer, mettre en page et établir des transitions sur des éléments multimédias tels que du texte, des images, de la vidéo, de l'audio. Le SMIL était le format d'échange des messages multimédias MMS (Multimedia Messaging Service) qui est un équivalent vidéo et image du service de message court (SMS : Short Message Service).

Le langage SMIL n'est plus guère utilisé de manière autonome, il a été intégré au format SVG.

Pourtant très simple il n'est pas aussi utilisée que les animations CSS, pourtant certaines animation ne peuvent s'effectuer qu'avec SMIL.


## Animation d'attribut

la balise animate prend plusieurs paramètres pour effectuer l'opération

`attributeName` : l'attribut pris en compte\
`from` : valeur de départ\
`to` : valeur d'arrivée\
`values`: la liste des valeurs successives de la propriété à animer, si il ya plus de 2 valeurs et que les balises `from` et `to` sont insuffisantes

### minutage
`begin` : début de l'animation\
`end` : fin de l'animation\
`dur` : durée de l'animation\
`min` : durée minimale (dans le cas où la durée de l'animation est calculée à partir d'autres éléments)\
`max` : durée maximale\
`restart` : indique quand l'animation peut être rejouée : `always` (toujours), `whenNotActive` (quand la forme n'est pas en cours d'une autre animation) ou `never` (jamais)\
`repeatCount` : Le nombre de fois que l'animation doit se répéter ou `indefinite` pour une animation infinie\
`repeatDur` : la durée totale en comptant toutes les répétitions\
`fill` : état final de l'animation : `freeze` garde l'animation dans son état finale ou `remove` retourne à l'état initial.

###
`calcMode` :  `discrete`, `linear`, `paced` ou `spline` défini comment sont calculés les points intermédiare de l'animation, l'accélération de celle-ci

<svg xmlns="http://www.w3.org/2000/svg" version="1.1" width="340px" height="140px">
<circle r="50" cx="60" cy="60" fill="red">
<animate
    attributeName="fill"
    values="green;orange;red;green"
    dur="10s"
    calcMode="discrete"
    repeatCount="indefinite"
/>
</circle>
<text x="60" y="130" text-anchor="middle">discrete</text>
<circle r="50" cx="200" cy="60" fill="red">
<animate
    attributeName="fill"
    values="green;orange;red;green"
    dur="10s"
    calcMode="linear"
    repeatCount="indefinite"
/>
</circle>
<text x="200" y="130" text-anchor="middle">linear</text>
</svg>

### interaction


<svg xmlns="http://www.w3.org/2000/svg" version="1.1" width="120px" height="120px">
<rect x="10" y="10" width="100" height="100" fill="#3ed124">
    <animate attributeName="rx" values="0;30;0" dur="5s" repeatCount="indefinite"
    onplaying="console.log('pmaying')"
    onprogress="console.log('p')"
    ontimeupdate="console.log('d')"
    onplay="console.log('c')"
     onbegin="console.log('begin')"
      onend="console.log('end')"
       onrepeat="console.log('repeat')"
    />
</rect>
</svg>

```svg
<rect x="10" y="10" width="100" height="100" rx="5" ry="5" fill="3ed124">
<animate
    attributeName="rx"
    values="0;30;0"
    dur="5s"
    repeatCount="indefinite"
/>
</rect>
```

La balise animate est incluse dans la balise de la forme à animer.


## Animation de forme (Morphing)

L'animation de forme n'est qu'une simple animation d'attribut. Seulement dans ce cas la propriété qui est animée est la propriété `d` d'une balise `path`.

Il est important que tous les chemins de l'animation possède le même nombre de poins, sinon l'animation ne peut pas être calculée.

Dessiner un chemin à l'aide de la balise path, dessiner un 2e chemin avec un nombre de point identique, puis un troisième, quatrième ....

```svg
<animate
    attributeName="d"
    attributeType="XML"
    values=" ; ; ; ;"
/>
```

```svg
<animate
    attributeName="d"
    attributeType="XML"
    from=" "
    to=" "
/>
```

<svg xmlns="http://www.w3.org/2000/svg" version="1.1" width="500px" height="250px" viewBox="0 0 500 250">
<path id="p1"
    d="M 100 100"
    stroke="red" fill="none"
    stroke-width="2" >
<animate xlink:href="#p1"
    attributeName="d"
    attributeType="XML"
    values="M 208.2973,14.715129 A 59.083692,63.810728 0 0 0 154.73861,51.247982 59.083692,63.810728 0 0 0 41.983458,78.647627 c 0,66.976923 112.755152,155.264663 112.755152,155.264663 0,0 112.75513,-88.28774 112.75513,-155.264663 A 59.196446,63.932505 0 0 0 208.2973,14.715129 Z;
    M 8.2973,14.715129 A 59.083692,63.810728 0 0 0 14.73861,51.247982 59.083692,63.810728 0 0 0 41.983458,78.647627 c 100,66.976923 112.755152,155.264663 112.755152,155.264663 0,0 112.75513,-88.28774 112.75513,-155.264663 A 59.196446,63.932505 0 0 0 208.2973,14.715129 Z;M 208.2973,14.715129 A 90.083692,63.810728 0 0 0 154.73861,51.247982 59.083692,63.810728 0 0 0 72.983458,78.647627 c 0,66.976923 112.755152,155.264663 112.755152,135.264663 0,0 112.75513,-88.28774 112.75513,-155.264663 A 0.196446,63.932505 0 0 0 208.2973,14.715129 Z"
    dur="10s"
    repeatCount="indefinite" />
        </path>
</svg>

## Animation de déplacement

L'animation de déplacement permet de déplacer une forme suivant un chemin

```svg
<animateMotion dur="10s"
    repeatCount="indefinite"
    rotate="auto"
    path="M20,50 C20,-50 180,150 180,50 C180-50 20,150 20,50 z" />
```

Dans le cas d'un chemin deja existant

```svg
<animateMotion dur="10s" repeatCount="indefinite">
  <mpath href="#cheminexistant"/>
</animateMotion>
```

## Animation de transformation





https://la-cascade.io/guide-des-animations-svg/

https://css-tricks.com/guide-svg-animations-smil/

SMIL
: Synchronized Multimedia Integration Language

MMS
: Multimedia Messaging Service
