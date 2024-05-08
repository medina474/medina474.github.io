---
title: Operateurs
---

>Un **opérateur** est un symbole qui indique au programme qu'il faut effectuer des opérations mathématiques ou logiques spécifiques.
{.definition}

## Opérateurs de signe

Supposons que la variable **a** a pour valeur 7

Opérateur |	Description |	Exemple
---|---|---
\+	 | positif	 |	a + -5 = 2
\−	 | inversion de signe	 |	a − +5 = 2

## Opérateurs arithmétiques

Supposons que la variable **a** a pour valeur 7 et que la variable **b** la valeur 19 alors :

Opérateur |	Description |	Exemple
---|---|---
\+	 | Addition	 |	a + b = 26
−	 | Soustraction	 |	a − b = -12
\*	 | Multiplication	 |	a * b = 133
/	 | Division	 |	b / a = 2
%	 | Modulo, reste de la division entière	|	b % a = 5
++ | Opérateur d'incrémentation<br>augmente la valeur entière de 1. | a++ = 8
-- | Opérateur de décrémentation<br>diminue la valeur entière de 1. | a\-\- = 6

## Opérateurs relationnels

Supposons que la variable **a** a pour valeur 7 et que la variable **b** la valeur 19 alors :

Opérateur |	Description |	Exemple
---|---|---
== |	Vérifie si les valeurs de deux opérandes sont égales ou non. Si oui, alors la condition devient vraie.	| a == b n'est pas vrai.
!= |	Vérifie si les valeurs de deux opérandes sont égales ou non. Si les valeurs ne sont pas égales, la condition devient vraie.	| a != b est vrai.
\>	| Vérifie si la valeur de l'opérande gauche est supérieure à la valeur de l'opérande droit. Si oui, alors la condition devient vraie.	| a > b n'est pas vrai.
<	| Vérifie si la valeur de l'opérande gauche est inférieure à la valeur de l'opérande droit. Si oui, alors la condition devient vraie.	| a < b est vrai.
\>= |	Vérifie si la valeur de l'opérande gauche est supérieure ou égale à la valeur de l'opérande droit. Si oui, alors la condition devient vraie.	| a >= b n'est pas vrai.
<= |	Vérifie si la valeur de l'opérande gauche est inférieure ou égale à la valeur de l'opérande droit. Si oui, alors la condition devient vraie.	| a <= b est vrai.

Le résultat des opérateurs conditionnels sont 1 pour la condition vraie et 0 pour la condition fausse;

## Opérateurs logiques

Supposons que la variable **a** a pour valeur 1 et que la variable **b** la valeur 0 alors :

Opérateur |	Description |	Exemple
---|---|---
&&	| **ET logique**. Si les deux opérandes sont différents de zéro, la condition devient vraie.	| a && b est faux.
\|\|	| **OU logique**. Si l'un des deux opérandes est différent de zéro, la condition devient vraie. | a \|\| b est vrai.
!	| **NON logique**. Il est utilisé pour inverser l'état logique de son opérande. Si une condition est vraie, alors l'opérateur logique NON la rendra fausse. | !(a && b) est vrai.

En savoir plus sur les [opérateurs logiques](logique)

## Opérateurs bit-à-bit

Les opérateurs bit-à-bit travaillent sur chacun des bits des opérandes. la table de vérité des opérateurs &, |, and ^ est la suivante.

a	| b	| a & b	| a \| b | a ^ b
---|---|---|---|---
0	| 0	| 0	| 0	| 0
0	| 1	| 0	| 1	| 1
1	| 1	| 1	| 1	| 0
1	| 0	| 0	| 1	| 1

Supposons que la variable **a** a pour valeur 60 et que la variable **b** la valeur 13 alors :

a = 0011 1100\
b = 0000 1101


a&b = 0000 1100
a|b = 0011 1101
a^b = 0011 0001
~a = 1100 0011

Supposons que la variable **a** a pour valeur 60 et que la variable **b** la valeur 13 alors :


