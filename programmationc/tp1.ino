/*
  Graphe 1 - Correction - TP1
*/
#include "controllino.h"
#include "AutomForArduino.h"

void ReadInput(void);
void Processing(void);
void WriteOutput(void);

// sorties automate
#define K1 CONTROLLINO_R0 // contacteur montee
#define K3 CONTROLLINO_R3 // contacteur descente
#define H6 CONTROLLINO_R4 // voyant montee
#define H8 CONTROLLINO_R5 // voyant descente
// entrees automate
#define S0 CONTROLLINO_A0 // Arret NF
#define S2 CONTROLLINO_A2 // Depart cycle NO
#define FCH CONTROLLINO_A3 // FC haute NO
#define FCB CONTROLLINO_A4 // FC basse NO
#define S5 CONTROLLINO_A5 // demande initialisation NO
#define S6 CONTROLLINO_A6 // demande Auto/Manu 

#define STATE_STOPPED   0
#define STATE_AUTOMATIC_ASCENDING 1
#define STATE_AUTOMATIC_LOADING 2
#define STATE_AUTOMATIC_DESCENDING 3
#define STATE_AUTOMATIC_UNLOADING 4

#define STATE_MANUAL_MODE       10
#define STATE_MANUAL_DESCENDING 11


TemporisationRetardMontee tempoX2(3000); // chargement
TemporisationRetardMontee tempoX4(5000); // dechargement

Clignoteur clignotant1hz(1000); // clignotant 1hz

// Entrées
int btn_stop, btn_start;
int btn_manual_mode, btn_returning_to_initial_state; 
int limit_switch_top, limit_switch_bottom;

// Etats
int state, state_next, is_state_changing; 


void setup() {
  Serial.begin(9600);   
    
  state = state_next = STATE_STOPPED;
  is_state_changing = 0;
}

void loop() {

  ReadInput();
  Processing();
  WriteOutput();
  
  is_state_changing = state_next != state;

  if(is_state_changing) 
  {
    state = state_next;
    Serial.print("Etat courant :" + String(state));
  }
}

void ReadInput()
{
  btn_nc_stop = !digitalRead(S0);
  btn_start = digitalRead(S2);

  limit_switch_top = digitalRead(FCH);
  limit_switch_bottom = digitalRead(FCB);
  
  btn_returning_to_initial_state = digitalRead(S5);
  btn_manual_mode = digitalRead(S6);
}

void Processing()
{
  if (btn_nc_stop) 
  {
    state_next = STATE_STOPPED;
    return;
  }

  if (state == STATE_STOPPED && limit_switch_bottom == 1 && btn_start == 1) state_next = STATE_AUTOMATIC_ASCENDING; 
  if (state == STATE_STOPPED && btn_manual_mode) state == STATE_MANUAL_MODE;

  if (state == STATE_AUTOMATIC_ASCENDING && limit_switch_top == 1) state_next = STATE_AUTOMATIC_LOADING; 
  if (state == STATE_AUTOMATIC_LOADING && tempoX2.getSortie()) state_next = STATE_AUTOMATIC_DESCENDING; 
  if (state == STATE_AUTOMATIC_DESCENDING && limit_switch_bottom == 1) state_next = STATE_AUTOMATIC_UNLOADING; 
  if (state == STATE_AUTOMATIC_UNLOADING && tempoX4.getSortie()) state_next = STATE_AUTOMATIC_ASCENDING; 

  if (state == STATE_MANUAL_MODE && btn_returning_to_initial_state) state_next = STATE_MANUAL_DESCENDING;
  
  if ((state == STATE_MANUAL_MODE || state == STATE_MANUAL_DESCENDING) 
      && limit_switch_bottom == 1) state_next = STATE_STOPPED;      
}

void WriteOutput()
{  
  int ascending = STATE_AUTOMATIC_ASCENDING;
  int descending = STATE_AUTOMATIC_DESCENDING || STATE_MANUAL_DESCENDING;

  digitalWrite(K1, ascending);
  digitalWrite(K3, descending);

  digitalWrite(H6, C_1Hz.statut() && ascending || limit_switch_top);
  digitalWrite(H8, C_1Hz.statut() && descending || limit_switch_bottom);

  if (STATE_AUTOMATIC_LOADING) T1.activation();
  if (STATE_AUTOMATIC_UNLOADING) T2.activation();
}
