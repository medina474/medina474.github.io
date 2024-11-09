---
title: Télémétrie
---

### Grafana

```sh
wget -q -O - https://apt.grafana.com/gpg.key | gpg --dearmor | sudo tee /etc/apt/keyrings/grafana.gpg > /dev/null
echo "deb [signed-by=/etc/apt/keyrings/grafana.gpg] https://apt.grafana.com stable main" | sudo tee -a /etc/apt/sources.list.d/grafana.list
sudo apt-get update && sudo apt-get install grafana-enterprise -y
```

Editer le fichier /etc/default/grafana-server

```
GF_AUTH_ANONYMOUS_ENABLED=true
GF_AUTH_ANONYMOUS_ORG_ROLE=Admin
GF_AUTH_DISABLE_LOGIN_FORM=true
GF_USERS_DEFAULT_THEME=light
GF_USERS_ALLOW_SIGN_UP=false
```

Redemarrer Grafana

```sh
sudo systemctl stop grafana-server && sudo systemctl start grafana-server
```

### Loki

```sh
sudo apt-get update && sudo apt-get install loki -y
```
