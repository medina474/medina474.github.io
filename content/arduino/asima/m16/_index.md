+++
title = "M16 : Système de remplissage de cuves"
+++

Code|Nom|Description des contacts|Adresse|Controllino
|---|---|---|---|---|
|**Boutons-poussoirs**|||
S0|Vanne 1 marche  |Contacteur|E124.0|*A0*
S1|Vanne 1 arrêt |Contacteur|E124.1|*A1*
S2|Vanne 2 marche|Contacteur|E124.2|*A2*
S3|Vanne 2 arrêt|Contacteur|E124.3|*A3*
S4|Vanne 3 marche|Contacteur|E124.4|*A4*
S5|Vanne 3 arrêt|Contacteur|E124.5|*A5*
S6|Arrêt|Contacteur|E124.6|*A6*
|**Sorties**|||
Y1|Vanne 1|A124.0|*R0*
Y2|Vanne 2|A124.1|*R1*
Y3|Vanne 3|A124.2|*R2*


Il s’agit de remplir un broyeur à charbon à partir de trois silos. Afin d’éviter un surremplissage du broyeur, le remplissage ne doit être effectué que par maximum deux des trois silos.

Le remplissage du broyeur à charbon à partir d’un silo a lieu tant que la bobine du curseur magnétique
(vanne) Y est sous tension. La commande de chaque bobine est assurée par un contacteur qui peut être connecté ou déconnecté individuellement au moyen de deux boutons-poussoirs. Pour éviter un surremplissage du broyeur à charbon, il faut garantir par verrouillage qu’un troisième contacteur ne peut pas être connecté lorsqu’il y a déjà deux contacteurs d’enclenchés simultanément. Le poussoir à verrouillage S6 doit permettre l’arrêt complet de l’installation à tout instant.
