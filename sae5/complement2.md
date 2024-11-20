---
title: Compléments 2
date: 2023-08-08T15:18:00+02:00
draft: false
---

#### 3. Dépôts



##### Export

Prévoir également une fonction d'export csv paramétrable des données des PDD, afin de permettre la réintégration dans d'autres outils si besoin (ex : sur une carte googlemaps ou openstreet d'un autre site internet).



##### Congés

Un module de déclaration de fermeture temporaire d'un point de dépôt pour congés, avec indication de la période et de la structure provisoire remplaçante. Lors de la déclaration de cette fermeture temporaire, tous les éléments doivent changer automatiquement dans l'ensemble de la base de données sur les dates associées (fiche client, feuille de route .). Idéalement on devrait pouvoir paramétrer un envoi de mail automatique d'information et de relance à J-X jours paramétrables.


##### Frais de livraison

Certains dépôts font l'objet de frais de livraison (différents niveaux de frais de livraison paramétrables).


#### 6. Adhérents

##### Bénévole

Ajouter un champ « bénévole » (case à cocher : « oui », non », « pourquoi pas » // et dans quel domaine (bricolage, tenue stand, vente, jardinage, cuisine, animation pédagogique. . . ) .
Ce champ doit permettre de faire ressortir des listes d'adhérents lorsqu'on lance des appels à bénévoles.

##### Salarié

Le salarié d'un Jardin est dispensé de cotisation. Suivant son statut il peut avoir le droit à un abonnement gratuit à un panier spécifique.

##### Les éléments relatifs à ses règlements :

- En particulier un pavé lié aux prélèvements, l'historique des règlements, les états des règlements, le solde en cours.
- Une ou plusieurs critères et zones de commentaires : son souhait de recevoir des SMS, son souhait de recevoir des e-mails…

Il faut donner la possibilité aux structures de créer différents types de clients via des catégories, ou tags par mots-clés (par ex : particuliers, AMAP, restauration collective, magasins, grossistes etc.). Cela permettra ensuite de personnaliser des offres (disponibilités produits, tarifs, lieu de livraison) par types de clients.

La fiche client doit mettre particulièrement en avant en synthèse 3 informations clés

- le type de client, si l'information est renseignée
- si l'adhésion est à jour ou non (réglée ou non réglée / en cours ou expirée), avec indication de la date d'expiration de la dernière adhésion renseignée.
- le solde du client

#### 7. Adhésion

Il existe 2 cas de figure de fonctionnement des adhésions sur les Jardins de Cocagne. Les paramétrages de l'outil doivent permettre de choisir l'une ou l'autre de ces options. Pour la v1.0 seul le premier cas est demandé.

###### 1er cas :

###### 2ème cas : adhésion valable pour 1 an à date anniversaire de l'inscription de la personne

Toute prise d'adhésion à un instant T est donc paramétrée pour 1 an.

Cela signifie que l'on appelle des renouvellements d'adhésions à tout moment de l'année. L'outil doit donc prévoir un système de listing qui permette de savoir de manière anticipée quelle adhésion arrive à échéance à quel moment, et donc quelles adhésions sont à appeler au renouvellement à quel moment.

Dans tous les cas, l'outil doit pouvoir proposer des filtres afin de sortir des listes des adhésions non réglées, expirées, les dispenses d'adhésion etc. mais aussi pouvoir filtrer les adhésions arrivant à expiration sur une périodicité spécifique demandée, ou même les adhésions à jour sur une période spécifique.

Les éléments relatifs à l'adhésion figurent sur chaque fiche client (cf. « 3.2 Clients »). L'enregistrement d'une adhésion peut être traité comme la commande d'un produit mais avec un système de suivi bien spécifique.

Les modes de règlements proposés sont les mêmes que pour les produits, à la nuance près que l'adhésion est payée en une fois. Elle peut être payée séparément, ou conjointement au paiement d'un produit ou d'un abonnement (ex : prélèvement de l'adhésion + 1 mois de paniers).

#### 8. Produits et abonnements

Lors de sa mise en vente (cf. « Saisie de l'offre produits et catalogue d'offre en ligne »), un produit est aussi caractérisé par :

- un nom de producteur avec sa localisation
- éventuellement une limite de quantité disponible
- une période d'offre, correspondant à une période de livraison possible (à définir par des dates de début / fin, ou option illimité)
- un prix de vente HT et TTC et un taux de TVA, La case TVA renvoie la valeur prédéfinie  dans les paramétrages, mais peut-être modifiée produit par produit. La saisie d'un prix de vente dans la case HT calcule mécaniquement le prix de vente TTC, et inversement.
- éventuellement une ou plusieurs catégories de client à qui l'offre est réservée
- éventuellement une catégorie de produit (cf. « 3.10 Saisie de l'offre produits et catalogue d'offre en ligne »)

On peut donc avoir un même produit (de même nom, unité, image, description) proposé à la vente sous plusieurs offres différentes, par exemple à 2 tarifs différents pour 2 catégories de clients différents. Offrir des facilités de duplication d'un produit à modifier ensuite pour faciliter la gestion  en back office.

Enfin, chaque produit peut être vendu au détail pour un achat et livraison unique, ou sous forme d'**abonnement** pour une régularité de livraison d'un même produit (selon le choix de la structure, à définir dans les paramétrages de l'offre produit).

##### Durée d'un abonnement

L'abonnement lié à un nombre de produits à recevoir** (v2.+)

La structure défini un nombre de produits à recevoir à partir de la date choisie par le client. L'abonnement prend à fin à échéance de l'ensemble des produits livrés. La période peut donc être variable selon la fréquence de livraison prédéfinie par la structure et les facilités éventuelles de reports permises par la structure.

##### Formes de souplesse dans les dates de livraison

Des formes de souplesse dans le calendrier de livraison sont parfois proposées aux clients afin de s'adapter à leurs absences.

Ainsi, pour chaque type d'abonnement, la structure doit pouvoir paramétrer les autorisations de modifications du calendrier de livraison qu'elle donne au client. Il existe les 2 cas suivants :

**1er cas : report de livraison du produit**

La structure offre la possibilité au client de modifier la semaine de livraison d'un produit prévu, aussi bien en anticipé avant la date prévue qu'en report après la date prévue. S'il y a déjà un produit de prévu en livraison sur cette semaine, le client en recevra donc 2. On parle alors d'un doublage.

Il doit être possible pour certains produits de définir des produits de doublage. Par exemple un panier simple doublé, devient un panier familial.

Dans le cas d'un abonnement lié à une période déterminée, le report de livraison du produit ne peut se faire que dans la période de l'abonnement (on ne peut pas le reporter après la fin de période).

Dans le cas d'un abonnement lié à un nombre de produits à recevoir, il n'y a pas à priori pas de contrainte de période, cela peut être reporté dans le temps après la fin du calendrier initialement prévu. En revanche la structure peut choisir ou non de déterminer un nombre maximum de produits qui peuvent être reportés.
Il faudra pouvoir paramétrer un délai minimal dans le back-office pour éviter une annulation 2H avant la confection des paniers.

**2ème cas : annulation de la livraison de produits**

Ce cas ne concerne que les abonnements liés à une période déterminée.
La structure offre la possibilité au client de supprimer une ou plusieurs livraisons de produits de son abonnement. La livraison et le produit sont tous simplement déprogrammés, ils ne seront donc pas facturés au client (impact sur le solde / les règlements initialement prévus).

Dans le paramétrage de cette option, la structure doit pouvoir définir si elle le souhaite un nombre maximum d'annulations autorisées par abonnement.

Chaque structure peut choisir, pour chacun de ses abonnements, de proposer l'une, l'autre, les 2, ou aucune de ces formes de souplesse.

Les modifications du calendrier de livraison (reports ou annulation de la livraison d'un produit) peuvent être faits soit par le client en front office depuis son espace client, soit par les salariés de la structure en back office depuis le calendrier de livraison prévu pour ce client. Lors de cette opération de déclaration d'absence, l'outil doit vérifier sur l'ensemble du compte client s'il y a d'autres livraisons de produits de prévues sur cette même semaine d'absence (ex : abonnement panier + œuf + fromage) et offrir la possibilité d'effectuer les reports / annulations pour tous les produits ou individuellement pour chacun des cas.

Il est possible également qu'un client demande à changer de jour de livraison dans la semaine (ex : changer la livraison prévue le mardi au vendredi, ce qui peut impliquer un changement de point de dépôt).




##### Paniers annulés, reportés

Fixer un nombre maxi de paniers annulés/reportés sur une période (ex : 3 paniers annulés/reportés maxi sur juillet et août). Mais l'adhérent peut faire une demande de « dérogation » si besoin de plus de 3 annulations : c'est alors l'admin, si d'accord, qui fait l'action d'annuler/reporter un 4ème, 5ème panier, en backoffice.

Le « doublage » des paniers doit pouvoir être contrôlé. ex : en été, nécessaire de répartir et étaler les paniers doublés, car impossible de doubler 50 paniers sur la dernière semaine d'août  par exemple. Si liberté donnée aux adhérents de choisir les semaines où ils souhaitent doubler leurs paniers, risque d'avoir des semaines avec énormément de paniers doublés => ingérable niveau maraîchage. Donc mettre un compteur qui bloc lorsque le nombre max de paniers doublés et atteint.

- Mais pour garder une marge de manœuvre et flexibilité, admin doit pouvoir agir et ajouter des doublés en backoffice, pour modifier le quota maxi.
- Lorsque I 'adhérent annule un panier, il doit donner une date de doublage obligatoirement pour compenser. Ou bien afficher un décompte (vous avez annulé 2 paniers cette année, et doublé 1 seul => vous avez un panier à doubler avant la fin de l'année)
- Fixer une date limite pour annuler/reporter/doubler un panier : définir le nombre de jours avant la livraison.

##### Gestion des paniers solidaires ou offerts

Certains clients ont des paniers payés X % du prix public de vente. Il conviendra de les gérer comme des paniers classiques avec un système de remises

Du coup le solde des remises sur une période donne la base pour facturer le Réseau, la MSA..  Ce système permet aussi de gérer des paniers ou produits offerts.

##### Changement de point de dépôt

L'ensemble des éléments de l'abonnement sont automatiquement programmés sur le même point de dépôt.

Néanmoins il est possible de changer de point de dépôt ponctuellement pour une date ou période précise, ou définitivement pour toute la fin de l'abonnement. Cela peut se faire en back office par les salariés de la structure ou en front office sur l'espace client par le client. Garder à l'esprit que certains PDD sont réservés à un public spécifique (la mention doit toujours apparaître + validation par mot de passe si ce type de PDD est choisi pour un changement).

Lors de cette opération de changement de PDD, l'outil doit vérifier sur l'ensemble du compte client s'il y a d'autres livraisons de produits de prévues sur ce PDD pour cette même date ou période (ex : abonnement panier + œuf + fromage) et offrir la possibilité d'effectuer les changements de point de dépôt pour tous les produits ou individuellement pour chacun des cas.



##### Gestion des dons des clients

Plusieurs systèmes de dons :

- au coup par coup
- dons de paniers
- abondement sur prix panier : ex 1€ de + pour abonder les paniers solidaires donc générer si demandé en fin d'année un reçu fiscal.

Les deux derniers ont un impact sur la gestion des paniers.
