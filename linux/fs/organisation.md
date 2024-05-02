---
title: Organisation
---

Tous les systèmes Linux adhèrent à une norme qui défini l'organisation et le nommage des dossiers et fichiers. 

Cette norme permet aux utilisateurs et aux auteurs de logiciel de prévoir l'emplacement des fichiers et des répertoires sans se poser de questions. 

Le répertoire de départ appelé racine est représenté par la barre oblique `/`. 

dossier|contenu
---|---
bin	 | alias du dossier `/usr/bin`. Contient les exécutables des commandes essentielles (`passwd`, `cp`, `mv`, `mkdir`, ...) pour les utilisateurs
boot | Fichiers statiques pour le programme d'amorçage
dev	 | Fichiers des pilotes de périphériques
etc	 | Dossier contenant les fichiers de configuration de tous les programmes du système.
home | Dossier contenant les dossier des utilisateurs (un dossier par utilisateur)
home/iutsd | Dossier de l'utilisateur `iutsd`
lib	 | alias du dossier `/usr/lib` Bibliothèques partagées et modules noyaux essentiels (par exemple `ngx_http_geoip_module.so` module pour le serveur nginx qui géolocalise une adresse ip grâce à une base de données)
lost+found|Contient des fragments de fichiers corrompus, récupérés par la commande fsck. Cela peut se produire si le système est arrêté brutalement pendant une écriture.
media |	Points de montage pour les supports amovibles comme les clés ou disques durs usb
mnt	 | Point de montage pour les montages temporaires executé par l'utilisateur
opt  | Dossier pour les programmes installés manuellement par l'utilisateur. (optional add-on software package). Le dossier `/usr/local` est utilisé de plus en plus à la place de celui-ci.
proc | Dossier virtuel pour les informations système.
root | Dossier personnel de l'utilisateur root. (Le seul qui ne soit pas dans `home`)
run	 | Données variables d'exécution comme les fichiers .pid qui contiennent des informations sur les programmes en cours d'exécution.
sbin | alias du dossier `/usr/sbin`. Contient les exécutables des programmes systèmes essentiels (`fsck`) réservés au superutilisateur `root`.
srv  | Données pour les services fournis par le système
sys	 | Répertoire virtuel pour les informations système
tmp	 | Dossier pour les fichiers temporaires
usr	 | Hiérarchie secondaire. Il contient les exécutables, bibliothèques et documentations pour toutes les applications de l'utilisateur.
usr/bin | voir `bin`
usr/sbin | voir `sbin`
var	 | Données variables. Dossier qui va contenir les emails, les fichiers des sites web,  etc.
var/www/html| Dossier racine du serveur web. On va trouver en premier lieu le fichier index.html
var/log | Dossier pour les fichiers log de journalisation des événements. 

## Définition

pid
: Process Identification Number

usr
: Unix System Resources

## Références

Debian : [L'arborescence des fichiers](https://www.debian.org/releases/stable/s390x/apcs02.fr.html)