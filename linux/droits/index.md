---
title: Droits
---

## Propriétaire

Changer le propriétaire d'un fichier ou d'un dossier (utilisateur root ou sudo) option -R pour la récursivité.

```
$ chmown utilisateur:groupe
```

chmod

Lette commande `chmmod` permet de modifier les permissions d’un fichier ou d’un dossier. Chaque fichier a trois types d’utilisateurs qui peuvent interagir avec lui :

- propriétaire	C’est l’utilisateur qui a créé et possède le dossier ou fichier.
- groupe	Tous les utilisateurs qui sont membres d’un même groupe.
- autres	Tous les autres utilisateurs, sur le système qui ne sont ni les propriétaires ni les membres du groupe.

Lire|Ecrire|Executer
:-:|:-:|:-:
4|2|1 
r|w|x

## ACL