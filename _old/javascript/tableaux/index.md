---
title: Tableaux
---

> **Définition :** Les tableaux servent à stocker un ensemble d'éléments de manière **ordonnée**. Ils sont gérés par l'objet `Array`.
{:.definition}

## Création

Il existe plusieurs moyens pour créer un objet `Array`.

<script>var fruits;</script>

En utilisant le constructeur

```javascript
var fruits = new Array();
```

fruits = <span id="d0"></span> 

Le tableau est initialisé avec une liste d'élements passés en argument du constructeur

```javascript
var fruits = new Array("banane", "ananas");
```

fruits = <span id="d1"></span> 

Attention, si le seul argument est un entier n alors le tableau est crée avec n éléments vides (empty slot) et les éléments sont de type indefini (undefined)

```javascript
var fruits = new Array(5);
```

fruits = <span id="d2"></span>

### En utilisant la syntaxe literale

La syntaxte literale utilise des crochets [ et ]

```javascript
var fruits = ["cerise", "abricot"];
```

fruits = "<span id="d3"></span>"

### Indice

Les éléments d'un tableau sont identifiés par leur position appelé indice à l'intérieur du tableau. Le premier indice d'un tableau est 0. Pour un tableau de taille 5 le dernier élément est positionné à l'indice 4.

`fruits[1] =` "<span id="p0"></span>"

Il est possible d'ajouter et d'étendre un tableau en spécifiant une valeur à un indice quelconque.

```javascript
fruits[10] = "kiwi";
```

`fruits.length =` <span id="p1"></span>\
`fruits[9] =` <span id="p2"></span>\
`fruits[10] =` <span id="p3"></span>

Les éléments ajoutés pour combler l'intervalle sont indéfinis.

### Variable et constante

Un tableau défini en tant que constante `const` ne peut pas être redéfini, mais ses éléments peuvent être modifiés, ajoutés, retirés.

```javascript
const panier = new Array("cerise", "abricot");
panier[1] = "banane";
panier[2] = "pomme";
panier.shift();
```

panier = <span id="d4"></span>

Si on tente de redéfinir l'objet.

```javascript
panier = new Array("banane", "pomme");
```

panier = <span id="d5"></span>

### Extraction

Il est possible lors de la définition d'une variable tableau de nommer les éléments à l'intérieur pour pouvoir extraire les valeurs indépendamment

```javascript
const position = new Array(48.6, 6.52)
const [latitude, longitude] = position;
```

latitude = <span id="d6">48.6</span>\
longitude = <span id="d7">6.52</span>

## Caractéristiques

- Les éléments sont restitués dans l'**ordre** dans lequel ils ont été placés dans le tableau
- Chaque élément est repéré par sa position, appelé **indice**, dans le tableau.
- Un même élément peut être présent à **plusieurs reprises** dans le tableau.
- Le premier élément est placé l'**indice 0**. On peut s'en souvenir en pensant que l'indice est le décalage par rapport à l'entrée du tableau. Le premier élément est à l'entrée du tableau donc sans décalage, 0 position de décalage.
- Les élements peuvent être de **nature différentes**.

### Un même élément peut être présent à plusieurs reprises dans le tableau.

```javascript
const fruits = ["orange","banane","cerise","fraise","ananas",
    "pomme","pêche","abricot","poire","pomme","raisin"];
```

```javascript
var user1 = { nom:"Einstein", prenom:"Albert" };
var user2 = { nom:"Curie", prenom:"Marie" };
var users = [ user1, user2, user1 ];
  
users[0].prenom = "Lucien";
```

users = <span id="r0"></span>

C'est bien 2 fois le même objet, la même référence à une zone mémoire, qui est présent dans le tableau.

### Les élements peuvent être de nature différentes.

```javascript
var tableau = new Array("Un grand savant", { nom:"Einstein", prenom:"Albert" }, 
    42, ["1879", "1955"], function(m, c) { return  m*c**2 });    
```

tableau = <span id="r1"></span>

typeof tableau[0] = <span id="r2"></span>\
typeof tableau[1] = <span id="r3"></span>\
typeof tableau[2] = <span id="r4"></span>\
typeof tableau[3] = <span id="r5"></span>\
typeof tableau[4] = <span id="r6"></span>

## Propriétés

### length

La propriété `length` indique le nombre d'éléments contenu dans le tableau.

```javascript
const fruits = ["banane", "pomme"];
fruits[4] = "orange";

fruits.length
```

`fruits.length =` <span id="t0"></span>

## Enumération

Il existe plusieurs moyens pour parcourir et itérer sur toutes les valeurs d'un tableau

Avec une boucle **for**

```javascript
for(let i = 0 ; i < fruits.length ; i++)
{
  document.write(fruits[i]);
}
```
<ul id="t1"></ul>

Avec une fonction passée à la fonction **forEach** du tableau

