---
title: Battery API
---

```javascript
navigator.battery.charging = <span id="charging"><script language='javascript'>document.write(navigator.battery.charging);</script></span>
navigator.battery.chargingTime = <span id="chargingTime"><script language='javascript'>document.write(navigator.battery.chargingTime);</script></span>
navigator.battery.dischargingTime = <span id="dischargingTime"><script language='javascript'>document.write(navigator.battery.dischargingTime);</script></span>
navigator.battery.level = <span id="level"><script language='javascript'>document.write(navigator.battery.level);</script></span>
```

<div id="log">
</div>

<script>
navigator.battery.onchargingchange = function() {
  document.getElementById("charging").innerHTML = navigator.battery.charging;
  document.getElementById("log").innerHTML += "onchargingchange<br>";
}

navigator.battery.onchargingtimechange = function() {
  document.getElementById("chargingTime").innerHTML = navigator.battery.chargingTime;
  document.getElementById("log").innerHTML += "onchargingtimechange<br>";
}

navigator.battery.ondischargingtimechange = function() {
  document.getElementById("dischargingTime").innerHTML = navigator.battery.dischargingTime;
  document.getElementById("log").innerHTML += "ondischargingtimechange<br>";
}

navigator.battery.onlevelchange = function() {
  document.getElementById("level").innerHTML = navigator.battery.level;
  document.getElementById("log").innerHTML += "onlevelchange<br>";
}
</script>
