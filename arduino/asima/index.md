---
title: Asima
---

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

-[M13 : Commande de chauffage](m13)
-[M43 : Commande de pompe](m43)
-[M44 : Installation de pompage des eaux usées](m44)

### M14 : Rampe d’éclairage

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
|**Boutons-poussoirs**|||
S0|Arrêt |Rupteur|E124.0|*A0*
S1|Marche|Contacteur|E124.1
S2|Cuve 1 vide|Contacteur|E124.2
S3|Cuve 2 vide|Contacteur|E124.3
S4|Cuve 3 vide|Contacteur|E124.4
|**Capteurs**|||
B1|Niveau max cuve 1|Rupteur|E124.6
B2|Niveau max cuve 2|Rupteur|E124.7
B3|Niveau max cuve 3|Rupteur|E125.0
B4|Niveau min cuve 1|Rupteur|E125.1
B5|Niveau min cuve 2|Rupteur|E125.2
B6|Niveau min cuve 3|Rupteur|E125.3
|**Sorties**|||
Y1|Vanne de remplissage cuve 1|A124.0|*R0*
Y2|Vanne de remplissage cuve 2|A124.1|*R1*
Y3|Vanne de remplissage cuve 3|A124.2|*R2*
Y4|Vanne de vidage cuve 1|A124.3|*R3*
Y5|Vanne de vidage cuve 2|A124.4|*R4*
Y6|Vanne de vidage cuve 3|A124.5|*R5*
|**Voyants lumineux**|||
H1|Voyant installation marche|A125.0
H2|Voyant cuve 1|A125.1
H3|Voyant cuve 2|A125.2
H4|Voyant cuve 3|A125.3

Monte-charge
### M42 : Monte-charge

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
