---
title: Types intervalles
---

Un intervalle possède un début d et une fin f, tels que d < f.

Les types de plage sont utiles car ils représentent de nombreuses valeurs d’éléments dans une seule valeur de plage et parce que des concepts tels que les plages qui se chevauchent peuvent être exprimés clairement. L’utilisation de plages d’heures et de dates à des fins de planification en est l’exemple le plus clair ; mais les fourchettes de prix, les plages de mesure d'un instrument, etc. peuvent également être utiles.

Les types de plage sont des types de données représentant une plage de valeurs d'un certain type d'élément (appelé sous-type de plage). Par exemple, des plages d’horodatage peuvent être utilisées pour représenter les plages horaires pendant lesquelles une salle de réunion est réservée. Dans ce cas, le type de données est tsrange (abréviation de « timestamp range ») et timestamp est le sous-type. 

## Types

- int4range : Intervalle d'entier
- int8range : Intervalle d'entier long
- numrange : Intervalle de nombres décimaux
- tsrange : Intervalle d'horodatage sans fuseau horaire
- tstzrange : Intervalle d'horodatage avec fuseau horaire
- daterange : Intervalle de date

### Déclaration

A l'aide de fonctions

```sql
SELECT int4range(10, 20);
```

Déclare un intervalle d'entiers enrte 10 inclus et 20 exclus.

En mode textuel

```sql
SELECT '[10,20)'::int4range;
```


## Limites inclusives et exclusives

Chaque plage non vide a deux limites, la limite inférieure et la limite supérieure. Tous les points entre ces valeurs sont inclus dans la plage. Une limite inclusive signifie que le point limite lui-même est également inclus dans la plage, tandis qu'une limite exclusive signifie que le point limite n'est pas inclus dans la plage.

Dans la forme textuelle d'une plage, les limites inclusives sont représentées par des crochets `[` et `]` tandis que les limites exclusives sont représentées par des parenthèses `(` et `)`. 

Les fonctions lower_inc et upper_inc testent respectivement l'inclusivité des limites inférieure et supérieure d'une valeur de plage.

## Plages infinies (illimitées)

La limite inférieure d'une plage peut être omise, ce qui signifie que toutes les valeurs inférieures à la limite supérieure sont incluses, par exemple `(,3)`. De même, si la limite supérieure de la plage est omise, alors toutes les valeurs supérieures à la limite supérieure de la plage le sont. 



Les fonctions lower_inf et upper_inf testent respectivement les limites inférieure et supérieure infinies d'une plage.


> Logique d’intervalles d’Allen : ensemble complet d’opérateurs booléens de base pour le positionnement relatif dans le temps.



Deux intervalles A et B peuvent se positionner selon 13 configurations.

### 1. Précède

A _Précède_ B lorsque la borne supérieure de A est strictement inférieure à la borne inférieure de B.

<svg viewbox="0 0 20 8" width="200" height="80">
<text x="4"  y="3"  font-size="1.8" text-anchor="middle">A</text>
<text x="12" y="5"  font-size="1.8" text-anchor="middle">B</text>
<line x1="3" x2="5"  y1="4" y2="4" stroke-width="1" stroke="black" />
<line x1="8" x2="16" y1="6" y2="6" stroke-width="1" stroke="black" />
</svg>

Allen|Postgres
---|---
A < B | A << B

```sql
select '[3,5]'::int4range << '[8,15]'::int4range;
```

### 2. Succède

A _Succède_ à B lorsque la borne inférieure de A est strictement supérieure à la borne supérieure de B.

<svg viewbox="0 0 20 8" width="200" height="80">
<text x="12" y="3" font-size="1.8" text-anchor="middle">A</text>
<text x="4"  y="5"  font-size="1.8" text-anchor="middle">B</text>
<line x1="8" x2="16" y1="4" y2="4" stroke-width="1" stroke="black" />
<line x1="3" x2="5"  y1="6" y2="6" stroke-width="1" stroke="black" />
</svg>

Allen|Postgres
------|---
A > B | A >> B

```sql
select '[8,15]'::int4range >> '[3,5]'::int4range;
```

