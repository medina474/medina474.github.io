#include <stdio.h> // Standard Input/Output

// Sur PC la fonction principale s'appele main
// Sur Controllino c'est init et loop

//int q1, q2, q3, q4;
int q[4];
int compteur;
int couleur;

int main() {
  printf("Démarrage du programme\n");
  // \n signifie new line. Passage à la ligne suivante

  //q1 = q2 = q3 = q4 = 1;
  //q[0] = q[1] = q[2] = .. 1;
  
void setup() 
{  
  
}

  int s0;

  while(s0 != 99) {
    printf("Changer l'état du moteur n° : ");
    scanf("%d", &s0);
    printf("s0 = %d\n", s0);

    q[s0] = !q[s0]; // inversion 0 -> 1 et 1 -> 0
    //if (s0 == 1) {
      /*
      if (q[s0] == 0) {
        q[s0] = 1;
      }
      else {
        q[s0] = 0;
      }
      */
    //}

    printf("Etat des ventilateurs ");
    for(int i = 0 ; i < 20 ; i++)
    {
      printf("q%d=%d ", i, q[i]);
    }
    printf("\n");

    compteur = 0;
    /*
    if (q1 == 1) {
      compteur++;
    }
    if (q2 == 1) {
      compteur++;
    }
    if (q3 == 1) {
      compteur++;
    }
    if (q4 == 1) {
      compteur++;
    }
    */

    for(int i = 0 ; i < 20 ; i++)
    {
      if (q[i] == 1) {
      compteur++;
      }
    }


    // 1 vert ; 2 orange ; 3 rouge
    if (compteur >= 15) {
      couleur = 1;
    } else if (compteur >= 12) {
      couleur = 2;
    } else {
      couleur = 1;
    }
   }
}

void loop() 
{
  s5 = digitalRead(CONTROLLINO_A5);
  if (s5 == 1)
  {
    for(int i = 0 ; i < 4 ; i++)
    {
      q[i] = 1;
    }
  }

  s0 = digitalRead(CONTROLLINO_A0);
  if (s0 == 1)
  {
    for(int i = 0 ; i < 4 ; i++)
    {
      q[i] = 0;
    }
  }

  compteur = 0;

  for(int i = 0 ; i < 4 ; i++)
  {
    if (digitalRead(CONTROLLINO_A1 + i) == 1)
    {
      q[i] = 0;
    }
  }
  
  for(int i = 0 ; i < 4 ; i++)
  {
    if (q[i] == 1) {
      compteur++;
    }
  }


  digitalWrite(CONTROLLINO_R0, compteur < 2); // Rouge
  digitalWrite(CONTROLLINO_R1, compteur == 2); // Orange
  digitalWrite(CONTROLLINO_R2, compteur >= 3); // Vert
 
}
