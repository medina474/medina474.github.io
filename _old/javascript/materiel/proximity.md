---
title: Proximity API
---

### User Proximity

```javascript
window.addEventListener('userproximity', function(userproximity) {
  userproximity.near = <span id="userproximity.near"></span>;
});

```

### Device Proximity

```javascript
window.addEventListener('deviceproximity', function(deviceproximity) {
  deviceproximity.min = <span id="deviceproximity.min"></span>;
  deviceproximity.max = <span id="deviceproximity.max"></span>;
  deviceproximity.value = <span id="deviceproximity.value"></span>;
});

```

<script>
window.addEventListener('userproximity', function(event) {
  document.getElementById("userproximity.near").innerHTML = userproximity.near;
});

window.ondeviceproximity = function(deviceproximity) {
  document.getElementById("deviceproximity.min").innerHTML = deviceproximity.min;
  document.getElementById("deviceproximity.max").innerHTML = deviceproximity.max;
  document.getElementById("deviceproximity.value").innerHTML = deviceproximity.value;
}
</script>
