---
title: Utilisateurs
---

## Ajouter un utilisateur

```shell-session
useradd iutsd
```

`--disabled-password` : le compte n'a pas de mot de passe. Il n'est pas possible de se connecter sauf en utilisant un système de clés.

`--disabled-login` : le compte est désactivé.

### Modifier le mot de passe 

```shell-session
passwd 
```

Modifier le mot de passe d'un autre utilisateur depuis le compte root.

```shell-session
passwd iutsd
```

### Supprimer un utilisateur

```shell-session
userdel iutsd
```

### Afficher l'identité de l'utilisateur

```shell-session
id
```

## Groupes

### Ajouter un groupe secondaire à l'utilisateur

```shell-session
gpasswd -a user group
```

```
gpasswd -d user group
```

umask

