---
title: Communication UDP
---

**TCP** (Transmission Control Protocol) et **UDP** (User Datagram Protocol) sont deux des principaux protocoles de transport dans la suite de protocoles Internet. Ils sont utilisés pour transmettre des données entre les appareils, mais ils fonctionnent de manière différente, chacun ayant ses avantages et ses inconvénients selon les cas d'utilisation.

### Avantages de TCP

**Fiabilité :** TCP garantit que les paquets arrivent complets et dans le bon ordre. Cela est essentiel pour les applications nécessitant une transmission intégrale des données, comme le transfert de fichiers ou l'affichage de pages Web.

**Contrôle d'erreurs :** TCP vérifie la validité des paquets, demande la retransmission des paquets corrompus ou manquants, ce qui assure la cohérence des données.

**Contrôle de congestion et de flux :** TCP ajuste la vitesse de transmission en fonction des conditions réseau pour éviter la surcharge et les pertes de données.

**Cas d'utilisation courants :**

- Navigation web (HTTP/HTTPS)
- Transfert de fichiers (FTP)7
- Courriel (SMTP, IMAP)
- Applications nécessitant une grande fiabilité et une réception complète des données

### Avantages de UDP

**Rapidité :** UDP n'effectue pas de vérification de connexion ni de retransmission de paquets perdus, ce qui permet une transmission plus rapide.
    
**Efficacité pour les applications en temps réel :** UDP est idéal pour les applications où la vitesse est plus importante que la fiabilité, comme le streaming vidéo en direct ou les jeux en ligne.
    
**Simplicité :** Avec une en-tête plus légère et sans gestion de session, UDP est moins complexe et consomme moins de ressources que TCP.

**Cas d'utilisation courants :**

- Streaming audio et vidéo (voix sur IP, vidéoconférence)
- Gaming en ligne
- DNS (requêtes de noms de domaine)
- Applications qui peuvent tolérer une certaine perte de données

Aspect|TCP  |UDP  |
---   |---  |---  |
Type de connexion|Basé sur une connexion (connexion orientée)|Sans connexion (non-orienté)
Fiabilité|Fiable (assure la livraison et l'ordre des paquets)|Non fiable (pas de garantie de livraison ni d'ordre)
Contrôle de flux|Oui, contrôle de flux et de congestion|Non
Vitesse|Plus lent (contrôle d'erreurs et de flux)|Plus rapide (moins de vérifications)
Transmission|Transmission continue et organisée|Envoi de paquets indépendants
Taille d'en-tête|Plus grande (environ 20 octets)|Plus petite (environ 8 octets)
Reconstruction des données|Reconstitue automatiquement les données dans l'ordre d'envoi|L'application doit gérer la reconstruction
