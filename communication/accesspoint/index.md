---
title: Access Point
---

## 1. Modifier le fonctionnement du client DHCP.

Le service DHCP client permet au système de demander pour chaque interface réseau (ethernet et wifi) une adresse IP au fournisseur d'adresses du réseau. Dans la plupart des cas le routeur, la box Internet ou la borne wifi.

Dans notre cas nous allons créer avec le Raspberry notre propre réseau autonome. Il ne doit pas demander d'adresse mais au contraire les distribuer aux appareils qui vont se connecter à lui. Il faut désactiver la demande d'adresse et définir manuellement une IP statique.

Nous allons utiliser les adresses IP standard privées 192.168.0.x pour notre réseau sans fil. Attribuer au serveur l'adresse IP 192.168.0.1. Le périphérique sans fil est nommé _wlan0_.

Il faut aussi désactiver la demande de connexion automatique au réseau  wifi par le biais du fichier _wpa_supplicant_

[Éditer](/linux/nano)  /etc/dhcpcd.conf

Ajouter à la fin du fichier

```apacheconf
interface wlan0
static ip_address=192.168.0.1/24
nohook wpa_supplicant
```

Redémarrer le service dhcp client

```shell-session
systemctl restart dhcpcd
```

## 2. Installer un serveur DHCP et DNS

> ***Dynamic Host Configuration Protocol (DHCP)*** est un protocole réseau dont le rôle est d’assurer la configuration automatique des paramètres IP d'une machine, notamment en lui attribuant automatiquement une adresse IP et un masque de sous-réseau. DHCP peut aussi configurer l’adresse de la passerelle par défaut et les serveurs de noms DNS.
{:.definition}

> ***Domain Name System (DNS)*** est un service informatique distribué utilisé pour traduire les noms de domaine Internet en adresse IP. Le DNS est un composant essentiel du réseau internet.
{:.definition}

Par exemple :
iutsd.univ-lorraine.fr est un nom de domaine pleinement qualifié (FQDN) il pointe vers une machine dont l'adresse IP est 193.50.135.38.
Cette relation est définie par les serveurs de noms maîtres orion.ciril.fr et arcturus.ciril.fr. Cette association est ensuite répliquée par les autres serveurs DNS lorsqu'un client en fait la demande.

Notre système va fournir aux appareils connectés une résolutions des noms de domaines en IP en interrogeant les différents serveurs maître.

**dnsmasq** est un paquet qui fournit plusieurs services dont le DNS et le DHCP.

Installer le [paquet logiciel](/linux/paquet/) `dnsmasq`.

Arrêter le service, car il n'est pas encore correctement configuré

```shell-session
$ systemctl stop dnsmasq
```

### Configurer le service dhcp serveur

[Éditer](/linux/nano) /etc/dnsmasq.conf

Trouver dans le fichier et activer les options suivantes

```apacheconf
domain-needed
bogus-priv
interface=wlan0
dhcp-range=192.168.0.50,192.168.0.150,255.255.255.0,12h
```

Tester la configuration

```shell-session
dnsmasq --test
```

Pour l'interface Wifi (wlan0), nous allons fournir des adresses IP entre 192.168.0.50 et 192.168.0.150, avec une durée de location de 12 heures.

Nous pouvons maintenant [démarrer](/linux/services) le service `dnsmasq`.

## 3. Hotspot

hostapd est un logiciel qui permet à une interface réseau d'agir comme un point d'accès (hospot / access point).

[Installer](/linux/paquet) le paquet `hostapd` et [éditer](/linux/nano) le fichier de configuration `/etc/hostapd/hostapd.conf`.

```apacheconf
interface=wlan0
hw_mode=g                   # Norme a/b/g
channel=1                   # Canal de fréquences, de 1 à 13
wmm_enabled=0
macaddr_acl=0
auth_algs=1
ignore_broadcast_ssid=0
wpa=2
wpa_key_mgmt=WPA-PSK        # Méthode de cryptage pour sécuriser la communication
wpa_pairwise=TKIP
rsn_pairwise=CCMP
ssid=RASPBERRY21            # Mettre un nom de réseau personnalisé
wpa_passphrase=supermotdepasse
```

Attention pas de commentaire dans le fichier

:warning: Attention : Vous devez utiliser un nom de SSID différent pour ne pas créer d'interférences avec les raspberry de vos camarades. Changer aussi le n° de canal (channel). Il y a en 13 au total pour la norme g.

a = IEEE 802.11a (5 GHz)\
b = IEEE 802.11b (2.4 GHz)\
g = IEEE 802.11g (2.4 GHz)

Vous pouvez tenter le mode a. Les canaux sont des nombres pairs entre 32 et 48



Il faut maintenant dire au système d'utiliser ce fichier de configuration. [Éditer](/linux/nano) le fichier `/etc/default/hostapd`


Décommenter et compléter la ligne

```shell-session
DAEMON_CONF="/etc/hostapd/hostapd.conf"
```

[Activer et démarrer](/linux/services) le service `hostapd`.


Ajouter l'application [Wifi Analyser](https://play.google.com/store/apps/details?id=com.farproc.wifi.analyzer&hl=fr&gl=US) sur votre téléphone pour vérifier la présence d'un nouveau réseau Wifi.

Connecter vous sur le réseau wifi du raspberry avec votre téléphone.
Vous pouvez accéder aux services du Raspberry mais pas naviguer sur Internet. Pour cela il faut que vos requêtes soient redirigées vers l'extérieur par l'intermédiaire d'un pont entre la wifi et l'interface filaire ethernet.

## 4. Routage

Il est nécessaire que les requêtes arrivant par la Wifi soient redirigées vers le port Ethernet. C'est un liende routage entre l'interface Wifi et l'interface ethernet (eth0).

[Éditer](/linux/nano) /etc/sysctl.conf

```apacheconf
net.ipv4.ip_forward=1
```
Créer les règles dans la table de routage

Installer le paquet iptables

```shell-session
iptables -t nat -A POSTROUTING -o eth0 -j MASQUERADE
iptables-save > /etc/iptables.ipv4.rules
```

[Éditer](/linux/nano) le fichier `/etc/rc.local`

```apacheconf
iptables-restore < /etc/iptables.ipv4.rules
exit 0
```

Redémarrer votre appareil.

```mermaid
graph LR
    Téléphone-- Wifi ---Raspberry-- Ethernet ---Internet
```

SSID
: Service Set Identifier

DNS
: Domain Name System

DHCP
: Dynamic Host Configuration Protocol

## Liens externes
https://www.maketecheasier.com/turn-raspberry-pi-into-wi-fi-bridge/
https://willhaley.com/blog/raspberry-pi-wifi-ethernet-bridge/
https://www.linuxtricks.fr/wiki/dnsmasq-le-serveur-dns-et-dhcp-facile-sous-linux
https://www.techrepublic.com/article/how-to-speed-up-dns-caching-on-your-linux-machines-with-dnsmasq/
