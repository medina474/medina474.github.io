---
title: 10. Parcours de Commande
date: 2023-08-08T15:18:00+02:00
draft: false
---

Les commandes peuvent se faire via 4 accès différents

- sur le catalogue d'offre de produits en ligne : en front office en accès libre à tous
- sur le catalogue d'offres privées : en front office, en s'étant connecté sur son espace client (d'après sa catégorie client)
- en back office, en créant une nouvelle commande pour un nouveau client
- en back office, depuis la fiche du client concerné, en créant une nouvelle commande

La commande consiste en :

choisir le ou les produits commandés : « ajouter au panier »  choisir le lieu de livraison (point de dépôt) - n'est proposée que la carte / liste appropriée de PDD selon le parcours de commande (public ou privé) + à valider par le mot de passe si PDD Réservé à un public spécifique   choisir le jour de livraison s'il y a plusieurs options   choisir la date de livraison du produit ou la date de démarrage de l'abonnement   s'il s'agit d'un abonnement, choisir la fréquence de livraison du produit  choisir le mode de règlement et éventuellement sa fréquence

En cas de choix du prélèvement SEPA, saisir le nom du titulaire du compte, et les coordonnées IBAN / BIC   saisir les éléments nécessaires à la création de la fiche client (Nom et coordonnées diverses) OU saisir les identifiant et mot de passe pour associer la commande à un compte client existant   payer une adhésion à l'association, sauf s'il y a déjà une cotisation à jour ou une dispense d'adhésion pour ce client, ou si la commande est n'est constitué que de produits qui peuvent être vendus sans adhésion

Dans le cas d'une commande en front office depuis le catalogue général, une mention « déjà client ? » permet aux personnes de renseigner leur identifiant et leur mot de passe afin d'associer la commande à leur compte client.

Dans ce cas, ainsi que dans le cas d'une commande depuis un catalogue privé sur l'espace client et dans le cas d'une commande faite en back office depuis la fiche client, les coordonnées sont prérenseignées (nom, coordonnées du client, éléments de prélèvement SEPA). Ces coordonnées peuvent être modifiées, et les modifications seront enregistrées dans le compte client. L'outil vérifie également s'il y a bien une cotisation à jour ou une dispense d'adhésion pour ce client, sinon il indique qu'il est  nécessaire de régulariser l'adhésion pour que la commande puisse être validée (élément bloquant).

La fiche de commande récapitule enfin les coordonnées, le ou les produits choisis, le prix de chaque élément, le lieu de livraison et calendrier de livraison prévisionnel, les éventuels frais de livraison selon les points de dépôts choisis, le montant total, l'échéancier de règlement prévu selon le mode choisi.

Un message indique comment finaliser le règlement pour procéder à la validation de la commande, et un lien vers le terminal de paiement CB est proposé si c'est le mode de règlement qui a été choisi.

Après validation du formulaire, l'ensemble des éléments sont enregistrés automatiquement en back office (et dans l'espace client). Les règlements sont en l'état « à recevoir » et les produits sont en l'état « précommandé ».

Un email de récapitulatif de la commande est automatiquement envoyé par email avec les instructions  pour finaliser le règlement (nécessaire à la validation de la commande).

### Délais limites de commandes et de modifications

Il est nécessaire de cloisonner dans le fonctionnement du logiciel un certain nombre de délais limites concernant toute modification au niveau des commandes, ce dans le but de pouvoir fixer définitivement à un instant t la synthèse des commandes à préparer / livrer pour un jour J.

La structure doit ainsi pouvoir déclarer :

un délai limite (J-X jours) de modification de commande : blocage des reports / annulation de livraisons de produits, de changement de point de dépôt ou de jour de livraison, de suppression de la commande par résiliation à partir de X jours avant la date concernée   un délai limite (J-X jours) de validation de commande : lors du passage d'une commande de l'état « précommandé » à l'état « en préparation » (en général provoqué par la réception d'un règlement « à recevoir » qui passe à l'état « payé » cf. paragraphe ci-après), l'outil doit vérifier que le délai limite de validation de commande est respecté afin de permettre la préparation dans de bonnes conditions. Si cette validation de commande (= en général saisie de règlement) intervient trop tard par rapport à la date de préparation / livraison prévue initialement, alors l'outil va décaler automatiquement la préparation/livraison de la commande (ou le démarrage de l'abonnement) à la prochaine date possible selon les jours et lieux choisis par le client. Le client est automatiquement informé de ce changement par email.   un délai limite (J-X jours) de prise de commande : pour éviter que le cas ci-dessus de décalage de livraison se reproduise trop fréquemment, il est prudent de fixer un délai limite de commande un peu plus conséquent par rapport au jour de préparation / livraison prévu, ce afin de laisser le temps aux clients de nous faire parvenir le règlement. Ce délai impactera sur la première date proposée au client pour livraison lors du parcours de commande.

