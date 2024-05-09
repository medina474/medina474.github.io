---
title: Structure
---

>Un structure permet de regrouper plusieurs types de données dans un seul bloc logique pour les associer à une super variable.
{:.definition}

Exemple de variables indépendantes representant des conditions météorologiques.

```C
float temperature;
float humidite;
int pression;
char vent_direction[2];
int vent_vitesse;
```

La structure rassemble les données dans un bloc logique

```C
struct blocmeteo
{
  float temperature;
  float humidite;
  int pression;
  char vent_direction[2];
  int vent_vitesse;
};
```

Les variables à l'intérieur de la structure sont appelées des **champs**.

La déclaration de variables de type structure s'effectue comme les autes types (int, float, etc...) en utilisant la déclaration le nom de la structure y compris l'instruction struct.

```C
struct blocmeteo paris;
struct blocmeteo strasbourg;
struct blocmeteo marseille;
```

On accède aux propriétés avec l'opérateur `.`

```C
paris.temperature = 15.2;
strabourg.humidite = 0.88;
marseille.pression = 1040;
```

### Nouveau type de données

Pour éviter d'écrire à chaque fois le mot clé struct lors de la déclaration d'une variable ou d'un paramètre de type structure, il est possible de définir un nouveau type à l'aide de la commande `typedef`. Veuillez noter que le nom du type vient tout à la fin de la définition, après la structure

```C
typedef blocmeteo struct
{
  float temperature;
  float humidite;
  int pression;
  char vent_direction[2];
  int vent_vitesse;
} meteo;
```

Le nom de la structure en elle même n'est plus utile, on peut l'ignorer.

```C
typedef struct
{
  float temperature;
  float humidite;
  int pression;
  char vent_direction[2];
  int vent_vitesse;
} meteo;
```

La déclaration des variables se fait directement avec le type;

```C
meteo paris;
meteo strasbourg;
meteo marseille;
```
