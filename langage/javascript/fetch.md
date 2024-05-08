---

title: Fetch
---

## Callback

Les objets `XMLHttpRequest` (XHR) permettent d'interagir avec des serveurs. On peut récupérer des données à partir d'une URL sans avoir à rafraîchir complètement la page. Cela permet à une page web d'être mise à jour sans perturber les actions de l'utilisateur.

XMLHttpRequest est beaucoup utilisé par l'approche **AJAX**.

Malgré son nom, XMLHttpRequest peut être utilisé afin de récupérer tout type de données et pas uniquement du XML.

Le téléchargement d'une ressources sur un serveur externe étant une opération lente, un méchanisme de callback est implémenté dans l'objet XMLHttpRequest.

Le developpeur affecte à la propriété onReadyStateChange un fonction. Cette fonction sdera appelé lors de l'arrivée des données.

```javascript
var xhttp = new XMLHttpRequest();

xhttp.onreadystatechange = function() {
  if (this.readyState == 4 && this.status == 200) {
    document.getElementById("demo").innerHTML = xhttp.responseText;
  }
};

xhttp.open("GET", "filename", true);
xhttp.send();
// .. Le programme continue .. lors de la réception des données la fonction dans onreadystatechange sera appelée et le traitement pourra se faire
```

L'inconvénient est une lecture non linéaire du code car les fonction callback ne sont là où elle seront appelées (après le send). Les fonction callback sont souvent des fonction anonyme. Le code est truffé de fonctions anonymes à l'intérieur d'autres fonctions.

## Les promesses

### Fonctions thenable

Les fonctions thenable peuvent être chainées à l'aide d'une propriété **then**

Une promesse est une méthode asynchrone qui peut retourner 2 états pris en charge par des fonctions.
**Resolve** et **Reject**

Les promesses peuvent être chainées grâce à la propriété thenable.

```javascript
fetch('https://example.com/movies.json')
  .then(reponse => reponse.json())
  .then(data => document.getElementById("demo").innerHTML = data.title;)
  .catch((error) => {
    console.error('Error:', error);
  });
```

L'opération de décodage json est elle aussi une fonction asynchrone cela laisse le temps au navigateur de traiter de larges fichiers sans bloquer l'utilisateur.

Les promesses sont chainables et gèrent le rattrapage d'erreurs (catch).

L'écriture suit cette fois ci un ordre logique d'éxécution, cependant l'imbriquation des promesses et l'utilisation massive de fonctions anonymes rendent le code pas plus simpe à lire.

## await / async

async et await sont 2 mots clés qui permettent de transformer n'importe qu'elle fonction en ode asynchrone et d'attendre à l'intérieur de celle-ci les opérations lentes sans avoir à déclarer de fonctions callbak ou de fonction thenable anonyme.

```javascript
async function getData()
{
  let reponse = await fetch("https://example.com/movies.json");
  let data = await reponse.json();
}
```

Le code est érit dans l'ordre logique sans aucune fonction anonyme. Ces dernières sont ajoutées par le compilateur lorsque le mot clé await est utilisé.

> Un `await` est **obligatoirement** utilisé dans une fonction async.
{: .danger}

https://developer.mozilla.org/fr/docs/Web/API/Fetch_API
