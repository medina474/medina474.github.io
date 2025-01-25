+++
title = "M45 : Surveillance de trois pompes"
+++

Code|Nom|Description des contacts|Adresse|Controllino
|---|---|---|---|---|
|**Boutons-poussoirs**|||
S0|Installation arrêt|Rupteur|E124.0|*A0*
S1|Installation marche|Contacteur|E124.1|*A1*
S3|Pompe 1 – test|Contacteur|E124.3|*A3*
S4|Pompe 2 – test|Contacteur|E124.4|*A4*
S5|Reset|Contacteur|E124.5|*A5*
S6|Q1 – Pompe 1|Rupteur|E124.6|*A6*
S7|Q2 – Pompe 2|Rupteur|E124.7|*A7*
|**Capteurs**|||
B1|Pompes arrêt|Rupteur|E125.0|*IN0*
B2|Pompe 1 marche|Rupteur|E125.1|IN1
B3|Trop-plein|Rupteur|E125.2
B4|Pompes arrêt|Rupteur|E125.3
B5|Pompe 2 marche|Rupteur|E124.2
|**Entrées analogiques**|||
U1|Niveau d’eau|PEW130|A8
U2|Niveau d’enclenchement|PEW132|A9
|**Sorties**|||
Y1|Vanne d’alimentation|A124.0|*R0*
PM1|Pompe 1|A124.1|*R1*
PM2|Pompe 2|A124.2|*R2*
PM3|Pompe 3|A124.3|*R3*
Sh|Avertisseur sonore|A124.5|*R5*
|**Voyant lumineux**|||
H1|Voyant lumineux Validation|A125.1|
H3|Voyant lumineux Pompe 1|A125.2|
H4|Voyant lumineux Pompe 2|A125.3|

## Énoncé

Pour des raisons de sécurité, un tout-à-l’égout est équipé de trois pompes. Suivant la quantité alimentée, il y a une pompe ou bien deux pompes qui fonctionnent. Afin d’équilibrer l’usure des pompes, la durée d’enclenchement doit être à peu près la même grâce à une séquence d’enclenchement appropriée. Si l’une des deux pompes tombe en panne, c’est la troisième pompe qui assume la fonction de la pompe défectueuse.

## Description fonctionnelle A

L’installation de pompage est mise en route avec le bouton-poussoir S1. L’état de fonctionnement est signalé par l’éclairage ininterrompu du voyant lumineux H1 ; la vanne d’alimentation Y1 s’ouvre. Si l’installation de pompage est mise hors service avec le bouton-poussoir S0, la vanne Y1 bloque et le voyant lumineux H1 s’éteint.

## Description fonctionnelle B

Si le niveau d’eau augmente jusqu’à ce que le capteur B2 réagisse, une pompe est enclenchée. Si le capteur B2 reste activé plus de 3 s malgré la pompe enclenchée, la deuxième pompe est elle aussi mise en route. Si le niveau des eaux usées baisse jusqu’à ce que le capteur B1 ne réagisse plus, plus aucune pompe ne doit être enclenchée.

Pour que l’usure des pompes 1 et 2 soit à peu près la même pour les deux pompes, les séquences d’enclenchement et de coupure doivent alterner. Si l’une des deux pompes tombe en panne (par ex. suite au déclenchement du relais de protection de moteur Q simulé par activation du bouton-poussoir S2 ou S3), la troisième pompe assume alors la fonction de la pompe défectueuse.

L’état de fonctionnement d’une pompe est signalé par l’éclairage ininterrompu du voyant lumineux correspondant H2, H3 ou H4. Si une pompe tombe en panne, le voyant lumineux correspondant se met à clignoter. Une fois la pompe défectueuse réparée, l’activation du bouton-poussoir S5 « Reset » la remettra en attente.

Si le capteur B3 réagit ou que deux pompes tombent en panne, la vanne Y1 doit se fermer et un signal
sonore devra retentir.
