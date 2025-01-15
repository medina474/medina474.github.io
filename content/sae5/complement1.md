---
title: Compléments 1
date: 2023-08-08T15:18:00+02:00
draft: false
---

#### 3. Dépôts

##### Carte de géolocalisation

Prévoir une **géolocalisation automatique** des points de dépôts sur une carte interactive sur le site internet, qui renverra un certain nombre d'informations du point de dépôt par infobulle ou fiche PDD.

A partir du module de paramétrage des points de dépôts en back office, le site internet présentera une carte de géolocalisation des points de dépôts.

Celle-ci devra être développée également sur un outil libre, qui ne dépendra pas de licences diverses à renouveler.

Elle pourra être mise sur une page informative du site internet de la structure (pour consulter les points de dépôts), mais aussi proposée dans le parcours de commande au moment de choisir le point de livraison.

La carte doit être centrée de manière à ce que tous les points de dépôts soient visibles dans le cadre (zoom / dézoom possible ensuite).

###### Espace d'information

En cliquant sur l'indicateur d'un point de dépôt, un espace d'information s'ouvre sur le côté pour donner les informations du PDD (mais la carte générale est toujours visible pour zoomer ou cliquer sur un autre indicateur si besoin).

L'espace d'information indique le nom du lieu, son adresse, ses coordonnées téléphone, mail, site web le texte de présentation du lieu et la photo ou image du PDD, les jours et créneaux horaires de récupération des paniers un lien choisir ce point de dépôt en lien avec le parcours de commande.

#### 8. Produits

##### Renouvellement

Prévoir une fonctionnalité manuelle de renouvellement individuel ou collectif d'abonnement, afin de permettre les renouvellements un peu particuliers ou ceux qui n'ont pas la tacite reconduction d'activée.

Pour les abonnements qui n'utiliseraient pas la tacite reconduction, prévoir une case « alerte structure X semaines avant la fin de l'abonnement ». Cela permettra au Jardin de Cocagne d'être prévenu par cette alerte que certains abonnements arrivent en fin d'échéance et demandent une gestion spécifique (exemple : renouvellement manuel ou cas des abonnements période d'essai, qu'il faudra renouveler manuellement vers un autre type d'abonnement plus long).

##### Résiliation

La résiliation d'abonnement peut être faite à tout moment, et peut être programmée en avance, par les salariés de la structure depuis le back office. Elle peut être programmée en fonction du solde (s'il correspond à un nb de produits restants à recevoir sans générer de règlement supplémentaire), ou bien en fonction d'une date précise à indiquer (le solde sera donc modifié et restera donc à régulariser). La résiliation a pour effet d'annuler les produits prévus en livraison après l'échéance indiquée ainsi que les règlements programmés. Cela met à jour le solde qui reste à régulariser par un règlement.

Lors de cette opération de résiliation d'abonnement, l'outil doit vérifier sur l'ensemble du compte client s'il y a d'autres abonnements en cours ou à venir (ex : abonnement panier + œuf + fromage) et offrir la possibilité d'effectuer la résiliation sur tous les abonnements ou individuellement pour chacun des cas.
