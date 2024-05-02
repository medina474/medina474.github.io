---
title: "Urlrewriting"
---


La réécriture d’URL (URL rewriting) est une technique qui permet de transformer une adresse URL en une autre. Elle rend les URL plus compréhensibles pour l’utilisateur, plus simples et plus efficaces pour le référencement.

La réécriture d'URL récupère des éléments et/ou des parties de l'adresse URL et les transforme en paramètres. Elle masque les paramètres et la vraie nature des pages (l’extension php disparait ainsi que la vraie localisation du fichier).

Elle est utilisée intensément avec les applications Web.

Exemple :
http://www.domaine.com/change/2024/09/25/MXN

Devient après réécriture
http://www.domaine.com/service.php?action=change&devise=MXN&date=2024-09-25

Activer le module Apache

```
LoadModule rewrite_module modules/mod_rewrite.so
```

Créer un répertoire W:/Apache24/htdocs/rewrite

Configurer les autorisations sur ce répertoire dans httpd.conf :
+	Autoriser l'utilisation de fichier .htaccess  (AllowOveride)
+	Activer la ré écriture  d'URL (RewriteEngine On)
+	Activer l'Option pour le suivi des liens symboliques (SymLinksIfOwnerMatch)
+	Configurer l'URL de base pour le répertoire (RewriteBase)

```
<Directory W:/Apache24/htdocs/rewrite>
  Options +SymLinksIfOwnerMatch
  AllowOverride FileInfo
  RewriteEngine On
  RewriteBase /rewrite/
</Directory>
```

Comme toutes les directives Apache, la configuration du module peut être à défaut écrite dans un fichier .htaccess, mais sa place est prioritairement dans le fichier de configuration d’Apache (httpd.conf) ou de l’hôte virtuel.

L’avantage avec le fichier .htaccess ce qu’il est lu à chaque requête, les performances sont moins bonnes mais il n’est pas nécessaire de redémarrer le service à chaque changement de règle.

La règle ne prend en compte que ce qui est après le répertoire de base.

Une directive de ré écriture est composée d’une règle d’expression régulière, une ré écriture dans le cas où l’url est conforme à la règle et un ou des drapeaux permettant de spécifier des commandes particulières.

```
RewriteRule règle réécriture [drapeaux]
```

Une ou plusieurs conditions peuvent accompagner la règle. Si les conditions sont vraies alors la règle sera évaluée sinon elle sera ignorée.

```
RewriteCond test1 [drapeaux]
RewriteCond test2 [drapeaux]
RewriteRule règle réécriture [drapeaux]
```

## Syntaxe des expressions régulières

### Recherche d’un motif

Cherchons la séquence de lettres « auto » si celui-ci est trouvé alors redirigeons vers la page voiture.html

```
RewriteRule auto voiture.html
```

Créer une page voiture.html

:heavy_check_mark: http://hostname/auto.html\
:heavy_check_mark: http://hostname/auto.php\
:heavy_check_mark: http://hostname/moto.html\
:heavy_check_mark: http://hostname/auto\
:heavy_check_mark: http://hostname/vautour.jpg\
:heavy_check_mark: http://hostname/dossier/15-auto.html\

Créer un fichier php qui va nous permettre d'afficher différentes valeurs passée en paramètre à notre redirection.

```php
<?php
echo 'Redirection<br>';
echo '$0 : '.$_GET['v0'].'<br>';
if (isset($_GET['v1'])) echo '$1 : '.$_GET['v1'].'<br>';
if (isset($_GET['v2'])) echo '$2 : '.$_GET['v2'].'<br>';
if (isset($_GET['v3'])) echo '$3 : '.$_GET['v3'].'<br>';
```

### Commence par : ^

```
RewriteRule ^auto redirection.php?v0=$0
```

:heavy_check_mark: http://hostname/auto.html\
:x: http://hostname/vautour.jpg\
:heavy_check_mark: http://hostname/autour.jpg\
:x: http://hostname/dossier/15-auto.html

### Termine par : $

```
RewriteRule auto$ redirection.php?v0=$0
```

:heavy_check_mark: http://hostname/auto.html
:heavy_check_mark: http://hostname/dossier/15-auto
:x: http://hostname/dossier/15-auto.png


### Un caractère : .

```
RewriteRule a..o$ redirection.php?v0=$0
```

:heavy_check_mark: http://hostname/auto\
:heavy_check_mark: http://hostname/allo\
:x: http://hostname/KTa5bo\
:heavy_check_mark: http://hostname/KTa/$o

### Groupe : ( )

Les groupes permettent de récupérer des variables, appelées références arrières ($1, $2, $3, …), pour chaque groupe.

$0 correspond à la totalité de la règle.

```
RewriteRule au(..)$ redirection.php?v0=$0&v1=$1
```

