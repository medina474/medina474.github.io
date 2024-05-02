---
layout: layouts/page.njk
title: KeePass
---

> **KeePass** est un logiciel gestionnaire de mots de passe. Il permet de centraliser, protéger et sauvegarder un ensemble de mots de passe dans un seul fichier chiffré.
{.definition}

L'avantage est que vous n'avez plus à vous souvenir des mots de passe de vos différents comptes. Les mots de passe peuvent être très longs et très compliqués le gestionnaire se charge de les retenir pour vous.

Télécharger et installer [KeePass 2.52](https://keepass.info/download.html).

Créer un nouveau fichier, renseigner le mot de passe principal, c'est le seul dont vous aurez à vous souvenir.

> En cas de perte de ce mot de passe il sera impossible de récupérer les informations du fichier !
{.warning}

Utilisez des chiffres, des lettres, des majuscules, des minuscules et un moyen mémotechique de retrouver votre mot de passe.

Par exemple la phrase : Louis XIV né le 5 septembre 1638 à Saint-Germain-en-Laye donne le mot de passe _LouisXIV5Sep1638StG.en-Laye_. Mais encore faut-il se souvenir de la transformation.

Le plus efficace est de choisir 4 mots simples sans signification entre eux.

![xkcd.com/936](https://imgs.xkcd.com/comics/password_strength.png)

![][Create]

## Entrée de mot de passe

Créer une entrée pour le compte `iutsd` du Rapberry.

![][Password]

Utiliser le générateur de mot de passe pour générer un mot de passe complexe.

![][Generator]

## Utilisation de KeePass

Ctrl J : Masque/Affiche le compte utilisateur\
Ctrl H : Masque/Affiche le mot de passe\
Ctrl V : Effectue une frappe clavier suivant la séquence définie\
Ctrl M : Charger la clé privée dans l'agent

Double clic sur le nom d'utilisateur : copie le nom d'utilisateur\
Double clic sur le mot passe : copie le mot de passe\
Double clic sur l'URL : ouvre la connexion


### Autotype

L'autotype (`Ctrl V`) génère des frappes clavier comme si c'était l'utilisateur qui les faisent lui même.

L'Autotype peut être défini au niveau du groupe ou de l'entrée.

:warning: au modèle d'autotype utilisé par défaut.

`{UserName}{TAB}{Password}{ENTER}`

![][Autotype]

## Gestion des clés ssh

KeePass est capable de fonctionner comme un agent pour vos [clés ssh](../ssh/).

## Authentification double facteurs

Installer le module `KeeOtp2` pour pouvoir générer des tokens basés sur le temps. L'heure courante est chiffré avec un code secret partagé entre l'appareil générant le token et le serveur d'authentification. Si le code généré est identique sur les 2 machines alors l'authentification est réussie.

> Attention : donner la possibilité à KeePass de générer des token OTP va à l'encontre de la philosophie de l'authentification à double facteurs puisque les deux se retrouvent au même endroit dans KeePass.
{.warning}

## Sauvegarde de KeePass

Le fichier KeePass est extremement important. Le perdre peut avoir des conséquences désastreuses. Il est donc impératif de le sauvegarder de manière très rigoureuse.

Une solution consiste à stocker le fichier sur `OneDrive` (ou un autre service similaire) puis à utilser un plugin de synchronisation comme [KeePassOneDriveSync](https://github.com/KoenZomers/KeePassOneDriveSync) pour synchroniser avec un fichier local sur votre machine.

> ***A savoir :*** Une version pour Android existe [Keepass2Android](https://play.google.com/store/apps/details?id=keepass2android.keepass2android&hl=fr). Elle utilise aussi la synchronisation avec OneDrive.


## Liste de contrôle

application|commande|version
-|-|-:
KeePass||2.52
KeeAgent||0.12.1.0
KeeOtp2||1.5.9
KoenZomers.KeePass.OneDriveSync||2.1.2.2
SSH Windows|ssh -V|OpenSSH_for_Windows_7.7p1, LibreSSL 2.6.5
SSH Git Bash|ssh -V|OpenSSH_8.4p1, OpenSSL 1.1.1h  22 Sep 2020

Tester la clé auprès de GitLab

```
ssh -T git@gitlab.com
```

[Create]: create.png "Créer un nouveau fichier avec KeePass"
[Password]: password.png "Créer un nouveau fichier avec KeePass"
[Generator]: generator.png "Générer un mot de passe complexe"
[Autotype]: autotype.png "Simuler une frappe clavier"