L'opérateur _Succède_ (>) est le transposé de l'opérateur _Précède_ (<).

### 3. Égale

A _Égale_ B lorsque les bornes inférieures et supérieures de chaque intervalle sont égales.

<svg viewbox="0 0 20 8" width="200" height="80">
<text x="6" y="2" font-size="1.8" text-anchor="middle">A</text>
<text x="6" y="6" font-size="1.8" text-anchor="middle">B</text>
<line x1="3" x2="10" y1="3" y2="3" stroke-width="1" stroke="black" />
<line x1="3" x2="10" y1="7" y2="7" stroke-width="1" stroke="black" />
</svg>

Allen |Postgres
------|---
A = B | A = B


```sql
select '[3,10]'::int4range = '[3,10]'::int4range;
```

L'opérateur _Égale_ (=) est son propre transposé.

### 4. Rencontre / rejoint

A _Rencontre_ (meets) B lorsque la borne supérieure de A moins la borne inférieure de B est égale à une unité.

Allen|Postgres
---|---
A m B | A -\|- B

<svg viewbox="0 0 20 8" width="200" height="80">
<text x="5"  y="3" font-size="1.8" text-anchor="middle">A</text>
<text x="11" y="5" font-size="1.8" text-anchor="middle">B</text>
<line x1="3" x2="7" y1="4" y2="4" stroke-width="1" stroke="black" />
<line x1="7" x2="15" y1="6" y2="6" stroke-width="1" stroke="black" />
</svg>

```sql
select '[3,6]'::int4range -|- '[7,14]'::int4range;
```

L'opérateur _Rencontre_ (m) a comme transposé l'opérateur _Rencontré par_ (mi). `i` pour inverse.

### 5. Chevauche / intersecte

A chevauche (overlaps) B lorsque la borne supérieure de A est supérieure à la borne inférieure de B sans que la borne inférieure de A soit supérieure à la borne supérieure de B.

<svg viewbox="0 0 20 8" width="200" height="80">
<text x="5"  y="3" font-size="1.8" text-anchor="middle">A</text>
<text x="11" y="5" font-size="1.8" text-anchor="middle">B</text>
<line x1="3" x2="8"  y1="4" y2="4" stroke-width="1" stroke="black" />
<line x1="5" x2="14" y1="6" y2="6" stroke-width="1" stroke="black" />
</svg>

Allen|Postgres
-------|---
A o B  | A && B

```sql
select '[3,8]'::int4range && '[5,14]'::int4range;
```

L'opérateur _Chevauche_ (o) a comme transposé l'opérateur _Est chevauché par_ (oi). `i` pour inverse.

### 6. Pendant

A se déroule _Pendant_ (during) B lorque la borne inférieure de A est supérieure à la borne inférieure de B et que la borne supérieure de A est inférieure à la borne supérieure de B.

<svg viewbox="0 0 20 8" width="200" height="80">
<text x="5"  y="3" font-size="1.8" text-anchor="middle">A</text>
<text x="11" y="5" font-size="1.8" text-anchor="middle">B</text>
<line x1="7" x2="10" y1="4" y2="4" stroke-width="1" stroke="black" />
<line x1="5" x2="14" y1="6" y2="6" stroke-width="1" stroke="black" />
</svg>

Allen|Postgres
------|---
A d B | A <@ B 

```sql
select '[7,10]'::int4range <@ '[5,14]'::int4range;
```

L'opérateur _Pendant_ (d) a comme transposé l'opérateur _Contient_ (di). `i` pour inverse.

### 7. Contient

A _Contient_ B lorsque la borne inférieure de A est inférieure à la borne inférieure de B et que la borne supérieure de A est supérieure à la borne supérieure de B.

Allen |Postgres
------|---
A di B | A @> B 

<svg viewbox="0 0 20 8" width="200" height="80">
<text x="5"  y="3" font-size="1.8" text-anchor="middle">A</text>
<text x="11" y="5" font-size="1.8" text-anchor="middle">B</text>
<line x1="5" x2="14" y1="4" y2="4" stroke-width="1" stroke="black" />
<line x1="7" x2="10" y1="6" y2="6" stroke-width="1" stroke="black" />
</svg>

