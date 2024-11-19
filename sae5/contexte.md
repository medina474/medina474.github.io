---
title: Contexte et cadre du projet
date: 2023-08-08T15:18:00+02:00
draft: false
---

#### Les Jardins de Cocagne

Les Jardins de Cocagne sont des exploitations maraîchères en **agriculture biologique** dont la vocation est de proposer des **parcours d'insertion socio-professionnelle** à des personnes éloignées de l'emploi. La majorité de ces structures sont des **associations loi 1901** avec un conventionnement **Atelier et Chantier d'Insertion**. Un Jardin de Cocagne accueille en moyenne 22 salariés en parcours d'insertion pour des durées variables de 1 à 24 mois, le support de travail étant le maraîchage biologique.

Les Jardins de Cocagne cultivent en moyenne 70 à 80 variétés de légumes et les commercialisent majoritairement sous forme d'**abonnement à des paniers** de légumes hebdomadaires auprès d'**adhérents-consommateurs**. Les autres modes de ventes peuvent être la vente au détail (sur site, marché de plein vent, sur commande) ou la vente auprès de professionnels (restauration collective, magasins, confrères, grossistes . . .). Ils peuvent parfois vendre d'autres produits que des légumes, et faire un peu d'achat-revente. Certains Jardins de Cocagne ont mis en place des activités de diversification sur leur structure (ateliers de transformation, animations pédagogiques, prestations espaces verts etc.).

#### Le Réseau Cocagne

Il existe près d'une centaine de Jardins de Cocagne dans toute la France, qui adhèrent au Réseau Cocagne, le réseau national des Jardins de Cocagne et Entreprises Solidaires Cocagne. Le Réseau Cocagne a une fonction d'appui à la professionnalisation et à la mutualisation entre les Jardins de Cocagne. Dans ce cadre, le Réseau Cocagne peut être amené à animer des groupes de travaux collectifs, ou proposer des **outils mutualisés** pour répondre aux besoins du plus grand nombre. Hormis le partage de valeurs à travers la charte nationale du Réseau Cocagne, il n'existe pas de lien de subordination entre le Réseau Cocagne et les Jardins de Cocagne. Les Jardins de Cocagne sont donc libres de participer ou non aux travaux collectifs ou de choisir d'utiliser ou non les outils mutualisés qui sont proposés.

Plus d'informations sur [https://www.reseaucocagne.org/](https://www.reseaucocagne.org/)

#### Logiciel préexistant

Dans les années 2000, un logiciel dit de « gestion des adhérents » a été conçu par un directeur de Jardin de Cocagne sur une base Microsoft Access. Ses fonctionnalités principales sont la gestion des adhérents, des abonnements aux paniers et des règlements associés, l'édition de feuilles de route pour la préparation et la livraison des paniers. Un export de données vers un logiciel de comptabilité est possible.

Cet outil était encore utilisé en juin 2016 par 65% des Jardins de Cocagne. Il répond assez bien aux besoins de base en termes de gestion d'abonnement aux paniers, mais les formules commerciales et le contexte ont fortement évolué, nécessitant à présent une modernisation de l'outil (internet, automatisation des processus, ouverture des modes de ventes).

> A ce jour 75% des Jardins de Cocagne ont manifesté un **besoin urgent** de développer un nouvel outil de gestion commerciale.

#### Quelques caractéristiques attendues du futur logiciel

##### Back Office et Front Office

Le projet vise à créer un nouvel outil de gestion commerciale qui sera utilisé par les Jardins de Cocagne. Cet outil sera composé d'un back office pour effectuer la gestion, et d'un front office permettant aux clients-abonnés paniers de réaliser différentes opérations. L'idée est d'autonomiser les clients sur certaines actions, et d'automatiser un maximum de tâches afin de simplifier la gestion administrative et dégager du temps pour des relations et de l'animation.

##### Paramétrage

**La complexité du projet réside dans la très grande diversité des modes de fonctionnements des Jardins de Cocagne.** L'outil créé devra donc posséder un **très haut niveau de paramétrage** possible pour pouvoir s'adapter au fonctionnement de chaque Jardin de Cocagne.

##### Les utilisateurs du futur logiciel

Pour le BackOffice, ils peuvent être soit salariés permanents des Jardins de Cocagne, soit salariés en parcours d'insertion voire bénévoles. Leur niveau de maîtrise des processus et des outils informatiques est donc très variable.

Il faut donc partir du principe que les utilisateurs du logiciel sont souvent **très peu qualifiés** et peu à l'aise avec l'outil informatique, avec un turn-over important sur leurs fonctions. Le nouvel outil devra donc être simple d'utilisation, avec une interface conviviale, intuitive et didactique permettant une compréhension facile et rapide.

En ce sens, il faudra développer des outils simples, d'infos bulles explicatives dans l'outil, de mode d'emploi ou d'aide en ligne, par exemple avec des tutoriels videos en ligne afin d'optimiser la prise en main.

