---
title: SFTP
---

> ***SFTP*** est un protocole de communication fonctionnant au-dessus de `SSH` pour transférer et gérer des fichiers à distance.

:warning: Il ne faut pas confondre `sftp` avec `ftps`. Les 2 protocoles offrent les mêmes fonctionnalités de transfert de fichiers.  Cependant le `ftps` fonctionne sur la base du FTP en l'encapsulant dans une couche SSL/TLS alors que le sftp fonctionne au dessus de SSH.

[Éditer](/linux/nano) la configuration du serveur SSH  (`/etc/ssh/sshd_config`)

```properties
Subsystem sftp internal-sftp

Match Group sftp
  ChrootDirectory %h
  ForceCommand internal-sftp
  X11Forwarding no
  AllowTcpForwarding no
```

Redémarrer le serveur `ssh`

```shell
$ systemctl restart sshd
```

Les utilisateurs du groupe `sftp` pourront se connecter à l'aide de `sftp`. Ils seront isolés dans leur dossier `home` (`%h`) qui deviendra leur origine (`ChrootDirectory`) et leur seul horizon. On parle alors de `chroot jail`.

Créer le groupe `sftp`.

```shell
$ groupadd sftp
```

---

NON TP sur la différence entre
Ajouter l'utilisateur `pi` au groupe `sftp`.

```shell
$ gpasswd -a pi sftp
```
Vérifier les groupes auxquels appartient l'utilisateur `pi`.

```shell
$ groups pi
```

:warning: Le développement à distance par SSH ne sera plus possible !

Retirer l'utilisateur du group `sftp`.

```shell
$ gpasswd -d pi sftp
```

---

### Utilisateur spécifique

Nous allons utiliser un autre utilisateur `cinema`.

```shell
$ useradd -s /usr/sbin/nologin -g www-data cinema
```

```shell
$ mkdir /home/cinema/.ssh
$ touch /home/cinema/.ssh/authorized_keys
$ nano /home/cinema/.ssh/authorized_keys
# copier la clé publique
$ chown -R cinema:cinema /home/cinema/.ssh
$ chmod -R 500 /home/cinema/.ssh
$ chmod 400 /home/cinema/.ssh/authorized_keys
```

> Le jail ne fonctionnera que si l'utilisateur `root` contrôle le dossier `home` de l'utilisateur.
{: .warning}

```shell
$ chown root:cinema /home/cinema
$ chmod 750 /home/cinema
```

Créer un dossier qui contiendra les fichiers du site web

```shell
$ mkdir /home/cinema/public_html
$ chown cinema:www-data /home/cinema/public_html
```

Utiliser `WinSCP` pour vous connecter aux fichiers de l'utilisateur `cinema`.

```
sftp://{USERNAME}@iutsd-raspberry30-896.ad.univ-lorraine.fr
```

SFTP
: Secure File Transfer Protocol.

FTPS
: FTP Secure ou FTP over SSL.

Chroot jail
: L'utilisateur connecté en sftp ne peut pas sortir du dossier qui lui est attribué.
