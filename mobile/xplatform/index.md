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

### .Net MAUI (ex Xamarin)

.Net Multi-platform App UI est un framework de développement mobile multiplateforme utilisant le langage C# et le framework .NET core.
Il ea étét fondé en 2011 (à la base appelé « Mono for Android » et « MonoTouch » pour iOS) et fût racheté en 2016 par Microsoft. Bien qu’il soit une alternative forte au développement d’applications natives, il reste tout de même nécessaire d’écrire des parties de code spécifiques à chaque plateforme. Aujourd’hui, les applications natives sont plutôt développées en Kotlin et Swift profitant des dernières optimisations alors que Xamarin base sa partie native sur les langages Java et Objective-C. (Paragraphe à revoir)

L'interface responsive en XML utilise XAML

Flutter est plus accessible pour les développeurs et propose un tronc commun pour toute l’application, ce qui apporte un gain de temps substantiel.

https://learn.microsoft.com/fr-fr/dotnet/maui/what-is-maui?view=net-maui-7.0
[https://dotnet.microsoft.com/en-us/](https://dotnet.microsoft.com/en-us/)


### React Native

React Native est un framework d'applications mobiles créé par Facebook sur la base de son framework existant React. Il est utilisé pour développer des applications natives pour Android, iOS et UWP en utilisant le langage Javascript et donc la librairie React..

> La plus grande erreur que nous ayons commise en tant que société a été de parier trop sur HTML par opposition au natif. - Mark Zuckerberg, 2012 -

<img src="react.png" height="64">

[https://reactnative.dev/](https://reactnative.dev/)



React Native est une solution multiplateforme lancée par Facebook en 2015, utilisant le Javascript et ayant vite fait ses preuves au sein de la communauté des développeurs. Aujourd’hui, son principal avantage face à Flutter est son ancienneté (facilité pour le développeur de trouver des bibliothèques ou du support). Néanmoins, Flutter rattrape bien son retard grâce à sa possibilité de personnaliser les éléments d’interface, et ses performances supérieures à son concurrent direct.


### Flutter

[Flutter](flutter)


### Kotlin Multiplatform 

https://www.jetbrains.com/kotlin-multiplatform/
