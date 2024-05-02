---
title: Utilisation d'une illustration SVG
---

## Image

Une illustration SVG peut être utilisée comme source d'un élément `<img>`

```html
<img src="illustration.svg" />
``` 

<img src="illustration.svg" />

## CSS

Une illustration SVG peut être utilisée comme source pour une image de fond dans du style CSS

En utilisant un fichier externe il est possible d'utiliser une portion personnalisée de l'illstration SVG en spécifiant un paramètre [fragment](../fragment)

```css
.bloc { 
  background:url(illustration.svg); 
}

.bloc3 { 
  background:url(illustration.svg#part3); 
}
```

<div class="bloc ext"></div>

### Comme data URI encodé en base 64

[https://www.base64encode.org/](https://www.base64encode.org/)

L'avantage est que tout est dans un seul fichier, la feuille de style. Il n'ya qu'une requête HTTP à faire et qu'un seul fichier à utiliser
L'encodage en base 64 permet de coder les informations avec des caractères **sûrs** qui n'entraineront pas des effets innatendus (fermeture de balise, guillements, caractère spéciaux). L'inconvénients est que la le nombre de caractères nécessaires est plus élevé de 20 à 30 % par rapport à l'information initiale et que la chaine est totalement illisible.

```css
.bloc { 
background-image: url(data:image/svg+xml;base64,PHN2ZyB4bWxucz0iaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmciIHZlcnNpb249IjEuMSI+CiAgPGNpcmNsZSBjeD0iMTUwIiBjeT0iNzUiIHI9IjcwIiBmaWxsPSIjM2VkMTI0Ii8+Cjwvc3ZnPg==);
}
```

<div class="bloc b64"></div>

Si vous souhaitez mettre la chaine de caractère base 64 sur plusieurs lignes. Il faut entourer la chaine par des guillemets et ajouter un caractère `\` avant chaque retour à la ligne.

```css
background-image: url("data:image/svg+xml;base64,\
PHN2ZyB4bWxucz0iaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdm\
ciIHZlcnNpb249IjEuMSI+CiAgPGNpcmNsZSBjeD0iMTUwIiBj\
eT0iNzUiIHI9IjcwIiBmaWxsPSIjM2VkMTI0Ii8+Cjwvc3ZnPg==");
```

<div class="bloc b64M"></div>

### data URI

Le code source SVG peut être mis directement comme data URI. Il faut faire attention au guillements simples / doubles à l'intérieur de la chaine uri. Il faut aussi échapper les caractères spéciaux qui ont une signification particulière en css comme le # codé en %23

Là aussi les retours à la ligne sont représentés par des `\` 

Le code est plus lisible

```css
.bloc { 
background-image: url("data:image/svg+xml,\
  <svg xmlns='http://www.w3.org/2000/svg' version='1.1'>\
  <circle cx='150' cy='75' r='70' fill='%233ed124'/>\
  </svg>"
}
```

<div class="bloc uriM"></div>

## favicon

Comme icône favorie d'onglet. Avec l'avantage de pouvoir à l'aide des média queries CSS d'adapter l'aspect de l'icone en fonction des situations

[https://css-tricks.com/svg-favicons-and-all-the-fun-things-we-can-do-with-them/](https://css-tricks.com/svg-favicons-and-all-the-fun-things-we-can-do-with-them/)

## En ligne

directement en incorporant le code svg au milieu de la page html

```html
<div>
<svg xmlns="http://www.w3.org/2000/svg">
  <circle cx="150" cy="75" r="70" fill="#3ed124"/>
</svg>
</div>
```

<svg xmlns="http://www.w3.org/2000/svg">
  <circle cx="150" cy="75" r="70" fill="#3ed124"/>
</svg>

C'est de loin la méthode la plus intéressante car avec cette technique la portion SVG est accessible par la feuille de style CSS de la page ainsi que par le javascript.
