#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure représentant une ligne du fichier CSV
typedef struct {
    char designation[50];
    int largeur;
    int hauteur;
    int epaisseur;
    float temps;
    int perimetre;
    int volume;
} Material;

double vv_max = 0, vv_min = 99999999, vl_max = 0, vl_min = 99999999;

void read_csv_and_export_binary(const char *csv_file, const char *binary_file) {
    FILE *csv = fopen(csv_file, "r");
    FILE *binary = fopen(binary_file, "wb");
    if (!csv || !binary) {
        perror("Erreur lors de l'ouverture des fichiers");
        exit(EXIT_FAILURE);
    }

    char line[300];
    Material material;

    // Ignorer la première ligne (entêtes)
    if (fgets(line, sizeof(line), csv) == NULL) {
        fprintf(stderr, "Le fichier est vide ou inaccessible.\n");
        exit(EXIT_FAILURE);
    }

    // Lire chaque ligne du fichier CSV
    while (fgets(line, 300, csv)) {
        printf("%s\n", line);
        // Supprimer le caractère de fin de ligne
        /*line[strcspn(line, "\n")] = '\0';

        // Extraire les valeurs
        if (sscanf(line, "%49[^,],%d,%d,%d,%f", 
                   material.designation, 
                   &material.largeur, 
                   &material.hauteur, 
                   &material.epaisseur, 
                   &material.temps) != 5) {
            fprintf(stderr, "Format invalide dans la ligne : %s\n", line);
            continue;
        }
 
        int perimetre = (material.largeur + material.hauteur) * 2;
        material.perimetre = perimetre;
        material.volume = material.largeur * material.hauteur * material.epaisseur;

        double vl = material.perimetre / material.temps;
        double vv = material.volume / material.temps;

        if (vl > vl_max) vl_max = vl;
        if (vl < vl_min) vl_min = vl;
        if (vv > vv_max) vv_max = vv;
        if (vv < vv_min) vv_min = vv;

        // Écrire la structure dans le fichier binaire
        fwrite(&material, sizeof(Material), 1, binary);*/
        
    }

    fclose(csv);
    fclose(binary);
    printf("Exportation terminée vers le fichier binaire : %s\n", binary_file);
}

void print_binary_content(const char *binary_file) {
    FILE *binary = fopen(binary_file, "rb");
    if (!binary) {
        perror("Erreur lors de l'ouverture du fichier binaire");
        exit(EXIT_FAILURE);
    }

    Material material;
    printf("Contenu du fichier binaire :\n");
    while (fread(&material, sizeof(Material), 1, binary)) {
        printf("Designation: %s, Largeur: %d, Hauteur: %d, Epaisseur: %d, Vitesse: %.2f\n",
               material.designation, material.largeur, material.hauteur, material.epaisseur, material.temps);
    }

    fclose(binary);
}

int main() {
    const char *csv_file = "BUT 2 eval.csv";
    const char *binary_file = "materials.bin";

    // Lire le fichier CSV et exporter en binaire
    read_csv_and_export_binary(csv_file, binary_file);

    printf("%f %f\n%f %f", vl_min, vl_max, vv_min, vv_max);
    // Afficher le contenu du fichier binaire (optionnel)
   // print_binary_content(binary_file);

    return 0;
}
