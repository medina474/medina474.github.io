---

title: Device Motion API
---

```javascript
window.addEventListener('devicemotion', function(event) {
    event.accelerationIncludingGravity.x = <span id='eventgx'></span>;
    event.accelerationIncludingGravity.y = <span id='eventgy'></span>;
    event.accelerationIncludingGravity.z = <span id='eventgz'></span>;

    event.acceleration.x = <span id='eventx'></span>;
    event.acceleration.y = <span id='eventy'></span>;
    event.acceleration.z = <span id='eventz'></span>;
}, false);
```

<script>
(function() {

  window.addEventListener("devicemotion",
    function (event) {
      document.getElementById('eventgx').innerHTML(event.accelerationIncludingGravity.x);
      document.getElementById('eventgy').innerHTML(event.accelerationIncludingGravity.y);
      document.getElementById('eventgz').innerHTML(event.accelerationIncludingGravity.z);

      document.getElementById('eventx').innerHTML(event.acceleration.x);
      document.getElementById('eventy').innerHTML(event.acceleration.y);
      document.getElementById('eventz').innerHTML(event.acceleration.z);
    }, true);
})();
</script>
