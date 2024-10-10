---
title:
---

1. break

L'instruction break permet de quitter immédiatement une boucle (for, while, do-while) ou une structure switch. Dès que le programme rencontre un break, il sort du bloc de code en cours.

for (int i = 0; i < 10; i++) {
    if (i == 5) {
        break;  // Sort de la boucle dès que i vaut 5
    }
    printf("%d\n", i);
}

Le break permet ici de sortir du bloc switch après avoir exécuté le code correspondant à la valeur testée

2. continue

L'instruction continue permet de sauter à l'itération suivante d'une boucle, sans terminer l'exécution du bloc de code courant.

for (int i = 0; i < 10; i++) {
    if (i == 5) {
        continue;  // Saute l'itération lorsque i vaut 5
    }
    printf("%d\n", i);
}

return

L'instruction return permet de quitter une fonction et de retourner une valeur (si la fonction n'est pas de type void). Elle interrompt l'exécution de la fonction en cours et retourne éventuellement une valeur à la fonction appelante.

4. goto

L'instruction goto permet de sauter directement à une autre partie du programme marquée par une étiquette (label). Son utilisation est généralement déconseillée car elle rend le code difficile à suivre et à maintenir. Cependant, dans certains cas spécifiques, elle peut être utile pour sortir de plusieurs niveaux d'imbrication ou dans la gestion de sortie d'erreur.

Une étiquette se définie avec un nom suivi d'un caractère :. Normalement, une étiquette est placée en colonne 0 du fichier de texte. 

Pour les autres instructions, les choses sont contrôlée par le compilateur, mais ce qui n'est pas le cas avec goto. Effectivement, si l'étiquette de destination n'est pas placée dans le même bloc que l'instruction goto, alors vous pouvez désynchroniser la pile d'exécution et donc aboutir à un crash de l'application. C'est pour cette raison qu'il est très fortement conseillé de ne pas utiliser l'instruction goto au profit des autres instructions. 

int a = 10;
if (a > 5) {
    goto fin;  // Saute directement à l'étiquette "fin"
}

printf("Ce message ne sera pas affiché.\n");

fin:
    printf("Fin du programme.\n");

