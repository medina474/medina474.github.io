---
title: HTTPS
---

**Secure Sockets Layer (SSL)**, et son successeur **Transport Layer Security (TLS)**, sont des protocoles de sécurisation des échanges sur Internet. Le protocole SSL a été développé à l'origine par Netscape. L'IETF (_Internet Engineering Task Force_) en a poursuivi le développement en le rebaptisant Transport Layer Security (TLS). On parle parfois de SSL pour désigner indifféremment SSL ou TLS.

## Protocole SSL

SSL 2.0 est la première version parue, elle possédait un certain nombre de défauts de sécurité, parmi lesquels la possibilité de forcer l'utilisation d'algorithmes de chiffrement plus faibles, ou bien une absence de protection pour la prise de contact et la possibilité pour un attaquant d'exécuter des attaques par troncature. Les protocoles PCT 1.0, puis SSL 3.0, furent développés pour résoudre la majeure partie de ces problèmes, SSL 3.0 devenant rapidement le protocole le plus populaire pour sécuriser les échanges sur Internet.

- **SSL 1.0**. Cette première spécification du protocole développé en 1994 par Netscape resta théorique et ne fut jamais mise en œuvre.
- La première version de SSL réellement utilisée est la **2.0** publiée en 1995. Elle fût également la première implémentation de SSL bannie, en 2011.
- Novembre 1996 : **SSL 3.0**, la dernière version de SSL, qui inspirera son successeur TLS. Ses spécifications sont rééditées en août 2008. Le protocole est banni en 2014, à la suite de la publication de la faille _POODLE_.

> Le SSL n’est théoriquement plus utilisé car toutes ses versions sont bannies, néanmoins le mot reste d’usage dans le langage courant.

## Missions

Le protocole SSL/TLS a plusieurs missions :

> Garantir la **confidentialité** des données échangées\
Assurer l'**intégrité** de ces données\
**Authentifier** le serveur\
Optionnellement authentifier le client via l'utilisation d'un certificat numérique
{: .objectif}

Le protocole SSL crée un canal de communication entre le client et le serveur **indépendamment du protocole** utilisé, il sécurise ainsi les transactions sur le web (protocole HTTP) ou les connexions via protocole FTP, IMAP ou POP, etc...

Ce canal de communication est un **tunnel opaque** qui empêche quiconque de voir ce qui y transite.

Il fonctionne sur l'établissement de clés privées et publiques qui s'apparentent à l'utilisation d'une serrure et de sa clé :
- La clé privée est enregistrée sur le serveur et connue de lui seul.
- La clé publique, connue de tous, chiffre les données à envoyer, qui, une fois réceptionnées par le serveur, sont décryptées au moyen de la clé privée.
- La clé publique est authentifiée par une **autorité de certification** par le biais du certificat.

## Fonctionnement

Pour communiquer de manière sécurisée il faut chiffrer les messages. Dans le cas d'un serveur web, nous avons des millions de personnes qui veulent communiquer avec un serveur.

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

## Travaux pratiques

[Travaux pratiques](travaux-pratiques)

### Définitions

TLS
: Transport Layer Security

CA
: Certificate Authority ou Autorité de certification. Agence notariale reconnue pour son honnêteté et sa rigueur.

CSR
: Certificate Signing Request. C'est un fichier de demande de certificat. Il est envoyé aux autorités de certification. Cette demande signée par l'autorité revient sous forme de certificat.

.key
: Fichier pem contenant uniquement la clé privée.

https://chiffrer.info/