Opérateur |	Description |	Exemple
---|---|---
&	| L'opérateur **ET binaire** copie un bit dans le résultat s'il existe dans les deux opérandes.	| (A & B) = 12, i.e., 0000 1100
\|	| L'opérateur **OU binaire** copie un bit s'il existe dans l'un ou l'autre des opérandes.	| (A \| B) = 61, i.e., 0011 1101
^	| L'opérateur **XOR binaire** copie le bit s'il est défini dans un opérande mais pas dans les deux.	| (A ^ B) = 49, i.e., 0011 0001
~	| L'opérateur de complément est unaire et a pour effet de "basculer" les bits.	| (~a ) = ~(60), i.e,. -0111101
\<\<	| Opérateur de **décalage binaire à gauche**. La valeur des opérandes de gauche est déplacée vers la gauche du nombre de bits spécifié par l'opérande de droite.	| a << 2 = 240 i.e., 1111 0000
\>\>	| Opérateur de **décalage binaire vers la droite**. La valeur des opérandes de gauche est déplacée vers la droite du nombre de bits spécifié par l'opérande de droite.	| a >> 2 = 15 i.e., 0000 1111

En savoir plus sur les [opérateurs bit-à-bit](bit)

## Opérateurs d'affectation

Les opérateurs d'affection combinent l'affectation simple aux autre opérateurs pour simplifier l'écriture d'une formule.

Opérateur |	Description |	Opérateur | Équivalence
---|---|---|---
=	| Opérateur d'affectation simple. Attribue les valeurs des opérandes de droite à l'opérande de gauche c = a + b attribuera la valeur de a + b à c
+=	| Addition et affectation |	a += 5 | a = a + 5
-=	| Soustraction et affectation	| a -= 5 | a = a - 5
*=	| Miltiplication et affectation	| a *= 5 | a = a * 5
/=	| Division et affectation	| a /= 5 | a = a / 5
%=	| Modulo et affectation	| a %= 5 | a = a % 5
<<=	| Décallage à gauche et affectation	| a <<= 2 | a = a << 2
\>>=	| Décallage à droite et affectation	| a >>= 2 | a = a >> 2
&=	| Et binaire et affectation	| a &= 2 | a = a & 2
^=	| Ou exclusif et affectation	| a ^= 2 | a = a ^ 2
\|=	| Ou binaire et affectation	| a \|= 2 | a = a | 2

## Autres

Outre les opérateurs évoqués ci-dessus, il existe quelques autres opérateurs importants.

Opérateur |	Description |	Exemple
---|---|---
sizeof()	| Renvoie la taille d'une variable. sizeof(a), où a est un entier, renverra 4.
&	 | Renvoie l'adresse d'une variable. &a renvoie l'adresse réelle de la variable.
\*	| Pointeur de la variable	*a;
? :	| Expression conditionnelle.

## Priorité et ordre d’évaluation

La priorité des opérateurs détermine le groupement des termes dans une expression et décide comment une expression est évaluée. Certains opérateurs ont une priorité plus élevée que d'autres ; par exemple, l'opérateur de multiplication a une priorité plus élevée que l'opérateur d'addition.

Par exemple, x = 7 + 3 * 2; ici, x est assigné à 13, pas 20 parce que * a une priorité plus élevée que +. On effecture d'abord la multiplication 3 * 2, puis on ajoute 7.

Les opérateurs avec la plus haute priorité apparaissent en haut du tableau, ceux avec la plus basse apparaissent en bas. Dans une expression, les opérateurs de priorité supérieure seront évalués en premier.

Categorie | Opérateurs | Associativité
---	|---|---
Préfixe		| () [] -> . ++ \-\-		| de gauche à droite
Unaire		| + - ! ~ ++ \-\- (type)* & sizeof	| de droite à gauche
Multiplicative 	| 	* / %		| de gauche à droite
Additive		| + -		| de gauche à droite
Décallage	| << >>		| de gauche à droite
Relationnelle		| < <= > >=		| de gauche à droite
Égalité		| == !=		| de gauche à droite
Et binaire		| &		| de gauche à droite
Ou exclusif		| ^		| de gauche à droite
Ou binaire	| 	\|	| de gauche à droite
Et logique	| 	&&	| de gauche à droite
Ou logique	| \|\|		| de gauche à droite
Ternaire	| ?: |	de droite à gauche
Assignation	| = += -= *= /= %=>>= <<= &= ^= \|=	|de droite à gauche
Séquence | , | de gauche à droite