```javascript
fruits.forEach(function(fruit) {
  document.write(fruit);
});
```

<ul id="t2"></ul>

Avec une itération **for of** sur les éléments


```javascript
for(fruit of fruits) {
  document.write(fruit);
});
```
<ul id="t3">
</ul>

Avec une itération **for in** sur les indices

```javascript
for(indice in fruits) {
  document.write(indice);
});
```

<ul id="t4"></ul>

Les clés

La fonction `keys` retourne un tableau contenant comme valeurs, les indices du tableau.

```javascript
for (const key of fruits.keys()) {
  document.write(key);
}
```

<ul id="t5"></ul>

la fonction `values` retourne un tableau contenant les valeurs du tableau. Cette fonction n'est pas très utiles en l'état

```javascript
for (const value of fruits.values()) {
  document.write(value);
}
```

<ul id="t6"></ul>

```javascript
for (const [key, value] of fruits.entries()) {
  document.write(key + " : " + value);
}
```

<ul id="t7"></ul>

## Opération sur les tableaux

### push

Ajoute un élément au tableau.

```javascript
fruits.push("framboise");
```

fruits.length = <span id="a00"></span>\
fruits = <span id="a01"></span>

### pop

Extrait et retire le dernier élément du tableau.

```javascript
var fruit = fruits.pop();
```

fruit = <span id="a10"></span>\
fruits.length = <span id="a11"></span>\
fruits = <span id="a12"></span>

### shift

Retire le premier élément du tableau.

```javascript
var fruit = fruits.shift();
```

fruit = <span id="a20"></span>\
fruits.length = <span id="a21"></span>\
fruits = <span id="a22"></span>

### unshift

Ajoute un ou plusieurs élément au début du tableau.

```javascript
fruits.unshift("mûre", "groseille"); 
```

fruits.length =  <span id="a31"></span>\
fruits =  <span id="a32"></span>

### concat

La fonction concat concatène 2 tableaux dans un 3e. Elle ne modifie pas le tableau en cours. Il faut réassigner la variable si on veut la conserver

```javascript
fruits = fruits.concat(["citron", "pomélo", "mandarine"]);
```

fruits.length =  <span id="a41"></span>\
fruits =  <span id="a42"></span>

### Décomposition

L'opérateur `spread` noté ... permet d'étendre un tableau en lieu et place de plusieurs arguments (pour les appels de fonctions) ou de plusieurs éléments (pour les littéraux de tableaux).

La fonction unshift prend en paramètres une liste de valeurs séparées par des virgules. Si on veut ajouter un tableau il faut décomposer celui-ci en une liste de valeur sinon nous aurons un élément tableau dans un tableau.

```javascript
var ajout = ["poire", "mirabelle"]
fruits.unshift(...ajout); 
```

fruits.length =  <span id="a51"></span>\
fruits =  <span id="a52"></span>

## Copie d'un tableau

### Copie superficielle

Une copie superficielle `shallow copy` copie l'adresse des objets originaux. Une modification dans l'original affecte la copie.

```javascript
var fruits = new Array("pomme", "banane");
var copie = fruits;
fruits[1] = "framboise";
```

copie[1] = <span id="c1"></span>

### Copie profonde

Une copie profonde `deep copy` duplique la source des éléments pour créé un nouveau tableau. Les éléments ne partage plus la même zone mémoire et sont indépendant. Il faut utiliser l'opérateur de décomposition pour extraire les valeurs et les réinjecter dans le constructeur de l'objet tableau.

```javascript
var fruits = new Array("pomme", "banane");
var copie = new Array(...fruits);
fruits[1] = "framboise";
```

copie[1] = <span id="c2"></span>

Attention Shallow copy pour tous les objets sauf pour String, Number et Boolean (Deep Copy)

## Tri

### reverse

Inverse l'ordre des éléments

```javascript
var fruits = ["mirabelle","mûre","groseille","pomme","orange","citron","pomélo","mandarine"];
fruits.reverse();
```

<span id="c3"></span>

### sort

```javascript
fruits.sort();
```
Le tableau est trié sur place il faut le copier d'abord si on veut conserver l'original

<span id="c4"></span>

## Recherche

### includes

Indique si un élément est présent dans le tableau, peu importe sa position.

```javascript
var fruits = ["mirabelle","mûre","groseille","pomme","orange","citron","pomme","mandarine"];
fruits.includes("pomme");
```
fruits.includes("pomme") = <span id="h1"></span>

### indexOf

Indique quelle est la position de l'élément dans le tableau. Si il y en a plusieurs, c'est la position du premier qui est retourné

```javascript
fruits.indexOf("pomme");
```

fruits.indexOf("pomme") = <span id="h2"></span>

Attention à l'index 0 qui est équivalent à faux alors que l'élément a été trouvé en toute première position !

