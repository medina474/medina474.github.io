---
title: Communication réseau
---

Télécharger DataDog Vector depuis Arche

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
      codec: "json"
      json:
        pretty: true
```
