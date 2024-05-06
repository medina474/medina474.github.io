---
layout: layouts/page.njk
title: Structure
---
Une structure est un objet composé de plusieurs champs de types différents, qui sert à représenter un objet. Par exemple un client peut être représenté
par son nom, son prénom, son année de naissance, son adresse.

```C
struct client // client est le nom de la structure
{
  char nom[25];
  char prenom[20];
  int annee_naissance;
  char adresse[100];
} Un_Client ; // Un_Client et le nom d'une variable de type client
// optionnel si on déclare seulement le type
// ; obligatoire dans tous les cas
```

Définition du type et déclaration de variables?
Définition de la structure
```C
struct client // client est le nom de la structure
{
  char nom[25];
  char prenom[20];
  int annee_naissance;
  char adresse[100];
} ;

//Déclaration de variables :
struct client Un_Client; // déclaration de la variable Un_Client
struct client NouveauClient; // déclaration de la variable NouveauClient
```

Manipulation des champs :
Les structures peuvent être manipulées champs par champs ou dans leur ensemble,
Exemple :
```C
typedef struct client CLIENT; // création d'un alias CLIENT sur struct client
struct client // client est le nom de la structure
{
char nom[25];
char prenom[20];
int annee_naissance;
char adresse[100];
} ;
Int main(void){
CLIENT Un_Client; // déclaration de la variable Un_Client
CLIENT NouveauClient; // déclaration de la variable NouveauClient
gets(NouveauClient.nom); // initialisation du champs nom
gets(NouveauClient.prenom);
gets(NouveauClient.adresse);
scanf("%d",&NouveauClient.annee_naissance);
Un_Client = NouveauClient; // Affectation sur l'ensemble des champs (copie)
}
```

```C
struct date
{
  int jour;
  int mois;
  int annee;
} *pdate ;

int main (void){
  pdate = (struct date *)malloc(sizeof(struct date));
  if (pdate == NULL){
    printf("erreur d'allocation mémoire!!!"); exit(-1);
  }
  printf("Donnez le jour : ");
  scanf("%d",&pdate->jour);
  printf("Donnez le mois : ");
  scanf("%d",&pdate->mois);
  printf("Donnez l'annee : ");
  scanf("%d",&pdate->annee);
  printf("La date %d/%d/%d \n", pdate->jour, pdate->mois, pdate->annee );
}
```