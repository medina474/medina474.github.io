---

title: Matériel
style: materiel.css
---

Ce n'est pas parce que le navigateur implémente les interfaces de programmation (API) que le matériel est en capacité de fournir les informations.

## Géolocalisation

```javascript
("geolocation" in navigator)
```

<div class="materiel" id="geolocation">
<div></div>
<div class="support">
	<a class="button" href='geolocation'>Tester</a>
</div>
</div>

<script>
if ("geolocation" in navigator)
	document.getElementById("geolocation").classList.add("support");
</script>

## Vibration

```javascript
("vibrate" in navigator)
```

<div class="materiel" id="vibrate">
<div></div>
<div class="support">
	<a class="button" href='vibrate'>Tester</a>
</div>
</div>
	
<script>
if ("vibrate" in navigator)
	document.getElementById("vibrate").classList.add("support");
</script>

## Capteur de lumière ambiante

```javascript
("ondevicelight" in window)
```

<div class="materiel" id="ambient">
<div></div>
<div class="support">
	<a class="button" href='ambient'>Tester</a>
</div>
</div>

<script>
if ("ondevicelight" in window)
	document.getElementById("ambient").classList.add("support");
</script>

## Capteur de proximité

```javascript
("ondeviceproximity" in window)
```

<div class="materiel" id="proximity">
<div></div>
<div class="support">
	<a class="button" href='proximity'>Tester</a>
</div>
</div>

<script>
if ("ondeviceproximity" in window)
	document.getElementById("proximity").classList.add("support");
</script>

## Mouvements

<div class="materiel" id="motion">
<div></div>
<div class="support">
	<a class="button" href='motion'>Tester</a>
</div>
</div>

```javascript
("ondevicemotion" in window)
```
<script>
if ("ondevicemotion" in window)
	document.getElementById("motion").classList.add("support");
</script>

## Orientation

<div class="materiel" id="orientation">
<div></div>
<div class="support">
	<a class="button" href='orientation'>Tester</a>
</div>
</div>

```javascript
("ondeviceorientation" in window) = <script>document.write("ondeviceorientation" in window);</script>
("orientation" in screen) = <script>document.write("orientation" in screen);</script>
```

<script>
if ("ondeviceorientation" in window || "orientation" in screen)
	document.getElementById("orientation").classList.add("support");
</script>

## Lecteur code barre

<div class="materiel" id="barcode">
<div></div>
<div class="support">
	<a class="button" href='barcode'>Tester</a>
</div>
</div>

<script>
document.getElementById("barcode").classList.toggle("support", 'BarcodeDetector' in window);
</script>

## Synthèse vocale

```javascript
("speechSynthesis" in window)
```

<div class="materiel" id="speech">
<div></div>
<div class="support">
	<a class="button" href='speech'>Tester</a>
</div>
</div>

<script>
if ("speechSynthesis" in window)
	document.getElementById("speech").classList.add("support");
</script>

## Batterie

```javascript
("battery" in navigator)
```

<div class="materiel" id="battery">
<div></div>
<div class="support">
	<a class="button" href='batterie'>Tester</a>
</div>
</div>
	

<script>
if ("battery" in navigator)
	document.getElementById("battery").classList.add("support");
</script>

L'API de statut de la batterie fournit des informations sur le niveau de charge de la batterie et envoie des notifications lors du changement de ce niveau.
Cette information peut être utilisée pour ajuster le fonctionnement d'une application lorsque la charge de batterie est faible et ainsi mettre en place une stratégie afin de préserver l'autonomie ou de sauvegarder les données quand la batterie est bientôt vide. Par exemple le site peut désactiver la lecture automatique des vidéos ou télécharger mois de données.

Malheureusement cette API a été utilisée pour traquer les utilisateurs, en effet deux chercheurs de l’Université de Princeton ont découvert qu'en combinant les informations de L'API il est possible d'assigner un identifiant unique à un appareil. Et si un utilisateur efface les cookies, passe en navigation privée, change de navigateur ou utilise un vpn, il est possible de faire revire la session (respawning) si il visite le même site dans un laps de temps très court.

Un autre aspect malveillant de la part des sites web peu scrupuleux serait d'utiliser l'information de la batterie pour pousser les utilisateurs dont l'appareil va bientôt s'éteindre à prendre des décisions précipitées et payer plus cher.



<a href="camera/liste">Liste</a>
<a href="camera/camera">Camera</a>
<a href="camera/capture">Capture</a>
<a href="camera/barcode-simple">Lecture de code barre</a>
<a href="camera/torch">Torche</a>
