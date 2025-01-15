---
title: Accès à distance avec SSH
---

```shell
$ apt install --no-install-recommends openssh-server
```

Copier / coller la clé root dans le fichier /root/.ssh/authorized_keys

```shell
$ nano .ssh/authorized_keys
```

```config
PasswordAuthentication no
```
