---
title: DNS Exercice
---

Quelle est l'adresse IP associée au nom de machine iutsd.univ-lorraine.fr ?

Rendez-vous sur l'outil [Dig](https://toolbox.googleapps.com/apps/dig/) de Google. Dig permet d'interroger le service DNS manuellement.

Une résolution d'adresse s'effectue en partant de la gauche vers la droite, du domaine le plus général vers le plus spécifique.

Demandons aux _serveurs racines_ quels sont les serveurs de noms qui gèrent le domaine _fr_. Il n'existe que 12 serveurs racines dans le monde (https://fr.wikipedia.org/wiki/Serveur_racine_du_DNS).

Nom : fr\
Type de demande : NS
```
fr. 21276 IN NS g.ext.nic.fr.
fr. 21276 IN NS d.nic.fr.
fr. 21276 IN NS e.ext.nic.fr.
fr. 21276 IN NS f.ext.nic.fr.
```

Demandons ensuite à g.ext.nic.fr qui gère le domaine univ-lorraine.fr

Nom : univ-lorraine.fr\
Type de demande : NS
```
univ-lorraine.fr. 21599 IN NS arcturus.ciril.fr.
univ-lorraine.fr. 21599 IN NS orion.ciril.fr.
```

Enfin demandons l'adresse IP de l'hôte iutsd.univ-lorraine.fr à arcturus.ciril.fr.

Nom : iutsd.univ-lorraine.fr\
Type de demande : A
```
iutsd.univ-lorraine.fr. 21599 IN CNAME front.pweb.dc.univ-lorraine.fr.
front.pweb.dc.univ-lorraine.fr. 21599 IN A 193.50.135.38
```

La réponse est que iutsd.univ-lorraine.fr est un nom alias (CNAME) de front.pweb.dc.univ-lorraine.fr et que l'adresse IP (A) de front.pweb.dc.univ-lorraine.fr est 193.50.135.38.