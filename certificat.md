---
title: "Certificat"
date: 2023-01-18T21:55:30+01:00
draft: false
---

Voir en préambule le chapitre sur la [Cryptographie](../cryptography/)

Pour communiquer de manière sécurisée nous avons vu qu'il fallait chiffrer les messages. Dans le cas d'un serveur web, nous avons des millions de personnes qui veulent communiquer avec un serveur.

Le fonctionnement par chiffrement symétrique n'est pas possible, car il faudrait que le serveur connaissent la clé de tous les visiteurs ou que le serveur distribue sa clé à tous les visiteurs potentiels. Dans ce cas il n'y a plus de secret car chacun connaît la clé de tout le monde.

Le chiffrement par paire de clé est l'idéal. Le serveur distribue sa clé publique à tout le monde. Celui qui veut communiquer avec le serveur chiffre le message avec la clé publique du serveur et seul le serveur est en mesure de  déchiffrer le message avec sa clé privée.

2 problèmes se posent alors. Comment le serveur répond à son visiteur ? Et comment être sûr que la clé publique correspond bien au serveur que je veux visiter (celui de ma banque par exemple) et pas à quelqu'un d'autre ?

### Comment répondre au client ?

Si le serveur répond en chiffrant les messages avec sa clé privée alors tous ceux qui connaissent la clé publique, donc tout le monde peuvent lire la réponse.

La solution consiste à établir une première communication sécurisée à l'aide d'un chiffrement asymétrique, de convenir aléatoirement d'une clé symétrique appelée clé de session, de se l'échanger, puis de continuer la communication avec un chiffrement symétrique. L'avantage est que la puissance de calcul d'un chiffrement symétrique est moindre qu'avec une paire privée/publique.

### Comment être sûr de l'identité de la clé publique ?

La solution consiste à faire entrer un troisième tiers dans la communication. Cette troisième partie est appelée **autorité de confiance**. Elle garanti par sa fonction que la clé publique appartient bien à celui qui la revendique.

Pour cela la création d'un certificat repose sur un enchaînement de procédure.

**Étape 1 :** le serveur génère une paire de clés publique/privée. La clé privée est soigneusement conservée et protégée par un chiffrement symétrique.

**Étape 2 :** le serveur envoie la clé publique à un organisme reconnu comme autorité de confiance. Il transmet avec la clé le ou les nom(s) du serveur ainsi que toutes sortes d'information permettant de l'identifier (justificatif de domicile, n° de téléphone, date de naissance, etc.)

**Étape 3 :** L'autorité vérifie l'identité du demandeur de certificat. La vérification peut être plus ou moins longue et complexe (vérification du propriétaire d'un nom de domaine, appel téléphonique, envoi de courrier avec code de confirmation)

**Étape 4 :** L'autorité valide la demande. L'ensemble clé publique + informations d'identité sont compilés dans un fichier. L'empreinte numérique de ce message est calculé, puis cette empreinte est chiffrée avec la clé privée de l'autorité. Le tout forme le certificat qui est retourné au serveur.

### Comment le visiteur vérifie l'identité du porteur du certificat ?

**Étape 1 :** Le serveur distribue publiquement son certificat.

**Étape 2 :** Le visiteur calcul l'empreinte du fichier

**Étape 3 :** Le visiteur déchiffre l'empreinte calculée par l'autorité (avec la clé publique de l'autorité)

**Étape 4 :** Si les deux empreintes sont identiques cela signifie que les informations contenues dans le certificat n'ont pas été altérées et que l'identité est bien celle validée par l'autorité.


## Autorité

Créer un certificat d'[autorité](../autority/) ou récupérer <a href="autority.crt" download>directement</a> le certificat de l'autorité.

Installer le certificat racine pour chaque navigateur (Firefox, Chrome et Edge)

Firefox – Options – Vie privée et sécurité – Afficher les certificats – Importer le fichier master.crt – Choisir le paramètre de confiance : Ce certificat peut identifier des sites web.

Chrome utilise le magasin de Windows qui est utilisé aussi par Edge et toutes les applications Windows.

Chrome – Paramètres – Rechercher : certificats – Gérer les certificats – Choisir l’onglet Autorités de certification racines de confiance – Importer … - Choisir le magasin par défaut.

## Création du certificat pour localhost

### Générer une demande de certificat et la clé privée associée

Sur le Raspberry

```shell-session
$ openssl req -new -utf8 -newkey rsa:2048 -nodes -keyout cinema.key -config cinema.cnf -out cinema.csr
```

`-new` : générer une demande de certificat\
`-nodes` : ne pas chiffrer la clé (no DES)\
`-out` : Nom du fichier pour écrire la demande de certificat.

Fichier de configuration `cinema.cnf`. (Utilisation itentionnelle de caractères non ascii)

```
[req]
prompt = no
distinguished_name = dn

[dn]
CN = client.cinema.org
emailAddress = emmanuel.medina@univ-lorraine.fr
O = 大阪大学
OU = Факультет радиотехники и кибернетики
L =  الإسكندرية
C = IT
```

### Accepter et signer la demande de certificat

Transférer la demande à l'autorité (le PC)

Fichier de configuration `extensions.cnf` qui va contenir les directives pour l'extension SAN (Subject Alternative Name)

```
[ v3_req ]
basicConstraints = CA:FALSE
keyUsage = nonRepudiation, digitalSignature, keyEncipherment
subjectAltName = @alt_names

[ alt_names ]
DNS.1 = iutsd-raspberry30-896.ad.univ-lorraine.fr
DNS.2 = client.cinema.org
IP.1 = 192.168.1.17
IP.2 = 100.64.96.58
```

Lancer la commande pour signer la demande et générer le certificat.

```
openssl x509 -req ^
    -in cinema.csr ^
    -CA master.crt ^
    -CAkey master.key ^
    -CAcreateserial ^
    -CAserial master.srl
    -extensions v3_req ^
    -extfile extensions.cnf ^
    -out cinema.crt
```

La commande `x509` est utilisée pour générer un certificat au format PKCS # 10.

`-CA` : certificat de l'autorité qui signe ce certificat\
`-CAkey` : clé privée de certificat d'autorité\
`-CAcreateserial` : fichier qui va contenir un identifiant de sérialisation, la prochaine fois utiliser l'option
`-CAserial` qui va incrémenter ce numéro de série.\
`-extfile` : fichier qui va contenir la configuration requise pour l'extension

Renvoyez le certificat sur le Raspberry

## Liste de contrôle

|application|commande|version|
|-|-|-|
|openssl|openssl version|1.1.1d

---

## Let's Encrypt

Let's Encrypt est une autorité de certification. Cette autorité fournit des certificats gratuits X.509 pour le protocole cryptographique TLS au moyen d'un processus automatisé. La durée des certificats est limité et son soumis à un contrôle de l'hébergement et du nom de domaine.

Installer le [paquet logiciel](/linux/paquet/) `certbot`.
