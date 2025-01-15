---
title: Cahier des charges
date: 2023-08-08T15:18:00+02:00
draft: false
---

> **À noter :** Ce document est un cahier des charges original donné par une structure nationale en vue de développer un système complet de gestion. Il vous expose à une mise en situation réelle. Il ne définit pas les priorités de développement, ni le rendu attendu pour cette situation d'apprentissage et d'évaluation. Quelques références au logiciel Dolibarr sont présentes dans ce document. Cette solution n'est finalement pas retenue et doit être ignorée.
{.definition }

#### Objectifs du document

Ce document représente un cahier des charges pour la réalisation du futur logiciel de **gestion commerciale** des Jardins de Cocagne.

Il doit servir de base à la rédaction d'une **proposition technique et financière** de développement et de déploiement de ce logiciel.

Ce projet doit répondre à 2 enjeux majeurs pour le Réseau et les Jardins de Cocagne.

- doter les jardins de cocagne d'un outil qui favorise le développement de leur activité économique mais aussi à terme les relations avec leur communauté d'adhérents et de partenaires économiques,
- constituer un projet co-pensé et co-construit par les jardins de cocagne et non pensé par la tête de réseau au bénéfice de ses membres.

### 1. Structure

Un module de paramétrage initial doit permettre de saisir les données de la structure utilisatrice :

- Logo de la structure
- Nom commercial
- Raison sociale
- Siège social
- Adresse de gestion
- Coordonnées commerciales : téléphone, mail, nom éventuel de la personne de contact, site web
- N° de SIRET
- Coordonnées bancaires de la structure : BIC, IBAN, n° ICS
- Une case à cocher « structure assujettie / non assujettie à la TVA »

#### Quelques structures

