Asima|Controllino Maxi|Sens|Adresse
---  |---  |---    |---
S0   | A0  |In     |*E124.0*
S1   | A1  |In     |*E124.1*
S2   | A2  |In     |*E124.2*
S3   | A3  |In     |*E124.3*
S4   | A4  |In     |*E124.4*
S5   | A5  |In     |*E124.5*
S6   | A6  |In     |*E124.6*
S7   | A7  |In     |*E124.7*
U1   | A8  |In A   |
U2   | A9  |In A   |
S8   | IN0 |Inter  |
S9   | IN1 |Interr |
S10  |     |       |
S11  |     |       |
H1   |     |       |
H2   |     |       |
H3   |     |       |
H4   |     |       |
E0   | R0  | Out   |A124.0
E1   | R1  | Out   |A124.1
E2   | R2  | Out   |A124.2
E3   | R3  | Out   |A124.3
E4   | R4  | Out   |A124.4
E5   | R5  | Out   |A124.5
E6   | R6  | Out   |A124.6
E7   | R7  | Out   |A124.7
E10  | R8  | Out   |
E11  | R9  | Out   |
E12  | D0  |       |   
E13  | D1  |       |
E14  | D2  |       |
E15  | D3  |       |
E16  | D4  |       |
E17  | D5  |       |
| D6  |       |
| D7  |       |
| D8  |       |
| D9  |       |
| D10 |       |
| D11 |       |

### M13 : Commande de chauffage

Commander la puissance du chauffage d’un entrepôt en connectant ou déconnectant des radiateurs.

Code|Nom|Description des contacts|Adresse|Controllino
|---|---|---|---|---|
||**Boutons-poussoirs**|||
S0|Arrêt|Rupteur|E124.0|*A0*
S1|Marche|Contacteur|E124.1|*A1*
S2|Connexion|Contacteur|E124.2|*A2*
S3|Déconnexion|Contacteur|E124.3|*A3*
||**Entrée analogique**
U1|Valeur de réglage|PEW130|
|**Sorties**
Y1|Vanne 1||A124.0|*R0*
Y2|Vanne 2||A124.1|*R1*
Y3|Vanne 3||A124.2|*R2*
Y4|Vanne 4||A124.3|*R3*
||**Voyants lumineux**
|H1|Voyant installat. marche||A125.0|

#### Description fonctionnelle 1

L’installation de chauffage est mise en état de disponibilité avec le bouton-poussoir S1 « Marche (On) », le voyant lumineux H1 est allumé. Les boutons-poussoirs « ▲ » et « ▼ » permettent de connecter et de déconnecter progressivement les radiateurs via les vannes Y1 à Y4. 
Le bouton-poussoir S0 « Arrêt (Off)» sert à arrêter l’installation de chauffage à tout instant.

#### Description fonctionnelle 2

Jusqu’à présent, on considérait que tous les radiateurs avaient la même puissance de chauffage ;
maintenant, il faut tenir compte d’une puissance de chauffage différente. 
Les vannes permettent ainsi d’enclencher les puissances suivantes : Y1 : 1 kW, Y2 : 2 kW, Y3 : 4 kW et Y4 : 8 kW. 
La puissance de chauffage peut être enclenchée par pas de 1 kW, de 0 kW à 15 kW.


#### Description fonctionnelle 3

Les radiateurs doivent, conformément à la description fonctionnelle 1, être connectés et déconnectés par réglage du potentiomètre et non avec les boutons-poussoirs « ▲ » et « ▼ ».
La gamme de réglage linéaire du potentiomètre vaut 0 V  0 % à 10 V 100 %.

#### Description fonctionnelle 4

Les radiateurs doivent, conformément à la description fonctionnelle 2, être connectés et déconnectés par réglage du potentiomètre et non avec les boutons-poussoirs « ▲ » et « ▼ ».

### M14 : 

Code|Nom|Description des contacts|Adresse|Controllino
|---|---|---|---|---|
||**Boutons-poussoirs**|||
S0|Arrêt    |Rupteur   |E124.0|*A0*
S1|Démarrage|Contacteur|E124.1|*A1*
S2|Descente |Contacteur|E124.2|*A2*
S3|Montée   |Contacteur|E124.3|*A3*
S4|Rythme   |Contacteur|E124.4|*A4*
S5|Man/auto |Contacteur|E124.5|*A5*
||**Entrée analogique**|||
U1|Valeur de réglage|PEW130|
||**Voyants lumineux**|||
H1|||A124.0|*R0*
H2|||A124.1|*R1*
H3|||A124.2|*R2*
H4|||A124.3|*R3*
H5|||A124.4|*R4*
H6|||A124.5|*R5*
H7|||A124.6|*R6*
H8|||A124.7|*R7*



