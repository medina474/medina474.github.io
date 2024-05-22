---
title: SVG
---

### Etape 1 : Détail d'un film

Lorsque l'on clique sur une ligne d'un film  afficher les détails de ce film.

URL de l'API :
https://morseweiswlpykaugwtd.supabase.co/functions/v1/film`,

Appel en POST

Paramètres : { "film_id": *** }


![films](film.png)

![films](film-2.png)


### Etape 2 : Notation

Ajouter 5 étoiles et les colorier les étoiles en fonction de la note du film

Etoile

```
<path d="m50,2 12,34h36l-28,22 10,34-30-20-30,20 10-34-28-22h36z" />
```

Attention : il faut pouvoir colorier des fractions d'étoiles

Indications : Utiliser le masquage SVG et les variables CSS
