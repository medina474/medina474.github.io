---
title: Compléments 2
date: 2023-08-08T15:18:00+02:00
draft: false
---

#### 3. Dépôts

##### Capacité d'accueil

Prévoir une case permettant de définir le nombre d'abonnements paniers maximum accueillis sur le point de dépôt. Cela induirait ensuite une fonction de vérification du nombre de places restantes pour valider une nouvelle inscription, et pourra définir un statut COMPLET de point de dépôt.

La capacité d'accueil doit être affichée dans l'espace d'information.

##### Export

Prévoir également une fonction d'export csv paramétrable des données des PDD, afin de permettre la réintégration dans d'autres outils si besoin (ex : sur une carte googlemaps ou openstreet d'un autre site internet).

##### Catégories

Prévoir 3 catégories de points de dépôts à choisir en menu déroulant :

###### PDD Ouvert à tous

ex : cas d'une boulangerie où n'importe qui peut se faire livrer un panier Ces PDD sont disponibles et affichés en tous lieux du front office.

###### PDD Réservé à un public spécifique

ex : cas d'un comité d' entreprise ou seuls les salariés de l'entreprise peuvent s'y faire livrer un panier Ces PDD sont affichés publiquement sur le front office mais indiquent une petite phrase « réservé aux texte personnalisable ». Ils sont proposés dans le parcours de commande, mais le choix de ce PDD est soumis à validation par un mot de passe.

En back office, sur les fiches PDD appartenant à cette catégorie, on doit avoir une case où écrire le texte personnalisable et une case avec le mot de passe (unique et modifiable).

L'information « Point dépôt réservé aux texte personnalisable » si c'est un PDD Réservé à un public spécifique

Cette information doit être affichée dans l'espace d'information.

###### PDD Professionnel

ex : cas d'une école qui commande des légumes pour sa cantine
En back office, sur les fiches PDD appartenant à cette catégorie, on doit pouvoir lier le lieu à une catégorie de client (cf. « 3.2 Clients »). En front office, ces PDD Professionnels n'apparaissent pas sur le site général, et n'apparaissent que dans le parcours de commande privé depuis les espaces clients des personnes appartenant à cette catégorie de client (cf. « 3.11 Parcours de Commande »).

Les catégories doivent s'afficher de manière différente sur la carte de localisation.

Sur la carte publique, ne doivent figurer que les PDD ouverts à tous et ceux réservés à un public spécifique (n'apparaissent pas les PDD professionnels). Dans les commandes des professionnels (catégories clients spécifiques), un onglet déroulant des PDD de leur catégorie sera suffisant si c'est plus simple.

Il serait pertinent que les indicateurs des points de dépôts puissent avoir une couleur différente : I couleur pour l'indicateur du PDD sur le site du Jardin de Cocagne, 1 couleur pour les PDD ouverts à tous, 1 couleur pour les PDD réservés à un public spécifique.

##### Congés

Un module de déclaration de fermeture temporaire d'un point de dépôt pour congés, avec indication de la période et de la structure provisoire remplaçante. Lors de la déclaration de cette fermeture temporaire, tous les éléments doivent changer automatiquement dans l'ensemble de la base de données sur les dates associées (fiche client, feuille de route .). Idéalement on devrait pouvoir paramétrer un envoi de mail automatique d'information et de relance à J-X jours paramétrables.


##### Frais de livraison

Certains dépôts font l'objet de frais de livraison (différents niveaux de frais de livraison paramétrables).

#### 5. Tournées de livraison

##### Livraison à domicile

Les Jardins peuvent proposer une livraison à domicile des paniers. Moyennant un coût supplémentaire, les adhérents peuvent demander à être livrés à leur domicile plutôt qu'en PDD. Le système doit pouvoir insérer dans les tournées des arrêts à domicile.


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


##### Gestion des dons des clients

Plusieurs systèmes de dons :

- au coup par coup
- dons de paniers
- abondement sur prix panier : ex 1€ de + pour abonder les paniers solidaires donc générer si demandé en fin d'année un reçu fiscal.

Les deux derniers ont un impact sur la gestion des paniers.
