---
title: Travaux dirigés 6
---

> Énoncé : Lire un fichier texte contenant des valeurs mixtes, effectuer des transformations.
{: .definition }

### Première partie

a. Ouvrir le fichier [prix-des-carburants](prix-des-carburants.csv) en mode lecture.

b. Lire le fichier caractère par caractère.

Utiliser la fonction ***fgetc***

c. Suivre les règles de formattage du document

c1 Les colonnes sont séparées par des virgules. 

```
ville,automate,mise à jour
Saint Die des Vosges,Oui,13/08/2024
```

Les colonnes _ville_, _automate_ et _mise à jour_ sont séparée par des virgules.

c2 Lorsque la valeur de la colonne contient une virgule, il ne faut pas la confondre avec un séparateur de colonne. Les colonnes sont alors entourées d'apostrophes.

```
prix SP95,prix SP98
'1,499','1,509'
```

Les colonnes contiennent des nombres à virgule. Il ne faut pas les découper. Les colonnes sont entourées d'apostrophes ' pour indiquer qu'il ne faut pas tenir compte des virgules à l'intérieur.

c3 Lorsque la valeur de la colonne contient une apostrophe, l'apostrophe est doublée.

```
'116,rue d''Alsace'
```

Si la colonne contient une apostrophe, elle est doublée pour éviter de la confondre avec l'apostrophe de début de colonne.


d. Convertir les nombres qui ont des virgules en nombres décimaux

e. Convertir les dates au format date unix

f. Enregistrer ces données dans un fichier carburant.bin au format binaire.

### Partie 2

a. Ouvrir le fichier **carburant.bin**

b. Positionner vous au 100e enregistrement, lire 8 enregistrements, calculer la moyenne du SP98

c. Positionner vous au 200e, lire 8 enregistrements calculer la moyenne du SP98

d. Demander à l'utilisateur le n° d'enregistrement souhaité, poistionnez vous dans le fichier, lire 8 enregistrements, calculer la moyenne du SP98.
