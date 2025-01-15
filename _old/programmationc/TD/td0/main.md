---
title: La fonction main
---

### Retour de la fonction main

La fonction main en C retourne généralement une valeur entière, et ce retour a une signification particulière. Le retour de la fonction main est utilisé pour indiquer à l'environnement d'exécution du programme (comme le système d'exploitation) si le programme s'est terminé correctement ou s'il a rencontré une erreur. 

Signification des valeurs de retour

0 : En C, retourner 0 dans la fonction main signifie que le programme s'est exécuté avec succès et sans erreurs. Cela est considéré comme un "statut de succès" ou un "code de sortie" indiquant que tout s'est déroulé correctement.

Valeurs non-nulles (typiquement positives) : Si le programme rencontre une erreur, vous pouvez retourner une valeur différente de 0 (souvent une petite valeur positive comme 1). Cela signifie qu'il y a eu une erreur ou une condition particulière. Les systèmes d'exploitation ou d'autres programmes qui appellent ce programme peuvent interpréter cette valeur pour comprendre la nature de l'erreur.

```c
#include <stdio.h>

int main() {
  puts("Bonjour Jérôme");
  return 0;  // Indique une exécution réussie
}
```

Pour quitter le programme prématurément sans attendre la fin de la fonction main, il faut utiliser la fonction exit

```c
exit(1);
```

##### Lire le retour de la fonction 

Sous Windows, vous pouvez lire la valeur de sortie d'un programme de plusieurs façons, notamment via l'invite de commandes (cmd) ou un script batch. Le code de retour d'un programme est appelé code d'erreur ou exit code et peut être capturé avec la variable spéciale %ERRORLEVEL%.


```batch
@echo off
mon_programme.exe

if %ERRORLEVEL% equ 0 (
  echo Programme exécuté avec succès !
) else (
  echo Le programme a échoué avec le code de retour %ERRORLEVEL%.
)
```
