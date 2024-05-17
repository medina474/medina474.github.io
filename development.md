---
title: Développement Linux sur PC
---

> Développer à distance depuis Visual Studio Code sur PC.
{:.info}

## WSL2 Sous système Linux pour Windows

https://docs.microsoft.com/fr-fr/windows/wsl/install-win10

Activer la fonctionalité Windows Subsystem Linux

```>shell
$ dism.exe /online /enable-feature /featurename:Microsoft-Windows-Subsystem-Linux /all /norestart
```

Activer la fonctionalité Virtual Machine Platform

```>shell
$ dism.exe /online /enable-feature /featurename:VirtualMachinePlatform /all /norestart
```

Passer WSL en version 2

```>shell
$ wsl --set-default-version 2
```

## Docker

Utiliser un container [Docker](docker).

---

## À distance par SSH

Activer le client OpenSSH de Windows (Settings - Apps & Features - Optional features)

Créer un dossier `.ssh` dans votre dossier utilisateur sur le PC (`C:\Users\VotreLogin\.ssh`)

Toujours dans le dossier `.ssh` créer un fichier `config`.

```
Host Raspberry08
  User pi
  HostName 192.168.1.17
  ForwardAgent yes
  StrictHostKeyChecking no
```

### Agent Forwarding

Un fois sur l'hôte distant vous allez avoir besoin de votre clé pour accédéer à GitLab par exemple. Plutôt que de stocker votre clé privée sur l'hôte distant (Le Raspberry) Nous allons activer l'Agent Forwarding pour passer votre clé d'hôte en hôte.

Si l'Agent ne fonctionne pas

Utiliser avec PuTTYGen pour convertir  la clé PuTTY en clé compatible OpenSSH (Menu - Conversions - Export OpenSSH Keys). Appeler la `id_rsa` et enregistrer la dans le dossier `.ssh`.

Ajouter à l'entrée Host

```
IdentityFile ~/.ssh/id_rsa
```

### Visual Studio Code

Installer l'exention [Remote Development](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.vscode-remote-extensionpack) de Microsoft

Remote Development est une extension qui permet d'ouvrir n'importe quel dossier dans un conteneur (Docker), sur une machine distante en SSH ou une machine WSL et de profiter de l'ensemble des fonctionnalités de VS Code.

F1 - Remote-SSH : Open Configuration File ... et choisir le fichier `config`

F1 - Remote-SSH : Connect to Host

La première fois l'opération prend un certain temps, le temps d'installer tous les outils de communication.

Vous travaillez sur le système distant comme si c'était un dossier local !

Vous pouvez ouvrir un fenêtre terminal sur le système distant.