### lastIndexOf

Indique quelle est la position de l'élément dans le tableau. Si il y en a plusieurs, c'est la position du dernier qui est retourné

```javascript
fruits.lastIndexOf("pomme")
```
fruits.lastIndexOf("pomme") = <span id="h3"></span>

## Extraire et remplacer

### slice
    
La méthode slice() renvoie un tableau, contenant une copie superficielle (shallow copy) d'une portion du tableau d'origine, la portion est définie par un indice de début et un indice de fin (exclus). Le tableau original ne sera pas modifié.

```javascript
var fruits = ["mirabelle","mûre","groseille","pomme","orange","citron","pomme","mandarine"];
var extrait = fruits.slice(2, 5) 
```

extrait = <span id="h4"></span>


### splice

La méthode splice() modifie le contenu d'un tableau en retirant des éléments et/ou en ajoutant de nouveaux éléments à même le tableau. On peut ainsi vider ou remplacer une partie d'un tableau.

Le premier paramètre indique l'indice de départ, le deuxième le nombre d'élements à supprimé et ensuite vient une liste (qui peut être vide) d'élément à insérer

```javascript
var fruits = ["mirabelle","mûre","groseille","pomme","orange","citron","pomme","mandarine"];
fruits.splice(2, 2, 'poire'); 
```

fruits = <span id="h5"></span>

## Fonctions sur les tableaux

Ces fonctions spéciales prennent en paramètre un fonction qui sera évaluée pour chaque élément du tableau. Cela permet une grande personnalisation dans le traitement.

### Tri personnalisé

`Array.sort(__function expression__)`

La fonction **sort()** crée et retourne un nouveau tableau contenant tous les éléments du tableau d'origine triés. Le tir s'éffectue suivant le résultat de la fonction définie en paramètres et ontenant une expresion de fonction .

La fonction expression prend en paramètres 2 éléments du tableau et doit retourner un nombre négatif si le premier élément est avant le deuxième,
0 si les 2 élements sont au même rang
et positif si le premier élément est après le deuxième.

    tableau.sort((eltA, eltB) => eltA - eltB)

Le résultat de la soustraction correspond bien au résultat que l'on veut pour le tri.

### Filtre sur un tableau

`Array.filter(__expression function__)`

La méthode **filter()** crée et retourne un nouveau tableau contenant tous les éléments du tableau d'origine qui remplissent une condition déterminée par la fonction expression.

### La condition est-elle remplie au moins une fois

`Array.some(__expression function__)`

### La condition est-elle satisfaite pour tous les éléments

`Array.every(__expression function__)`

### find()

## Le patron de conception Map, Filter, Reduce

Map, Filter, Reduce est un modèle de conception (pattern) qui implémente des fonctions qui opèrent sur des séquences de données.

### Map

**Map** applique une fonction unaire à chaque élément de la séquence et renvoie une nouvelle séquence contenant les résultats, dans le même ordre.

```javascript
Array.map(__expression function__);
```

### filter()

### Reduce()

**Reduce** combine les éléments de la séquence ensemble, en utilisant une fonction binaire. Un accumulateur est passé d'éléments en éléments qui permet d'ajouter (accumuler) les valeurs une à une. Le résultat final est une seule et unique valeur.

    Array.reduce(__expression function__);

L'intérêt de ces fonctions est de pouvoir les chainer et combiner pour effectuer en une seule ligne plusieurs opération.

```javascript
Array.filter(__expression function__).map(expression).reduce(__expression function__);
```

Utilisation de reduce pour sélectionner une ligne suivant un critère

```javascript
Array.reduce(function (select, current) {
  return current > select ? current : bts;
});
```

- Array.from()
- Array.isArray()
- Array.observe()
- Array.of()
- Array.prototype.copyWithin()

- Array.prototype.fill()

- Array.prototype.
- Array.prototype.forEach()
- Array.prototype.join()
- Array.prototype.reduceRight()
- Array.prototype.toLocaleString()
- Array.prototype.toSource()
- Array.prototype.toString()
- Array.prototype[@@iterator]()
- Array.unobserve()
- get Array[@@species]   

- Array.prototype.includes()
- Array.prototype.findIndex()

https://dmitripavlutin.com/how-three-dots-changed-javascript/

:shallow copy
copie superficielle

:deep copy 
copie profonde

<script>
document.getElementById('d0').innerText = JSON.stringify( new Array() );
document.getElementById('d1').innerText = JSON.stringify( new Array('banane', 'ananas') );
document.getElementById('d2').innerText = JSON.stringify( new Array(5) );
document.getElementById('d3').innerText = JSON.stringify( ['cerise', 'abricot'] );

var fruits = ['cerise', 'abricot'];
fruits[10] = "kiwi";

