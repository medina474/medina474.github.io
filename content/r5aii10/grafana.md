---
title: Grafana
---

Grafana est un outil open source de **visualisation** et de **surveillance de données** principalement utilisé pour analyser et afficher des métriques de performance provenant de diverses sources. Il permet de créer des **tableaux de bord interactifs** et personnalisables pour surveiller des systèmes, des applications et des infrastructures. Grafana supporte de nombreux types de sources de données.

### Installer Grafana

```sh
wget -q -O - https://apt.grafana.com/gpg.key | gpg --dearmor | sudo tee /etc/apt/keyrings/grafana.gpg > /dev/null
echo "deb [signed-by=/etc/apt/keyrings/grafana.gpg] https://apt.grafana.com stable main" | sudo tee -a /etc/apt/sources.list.d/grafana.list
sudo apt-get update && sudo apt-get install --no-install-recommends grafana-enterprise -y
```

Editer le fichier /etc/default/grafana-server

```
GF_AUTH_ANONYMOUS_ENABLED=true
GF_AUTH_ANONYMOUS_ORG_ROLE=Admin
GF_AUTH_DISABLE_LOGIN_FORM=true
GF_USERS_DEFAULT_THEME=light
GF_USERS_ALLOW_SIGN_UP=false
GF_USERS_DEFAULT_LANGUAGE=fr-FR
GF_AUTH_ANONYMOUS_ORG_NAME=IUT
```

```sh
sudo systemctl enable grafana-server
```

Redemarrer le service Grafana

```shell
sudo systemctl restart grafana-server
```

Accéder à Grafana depuis votre navigateur

http://100.68.98.xx:3000/
