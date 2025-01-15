---

title: API Vibration
---

Vibration de 125 ms.

```javascript
window.navigator.vibrate(125);
```
<button onclick="window.navigator.vibrate(125)">Tester</button>

Vibration de 125 ms, les valeurs suivantes ne sont pas prises en compte.

```javascript
window.navigator.vibrate(125, 500, 125, 500, 125, 500, 125, 500, 125);
```
<button onclick="window.navigator.vibrate(125, 500, 125, 500, 125, 500, 125, 500, 125)">Tester</button>

Vibration suivant un schéma de 125 ms de vibration suivi d'un repose de 500 ms et d'une nouvelle vibration de 125 ms.

```javascript
window.navigator.vibrate([125, 500, 125]);
```

<button onclick="window.navigator.vibrate([125, 500, 125])">Tester</button>

Vibration suivant un schéma de 125 ms de vibration suivi de 500 ms de repos, 125 ms de vibration, repos d'une seconde et vibration de deux secondes.

```javascript
window.navigator.vibrate([125, 500, 125, 1000, 2000]);
```

<button onclick="window.navigator.vibrate([125, 500, 125, 1000, 2000])">Tester</button>

Arrêt de la vibration en cours.

```javascript
window.navigator.vibrate(0);
```

<button onclick="window.navigator.vibrate(30000)">Démarrer</button> <button onclick="window.navigator.vibrate(0)">Arrêter</button>
