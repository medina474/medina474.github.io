---
title: Progressive Web App
date: 2022-05-03T15:18:26+01:00
draft: false
---

Une **PWA** (Progressive Web App) est une application qui utilise les standard et les technologie du web pour fonctionner.

Le point départ est donc tout naturellement une page **html**.

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

Installer ensuite l'extension pwabuilder pour VSCode et faire en sorte de satisfaire aux besoins d'une application PWA.

## Lighthouse

Lighthouse est un outil de Chrome qui teste une page ou un site suivant plusieurs critères et qui donne des conseils pour améliorer son code.
Il y a différents domaines d'analyse : l'accessibilité aux personnes mal voyantes, performance, optimisation pour les moteurs de recherche (seo) et aussi donc pwa.

## Service Worker

Un service worker est un bout de code javascript qui s’exécute en parallèle du site. Son action est limitée à l'arrière plan, il ne peut pas interagir directement avec l'utilisateur.
De part son exécution en thread parallèle et en arrière plan le service worker est utilisé pour le calcul intensif comme de la génération de pdf, de rendu 3D ou de décodage vidéo (lecteur qrcode).

Dans le cas d'une PWA le service worker est utilisé pour la gestion des communications réseaux. Une des conditions que doit satisfaire une PWA est de pouvoir s'exécuter dans tous les cas même sans accès au réseau.

Le service worker va observer tous les communications : chargement des pages, des feuilles de styles css, des images, d'appels API et va mettre mettre en cache ce qui le plus opportun. Le cache d'un service worker est un cache différent du cache par défaut du navigateur.

Voir les différentes stratégies de mise en cache avec un [service worker](../../webworker)
