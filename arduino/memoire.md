---
title: Mémoire
---

![](arduino-memory-map.png)

STARTUP : code de démarrage\
CODE : code de l'application, y compris celui des bibliothèques\
LOAD_DATA : les valeurs des variables globales et statiques initialisées\
REGISTERS : registres du microcontrôleur (GPIOs, TIMERS, etc.)\
DATA : variables globales et statiques initialisées\
BSS : variables globales et statiques non initialisées\
STACK : la pile\

### Stack (Pile)

Lors de l'exécution du programme, la pile est utilisée pour empiler les adresses de retour des fonctions, ainsi que les variables locales.

La pile est gérée grâce à un registre spécial : le pointeur de pile.

Lorsque l'on appelle une fonction l'adresse de retour est placée sur la pile et le pointeur de pile est décrémenté de 2 octets (la taille d'une adresse ATMEGA).

Si la fonction appelée déclare une variable locale le pointeur de pile est décrémenté de la taille de la variable. Dans certains cas, le compilateur utilisera un registre, plus rapide.

Si cette fonction appelle une autre fonction, le pointeur de pile est encore décrémenté, de la même manière.

Si la valeur du pointeur de pile descend trop bas il y a un risque d'aller corrompre les adresses haute de la zone des variables globales. Si le programme utilise des objets String ou l'allocation dynamique, les adresses hautes du tas seront corrompues.

### Heap (tas)

Entre la pile (Stack) et la zone BSS se trouve la mémoire libre.

Cette zone s'appelle le tas (heap). Si le programme comporte un grand nombre de variables globales la taille du tas sera réduite d'autant.

L'allocation dynamique de mémoire revient donc à réserver un bloc mémoire de la taille demandée dans cette zone appelée tas. Le **demandeur est responsable** de la libération de ce boc quand il sera devenu inutile.

#### fragmentation

fragmentation = 1 - plus grand block / mémoire totale 

```C
float getFragmentation() {
  return 100 - getLargestAvailableBlock() * 100.0 / getTotalAvailableMemory();
}
```

Nous avons vu comment la fragmentation augmente, parlons maintenant des conséquences d’un niveau de fragmentation élevé.

Conséquence 1 : programme peu fiable

Par définition, un niveau de fragmentation élevé signifie que vous avez beaucoup de mémoire libre, mais que vous ne pouvez allouer que de petits blocs. Si votre programme a besoin d'un bloc plus gros, il ne l'obtiendra pas et cessera de fonctionner.

Conséquence 2 : performances dégradées

Un tas très fragmenté est plus lent car l'allocateur de mémoire prend plus de temps pour trouver le meilleur trou, appelé « best-fit ».


https://cpp4arduino.com/2018/11/06/what-is-heap-fragmentation.html

https://wiki.mchobby.be/index.php?title=Arduino_Memoire
