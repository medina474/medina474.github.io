---
title: Hugo
---

Télécharger la version extended du générateur [Hugo](https://gohugo.io/installation/).

Vérifier que le binaire hugo.exe se trouve dans un _dossier accessible_ à `PATH`

```
hugo version

hugo v0.110.0-e32a493b7826d02763c3b79623952e625402b168+extended windows/amd64 BuildDate=2023-01-17T12:16:09Z VendorInfo=gohugoio
```

Créer un nouveau site

```shell-session
hugo new site projet
```

Placer vous dans le dossier `projet`

### Git

```shell-session
$ git init
```

Ajouter le fichier `.gitignore` à la racine du dossier

```
# Generated files by hugo
/public/
/resources/_gen/
/assets/jsconfig.json
hugo_stats.json

# Temporary lock file while building
/.hugo_build.lock
```

## Créer les pages

```
hugo new _index.md
hugo new variables\_index.md
```

Les pages créées sont dans le dossier `content`

Dans le dossier `layouts/_default` créer une page `list.html`
Le layout `list.html` est utilisé par le contenu _index


```html
<!doctype html>
<html class="no-js" lang="{{ .Site.Language.Lang }}">

<head>
  <meta charset="utf-8">
  <title>{{ .Title }} | {{ .Site.Title }}</title>
</head>

<body>
  <h1>{{ .Title }}</h1>
  {{ .Content }}
</body>
</html>
```


```shell-session
hugo -D
```

Les pages générées sont dans le dossier public

Ajouter dans `config.toml`

```toml
[markup.highlight]
  style = 'vs'
  tabWidth = 2
```

### Build avec Visual Studio Code

```json
{
	"version": "2.0.0",
	"tasks": [
		{
			"label": "echo",
			"type": "shell",
			"command": "hugo -D",
			"group": {
				"kind": "build",
				"isDefault": true
			}
		}
	]
}
```

Appuyez maintenant sur ctrl+maj+B pour lancer la compilation du site

### Publier qur Gitlab Pages

Créer un fichier `.gitlab-ci.yml`


```yaml
image: registry.gitlab.com/pages/hugo/hugo_extended:latest

variables:
  GIT_SUBMODULE_STRATEGY: recursive

pages:
  script:
  - hugo
  artifacts:
    paths:
    - public
  rules:
  - if: $CI_COMMIT_BRANCH == $CI_DEFAULT_BRANCH
```
