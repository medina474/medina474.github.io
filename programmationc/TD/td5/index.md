---
title: Travaux dirigés 5
---

> Énoncé : Lire un fichier texte contenant des valeurs numériques en colonne et effectuer une analyse.
{: .definition }

a. Créer un programme en C

b. Ouvrir le fichier [notes.tsv](notes.tsv) en mode lecture.

c. Lire la totalité du fichier, les colonnes sont séparées par le caractère tabulation (chercher le code ascii).

Pour « découper » une chaine de caractères en colonnes, il faut chercher à l'intérieur de cette chaine le « séparateur » de colonne.

Dans notre cas le séparateur est le caractère tabulation \t.

La fonction C qui permet de chercher un séparateur (appelé token) est ***strtok***.

d. Pour chaque ligne calculer la moyenne des colonnes : anglais, litterature, mathemathiques, sciences et arts.

e. Définir une structure permettant de stocker toutes les valeurs en mode « machine ». N'oubliez pas la colonne moyenne.

f. Enregistrer les données en mode binaire dans un deuxième fichier (notes.bin)

g. Les notes sont des nombres décimaux et non pas des nombres réels. Utilisez une méthode intelligente pour stocker ces nombres.
