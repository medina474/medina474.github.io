---
title: Structure
---

Les structures en C permettent de regrouper différents types de données sous un même nom, facilitant la gestion des données complexes dans un programme.

Une structure est un objet composé de plusieurs champs de types différents, qui sert à représenter un objet. Par exemple un client peut être représenté par son nom, son prénom, son année de naissance, son adresse.

Une structure est un **type de données personnalisé** qui peut contenir des variables de types différents. On la définit à l'aide du mot-clé ***struct***.

#### Définition de la structure

```c
struct Personne
{
  char nom[25];
  char prenom[20];
  int annee_naissance;
  char adresse[100];
};
```

Une fois la structure définie, on peut créer des variables de ce type.

```c
struct Personne un_client;      // déclaration de la variable Un_Client
struct Personne nouveauClient;  // déclaration de la variable NouveauClient
```

### Manipulation des champs :

Les structures peuvent être manipulées champs par champs ou dans leur ensemble,

Pour accéder aux membres d'une structure, on utilise l'opérateur point ***.***.

```c
int main(void){
  CLIENT Un_Client; // déclaration de la variable Un_Client
  CLIENT NouveauClient; // déclaration de la variable NouveauClient
  
  gets(NouveauClient.nom); // initialisation du champs nom
  gets(NouveauClient.prenom);
  gets(NouveauClient.adresse);
  
  scanf("%d",&NouveauClient.annee_naissance);
  
  Un_Client = NouveauClient; // Affectation sur l'ensemble des champs (copie)
}
```

On peut également manipuler les structures via des pointeurs. Avec un pointeur de structure, l'accès aux membres se fait via l'opérateur flèche ->. (à la place de *variable.)

```c
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

### Structures imbriquées

Les structures peuvent contenir d'autres structures en tant que membres, ce qui permet de créer des hiérarchies de données plus complexes.

```c
struct Adresse {
  char rue[100];
  char ville[50];
  int codePostal;
};

struct Personne {
  char nom[50];
  int age;
  float taille;
  struct Adresse adresse;
};
```

Pour accéder à des données imbriquées, on utilise une succession de . :

```c
strcpy(personne1.adresse.rue, "123 Rue Exemple");
strcpy(personne1.adresse.ville, "Paris");
personne1.adresse.codePostal = 75001;

printf("Ville: %s\n", personne1.adresse.ville);
```

### Utilisation des typedef avec les structures

Pour simplifier l’utilisation d’une structure, on peut utiliser le mot-clé ***typedef***. Cela permet d’éviter de répéter le mot-clé struct chaque fois qu’on utilise la structure.

typedef struct {
    char nom[50];
    int age;
    float taille;
} Personne;

typedef struct client CLIENT; // création d'un alias CLIENT sur struct client


Personne personne3; // Pas besoin d'écrire "struct Personne"
