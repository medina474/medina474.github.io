---
title: Applications natives
---

> **Objectif :** Concevoir une application pour une plateforme spécifique afin de bénéficier des **meilleures performances**.
{: .objectif}

Une application « **native** » est conçue avec les **outils de développement officiels** et spécifiques à l'appareil sur lequel elle sera installée.

Une application « native » permet d'exploiter toute la puissance et les possibilités matérielles offertes par le terminal. En effet le langage de développement est compilé en **langage machine**, ce qui signifie que l'application est exécutable directement par le terminal. Un programme compilé est en général plus rapide que le même programme écrit dans un langage dit **interprété**.

Les langages de développement des différentes plateformes sont eux aussi très différents.

Il est donc nécessaire de concevoir et développer l’application **autant de fois** que de plateformes pour lesquelles ont veut distribuer l'application. Et les développeurs maîtrisent en général l’un ou l’autre de ces environnements.

![iOS](ios.webp){: .h-8 .align-middle} [iOS](ios)

![Android](android.png){: .h-8 .align-middle} [Android](android)

![Windows](windows.png){: .h-8 .align-middle} [Windows](windows)

### Définitions

Langage interprété
: La traduction se produit en **temps réel** pendant l'exécution. Ainsi, le langage requiert la présence d'un **interpréteur** pour exécuter le programme (appelé dans ce cas script). L'avantage est qu'un même script peut fonctionner sur différentes plateformes, mais la traduction du code à chaque exécution peut affecter les performances. Exemple de langages interprétés : JavaScript, Python, PHP, Ruby, Perl

Langage semi-interprété
: Le code source est d'abord traduit dans un langage intermédiaire (appelé bytecode) qui est un langage pour une machine virtuelle générique. La traduction du bytecode par la machine virutelle est plus rapide q'une interprétation d'un script textuel, les performances sont ainsi normalement préservées.
Exemple de langages interprétés : Java, C#, PHP (avec Facebook HHVM)

Langage compilé
: La traduction se fait sur une machine de développement par un compilateur qui génère un fichier exécutable “une fois pour toutes“. Cela impose donc de compiler le programme pour chaque plateforme ou variante de destination.
Exemple de langages compilés : C/C++, Swift, Rust, Go, Pascal