document.getElementById('p0').innerText = fruits[1]
document.getElementById('p1').innerText = fruits.length
document.getElementById('p2').innerText = fruits[9]
document.getElementById('p3').innerText = fruits[10]

const panier = new Array('cerise', 'abricot');
panier[1] = 'banane';
panier[2] = 'pomme';
panier.shift();
document.getElementById('d4').innerText = JSON.stringify(panier);

try { panier = new Array(); } catch(error) { document.getElementById('d5').innerText = error; }



var user1 = { nom:'Einstein', prenom:'Albert' };
var user2 = { nom:'Curie', prenom:'Marie' };
var users = [ user1, user2, user1];
users[0].prenom = 'Lucien';
document.getElementById('r0').innerText = JSON.stringify(users);

var tableau = new Array("Un grand savant", { nom:"Einstein", prenom:"Albert" }, 42, ["1879", "1955"], function() { return "E = mc²" }); 
document.write(JSON.stringify(tableau));
document.getElementById('r1').innerText = JSON.stringify(tableau);
document.getElementById('r2').innerText = Object.prototype.toString.call(tableau[0]);
document.getElementById('r3').innerText = Object.prototype.toString.call(tableau[1]);
document.getElementById('r4').innerText = Object.prototype.toString.call(tableau[2]);
document.getElementById('r5').innerText = Object.prototype.toString.call(tableau[3]);
document.getElementById('r6').innerText = Object.prototype.toString.call(tableau[4]);


fruits = ["banane", "pomme"];
fruits[4] = "orange";

document.getElementById('t0').innerText = fruits.length;

let liste = "";
for(let i = 0 ; i < fruits.length ; i++)
{
  liste += `<li>${fruits[i]}</li>`
}

document.getElementById('t1').innerHTML = liste;

liste = "";
fruits.forEach(function(fruit) {
  liste += `<li>${fruit}</li>`
});
document.getElementById('t2').innerHTML = liste;

liste = "";
for(fruit of fruits) {
  liste += `<li>${fruit}</li>`
}
document.getElementById('t3').innerHTML = liste;

liste = "";
for(fruit in fruits) {
 liste += `<li>${fruit}</li>`
}
document.getElementById('t4').innerHTML = liste;

liste = "";
for (const key of fruits.keys()) {
  liste += `<li>${key}</li>`
}
document.getElementById('t5').innerHTML = liste;

liste = "";
for (const value of fruits.values()) {
  liste += `<li>${value}</li>`
}
document.getElementById('t6').innerHTML = liste;

liste = "";
for (const [key, value] of fruits.entries()) {
  liste += `<li>${key} : ${value}</li>`
}
document.getElementById('t7').innerHTML = liste;




fruits.push("framboise");
document.getElementById('a00').innerText = fruits.length
document.getElementById('a01').innerText = JSON.stringify(fruits);

document.getElementById('a10').innerText = fruits.pop();
document.getElementById('a11').innerText = fruits.length
document.getElementById('a12').innerText = JSON.stringify(fruits);

document.getElementById('a20').innerText = fruits.shift();
document.getElementById('a21').innerText = fruits.length
document.getElementById('a22').innerText = JSON.stringify(fruits);


fruits.unshift("mûre", "groseille");
document.getElementById('a31').innerText = fruits.length
document.getElementById('a32').innerText = JSON.stringify(fruits);

fruits = fruits.concat(["citron", "pomélo", "mandarine"]);
document.getElementById('a41').innerText = fruits.length
document.getElementById('a42').innerText = JSON.stringify(fruits);

fruits.unshift(...["poire", "mirabelle"]);
document.getElementById('a51').innerText = fruits.length
document.getElementById('a52').innerText = JSON.stringify(fruits);

fruits = new Array("pomme", "banane");
var copie = fruits;
fruits[1] = "framboise";
document.getElementById('c1').innerText = copie[1];

fruits = new Array("pomme", "banane");
copie = new Array(...fruits);
document.getElementById('c2').innerText = copie[1];

fruits = ["poire","mirabelle","mûre","groseille","pomme","orange","citron","pomélo","mandarine"];
fruits.reverse();
document.getElementById('c3').innerText = JSON.stringify(fruits);

fruits.sort();
document.getElementById('c4').innerText = JSON.stringify(fruits);

fruits = ["mirabelle","mûre","groseille","pomme","orange","citron","pomme","mandarine"];
document.getElementById('h1').innerText = fruits.includes("pomme");
document.getElementById('h2').innerText = fruits.indexOf("pomme");
document.getElementById('h3').innerText = fruits.lastIndexOf("pomme");

fruits = ["mirabelle","mûre","groseille","pomme","orange","citron","pomme","mandarine"];
document.getElementById('h4').innerText = fruits.slice(2, 5);

fruits.splice(2, 2, 'poire')
document.getElementById('h5').innerText = fruits;

fruits.keys
fruits.values

</script>
