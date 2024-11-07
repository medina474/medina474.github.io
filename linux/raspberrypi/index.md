---
title: "Installer Raspberry Pi OS"
---

> ***Objectif :***  Installer et utiliser un système d'exploitation pour Raspberry Pi.
{: .objectif}

**Raspberry Pi OS** (anciennement Raspbian) est le système d'exploitation officiel, c'est une version aménagée et optimisée de Debian GNU/Linux. La version desktop permet de travailler avec un bureau comme un ordinateur classique. Un clavier, une souris et un écran sont indispensables pour l'utiliser.

La version lite ne comporte pas de bureau graphique, il est nécessaire de se connecter à distance à la console pour pouvoir le contrôler.

Raspberry Pi OS est disponible en 64 bits pour Raspberry v4 et v3. Vis à vis de la quantité de mémoire du modèle 3, la version 64 bits est inutile, car elle consomme plus d'espace lors de l'adressage et ne permet pas d'accéder à plus de mémoire. Cependant de plus en plus de paquets logiciels sont fournis en mode 64 bits uniquement. Si on veut pouvoir utiliser les dernières versions de ces logiciels, il faut installer la version 64 bits.

Plusieurs autres systèmes pour des usages spécifiques sont disponibles : Ubuntu, OSMC (Media Center), Windows IoT Core (non compatible avec les dernières versions), PiNet, RiscOs, LibreElec (pour la domotique) etc.


## Copier Raspberry Pi OS (64-bit) Lite

La version Lite est une version allégée, sans interface graphique et sans bureau. Elle convient parfaitement à une utilisation en mode serveur.

Télécharger le fichier _raspios_lite_armhf-2022-04-07/2022-04-04-raspios-bullseye-armhf-lite.img.xz_ sur la [page officielle](https://www.raspberrypi.com/software/operating-systems/)

Transférer l'image sur une carte micro SD avec le logiciel [Rufus](https://github.com/pbatard/rufus/releases/download/v3.20/rufus-3.20p.exe).


### Activer l'accès à distance par ssh

> **headless** : mode de fonctionnement _sans tête_, utilisation d'un appareil sans écran, ni clavier, ni souris branchés directement à lui.
{:.definition}

Créer un fichier appelé simplement `ssh`, sans extension. Utiliser notepad, et enregistrer le fichier dans la partition boot de la carte.

Fichier vide, sa seule présence suffit à autoriser les connexions extérieures par ssh.


### Configurer le premier utilisateur

Dans les versions antérieures le premier utilisateur par défaut était `pi` et le mot de passe `raspberry`. C'est un gros problème de sécurité car de nombreux systèmes étaient accessibles avec le compte par défaut.

Le moyen le plus simple pour générer le mot de passe crypté consiste à utiliser OpenSSL sur un Raspberry Pi déjà en cours d'exécution.

Ouvrez une fenêtre de terminal et entrez

```shell
echo 'supermotdepasse' | openssl passwd -6 -stdin
```

Il est possible d'utiliser OpenSSL ou LibreSSL pour Windows. Cependant il faut être très prudent sur la version utilisée et les options de commande car dans ce cas le mot de passe ne sera pas correctement configuré et reconnu.

Créer un fichier userconfig.txt dans la partition boot de la carte. Écrir le nom du premier utilisateur et le mot de passe généré les deux séparé par deux points `:`.

L'exemple suivant défini un premier utilisateur nommé `iutsd` avec comme mot de passe `supermotdepasse`.

```
iutsd:$1$vHB3mzA8$BmwJzF3lUH.5ICIwF3Yuk1
```

Communiqué officiel du [7 avril 2022](https://www.raspberrypi.com/news/raspberry-pi-bullseye-update-april-2022/).


### Configurer le wifi

Ajouter un fichier `wpa_supplicant.conf` dans la partition boot.

```properties
ctrl_interface=DIR=/var/run/wpa_supplicant GROUP=netdev
update_config=1
country=FR
```
Les normes étant différentes suivant les pays, la Wifi ne peut fonctionner si ce fichier n'est pas renseigné


## Démarrer le Raspberry

Installer la carte dans le Raspberry, brancher le câble Ethernet et l'alimentation.


## Se connecter

Retrouver l'adresse ip de votre Raspberry avec le programme [Advanced IP Scanner](https://www.advanced-ip-scanner.com/download/Advanced_IP_Scanner_2.5.4594.1.exe).

![Advanced IP Scanner](Advanced_IP_Scanner.png)

Liste des [appareils](appareils).

Utiliser le programme **PuTTY** pour se connecter en SSH. Utiliser le compte et le mot de passe configuré à l'étape précédente.

![Putty](PuTTY.png)

Pour faire fonctionner le pavé numérique, aller dans le menu Terminal – Features puis cocher _Disable application keypad mode_

Vous pouvez aussi enregistrer le nom d'utilisateur dans Connection - Data.

Enregistrer la session (save sur le profil Default Setings) pour la retrouver ces réglages à la prochaine connexion.

## Définition

headless
: Système fonctionnant sans écran, clavier et souris

hid
: Human Interface Devices : Prériphériques pour que l'utilisateur puisse intéragir avec le système :clavier, souris, manette, afficheur ...

ssh
: Secure Shell : Protocole pour se connecter de manière sécurisé d'un ordinateur à un autre.