##### Open source, hébergement, liens avec sites web existants

Le Réseau Cocagne tient à ce que le futur logiciel soit libre (Open Source), qu'il soit souple et évolutif (en mode SAAS).

Nous imaginons une base commune nationale avec un hébergement centralisé et sécurisé, et une déclinaison **multi société** de l'outil, que chaque Jardin pourra individualiser (les données restent la propriété du Jardin). Nous souhaitons un fonctionnement avec plusieurs modules et fonctionnalités, qui seront activés ou non par les Jardins de Cocagne selon leur choix.

L'idée est de développer la base principale de l'outil via un prestataire, mais nous souhaitons que les Jardins de Cocagne puissent à terme développer eux-mêmes des modules ou fonctions complémentaires d'après leurs besoins, qui bénéficieront à tous. **La simplicité du langage de développement** (exemple php) sera donc également un critère de choix. Il sera nécessaire de prévoir des outils explicatifs sur le mode de fonctionnement technique du nouveau logiciel (schéma ou modèle de données expliqué, commentaires, aide, transfert de compétences éventuel) afin que des développeurs bénévoles issus des Jardins puissent facilement aborder l'outil pour participer au développement de nouvelles améliorations.

Lors de nos études prospectives, nous avons identifié *Dolibarr* comme ERP qui pourrait répondre à nos besoins. Nous restons évidemment ouverts à d'autres propositions notamment des logiciels existants de gestion de paniers à faire évoluer au vue de nos besoins exprimés dans le présent cahier des charges.

##### Hébergement application et données

Il est envisagé un **hébergement centralisé** des données et programmes sur des serveurs administrés par le prestataire.

Les mises à jour du programme seront ainsi facilitées.

#### Vocabulaire

Dans ce cahier des charges le langage est simplifié pour clarifier les processus et élargir les possibilités de fonctionnement de l'outil.

Habituellement les adhérents-consommateurs du Jardins de Cocagne (abonnés aux paniers ou achat détail au marché) sont appelés les **adhérents** ; les autres types de ventes réalisées auprès clients de professionnels sont distingués.

Or, dans ce cahier des charges on utilisera le terme **« client »** au sens large, pour toute personne physique ou morale qui va faire un acte d'achat auprès du Jardin de Cocagne (aussi bien un abonné aux paniers, qu'un particulier achetant au marché, qu'un professionnel passant une commande).

Le terme **« adhérent »** ne sera utilisé que dans le cadre de l'adhésion à l'association, qui est distincte et dissociée de l'acte d'achat (même si dans certains cas l'adhésion à l'association est obligatoire pour pouvoir effectuer certains actes d'achat).

A noter que des Jardins peuvent être en SCIC et n'ont pas d'adhérent au sens association mais plutôt des clients qui peuvent être sociétaires.

Si le cœur des activités commerciales des Jardins de Cocagne est bien l'abonnement au panier, on utilisera le terme large de **« produit »** pour tout élément qui peut être proposé à la vente (un légume, un panier, un abonnement, un lot, un agenda etc.). Certains termes **« paniers »** sont repris par habitude de langage car ils correspondent à un usage spécifique des abonnements : la fonctionnalité décrite peut être élargie à tous les types d'abonnements à des livraisons de produits.

Habituellement dans un Jardin de Cocagne on utilise le terme de **« point de dépôt »** (ou point de retrait) comme lieu de livraison des paniers, et l'on traite différemment les livraisons des autres modes de ventes et des commandes de professionnels. Dans ce cahier des charges on utilisera le terme unique de point de dépôt pour tous les lieux de livraison, quel que soit le type de produits ou de clients concernés. Une catégorie de point de dépôt permettra ensuite de les distinguer dans leurs usages.

Enfin, la mention de **« structure »** désigne les Jardins de Cocagne, structures utilisatrices de ce futur outil grâce aux déclinaisons multi-sociétés. La mention de « Jardin » ou « Jardin de Cocagne » peut aussi apparaître pour le même usage.

#### Résumé

Un Jardin de Cocagne est une association composée de salariés permanents constituant l'équipe d'encadrement, de salariés en réinsertion professionnelle (chômeurs de longue durée, personnes en très grande difficulté sociale, réfugiés, etc.) de bénévoles et d'adhérents consommateurs.

Seuls les adhérents peuvent utiliser les services de l’association.

Les adhérents peuvent s'abonner à des paniers, de différentes tailles et composition.

Les paniers sont livrés à des fréquences régulières (toutes les semaines, toutes les deux semaines, tous les mois) dans des dépôts. Les adhérents viennent ensuite chercher leurs paniers dans le dépôt auquel ils sont rattachés.

Le système informatique devra comprendre un backoffice utilisé par l'équipe du Jardin pour gérer les abonnements, la production et les livraisons, et d'un frontoffice permettant aux adhérents de gérer leur abonnement.

Le système informatique devra être mutualisé au niveau du réseau Cocagne.
