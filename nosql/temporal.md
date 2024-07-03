---
title: Requêtes temporelles
---

> Logique d’intervalles d’Allen : ensemble complet d’opérateurs booléens de base pour le positionnement relatif dans le temps.

Un intervalle possède un début d et une fin f, tels que d < f.

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

### Égale

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
