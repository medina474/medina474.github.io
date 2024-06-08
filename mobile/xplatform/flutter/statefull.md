---
title: Statefull
---

Un widget Statefull est un widget avec état, ce qui signifie qu'il possède un objet State (défini ci-dessous) qui contient des champs qui **affectent** son apparence.

La classe State est la configuration de l'état. Il contient les valeurs (dans ce cas le titre) fournies par le parent (dans ce cas le widget App) et utilisées par la méthode build de l'État. Les champs d'une sous-classe de widget sont toujours marqués « final ».
