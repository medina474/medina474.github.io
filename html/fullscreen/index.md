---
title: Fullscreen API
---
	
<style>
#fullscreen { display:none }
#fullscreen:-moz-full-screen { display:block; color:#fff }
#fullscreen:-webkit-full-screen { display:block }
#fullscreen:fullscreen { display:block }
h1:fullscreen {
  border:1px solid #f00;
}
p:fullscreen {
font-size: 200%;
}
:fullscreen {background: green}
::backdrop {background: yellow}
html:-moz-full-screen {background: green}
:-ms-fullscreen {background: green}
::-ms-backdrop {background: yellow}
:-webkit-full-screen {background: green}
</style>

Pseudo classe Fullscreen par défaut sur l'élément pour lequel dans le cas de document c'est html. Ne fonctionne pas avec F11
Standard (Edge) : 

```javascript
document.documentElement.requestFullscreen();
document.exitFullscreen();
```

<button onclick="document.documentElement.requestFullscreen()">Passer en plein écran</button>
<button onclick="document.exitFullscreen()">Quitter le plein écran</button><br>

<span id="std"></span><br>

<script>
	std = document.getElementById("std")
	function fullscreenStatus(engine, enabled, element) {
		msg  = "Plein écran " + (enabled ? "" : "non ") + "supporté.<br>"
		msg += "Élément en plein écran : " + element
		engine.innerHTML = msg
		engine.className = (enabled ? "ok" : "ko")
	}

	fullscreenStatus(std, document.fullscreenEnabled, document.fullscreenElement)
	document.addEventListener("fullscreenchange", () => {
				fullscreenStatus(std, document.fullscreenEnabled,
							document.fullscreenElement)})

	document.addEventListener("fullscreenerror", () => {
    std.innerHTML = "Erreur de passage en plein écran !"
    std.className = "ko" });
</script>

## Préfixes

### Mozilla (Firefox) : 
<button onclick="document.documentElement.mozRequestFullScreen()">Passer en plein écran</button>
<button onclick="document.mozCancelFullScreen()">Quitter le plein écran</button><br>

<span id="moz">Mozilla (Firefox)</span>
<br>
<script>
moz = document.getElementById("moz")
fullscreenStatus(moz, document.mozFullScreenEnabled, document.mozFullScreenElement)

document.addEventListener("mozfullscreenchange", function(){
  fullscreenStatus(moz, document.mozFullScreenEnabled,
  document.mozFullScreenElement)
});

document.addEventListener("mozfullscreenerror", function() {
  moz.innerHTML = "Erreur de passage en plein écran !"
  moz.className = "ko" 
});
</script>

### Webkit (Chrome, Opera, Safari) : 
<button onclick="document.documentElement.webkitRequestFullscreen()">Passer en plein écran</button>
<button onclick="document.webkitExitFullscreen()">Quitter le plein écran</button><br>
<span id="webkit"></span>
<script>
  webkit = document.getElementById("webkit")
  fullscreenStatus(webkit, document.webkitFullscreenEnabled, document.webkitFullscreenElement)
  document.addEventListener("webkitfullscreenchange", function(){
        fullscreenStatus(webkit, document.webkitFullscreenEnabled,
              document.webkitFullscreenElement)})
  document.addEventListener("webkitfullscreenerror", function() {
        webkit.innerHTML = "Erreur de passage en plein écran !"
        webkit.className = "ko" })
	</script>

### Microsoft (10 &le; Internet Explorer &le; 11) :
<button onclick="document.documentElement.msRequestFullscreen()">Passer en plein écran</button>
<button onclick="document.msExitFullscreen()">Quitter le plein écran</button><br>
<span id="ms"></span><br>
<script>
  ms = document.getElementById("ms")
  fullscreenStatus(ms, document.msFullscreenEnabled, document.msFullscreenElement)
  document.addEventListener("MSFullscreenChange", function(){
        fullscreenStatus(ms, document.msFullscreenEnabled,
              document.msFullscreenElement)})
  document.addEventListener("MSFullscreenError", function() {
        ms.innerHTML = "Erreur de passage en plein écran !"
        ms.className = "ko" })
