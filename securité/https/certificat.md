---
title: Certificat
---

Voir en préambule le chapitre sur la [Cryptographie](../cryptography/)

## Autorité

Créer un certificat d'[autorité](../autority/) ou récupérer <a href="autority.crt" download>directement</a> le certificat de l'autorité.

Installer le certificat racine pour chaque navigateur (Firefox, Chrome et Edge)

Firefox – Options – Vie privée et sécurité – Afficher les certificats – Importer le fichier master.crt – Choisir le paramètre de confiance : Ce certificat peut identifier des sites web.

Chrome utilise le magasin de Windows qui est utilisé aussi par Edge et toutes les applications Windows.

Chrome – Paramètres – Rechercher : certificats – Gérer les certificats – Choisir l’onglet Autorités de certification racines de confiance – Importer … - Choisir le magasin par défaut.

## Création du certificat pour localhost

### Générer une demande de certificat et la clé privée associée

Sur le Raspberry

```>shell
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
