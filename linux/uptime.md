
---
title: Uptime Kuma
---

### Ajouter un utilisateur

useradd -r -s /usr/sbin/nologin -U -M uptime

#### Se connecter avec cet utilisateur

su -l uptime -s /bin/bash

#### Installer nvm

curl -o- https://raw.githubusercontent.com/nvm-sh/nvm/v0.39.7/install.sh | bash

nvm install lts
nvm list
npm install -g npm@latest

cd opt/
git clone https://github.com/louislam/uptime-kuma.git
cd uptime-kuma/
npm run setup

which node

/etc/systemd/system/uptime.service

```
[Unit]
Description=Uptime Kuma
After=network-online.target

[Service]
User=uptime
Group=uptime
Restart=on-failure
WorkingDirectory=/opt/uptime-kuma
ExecStart=/home/uptime/.nvm/versions/node/v20.14.0/bin/node server/server.js

[Install]
WantedBy=multi-user.target
```

systemctl enable uptime
systemctl start uptime
systemctl status uptime
journalctl -u uptime
