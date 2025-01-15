---
title: Communication réseau
---

Télécharger DataDog Vector depuis [le site de Datadog](https://vector.dev/docs/setup/installation/package-managers/msi/)

Ecrire le fichier de configuration permettant de lancer un serveur web et d'écouter sur le protocole http

```yaml
  web:
    type: "http_server"
    address: "0.0.0.0:8099"
    encoding: "json"
```

envoyer l'entrée vers la console

```yaml
sinks:
  print:
    type: "console"
    inputs: ["web"]
    encoding:
      codec: text
```

Utiliser Visual Studio Code et REST Client pour tester le fonctionnement.

### Programme C

Écrire un programme C qui permet d'envoyer des messages en http.

Utiliser la commiunication par ***socket***

Créer tout d'abord une variable de type ***sockaddr_in*** pour contenir l'adresse de vore serveur.

Si le programme s'execute sur la même machine il faut utiliser l'adresse loopback 127.0.0.1

déclarer une chaine de caractère et envoyer là à l'aide la fonction ***send***

Attendre et lire la réponse à l'aide de la fonction ***recv***
