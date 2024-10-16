---
title: Postgresql
---

### Installation de PostgreSQL

```yaml
  postgresql:
    container_name:  r5a10-postgresql
    build:
      context: ./postgresql
    healthcheck:
      test: ["CMD-SHELL", "sh -c 'pg_isready -U postgres -d ${DB_NAME}'"]
      interval: 15s
      timeout: 5s
      retries: 5
      start_period: 30s
    restart: no
    configs:
      - source: postgresql_initdb
        target: /docker-entrypoint-initdb.d/
    volumes:
      - postgresql:/var/lib/postgresql/data
      - ./data:/data
    ports:
      - 5432:5432
    environment:
      POSTGRES_USER: ${POSTGRES_USER:-postgres}
      POSTGRES_PASSWORD: ${DB_ROOT_PASSWORD}
```

Fichier **Dockerfile**

Partir d'une image de base postgresql 16.4 et ajouter les extensions nécessaire

```
FROM postgres:16.4
```

**postGis** extension géographique, **pgRouting** calcul d'itinéraire

```
RUN set -eux; \
  apt-get update; \
  apt-get -y install \
    postgresql-16-postgis-3 \
    postgresql-16-pgrouting;
```

**Apache Age** extension permettant de travailler sur des graphes et avec le langage Cypher.

```
RUN set -eux; \
  apt-get update; \
  apt-get -y install \
    postgresql-16-age;
```

### API REST

PostgREST est une solution open-source qui transforme une base de données PostgreSQL en une API RESTful complète de manière automatique. Cela permet de créer une API basée sur les données contenues dans une base PostgreSQL, sans avoir à écrire manuellement du code backend. 

API RESTful basée sur PostgreSQL :

Chaque table, vue et fonction SQL devient un endpoint d'API accessible via des requêtes HTTP standard (GET, POST, PATCH, DELETE).

```yaml
  postgrest:
    container_name:  r5a10-postgrest
    image: postgrest/postgrest:${POSTGREST_VERSION:-v12.2.2}
    restart: no
    depends_on:
      postgresql:
        condition: service_healthy
    command: postgrest
    ports:
      - 3005:3000
    environment:
      PGRST_DB_URI: postgres://${POSTGREST_USER:-postgres}:${DB_ROOT_PASSWORD}@${POSTGREST_HOST:-postgresql}:${POSTGREST_DB_PORT:-5432}/${DB_NAME:-northwind}
      PGRST_DB_SCHEMAS: ${POSTGREST_DB_SCHEMAS:-public}
      PGRST_DB_ANON_ROLE: ${POSTGREST_DB_ANON_ROLE:-postgres}
      PGRST_JWT_SECRET: ${POSTGREST_JWT_SECRET}
      PGRST_DB_USE_LEGACY_GUCS: ${POSTGREST_DB_USE_LEGACY_GUCS:-false}
      PGRST_APP_SETTINGS_JWT_SECRET: ${POSTGREST_APP_SETTINGS_JWT_SECRET}
      PGRST_APP_SETTINGS_JWT_EXP: ${POSTGREST_APP_SETTINGS_JWT_EXP}
```

### API GraphQL

PostGraphile est un outil open-source qui génère une API GraphQL entièrement fonctionnelle à partir d'une base de données PostgreSQL. Contrairement à PostgREST, qui génère une API REST, PostGraphile se concentre sur la génération d'une API GraphQL en exploitant directement les schémas et données de PostgreSQL.

[GraphQL](graphe/graphql)

fichier compose

```yaml
 postgraphile:
   container_name: r5a10-postgraphile
   build:
     context: ./postgraphile
   restart: no
   depends_on:
     postgresql:
       condition: service_healthy
   command:
     [
       "--port", "${POSTGRAPHILE_PORT:-5000}",
       "--schema", "${POSTGRAPHILE_SCHEMA:-public}",
       "--enhance-graphiql",
       "--cors",
       "--allow-explain",
       "--dynamic-json",
       "--append-plugins",
       "postgraphile-plugin-connection-filter,postgraphile-plugin-fulltext-filter,@graphile/postgis,postgraphile-plugin-connection-filter-postgis"
     ]
   ports:
     - 3006:5000
   environment:
     - PGHOST=${POSTGRAPHILE_HOST:-postgresql}
     - PGPORT=${POSTGRAPHILE_DB_PORT:-5432}
     - PGUSER=${POSTGRAPHILE_DB_USER:-postgres}
     - PGPASSWORD=${DB_ROOT_PASSWORD}
     - PGDATABASE=${DB_NAME:-northwind}
```

