---
title: Installer Debian 12
---

Démarrer sur l'iso _debian-12.5.0-amd64-netinst.iso_

### Debian GNU/Linux UEFI Installer menu

Advanced options ...

... Expert install

### Debian installer main menu

#### Choose language

- Select a language : French - Français
- Pays (territoire ou région) : France
- Pays qui servira de base aux paramètres régionaux par défaut : France fr_FR.UTF-8
- Paramètres régionaux supplémentaires : (aucun)

#### Acces software for a blind person using a braille display

- Ne pas faire, sauter l'étape

### Menu princinpal du programme d'installation Debian

#### Configurer le clavier

- Disposition du clavier à utiliser : Français
- Continuer

#### Détection et montage du support d'installation

- Continuer

#### Charger des composants depuis le support d'installation

- Ne rien sélectionner
- Continuer

#### Détecter le matériel réseau

#### Configurer le réseau

- Faut-il configurer le réseau automatiquement ? : Oui
- Délai d'attente (en secondes) pour la détection du réseau : 3
- Nom de la machine :
- Domaine :

#### Créer les utilisateurs et choisir les mots de passe

Faut-il autoriser les connexions du superutilisateur ?
Oui

Faut-il créer un compte d'utilisateur ordinaire maintenant ?
Non

#### Configurer l'horloge

Faut-il utiliser NTP pour régler l'horloge ?
Non

Fuseau horaire :
Europe/Paris

#### Détecter les disques

#### Partionnner les disques
Assité - utiliser un disque entier
SCSI1 (0,0,0) (sda)

Schéma de partitionnement
Tout dans une seule partition (recommandé pour les débutants)

Terminer le partitionnement et appliquer les changements

Faut-il appliquer les changements sur les disques ?
Oui

#### Installer le système de base

Noyau à installer
linux-image-amd64

Pilotes à inclure sur l'image disque en mémoire ( initrd )
image ciblée : seulement les pilotes nécessaires pour ce système

#### Configurer l'outil de gestion des paquets

Faut-il analyser d'autres supports d'installation ?
_Non_

Faut-il utiliser un miroir sur le réseau
_Oui_

Protocole de téléchargement des fichiers
_http_

Souhaitez-vous utiliser des microprogrammes non libres ?
_Oui_

Souhaitez-vous utiliser des logiciels non libres ?
_Non_

Souhaitez-vous utiliser des logiciels de la section contrib ?
_Non_

Activer les dépôts source dans APT
Non

Services à utiliser

- mises à jour de sécurité
- mises à jour de la publication

#### Choisir et installer des logiciels

Gestion des mises à jour sur ce système :
Installation automatique des mises à jour de sécurité

Sélection des logiciels
Tout décocher

#### Installer le programme de démarrage GRUB

Faut-il forcer l'installation sur le chemin des supports amovibles EFI
_Non_

Faut-il mettre à jour les variables dans la mémoire non volatile pour démarrer Debian automatiquement ? (12 bookworm)
_Oui_

Faut-il exécuter os-prober automatiquement pour détecter et amorcer d'autres systèmes ? (12 bookworm)
_Non_

#### Terminer l'installation

L'horloge système est-elle à l'heure universelle (UTC) ?
_Non_

Veuillez sélectionner <Continuer> pour redémarrer
Continuer
