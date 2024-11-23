---
title: Travaux dirigés 6
---

> Énoncé : Lire un fichier texte contenant des valeurs mixtes, effectuer des transformations.
{: .definition }

a. Ouvrir le fichier [prix-des-carburants](prix-des-carburants.csv) en mode lecture.

b. Lire le fichier caractère par caractère.

Utiliser la fonction ***fgetc***

c. Les colonnes sont séparées par des virgules. 

Lorsque la valeur de la colonne contient une virgule, il ne faut pas la confondre avec un séparateur de colonne. Les colonnes sont alors entourées d'apostrophes.

Lorsque la valeur de la colonne contient une apostrophe, l'apostrophe est doublée.

```
ville,automate,mise à jour
Saint Die des Vosges,Oui,13/08/2024
```

Les colonnes ville, automate et mise à jour sont séparée par des virgules.

```
prix SP95,prix SP98
'1,499','1,509'
```

Les colonnes contiennent des nombres à virgule. Il ne faut pas les découper. Les colonnes sont entourées d'apostrophes ' pour insiquer qu'il ne faut pas tenir compte des virgules à l'intérieur.

```
'116,rue d''Alsace'
```

Si la colonne contient une apostrophe, elle est doublée pour éviter de la confondre avec l'apostrophe de début de colonne.


d. Convertir les nombres qui ont des virgules en nombres décimaux

e. Convertir les dates au format date unix

f. Enregistrer ces données au format binaire.
