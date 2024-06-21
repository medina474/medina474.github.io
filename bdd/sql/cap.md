---
title: CAP
---

Le théorème CAP, également connu sous le nom de théorème de Brewer, est un principe fondamental en informatique distribuée. Il énonce qu'il est impossible pour un système informatique distribué de garantir simultanément les trois propriétés suivantes :

1. **Cohérence (Consistency)** : Tous les nœuds voient les mêmes données en même temps. En d'autres termes, toutes les lectures reçoivent la même réponse la plus récente.

2. **Disponibilité (Availability)** : Chaque demande reçoit une réponse (succès ou échec), mais sans garantie que cette réponse soit la plus récente.

3. **Tolérance au partitionnement (Partition Tolerance)** : Le système continue de fonctionner même en cas de défaillance ou de perte de communication entre des parties du système.

Le théorème CAP stipule que dans tout système distribué, il est possible d'optimiser seulement **deux** des trois propriétés à la fois, mais **jamais** les trois simultanément. Cela signifie qu'un système distribué doit faire un compromis en fonction de ses priorités :

- **CA (Cohérence et Disponibilité)** : Le système est cohérent et disponible, mais peut ne pas tolérer les partitions du réseau. Un système qui favorise la cohérence et la disponibilité pourrait être une base de données relationnelle traditionnelle, qui nécessite une connexion constante pour assurer l'intégrité des transactions.

- **CP (Cohérence et Tolérance au Partitionnement)** : Le système est cohérent et peut tolérer les partitions du réseau, mais peut ne pas toujours être disponible. Un système qui favorise la cohérence et la tolérance au partitionnement pourrait être un système bancaire, où il est crucial que toutes les transactions soient enregistrées de manière cohérente même en cas de problèmes réseau, au prix de la disponibilité temporaire.

- **AP (Disponibilité et Tolérance au Partitionnement)** : Le système est disponible et tolère les partitions du réseau, mais peut ne pas toujours être cohérent. Un système qui favorise la disponibilité et la tolérance au partitionnement pourrait être un service de réseau social où la disponibilité est essentielle, même si cela signifie que certaines lectures ne sont pas toujours à jour.
 
