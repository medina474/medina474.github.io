---
title: Informatique
---

- [Cours](../programmationc)
- [Controllino](controllino)
- [Asima](asima)

### Maquettes Asima

- M1 : Fonctions logiques de base
- M2 : Composants fonctionnels numériques
- M3 : Moteur MARCHE/ARRÊT
- M4 : Contacteur inverseur
- M5 : Montage étoile-triangle
- M6 : Commutation étoile-triangle à inversion de pôles
- [M7 : Commande de table alternante](asima/m7)
- M8 : Montage de Dahlander
- M9 : Moteur avec 2 enroulements
- M10 :Démarreur de moteur asynchrone à rotor bobiné
- M11 : Bande transporteuse
- M12 : Compensation du courant réactif
- [M13 : Commande de chauffage](asima/m13)
- [M14 : Rampe d’éclairage](asima/m14)
- M15 : Système de remplissage de réservoirs
- [M16 : Système de remplissage de cuves](asima/m16)
- M17 : Broyeur à charbon
- M18 : Estampilleuse
- M19 : Commande de ventilateur
- M20 : Feu de chantier
- M21 : Feux de passage pour piétons
- M22 : Convoyeur collecteur
- M23 : Installation de chargement à bandes transporteuses
- M40 : Commande de silo
- M41 : Réacteur
- [M42 : Monte-charge](asima/m42)
- [M43 : Commande de pompe](asima/m43)
- [M44 : Installation de pompage des eaux usées](asima/m44)
- M45 : Surveillance de trois pompes
- M46 : Installation de pompage (pression)
- M47 : Distributeur automatique de boissons chaudes
- M48 : Malaxeur
- M49 : Commande séquentielle

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
