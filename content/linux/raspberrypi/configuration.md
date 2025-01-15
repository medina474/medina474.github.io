---
title: "Configuration Raspberry Pi OS"
---

## Régler le fuseau horaire sur Paris.

```shell
timedatectl set-timezone Europe/Paris
```

## Activer la paramètres linguistiques pour la France

```shell
localectl set-locale LANG=fr_FR.UTF-8
```

Vérifier que la ligne `fr_FR.UTF-8 UTF-8` est bien active dans le fichier _`/etc/locale.gen`_

Redémarrer et contrôller ensuite les paramètres

```shell
locale
```
