---
title: Requêtes temporelles
---

> Logique d’intervalles d’Allen : ensemble complet d’opérateurs booléens de base pour le positionnement relatif dans le temps.

### précède

A précède à B

<svg viewbox="0 0 20 8" width="200" height="80">
<line x1="3" y1="4" x2="5" y2="4" stroke-width="1" stroke="black" />
<line x1="8" y1="6" x2="15" y2="6" stroke-width="1" stroke="black" />
<svg>

Allen|Postgres
---|---
<  |<<

### succède

A succède à B

<svg viewbox="0 0 20 8" width="200" height="80">
<line x1="13" y1="4" x2="15" y2="4" stroke-width="1" stroke="black" />
<line x1="3" y1="6" x2="10" y2="6" stroke-width="1" stroke="black" />
<svg>


Allen|Postgres
---|---
>  |>>


### égale

### rencontre / rejoint

meet

Allen|Postgres
---|---
m  |-\|-

<svg viewbox="0 0 20 8" width="200" height="80">
<line x1="3" y1="4" x2="7" y2="4" stroke-width="1" stroke="black" />
<line x1="7" y1="6" x2="14" y2="6" stroke-width="1" stroke="black" />
<svg>

### chevauche / intersecte

overlap

Allen|Postgres
---|---
o  |&&

<svg viewbox="0 0 20 8" width="200" height="80">
<line x1="3" y1="4" x2="7" y2="4" stroke-width="1" stroke="black" />
<line x1="7" y1="6" x2="14" y2="6" stroke-width="1" stroke="black" />
<svg>

### pendant

during

Allen|Postgres
---|---
d  |

<svg viewbox="0 0 20 8" width="200" height="80">
<line x1="3" y1="4" x2="7" y2="4" stroke-width="1" stroke="black" />
<line x1="7" y1="6" x2="14" y2="6" stroke-width="1" stroke="black" />
<svg>

### commence

Allen|Postgres
---|---
s  |

<svg viewbox="0 0 20 8" width="200" height="80">
<line x1="3" y1="4" x2="7" y2="4" stroke-width="1" stroke="black" />
<line x1="7" y1="6" x2="14" y2="6" stroke-width="1" stroke="black" />
<svg>

### finit


Allen|Postgres
---|---
f  |

<svg viewbox="0 0 20 8" width="200" height="80">
<line x1="3" y1="4" x2="7" y2="4" stroke-width="1" stroke="black" />
<line x1="7" y1="6" x2="14" y2="6" stroke-width="1" stroke="black" />
<svg>

= 	equal 	int4range(1,5) = '[1,4]'::int4range 	t

<> 	not equal 	numrange(1.1,2.2) <> numrange(1.1,2.3) 	t

< 	less than 	int4range(1,10) < int4range(2,3) 	t
> 	greater than 	int4range(1,10) > int4range(1,5) 	t

<= 	less than or equal 	numrange(1.1,2.2) <= numrange(1.1,2.2) 	t
>= 	greater than or equal 	numrange(1.1,2.2) >= numrange(1.1,2.0) 	t

@> 	contains range 	int4range(2,4) @> int4range(2,3) 	t
@> 	contains element 	'[2011-01-01,2011-03-01)'::tsrange @> '2011-01-10'::timestamp 	t
<@ 	range is contained by 	int4range(2,4) <@ int4range(1,7) 	t
<@ 	element is contained by 	42 <@ int4range(1,7) 	f

&& 	overlap (have points in common) 	int8range(3,7) && int8range(4,12) 	t
<< 	strictly left of 	int8range(1,10) << int8range(100,110) 	t
>> 	strictly right of 	int8range(50,60) >> int8range(20,30) 	t
&< 	does not extend to the right of 	int8range(1,20) &< int8range(18,20) 	t
&> 	does not extend to the left of 	int8range(7,20) &> int8range(5,10) 	t
-|- 	is adjacent to 	numrange(1.1,2.2) -|- numrange(2.2,3.3) 	t
- https://fr.wikipedia.org/wiki/-Alg%C3%A8bre_des_intervalles_d%27Allen
- https://drops.dagstuhl.de/opus/volltexte/2018/9776/pdf/LIPIcs-TIME-2018-11.pdf
