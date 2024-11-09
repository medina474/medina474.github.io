---
title: Loki
---

```sh
sudo apt-get update && sudo apt-get install loki -y
```

```http
POST http://100.64.98.36:3100/loki/api/v1/push
Content-Type: application/json

{
  "streams": [
    {
      "stream": { "service_name": "test", "level": "INFO" },
      "values": [
          [ "1731140583000000000", "Démarrage pompe 1" ],
          [ "1731140600000000000", "Arrêt pompe 1" ]
      ]
    }
  ]
}
```

```
sudo apt-get install libcurl4-openssl-dev
```

```c
#include <stdio.h>
#include <curl/curl.h>

int envoyer_log_a_loki(const char *json_payload) {
    CURL *curl = curl_easy_init();
    if (curl) {
        CURLcode res;
        curl_easy_setopt(curl, CURLOPT_URL, "http://<loki-host>:<loki-port>/loki/api/v1/push");

        // Ajout du type de contenu JSON
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/json");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        // Données JSON
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json_payload);

        // Envoi de la requête
        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            fprintf(stderr, "Erreur: %s\n", curl_easy_strerror(res));
        }

        // Libération des ressources
        curl_easy_cleanup(curl);
        curl_slist_free_all(headers);
        return (res == CURLE_OK) ? 0 : 1;
    }
    return 1;
}
```

Dans cet exemple, le payload JSON doit être formatté au format attendu par Loki.
2. Vector ou Fluent Bit comme Agent de Log

Si vous préférez éviter d'intégrer directement les appels HTTP dans votre code, vous pouvez utiliser un agent de log comme Datadog Vector ou Fluent Bit pour envoyer les messages à Loki. Voici comment :

Votre programme en C écrit les logs dans un fichier ou dans stdout.
Configurez Vector ou Fluent Bit pour surveiller ces logs et les transférer vers Loki.

3. Utilisation d’OpenTelemetry

OpenTelemetry fournit des SDK pour plusieurs langages, mais pas directement pour C. Toutefois, il est possible d'utiliser un exporteur OpenTelemetry compatible avec Loki pour envoyer des logs. Cela implique toutefois d'intégrer une bibliothèque intermédiaire (par exemple, en C++) ou de passer par un exporteur tiers.

Ces solutions permettent de contourner l'absence de SDK Loki en C et facilitent l'envoi de logs depuis une application C vers Loki pour les visualiser dans Grafana.