Dockerfile Postgraphile

```
FROM node:alpine
LABEL description="Instant high-performance GraphQL API for your PostgreSQL database https://github.com/graphile/postgraphile"

# Install PostGraphile and PostGraphile connection filter plugin
RUN npm install -g postgraphile &&\
  npm install -g postgraphile-plugin-connection-filter &&\
  npm install -g @graphile/postgis  &&\
  npm install -g postgraphile-plugin-connection-filter-postgis &&\
  npm install -g postgraphile-plugin-fulltext-filter

EXPOSE 5000
ENTRYPOINT ["postgraphile", "-n", "0.0.0.0", "--cors"]
```

### FerretDB

Clone de MongoDB mais avec postgreSQL

```json
  ferretdb:
    container_name: r5a10-ferretdb
    image: ghcr.io/ferretdb/ferretdb
    healthcheck:
      test: ["CMD", "/ferretdb", "ping"]
      interval: 30s
      timeout: 5s
      retries: 3
      start_period: 20s
    ports:
      - 27017:27017
      - 8088:8088
    volumes:
      - ferretdb:/state
    environment:
      FERRETDB_POSTGRESQL_URL: postgres://postgres:supermotdepasse@postgresql:5432/ferretdb
      FERRETDB_TELEMETRY: disable
```

### Metabase

Analyse des données


```json
  metabase:
    container_name: r5a10-metabase
    image: metabase/metabase:latest
    healthcheck:
      test: curl --fail -I http://localhost:3000/api/health || exit 1
      interval: 15s
      timeout: 5s
      retries: 5
    depends_on:
      postgresql:
        condition: service_healthy
    volumes:
      - /dev/urandom:/dev/random:ro
    ports:
      - 3002:3000
    environment:
      MB_DB_TYPE: ${MB_DB_TYPE:-postgres}
      MB_DB_HOST: ${MB_DB_HOST:-postgresql}
      MB_DB_PORT: ${MB_DB_HOST:-5432}
      MB_DB_USER: ${MB_DB_USER:-postgres}
      MB_DB_PASS: ${DB_ROOT_PASSWORD}
      MB_DB_DBNAME: ${MB_DB_DBNAME:-metabase}
      MB_SITE_LOCALE: fr
      MB_ADMIN_EMAIL: etudiant@univ-lorraine.fr
      MB_ANON_TRACKING_ENABLED: false
      MB_CHECK_FOR_UPDATES: false
      MB_NO_SURVEYS: yes
      MB_START_OF_WEEK: monday
      MB_CUSTOM_FORMATTING: '{"type/Temporal":{"time_style":"HH:mm","date_style":"D MMMM, YYYY","date_abbreviate":true},"type/Currency":{"currency":"EUR"},"type/Number":{"number_separators":", "}}'
      MB_EMAIL_SMTP_HOST: mailpit
      MB_EMAIL_SMTP_PORT: 1025
      MB_EMAIL_FROM_ADDRESS: metabase@univ-lorraine.fr
```

### Grafana

```json
  grafana:
    container_name: r5a10-grafana
    image: grafana/grafana-oss:${GRAFANA_VERSION:-11.1.3}
    restart: no
    depends_on:
      mariadb:
        condition: service_healthy
    deploy:
      resources:
        limits:
          memory: 100M
    volumes:
      - grafana:/var/lib/grafana
    ports:
      - 3001:3000
    environment:
      GF_SECURITY_ADMIN_EMAIL: etudiant@univ-lorraine.fr
      GF_SECURITY_ADMIN_PASSWORD: supermotdepasse
      GF_USERS_DEFAULT_THEME: light
      GF_USERS_ALLOW_SIGN_UP: false
      GF_FEATURE_TOGGLES_ENABLE: traceQLStreaming metricsSummary lokiFormatQuery alertmanagerRemoteOnly
```
