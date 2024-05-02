---
title: Sélecteurs
---

## Sélecteur universel

Ce sélecteur cible tous les nœuds d'un document. Il existe également une variante pour ne cibler qu'un seul espace de noms et une variante pour cibler tous les espaces de noms.

```css
*
```

Cible tous les éléments du document.

## Sélecteur de type

Ce sélecteur simple cible les éléments qui correspondent au nom indiqué. 

```css
input
```

Cible tous les éléments `<input>`.

## Sélecteur de classe

Ce sélecteur simple cible les éléments en fonction de la valeur de leur attribut class.

```css
.active
```

Cible tous éléments qui possèdent parmi toutes ses claasses, la classe `active` (comme class="article active dernier").

## Sélecteur d'identifiant

Ce sélecteur simple cible un élément d'un document en fonction de la valeur de son attribut id. Dans un document, il ne doit y avoir qu'un seul élément pour un identifiant donné.

```css
#toc
```

Cible l'élément qui possède l'identifiant `toc` (défini avec l'attribut id="toc").

## Combinateurs

### Sélecteur de voisin direct

Le combinateur `+` permet de sélectionner les nœuds qui suivent immédiatement un élément donné.

```css
div + p
```

Cible n'importe quel élément `<p>` qui suit **immédiatement** un élément `<div>`.

### Les sélecteurs de voisins

Le combinateur `~` permet de sélectionner les nœuds qui suivent un élément et qui ont le même parent.

```css
p ~ span 
```

Cible les éléments `<span>` qui suivent (immédiatement ou non) un élément `<p>` et qui ont le même élément parent.

### Les sélecteurs d'éléments fils

Le combinateur `>` permet de sélectionner les nœuds qui sont des fils directs d'un élément donné.

```css
ul > li 
```

Cible tous les éléments `<li>` qui sont directement situés sous un élément `<ul>`.


### Les sélecteurs d'éléments descendants

Le combinateur (`espace`) permet de sélectionner les nœuds qui sont des descendants (pas nécessairement des fils directs) d'un élément donné.

```css
div span
```

Cible n'importe quel élément `<span>` situé à l'intérieur d'un élément `<div>` quelque soit la profondeur.


## Sélecteurs d’attribut

Les sélecteurs d'attribut permettent de cibler un élément selon la présence d'un attribut ou selon la valeur donnée d'un attribut.

### Présence

```css
div[title]
```

Cible tous les éléments div qui possèdent un attribut title.


### Égalité

```css
div[title="lot"]
```

Cible tous les éléments qui possèdent un attribut title dont la valeur est exactement lot.


### Contient

Cible tous les éléments qui possèdent un attribut title et dont la valeur contient au moins une occurrence de lot (contient) dans la chaîne de caractères. Cela peut-être matelot ou loterie

```css
div[title*="lot"]
```

### Contient le mot

Cible un élément qui possède un attribut title dont la valeur est lot. Cette forme permet de fournir une liste de valeurs, séparées par des blancs, à tester. Si au moins une de ces valeurs est égale à celle de l'attribut, l'élément sera ciblé.

```css
div[title~="lot"]
```

### Contient

Cible un élément qui possède un attribut title dont la valeur est exactement lot ou dont la valeur commence par lot suivi immédiatement d'un tiret (U+002D) lot-. Cela peut notamment être utilisé pour effectuer des correspondances avec des codes de langues. (fr fr-FR fr-BE)

```css
div[title|="lot"]
```

### Commence

```css
div[title^="lot"]
```

### Termine

```css
div[title$="lot"]
```

### Sensibilité à la casse

```css
div[title$="lot"i]
div[title$="lot"s]
```

i : insensible ; s : sensible

## Pseudo classes

```css
:not()
```

La pseudo-classe :first-child cible un élément qui est le premier élément fils par rapport à son élément parent.

```css
:first-child
```

La pseudo-classe :last-child cible un élément qui est le dernier élément fils par rapport à son élément parent.

```css
:last-child
```

Autrement dit, un sélecteur utilisant cette pseudo-classe cible les éléments fils d'un élément dont les positions correspondent au motif an+b.

```css
:nth-child()
```

1n+0 ou n cible chaque élément fils. n ne cible aucun élément pour le navigateur Android jusqu'à la version 4.3 alors qu'1n fonctionne. 1n est synonyme de 1n+0 et les deux peuvent donc être utilisés de façon équivalente.
2n+0 ou 2n cible les éléments fils 2, 4, 6, 8, etc. On pourra utiliser le mot-clé even à la place de cette expression.

2n+1 cible les éléments fils 1, 3, 5, 7, etc. On pourra utiliser le mot-clé odd à la place de cette expression.

3n+4 cible les éléments fils 4, 7, 10, 13, etc.

0n+3 (ou plus simplement 3) cible le troisième élément.



```css
:nth-last-child()
```

```css
:only-child
```

```css
:empty
```

### Premier élément

```css
:first-of-type
```

```css
:last-of-type
```

```css
:nth-last-of-type()
```

```css
:nth-of-type()
```

```css
:only-of-type
```
