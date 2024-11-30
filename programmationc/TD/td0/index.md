---
title: Installation de l'environnement de développement
---


Télécharger W64DevKit pour Windows

[https://github.com/skeeto/w64devkit](https://github.com/skeeto/w64devkit)

Dans la rubrique Releases (bandeau à droite)

Prendre l'executable pour 64 bits

Installer sur la partition D:\

Modifier les variables d'environnement pour votre compte

Dans la variable Path ajouter D:\w64devkit\bin

Lancer VSCode

Ajouter l'extension C/C++ de Microsoft

### Exercice A : Premier programme

Créer un dossier TP dans D:\

Ouvrir ce dossier avec VSCode

La fonction puts en C est utilisée pour afficher une chaîne de caractères (_string_) sur la sortie standard, généralement la console.

Une particularité de puts est qu'après avoir affiché la chaîne, elle ajoute automatiquement un caractère de nouvelle ligne (\n). Cela signifie que le curseur passe à la ligne suivante après l'affichage du texte.

Créer un fichier td0a.c

```c
#include <stdio.h>

void main() {
  puts("Bonjour Jérôme");
}
```

Cliquer sur l'icone de menu Run & Debug

Créer 2 fichier dans le dossier ***.vscode***


tasks.json

```json
{
  "version": "2.0.0",
  "tasks": [
    {
      "type": "cppbuild",
      "label": "Compilation",
      "command": "gcc.exe",
      "args": [
        "-fdiagnostics-color=always",
        "-g",
        "${workspaceFolder}${pathSeparator}main.c",
        "-o",
        "${workspaceFolderBasename}.exe"
      ],
      "options": {
        "cwd": "${workspaceFolder}"
      },
      "problemMatcher": [
        "$gcc"
      ],
      "group": {
        "kind": "build",
        "isDefault": true
      },
      "presentation": {
        "reveal": "silent",
        "revealProblems": "onProblem",
        "close": true
      }
    }
  ]
}
```

launch.json

```json
{
  "version": "0.2.0",
  "configurations": [
    {
      "name": "Lancer",
      "type": "cppdbg",
      "request": "launch",
      "program": "${workspaceFolder}${pathSeparator}${workspaceFolderBasename}.exe",
      "args": [],
      "stopAtEntry": false,
      "cwd": "${workspaceFolder}",
      "environment": [],
      "externalConsole": false,
      "MIMode": "gdb",
      "miDebuggerPath": "gdb",
      "setupCommands": [
        {
          "description": "Enable pretty-printing for gdb",
          "text": "-enable-pretty-printing",
          "ignoreFailures": true
        },
        {
          "description": "Set Disassembly Flavor to Intel",
          "text": "-gdb-set disassembly-flavor intel",
          "ignoreFailures": true
        }
      ],
      "preLaunchTask": "Compilation"
    }
  ]
}
```
