Flutter est un **framework**, un ensemble d'outil pour développer des applications Web, Windows, Android et iOS à partir d'un socle commun.

Flutter est développé par Google c'est donc une alternative sérieuse et crédible aux développements d'applications natives.

Le langage utilisé est **Dart**, une évolution de javascript qui utilise un **typage fort**.

Flutter reprend des concepts de React tout en les améliorant. Toute l'application est pensée en forme de Widget qui vont vivre et se rafraîchir de manière indépendante.

Les **widgets** : ils permettent de décrire simplement le rendu final. Chaque objet est défini indépendamment des contraintes parentes. C’est son emplacement dans le code qui permettra de définir ses contraintes extérieures. Cela permet de construire facilement son interface ; le code est alors plus facilement lisible et maintenable.

Les **composants** : ils ont été recréés par Google. Les développeurs disposent d’une galerie de composants s’adaptant à IOS comme Android, et aux différentes versions d’OS. Cependant une pléthore de composants hétéroclites quelque fois pas maintenu et conçus pour le même objectif ne rendent pas la tâche du développeur facile.


## Les concurrents

### React Native

React Native est une solution multiplateforme lancée par Facebook en 2015, utilisant le Javascript et ayant vite fait ses preuves au sein de la communauté des développeurs. Aujourd’hui, son principal avantage face à Flutter est son ancienneté (facilité pour le développeur de trouver des bibliothèques ou du support). Néanmoins, Flutter rattrape bien son retard grâce à sa possibilité de personnaliser les éléments d’interface, et ses performances supérieures à son concurrent direct.

https://reactnative.dev/

### .Net MAUI (ex Xamarin)

.Net Multi-platform App UI est un framework de développement mobile multiplateforme utilisant le langage C# et le framework .NET core.
Il ea étét fondé en 2011 (à la base appelé « Mono for Android » et « MonoTouch » pour iOS) et fût racheté en 2016 par Microsoft. Bien qu’il soit une alternative forte au développement d’applications natives, il reste tout de même nécessaire d’écrire des parties de code spécifiques à chaque plateforme. Aujourd’hui, les applications natives sont plutôt développées en Kotlin et Swift profitant des dernières optimisations alors que Xamarin base sa partie native sur les langages Java et Objective-C. (Paragraphe à revoir)

Flutter est plus accessible pour les développeurs et propose un tronc commun pour toute l’application, ce qui apporte un gain de temps substantiel.

https://learn.microsoft.com/fr-fr/dotnet/maui/what-is-maui?view=net-maui-7.0

## Installation

[Télécharger](https://flutter.dev/docs/get-started/install/windows) Flutter pour votre OS.

Installer le, comme indiqué dans la documentation (mettre à jour le path)

Utiliser Visual Studio Code, et installer les plugins [Dart](https://marketplace.visualstudio.com/items?itemName=Dart-Code.dart-code) et [Flutter](https://marketplace.visualstudio.com/items?itemName=Dart-Code.flutter)

Avec Visual Studio Code lancer l'outil de diagnostic **flutter doctor** à partir du menu View, Command
Palette (Ctrl Maj P)
