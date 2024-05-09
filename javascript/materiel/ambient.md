---
title: Ambient Light API
---

Les capteur ALS (Ambient Light Sensor) mesurent la luminosité ambiante. L'appareil peut ainsi ajuster la luminosité et/ou le contraste des éléments affichés sur l'écran. Cela a deux avantages : améliorer l'expérience utilisateur en adaptant la visibilité à l'environnement (plein soleil, obscurité) et économiser l'énergie en baissant la luminosité de l'écran quand cela est possible.

L'information de luminosité peut être fournie par un capteur spécifique qui délivrera un mesure précise ou directement par la caméra.

### Device Light

Retourne la luminosité ambiante en lux

```javascript
window.addEventListener('devicelight', function(devicelight) {
    devicelight.value = <span id='devicelight.value'></span>;
    devicelight.min = <span id='devicelight.min'></span>;
    devicelight.max = <span id='devicelight.max'></span>;
});

```

### Light Level

Indique seulement 3 niveaux : normal, bright, ou dim

```javascript
window.addEventListener('lightlevel', function(lightlevel) {
    lightlevel.value = <span id='lightlevel.value'></span>;
});

```

<script language='javascript'>
document.addEventListener("DOMContentLoaded", function(event) {

    if ('ondevicelight' in window) {
      window.addEventListener('devicelight', function(devicelight) {
            document.getElementById('devicelight.value').innerHTML = devicelight.value;
            document.getElementById('devicelight.min').innerHTML = devicelight.min;
            document.getElementById('devicelight.max').innerHTML = devicelight.max;
        }, false);
    } else {
        //document.write("ondevicelight Non supporté");
    }

    if ('onlightlevel' in window) {
      window.addEventListener('lightlevel', function(lightlevel) {
            document.getElementById('lightlevel.value').innerHTML = lightlevel.value;
        }, false);
    } else {
        //document.write("onlightlevel Non supporté");
    }
});
</script>
