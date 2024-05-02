---

title: Géolocalisation
---

<button id="GeoLocationTest2" onclick="getCurrentPositionSimple()">Lancer le test</button>
<p id='GeoLocationResult'></p>
<script>
function getCurrentPositionSimple() {
    var r = document.getElementById('GeoLocationResult');
    if (navigator.geolocation)
    {
		navigator.geolocation.getCurrentPosition(
		function(position) {
			r.innerHTML = "Latitude: " + position.coords.latitude + "<br> Longitude: " + position.coords.longitude;
		}, function(error) {
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
	else { r.innerHTML="La géolocalisation n'est pas supportée par votre navigateur."; }	
}
</script>

## GeoLocation

```javascript
navigator.geolocation.getCurrentPosition(function(position) {
	position.coords.latitude = <span id="coords.latitude"></span>;
	position.coords.latitude = <span id="coords.longitude"></span>;
	position.coords.accuracy = <span id="coords.accuracy"></span>;
	
	position.coords.altitude = <span id="coords.altitude"></span>;
	position.coords.altitudeAccuracy = <span id="coords.altitudeAccuracy"></span>;
	
	position.coords.heading = <span id="coords.heading"></span>;
	position.coords.speed = <span id="coords.speed"></span>;
	
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
				document.getElementById("coords.latitude").innerHTML = position.coords.latitude;
				document.getElementById("coords.longitude").innerHTML = position.coords.longitude;
				document.getElementById("coords.accuracy").innerHTML = position.coords.accuracy;
				
				document.getElementById("coords.altitude").innerHTML = position.coords.altitude;
				document.getElementById("coords.altitudeAccuracy").innerHTML = position.coords.altitudeAccuracy;
				
				document.getElementById("coords.heading").innerHTML = position.coords.heading;
				document.getElementById("coords.speed").innerHTML = position.coords.speed;

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
