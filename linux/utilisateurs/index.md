---
title: Utilisateurs
---

## Ajouter un utilisateur

```shell
useradd iutsd
```

`-s /usr/sbin/nologin` : le compte est désactivé.

### Modifier le mot de passe

```shell
passwd
```

Modifier le mot de passe d'un autre utilisateur depuis le compte root.

```shell
passwd iutsd
```

### Supprimer un utilisateur

```shell
userdel iutsd
```

### Afficher l'identité de l'utilisateur

```shell
id
```

## Groupes

Voir les groupes d'un utilisateur

```shell
groups user
```

### Ajouter un groupe secondaire à l'utilisateur

```shell
gpasswd -a user group
```

```shell
gpasswd -d user group
```

umask
