---
title: Théorie des graphes
---

### Définition

Un graphe **G** est constitué de deux ensembles **V** et **E** où  
- V est un ensemble fini mais non vide de sommets,
- E est un ensemble d’arêtes,  
Une arête est un ensemble de deux (_couple_) sommets.
- G = {V, E}

### Vocabulaire

Les sommets sont parfois appelés des **nœuds**. En anglais ils sont appelés _**vertices**_ (sing. _vertex_).

Les arêtes sont parfois appelés des **arcs**. En anglais ils sont appelés _**edges**_.

<svg>
<circle cx="30" cy="70" r="5"/>
<text x="25" y="60">A</text>
<circle cx="115" cy="15" r="5"/>
<text x="125" y="15">B</text>
<circle cx="150" cy="90" r="5"/>
<text x="160" y="90">D</text>
<circle cx="50" cy="120" r="5"/>
<text x="30" y="125">C</text>
<circle cx="170" cy="140" r="5"/>
<text x="180" y="140">E</text>
<circle cx="200" cy="60" r="5"/>
<text x="195" y="50">H</text>
<circle cx="280" cy="40" r="5"/>
<text x="290" y="40">G</text>
<circle cx="250" cy="100" r="5"/>
<text x="260" y="110">F</text>
<line x1="30" y1="70" x2="115"  y2="15" stroke="#000" stroke-width="2"  />
<line x1="30" y1="70" x2="150"  y2="90" stroke="#000" stroke-width="2"  />
<line x1="50" y1="120" x2="150"  y2="90" stroke="#000" stroke-width="2"  />
<line x1="150" y1="90" x2="170"  y2="140" stroke="#000" stroke-width="2"  />
<line x1="50" y1="120" x2="115"  y2="15" stroke="#000" stroke-width="2"  />
<line x1="280" y1="40" x2="250"  y2="100" stroke="#000" stroke-width="2"  />
</svg>

```
V = [A, B, C, D, E, F, G, H]  
E = [{A, B}, {A, D}, {B, C}, {C, D}, {D, E}, {G, H}]
```

#### Notation : 

L’arête {A, B} pourra être notée  A—B ou B—A. Ce qui implique que {A, B} = {B, A}.

### Définitions : 

Dans un graphe G = {V , E}

- deux sommets A, B ∈ V (qui appartiennent à l'ensemble des sommets V) sont **adjacents** s’ils sont reliés par une arête. Par exemple si A—B ∈ E (l'arête A-B appartient à l'ensemble V des arêtes) ;
- une arête A—B est **incidente** aux sommets A et B ;
- le **degré** d’un sommet est le nombre d’arêtes qui lui sont incidentes.

Dans notre exemple :
- A et B sont adjacents ;
- l’arête B—C est incidente à B et à C ;
- le degré de A est 2 ;
- le degré de D est 3 ;
- le degré de F est 0 ;
- le degré de G est 1.

### Sous-graphes

Soit un graphe G = {V , E}. Le graphe G' {V', E'} est un **sous-graphe** de G si les conditions suivantes sont réunies :
- V' ⊆ V et V ≠ ∅ (V' est inclus dans V) ;
- E' ⊆ E ;
- les sommets composant les arêtes de E' doivent appartenir à V'.

<svg>
<g fill="red" >
<circle cx="30" cy="70" r="5"/>
<text x="25" y="60">A</text>
<circle cx="115" cy="15" r="5"/>
<text x="125" y="15">B</text>
<circle cx="150" cy="90" r="5"/>
<text x="160" y="90">D</text>
<circle cx="50" cy="120" r="5"/>
<text x="30" y="125">C</text>
<circle cx="170" cy="140" r="5"/>
<text x="180" y="140">E</text>
<g stroke="#f00" stroke-width="2">
<line x1="30" y1="70" x2="115"  y2="15" />
<line x1="30" y1="70" x2="150"  y2="90" />
<line x1="50" y1="120" x2="150"  y2="90" />
<line x1="150" y1="90" x2="170"  y2="140" />
<line x1="50" y1="120" x2="115"  y2="15" />
</g>
</g>
<circle cx="200" cy="60" r="5"/>
<text x="195" y="50">H</text>
<circle cx="280" cy="40" r="5"/>
<text x="290" y="40">G</text>
<circle cx="250" cy="100" r="5"/>
<text x="260" y="110">F</text>
<line x1="280" y1="40" x2="250"  y2="100" stroke="#000" stroke-width="2"  />
</svg>

### Multigraphes

Une paire de sommets peut être connectée par plus d’une arête

### Graphes dirigés

Les arêtes sont des paires ordonnées de sommets.

- Une arête partant du sommet A et allant au sommet B est dénotée A → B.
- Le **degré intérieur** d’un sommet est le nombre d’arêtes arrivant à ce sommet.
- Le **degré extérieur** d’un sommet est le nombre d’arêtes sortant de ce sommet

Le degré intérieur de D est 1 ; son degré extérieur est 2.

### Boucles : 

On peut autoriser qu’un graphe contienne des boucles,
c’est-`a-dire qu’une arˆete ait pour extr´emit´es le mˆeme sommet

### Graphes connexes

n graphe G = (V , E ) est connexe si pour toute paire de sommets u, v 2 V , il existe un chemin `a extr´emit´es u et v dans G .
