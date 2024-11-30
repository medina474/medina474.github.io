---
title: Travaux dirigés 6
---

> Énoncé : Lire un fichier texte contenant des valeurs mixtes, effectuer des transformations.
{: .definition }

### Première partie

a. Ouvrir le fichier [prix-des-carburants](prix-des-carburants.csv) en mode lecture.

```c
FILE *fp = fopen("prix-des-carburants.csv", "r");
if (fp == NULL) {
  perror("Error");  // print error
  exit(-1);         // J'ai décidé que -1 est un code erreur
}

fclose(fp);
```

b. Lire le fichier caractère par caractère.

Utiliser la fonction ***fgetc***

```c
while ((caractere = fgetc(fp)) != EOF) 
{
  putchar(caractere); // Ecrire le caractère à l'écran
}
```

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

```c
int ncolonne = 0;
int nligne = 0;

while ((caractere = fgetc(fp)) != EOF) 
{
  if (caractere == ',') {
    ncolonne++;
    printf("nouvelle colonne %d\n", ncolonne);
  } 
  else if (caractere == '\n') {
    ncolonne = 0;
    nligne++;
    printf("nouvelle ligne %d\n", nligne);
  }  
}
```


```c
int drapeau_apostrophe = 0;   //flag en anglais
int ncolonne = 0;
int nligne = 0;

while ((caractere = fgetc(fp)) != EOF) 
{
  if (caractere == '\'') {
    drapeau_apostrophe = !drapeau_apostrophe;
  }
  if (caractere == ',' && drapeau_apostrophe == 0) {
    ncolonne++;
    printf("nouvelle colonne %d\n", ncolonne);
  } 
  else if (caractere == '\n' && drapeau_apostrophe == 0) {
    ncolonne = 0;
    nligne++;
    printf("nouvelle ligne %d\n", nligne);
  }  
}
```

```c
// * pointeur . On ne travaille sur une copie de PrixCarburant
// mais sur la variable d'origine du pointeur
void RemplirStructure(PrixCarburant *prix, char *valeur, int ncolonne) {

  switch (ncolonne)
  {
  case 0:
    // -> Equivalent à (*prix).identifiant
    prix->identifiant = atoi(valeur);
    break;
  
  case 1:
    strcpy(prix->code_postal, valeur);
    break;

  case 2:
    strcpy(prix->presence, valeur);
    break;

  case 3:
    strcpy(prix->adresse, valeur);
    break;

  case 4:
    strcpy(prix->ville, valeur);
    break;

  case 5:
    prix->automate = strcmp("Oui", valeur); // string compare
    break;

  case 6:
    prix->date_mise_a_jour = 0;
    break;

  case 7:
    prix->Gazole = ConvertirNombreVirgule(valeur);
    break;

  case 8:
    prix->SP95 = ConvertirNombreVirgule(valeur);
    break;

  case 9:
    prix->SP98 = ConvertirNombreVirgule(valeur);
    break;

  case 10:
    prix->GPLc = ConvertirNombreVirgule(valeur);
    break;

  case 11:
    prix->E10 = ConvertirNombreVirgule(valeur);
    break;

  case 12:
    prix->E85 = ConvertirNombreVirgule(valeur);
    break;

  case 13:
    strcpy(prix->marque, valeur);
    break;  

  case 14:
    strcpy(prix->geo_point, valeur);
    break;

  case 15:
    strcpy(prix->code, valeur);
    break;
  
  default:
    break;
  }
}
```

```c
void AfficherStructure(PrixCarburant prix) 
{
  printf("**********\n");
  printf("%s (%d)\n", prix.marque, prix.identifiant);
  printf("%.3f %.3f %.3f %.3f %.3f %.3f\n", prix.Gazole / 1000.0, prix.SP95 / 1000.0, prix.SP98 / 1000.0, prix.GPLc / 1000.0, prix.E10 / 1000.0, prix.E85 / 1000.0);
  printf("%s %s %s\n", prix.adresse, prix.code_postal, prix.ville);
}
```

```c
char buffer[200];

PrixCarburant prix;

// EOF : End Of File (fin du fichier)
while ((caractere = fgetc(fp)) != EOF) 
{
  if (caractere == '\'') {
    drapeau_apostrophe = !drapeau_apostrophe;
  }
  else if (caractere == ',' && !drapeau_apostrophe) {
    buffer[ncaractere] = 0;
    if (nligne >  0) RemplirStructure(&prix, buffer, ncolonne);
    ncolonne++;
    ncaractere = 0;
    //printf("nouvelle colonne %d\n", ncolonne);
  } 
  else if (caractere == '\n' && !drapeau_apostrophe) {
    AfficherStructure(prix);
    fwrite(&prix, sizeof(PrixCarburant), 1, fp2);
    ncolonne = 0;
    ncaractere = 0;
    nligne++;
  } 
  else {
    buffer[ncaractere] = caractere;
    ncaractere++;
  } 
}
```

d. Convertir les nombres qui ont des virgules en nombres décimaux

e. Convertir les dates au format date unix
f. Enregistrer ces données dans un fichier carburant.bin au format binaire.

```c
FILE *fp2 = fopen("carburant.bin", "wb");

fwrite(&prix, sizeof(PrixCarburant), 1, fp2);

fclose(fp2);
```

[code source complet](td6a.1.c)

### Partie 2

a. Ouvrir le fichier **carburant.bin**

b. Positionner vous au 100e enregistrement, lire 8 enregistrements, calculer la moyenne du SP98

c. Positionner vous au 200e, lire 8 enregistrements calculer la moyenne du SP98

d. Demander à l'utilisateur le n° d'enregistrement souhaité, poistionnez vous dans le fichier, lire 8 enregistrements, calculer la moyenne du SP98.
