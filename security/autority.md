---
title: "Autority"
---


## Création du certificat de l'autorité racine de confiance

La validation de l'identité repose sur un travail de l'autorité. Ce travail de notariat n'est pas gratuit. Et les certificats sont généralement assez chers.

Nous allons devenir nous même une autorité de confiance, mais sa reconnaissance sera limitée aux seules machines que nous possédons.

:warning: Attention : Apple ne permet pas d'ajouter des autorités sur iPhone, les certificats que nous validerons ne seront pas reconnus comme fiables sur ces appareils.

Le PC sera notre autorité. Télécharger [OpenSSL](https://wiki.openssl.org/index.php/Binaries) pour Windows. Choisir la version François Piette.

Créer un fichier de configuration appelé `master.cnf`
```
[req]
prompt = no
distinguished_name = dn

[dn]
CN = Lìcence Professionnelle AMIO   # Common Name / FQDN
emailAddress = emmanuel.medina@univ-lorraine.fr
O = Université de Lorraine          # Organization Name
OU = IUT de Saint-Dié des Vosges    # Organization Unit Name
L = Saint-Dié des Vosges            # Locality Name
C = FR                              # Country

[v3_ca]
subjectKeyIdentifier = hash
authorityKeyIdentifier = keyid:always,issuer
basicConstraints = critical, CA:true
keyUsage = critical, digitalSignature, cRLSign, keyCertSign
```

Rubrique `[req]` : propriétés de la requête

`prompt = no` : ne demande pas les informations par le clavier mais utilise les informations du fichier de configuration. Cette méthode est à préférer si on souhaite utiliser des caractères autres qu'ascii.\
`distinguished_name = dn` : rubrique du fichier de configuration à utiliser pour définir les informations du propriétaire du certificat.

Rubrique `[dn]` : Contient les informations du propriétaire du certificat : Le pays (Country), la ville (Locality), son nom, le détail de l'organisation (Organization).

Rubrique `[v3_ca]` : Contient les propriétés pour définir un certificat racine et définit la politique d'utilisation du certificat (keyUsage)

Générer le certificat de l'autorité (master.crt) racine ainsi que la clé privée associée (master.key)
```shell-session
$ openssl req -x509 -utf8 -newkey rsa:4096 ^
-keyout master.key ^
-config master.cnf ^
-extensions v3_ca -days 1826 ^
-out master.crt
```

La commande req est utilisée pour traiter les demandes de création de certificats au format PKCS # 10.

Nous l’utilisons ici pour créer un certificat auto-signé à utiliser comme autorité de certification racine.

`-x509` : Norme spécifiant le format du certificat. Nous l’utilisons ici pour générer un certificat auto-signé au lieu d'une demande de certificat.\
`-utf8` : Les valeurs seront encodées en UTF8, sinon elles le seront en ascii et aucun accent ne sera affiché correctement.\
`-newkey rsa:4096` : Génère la clé privée RSA (de longueur 4096 bits) en même temps que le certificat.\
`-keyout` : Nom du fichier pour écrire la clé privée nouvellement créée (ici master.key).\
`-config` : fichier de configuration à utiliser (ici master.cnf)\
`-extensions` : rubrique du fichier de configuration à prendre en compte lors de la création du certificat. (ici les extensions v3_ca)\
`-days` : Nombre de jours de validité du certificat. Nous définissons ici une validité de 5 ans.\
`-out` : Nom du fichier pour écrire le certificat.
