---
title: "Configuration Raspberry Pi OS"
---

## Régler le fuseau horaire

```shell-session
timedatectl set-timezone Europe/Paris
```

## Activer la paramètres linguistiques pour la France

```shell-session
localectl set-locale LANG=fr_FR.UTF-8
```

Vérifier que la ligne `fr_FR.UTF-8 UTF-8` est bien active dans le fichier _`/etc/locale.gen`_

Générer les fichiers systèmes pour la nouvelle langue

```shell-session
locale-gen
```

Redémarrer et contrôller ensuite les paramètres

```shell-session
locale
```
