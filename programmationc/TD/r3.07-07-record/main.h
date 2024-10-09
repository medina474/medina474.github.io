#include <time.h>

typedef struct meteo
{
  int temperature;
  int precipitation;
  char vent_direction[3];
  int vent_vitesse;
  int humidite;
  time_t dateheure;
} meteos;

typedef struct element
{
  meteos *element;
  elements *suivant;
} elements;
