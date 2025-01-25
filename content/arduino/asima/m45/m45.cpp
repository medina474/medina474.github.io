#include <Arduino.h>
#include <Controllino.h>

#define S0 CONTROLLINO_A0
#define S1 CONTROLLINO_A1
#define BC1 CONTROLINO_IN0
#define BC2 CONTROLINO_IN1

#define Y1 CONTROLLINO_R0
#define PM1 CONTROLINO_R1
#define PM2 CONTROLINO_R2

#define ETAPE_ARRET 0
#define ETAPE_MARCHE 1

#define ETAPE_POMPES_ARRET 10
#define ETAPE_POMPE1_MARCHE 11

int etape, etape_marche;

int s0, s1, bc1, bc2;

void setup() {
  pinMode(Y1, OUTPUT);
  pinMode(PM1, OUTPUT);
  pinMode(PM2, OUTPUT);

  pinMode(S0, INPUT);
  pinMode(S1, INPUT);
  pinMode(BC1, INPUT);
  pinMode(BC2, INPUT);

  etape = ETAPE_ARRET;
  etape_marche = ETAPE_POMPES_ARRET;
}

void loop() {
  
  // 1. Lire les entrées
  s0 = digitalRead(S0);
  s1 = digitalRead(S1);
  bc1 = digitalRead(BC1);
  bc2 = digitalRead(BC2);

  // 2. Grafcet
  if (etape == ETAPE_ARRET && s1) {
    etape = ETAPE_MARCHE;
  }

  if (etape == ETAPE_MARCHE && !s0) {
    etape = ETAPE_ARRET;
    etape_marche = ETAPE_POMPES_ARRET;
  }

  if (etape = ETAPE_MARCHE && 
      etape_marche == ETAPE_POMPES_ARRET && !b2) {
    etape_marche = ETAPE_POMPE1_MARCHE;
  }

  digitalWrite(Y1, etape == ETAPE_MARCHE);
  digitalWrite(PM1, etape_marche == ETAPE_POMPE1_MARCHE);

}
