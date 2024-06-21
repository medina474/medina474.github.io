###  Développement d'une application de jeu de type Geo Challenge en Flutter

### Contexte :
Vous êtes chargé de développer une application de jeu de questions à choix multiples (QCM) sur les drapeaux des pays. Le jeu comporte trois écrans principaux : l'écran d'accueil où l'utilisateur entre son nom, l'écran du jeu avec les questions, et l'écran des scores affichant le résultat final.

### Exigences Fonctionnelles :

#### Écran d'Accueil :

Inviter l'utilisateur à entrer son nom dans un champ de texte.

Un bouton pour commencer le jeu après avoir entré le nom.

Un appui sur le bouton amène vers le deuxième écran.

#### Écran de Jeu :

Afficher le drapeau d'un pays. (https://morseweiswlpykaugwtd.supabase.co/storage/v1/object/public/flags/code2lettres.webp)
  
Afficher quatre boutons avec des noms de pays (une bonne et trois mauvaises réponses). Les boutons sont arrangés suivant 2 lignes et 2 colonnes

L'utilisateur apuuie sur un bouton qui valide la réponse. L'affichage passe à la question suivante.

Répéter le processus pour un total de 5 questions.

Passer au troisième écran qui affiche le nom du joueur et son score.

Calculer les points en fonction du nombre de bonnes réponses.

_Bonus :_ Déclarer un minuteur (Timer) passer à la question suivante au bout de 5 secondes même sans réponse.


### Exigences Techniques :

- Utilisation du framework Flutter pour le développement de l'application.
- Navigation entre les écrans avec Navigator.

Questions : 
```json
[
  {
    'drapeau': 'vn',
    'reponses': ['Chine', 'Vietnam', 'Corée du nord', 'Maroc'],
    'correct': 'Vietnam'
  },
  {
    'drapeau': 'tn',
    'reponses': ['Singapour', 'Turquie', 'Chine', 'Tunisie'],
    'correct': 'Tunisie'
  },
  {
    'drapeau': 'lr',
    'reponses': ['Liberia', 'États-Unis', 'Malaisie', 'Panama'],
    'correct': 'Liberia'
  },
  {
    'drapeau': 'pe',
    'reponses': ['Autriche', 'Lettonie', 'Monaco', 'Panama'],
    'correct': 'Pérou'
  },
  {
    'drapeau': 'om',
    'reponses': ['Madagascar', 'Oman', 'Bulgarie', 'Bénin'],
    'correct': 'Oman'
  }
]
```

Vous pouvez utiliser des données statiques contenues dans l'application.

_Bonus :_ Recupérer dynamiquement les questions depuis l'API :

```
POST https://morseweiswlpykaugwtd.supabase.co/functions/v1/quizz
Authorization: Bearer eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJzdXBhYmFzZSIsInJlZiI6Im1vcnNld2Vpc3dscHlrYXVnd3RkIiwicm9sZSI6ImFub24iLCJpYXQiOjE3MDY5NTcxMjgsImV4cCI6MjAyMjUzMzEyOH0.UV5XCINWe-Jaw6_-787Veh-LxjzUVudArvrgH6Ycf30
```






Je veux faire une application de jeu en Flutter. Sur le premier écran l’utilisateur est invité a entrer son nom sur le deuxième écran apparaît un jeu de type QCM. L'application interroge une Web API en POST pour récupérer les questions. Un drapeau d'un pays s'affiche ainsi que 4 boutons. Le drapeau est une image distante. Un des bouton est la bonne réponse les 3 autres sot faux. Un minuteur s'affiche car l'utilisateur doit répondre en moins de 15 secondes. Les point sont compté en fonction du nombre de bonnes réponse. Au bout de 5 questions un troisième écran apparaît montrant le score.
