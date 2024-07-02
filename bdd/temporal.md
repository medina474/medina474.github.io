---
title: Requêtes temporelles
---

> Logique d’intervalles d’Allen : ensemble complet d’opérateurs booléens de base pour le positionnement relatif dans le temps.

Un intervalle possède un début d et une fin f, tels que d < f.

Deux intervalles A et B peuvent se positionner selon 13 configurations.

### Précède

A précède B

<svg viewbox="0 0 20 8" width="200" height="80">
<text y="3" x="4" font-size="1.8" text-anchor="middle">A</text>
<text y="5" x="11" font-size="1.8" text-anchor="middle">B</text>
<line x1="3" x2="5"  y1="4" y2="4" stroke-width="1" stroke="black" />
<line x1="8" x2="15" y1="6" y2="6" stroke-width="1" stroke="black" />
<svg>

Allen|Postgres
---|---
A < B | A << B

```sql
select '[3,5]'::int4range << '[8,15]'::int4range;
```

### Succède

A succède à B. 

<svg viewbox="0 0 20 8" width="200" height="80">
<text y="3" x="14" font-size="1.8" text-anchor="middle">A</text>
<text y="5" x="6" font-size="1.8" text-anchor="middle">B</text>
<line x1="8" x2="15" y1="4" y2="4" stroke-width="1" stroke="black" />
<line x1="3" x2="5"  y1="6" y2="6" stroke-width="1" stroke="black" />
<svg>

Allen|Postgres
------|---
A > B | A >> B

```sql
select '[8,15]'::int4range >> '[3,5]'::int4range;
```

L'opérateur Succède (>) est le transposé de l'opérateur Précède (<).

### Égale

<svg viewbox="0 0 20 8" width="200" height="80">
<text y="2" x="6" font-size="1.8" text-anchor="middle">A</text>
<text y="6" x="6" font-size="1.8" text-anchor="middle">B</text>
<line x1="3" x2="10" y1="3" y2="3" stroke-width="1" stroke="black" />
<line x1="3" x2="10" y1="7" y2="7" stroke-width="1" stroke="black" />
<svg>

Allen|Postgres
------|---
A = B | A = B


```sql
select '[3,10]'::int4range = '[3,10]'::int4range;
```

L'opérateur Égale (=) est son propre transposé.

### Rencontre / rejoint

A rencontre (meets) B

Allen|Postgres
---|---
A m B | A -\|- B

<svg viewbox="0 0 20 8" width="200" height="80">
<text y="2" x="6" font-size="1.8" text-anchor="middle">A</text>
<text y="6" x="6" font-size="1.8" text-anchor="middle">B</text>
<line x1="3" x2="7" y1="4" y2="4" stroke-width="1" stroke="black" />
<line x1="7" x2="14" y1="6" y2="6" stroke-width="1" stroke="black" />
<svg>

```sql
select '[3,6]'::int4range -|- '[7,14]'::int4range;
```

L'opérateur Rencontre (m) a comme transposé l'opérateur Rencontré par (mi). `i` pour inverse.

### Chevauche / intersecte

A chevauche (overlaps) B 

<svg viewbox="0 0 20 8" width="200" height="80">
<line x1="3" x2="8"  y1="4" y2="4" stroke-width="1" stroke="black" />
<line x1="5" x2="14" y1="6" y2="6" stroke-width="1" stroke="black" />
<svg>

Allen|Postgres
-------|---
A o B  | A && B

```sql
select '[3,8]'::int4range && '[5,14]'::int4range;
```

L'opérateur _Chevauche_ (o) a comme transposé l'opérateur _Est chevauché par_ (oi). `i` pour inverse.

### Pendant

A se déroule pendant (during) B

<svg viewbox="0 0 20 8" width="200" height="80">
<line x1="7" x2="10" y1="4" y2="4" stroke-width="1" stroke="black" />
<line x1="5" x2="14" y1="6" y2="6" stroke-width="1" stroke="black" />
<svg>

Allen|Postgres
------|---
A d B | A <@ B 

```sql
select '[7,10]'::int4range <@ '[5,14]'::int4range;
```

L'opérateur _Pendant_ (d) a comme transposé l'opérateur _Contient_ (di). `i` pour inverse.

### Contient

A contient B

Allen |Postgres
------|---
A di B | A @> B 

<svg viewbox="0 0 20 8" width="200" height="80">
<line x1="5" x2="14" y1="4" y2="4" stroke-width="1" stroke="black" />
<line x1="7" x2="10" y1="6" y2="6" stroke-width="1" stroke="black" />
<svg>

```sql
select '[5,14]'::int4range @> '[7,10]'::int4range;
```

L'opérateur _Contient_ (di) est le transposé de l'opérateur _Pendant_ (d).

### Commence

A commence en même temps (starts) que B

<svg viewbox="0 0 20 8" width="200" height="80">
<line x1="5" y1="4" x2="10" y2="4" stroke-width="1" stroke="black" />
<line x1="5" y1="6" x2="14" y2="6" stroke-width="1" stroke="black" />
<svg>

Allen |Postgres
------|---
A s B | A &> B

```sql
select '[5,15]'::int4range &> '[5,10]'::int4range;
```

L'opérateur Commence (s) a comme transposé l'opérateur Débuté par (si). `i` pour inverse.

### Finit

A finit en même temps (finishes) que B

<svg viewbox="0 0 20 8" width="200" height="80">
<line x1="5"  x2="15" y1="4" y2="4" stroke-width="1" stroke="black" />
<line x1="10" x2="15" y1="6" y2="6" stroke-width="1" stroke="black" />
<svg>

Allen|Postgres
------|---
A f B | A &< B 

```sql
select '[5,15]'::int4range &< '[10,15]'::int4range;
```

L'opérateur Finit (f) a comme transposé l'opérateur Terminé par (fi). `i` pour inverse.



<svg viewbox="0 0 20 8" width="200" height="80">
<line x1="3" y1="4" x2="7" y2="4" stroke-width="1" stroke="black" />
<line x1="7" y1="6" x2="14" y2="6" stroke-width="1" stroke="black" />
<svg>


- https://fr.wikipedia.org/wiki/-Alg%C3%A8bre_des_intervalles_d%27Allen
- https://drops.dagstuhl.de/opus/volltexte/2018/9776/pdf/LIPIcs-TIME-2018-11.pdf