On peut éventuellement imaginer un délai de prise de commande différente en fonction des catégories clients (ex : un client professionnel payant en facture fin de mois peut à priori bénéficier d'un délai de prise de commande raccourci équivalent au délai limite de validation de commande).

### Etats de commande « précommandé, en préparation, livré »

Cas général du prépaiement des produits

La description ci-dessous n'est valable que dans le cas très majoritaire de prépaiement des produits (paiement en anticipé).

Une commande, ou un produit, peut avoir différents états :
- Précommandé : une commande a été passée mais le règlement est en état « à recevoir ». Rien ne se passe en attendant de recevoir le règlement.
- En préparation : le règlement a été reçu, il est passé de l'état « à recevoir » à l'état « programmé » ou « payé » (paiement CB validé sur le terminal, mandat de prélèvement SEPA signé reçu, autres modes de règlements reçus). Cela a pour effet de valider la commande, et envoyer un email de validation de la commande au client. L'état de la commande passe de « précommandé » à « en préparation ». Cela a pour effet de faire apparaître la commande dans la synthèse des commandes à préparer / livrer (cf. paragraphe ci-après). Rappel : au moment de la validation de la commande, l'outil vérifie que le délai nécessaire pour la préparation est respecté, décale automatiquement la date de livraison à la prochaine date possible. Cas particulier de l'abonnement : l'ensemble des produits constituant l'abonnement sont indiqués en préparation, sur toutes les semaines prévues.
- Livré : une fois que la livraison a été effectuée et déclarée en tant que telle (cf. paragraphe 3.14 ci-après), la commande passe à l'état livré. Cas particulier de l'abonnement : seuls les produits déjà livrés apparaissent comme « livrés », les autres restant à venir en livraison apparaissent toujours comme « en préparation ». La commande globale « abonnement » apparaît comme « en cours de livraison » du moment où au moins un produit de l'abonnement a été livré. Une fois que tous les produits de l'abonnement ont été livrés et que l'abonnement est terminé, celui-ci figure enfin comme « livré ».

#### Cas particulier du paiement à postériori

Les offres de vente qui proposent un paiement réalisé à postériori (ex : paiement fin de mois des commandes réalisées dans le mois) n'auront pas de statut « précommandé » ni de corrélation avec la réception des règlements. La validation du formulaire de commande aura pour effet de passer directement la commande en l'état « en préparation ».

Le passage à l'état livré est le même, soumis à la validation de la feuille de route.

Les règlements seront en état « à recevoir » jusqu'à réception du règlement, obtenu la plupart du temps sur présentation de facture. Si le client a choisi le mode de règlement par prélèvement SEPA et a déjà transmis le mandat de prélèvement signé, le règlement est en état « programmé ».
Ce cas de figure est relativement peu fréquent et est plutôt bien contrôlé. Il s'agit la plupart du temps des clients professionnels qui disposeront d'un catalogue privé.

Certaines structures, qui réservent les ventes au détail sur site aux abonnés paniers et ne souhaitent pas faire de gestion de caisse, pourraient également s'en servir pour prélever en fin de mois les achats réalisés au détail par les abonnés paniers (ex : Jardin du Limon à Vauhallan).
Note : il faut rendre possible la modification manuelle de l'état de commande, en cas de nécessité.


Pour rappel en front office on peut considérer qu'il y a 3 parcours de commandes possibles  :

- un parcours « nouveau client » depuis le catalogue public (qui va créer un compte client)
- un parcours « déjà client » depuis le catalogue public, qui va rattacher sa commande à son compte client
- un parcours « commande privée » depuis un catalogue privé sur l'espace client, pour une catégorie de clients bien spécifiques
