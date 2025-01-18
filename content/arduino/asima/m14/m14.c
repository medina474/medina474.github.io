#include <Arduino.h>
#include "Controllino.h"

#define MANUEL 0
#define AUTO 1

int depart_cycle;
int compteur;
int sens;
int s4_precedent, s4_fm;
int s5_precedent, s5_fm;
int mode;
unsigned long tempo_start;
int duree;

// 1 fois au démarrage
void setup() {
  // Intialisation
  mode = MANUEL;
  depart_cycle = 0;
  compteur = 0;
  s4_precedent = s4_fm = 0;
  sens = 0;
  duree = 2000;
}

void arreter_cycle() {
  depart_cycle = 0;
  compteur = 0;
  sens = 0;
}

// toutes les 1ms
void loop() {
  int s0 = digitalRead(CONTROLLINO_A0);
  int s1 = digitalRead(CONTROLLINO_A1);
  int s2 = digitalRead(CONTROLLINO_A2);
  int s3 = digitalRead(CONTROLLINO_A3);
  
  int s4 = digitalRead(CONTROLLINO_A4);
  s4_fm = (s4 > s4_precedent);  
  s4_precedent = s4;

  int s5 = digitalRead(CONTROLLINO_A5);
  s5_fm = (s5 > s5_precedent);  
  s5_precedent = s5;

  duree = analogRead(CONTROLLINO_A8) * 100;

  if (s1) {
    depart_cycle = 1;
  }

  if (!s0) {
    arreter_cycle();
  }

  if (depart_cycle && s5_fm) {
    mode = !mode;
    if (mode == AUTO) {
      tempo_start = millis();
    }
  }


  // Je suis en départ cycle
  // Aucun sens encore défini
  // Je ne peux pas changer de sens en cours 
  if (depart_cycle && sens == 0 && s2) {
    sens = 1;
    co14mpteur = 0;
  }

  if (depart_cycle && sens == 0 && s3) {
    sens = -1;
    compteur = 8;
  }

  unsigned long temps_ecoule = millis() - tempo_start;

  if (depart_cycle && (
        (s4_fm && mode == MANUEL) ||
        (temps_ecoule > duree && mode == AUTO))) {
    compteur = compteur + sens;
    tempo_start = millis();
    //compteur++;
  }


  if ((compteur == 8 && sens == 1) || 
      (compteur == 0 && sens == -1)) {
    arreter_cycle();
  }

  digitalWrite(CONTROLLINO_R0, depart_cycle);

  digitalWrite(CONTROLLINO_R1, compteur == 1);
  digitalWrite(CONTROLLINO_R2, compteur == 2);
  digitalWrite(CONTROLLINO_R3, compteur == 3);
  digitalWrite(CONTROLLINO_R4, compteur == 4);
  digitalWrite(CONTROLLINO_R5, compteur == 5);
  digitalWrite(CONTROLLINO_R6, compteur == 6);
  digitalWrite(CONTROLLINO_R7, compteur == 7);

}
