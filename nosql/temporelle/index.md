---
title: Base de données temporelles
----

```yaml
  prometheus:
    container_name: r5a10-prometheus
    image: prom/prometheus:${PROMETHEUS_VERSION:-v2.53.0}
    restart: no
    command:
      - '--config.file=/etc/prometheus/prometheus.yml'
    configs:
      - source: prometheus_config
        target: /etc/prometheus/prometheus.yml
    volumes:
      - prometheus:/prometheus
    ports:
      - 9090:9090
```