- [Jardins de Cocagne de Thaon-les-Vosges](https://thaonlesvosges.fr/ville-au-quotidien/emploi/les-structures-de-linsertion-par-lactivite-economique/les-jardins-de-cocagne/)
- [Le jardin de Cocagne Angevin](https://www.jardin-cocagne-angers.org/)
- [Les potagers de Velles](https://www.solidariteaccueil.org/les-potagers-de-velles)

### 2. Calendrier

La structure doit définir de manière générale son calendrier livrable c'est-à-dire les jours et semaines où des livraisons sont possibles.

Les jours possibles de livraison dans la semaine sont définis d'après les jours de livraison des points de dépôts. (cf. partie suivante)

La structure doit pouvoir définir, de manière globale les **semaines non livrables**, à décocher sur un calendrier (cela revient à exclure les semaines de fermeture de la structure)

Ces éléments auront une incidence sur le parcours de commande (dates proposées en livraison), le paramétrage des abonnements et l'information des dates de livraison des produits, les récaps de commandes et feuilles de routes.

#### Jours fériés

La prise en compte des **jours fériés** auront pour incidence de **décaler** la livraison sur un jour inhabituel de la même semaine (ex : mardi 8 mai férié, livraison décalée au mercredi 9 mai). Cette déclaration des décalages de livraison doit s'aborder jour férié par jour férié, et idéalement par tournée de livraison (exemple pour 2 tournées prévues les mardis, l'une pourrait être décalée au lundi et l'autre au mercredi pour des raisons d'organisation).

### 3. Dépôts

> Les points de dépôts (PDD) sont des lieux de livraison des produits commandés. Ils regroupent la plupart du temps plusieurs commandes, que les clients viennent chercher à cet endroit à un **jour** et **créneau horaire** précis.
{.definition}

Une fiche point de dépôt comprend :

- Boutons Créer, Enregistrer, Fermer, Supprimer, Archiver
- N° identifiant créé automatiquement (numéro unique, non modifiable)
- Identifiant de tournée et no d'ordre de livraison dans la tournée (cf. « [Tournée de livraison](#5-tournées-de-livraison) »).
- Nom du point de dépôt, adresse, code postal, ville, no de téléphone n° obligatoire pour l'enregistrement de la fiche
- Mail générique de la structure, site web de la structure (facultatif)
- Nom de la personne référente + mail + téléphone spécifique de la personne référente
- On doit pouvoir préciser le jour de livraison de ce point de dépôt (incidence sur la commande et la feuille de route), le créneau horaire de livraison (information interne) et les créneaux horaires de récupération des paniers (apparaîtront en front office).
- Une zone de texte libre de présentation du lieu et le téléchargement possible d'une photo ou image du lieu.
- Prévoir une case de texte libre pour noter des commentaires.

#### Capacité d'accueil

Prévoir une case permettant de définir le nombre d'abonnements paniers maximum accueillis sur le point de dépôt. Cela induirait ensuite une fonction de vérification du nombre de places restantes pour valider une nouvelle inscription, et pourra définir un statut COMPLET de point de dépôt.

La capacité d'accueil doit être affichée dans l'espace d'information.

#### Catégories

Prévoir 3 catégories de points de dépôts à choisir en menu déroulant :

##### PDD Ouvert à tous

ex : cas d'une boulangerie où n'importe qui peut se faire livrer un panier Ces PDD sont disponibles et affichés en tous lieux du front office.

##### PDD Réservé à un public spécifique

ex : cas d'un comité d' entreprise ou seuls les salariés de l'entreprise peuvent s'y faire livrer un panier Ces PDD sont affichés publiquement sur le front office mais indiquent une petite phrase « réservé aux ... (texte personnalisable) ». Ils sont proposés dans le parcours de commande, mais le choix de ce PDD est soumis à validation par un mot de passe.

En back office, sur les fiches PDD appartenant à cette catégorie, on doit avoir une case où écrire le texte personnalisable et une case avec le mot de passe (unique et modifiable).

L'information « Point dépôt réservé aux texte personnalisable » si c'est un PDD Réservé à un public spécifique

Cette information doit être affichée dans l'espace d'information.

##### PDD Professionnel

ex : cas d'une école qui commande des légumes pour sa cantine
En back office, sur les fiches PDD appartenant à cette catégorie, on doit pouvoir lier le lieu à une catégorie de client (cf. « 3.2 Clients »). En front office, ces PDD Professionnels n'apparaissent pas sur le site général, et n'apparaissent que dans le parcours de commande privé depuis les espaces clients des personnes appartenant à cette catégorie de client (cf. « 3.11 Parcours de Commande »).

Les catégories doivent s'afficher de manière différente sur la carte de localisation.

Sur la carte publique, ne doivent figurer que les PDD ouverts à tous et ceux réservés à un public spécifique (n'apparaissent pas les PDD professionnels). Dans les commandes des professionnels (catégories clients spécifiques), un onglet déroulant des PDD de leur catégorie sera suffisant si c'est plus simple.

Il serait pertinent que les indicateurs des points de dépôts puissent avoir une couleur différente : I couleur pour l'indicateur du PDD sur le site du Jardin de Cocagne, 1 couleur pour les PDD ouverts à tous, 1 couleur pour les PDD réservés à un public spécifique.

### 4. Jours de préparation

Les jours de préparation sont des jours pendant lesquels tous les paniers appartenant à une ou plusieurs tournées sont préparés.


### 5. Tournées de livraison

Les points de dépôts sont livrés dans des **tournées de livraison**.

Une tournée de livraison est définie par :

- un identifiant de tournée qui doit pouvoir être personnalisable (chiffre ex : 1, 2, 3 ; ou lettre ex : tournée Ma ou V pour Mardi ou Vendredi, ou tournées BLR ou MTR pour Beaune la Rolande ou Montrouge.)
- un jour de livraison
- une **succession ordonnées** de points de dépôts, définie grâce à un n° d'ordre de livraison dans la tournée, donner la possibilité de définir une couleur pour une tournée (la couleur a pour incidence de coloriser les PDD dans la partie gestion des PDD et synthèse des commandes à préparer et livrer / feuilles de route)

#### Livraison à domicile

Les Jardins peuvent proposer une livraison à domicile des paniers. Moyennant un coût supplémentaire, les adhérents peuvent demander à être livrés à leur domicile plutôt qu'en PDD. Le système doit pouvoir insérer dans les tournées des arrêts à domicile.

##### Module de visualisation

Il faudrait prévoir un module de visualisation des tournées facilitant leur (ré)organisation. Ex : liste globale des PDD organisée par identifiant de tournée puis ordre de livraison, et prévoir une facilité pour les reclasser (changer l'ordre de livraison d'une tournée, changer un PDD de tournée.)

Un même point de dépôt peut appartenir à 2 tournées différentes, dans le cas où un même site propose 2 créneaux différents de livraison / récupération de paniers dans la semaine. Le client choisi un des 2 créneaux de livraison. A voir comment cette double appartenance sera gérée informatiquement (sélection du point de dépôt puis du jour 2).


### 6. Adhérents

Un client peut être une personne physique ou morale.

La fiche client comporte :

##### les éléments relatifs à son identité.

- N° identifiant créé automatiquement (numéro unique, non modifiable)
- Raison sociale (en cas de personne morale)
- Civilité (Mr / Mme...). Prévoir un onglet déroulant avec le contenu paramétrable dans les initialisations
- Nom, Prénom, Adresse, Code Postal, Ville, n° téléphone, mail. Rendre ces éléments obligatoires pour l'enregistrement de la fiche.
- 2ème et 3ème case de téléphone, Profession, date de naissance. Éléments facultatifs pour l'enregistrement de la fiche
- Mot de passe d'accès à son espace client « Mon compte » (créé automatiquement mais modifiable)

##### Les éléments relatifs à son adhésion

(cf. paragraphe 7)

- Date de 1ère adhésion,
- Historique des adhésions avec leur période et le type d'adhésion.
- Élément indiquant si l'adhésion est à jour ou non (réglée ou non réglée / en cours ou expirée), avec indication de la date d'expiration de la dernière adhésion.
- Une case « dispensé d'adhésion » à cocher, pour le cas de clients professionnels à qui l'on ne demande pas d'adhésion.

Pour le reste confer le paragraphe 7

##### Les éléments relatifs à ses différentes commandes de produits ou d'abonnements

- Les commandes doivent pouvoir être réalisées, modifiées, ou visualisées depuis la fiche client. L'historique des commandes doit être présent, avec l'information du point de dépôt et les frais de livraison éventuellement associés, et un accès aux bons de livraisons et aux factures.

> Note : Il se peut qu'un client ait plusieurs abonnements en même temps (pas de limite de nombre).

Pour le reste confer le paragraphe 8

##### Espace client « Mon compte »

Le client pourra accéder à un espace client appelé « Mon compte », sur lequel il pourra consulter :

- Ses coordonnées personnelles
- Ses coordonnées bancaires (prélèvement SEPA)
- Ses commandes en cours, avec calendrier et lieux de livraison prévus
- L'historique de ses commandes, de ses livraisons reçues et ses factures
- Le suivi de ses règlements effectués, les règlements prévisionnels programmés ou à recevoir, l'état de son solde
- En cas d'abonnement panier : la composition de son prochain panier à venir. L'affichage sera personnalisé grâce au module décrit en « Composition des paniers ».
- En cas d'abonnement panier : Les feuilles de chou de son panier (affichage ciblé selon son type de panier et tournée de livraison). Cf. « Modèles pour publipostage »
- En cas de client appartenant à une catégorie spécifique : le catalogue d'offre privée

Depuis cet espace, il pourra :

- Renseigner / Modifier ses coordonnées personnelles
- Renseigner / Modifier ses coordonnées bancaires (prélèvement)
- Déclarer une absence reporter ou annuler un produit selon l'option configurée par le Jardin de Cocagne
- Modifier son point de dépôt ponctuellement pour une livraison, ou définitivement pour toutes les livraisons d'un abonnement
- Modifier le jour de livraison de son abonnement (ponctuellement ou définitivement)
- Télécharger les factures relatives à ses commandes (v2.+)
- Effectuer un règlement de régularisation par carte bancaire ou par ordre de prélèvement  (v2.+)
- Télécharger les feuilles de chou de son panier  (v2.+)
- Effectuer une commande depuis le catalogue d'offre privée

Le module gestion des utilisateurs : il devra permettre de gérer un annuaire avec des profils de droits (ou groupes). Il serait souhaitable de ne pas distinguer des adhérents, de clients ou d'utilisateurs mais avoir un outil puissant de gestion des permissions.

### 7. Adhésions

Il sera nécessaire de distinguer l'adhésion à l'abonnement panier et l'adhésion à l'association Jardin de Cocagne avec la possibilité de lier automatiquement les deux dans le paramétrage de la structure.

Les deux sont liés, un adhérent panier est obligatoirement adhérent de l'association (l'inverse n'est pas vrai)

Un adhérent sans panier est appelé un **soutien**. Il devra être dans la liste des personnes convoquées aux assemblées générales de l'association.

###### 7.1 Adhésion à l'association

> A noter que c'est cette adhésion qui est la base pour calculer une partie de la cotisation annuelle que reverse le jardin au Réseau national.

Dans le cas des Jardins de Cocagne sous statut associatif (98 % des jardins), l'adhésion est obligatoire pour pouvoir accéder aux services et à la vente des produits de l'association. Tout client doit avant tout être adhérent, sauf cas particulier de clients professionnels à qui l'on ne demanderait pas d'adhésion (cf. case « dispensé d'adhésion » prévue sur la fiche client).

On peut proposer différents types d'adhésion à des prix différents (exemple Adhésion soutien, Adhésion solidaire… ) qui doivent être paramétrables dans l'outil : libellé + montant (boutons Créer, Enregistrer, Fermer, Supprimer, Archiver).

Adhésion valable sur une périodicité fixe déterminée par le Jardin

La périodicité doit être paramétrable dans l'outil. ex : année civile 01/01 au 31/12, ou bien du 01/04 au 31/03.

En général, une adhésion prise en cours de période est facturée à plein tarif, et est valable jusqu'à la fin de la période en cours.

Sauf cas particuliers

- Certains Jardins utilisent la notion de "date charnière" à paramétrer : c'est la date à partir de laquelle l'adhésion payée va jusqu'à la fin de la période suivante. Ex : si périodicité adhésion 01/01-31/12, et date charnière au 01/10 alors une inscription entre le 01/10 et le 31/12 année N sera valable jusqu'au 31/12 N+l.
- D'autres Jardins font une cotisation dégressive au trimestre en fonction de la période d'inscription de l'adhérent.

Les renouvellements d'adhésions sont tous appelés en même temps, avant la fin de la périodicité fixe.

###### 7.2 Adhésion au panier

Confer les abonnements aux produits


### 8. Produits et abonnements

Les produits sont les différentes unités élémentaires qui peuvent être vendues. Cela peut être :

- des produits alimentaires (légumes, fruits, pain, œuf . . qui disposeront chacun d'une unité appropriée (pièce, kg, botte, filet, boîte, bouteille, colis)
- des lots composés de différents produits (ex : petit ou grand panier légumes, panier fruits, panier fermier . ou encore « composition ratatouille », « composition pot au feu » .
- des produits non alimentaires, matériels ou immatériels (ex : agenda, ecocup, adhésion, bon cadeau . . .)

Chaque produit dispose à minima d'un nom et d'une unité, et éventuellement d'une photo ou image et d'une description.


##### Abonnements / Panier

Un abonnement est un pack de vente d'un même produit livré régulièrement. Les abonnements peuvent concerner tous les types de produits : aussi bien les produits élémentaires (ex : abonnement boîtes d'œufs), que les lots de produits (ex : abonnement au panier fermier). C'est à la structure de déterminer les abonnements qu'elle propose.

##### Durée d'un abonnement

L'abonnement lié à une période déterminée

La structure définit la période type de l'abonnement grâce à des calendriers (ex : sur l'année civile, par trimestre, de Mai à Octobre. ..). Tout abonnement pris est paramétré jusqu'à la fin de la période. Un abonnement peut être démarré en cours de période et va jusqu'à la fin de la période, un calcul est donc fait sur le nombre de produits restant à recevoir d'ici la fin de la période.


##### Dates et fréquence de livraison

Avant tout, le paramétrage des abonnements prendra compte des éléments déclarés dans le calendrier « livrable » (cf. 3.6 : semaines non livrables en général et jours fériés).

Par ailleurs, pour chaque type d'abonnement, la structure doit pouvoir paramétrer :

- les semaines livrables pour cet abonnement, à cocher / décocher sur un calendrier, en fonction des semaines de disponibilité ou d'indisponibilité du produit (ex : paniers fruits de Mai à Octobre, ou période creuse 2 mois sans fromages)
- la ou les fréquences types proposées pour cet abonnement (hebdomadaire, tous les 15 jours semaines paires ou impaires, 1 fois par mois ...). Plusieurs fréquences peuvent être proposées au choix du client.

Les échéances de livraison pour un client seront donc préprogrammées d'après les éléments ci-dessus proposés par la structure et le choix éventuel fait par le client.

Il faut pouvoir ajuster les semaines de livraison par abonnements, mais aussi par tournées de livraison ou dépôts. En effet pour lisser la charge de travail et la production de légumes, les abonnements mensuels ne seront pas tous distribués la même semaine à tous les adhérents. Pour un même abonnement il existera un décalage de livraison.


##### Démarrage, renouvellement et résiliation d'abonnement

Le démarrage d'abonnement peut se faire à tout moment. La date de démarrage peut être choisie et programmée en avance.

L'abonnement est programmé d'après les conditions de paramétrages définies par la structure (durée de l'abonnement, calendrier livrable, fréquence de livraison, modes de règlements, échéances de règlements etc.) et les options prises par le client parmi les choix proposés lors du parcours de commande (fréquence de livraison, jour de livraison, point de dépôt, mode de règlement et fréquence etc.).

Lors du paramétrage des différents types d'abonnements, il doit être possible de cocher une case « tacite reconduction », et de renseigner une case « renouvellement et information client X semaines  avant la fin de l'abonnement » (X étant personnalisable).

Dans ce cas de figure, pour chaque client disposant de tels abonnements reconductibles, à la date X en question l'abonnement doit être reproduit à la suite de l'abonnement en cours, à l'identique selon ses paramètres types (produit, point de dépôt, fréquence et jour de livraison, mode de règlement et fréquence etc.). Il prend en compte les changements définitifs ayant eu lieu en cours d'abonnement  (point de dépôts, jour de livraison, mode de règlement et fréquence) mais ne reproduit pas les changements ponctuels demandés (point dépôt, report ou annulation de la livraison de produits).

Si le règlement est le prélèvement SEPA l'abonnement est automatiquement validé.

Quid gestion du solde en fin d'abonnement ? On doit pouvoir choisir de repartir à 0 ou conserver ce solde (globalement à la création du type d'abonnement ou abonné par abonné ?)

Pour les autres modes de règlements, l'abonnement est en précommande et le jardin attend validation par un règlement.

Il est souhaitable que l'on puisse paramétrer l'élément déclencheur du démarrage de l'abonnement  solde positif ou réception du contrat voire rien puisque certains jardins livrent le 1 er panier avec dedans le contrat d'abonnement et les documents à retourner.

En parallèle, un email automatique est envoyé informant le client de la tacite reconduction de son abonnement et des démarches éventuelles de règlements à effectuer. Cet email prévoit différents types de mail en fonction du mode de règlement du client.

Prévoir module puissant de paramétrage de mails (signatures, formules type...)

Si une résiliation a été programmée pour cet abonnement (pour avant ou pour le jour de la fin de l'abonnement), alors l'abonnement n'est pas renouvelé.

##### Composition des paniers

Après la préparation des paniers, on veut suivre ce qui a été mis dans les paniers c'est à dire les légumes vendus.

A terme, il pourra être envisagé un outil qui aide à préparer la livraison en aidant l'encadrant à calculer les besoins en légumes mais aussi à communiquer (sous toutes réserves!) aux adhérents une composition prévisionnelle de paniers.
Par contre, il n'est pas souhaité une fonction de choix de la compo du panier par le client.

Un module doit pouvoir permettre, chaque semaine, d'aller renseigner les compositions des paniers de la semaine pour les clients qui sont abonnés aux paniers. Sur une même tournée, la composition est différente d'un type de panier à un autre, et peut aussi être différente d'une tournée à une autre (ex : composition du petit panier différente le Mardi et le Vendredi).

La composition d'un panier est caractérisée par :

- un type de panier, un no de tournée et un no de semaine
- une liste de légumes avec les quantités prévues et une unité pour chaque ligne (kg, botte, pièce etc.)
- le prix unitaire des légumes (prix au kg, à la botte, à la pièce etc.)
- le prix légumes mis en panier : détail pour chaque ligne (= prix unitaire * quantité prévue) et le prix total de légumes mis en panier (= la somme du détail de chaque ligne).

Pour faciliter la saisie des compos de paniers (qui se ressemblent souvent), prévoir une fonction « dupliquer », pour apporter ensuite juste des modifications mineures.

Dans un premier temps, cette composition serait exploitée pour publication :

- Sur l'espace client des personnes abonnées au panier : ne s'affiche de la composition de son panier (d'après le type de panier, no de tournée auquel il appartient)
- Par envoi d'email aux personnes recevant un panier cette semaine (idem ne s'affiche que la composition de son panier)
- Par publipostage pour édition de la feuille de chou
- Éventuellement sur le site internet ou réseaux sociaux. Le Jardin doit pouvoir choisir quel type de publication il souhaite mettre en place ou non, et quels éléments sont publiés (seulement la liste des légumes, avec les grammages prévus ou non, avec les tarifs unitaires légumes ou non etc.)
Dans les évolutions à long terme on pourrait imaginer .
- Pouvoir consulter le récap successif semaines après semaines des compositions de paniers (ordonnés par type et no de tournée).
- Pouvoir suivre dans le temps le prix total légumes mis en panier semaines après semaines (afin d'encadrer les variations et être au plus près en fin d'année)
- Pouvoir alimenter la variation des stocks d'après le nombre de panier préparés et leur composition, ou éventuellement calculer les quantités de récoltes à effectuer pour honorer ces  paniers (cf. paragraphe suivant)