</script>
	

```css
div:fullscreen { }
```




    backdrop
<script>
  function isItemSupported(item, isFunc, ref){
	value = eval(item);
//	alert(item+" :\n\n"+value);		// DÃ©bug.
	if (!ref)
		ref = value;
	if (!value || value != ref){
		document.write('<br><br><span id="'+item+'"></span>');
 		eltMsg = document.getElementById(item);
//		eltMsg.innerHTML = item.slice(item.lastIndexOf('.')+1) + (isFunc?"()":"") + " non supportÃ©" + (isFunc?"e":"") + " par votre navigateur !";
		eltMsg.innerHTML = item + (isFunc?"()":"") + " non supportÃ©" + (isFunc?"e":"") + " par votre navigateur !";
		eltMsg.className = "ko";
	}
}

	isItemSupported("document.documentElement.requestFullscreen", true)
	isItemSupported("document.exitFullscreen", true)
	isItemSupported("document.fullscreenEnabled")
	isItemSupported("document.fullscreenElement")

	isItemSupported("document.documentElement.msRequestFullscreen", true)
	isItemSupported("document.msExitFullscreen", true)
	isItemSupported("document.msFullscreenEnabled")
	isItemSupported("document.msFullscreenElement")

	isItemSupported("document.documentElement.mozRequestFullScreen", true)
	isItemSupported("document.mozCancelFullScreen", true)
	isItemSupported("document.mozFullScreenEnabled")
	isItemSupported("document.mozFullScreenElement")

	isItemSupported("document.documentElement.webkitRequestFullscreen", true)
	isItemSupported("document.webkitExitFullscreen", true)
	isItemSupported("document.webkitFullscreenEnabled")
	isItemSupported("document.webkitFullscreenElement")
  */
</script>	 

<button onclick="testRequestFullScreen()">Passer en plein écran</button>

<script>
function testRequestFullScreen() {
var el = document.getElementById('fullscreen');

// use necessary prefixed versions
//el.webkitRequestFullscreen();
el.mozRequestFullScreen();
//el.msRequestFullscreen();

// finally the standard version
//el.requestFullscreen();
}          
</script>
The el in the above example now matches the :fullscreen selector, and can be styled in that mode:

https://hacks.mozilla.org/2012/01/using-the-fullscreen-api-in-web-browsers/

Examples:

- Go to http://robnyman.github.com/fullscreen/
- Click on the 'fullscreen' button. => Fullscreen mode is on and background become red => OK, works as intended
- Press escape or F11 or click on the 'cancel fullscreen' button => OK, works as intended
- Now, press F11 => fullscreen is on but page background remains yellow. html:-moz-full-screen { background: red; } doesn't work.
- With F11 Fullscreen still enabled, click on the 'fullscreen' button => Background become red.
- With F11 Fullscreen still enabled, click 'cancel fullscreen' => Nothing happens.


Issues:
1: You can't cancel fullscreen mode programmatically if it has been toggled on with F11
2: When triggered with F11 no event is fired and CSS ':-moz-full-screen' is not supported.
3: You can toggle fullscreen mode with the JS API when F11 fullscreen is already on. This leads to confusion for developers as well as for users.
4: To cancel fullscreen mode with their keyboard, users need to press either ESC or F11 depending on how they enabled fullscreen mode. This is confusing.
5: Lets say you are creating a game and would like to offer fullscreen mode to your players. As far as i am aware, you cannot keep track of whether the fullscreen mode is enabled or not since F11 fullscreen doesn't trigger events. So for instance you can not reliably change the visual aspect of your fullscreen button accordingly (like with a 'toggle on' icon and a 'toggle off' icon).


Expected results:

I think the Fullscreen API and F11 fullscreen should behave the same.

FWIW, F11 fullscreen and API Fullscreen behave inconsistently in Webkit too.
I can confirm that this happens. F11 behavior has an animation and doesn't seem to be consistent with the fullscreen API. We're building games using this, and Firefox is the only major browser that is showing issues with fullscreen.

https://caniuse.com/fullscreen