```sql
select '[5,14]'::int4range @> '[7,10]'::int4range;
```

L'opérateur _Contient_ (di) est le transposé de l'opérateur _Pendant_ (d).

### 8. Commence

A _Commence_ en même temps (starts) que B lorsque la borne inférieure de A est égale à la borne inférieure de B.

<svg viewbox="0 0 20 8" width="200" height="80">
<text x="5"  y="3" font-size="1.8" text-anchor="middle">A</text>
<text x="11" y="5" font-size="1.8" text-anchor="middle">B</text>
<line x1="5" y1="4" x2="10" y2="4" stroke-width="1" stroke="black" />
<line x1="5" y1="6" x2="14" y2="6" stroke-width="1" stroke="black" />
</svg>

Allen |Postgres
------|---
A s B | A &> B

```sql
select '[5,15]'::int4range &> '[5,10]'::int4range;
```

L'opérateur _Commence_ (s) a comme transposé l'opérateur _Débuté par_ (si). `i` pour inverse.

### 9. Finit

A _Finit_ en même temps (finishes) que B lorsque la borne supérieure de A est égale à la borne supérieure de B.

<svg viewbox="0 0 20 8" width="200" height="80">
<text x="5"  y="3" font-size="1.8" text-anchor="middle">A</text>
<text x="11" y="5" font-size="1.8" text-anchor="middle">B</text>
<line x1="5"  x2="15" y1="4" y2="4" stroke-width="1" stroke="black" />
<line x1="10" x2="15" y1="6" y2="6" stroke-width="1" stroke="black" />
</svg>

Allen|Postgres
------|---
A f B | A &< B 

```sql
select '[5,15]'::int4range &< '[10,15]'::int4range;
```

L'opérateur _Finit_ (f) a comme transposé l'opérateur _Terminé par_ (fi). `i` pour inverse.

## Opérateurs combinatoires

### Union

<svg viewbox="0 0 20 8" width="200" height="80">
<text x="5"  y="3" font-size="1.8" text-anchor="middle">A</text>
<text x="11" y="5" font-size="1.8" text-anchor="middle">B</text>
<line x1="5" x2="10" y1="4" y2="4" stroke-width="1" stroke="black" />
<line x1="8" x2="15" y1="6" y2="6" stroke-width="1" stroke="black" />
<line x1="8" x2="15" y1="6" y2="6" stroke-width="1" stroke="black" />
</svg>

```sql
select '[5,10]'::int4range + '[8,15]'::int4range;
```
### Intersection

<svg viewbox="0 0 20 8" width="200" height="80">
<text x="5"  y="2" font-size="1.8" text-anchor="middle">A</text>
<text x="11" y="6" font-size="1.8" text-anchor="middle">B</text>
<line x1="5" x2="10" y1="4" y2="4" stroke-width="1" stroke="black" />
<line x1="8" x2="15" y1="6" y2="6" stroke-width="1" stroke="black" />
<line x1="8" x2="15" y1="6" y2="6" stroke-width="1" stroke="black" />
</svg>

```sql
select '[5,10]'::int4range * '[8,15]'::int4range;
```

### Difference

<svg viewbox="0 0 20 8" width="200" height="80">
<text x="5"  y="2" font-size="1.8" text-anchor="middle">A</text>
<text x="11" y="6" font-size="1.8" text-anchor="middle">B</text>
<line x1="5" x2="10" y1="4" y2="4" stroke-width="1" stroke="black" />
<line x1="8" x2="15" y1="6" y2="6" stroke-width="1" stroke="black" />
<line x1="8" x2="15" y1="6" y2="6" stroke-width="1" stroke="black" />
</svg>

```sql
select '[5,10]'::int4range - '[8,15]'::int4range;
```

- https://fr.wikipedia.org/wiki/-Alg%C3%A8bre_des_intervalles_d%27Allen
- https://drops.dagstuhl.de/opus/volltexte/2018/9776/pdf/LIPIcs-TIME-2018-11.pdf
