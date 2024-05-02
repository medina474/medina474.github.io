---
layout: layouts/page.njk
title: JWT
---

JWT est un jeton permettant d’échanger des informations de manière sécurisée. Ce jeton est composé de trois parties, dont la dernière, la signature, permet d’en vérifier la légitimité. JWT est souvent utilisé pour offrir une authentification stateless au sein d’applications. Plusieurs librairies permettent de manipuler ces tokens évitant ainsi l’écriture d’un code personnel pouvant donner lieu à des vulnérabilités. 

JWT pour JSON Web Token est une méthode sécurisée d’échange d’informations, décrite par la RFC 7519. L’information est échangée sous la forme d’un jeton signé afin de pouvoir en vérifier la légitimité. Ce jeton est compact et peut être inclus dans une URL ou dans l'entête d'une requête http.

JWT est couramment utilisé pour implémenter des mécanismes d’authentification stateless pour des SPA (Single Page Application) ou pour des application mobiles.

Un JWT est composé de trois parties, chacune contenant des informations différentes :

- un header,
- un payload (les “claims”),
- la signature.

Le header et le payload sont structurés en JSON. Ces trois parties sont chacunes encodées en base64url, puis concaténées en utilisant des points (“.”).

Le header identifie quel algorithme a été utilisé pour générer la signature, ainsi que le type de token dont il s’agit (souvent JWT, mais le champ a été prévu dans le cas où l’application traite d’autres types d’objet qu’un JWT).

Exemple de header :

̀```
{
  "alg": "HS256",
  "typ": "JWT"
}
̀```

Ici, le header indique que la signature a été générée en utilisant HMAC-SHA256.

Le payload est la partie du token qui contient les informations que l’on souhaite transmettre. Ces informations sont appelées “claims”. Il est possible d’ajouter au token les claims que l’on souhaite, mais un certain nombre de claims sont déjà prévus dans les spécifications de JWT.

Par exemple, sub qui identifie le sujet du token (qui le token identifie), iss (issuer) va permettre d’identifier l’émetteur du token ou encore exp qui indique la date d’expiration du token. Il est fortement conseillé d’assigner une valeur à ce dernier champ afin de limiter la durée de vie du token. Si la date d’expiration est dépassée, le token sera rejeté.

Exemple de payload :

```
{
  "sub": "Albert Einstein",
  "exp": "1485968105",
  "admin": "true"
}
```

La signature est la dernière partie du token. Elle est créée à partir du header et du payload générés et d’un secret. Une signature invalide implique systématiquement le rejet du token.

signature = HMAC-SHA256(key, header + '.' + payload)

Une fois ces 3 éléments générés, on peut assembler notre token JWT.
token = encodeBase64(header) + '.' + encodeBase64(payload) + '.' + encodeBase64(signature)

En reprenant les exemples précédents, on arrive au résultat suivant :

Header: { "alg": "HS256", "typ": "JWT" }
Payload: { "subject": "John Doe", "admin": true, "iat": "1485968105" }

Token généré :
eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJzdWJqZWN0IjoiSm9obiBkb2UiLCJhZG1pbiI6dHJ1ZSwiaWF0IjoiMTQ4NTk2ODEwNSJ9.fiSiLFuR4RYuw606Djr2KtQ7y2u-G6OzlHchzklBcd0

    Header . Payload . Signature

Maintenant que l’on a notre token, utilisons-le pour nous authentifier !

https://blog.ippon.fr/2017/10/12/preuve-dauthentification-avec-jwt/

JWT
: JSON Web Token

Stateless
: Un protocole stateless (sans état) est un protocole de communication dans lequel le récepteur ne doit pas conserver l'état de session des requêtes précédentes. L'expéditeur transfère l'état de session pertinent au destinataire de manière à ce que **chaque** demande puisse être comprise **isolément**, c'est-à-dire sans référence à l'état de session des demandes précédentes retenues par le destinataire.