### M16 : Système de remplissage de cuves

Code|Nom|Description des contacts|Adresse|Controllino
|---|---|---|---|---|
||**Boutons-poussoirs**|||
S0|Arrêt |Rupteur|E124.0|*A0*
S1|Marche|Contacteur|E124.1
S2|Cuve 1 vide|Contacteur|E124.2
S3|Cuve 2 vide|Contacteur|E124.3
S4|Cuve 3 vide|Contacteur|E124.4
||**Capteurs
B1|Niveau max cuve 1|Rupteur|E124.6
B2|Niveau max cuve 2|Rupteur|E124.7
B3|Niveau max cuve 3|Rupteur|E125.0
B4|Niveau min cuve 1|Rupteur|E125.1
B5|Niveau min cuve 2|Rupteur|E125.2
B6|Niveau min cuve 3|Rupteur|E125.3
||**Sorties
Y1|Vanne de remplissage cuve 1|A124.0|*R0*
Y2|Vanne de remplissage cuve 2|A124.1|*R1*
Y3|Vanne de remplissage cuve 3|A124.2|*R2*
Y4|Vanne de vidage cuve 1|A124.3|*R3*
Y5|Vanne de vidage cuve 2|A124.4|*R4*
Y6|Vanne de vidage cuve 3|A124.5|*R5*
||**Voyants lumineux
H1|Voyant installation marche|A125.0
H2|Voyant cuve 1|A125.1
H3|Voyant cuve 2|A125.2
H4|Voyant cuve 3|A125.3


### M42

Code|Nom|Description des contacts|Adresse|Controllino
|---|---|---|---|---|
|**Boutons-poussoirs**|||
S0|Arrêt|Rupteur|E124.0|*A0*
S1|Bouton-poussoir station 4|Contacteur|E124.1|*A1*
S2|Bouton-poussoir station 3|Contacteur|E124.2|*A2*
S3|Bouton-poussoir station 2|Contacteur|E124.3|*A3*
S4|Bouton-poussoir station 1|Contacteur|E124.4|*A4*
S5|Descente|Contacteur|E124.5|*A5*
|**Capteurs**|||
B6 |Capteur station 1    |Rupteur|E124.6|*A6*
B7 |Capteur station 2    |Rupteur|E124.7|*A7*
B8 |Capteur station 3    |Rupteur|E125.0|
B9 |Capteur station 4    |Rupteur|E125.1|
B10|Fin de course en bas |Rupteur|E125.2|
B11|Fin de course en haut|Rupteur|E125.3|
|**Sorties**|||
K1|Monter   ||A124.0|*R0*
K2|Descendre||A124.5|*R5*
|**Voyant lumineux**
H1|Station 4||A124.1|*R1*
H2|Station 3||A124.2|*R2*
H3|Station 2||A124.3|*R3*
H4|Station 1||A124.4|*R4*

### M43 : Commande de pompe

Code|Nom|Description des contacts|Adresse|Controllino
|---|---|---|---|---|
|**Boutons-poussoirs**|||
S0|Arrêt                  |Rupteur|E124.0|*A0*
S1|Protection du moteur Q1|Rupteur|E124.1|*A1*
S2|Protection du moteur Q2|Rupteur|E124.2|*A2*
S3|Protection du moteur Q3|Rupteur|E124.3|*A3*
S4|Protection du moteur Q4|Rupteur|E124.4|*A4*
S5|Marche|Contacteur|E124.5|*A5*
|**Capteurs**|||
B1|Capteur de pression 1|Rupteur|E124.6|*A6*
B2|Capteur de pression 2|Rupteur|E124.7|*A7*
Sorties
M1|Commande pompe 1|A124.0|*R0*
M2|Commande pompe 2|A124.1|*R1*
M3|Commande pompe 3|A124.2|*R2*
M4|Commande pompe 4|A124.3|*R3*
SH|Avertisseur sonore|A124.5|*R5*
|**Voyants lumineux**|||
H1|Voyant lumineux pompe 1|A125.0|
H2|Voyant lumineux pompe 2|A125.1|
H3|Voyant lumineux pompe 3|A125.2|
H4|Voyant lumineux pompe 4|A125.3|

