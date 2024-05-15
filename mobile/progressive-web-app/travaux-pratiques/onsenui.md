---
title: Onsen UI
---

Pour accélérer le développement nous allons utiliser le framework [OnsenUI](../onsenui/) qui permet d'utiliser des composants prédéfinis et obtenir un affichage semblable à ce que l'on trouve dans les applications natives.

## Single Page Application

Le point départ est donc tout naturellement **une** page **html**.

```html
<!DOCTYPE html>
<html lang="fr">
<head>
  <meta charset="UTF-8">
  <title>Cinéma</title>
</head>

<body>
</body>
</html>
```

L'application est responsive et s'affiche en pleine largeur sur tous les écrans.

```html
<meta name="viewport" content="width=device-width, initial-scale=1.0">
```

Ajouter dans l'entête html les liens vers la librairie OnsenUI (fichiers CSS et JavaScript).

Vous pouvez télécharger les librairies ou utiliser celle disponible sur les CDNs. Dans le cas d'un téléchargement local il faut aussi télécharger les packs d’icônes.

```html
<link rel="stylesheet" href="./onsenui@2.12.8/css/onsenui.css">
<link rel="stylesheet" href="./onsenui@2.12.8/css/onsen-css-components.min.css">
<script src="./onsenui@2.12.8/js/onsenui.min.js"></script>
```
### Définitions

CDN
: Content Delivery Network est un réseau de serveurs repartis autour du monde. Ils distribuent des fichiers statiques fréquemment demandés pour les pages Web à forte fréquentation. Les CDN accélerent le chargement des pages web. 
