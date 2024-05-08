---
title: Chaines de caracteres
---

En langage C le tableau se comporte comme un pointeur aux différences suivantes :
I La réservation de la zone mémoire est dimensionnée par sa déclaration
(ex : int tab[100]) ;
I Cette zone mémoire ne peut pas être redimensionnée. On dit alors que la
taille du tableau est statique.

Si je déclare int tab[100], alors tab (le nom du tableau) est un pointeur
contenant l’adresse du premier élément du tableau.
tab = &tab[0];
*tab = *(&tab[0]) = tab[0];

En langage C, le codage utilisé pour les caractères est le codage ASCII (étendu
pour les accents). Une table de code ASCII est disponible ici.
Les différents codes courants (en décimal) sont les suivants :
I ’ ’ (espace) ⇒ 32 ;
I ’0’ à ’9’ : ⇒ 48 à 57 ;
I ’A’ à ’Z’ : ⇒ 65 à 90 ;
I ’a’ à ’z’ : ⇒ 97 à 122.

En se basant sur la relation de précédence alphabétique des caractères, nous
pouvons définir une précédence lexicographique pour les chaînes de caractères.
Cette relation de précédence qui suit l’ordre du dictionnaire est définie de la
manière suivante :
I La chaîne vide "" précède lexicographiquement toutes les autres chaînes ;
I La chaîne A = a1a2...ap (p caractères) précède lexicographiquement la
chaîne B = b1b2...bm (m caractères) si l’une des deux conditions suivantes
est remplie :
X a1 < b1 ;
X a1 = b1 et a2a3...ap précède lexicographiquement b2b3...bm

• "ABC" précède "BCD" car ’A’<’B’ ;
• "ABC" précède "B" car ’A’<’B’ ;
• "Abc" précède "abc" car ’A’<’a’ ;
• "ab" précède "abcd" car "" précède "cd" ;
• " ab" précède "ab" car ’ ’<’a’ (le code ASCII de ’ ’ est 32, et le
code ASCII de ’a’ est 97).
Il ne faut pas oublier que l’ordinateur travaille avec les codes ASCII ! ! !

Contrairement aux langage plus évolués (Java, C++, PHP, ...), il n’existe
pas en C de type prédéfini chaîne de caractères.
Or, dans tout programme informatique qui se respecte, les chaînes de
caractères sont très utilisées afin de stocker des informations non numériques
comme par exemple une liste de noms, d’adresses, de références, ....
Par conséquent, il existe quand même des notations particulières et une bonne
quantité de fonctions spéciales pour le traitement des chaînes de caractères
que nous allons étudier ici.

En langage C, les chaînes de caractères sont des tableaux de caractères.
Leur déclaration est donc analogue à celle d’un tableau à une dimension :
