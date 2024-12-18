---
title: Raspberry Pi OS
---

## Protéger l'accès

Voir le paragraphe [durcir la sécurité](../security/hardened).

## Effectuer une mise à jour du système.

> Sans être connecté à l'utilisateur root, il est nécessaire d'utiliser la précommande _sudo_ (_substitute user do ..._) à chaque ligne.
{:.info}

```shell
apt update
apt list --upgradable
apt upgrade -y
```
Il est possible de chainer plusieurs commande sur une seule ligne, en utilisant l'opérateur _&&_

```shell
apt update && apt upgrade -y
```
_`apt update`_ permet de mettre à jour les catalogues contenant la liste des différentes versions des paquets disponibles.

_`apt list --upgradable`_ permet de lister les paquets qui doivent être mise à jour.

_`apt upgrade`_ permet d'appliquer les mises à jour trouvées, le commutateur -y permet d'accepter automatiquement toutes les demandes.

## Configurations supplémentaires


Si besoin revoir les [commandes](../linux) d'un système Linux.

[Advanced IP Scanner]: /img/Advanced_IP_Scanner.png "Advanced IP Scanner"
[PuTTY]: /img/PuTTY.png "PuTTY"


headless
: Mode de fonctionnement _sans tête_, utilisation d'un appareil sans écran, ni clavier, ni souris branchés directement à lui.

ssh
: Secure Shell est un protocole de communication sécurisé. Il a été conçu pour remplacer les différents protocoles non chiffrés tel que rlogin et telnet. Le chiffrement de tous les paquets de communication rend ce protocole très sûr.
