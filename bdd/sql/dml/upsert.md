## Upsert

## Renvoyer des données à partir de lignes modifiées

Il est parfois utile d'obtenir des données à partir de lignes modifiées pendant leur manipulation. Les commandes INSERT, UPDATE et DELETE ont toutes une clause RETURNING facultative qui prend en charge cela. L'utilisation de RETURNING évite d'effectuer une requête supplémentaire dans la base de données pour collecter les données et s'avère particulièrement utile lorsqu'il serait autrement difficile d'identifier de manière fiable les lignes modifiées.

Le contenu autorisé d'une clause RETURNING est le même que celui de la liste de sortie d'une commande SELECT (voir Section 7.3). Il peut contenir des noms de colonnes de la table cible de la commande ou des expressions de valeurs utilisant ces colonnes. Un raccourci courant est RETURNING *, qui sélectionne toutes les colonnes de la table cible dans l'ordre.

Dans un INSERT, les données disponibles pour RETURNING sont la ligne telle qu'elle a été insérée. Ce n'est pas très utile dans les insertions triviales, car cela répéterait simplement les données fournies par le client. Mais cela peut être très pratique lorsque l’on s’appuie sur des valeurs par défaut calculées. Par exemple, lorsque vous utilisez une colonne série pour fournir des identifiants uniques, RETURNING peut renvoyer l'ID attribué à une nouvelle ligne :
