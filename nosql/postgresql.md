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

```
FROM postgres:16.4
```

### API REST



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
      PGRST_DB_URI: postgres://${POSTGREST_USER:-postgrest}:${DB_PASSWORD}@${POSTGREST_HOST:-postgresql}:${POSTGREST_DB_PORT:-5432}/${DB_NAME:-postgrest}
      PGRST_DB_SCHEMAS: ${POSTGREST_DB_SCHEMAS:-public}
      PGRST_DB_ANON_ROLE: ${POSTGREST_DB_ANON_ROLE:-postgrest}
      PGRST_JWT_SECRET: ${POSTGREST_JWT_SECRET}
      PGRST_DB_USE_LEGACY_GUCS: ${POSTGREST_DB_USE_LEGACY_GUCS:-false}
      PGRST_APP_SETTINGS_JWT_SECRET: ${POSTGREST_APP_SETTINGS_JWT_SECRET}
      PGRST_APP_SETTINGS_JWT_EXP: ${POSTGREST_APP_SETTINGS_JWT_EXP}
```
