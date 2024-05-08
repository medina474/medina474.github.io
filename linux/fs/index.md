---
title: Dossiers et fichiers
---

Les fichier dans un système Linux n'ont pas forcement d'extension. Pour différencier un fichier `cinema` d'un dossier `cinema`, il convient d'ajouter au dossier une barre oblique `cinema/`.

## Commande `ls` (list)

Lister les fichiers et dossiers.

```shell-session
$ ls
```

### Options

Lister tous les fichiers et dossiers, même ceux cachés. 

> Les fichiers et dossiers cachés sont ceux dont le nom commence par un point `.`.\
{.info}

`.cinema\` est un dossier caché.

```shell-session
$ ls -a
```

Afficher le détail des fichiers sous forme de liste.

```shell-session
$ ls -l
```

Afficher le détail de tous les fichiers (y compris les fichiers cachés) sous forme de liste.

```shell-session
$ ls -la
```

## Commande `mkdir` (make directory).

Créer un dossier.

```shell-session
$ mkdir cinema
```

## Commande `rmdir` (remove directory).

Supprimer le dossier à condition que celui ci soit vide.

```shell-session
$ rmdir cinema
```

## Commande rm (remove)

Supprimer un fichier

```shell-session
$ rm index.js
```
Commande `rm --recursive` (remove).

Supprimer tous les fichier et sous dossier, ainsi que le dossier `cinema`. 

```shell-session
$ rm -r cinema/
```

>Attention en ligne de commande il n'y a pas de corbeille pour récupérer des fichiers accidentellement supprimés.
{: .warning}


## Commande `mv` (move).

Déplacer le fichier `main.css` dans le dossier `styles`.

```shell-session
$ mv main.css styles/
```

Le renommage d'un fichier est équivalent à déplacer ce fichier dans le même dossier avec un nom différent.

Renommer le fichier `index.js` en `server.js`

```shell-session
$ mv index.js server.js
```

## Commande `cp` (copy)

Duplique un fichier

```shell-session
$ cp index.js server.js
```

Copie un fichier dans un dossier

```shell-session
$ cp main.css styles/
```

## Analyser l'occupation de la carte mémoire.

```shell-session
$ ncdu
```

## Définitions

fs
: File System, Système de fichiers
