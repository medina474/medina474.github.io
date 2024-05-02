---
title: Navigator
---

```javascript
navigator.userAgent = ;
navigator.appName = ;
navigator.appCodeName = ;
```

```javascript
navigator.appVersion = ;
navigator.appMinorVersion = ;
```

```javascript
navigator.buildID = ;
```

```javascript
navigator.product = ;
navigator.productSub = ;
```

```javascript
navigator.vendor = ;
navigator.vendorSub = ;
```


```javascript
navigator.cookieEnabled =;
```

```javascript
navigator.doNotTrack =;
```

```javascript
navigator.platform =;
```

```javascript
navigator.oscpu = ;
```

```javascript
navigator.cpuClass=;
```

```javascript
navigator.onLine =;
```

```javascript
navigator.plugins= ;
```


## Langues

```javascript
navigator.systemLanguage = ;
navigator.userLanguage = ;
navigator.language = ;
```

<table>
<script language='javascript'>
let a = "";
	for (i=0; i < navigator.languages.length; i++)
		 a += '<tr><td>' + navigator.languages[i] + '</td></tr>';

</script>
</table>

## Plugins

```javascript
```


```javascript
navigator.maxTouchPoints =;
```


```javascript
navigator.hardwareConcurrency =;
```


```javascript
navigator.webdriver =;
```


```javascript
navigator.pointerEnabled =;
```

```javascript
navigator.connectionSpeed=;
```


<script type="application/javascript">
(function() {

  window.addEventListener("load",
    function (event) {
			let i = 0;
  		let operators = document.querySelectorAll(".token.operator");

      operators[i++].nextSibling.textContent  = ` "${navigator.userAgent}"`;
			operators[i++].nextSibling.textContent  = ` "${navigator.appName}"`;
			operators[i++].nextSibling.textContent  = ` "${navigator.appCodeName}"`;
			operators[i++].nextSibling.textContent  = ` "${navigator.appVersion}"`;
			operators[i++].nextSibling.textContent  = ` "${navigator.appMinorVersion}"`;
			operators[i++].nextSibling.textContent  = ` "${navigator.buildID}"`;
			operators[i++].nextSibling.textContent  = ` "${navigator.product}"`;
			operators[i++].nextSibling.textContent  = ` "${navigator.productSub}"`;
			operators[i++].nextSibling.textContent  = ` "${navigator.vendor}"`;
			operators[i++].nextSibling.textContent  = ` "${navigator.vendorSub}"`;

			operators[i++].nextSibling.textContent  = ` "${navigator.cookieEnabled}"`;
			operators[i++].nextSibling.textContent  = ` "${navigator.doNotTrack}"`;
			operators[i++].nextSibling.textContent  = ` "${navigator.platform}"`;
			operators[i++].nextSibling.textContent  = ` "${navigator.oscpu}"`;
			operators[i++].nextSibling.textContent  = ` "${navigator.cpuClass}"`;

			operators[i++].nextSibling.textContent  = ` "${navigator.onLine}"`;

			let t = "";
			for (j=0; j<navigator.plugins.length; j++)
		 		t += navigator.plugins[j].name + ' (' + navigator.plugins[j].version + ') ' + navigator.plugins[j].filename + ' '+navigator.plugins[j].description + ' ';

			operators[i++].nextSibling.textContent  = t;

			operators[i++].nextSibling.textContent  = ` "${navigator.systemLanguage}"`;
			operators[i++].nextSibling.textContent  = ` "${navigator.userLanguage}"`;
			operators[i++].nextSibling.textContent  = ` "${navigator.language}"`;

			operators[i++].nextSibling.textContent  = ` ${navigator.maxTouchPoints}`;
			operators[i++].nextSibling.textContent  = ` ${navigator.hardwareConcurrency}`;
			operators[i++].nextSibling.textContent  = ` ${navigator.webdriver}`;
			operators[i++].nextSibling.textContent  = ` "${navigator.pointerEnabled}"`;
			operators[i++].nextSibling.textContent  = ` "${navigator.pointerEnabled}"`;
    }, true);
})();
</script>
