---
title: Informatique Industrielle
---

> Le langage C reste aujourd'hui très utilisé, notamment pour le développement du noyau des systèmes d'exploitation, des logiciels embarqués et des applications nécessitant des performances élevées. Sa simplicité, sa proximité avec le matériel et sa portabilité sont les principales raisons de son succès durable.
{:.definition}

- [Histoire du langage C](histoire)

## Caractéristiques

- Langage de programmation procédural ;
- Langage de bas niveau : conçu pour être compilé en un nombre d’instructions machine prévisible en termes d’occupation mémoire et de charges de calcul ;
- Langage extrêmement utilisé dans :
  - La programmation embarquée sur micro-contrôleurs ;
  - Les calculs intensifs ;
  - L’écriture du noyau de systèmes d’exploitation ;
  - Les modules où la rapidité de traitement est importante.

Sa syntaxe de base a inspiré de nombreux langages plus récents dont C++, Java et PHP, C#, JavaScript, ...

### Avantages

- Nombre restreint de concepts, ce qui facilite sa maîtrise ;
- Nombre restreint de mots clés, ce qui facilite l’apprentissage ;
- Proche de la machine : opérateurs proches du langage machines et fonctions permettant un accès direct au système ;
- Programmation modulaire : permet de gérer plusieurs ﬁchiers sources ⇒ structuration, compréhensibilité et réutilisation du code ;
- Grand nombre de bibliothèques tierces existantes.

### Inconvénients

- Pas universel car la génération des exécutables dépend du compilateur et donc de la cible ;
- Langage bas niveau oﬀrant peu de fonctionnalités notamment pour la gestion de la mémoire et les chaînes de caractères ;
- Pas de gestion eﬃcace des erreurs et beaucoup de libertés laissées au programmeur ⇒ rigueur et discipline de programmation ;
- Bibliothèque standard assez pauvre.


## Concepts

- [Anatomie d'un programme](anatomie)
- [La compilation](compilation)
- [Les variables](variables)

### Opérateurs

- [Opérateurs d'affectation](opérateurs/affectation)
- [Opérateurs arithmétiques](opérateurs/arithmétiques)
- [Opérateurs logiques](opérateurs/logique)
- [Opérateurs bit à bit](opérateurs/bit)

### Les instructions

- [Instructions conditionnelles](instructions/conditions)
- [Instructions de boucles](instructions/boucles)
- [Instructions de débranchement](instructions/debranchement)

### Les programmation avancée

- [Les pointeurs](variables/pointeurs)
- [Les chaines de caractères](string)
- [Les structures](variables/structure)
- [Les fichiers](fichiers)
- [Lecture et écriture en bloc](fichiers/bloc)
- [Les fonctions mathématiques](math)

## Travaux dirigés

- [Installation de l'environnement de développement](td)
- [Travaux dirigés 1](TD/td1)
- [Travaux dirigés 2](TD/td2) 
- [Travaux dirigés 3](TD/td3) : lecture d'un fichier texte
- [Travaux dirigés 4](TD/td4) : structure
- [Travaux dirigés 5](TD/td5) : Lecture d'un fichier tsv, écriture binaire
- [Travaux dirigés 6](TD/td6) : Lecture mixte
