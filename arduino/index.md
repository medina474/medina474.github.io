---
title: Arduino
---

L’Arduino est une carte basée sur un microcontrôleur du fabriquant Atmel : ATMEGA168 ou ATMEGA328.

Elle dispose dans sa version de base de 2Ko de mémoire vive, et 32Ko de mémoire flash pour stocker ses programmes. Elle peut être connectée à 13
entrées ou sorties numériques, dont 3 PWM pouvant donner 3 sorties analogiques et 6 entrées analogiques convertissant en 10 bit.

Dans la version la plus courante, la communication avec l’ordinateur se fait par un port USB. Il existe plusieurs versions de l’Arduino, dont une version
miniaturisée.

## Environnement logiciel

La carte dispose d’un logiciel système interne (appelé bootloader) qui permet la récupération du programme via la liaison USB et de son implantation en mémoire.

Pour programmer un Arduino il existe plusieurs solutions. Le plus connu et le plus utilisé et celui disponible sur le [site officiel](https://www.arduino.cc/en/software). Il est est un peu daté et concurencé par d'autres outils comme Visual Studio Code avec l'extension PlatformIO. Pour répondre à cette concurence une nouvelle version est en préparation et sera très prochainement disponible.

> **PWM** : Pulse Width Modulation. La modulation de largeur d'impulsions est une technique couramment utilisée pour synthétiser des signaux pseudo analogiques à l'aide de circuits numériques (1 ou 0).
{.definition}


> **Bootloader** : Le chargeur d'amorçage permet de charger un programme dans la mémoire FLASH du microcontrôleur à partir de la ligne série et d'exécuter celui-ci.
{.definition}

### Caractéristiques techniques

Toutes les cartes Arduino sont équipées de micro-controleur ATMEGA de Atmel
- ATmega 328p pour les carte UNO, Nano...
- ATmega 2560 pour la carte Mega …
- Autre µC : ATmega 32u4, AT91SAM3XE8…
- Frequence d'horloge de 16Mhz à 84Mhz
- Nombre d'entrées sorties de 14 à 54
- Entrées analogique : 6 à 16
- Sortie PWM de : 6 à 16
- Mémoire vive Flash de 32Ko à 512Ko pour le programme
- Mémoire vive SRAM de 2Ko à 96Ko, mémoire statique rapide pour variables
- Mémoire morte EEPROM de 1Ko à 16Ko


## La carte MEGA 2560

![](mega.jpg)

Alimentation - via port USB ou 7 à 12 V sur connecteur alim
Caractéristiques             | Arduino UNO R3 | Mega 2560
---|---|---
Microcontrôleur              | ATmega328P | ATmega2560
Horloge                      | 16 MHz     | 16 MHz
Tension d'entrée recommandée | 7-12V | 7-12V
Tension de fonctionnement    | 5V  | 5V
Entrée/Sorties                 | 14     | 54/15
Entrée/Sorties analogiques PWM | 6      | 16 (10 bits)
Intensité par E/S              | 20 mA  | 40 mA
Port série UART                |1       | 4 
Bus || Bus I2C et SPI
USB |USB B| USB B
Wifi |Non | Non
Dimensions | 68 x 53 x 15 mm | 107 x 53 x 15 mm

## Mémoire

![](arduino-memory-map.png)

STARTUP : code de démarrage\
CODE : code de l'application, y compris celui des librairies\
LOAD_DATA : les valeurs des variables globales et statiques initialisées\
REGISTERS : registres du microcontrôleur (GPIOs, TIMERS, etc.)\
DATA : variables globales et statiques initialisées\
BSS : variables globales et statiques non initialisées\
STACK : la pile\

### Stack (Pile)

Lors de l'exécution du programme, la pile est utilisée pour empiler les adresses de retour des fonctions, ainsi que les variables locales
.
La pile est gérée grâce à un registre spécial : le pointeur de pile.

Lorsque l'on appelle une fonction l'adresse de retour est placée sur la pile et le pointeur de pile est décrémenté de 2 octets (la taille d'une adresse ATMEGA).

Si la fonction appelée déclare une variable locale le pointeur de pile est décrémenté de la taille de la variable. Dans certains cas, le compilateur utilisera un registre, plus rapide.

Si cette fonction appelle une autre fonction, le pointeur de pile est encore décrémenté, de la même manière.

Si la valeur du pointeur de pile descend trop bas il y a un risque d'aller corrompre les adresses haute de la zone des variables globales. Si le programme utilise des objets String ou l'allocation dynamique, les adresses hautes du tas seront corrompues.

### Heap (tas)

Entre la pile (Stack) et la zone BSS se trouve la mémoire libre.

Cette zone s'appelle le tas (heap). Si le programme comporte un grand nombre de variables globales la taille du tas sera réduite d'autant.

L'allocation dynamique de mémoire revient donc à réserver un bloc mémoire de la taille demandée dans cette zone appelée tas. Le **demandeur est responsable** de la libération de ce boc quand il sera devenu inutile.

#### fragmentation

fragmentation = 1 - plus grand block / mémoire totale 

````C
float getFragmentation() {
  return 100 - getLargestAvailableBlock() * 100.0 / getTotalAvailableMemory();
}
```


We saw how fragmentation increases, now let’s talk about the consequences of a high fragmentation level.

Consequence 1: Unreliable program
By definition, a high fragmentation level means you have a lot of free memory, but you can only allocate small blocks. If your program needs a bigger block, it will not get it and will stop working.

Consequence 2: Degraded performance
A highly fragmented heap is slower because the memory allocator takes more time to find the best hole, the so-called “best-fit.”


https://cpp4arduino.com/2018/11/06/what-is-heap-fragmentation.html

https://wiki.mchobby.be/index.php?title=Arduino_Memoire


## Tableaux

https://openclassrooms.com/fr/courses/19980-apprenez-a-programmer-en-c/7672506-creez-des-variables-de-type-tableaux

https://zestedesavoir.com/tutoriels/755/le-langage-c-1/1043_aggregats-memoire-et-fichiers/4281_les-tableaux/

2 dimensions

dynamiques

échelles


## Principales Instructions

### Gestion du temps

**millis(ms)** : retourne le temps écoulé depuis le dernier reset en millisecondes. (repasse à 0 après 50 jours environs)

**micro(µs)** : retourne le temps écoulé depuis le dernier reset en microsecondes. (repasse à 0 après 70 minutes environs)

**delay(ms)** : provoque une pause de ms millisecondes

**delayMicroseconds(µs)** : provoque une pause de µs microsecondes

### Gestion entrées/sorties numériques

pinMode(Num_Port, Type) : sélection du type entrée ou sortie
- Num_Port : Numéro de la broche (de 0 à 19)
- Type : INPUT, INPUT_PULLUP, OUTPUT

digitalWrite(Num_Port, Valeur) : Ecriture sur une sortie
- Valeur : LOW, HIGH, 0, 1

Variable = digitalRead(Num Port) : Lecture d'une entrée
- Valeur : 0, 1

### Gestion entrées/sorties analogiques

La sélection du type entrée n'est pas nécessaire pour les entrées analogique.

Variable = analogRead(Num_Port) : Lecture d'une entrée analogique
- Valeur : 0 à 1023 (1024 pas de 4,9mv avec vref 5V)
- Num_Port : de 0 à 7

analogReference(type) : Sélection de la tension de référence
- DEFAULT : Valeur par défaut, utilise Vcc comme référence
- INTERNAL : Pour carte de type Uno, utilise la référence interne de 1.1v
- INTERNAL1V1 : Pour carte de type mega, utilise la référence interne de 1.1v
- INTERNAL2v56 : Pour carte de type mega, utilise la référence interne de 2.56v
- EXTERNAL : Utilise l'entrée externe Aref

### Gestion entrées/sorties PWM

analogWrite(Num_Port, Valeur) : Ecriture sur sortie PWM
Envoi sur la sortie un signal de 490Hz dont le rapport cyclique et défini par le paramètre Valeur.
- Valeur : 0 à 255 >> 0% à 100%
- Sorties disponibles : 3,5,6,9,10 et 11

tone(Num_Port, Fréquence, [durée]) : Sortie en Fréquence. Envoi sur la sortie un signal de rapport cyclique 50% à la
fréquence passée en paramètre en Hz. Le paramètre durée est optionnel. S'il n'est pas défini le signal est permanent.

noTone(Num_Port) : Stop le signal émis sur le port indiqué en paramètre

pulseIn(Num Port, Valeur_Seuil, [délai]) : Mesure d'impulsion:
Mesure la durée d'une impulsion en microseconde en détectant l'état de l'entrée choisi par Valeur_Seuil. Le paramètre délai précise un temps limite de lecture de l'entrée. Si ce paramètre est absent la valeur par défaut est de 1 seconde.

### Port série asynchrone

Les ports séries sont gérés par une bibliothèque intégrée ne nécessitant pas de déclaration. Les cartes de type Uno ne disposant que d'un port
série Nomport est toujours Serial, les cartes plus évoluées de type Mega utilisent Serial, Serial1, Serial2, Serial3 pour définir l'un de leurs 4 ports
série.

Serial.begin(Vitesse ,[Config]) : Initialisation
Vitesse : 300, 9600, 57600, 115200 bauds
Config : configuration du format de transmission (nombre de bit, parité, bit de stop) : SERIAL_BPS par défaut SERIAL_8N1
B : nombre de bits (5,6,7,8) , P : parité (N=sans, E paire, O impaire)
S : bits de stop ( 1, 2)

- Serial.end() : Libération du port
libère les ports TX et RX

Ecriture sur port série :
- Serial.write(int val) Envoi l'octet sur le port
- Serial.write(String) Envoi la chaine de caractère sur le port
- Serial.write(Buff,Len) Envoi N octets du tableau Buff
- Serial.print(Valeur) Envoi l'expression en ASCII de la valeur
- Serial.print(Val,Format)Envoi l'expression en ASCII de la valeur en fonction du format (HEX,BIN,DEC)
- Serial.println(Valeur) Idem et ajout d'un CRLF (retour chariot)

Lecture du port série :

- Serial.available() Renvoie le nombre de caractères à lire dans le buffer de réception
- variable = Serial.peek() Lit le premier caractère reçu sans l'effacer, renvoie 255 si vide.
- variable = Serial.read() Extrait le premier caractère reçu et l'efface du buffer, renvoie 255 si vide.
- variable = Serial.readBytes(String,longueur)
Extrait la chaine des Lg premiers caractères reçus dans String et les effaces du buffer.

- variable = Serial.readBytesUntil(Val_Arret,String,Lg_max)
Extrait les caractères reçus jusqu'à découverte du caractère d'arrêt ou le nombre maxi et les effaces du buffer.
- variable = Serial.find(Valeur)
Renvoie une valeur true si la valeur a été trouvée dans le buffer, vide celui-ci jusqu'à la découverte de la valeur ou complètement si pastrouvée.
- Serial.setTimeout(Long_Tms)
 Configure le temps maxi d'attente de caractères avant abandon pour les fonctions readBytes et readBytesUntil. Par défaut = 1000
ms.

### Classe String

La classe String permet une gestion plus simple des chaines de caractères.
- Concaténation
- Conversion de variable en chaine de caractères
