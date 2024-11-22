---
title: Travaux dirigés 5
---

On désire stocker dans un tableau un ensemble de données. La taille du tableau est de 5 éléments

Les données à stocker regroupent plusieurs caractéristiques

    vitesse de 0 à 300 km/h (Précision : ± 1)
    direction 2 caractères : N, S, E, O, NE, SE, SO, NO
    temperature de -40° à +65° (Précision : ± 0.3°C)
    humidite de 0 à 100% (Précision : ± 3%)
    pression de 260 à 1260 mbar (± 1 mbar)

a. Définir la structure de données à utiliser. Cette structure devra utiliser le moins d'octets possible.

b. Demander à l'utilisateur de remplir le tableau avec une saisie manuelle.

c. Lorsque l'utilisateur arrive au bout de la capacité ajouter 5 cases au tableau

d. Lorsque l'utilisateur entre un nombre supérieur à 300 pour la vitesse. Afficher :

    L'humidité maximale
    La pression minimale
    La température moyenne

e. Tri du tableau

Utilisez la fonction qsort de la bibliothèque standard pour trier un tableau pour trier le tableau suivant la caractéristiques temperature
