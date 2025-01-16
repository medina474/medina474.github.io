Que stocke un table des faits ?
ChatGPT a dit :
ChatGPT

Une table des faits dans un entrepôt de données (data warehouse) stocke les mesures quantitatives ou les données transactionnelles d'une organisation. Ces données représentent généralement des événements commerciaux ou des transactions qui sont capturés au fil du temps. Les informations stockées dans une table des faits sont souvent numériques et sont utilisées pour l'analyse et les rapports dans un contexte de Business Intelligence.
Composants typiques d'une table des faits :

    Mesures ou faits : Les valeurs numériques (comme les montants de vente, les quantités vendues, les coûts, les revenus) qui sont analysées.
    Clés étrangères : Des références aux tables de dimension (comme la dimension produit, client, date, etc.), qui permettent de donner un contexte aux faits. Ces dimensions définissent le "quoi", le "qui", et le "quand" des faits.
    Granularité : Chaque ligne de la table des faits représente une occurrence d'un événement à un certain niveau de détail (ou granularité), par exemple, une vente par produit, par jour, par magasin.

Exemple :

Dans une table des faits de ventes, on pourrait trouver les colonnes suivantes :

    Clé étrangère du produit
    Clé étrangère du client
    Clé étrangère de la date
    Montant des ventes (mesure)
    Quantité vendue (mesure)

Ces données peuvent ensuite être agrégées ou analysées selon différentes dimensions pour générer des insights stratégiques.
