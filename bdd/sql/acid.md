---
title: ACID
---

Les propriétés **ACID** sont un ensemble de caractéristiques essentielles qui garantissent la fiabilité et la cohérence des transactions dans une base de données. Ces propriétés sont particulièrement importantes pour les systèmes de gestion de bases de données relationnelles (SGBDR) afin de maintenir l'**intégrité** des données dans un environnement **multi-utilisateurs**.

Les propriétés **ACID** sont les suivantes :

## 1. Atomicité (Atomicity)

L'atomicité assure que toutes les opérations d'une transaction sont exécutées de manière indivisible et tout ou rien. Si une partie de la transaction échoue, toutes les opérations effectuées jusqu'à ce point sont annulées, et la base de données est ramenée à son état initial. Cela garantit que la base de données reste cohérente en cas d'erreur ou d'interruption.

## 2. Cohérence (Consistency)

La cohérence garantit que la base de données passe d'un état valide à un autre état valide après l'exécution d'une transaction. Cela signifie que chaque transaction doit respecter toutes les règles d'intégrité et de contraintes définies dans la base de données. Si une transaction viole l'une de ces règles, elle est annulée, et la base de données ne sera pas laissée dans un état incohérent.

## 3. Isolation (Isolation)

L'isolation assure que chaque transaction s'exécute de manière isolée des autres transactions en cours. Cela signifie que les résultats d'une transaction ne sont visibles aux autres transactions qu'une fois la transaction terminée et validée. Cela évite les conflits d'accès concurrents et garantit que chaque transaction agit comme si elle était exécutée individuellement, même si plusieurs transactions sont en cours simultanément.

## 4. Durabilité (Durability)

La durabilité garantit que les résultats d'une transaction validée sont persistants et restent disponibles même en cas de panne du système, de redémarrage du serveur ou de tout autre événement imprévu. Une fois qu'une transaction est confirmée, ses modifications sont écrites de manière permanente dans la base de données et ne peuvent pas être perdues.

En respectant ces propriétés ACID, les SGBDR garantissent l'intégrité, la fiabilité et la cohérence des données, ce qui est essentiel pour les applications critiques où l'**exactitude** des informations est primordiale. Cependant, dans certaines situations, la stricte application des propriétés ACID peut entraîner une baisse de performance, notamment dans les systèmes à haute concurrence. Dans ces cas, certains systèmes de bases de données utilisent des mécanismes de contrôle de la concurrence moins stricts, appelés propriétés BASE (Basically Available, Soft-state, Eventually-consistent).
