---
title: Manifest Progressive Web App
---

Le fichier manifest fournit des informations sur l'application, telles que son nom, ses icônes, ses couleurs, etc., permettant ainsi à l'utilisateur de l'ajouter à l'écran d'accueil de son appareil.

Créer un fichier manifest.json à la racine de votre site

```json
{
  "name": "Ski Map",
  "short_name": "SkiMap",
  "icons": [{
    "src": "/images/icons/icon-128x128.png",
      "sizes": "128x128",
      "type": "image/png"
    },
    {
      "src": "/images/icons/icon-144x144.png",
      "sizes": "144x144",
      "type": "image/png"
    }],
  "start_url": "/index.html",
  "display": "standalone",
  "background_color": "#3E4EB8",
  "theme_color": "#2F3BA2"
}
```

Ajouter le lien vers le manifest dans votre page

```html
<link rel="manifest" href="/manifest.json">
```

Ajouter les icones de l'application

Ouvrir les outils de développement de Chrome dans l'onglet Audit et faire en sorte que l'application soit 100% compatible Progressive Web App.

Suivre les recommandations et conseils de l'outil Ligthhouse.
