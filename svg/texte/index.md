---
title: Texte
---

<svg width="0" height="0">
  <defs>
    <pattern id="tenthGrid" width="25" height="25" patternUnits="userSpaceOnUse">
      <path d="M 25 0 L 0 0 0 25" fill="none" stroke="gray" stroke-width="0.5"/>
    </pattern>
    <pattern id="fiftygrid" width="50" height="50" patternUnits="userSpaceOnUse">
      <rect width="50" height="50" fill="url(#tenthGrid)"/>
      <path d="M 50 0 L 0 0 0 50" fill="none" stroke="gray" stroke-width="1"/>
    </pattern>
    <symbol id="grid">
      <rect width="100%" height="100%" fill="url(#fiftygrid)"/>
      <path d="M 500 0 L 500 250 0 250" fill="none" stroke="gray" stroke-width="1"/>
    </symbol>
  </defs>
</svg>

Le texte est géré entièrment par l'utilisateur. il n'y a pas de retour à la ligne automatique ni de calcul d'espacement entre les lignes.

Les balise `tspan` permettent de spécifier une nouvelle position ou des nouveaux attributs pour la partie de texte concernée. Si l'abscisse x n'est pas renseignée alors le texte continue là où il devrait être.

<svg width="500" height="100">
  <use href="#grid"/>
  <text fill="black" y="30" x="0">
    <tspan y="25">Bonjour</tspan>
    <tspan y="50">Tout le monde</tspan>
  </text>
</svg>

```svg
<text>
  <tspan y="30">Bonjour</tspan>
  <tspan y="60">Tout le monde</tspan>
</text>
```

### Alignement

La propriété `text-anchor` permet d'aligné le texte.

 <svg width="500" height="100">
  
  <line x1="100" x2="100" y1="0" y2="130" stroke="red" opacity="0.5"/>
  <line x1="0" x2="300" y1="20" y2="20" stroke="red" opacity="0.5"/>
  <line x1="0" x2="300" y1="50" y2="50" stroke="red" opacity="0.5"/>
  <line x1="0" x2="300" y1="80" y2="80" stroke="red" opacity="0.5"/>
  <text fill="black" y="20" x="100" font-size="22" text-anchor="start">Bonjour</text>
  <text fill="black" y="50" x="100" font-size="22" text-anchor="middle">Bonjour</text>
  <text fill="black" y="80" x="100" font-size="22" text-anchor="end">Bonjour</text>
</svg>

```svg
<text y="20" x="100" font-size="22" text-anchor="start">Bonjour</text>
<text y="50" x="100" font-size="22" text-anchor="middle">Bonjour</text>
<text y="80" x="100" font-size="22" text-anchor="end">Bonjour</text>
```
Les autres propriété pour la mise en forme sont identique au CSS/HTML

## Texte sur un chemin

La balise `textPath` prend comme référence `href` un chemin visible ou non et permet d'écir le long de celui-ci

<svg width="500" height="150">
  <path id="chemin" fill="none" stroke="#3ed124"
    d="m 13.176044,90.907441 c 43.805202,0 47.763989,-37.757205 74.555353,-36.833031 26.791363,0.924174 50.673413,49.0028 83.366583,53.13354 46.40344,5.86301 86.62236,-45.235139 133.36663,-43.614483 61.53586,2.133491 168.2861,19.182088 171.1706,69.437383" />
  <text>
    <textPath href="#chemin">
      Les coïncidences, me répondit mon ami, sont les pires ennemies de la vérité..
    </textPath>
  </text>
</svg>

```svg
<path id="chemin" fill="none" stroke="#3ed124"
    d="m 13.176044,90.907441 ..." />
<text>
  <textPath href="#chemin">
    Les coïncidences, me répondit mon ami, sont les pires ennemies de la vérité..
  </textPath>
</text>
```

## Texte libre

la balise `foreignObject` permet d'inclure un autre document xml à l'intérieur du SVG. En l'occurence ici de l'HTML. Nous retrouvons le fonctionnement normal d'un paragraphe de texte html.

Il est également possible d'utiliser les balises `input` des formulaires.

<svg width="500" height="250">
  <foreignObject x="20" y="20" width="400" height="200">
    <p>Je me trouvais ici. Vers onze heures, après avoir procédé, sur les fourneaux du laboratoire, à une courte expérience de chimie, j’avais fait glisser mon bureau jusqu’ici, car le père Jacques, qui passa la soirée à nettoyer quelques-uns de mes appareils, avait besoin de toute la place qui se trouvait derrière moi. Ma fille travaillait au même bureau que moi.</p>
    <form>
      <input type="text">
    </form>
  </foreignObject>
</svg>

```svg
<foreignObject x="20" y="20" width="400" height="200">
  <p>Je me trouvais ... </p>
  <form>
  <input type="text">
</foreignObject>
```
