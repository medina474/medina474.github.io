#include <Arduino.h>
#include "Controllino.h"

// Les entrées
// Les boutons  (avec gestion du front montant)
int s0, s1, s2, s3, s4, s5;
int s0_fm, s1_fm, s2_fm, s3_fm, s4_fm, s5_fm;
int s0_prec, s1_prec, s2_prec, s3_prec, s4_prec, s5_prec;

// Les capteurs
int b6, b7, b8, b9;

void setup()
{
  pinMode(CONTROLLINO_R0, OUTPUT);
  pinMode(CONTROLLINO_R5, OUTPUT);

  pinMode(CONTROLLINO_A0, INPUT);
  pinMode(CONTROLLINO_A1, INPUT);
  pinMode(CONTROLLINO_A2, INPUT);
  pinMode(CONTROLLINO_A2, INPUT);
  pinMode(CONTROLLINO_A4, INPUT);
  pinMode(CONTROLLINO_A5, INPUT);

  Serial.begin(9600);
}

void loop()
{
  // 1a. Lecture des entrées
  s0 = digitalRead(CONTROLLINO_A0);
  s0_fm = (s0 > s0_prec);
  s0_prec = s0;

  s1 = digitalRead(CONTROLLINO_A1);
  s1_fm = (s1 > s1_prec);
  s1_prec = s1;

  s2 = digitalRead(CONTROLLINO_A2);
  s2_fm = (s2 > s2_prec);
  s2_prec = s2;

  s3 = digitalRead(CONTROLLINO_A3);
  s3_fm = (s3 > s3_prec);
  s3_prec = s3;

  s4 = digitalRead(CONTROLLINO_A4);
  s4_fm = (s4 > s4_prec);
  s4_prec = s4;

  s5 = digitalRead(CONTROLLINO_A5);
  s5_fm = (s5 > s5_prec);
  s5_prec = s5;

  // 1b. Lecture des entrées capteurs
  b6 = digitalRead(CONTROLLINO_A6);
  b7 = digitalRead(CONTROLLINO_A7);
  b8 = digitalRead(CONTROLLINO_IN0);
  b9 = digitalRead(CONTROLLINO_IN1);
}
