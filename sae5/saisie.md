---
title: 9. Saisie de l'offre produits et Catalogue d'offre en ligne (v2.+)
date: 2023-08-08T15:18:00+02:00
draft: false
---

A partir de la liste des produits et des abonnements paramétrés, la structure va saisir son offre produits, c'est-à-dire déclarer la liste des produits disponibles à la vente qui apparaîtront dans le catalogue d'offre en ligne.

Pour cela elle va déclarer une période de disponibilité du produit

Cette période est caractérisée par des dates calendaires : date de début et date de fin. Il est possible de déclarer une date de début sans déclarer de date de fin : auquel cas la disponibilité est illimitée, jusqu'à ce qu'une personne saisisse un jour une date de fin.

Du moment où un produit a une période de disponibilité future ou en cours de renseignée, le produit apparaît en front office dans le catalogue d'offre en ligne et peut être commandé. En revanche la période de disponibilité correspond à une périodicité de livraison : par ex si une période de disponibilité future démarre dans 15 jours, je peux commander dès à présent mais pour une livraison qui ne pourra démarrer que dans 15 jours.

Du moment où la date de fin est dépassée, le produit n'est plus visible ni proposé à la vente sur le site internet.

Pour cette offre produit, la structure va préciser également

- le nom du producteur avec sa localisation
- éventuellement la limite de quantité disponible
- le prix de vente HT et TTC et le taux de TVA, La case TVA renvoie la valeur prédéfinie dans les paramétrages, mais peut-être modifiée produit par produit. La saisie d'un prix de vente dans la case HT calcule mécaniquement le prix de vente TTC, et inversement.

- les modes de règlements et périodicités de règlements proposés pour ce produit ou cet abonnement  o éventuellement une ou plusieurs catégories de client à qui l'offre est réservée (cf. ci-dessous)
- éventuellement une catégorie de produit (cf. ci-dessous)
- éventuellement indiquer que la vente de ce produit ne nécessite pas d'adhésion à jour pour être vendu, via à une case à cocher (on peut envisager que certains produits puissent être vendus sans être conditionnés par l'existence d'une adhésion à jour, ex : cas de ventes ponctuelles, bons cadeaux etc.)
Un même produit (de même nom, unité, image, description), peut être proposé plusieurs fois à la vente, parfois même de manière simultanée, avec un ou plusieurs des éléments ci-dessus qui varient. Par exemple : on pourra saisir une vente de tomates au kg à un tarif client final accessible à tous, et une vente de tomates au kg à un tarif réduit pour les professionnels qui sera proposée seulement à la catégorie de clients « magasins bio ». Pour faciliter le travail de publication, prévoir un bouton « dupliquer une offre » pour modifier ensuite les quelques éléments qui varient.
Le fait de renseigner une catégorie de client à qui l'offre est réservée a pour effet de ne publier l'offre que dans l'espace client des clients qui appartiennent à cette catégorie. Cette offre n'apparaîtra donc pas sur le catalogue général de produits en front office.

Il y a donc un catalogue d'offre de produits en ligne, accessible et visible par tous en front office, et des catalogues d'offres privées, accessibles depuis les espaces clients, qui se constituent d'après le tag « catégorie client ».

Précision sur la quantité limite d'un produit : cela s'apparente à une gestion de stock. Lorsque la quantité limite est atteinte et que tous les produits de l'offre ont été vendus, l'offre n'est plus disponible ni affichée sur le site. Prévoir un message d'avertissement en back office lors de l'épuisement d'un produit (en lien avec « 5.7 Gestion des disponibilités / des stocks »).

Afin de permettre l'organisation du catalogue en ligne et prévoir le classement des produits, il faut probablement prévoir module de classement du catalogue. On pourrait imaginer que les structures créent des catégories de produits, puis choisissent une hiérarchisation.

Par ex : figure en Ier la catégorie abonnements, puis la catégorie légumes au détail, puis la catégorie autres produits. Chaque produit étant classé par ordre alphabétique au sein d'une même catégorie de produits.
On peut imaginer comme fonction avancée à long terme un système de mise en avant de certains produits dans le catalogue (mes favoris, les plus vendus, ventes flash etc.)

En back office on doit pouvoir obtenir une vue synthétique de l'offre actuellement en cours, et des offres privées par types de clients. On doit également pouvoir réaliser certains filtres ex : produits épuisés, ou offres dont la disponibilité termine entre le xx/xx/xxxx et le xx/xx/xxxx etc.

Enfin, il serait judicieux de pouvoir déterminer en back office — si le Jardin le souhaite — un montant minimum d' achat pour valider une commande. A définir pour le cas général et par catégorie de client (il arrive que certains clients professionnels soient soumis à un minimum de commande pour permettre une livraison sur leur structure).
