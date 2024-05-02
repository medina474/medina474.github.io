---
title: Compilation cross plateforme
---

> **Objectif :** Obtenir des performances natives en utilisant un langage différent du système mais commun à plusieurs
plateformes permettant d'écrire le programme une seule fois

La compilation cross plateforme utilise un langage autre que celui préconisé par défaut par le constructeur de
l'appareil. Cela permet d'utiliser un langage déjà connu d'un développeur et de l'utiliser sur plusieurs plateformes.
Cette approche est appelée WORA Write once, run anywhere

Les performances sont proches d'une application native, cependant des librairies d'adaptation et/ou ou micro machines
virtuelles sont nécessaires à l'exécution du programme, elles ralentissent le programme de manière imperceptible mais
surtout augmentent grandement la taille de l'exécutable.

Les solutions sont :

### Xamarin

Xamarin est le fruit du portage de la plateforme .Net sur la plateforme Linux. Ce portage open source appelé Mono n'était pas conduit par Microsoft et violait sa propriété industrielle. Cependant Microsoft considéra que cette diffusion lui était profitable et s'engagea à ne pas poursuivre les auteurs ni demander de royalties. En 2016 Microsoft l'achète et l'intègre dans sa suite Visual Studio et en fait son outil officiel. Toujours en 2016 Microsoft opère un virage open source et lance .Net Core un réécriture complète et multi-plateforme de .Net. Xamarin est abandonné en 2022, mais son successeur est là.

<img src="xamarin.png" height="64">

### .Net MAUI

.Net MAUI (Multi-platform App UI) est le successeur de Xamarin. Ce langage est basé sur C# et des fichiers de description d'interface responsive en XML.
Encore peur rependu Microsoft espère que son utilisation progressera.

[https://dotnet.microsoft.com/en-us/](https://dotnet.microsoft.com/en-us/)

### ReactNative

React Native est un framework d'applications mobiles créé par Facebook sur la base de son framework existant React. Il est utilisé pour développer des applications natives pour Android, iOS et UWP en utilisant le langage Javascript et donc la librairie React..

> La plus grande erreur que nous ayons commise en tant que société a été de parier trop sur HTML par opposition au natif. - Mark Zuckerberg, 2012 -

<img src="react.png" height="64">

[https://reactnative.dev/](https://reactnative.dev/)

### Flutter
