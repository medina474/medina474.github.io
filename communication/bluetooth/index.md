---
title: Bluetooth
---

## GAP

GAP est un acronyme pour Generic Access Profile, , et il contrôle les connexions et la publicité dans Bluetooth. GAP est ce qui rend votre appareil visible au monde extérieur et détermine comment deux appareils peuvent (ou ne peuvent pas) interagir l'un avec l'autre.

GAP définit divers rôles pour les appareils, mais les deux concepts clés à garder à l'esprit sont les **appareils centraux** et les **appareils périphériques**.

Les périphériques sont de petits périphériques à faible consommation d'énergie et contenant des ressources qui peuvent se connecter à un périphérique central beaucoup plus puissant. Les périphériques sont des choses comme un moniteur de fréquence cardiaque, une balise de proximité compatible BLE, etc.

Les appareils centraux sont généralement le téléphone mobile ou la tablette auxquels vous vous connectez avec beaucoup plus de puissance de traitement et de mémoire.

Publicité et données de réponse à l'analyse: il existe deux façons d'envoyer de la publicité avec GAP. La charge utile des données publicitaires et la charge utile Scan Response. Les deux charges utiles sont identiques et peuvent contenir jusqu'à 31 octets de données, mais seule la charge utile des données publicitaires est obligatoire car il s'agit de la charge utile qui sera constamment transmise depuis l'appareil pour informer les appareils centraux à portée de son existence. La charge utile de réponse d'analyse est une charge utile secondaire facultative que les périphériques centraux peuvent demander et permet aux concepteurs de périphériques d'ajuster un peu plus d'informations dans la charge utile publicitaire, telle qu'une chaîne pour un nom de périphérique, etc.

https://www.cardinalpeak.com/blog/what-is-ble-and-how-do-its-related-gap-and-gatt-profiles-work
https://learn.adafruit.com/introduction-to-bluetooth-low-energy/gap

## GATT

Un profil n'existe pas réellement sur le périphérique BLE lui-même, il s'agit simplement d'une **collection prédéfinie** de services qui a été compilée par le Bluetooth SIG ou par les concepteurs de périphériques. Le profil de fréquence cardiaque, par exemple, combine le service de fréquence cardiaque et le service d'informations sur l'appareil.


### Prestations de service

Les services sont utilisés pour diviser les données en entités logiques et contiennent des morceaux de données spécifiques appelés caractéristiques. Un service peut avoir une ou plusieurs caractéristiques, et chaque service se distingue des autres services au moyen d'un identifiant numérique unique appelé UUID, qui peut être soit 16 bits (pour les services BLE officiellement adoptés) soit 128 bits (pour les services personnalisés ).

Une liste complète des services BLE officiellement adoptés est disponible sur la page Services du Portail des développeurs Bluetooth. Si vous regardez le service de fréquence cardiaque, par exemple, nous pouvons voir que ce service officiellement adopté a un UUID 16 bits de 0x180D et contient jusqu'à 3 caractéristiques, bien que seule la première soit obligatoire : mesure de la fréquence cardiaque, capteur corporel Emplacement et point de contrôle de la fréquence cardiaque.

### Caractéristiques

Le concept de niveau le plus bas dans les transactions GATT est la caractéristique, qui encapsule un seul point de données (bien qu'il puisse contenir un tableau de données connexes, telles que les valeurs X/Y/Z d'un accéléromètre à 3 axes, etc.).

