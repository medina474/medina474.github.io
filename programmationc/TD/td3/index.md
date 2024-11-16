---
title: Travaux dirigés 3
---

> Énoncé : Lire un fichier texte contenant des valeurs numériques et effctuer une analyse.
{: .definition }

a. Ouvrir le fichier [observations.csv](observations.csv) en mode lecture

b. Lire la totalité du fichier 

c. A la fin de la lecture, afficher la plus grande valeur (maximim) et la plus petite (minimum).

d. Afficher la moyenne des valeurs lues.

e. Pour chaque ligne lue afficher la moyenne depuis le début de la série et la moyenne glissante sur les 5 dernières valeurs. (voir [td2](td2))


#### a. Ouvrir le fichier

La fonction ***[fopen](../../fichiers)*** ouvre le fichier. si le retour est NULL alors c'est qu'il y a eu un problème. la fonction ***perror*** permet d'afficher le détail de l'erreur, pour en savoir un peu plus.


#### b. Lire la totalité du fichier 

La lecture d'une ligne se fait avec la fonction ***fgets***

La conversion s'effectue à l'aide la fonction ***atof*** de la librairie ***stdlib.h***.

Répeter l'opération tant qu'il y a des lignes

#### c. Calculer à chaque ligne le maximum et le minimum
