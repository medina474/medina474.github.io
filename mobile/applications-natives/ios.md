---
title: iOS
---

Les applications natives pour **iPhone** et **iPad** sont développées exclusivement sur un ordinateur **Mac** avec l'IDE **XCode**.

![XCode](xcode.png)

### Les langages spécifiques

Le langage utilisé au départ était **Objective C**, une extension du langage C Ansi. Il a été défini par Brad Cox au début des années 80, tout comme le C++ son concurrent. Ce langage a été choisi par la société Next pour développer son système *NextStep*.

Steve Jobs alors dirigeant de la société Next amène l'ensemble de l'ingénierie de Next lors de son retour chez Apple. Ce système permettra la renaissance d'Apple et le développement de nouveaux produits comme **OS X** et l'**iPhone**.

Le langage est conçu sur l'envoi de messages à des objets. La gestion de la mémoire reste encore sous la responsabilité du programmeur comme en C ou C++.

#### Swift

Pour satisfaire aux besoins d'un langage plus moderne, débarrassé des contraintes rébarbatives de gestion de la mémoire, Apple a conçu en 2014 un nouveau langage le **Swift**.

Objective C et Swift sont des langages exclusivement utilisé par Apple pour ses produits. Même si Apple pousse pour que Swift soit utilisé sur plus de plateformes, cela n'est pas encore le cas.

#### Une exemple en Objective C

```objective-c
-(void)testMethod:(BOOL(^)(NSInteger))guessTheNumber {
  BOOL winner = guessTheNumber(5);
  if( winner ) {
    NSLog(@"We won!");
  }
  else {
    NSLog(@"We lost.");
  }
}

-(void)runTest {
  [self testMethod:^(NSInterger guessTheNumber) {
    BOOL guessedRight = NO;
    if( guessTheNumber == 3) {
      guessedRight = YES;
    }
    return guessedRight;
  }];
}
```

#### Une exemple en Swift

```swift
func sayHelloWorld() -> String {
  return "hello, world"
}

println(sayHelloWorld())
```


### Distribution des applications

Les applications sont **signées numériquement** et doivent être distribués par l'**Apple Store** pour les applications disponibles à une diffusion publique.

Il est possible par le biais de l'abonnement **Apple Developer Enterprise** de diffuser des applications de manière privée au sein d'une organisation comme l'Université par exemple. Cette méthode de distribution est appelée **In-House Distribution**.

### Matériel

le matériel est limité aux produits de la marque Apple : iPhone, iPad et iPad Pro
