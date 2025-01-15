---
title: Évaluation 2
---

Un opérateur régional d'aviation vous demande de concevoir un système de réservation pour ses appareils.

Vous avez à votre disposition :
- L'illustration de l'<a href="avion.svg" download>avion</a> vide
- L'illustration d'un <a href="siege.svg" download>siège</a>

## Travail à faire

1. Incorporer l'illustration de l'avion dans une page html.
2. Ajouter le siège comme un symbole réutilisable de l'illustration.
3. Modifier le symbole pour qu'il puisse être colorier avec 3 couleurs, une pour le contour, une pour l'assise (rect) et une pour le dossier (path)

4. Créer 3 classes css pour représenter les 3 états des sièges : libre,
réservé et occupé. Utiliser un générateur de nuances comme [material.io](https://material.io/resources/color/)

5. Ajouter une zone située à (200px, 280px) qui correspond à la cabine.

6. Ajouter dans la page html un champ de saisie qui permet de choisir un nombre de rangées entre 2 et 10. Ajouter un bouton "appliquer" pour ajouter, avec un script, le nombre sélectionné de rangées de sièges.
Les rangées sont espacées de 40px verticalement, les sièges ont le statut libre. Les sièges d'une rangées sont placés horizontalement à 0, 28, 87 et 115.

7. Lorsque l'on clique sur un siège celui ci passe de l'état libre à réservé puis à occupé. Vérifier que les couleurs changent bien en fonction de son état.

Références : 
- https://www.seatguru.com/airlines/Air_Canada/Air_Canada_Dash_81.php
- https://www.chronoaviation.com/flotte/dash-8-100
