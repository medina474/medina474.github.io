---
title: JAMStack
---

# Eleventy

Créer le projet et installer Eleventy (11ty)

```>shell
git init

npm init
npm install --save-dev @11ty/eleventy
```

Par défaut les fichiers pris en compte sont ceux situés à la racine du projet. Cela permet d'inclure eleventy dans un projet existant sans en modifier la structure.

Pour ce projet les fichiers sources sont dans le dossier `src`.

Créer un fichier `.eleventy.js` à la racine. Ce fichier contient la configuration et les actions de compilation.

Il faut définir le dossier `src` comme étant l'entrée d'eleventy.

```javascript
module.exports = function (config) {

  return { dir: { input: "src" } }
};
```

Exclure du contrôle de version (`.gitignore`) les dossiers `_site` et `node_modules`.

```yaml
node_modules
package-lock.json

# Eleventy
_site
```

## Template

Les fichiers sources de contenu sont appelés templates. Plusieurs formats peuvent être utilisés au choix. Nous allons utiliser le format Markdown. Le code [Markdow](markdown) permet de formater du texte en html avec des codes très simples. Cette syntaxe comprenant moins de code que du html classique, il permet de se concentrer sur le contenu sans le noyer au milieu d'un tas de balises et de propriétés.

Indiquer au compilateur 11ty de traiter les fichiers Markdown.



``` javascript
const markdownIt = require("markdown-it");

let markdownLib = markdownIt();
config.setLibrary("md", markdownLib);
```

Le code Markdown est converti au format html mais pour être pleinement fonctionnel il faut l'inclure dans une page complète.

## Layout

Le contenu va être intégré dans des layouts pour un rendu final.

Créer un dossier `src/_includes/layouts` et placer un fichier `page.njk`.
Le format njk Nunjucks est un format qui ajoute des balise de remplacement dans un fichier html.


les variables de remplacement sont balisées entre double accolades <code>&lbrace;&lbrace;&nbsp;&rbrace;&rbrace;</code>


La page html possède un bloc liminaire appelé `Front Matter` au format `YALM`. Ce bloc contient des informations importantes qui renseignent le contenu à venir.
Nous allons définir une variable `title` contenant le titre de notre page. Ensuite cette variable peut être utilisée à l'intérieur de la page graçe à la syntaxe Nunjucks.

La variable `content` proviendra du contenu markdown des différents templates. Le filtre `safe` échappe les caractères spéciaux html pour un rendu fidèle sans interférence avec les balises html.


``` html
---
title: Programmation embarquée
---
<!doctype html>
<html lang="fr">
<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>{{ title }}</title>
</head>
<body>
<h1>{{ title }}</h1>
{{ content | safe }}
</body>
</html>
```

Les templates markdowns vont eux aussi intégrer un bloc front matter. Avec une variable `layout` pour indiquer quel fichier layout utiliser et une variable `title` qui va écraser la variable `title` du layout.

```yaml
---
layout: layouts/page.njk
title: PostgreSQL
---
```

Compiler les fichiers. Il seront placés dans un dossier `_site`. Démarrer le serveur web intégré.

```>shell
$ npx @11ty/eleventy --serve
```

## CSS

```>shell
npm install --save-dev clean-css
```

Dans l'export du fichier `.eleventy.js`

```javascript
const cleancss = require("clean-css");
config.addFilter("cleancss", function (code) {
  return new cleancss({}).minify(code).styles;
});
```

Créer un fichier `styles.njk`. Le front maker du fichier indique avec la variable `permalink` l'emplacement et le nom du fichier final.

les commande nunjucks `include` permettent d'inclure les sources d'autres fichiers.

La commande `set` permet de définir une nouvelle variable nunjucks. (En plus de celles déclarées dans le front maker)

Cette variable est ensuite insérée directement dans la page en appliquant le filtre `cleancss`.

```
---
permalink: css/styles.css
---
﹛% set css %﹜
  ﹛% include "components/main.css" %﹜
  ﹛% include "components/blockquote.css" %﹜
  ﹛% include "components/prism.css" %﹜
﹛% endset %﹜

﹛﹛ css | cleancss | safe ﹜﹜
```

## Images

Les fichier images sont simplement recopiés du dossier source (`src`) vers le dossier destination (`_site`).

```javascript
config.addPassthroughCopy("src/**/*.png");
```

## Bloc code source

Pour déclarer un bloc de code il suffit d'entourer les lignes de codes par une clôture de code (`code fence`) représentée  des triples accents ` ``` `.

~~~
```
let div = document.getElementById("menu");
```
~~~

Pour la coloration syntaxique il faut ajouter le plugin syntaxhighlight et ajouter au` code fence` le langage à mettre en évidence.

```>shell
$ npm install -save @11ty/eleventy-plugin-syntaxhighlight
```

~~~
``` javascript
~~~

```
const syntaxHighlight = require("@11ty/eleventy-plugin-syntaxhighlight");
config.addPlugin(syntaxHighlight);
```

## Ajout de fonctionnalités à Mardown


Il est possible d'ajouter à la syntaxe Markdown d'autres commandes utiles comme l'ajout d'attibut css, la prise en charges des balises html de définition dt/dd l'insersertion de caractères émoji.

```>shell
$ npm install -save @gerhobbelt/markdown-it-attrs
$ npm install -save markdown-it-deflist
$ npm install -save markdown-it-emoji
```

``` javascript
const markdownItEmoji = require("markdown-it-emoji");
const markdownItDefinition = require("markdown-it-deflist");
const markdownItAttrs = require("@gerhobbelt/markdown-it-attrs");

let markdownLib = markdownIt()
  .use(markdownItAttrs)
  .use(markdownItDefinition)
  .use(markdownItEmoji);
```
`:)` devient :)

https://gist.github.com/rxaviers/7360908

## Diagramme

La réalisation des diagramme utilise le plugin [Mermaid] (https://mermaid-js.github.io/mermaid/#/)

Du fait de son conception intimment liée au navigateur c'est un plugin client, le diagramme ne sear pas compilé par le serveur par le navigateur du clien (`CSR`)

Il faut indiquer au plugin de coloration syntaxique de passer outre le langage mermaid.

```
config.addMarkdownHighlighter((str, language) => {
    if (language === "mermaid") {
      return `<pre class="mermaid">${str}</pre>`;
    }
    return highlighter(str, language);
  });
```

Ajouter dans le layout `page.njk` le script pour prendre en charge le format mermaid.

```
<script src="https://unpkg.com/mermaid/dist/mermaid.min.js"></script>
<script>mermaid.initialize({ startOnLoad: true });</script>
```

https://cornishweb.com/index.php/2019/05/25/using-mermaid-js-with-eleventy-io/

## Publication

Grâce à la gestion de projet git publier les sources du projet sur gitlab.

https://gitlab.com/LPAMIO/raspberry




https://lpamio-programmation-embarquee.netlify.app/
