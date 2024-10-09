#include <stdio.h>
#include <time.h>
#include "main.h"

void main() {

    FILE *fp;
    fp = fopen("donnees.bin", "rb");

    meteos releve2;
    /*
    puts("Quelle est la température ?");
    scanf("%d", &releve2.temperature);

    puts("Quelle est la hauteur des précipitations ?");
    scanf("%d", &releve2.precipitation);

    puts("Quelle est la direction du vent ?");
    scanf("%3s", releve2.vent_direction);

    puts("Quelle est la vitesse du vent ?");
    scanf("%d", &releve2.vent_vitesse);

    puts("Quelle est l'humidité ?");
    scanf("%d", &releve2.humidite);

    releve2.dateheure = time(NULL);

    fwrite(&releve2, sizeof(meteos), 1, fp);
    */


}
