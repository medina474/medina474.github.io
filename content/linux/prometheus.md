---
title: Prometheus
---

### Ajouter un utilisateur

useradd -r -s /usr/sbin/nologin -U -M prometheus

-r user system gid < 1000


curl -o- https://github.com/prometheus/prometheus/releases/download/v2.52.0/prometheus-2.52.0.linux-amd64.tar.gz

tar -xvf prometheus-2.52.0.linux-amd64.tar.gz -C /opt/prometheus

mkdir /var/lib/prometheus


etc/prometheus/prometheus.yaml

scrape_configs:
  - job_name: 'node_exporter'
    static_configs:
      - targets: ['localhost:9100']


node exporter

curl -LO https://github.com/prometheus/node_exporter/releases/download/v1.8.1/node_exporter-1.8.1.linux-amd64.tar.gz
tar -xvf node_exporter-1.8.1.linux-amd64.tar.gz -C /opt
rm node_exporter-1.8.1.linux-amd64.tar.gz
/opt/node_exporter/node_exporter

### mysqld exporter

[Unit]
Description=Prometheus exporter for MySQL server metrics
Documentation=https://github.com/prometheus/mysqld_exporter

[Service]
User=prometheus
Group=prometheus
Restart=on-failure
ExecStart=/opt/mysqld_exporter/mysqld_exporter \
  --config.my-cnf /etc/prometheus/.my.cnf
ExecReload=/bin/kill -HUP $MAINPID
TimeoutStopSec=20s
SendSIGKILL=no

[Install]
WantedBy=multi-user.target