:heavy_check_mark: http://hostname/auto
:heavy_check_mark: http://hostname/jaune

### Ou : |
Un groupe est donc créé lors de l’utilisation d’un « Ou »
RewriteRule ^auto|moto redirection.php?v0=$0&1=$1

:heavy_check_mark: http://hostname/automobile
:heavy_check_mark: http://hostname/motoculteur

Il est préférable de placer les conditions Ou à l’intérieur d’un groupe (auto|moto)

### Zéro ou un : ?
RewriteRule voiture(s?) redirection.php?v0=$0&v1=$1

:heavy_check_mark: http://hostname/voiture
:heavy_check_mark: http://hostname/voitures
:x: http://hostname/voituresss

Les lettres « s » supplémentaires ne font pas partie de la validation mais ne gênent en rien. Lors de la récupération de la variable une seule lettre « s » sera récupérée. Il faudrait ajouter $ pour indiquer la fin de la chaine.

### Zéro ou plus : *
RewriteRule voiture(s*) redirection.php?v0=$0&v1=$1

:heavy_check_mark: http://hostname/voiture
:heavy_check_mark: http://hostname/voitures
:heavy_check_mark: http://hostname/voituresss


### Zéro ou plus non gourmand : *?

Non gourmand (ungreedy) signifie que la capture va prendre le **moins de caractères possibles** pour satisfaire la règle.
RewriteRule voiture(s*?) redirection.php?v0=$0&v1=$1

:heavy_check_mark: http://hostname/voiture
:heavy_check_mark: http://hostname/voitures
:heavy_check_mark: http://hostname/voituresss

### Un ou plus : +

RewriteRule voiture(s+) redirection.php?v0=$0&v1=$1

- :x: http://hostname/voiture
- :heavy_check_mark: http://hostname/voitures
- :heavy_check_mark: http://hostname/voituresss

### Un ou plus non gourmand : +?
RewriteRule voiture(s+?) redirection.php?v0=$0&v1=$1

- :x: http://hostname/voiture
- :heavy_check_mark: http://hostname/voitures
- :heavy_check_mark: http://hostname/voituresss

### Exactement n fois : {n}

RewriteRule ^x{3}$ redirection.php?v0=$0&v1=$1
n fois ou plus : {n,}
RewriteRule ^x{3,}$ redirection.php?v0=$0&v1=$1
Entre n et m fois : {n,m}
RewriteRule ^x{3,5}$ redirection.php?v0=$0&v1=$1

Si on ne met de délimiteurs (début, fin ou autres caractères), alors les caractères x supplémentaires ne feront pas partie du groupe mais la règle sera validée tout de même.
	{3}	{3,}	{3,5}
http://hostname/xx
http://hostname/xxx

http://hostname/xxxx

http://hostname/xxxxx

http://hostname/xxxxxx

Un ensemble spécifique de caractères : [ ]:
RewriteRule ^[AEIOU]$ redirection.php?v1=$1

http://hostname/A
http://hostname/B
Une plage de caractères : [ - ]
RewriteRule ^([A-D])$ redirection.php?v1=$1

http://hostname/A
http://hostname/B
http://hostname/c
http://hostname/E
Un caractère de l’alphabet : [A-Za-z]
RewriteRule ^([A-Za-z])$ redirection.php?v1=$1

http://hostname/T
http://hostname/t
http://hostname/é

Un caractère de mot : \w
RewriteRule ^(\w+)$ redirection.php?v0=$0&v1=$1

http://hostname/T
http://hostname/t
http://hostname/t0_A
http://hostname/é
\w : correspond à un caractère d'un mot : a-z, A-Z, 0-9, _ (underscore)
\W : un caractère qui n'est pas un caractère de mot
Un chiffre : \d
RewriteRule ^(\d+)$ redirection.php?v0=$0&v1=$1

\d : correspond à un chiffre : 0-9
\D : un caractère qui ne correspond pas à un chiffre

Exercices

Écrire les règles suivantes :
•	Une date sur 4 chiffres commençant par 19xx  ou 20xx
•	Un mois sur 2 chiffres
•	Le jour du mois sur 2 chiffres

/rewrite/2014/09/25/MXN
Devient après réécriture
/rewrite/service.php?action=change&devise=MXN&date=2014-09-25

### Drapeaux
https://craym.eu/tutoriels/referencement/flag_url_rewriting.html

C	Chainée avec la règle suivante
CO cookie	Set specified cookie
E var:­value	Set environmental variable “var” to “value”
F	Interdit (Forbidden) (403 header)
G	Gone - no longer exists
H handler	Set handler
L	Dernière (Last) ; arrête le traitement
N	Continue (Next) ; continue le traitement
NC	Non sensible à la casse (Case insensitive)
NE	Do not escape output
NS	Ignore if subrequest
P	Proxy
PT	Pass through
R[=code]	Redirect to new URL, with optional code (see below)
QSA	Ajoute (Query String Append)
S=x	Skip next x rules
T=mime­-type	Set mime type

