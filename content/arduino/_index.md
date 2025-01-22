---
title: Informatique
---

- [Cours](../programmationc)
- [Controllino](controllino)
- [Asima](asima)

### Maquettes Asima

- M10 :Démarreur de moteur asynchrone à rotor bobiné
- M11 : Bande transporteuse
- M12 : Compensation du courant réactif
- [M13 : Commande de chauffage](asima/m13)
- [M14 : Rampe d’éclairage](asima/m14)
- M15 : Système de remplissage de réservoirs
- [M16 : Système de remplissage de cuves](asima/m16)
- M18 : Estampilleuse
- [M19 : Commande de ventilateur](asima/m19)
- M20 : Feu de chantier
- M21 : Feux de passage pour piétons
- M22 : Convoyeur collecteur
- M23 : Installation de chargement à bandes transporteuses
- [M42 : Monte-charge](asima/m42)
- [M43 : Commande de pompe](asima/m43)
- [M44 : Installation de pompage des eaux usées](asima/m44)

## Fonctions utiles

### Définir le sens d'un port

```c
pinMode(CONTROLLINO_R0, OUTPUT);
```

### Lire une entrée

```c
s0 = digitalRead(CONTROLLINO_A0);
s1 = digitalRead(CONTROLLINO_A1);
s2 = digitalRead(CONTROLLINO_A2);
s3 = digitalRead(CONTROLLINO_A3);
```

### Détecter un front montant

```c
s4 = digitalRead(CONTROLLINO_A4);
s4_fm = (s4 > s4_precedent);  
s4_precedent = s4;
```

### Actionner une sortie

```c
digitalWrite(CONTROLLINO_R1, 1);
```

### Temporisation

```c
unsigned long temps_ecoule = millis() - tempo_start;

if (temps_ecoule > duree) {
  /* */
  tempo_start = millis();
}
```
