---
layout: layouts/page.njk
title: SVG - Colorier une carte
---

Vous devez colorier une carte de France suivant le classement des régions dans différents critères.

1. Créer un page HTML

2. Incorporer la carte de <a href="france.svg" download>France</a> dans la page.

3. Ajouter une feuille de style pour représenter 9 nuances de couleur 
Utiliser le site [Color Brewer](https://colorbrewer2.org/#type=sequential&scheme=YlOrRd&n=5) pour générer la palette de couleur

4. Ajouter un bloc javascript à la fin de la page. Définir le tableau suivant :

Région|Code|Taux
---|---|--:|
Auvergne-Rhône-Alpes|FR-ARA|21
Bourgogne-Franche-Comté|FR-BFC|31
Bretagne|FR-BRE|33
Corse|FR-COR|12
Centre-Val de Loire|FR-CVL|18
Grand Est|FR-GES|22
Hauts-de-France|FR-HDF|38
Île-de-France|FR-IDF|34
Normandie|FR-NOR|4
Nouvelle-Aquitaine|FR-NAQ|17
Occitanie|FR-OCC|28
Pays de la Loire|FR-PDL|30
Provence-Alpes-Côte d'Azur|FR-PAC|9


5. Ajouter un bouton et au clic colorier la carte suivant le taux

Couleur|Bornes
---|---|
#ffffe5 |0 < taux <= 5
#f7fcb9 | 5 < taux <= 10
#d9f0a3 |10 < taux <= 15
#addd8e |15 < taux <= 19
#78c679 |19 < taux <= 23
#41ab5d |23 < taux <= 27
#238443 |27 < taux <= 31
#006837 |31 < taux <= 35
#004529 |35 < taux <= 40

Voir la [réponse](reponse)