### Conditions
https://www.monsite.fr/forum/admin/index.php?page=db&start=30

|variable|description|valeur|
---|---|---

%{REMOTE_ADDR} 	Adresse du client
%{THE_REQUEST} 	La ligne complète de la requête (sans les entêtes) 	GET /forum/admin/index.php?page=db&start=30 HTTP/1.1
%{REMOTE_HOST} |	Nom de la machine cliente ou à défaut son adresse
%{REMOTE_PORT} |	Port utilisé par le client pour la connexion
%{REQUEST_METHOD} |	Méthode HTTP employée par la requête (généralement GET ou POST) 	GET
%{SCRIPT_FILENAME} et %{REQUEST_FILENAME} 	Chemin complet (absolu) du document appelé 	W:/Web/Apache24/htdocs/forum/admin/index.php
%{HTTPS} |	Booléen (valeur on ou off) indiquant l'usage ou non du protocole sécurisé (peut être utilisée indépendamment de la présence ou non du module ssl) 	on
%{QUERY_STRING} |	Les paramètres passés dans l'URL, regroupés sous la forme d'une chaîne. Elle représente toute la partie située après le point d'interrogation (exclus), si tant est qu'elle existe. 	page=db&start=30
(deux paramètres : page de valeur db et start de valeur 30)
%{REQUEST_URI} 	La ressource telle que demandée dans la requête HTTP (voir la variable THE_REQUEST) 	/forum/admin/index.php
%{REMOTE_USER}

### En têtes HTTP

|variable|description|valeur|
---|---|---
HTTP_HOST |	Nom du serveur tel que demandé par le client par l'intermédiaire de l'entête Host |	www.monsite.fr
HTTP_REFERER |	Indique la provenance de l'utilisateur (il est déconseillé de l'utiliser car celle-ci n'est pas fiable et est falsifiable)
HTTP_COOKIE |	Une chaîne regroupant l'ensemble des cookies que le client renvoie 	skin=blue; pref_ordre=asc
(deux cookies : skin de valeur blue et pref_ordre de valeur asc)
HTTP_USER_AGENT |	Identifiant du client |	Mozilla/5.0 (Windows; U; Windows NT 5.1; fr; rv:1.8.1.11) Gecko/20071127 Firefox/2.0.0.11
HTTP_ACCEPT |	Formats acceptés par le client 	| text/xml,application/xml,application/xhtml+xml,text/html; q=0.9,text/plain; q=0.8,image/png,*/*; q=0.5
HTTP_FORWARDED||
HTTP_PROXY_CONNECTION||

### SVariables internes du serveur
%{DOCUMENT_ROOT}

|variable|description|valeur|
---|---|---
DOCUMENT_ROOT | La racine du serveur telle que définie par la directive DocumentRoot |	W:/Web/Apache24/htdocs/
SERVER_NAME | Nom réel du serveur | www.monsite.fr
SERVER_ADMIN | Correspond à la valeur de la directive ServerAdmin attribué au serveur | admin@monsite.fr
SERVER_ADDR | Adresse du serveur
SERVER_PORT | Port d'écoute du serveur (80 : port standard du protocole HTTP et 443 pour HTTPS) | 443
SERVER_PROTOCOL | Description du protocole employé 	HTTP/1.1
SERVER_SOFTWARE | |

 
## Exemples utiles

Forcer un domaine

```
RewriteCond %{HTTP_HOST} ^www.i2mxx.local [NC]
RewriteRule ^(.*)$ http://www.i2mxx.local/$1 [R=301,L]
```

Rediriger vers un protocole sécurisé

```
RewriteCond %{HTTPS} !=on
RewriteRule ^(.*)$ https://www.i2mxx.local/$1 [R=301,L]
```

Forcer à utiliser les minuscules

```
RewriteMap lowercase int:tolower
RewriteCond \$1 [A-Z]
RewriteRule ^/(.*)$ /\${lowercase:\$1} [R=301,L]
```

Forcer tout le trafic à passer par une page unique d’amorçage (bootstrap)

```
RewriteCond %{REQUEST_FILENAME} !-f
RewriteCond %{REQUEST_FILENAME} !-d
RewriteCond %{REQUEST_FILENAME} !-l
RewriteRule .* index.php [L]
```

C’est une voir la règle centrale des applications web. Toutes les requêtes (sauf celles dirigées spécifiquement sur un fichier, un dossier ou un lien symbolique)  sont dirigées
URL Canonique
RewriteMap examplemap txt:W:\Apache24\conf\map.txt

Slash de traine (Trailing Slash)
http://example.com/foo/ Avec un slash de fin, par convention un répertoire.
http://example.com/foo Sans slash de fin, par convention un fichier sans extension.
