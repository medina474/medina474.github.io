---

title: Géolocalisation
---

<button id="GeoLocationTest2" onclick="getCurrentPositionSimple()">Lancer le
test</button>

<p id='GeoLocationResult'></p>
<script>
function getCurrentPositionSimple() {
  var r = document.getElementById('GeoLocationResult');
  if (navigator.geolocation)
  {
    navigator.geolocation.getCurrentPosition(
      function(position) {
        r.innerHTML = "Latitude: " + position.coords.latitude + "<br> Longitude: " + position.coords.longitude;
      }, 
      function(error) {
        switch(error.code)
        {
        case error.PERMISSION_DENIED:
          r.innerHTML="L'utilisateur a refusé l'accès à la géolocalisation.";
          break;
        case error.POSITION_UNAVAILABLE:
          r.innerHTML="Impossible de déterminer la géolocalisation.";
        break;
        case error.TIMEOUT:
          r.innerHTML="Le temps d'attente est dépassé.";
          break;
        case error.UNKNOWN_ERROR:
          r.innerHTML="Une erreur inconnue s'est produite.";
          break;
        }
      });
  }
  else { 
    r.innerHTML="La géolocalisation n'est pas supportée par votre navigateur."; 
  }
}
</script>

## GeoLocation

```javascript
navigator.geolocation.getCurrentPosition(function(position) {
  position.coords.latitude = ;
  position.coords.latitude = ;
  position.coords.accuracy = ;
  
  position.coords.altitude = ;
  position.coords.altitudeAccuracy = ;
  
  position.coords.heading = ;
  position.coords.speed =  ;
  
  }, function(error) {
    error.code = <span id="coords.error"></span>;
  });
```

<button id="GeoLocationTest">Lancer le test</button>

<div id="map" style="width:100%; height:290px"></div>

<script>
(function() {
  document.getElementById('GeoLocationTest').onclick = function() {

  if ('geolocation' in navigator)
  {
    navigator.geolocation.getCurrentPosition(
      function(position) {
        let i = 0;
        let operators = document.querySelectorAll("code .o");
        let message;

        console.log(position);

        operators[i++].nextSibling.textContent  = ` ${position.coords.latitude}`;
        operators[i++].nextSibling.textContent  = ` ${position.coords.longitude}`;
        operators[i++].nextSibling.textContent  = ` ${position.coords.accuracy}`;

        operators[i++].nextSibling.textContent  = ` ${position.coords.altitude}`;
        operators[i++].nextSibling.textContent  = ` ${position.coords.altitudeAccuracy}`;

        operators[i++].nextSibling.textContent  = ` ${position.coords.heading}`;
        operators[i++].nextSibling.textContent  = ` ${position.coords.speed}`;

        var map = L.map('map', {
          center: [position.coords.latitude, position.coords.longitude],
          zoom: 13
        });

        L.tileLayer('https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png', {
          attribution: 'Map data © <a href="http://openstreetmap.org">OpenStreetMap</a> contributors',
          maxZoom: 18
        }).addTo(map);

      }, function(error) {
        switch(error.code)
        {
        case error.PERMISSION_DENIED:
          document.getElementById("coords.error").innerHTML = "PERMISSION_DENIED";
          break;
        case error.POSITION_UNAVAILABLE:
          document.getElementById("coords.error").innerHTML = "POSITION_UNAVAILABLE";
          break;
        case error.TIMEOUT:
          document.getElementById("coords.error").innerHTML = "TIMEOUT";
          break;
        case error.UNKNOWN_ERROR:
          document.getElementById("coords.error").innerHTML = "UNKNOWN_ERROR";
          break;
        }
      });
  }
  }
})();
</script>
