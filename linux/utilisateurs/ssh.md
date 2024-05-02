---
title: SSH
---

### Authentification par clé.

Vous déposer sur le serveur votre clé publique. Cette clé peut être utilisée par une multitude de serveurs. Elle est publique et n'a pas d'importance toute seule.

Votre clé privée est chiffrée et stockée sur votre machine (dans KeePass). Elle doit rester absolument secrète.

Lorsque vous voulez vous connecter au serveur, vous commencez par déchiffrer votre clé privée pour pouvoir l'utiliser. Vous utiliser le mot de passe qui chiffre la clé privée.

> Le mot de passe du compte n'a rien à voir avec le mot de passe qui chiffre la clé privée.

Il est même conseillé de désactiver le mot de passe du compte et de n'authoriser que la connexion avec les clés publiques/privées.

Vous chiffrez un message sans importance, comme la date et l'heure courante.

Vous transmettez ce message au serveur. Si le serveur arrive à déchiffrer ce message alors c'est que c'est bien vous le possesseur de la clé privée qui essayez de vous connecter.

#### Attaque par rejeu ou Replay attack

En utilisant la date et l'heure vous empêcher quelqu'un de réutiliser votre message pour se connecter en effet le serveur voyant que le message est daté ne permettra pas la connexion.

Le serveur peut aussi vous envoyez un nombre aléatoire valide quelques minutes seulement (token de session), si vous renvoyez ce même identifiant chiffré alors vous êtes la bonne personne.

#### Agent

Un agent est un petit programme qui garde votre clé privée en mémoire pendant toute la durée d'une session. Cela évite de devoir renseigner la mot de passe de déchiffrement chaque fois que la clé doit être utilisée. Il existe plusieurs programe comme `ssh-agent`, `pageant` ou `KeeAgent`.

## Travaux pratiques

Créer une nouvelle entrée dans KeePass pour l'utilisateur `root`.

Ajouter le plugin [KeeAgent](https://lechnology.com/software/keeagent/#download) qui permet d'agir comme un agent SSH aux programmes qui le demandes.

Un agent SSH, délivre la clé privée chaque fois qu'un programme en a besoin. Cela évite de devoir fournir le mot de passe de la clé à chaque utilisation.

Ajouter la clé privée `.ppk` issue de PuTTYGen dans la zone des fichiers. Supprimer ensuite le fichier de vore disque il n'a plus rien à y faire.

![][Attachment]

[x] Autoriser KeeAgent à utiliser la clé et charger la clé au démarrage.

Vous pouvez charger la clé à la demande avec la combinaison de touches `Ctrl M` et régler la durée pendant la clé est disponible par l'agent.

Vous pouvez vérifier les clés chargées par l'agent. Menu - Tools - KeeAgent

> Attention : il ne faut pas charger trop de clés en même temps. Lors de la connexion à un serveur les clés sont testées une par une jusqu'à trouver la bonne. Le serveur risque de bloquer la connexion si trop de tentatives infructueuses sont effectuées.
{.warning}

![][KeeAgent]

Ajouter l'adresse _ssh://iutsd-raspberry30-896.ad.univ-lorraine.fr_ dans la zone URL. Double cliquer sur l'URL dans la liste pour vous connecter.


### Agent pour OpenSSH

Créer une nouvelle paire de clé. Ajouter la clé publique dans votre compte GitLab ou GitHub. Ajouter cette même clé publique dans le fichier authorized_keys du compte pi du Raspberry.


Cocher `Enable agent for Windows OpenSSH`

Ouvrir un terminal Windows et tester l'utilisation de la clé

```shell-session
$ ssh -V
$ ssh -T git@gitlab.com
```

Si Git ne fonctionne pas dans Visual Studio Code, renommer le fichier `C:\Program Files\Git\usr\bin\ssh.exe`. alors avec la version SSH de Windows.

### Utiliser l'agent avec Git Bash

Cocher `Create Cygwin compatible socket file` et choisir un fichier comme `%USERPROFILE%\.ssh\keeagent.sock`

Lancer `Git Bash`, éditer le fichier `.bash_profile`

```
nano ~/.bash_profile
```

Ajouter la ligne
```
export SSH_AUTH_SOCK="C:/USERS/<VOTRE COMPTE>/.ssh/keeagent.sock"
```

Relancer KeePass ainsi que Git Bash et tester l'utilisation de la clé

```shell-session
$ ssh -V
$ ssh -T git@gitlab.com
```

https://code.mendhak.com/keepass-and-keeagent-setup/

[Attachment]: attachment.png "Attacher la clé privée"
[KeeAgent]: keeagent.png "Configurer l'utilisation de la clé privée"
