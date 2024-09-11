---
title: Perfectionnement en langage C
---

Le langage C reste aujourd'hui très utilisé, notamment pour le développement des systèmes d'exploitation, des logiciels embarqués et des applications nécessitant des performances élevées. Sa simplicité, sa proximité avec le matériel et sa portabilité sont les principales raisons de son succès durable.

Le langage C a été créé au début des années 1970 par Dennis Ritchie aux laboratoires Bell (AT&T) pour réécrire le système d'exploitation UNIX, qui était initialement en langage d'assemblage.

### Langage C original (1972)

La première version du C était étroitement liée à UNIX. Son adoption rapide a fait de C le langage privilégié pour développer des systèmes d’exploitation et des logiciels nécessitant des performances et une gestion fine de la mémoire.

### K & R C (1978)

En 1978, Brian Kernighan et Dennis Ritchie publient le livre de référence "The C Programming Language". C'est la première formalisation du langage C. Ce standard a dominé jusqu'au milieu des années 1980. Il introduisait des concepts tels que les types de données, les structures

### ANSI C (1989) ou C89

Dans les années 1980, le besoin d'un standard plus formel s'est fait sentir, car plusieurs versions divergentes de C étaient utilisées. En 1989, l'ANSI (American National Standards Institute) publie le standard ANSI C ou C89. Cette version standardise plusieurs éléments du langage.

### C90 (1990)

Le standard C89 a été adopté par l'ISO (International Organization for Standardization) en 1990, sous le nom de C90. Les deux versions, ANSI C et C90, sont donc pratiquement identiques.

### C99 (1999) :

En 1999, une révision majeure du langage a été publiée sous le nom de C99. Cette version introduit de nombreuses améliorations, dont :

- La prise en charge des variables déclarées à n’importe quel endroit du code, pas seulement au début d'un bloc.
- Les tableaux dynamiques et les types entiers plus précis.
- Les boucles for avec des variables locales.
- De nouvelles fonctions mathématiques et des améliorations sur la précision des nombres flottants.

### C11 (2011)

Le standard C11 apporte des améliorations pour le rendre plus moderne tout en conservant sa simplicité. Il introduit :

- Le support des threads avec une bibliothèque standard pour le multi-threading.
- La gestion des alignements mémoire.
- De nouvelles fonctionnalités de sécurité

### C18 (2018)

C18 est une version mineure qui clarifie et corrige certaines ambiguïtés du C11 sans ajouter de nouvelles fonctionnalités significatives. Elle se concentre essentiellement sur la correction de bugs et des révisions formelles du langage.

### C2x (à venir)

La prochaine version majeure du langage est en cours de développement sous le nom provisoire C2x. Elle vise à apporter des améliorations sur la sécurité, la simplicité et la compatibilité avec les versions précédentes.

## Caractéristiques

- Langage de programmation procédural ;
- Langage de bas niveau : conçu pour être compilé en un nombre d’instructions machine prévisible en termes d’occupation mémoire et de charges de calcul ;
- Langage extrêmement utilisé dans :
  - La programmation embarquée sur micro-contrôleurs ;
  - Les calculs intensifs ;
  - L’écriture de systèmes d’exploitation ;
  - Les modules où la rapidité de traitement est importante.
- Les noyaux des grands systèmes d’exploitation (UNIX, Windows et Linux) sont développés en grande partie en C ;

Sa syntaxe de base a inspiré de nombreux langages plus récents dont C++, Java et PHP, C#, JavaScript

### Avantages

- Nombre restreint de concepts, ce qui facilite sa maîtrise ;
- Nombre restreint de mots clés, ce qui facilite l’apprentissage ;
- Proche de la machine : opérateurs proches du langage machines et fonctions permettant un accès direct au système ;
- Programmation modulaire : permet de gérer plusieurs ﬁchiers sources ⇒ structuration, compréhensibilité et réutilisation du code ;
- Grand nombre de bibliothèques tierces existantes.

### Inconvénients

- Pas portable car la génération des exécutables dépend du compilateur et donc de la cible ;
- Langage bas niveau oﬀrant peu de fonctionnalités notamment pour la
- Gestion de la mémoire et les chaînes de caractères ;
- Pas de gestion eﬃcace des erreurs et beaucoup de libertés laissées au programmeur ⇒ rigueur et discipline de programmation ;
- Bibliothèque standard assez pauvre.


- [Les variables](variables)
- [Les pointeurs](pointeur)
- [Les chaines de caractères](string)
- [Les structures](structure)
- [Les fichiers](fichier)



## Opérateurs 

- Opérateur d'affectation
- Opérateurs arithmétiques
- Opérateurs d'incrémentation et de décrémentation
- [Opérateurs logiques](logique)
- [Opérateurs bit à bit](bit)
- Opérateurs combinés
- Opérateurs relationnels

- [math](math)

Opérateurs de conversion de type


Les Opérateurs

Les Opérateurs relationnels :

Ils sont utilisés pour les structures conditionnelles, de choix et itératives. Ils permettent de comparer une variable par rapport à une autre variable ou à une valeur ou une expression. Le résultat ne peut être que VRAI ou FAUX.

FAUX : false correspond à 0
VRAI : true correspond à toute valeur ≠ 0
!

Les Opérateurs
Les Opérateurs logiques :
Ils sont utilisés exactement comme les opérateurs relationnels.

Les Opérateurs
 :
Exemple :
Résultat :

Les Opérateurs
L'Opérateur de conversion de type :
Ils existe deux conversions possibles:
 La conversion implicite :
Elle est effectuée pour évaluer le même type de données lors d'évaluation
d'expressions. Les conversions systématiques de char en int, en float, en
double, la conversion se fait toujours du type le plus petit vers le plus
long.
 La conversion explicite :
On peut changer le type d'une variable vers un autre type en utilisant
l'opérateur cast (type) en le mettant devant l'identificateur de la variable
à convertir.
Les Opérateurs
L'opérateur de conversion de type :
Exemple :
Résultat :
!
Les Opérateurs
La priorité
des opérateurs :

https://www.doc.ic.ac.uk/lab/cplus/cstyle.html
https://www.digikey.fr/fr/resources/conversion-calculators/conversion-calculator-resistor-color-code