### M44 : Installation de pompage des eaux usées

Etudier et réaliser la programmation d'une installation de pompage des eaux usées.

Code|Nom|Description des contacts|Adresse|Controllino
|---|---|---|---|---|
|**Boutons-poussoirs**|||
S0|Installation arrêt |Rupteur   |E124.0|*A0*
S1|Installation marche|Contacteur|E124.1|*A1*
S3|Pompe 1 – test     |Contacteur|E124.3|*A3*
S4|Pompe 2 – test     |Contacteur|E124.4|*A4*
S5|Reset              |Contacteur|E124.5|*A5*
S6|Q1 – Pompe 1       |Rupteur   |E124.6|*A6*
S7|Q2 – Pompe 2       |Rupteur   |E124.7|*A7*
|**Capteurs**|||
B1|Pompes arrêt       |Rupteur|E125.0|
B2|Pompe 1 marche     |Rupteur|E125.1|
B3|Trop-plein         |Rupteur|E125.2|
B4|Pompes arrêt       |Rupteur|E125.3|
B5|Pompe 2 marche     |Rupteur|E124.2|
|**Entrées analogiques**|||
U1|Niveau d’eau          ||PEW130|*A8*
U2|Niveau d’enclenchement||PEW132|*A9*
|**Sorties**|||
Sh|Avertisseur sonore|A124.0|*R0*
M1|Pompe 1||A124.1   |*R1*
M2|Pompe 2||A124.3   |*R3*
|**Voyants lumineux**|||
H1|Validation||A124.2|*R8*
H3|Pompe 1||A124.4   |*D0*
H4|Pompe 2||A124.5   |*D1*


L’installation est mise en route avec le bouton-poussoir S1, l’état de fonctionnement est signalé par le voyant lumineux H1. Le bouton-poussoir S0 doit permettre d’arrêter immédiatement l’installation.

Le niveau dans la cuve est mesuré à l'aide d'un capteur analogique de pression (U1). On prodédera à une mise à l'échelle de la mesure pour que la plage de variation soit comprise entre 0% (cuve vide) et 100% (cuve pleine).

Le seuil de déclenchement de la première pompe P1 sera réglé à l'aide d'un potentiomètre qui est cablé sur une entrée analogique de l'automate. La plage de variation de cette entrée sera également ramenée entre 0 et 50% pour pouvoir faire l'analogie avec le niveau de la cuve.



Si le niveau d’eau atteint le premier seuil de déclenchement, la pompe P1 se met en route. Lorsque le niveau d’eau repasse en-dessous du premier seuil, la pompe P1 est mise hors service.

Si l’arrivée d’eau est telle que le niveau d’eau continue d’augmenter malgré la pompe P1 qui est enclenchée, la pompe P2 est alors connectée lorsque le niveau d’eau atteint le deuxième seuil (premier seuil + 30%). Lorsque le niveau d’eau repasse sous le premier seuil, la pompe 2 est arrêtée elle aussi.

Il doit aussi pouvoir être possible de procéder à un test de fonctionnement des pompes lorsque les deux pompes sont arrêtées alors que le niveau d'eau est bas. Si le bouton-poussoir S3 ou S4 est actionné, la pompe correspondante doit fonctionner pendant 3 s maximum.

L’éclairage ininterrompu des voyants lumineux H3 et H4 signale l’état de fonctionnement des pompes. Si un relais de protection de moteur déclenche, le voyant lumineux correspondant au moteur en question se met à clignoter à 0.5Hz et un signal sonore retentit simultanément pendant 5s. C’est seulement après avoir remédié à la perturbation qu’il est possible d’acquitter le clignotement du voyant lumineux en actionnant le bouton-poussoir Reset.

L’installation est conçue de manière à ce que, même pour une très grande quantité d’eau à l'entrée du système, le débit des deux pompes réunies suffise à refouler l’eau. Si, suite à la défaillance d'une pompe le niveau d’eau atteint 90% de la cuve (seuil d'alerte), un signal sonore retentit simultanément jusqu’à ce que le bouton-poussoir Reset soit actionné.
