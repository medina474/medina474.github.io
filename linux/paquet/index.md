---
title: Gestion des paquets logiciels
---

## Effectuer une mise à jour du système.

> Sans être connecté à l'utilisateur root, il est nécessaire d'utiliser la précommande _sudo_ (_substitute user do ..._) à chaque ligne.
{:.info}

```>shell
$ apt update
$ apt list --upgradable
$ apt upgrade -y
```
Il est possible de chainer plusieurs commande sur une seule ligne, en utilisant l'opérateur _&&_

```>shell
$ apt update && apt upgrade -y
```

_`apt update`_ permet de mettre à jour les catalogues contenant la liste des différentes versions des paquets disponibles.

_`apt list --upgradable`_ permet de lister les paquets qui doivent être mise à jour.

_`apt upgrade`_ permet d'appliquer les mises à jour trouvées, le commutateur _-y_ permet d'accepter automatiquement toutes les demandes.


```>shell
$ apt list --manual-installed
```

```>shell
$ apt search paquet
```


```>shell
$ apt install paquet
```

## Ajouter un dépôt d'un éditeur tiers.

Stocker les clés des dépôts des éditeurs tiers dans un dossier porte-clés

Créer un dossier `/usr/local/share/keyrings`

```>shell
$ wget -qO /usr/local/share/keyrings/mongodb-org-4_4.asc https://www.mongodb.org/static/pgp/server-4.4.asc
```>shell

Exemple de clé GPG

```
-----BEGIN PGP PUBLIC KEY BLOCK-----
Version: GnuPG v1

mQINBFzteqwBEADSirbLWsjgkQmdWr06jXPN8049MCqXQIZ2ovy9uJPyLkHgOCta
8dmX+8Fkk5yNOLScjB1HUGJxAWJG+AhldW1xQGeo6loDfTW1mlfetq/zpW7CKbUp
qve9eYYulneAy/81M/UoUZSzHqj6XY39wzJCH20H+Qx3WwcqXgSU7fSFXyJ4EBYs
kWybbrAra5v29LUTBd7OvvS+Swovdh4T31YijUOUUL/gJkBI9UneVyV7/8DdUoVJ
a8ym2pZ6ALy+GZrWBHcCKD/rQjEkXJnDglu+FSUI50SzaC9YX31TTzEMJijiPi6I
...
UgxkcI2y2FY/lPapcPPKe0FHzCxG2U/NRdM+sqrIfp9+s88Bj+Eub7OhW4dF3AlL
bh/BGHL9R8xAJRDLv8v7nsKkZWUnJaskeDFCKX3rjcTyTRWTG7EuMCmCn0Ou1hKc
R3ECvIq0pVfVh+qk0hu+A5Dvj6k3QDcTfse+KfSAJkYvRKiuRuq5KgYcX3YSzL6K
aZitMyu18XsQxKavpIGzaDhWyrVAig3XXF//zxowYVwuOikr5czgqizu87cqjpyn
S0vVG4Q3+LswH4xVTn3UWadY/9FkM167ecouu4g3op29VDi7hCKsMeFvFP6OOIls
G4vQ/QbzucK77Q==
=eD3N
-----END PGP PUBLIC KEY BLOCK-----
```
