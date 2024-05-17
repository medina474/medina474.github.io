---
title: NodeRed
---

## Installer NodeRed

Installer NodeRed à l'aide du script fourni par l'éditeur.

```>shell
bash <(curl -sL https://raw.githubusercontent.com/node-red/linux-installers/master/deb/update-nodejs-and-nodered)
```

https://nodered.org/docs/getting-started/raspberrypi


## Sécuriser l'accès

Éditer le fichier `/home/iutsd/.node-red/settings.js`

Générer le Hash du votre mot de passe

```>shell
node-red admin hash-pw
```

Recopier dans la partie permettant d'activer les utilisateurs.

```
adminAuth: {
  type: "credentials",
  users: [{
    username: "iutsd",
    password: "$2b$08$GY1LR9SgAkqxuE1ui1CaNuVuQYM.P30Bqnnt8riPDNpVtgBsboDty",
    permissions: "*"
  }]
}
```

https://nodered.org/docs/user-guide/runtime/securing-node-red

## Activer et démarrer le service nodered

Rendez vous avec un navigateur sur l'adresse IP de votre rasberry et en spécifiant le port de NodeRed le 1880


## Créer un premier service

La programmation avec NodeRed consiste à poser des brique (`node`) sur le diagramme (`flow`) et à les relier entre eux.

Les données échangées sont des objets JSON et doivent posséder la propriété `payload` (charge utile). Le payload peut être un nombre, une chaine de caractères, un tableau ou un objet complexe.

Certains nodes peuvent avoir plusieurs entrèes/sorties.

Ajouter les nodes `http in`, `http response` `function` et `debug`

![](webservice-1.png)





[https://nodered.org/](https://nodered.org/)
