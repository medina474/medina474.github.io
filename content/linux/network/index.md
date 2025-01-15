---
title: Réseaux
---

### Afficher l'adresse IP de la machine

```shell
$ hostname -I
```

### Modifier le nom d'hôte de la machine

```shell
$ hostnamectl set-hostname iutsd-raspberry30-896.ad.univ-lorraine.fr
```

Ajouter le nom d'hôte dans le fichier hosts

[Éditer](/linux/nano) nano /etc/hosts

```
127.0.0.1    iutsd-raspberry30-896.ad.univ-lorraine.fr
```

Affiche le nom d'hôte de la machine

```shell
$ hostnamectl
```


```shell
$ ifconfig
```

Installer le [paquet logiciel](/linux/paquet/) `dnsutils`.

```shell
dig @127.0.0.1 www.univ-lorraine.fr
```

### Programmes à l'écoute

```shell
$ netstat -tulpn | grep LISTEN
```
### Afficher les réseaux wifi à proximité

```
wpa_cli -i wlan0
> scan
> scan_results
> quit
```

## Réseau de l'Université de Lorraine

Pour le personnel uniquement.

### Se connecter au Wifi de l'Université de Lorraine

```
WPAP2-PEAP with CCMP/MSCHAPV2 (without domain)
identifiant : xxx5@univ-lorraine.fr
```

### Se connecter au VPN de l'Université de Lorraine

Installer le [paquet logiciel](/linux/paquet/) `openconnect`.

```
openconnect -u xxx5@iutsd-enseignant --authgroup='Universite-de-Lorraine' vpn.lothaire.net
```


To determine whether a given executable daemon/path/to/daemon supports TCP Wrappers, type:

 $ ldd /path/to/daemon | grep libwrap.so
