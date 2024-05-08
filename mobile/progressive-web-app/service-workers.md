---
title: "Service workers"
---

> **Définition** : Un service worker est un script JavaScript exécuté en arrière-plan par le navigateur web. 
{: .definition }

1. **Caching des ressources**: Le service worker peut être utilisé pour mettre en cache des ressources statiques telles que des fichiers CSS, JavaScript, images, etc. Cela permet une expérience utilisateur plus rapide et une utilisation **hors ligne** de l'application web.

2. **Gestion des requêtes réseau**: Il peut intercepter les requêtes réseau et les rediriger vers le cache, ou même vers un serveur différent. Cela peut être utilisé pour implémenter des **stratégies de mise en cache personnalisées**, des réponses hors ligne ou pour améliorer les performances en réduisant la dépendance au réseau.

3. **Notifications Push**: Les service workers peuvent être utilisés pour recevoir et afficher des notifications push, permettant aux utilisateurs d'être informés même lorsque la page n'est pas active.

4. **Synchronisation des données**: Les service workers peuvent être utilisés pour synchroniser des données en arrière-plan lorsque l'appareil est en ligne. Par exemple, sauvegarder des brouillons de messages lorsque la connexion Internet est instable et les envoyer une fois que la connexion est rétablie.

5. **Gestion des erreurs**: Ils peuvent être utilisés pour gérer les erreurs de réseau ou de serveur de manière transparente pour l'utilisateur, en affichant des pages d'erreur personnalisées ou en tentant de récupérer les données.

6. **Préchargement de ressources**: Les service workers peuvent précharger des ressources importantes pour améliorer les performances, comme les pages suivantes dans une application de navigation ou les images sur une page.

En résumé, les service workers offrent des fonctionnalités puissantes pour améliorer les performances, la fiabilité et l'expérience utilisateur des applications web, en particulier dans les scénarios où la **connectivité réseau est limitée ou instable**.


https://developers.google.com/web/fundamentals/primers/service-workers

## Stratégies de mise en cache

### Cache seulement

Idéal pour : tout ce que vous considérez comme statique par rapport à une "version" particulière de votre site. Vous devriez les avoir mis en cache dans l'événement d'installation, vous pouvez donc compter sur leur présence. … bien que vous n'ayez pas souvent besoin de gérer ce cas spécifiquement, le cache, en se rabattant sur le réseau, le couvre.

Si aucune correspondance n'est trouvée dans le cache, la réponse ressemblera à une erreur de connexion.

```javascript
self.addEventListener('fetch', function (event) {
  event.respondWith(caches.match(event.request));
});
```

### Réseau seulement

Idéal pour : les choses qui n'ont pas d'équivalent hors ligne, comme les pings analytiques, les requêtes non-GET. … bien que vous n'ayez pas souvent besoin de gérer ce cas spécifiquement, le cache, en se rabattant sur le réseau, le couvre.

```javascript
self.addEventListener('fetch', function (event) {
  event.respondWith(fetch(event.request));
});
```

### Cache d'abord

Si vous ne parvenez pas à servir quelque chose à partir du cache et/ou du réseau, vous souhaiterez peut-être fournir une solution de secours générique.

Idéal pour : les images secondaires telles que les avatars, les requêtes POST ayant échoué et un "Indisponible en mode hors connexion". page.

```javascript
self.addEventListener('fetch', function (event) {
  event.respondWith(
    // Try the cache
    caches
      .match(event.request)
      .then(function (response) {
        // Revenir au réseau
        return response || fetch(event.request);
      })
      .catch(function () {
        // Si les deux échouent, affichez une solution de secours générique :
        return caches.match('/offline.html');
        // However, in reality you'd have many different
        // fallbacks, depending on URL and headers.
        // Eg, a fallback silhouette image for avatars.
      }),
  );
});
```

L'élément auquel vous vous rabattez est probablement une dépendance d'installation.

Si votre page publie un e-mail, votre service worker peut se contenter de stocker l'e-mail dans une "boîte d'envoi" IndexedDB et répondre en informant la page que l'envoi a échoué mais que les données ont été conservées avec succès.


### Utilisation du cache en cas de défaillance réseau

Idéal pour : un correctif rapide pour les ressources qui se mettent à jour fréquemment, en dehors de la "version" du site. Par exemple. articles, avatars, chronologies des médias sociaux et tableaux de classement des jeux.

Cela signifie que vous donnez aux utilisateurs en ligne le contenu le plus à jour, mais les utilisateurs hors ligne obtiennent une ancienne version mise en cache. Si la requête réseau réussit, vous souhaiterez probablement mettre à jour l'entrée du cache.

Cependant, cette méthode a des défauts. Si l'utilisateur a une connexion intermittente ou lente, il devra attendre que le réseau tombe en panne avant d'obtenir le contenu parfaitement acceptable déjà sur son appareil. Cela peut prendre un temps extrêmement long et est une expérience utilisateur frustrante.

```javascript
self.addEventListener('fetch', function (event) {
  event.respondWith(
    fetch(event.request).catch(function () {
      return caches.match(event.request);
    }),
  );
});
```

Voir le modèle suivant, Cache puis réseau, pour une meilleure solution.

### Utilisation du cache puis mise à jour réseau

Idéal pour : du contenu qui se met à jour fréquemment. Par exemple. des articles, des chronologies sur les réseaux sociaux et des jeux. classements.

Cela nécessite que la page fasse deux requêtes, une au cache et une au réseau. L'idée est d'afficher d'abord les données mises en cache, puis de mettre à jour la page quand/si les données réseau arrivent.

Parfois, vous pouvez simplement remplacer les données actuelles lorsque de nouvelles données arrivent (par exemple, le classement du jeu), mais cela peut être perturbant avec des éléments de contenu plus volumineux. Fondamentalement, ne "disparaissez" pas quelque chose que l'utilisateur peut lire ou avec lequel il interagit.

Twitter ajoute le nouveau contenu au-dessus de l'ancien contenu et ajuste la position de défilement afin que l'utilisateur ne soit pas interrompu. Cela est possible car Twitter conserve principalement un ordre principalement linéaire du contenu. J'ai copié ce modèle pour l'entraînement au frisson afin d'afficher le contenu à l'écran le plus rapidement possible, tout en affichant un contenu à jour dès son arrivée.

```javascript
var networkDataReceived = false;

startSpinner();

// fetch fresh data
var networkUpdate = fetch('/data.json')
  .then(function (response) {
    return response.json();
  })
  .then(function (data) {
    networkDataReceived = true;
    updatePage(data);
  });

// fetch cached data
caches
  .match('/data.json')
  .then(function (response) {
    if (!response) throw Error('No data');
    return response.json();
  })
  .then(function (data) {
    // don't overwrite newer network data
    if (!networkDataReceived) {
      updatePage(data);
    }
  })
  .catch(function () {
    // we didn't get cached data, the network is our last hope:
    return networkUpdate;
  })
  .catch(showErrorMessage)
  .then(stopSpinner);
  ```

Code dans le Service Worker :

Vous devriez toujours aller sur le réseau et mettre à jour un cache au fur et à mesure.

Traduction : https://web.dev/offline-cookbook/

https://web.dev/service-worker-caching-and-http-caching/
