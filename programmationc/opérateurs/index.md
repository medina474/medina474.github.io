---
title: Operateurs
---

>Un **opérateur** est un symbole qui indique au programme qu'il faut effectuer des opérations mathématiques ou logiques spécifiques.
{:.definition}

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

Supposons que la variable **a** a pour valeur 60 et que la variable **b** la valeur 13 alors :

En savoir plus sur les [opérateurs bit-à-bit](bit)


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
