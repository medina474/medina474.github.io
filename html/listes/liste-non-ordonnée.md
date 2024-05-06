---
title: liste non ordonnée
---

Une liste non ordonnée utilise la balise `<ul>` (***u***nordered ***l***ist) pour la liste et la balise `<li>` pour les éléments.
Chaque élément est précédé d'un marqueur sour forme d'une puce.

```html
<ul>
  <li>France</li>
  <li>Mexique</li>
  <li>Allemagne</li>
  <li>Espagne</li>
  <li>États-Unis d'Amérique</li>
  <li>Royaume-Uni de Grande-Bretagne et d'Irlande</li>
</ul>
```

<ul>
  <li>France</li>
  <li>Mexique</li>
  <li>Allemagne</li>
  <li>Espagne</li>
  <li>États-Unis d'Amérique</li>
  <li>Royaume-Uni de Grande-Bretagne et d'Irlande</li>
</ul>

L'élement `<ul>` est de type bloc. Le bloc est précédé et suivi d'une marge correspondant à une unité de taille de police. Un retrait de 40px est appliqué au début du texte intérieur

```css
ul {
  display: block;
  list-style-type: disc;
  margin-block-start: 1em;
  margin-block-end: 1em;
  padding-inline-start: 40px;
}
```


## Style de la puce

```css
ul { list-style-type: none; }
```

<ul style='list-style-type: none'>
	<li>France</li>
	<li>Mexique</li>
	<li>Allemagne</li>
	<li>Espagne</li>
	<li>États-Unis d'Amérique</li>
</ul>

### Disque plein

```css
list-style-type: disc;
```

<ul style='list-style-type: disc'>
  <li>France</li>
  <li>Mexique</li>
  <li>Allemagne</li>
  <li>Espagne</li>
  <li>États-Unis d'Amérique</li>
  <li>Royaume-Uni de Grande-Bretagne et d'Irlande</li>
</ul>

### Cercle évidé

```css
list-style-type: circle;
```

<ul style='list-style-type: circle'>
  <li>France</li>
  <li>Mexique</li>
  <li>Allemagne</li>
  <li>Espagne</li>
  <li>États-Unis d'Amérique</li>
  <li>Royaume-Uni de Grande-Bretagne et d'Irlande</li>
</ul>

### Carré

```css
list-style-type: square;
```

<ul style='list-style-type: square'>
  <li>France</li>
  <li>Mexique</li>
  <li>Allemagne</li>
  <li>Espagne</li>
  <li>États-Unis d'Amérique</li>
  <li>Royaume-Uni de Grande-Bretagne et d'Irlande</li>
</ul>

### Triangle

```css
list-style-type: triangle;
```

<ul style="list-style-type: triangle;">
  <li>France</li>
  <li>Mexique</li>
  <li>Allemagne</li>
  <li>Espagne</li>
  <li>États-Unis d'Amérique</li>
  <li>Royaume-Uni de Grande-Bretagne et d'Irlande</li>
</ul>

#### Alternative

```css
list-style-type: "\25b8"
```

<ul style='list-style-type: "\25b8"'>Pays
  <li>France</li>
  <li>Mexique</li>
  <li>Allemagne</li>
  <li>Espagne</li>
  <li>États-Unis d'Amérique</li>
  <li>Royaume-Uni de Grande-Bretagne et d'Irlande</li>
</ul>

### Caractère personnalisé

<ul style='list-style-type: "\01F996"'>Pays
  <li>France</li>
  <li>Mexique</li>
  <li>Allemagne</li>
  <li>Espagne</li>
  <li>États-Unis d'Amérique</li>
  <li>Royaume-Uni de Grande-Bretagne et d'Irlande</li>
</ul>


```css
list-style-type: symbols(repeating "○" "●")
```

<ul style='list-style-type: symbols(repeating "○" "●")'>Pays
    <li>France</li>
    <li>Mexique</li>
    <li>Allemagne</li>
    <li>Espagne</li>
    <li>États-Unis d'Amérique</li>
    <li>Royaume-Uni de Grande-Bretagne et d'Irlande</li>
</ul>


<style>
li::marker {
    color:red;
    font-size:112%;
}
</style>

<ul style='list-style-type: symbols(repeating "○" "●")'>Pays
    <li>France</li>
    <li>Mexique</li>
    <li>Allemagne</li>
    <li>Espagne</li>
    <li>États-Unis d'Amérique</li>
    <li>Royaume-Uni de Grande-Bretagne et d'Irlande</li>
</ul>



## Liste imbriquées

<ul style='list-style-type: symbols(repeating "w" "x" "y", "z")'>
	<li>France</li>
	<li>Mexique</li>
	<ul>
        <li>France</li>
        <li>Mexique</li>
        <li>Allemagne</li>
        <li>Espagne</li>
        <ul>
            <li>France</li>
            <li>Mexique</li>
            <li>Allemagne</li>
            <li>Espagne</li>
            <ul>
                <li>France</li>
                <li>Mexique</li>
                <ul>
                    <li>France</li>
                    <li>Mexique</li>
                    <li>Allemagne</li>
                    <li>Espagne</li>
                    <li>U.S.A.</li>
                </ul>
                <li>Allemagne</li>
                <li>Espagne</li>
                <li>U.S.A.</li>
            </ul>
            <li>U.S.A.</li>
        </ul>
        <li>U.S.A.</li>
    </ul>
	<li>Espagne</li>
	<li>U.S.A.</li>
</ul>


[MDN Web Docs.](https://developer.mozilla.org/fr/docs/Web/HTML/Element/ul)
