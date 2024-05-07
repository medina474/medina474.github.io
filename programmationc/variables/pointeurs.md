---
title: "Pointeurs"
date: 2022-11-13T08:02:03+01:00
draft: false
---

> Un pointeur est une variable de type **référence**, dont la valeur est l'**adresse** d'une autre variable appelée cible.

Sur un sytème 32 bits la taille d'un pointeur est de 4 octets (32 bits), sur un système 64 bits la taille d'un pointeur de de 8 octets (64 bits).

```C
int score = 65040073;
int *pointeur = &score;
```

<svg viewbox="0 0 300 330" width="300">
<defs
     id="defs84">
    <marker
       style="overflow:visible;"
       id="Arrow1Send"
       refX="0.0"
       refY="0.0"
       orient="auto">
      <path
         transform="scale(0.2) rotate(180) translate(6,0)"
         style="fill-rule:evenodd;fill:context-stroke;stroke:context-stroke;stroke-width:1.0pt;"
         d="M 0.0,0.0 L 5.0,-5.0 L -12.5,0.0 L 5.0,5.0 L 0.0,0.0 z "
         id="path4681" />
    </marker>
    <marker
       style="overflow:visible"
       id="Arrow1Sstart"
       refX="0.0"
       refY="0.0"
       orient="auto">
      <path
         transform="scale(0.2) translate(6,0)"
         style="fill-rule:evenodd;fill:context-stroke;stroke:context-stroke;stroke-width:1.0pt"
         d="M 0.0,0.0 L 5.0,-5.0 L -12.5,0.0 L 5.0,5.0 L 0.0,0.0 z "
         id="path4678" />
    </marker>
    <marker
       style="overflow:visible;"
       id="Arrow1Lend"
       refX="0.0"
       refY="0.0"
       orient="auto">
      <path
         transform="scale(0.8) rotate(180) translate(12.5,0)"
         style="fill-rule:evenodd;fill:context-stroke;stroke:context-stroke;stroke-width:1.0pt;"
         d="M 0.0,0.0 L 5.0,-5.0 L -12.5,0.0 L 5.0,5.0 L 0.0,0.0 z "
         id="path4669" />
    </marker>
    <marker
       style="overflow:visible;"
       id="Arrow2Lend"
       refX="0.0"
       refY="0.0"
       orient="auto">
      <path
         transform="scale(1.1) rotate(180) translate(1,0)"
         d="M 8.7185878,4.0337352 L -2.2072895,0.016013256 L 8.7185884,-4.0017078 C 6.9730900,-1.6296469 6.9831476,1.6157441 8.7185878,4.0337352 z "
         style="fill-rule:evenodd;fill:context-stroke;stroke-width:0.62500000;stroke-linejoin:round;"
         id="path4687" />
    </marker>
    <style>
    .rect {
      fill: none;
      stroke: black;
      stroke-width: 1px;
    }
    .ligne {
      stroke: black;
      stroke-width: 0.5px;
    }
    text.address { font-size:11px; }
    .variable { fill: #ffcc44; }
    </style>
  </defs>
  <text x="0" y="0" class="address">
    <tspan x="0" y="14">10000</tspan>
    <tspan x="0" y="34">10001</tspan>
    <tspan x="0" y="54">10002</tspan>
    <tspan x="0" y="74">10003</tspan>
    <tspan x="0" y="94">10004</tspan>
    <tspan x="0" y="114">10005</tspan>
    <tspan x="0" y="134">10006</tspan>
    <tspan x="0" y="154">10007</tspan>
    <tspan x="0" y="174">10008</tspan>
    <tspan x="0" y="194">10009</tspan>
    <tspan x="0" y="214">10010</tspan>
    <tspan x="0" y="234">10011</tspan>
    <tspan x="0" y="254">10012</tspan>
    <tspan x="0" y="274">10013</tspan>
    <tspan x="0" y="294">10014</tspan>
    <tspan x="0" y="314">10015</tspan>
  </text>
  <rect x="40" y="60" width="75" height="80" class="variable"/>
  <text x="0" y="0">
    <tspan x="45" y="15">0000 1100</tspan>
    <tspan x="45" y="35">0100 0000</tspan>
    <tspan x="45" y="55">0000 0100</tspan>
    <tspan x="45" y="75">1100 1001</tspan>
    <tspan x="45" y="95">0110 1110</tspan>
    <tspan x="45" y="115">1110 0000</tspan>
    <tspan x="45" y="135">0000 0011</tspan>
    <tspan x="45" y="155">1100 0000</tspan>
    <tspan x="45" y="175">0010 0000</tspan>
    <tspan x="45" y="195">0000 0000</tspan>
    <tspan x="45" y="215">0000 1111</tspan>
    <tspan x="45" y="235">1001 0000</tspan>
    <tspan x="45" y="255">0000 0000</tspan>
    <tspan x="45" y="275">0000 0000</tspan>
    <tspan x="45" y="295">0110 0000</tspan>
    <tspan x="45" y="315">0000 0000</tspan>
  </text>
  <rect x="40" y="1" width="75" height="320" class="rect"/>
  <path d="M40,20h75 M40,40h75 M40,60h75 M40,80h75 M40,100h75 M40,120h75 M40,140h75 M40,160h75  M40,180h75  M40,200h75  M40,220h75  M40,240h75  M40,260h75  M40,280h75  M40,300h75" class="ligne"/>
  <path
     style="fill:none;stroke:#000;stroke-width:1.5px;stroke-opacity:1"
     d="M 118,60 c 8,0 8,4 8,20
     0,8 0,20 8,20
     -8,0 -8,10 -8,20
     0,16 0,20 -8,20" />
<path
     style="fill:none;stroke:#000000;stroke-width:1px;stroke-linecap:butt;stroke-linejoin:miter;stroke-opacity:1;marker-end:url(#Arrow2Lend)"
     d="M 134.3373,22.772575 35.934705,64.97496"
 />
  <text x="140" y="105">score</text>
  <text x="140" y="25">*pointeur</text>
  </svg>

La déclaration d'un pointeur s'effectue en utilisant le symbole `*` appelé indirection.

Pour déclarer un pointeur il convient de spécifier aussi le type de la variable cible. Comme cela le système connait le nombre d'octets visés par le pointeur.

Dans cette déclaration le pointeur `*pointeur` vise une variable de type `int`.

L'opérateur `&` sur une variable existante permet de d'assigner au pointeur l'adresse de la variable cible.


Le format %p de `printf` permet d'afficher l'adresse mémoire d'un pointeur.

```C
printf("%p\n", pointeur);
```

Pour modifier la valeur d'une variable données en passant par le pointeur s'effectue en utilisant l'opérateur d"indérection `*`;

```C
*pointeur = 66000000;
printf("%d\n", score);
```

l'opérateur d'indirection `*` modifie la valeur ciblée par le pointeur, et non le pointeur lui-même.

## Allocation dynamique

Les allocations de mémoires pour les pointeurs sont réalisées dans une zone mémoire bien spécifique qui s’appelle le tas (heap) (cours INFO2).

I L’allocation correspond à la réservation d’un bloc mémoire spécifique à votre programme par le gestionnaire de mémoire du système d’exploitation.

I Cette opération est qualifiée d’allocation dynamique car la taille du bloc est modifiable à tout instant dans votre programme.

I La gestion de l’allocation mémoire se fait grˆace aux 3 fonctions suivantes :

X malloc et calloc : demande de mémoire du programme au système d’exploitation ;
X realloc : changement de la taille du bloc mémoire alloué (en + ou en -) ;
X free : libération du bloc mémoire lorsqu’il n’est plus utilisé.

Afin de pouvoir gérer la mémoire dynamiquement en utilisant ces fonctions, il faut inclure stdlib.h.

La déclaration d’un pointeur n’engendre pas de réservation mémoire. Si on ne réserve pas d’emplacement mémoire, il y a risque de débordement d’un pointeur dans les données voisines, donc de plantage du programme.


### malloc

```C
void *malloc(size t taille);
```

Elle permet d’allouer un bloc de mémoire de taille octets dans la zone de mémoire appelée tas (heap), réservée aux données ;

Le bloc de données n’est pas initialisé lors de l’allocation ;

Elle renvoie un pointeur de type void (permettant de gérer les adresses de données de tous types). Il convient donc de le convertir en un type de données déterminé (cast) ;

Si l’allocation réussit, la fonction renvoie un pointeur sur le bloc nouvellement alloué. Si la place disponible est insuffisante ou si taille vaut 0, elle renvoie un pointeur nul : NULL.


### calloc

```C
void *calloc(size t nombre, size t tailleType);
```

Elle permet d’allouer un bloc de mémoire de nombre ∗ tailleType octets dans la zone de mémoire appelée tas (heap), réservée aux données ;

Le bloc de données est initialisé avec des 0 lors de l’allocation ;

Elle renvoie un pointeur de type void (permettant de gérer les adresses de données de tous types). Il convient donc de le convertir en un type de données déterminé (cast) ;

Si l’allocation réussit, la fonction renvoie un pointeur sur le bloc nouvellement alloué. Si la place disponible est insuffisante ou si taille vaut 0, elle renvoie un pointeur nul : NULL.

### realloc

```C
void *realloc(void *pointeurBase, size t newTaille);
```

Elle permet de changer la taille d’un bloc de mémoire déjà alloué. Elle est le reflet de l’aspect dynamique des pointeurs ;

Le paramètre newTaille correspond à l’addition de la taille de l’ancien bloc et de la taille du bloc supplémentaire à ajouter ;

Le contenu du bloc précédant est gardé ⇒ pas besoin de gérer le copie ;

Elle renvoie un pointeur de type void (permettant de gérer les adresses de données de tous types). Il convient donc de le convertir en un type de données déterminé (cast) ;

Si l’allocation réussit, la fonction renvoie un pointeur sur le bloc nouvellement alloué. Si la place disponible est insuffisante ou si newTaille vaut 0, elle renvoie un pointeur nul : NULL.

### Libération

La fonction free

```C
void *free(void *pointeur);
```

Cette fonction permet de libérer l’espace mémoire alloué par les 3 fonctions précédentes.

Il est important de libérer l’espace après utilisation, sinon celui-ci devient inutilisable pour la suite du programme ! ! ! !


```C
# include < stdio .h >

int main (int argc, char *argv[])
{
  int *p;
  ...
  free(p); // libération de la mémoire occupée
}
```