À l'instar des services, chaque caractéristique se distingue par un UUID prédéfini de 16 ou 128 bits, et vous êtes libre d'utiliser les caractéristiques standard définies par le Bluetooth SIG (qui garantit l'interopérabilité entre les HW/SW compatibles BLE) ou définissez vos propres caractéristiques personnalisées que seuls votre périphérique et le logiciel comprennent.

Par exemple, la caractéristique de mesure de la fréquence cardiaque est obligatoire pour le service de fréquence cardiaque et utilise un UUID de 0x2A37. Il commence par une seule valeur de 8 bits décrivant le format de données HRM (que les données soient UINT8 ou UINT16, etc.), et continue en incluant les données de mesure de la fréquence cardiaque qui correspondent à cet octet de configuration.

Les caractéristiques sont le point principal sur lequel vous interagirez avec votre périphérique BLE, il est donc important de comprendre le concept. Ils sont également utilisés pour renvoyer des données au périphérique BLE, car vous pouvez également écrire dans la caractéristique. Vous pouvez implémenter une interface de type UART simple avec un « service UART » personnalisé et deux caractéristiques, une pour le canal TX et une pour le canal RX, où une caractéristique pourrait être configurée en lecture seule et l'autre aurait des privilèges d'écriture.

https://www.kernel.org/pub/linux/bluetooth/

## Étape 1 Intaller  *BlueZ 5.9* sur Raspberry

BlueZ la pile de contrôle du bluetooth pour Linux.

a. Télécharger et décompresser les sources du projets

```>shell
wget https://www.kernel.org/pub/linux/bluetooth/bluez-X.XX.tar.xz
tar xvf bluez-X.XX.tar.xz
```

b. corriger les 2 fichiers sources `tools/l2test.c` et `tools/rctest.c`. Ajouter dans les entêtes la ligne suivante

```C
#include <linux/sockios.h>
```

c. Installer les librairies nécessaires lors de la compilation

```>shell
apt-get install -y libusb-dev libdbus-1-dev libglib2.0-dev libudev-dev libical-dev libreadline-dev
```

https://www.instructables.com/Control-Bluetooth-LE-Devices-From-A-Raspberry-Pi/
https://www.argenox.com/library/bluetooth-low-energy/using-raspberry-pi-ble/


d. Compiler

```>shell
cd bluez-5.9

export LDFLAGS=-lrt
./configure --prefix=/usr --sysconfdir=/etc --localstatedir=/var --enable-library -disable-systemd

make
make install
```

e. Tester

```>shell
btmon -v

hcitool -i hci0 lescan
```

Arrêter et démarrer le bluetooth

```>shell
hciconfig hci0 down
hciconfig hci0 up
```

http://tvaira.free.fr/bts-sn/activites/activite-ble/activite-ble-esp32.html
https://circuitdigest.com/microcontroller-projects/ble-based-proximity-control-using-esp32

## Étape 2

Sur un ESP 32 prévoir un dispositif de lecture de la température et de l'humidité

## Étape 3

Installer sur votre téléphone l'application nRF

## Étape 4

Publier à l'aide d'un serveur Bluetooth et d'un profile Environmental Sensing les valeurs de température et d'humidité du capteur
https://www.hackster.io/ManniAT/esp32-ble-environmental-gatt-server-14cceb

## Étape 5

Lire depuis le téléphone avec l'application nRF les valeurs renvoyées par l'ESP 32

## Étape 6

Sur Rapsberry écrire un programme NodeJS à l'aide de la librairie @abandonware/noble

Le programme NodeJs scan les périphériques Bluetooth indiquant un service Environmental Sensing, se connecte et lit les valeurs

Comme il ya beaucoup d'appareils Bluetoth dans la salle il convient de filter suivant le nom de machine

```javascript
console.log(`${peripheral.address} ${peripheral.advertisement.localName} ${peripheral.rssi}`);

if (peripheral.advertisement.localName=="AMIO21") {
  await noble.stopScanningAsync();
  await peripheral.connectAsync();
} ;
```

# Séance 2

## Étape 7

Exposer ces valeurs via un web service Rest avec Express

## Étape 8

Exposer ces valeurs via un web service temps réel avec Socket.io

https://socket.io/

## Étape 9

Retour de l'utilisateur vers le Rasberry

Ajouter une LED sur le breadboard

https://www.w3schools.com/nodejs/nodejs_raspberrypi_webserver_websocket.asp


# Beacon

Le beacon émet un signal à intervalles réguliers. Lorsqu’un appareil se situe dans la zone de diffusion, il réceptionne l’émission et la manifeste sous forme d’une action précise pour le destinataire. Les applications sont multiples. Elles peuvent s’intégrer dans un cadre professionnel ou ouvert au public.

A l'aide de flutter faire de votre téléphone une balise Beacon

https://medium.com/flutter-community/how-to-turn-your-phone-into-a-beacon-with-flutter-47619bfa9963

Implementer le profile Beacon sur l'ESP 32

Sur le raspberry écrire un programme NodeJS qui scanne les Beacon à proximité


GAP
: Generic Access Profile
