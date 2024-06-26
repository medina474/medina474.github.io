---
title: Speech
---

```javascript
var su = new SpeechSynthesisUtterance();
su.lang = "fr";
su.text = "Il me semble, bercé par ce choc monotone, Qu'on cloue en grande hâte un cercueil quelque part. Pour qui ? - C'était hier l'été ; voici l'automne ! Ce bruit mystérieux sonne comme un départ.";
speechSynthesis.speak(su);
```

<p>
Bientôt nous plongerons dans les froides ténèbres ;<br>
Adieu, vive clarté de nos étés trop courts !<br>
J'entends déjà tomber avec des chocs funèbres<br>
Le bois retentissant sur le pavé des cours.<br>
</p>

<p>
Tout l'hiver va rentrer dans mon être : colère,<br>
Haine, frissons, horreur, labeur dur et forcé,<br>
Et, comme le soleil dans son enfer polaire,<br>
Mon coeur ne sera plus qu'un bloc rouge et glacé.<br>
</p>

<p>
J'écoute en frémissant chaque bûche qui tombe ;<br>
L'échafaud qu'on bâtit n'a pas d'écho plus sourd.<br>
Mon esprit est pareil à la tour qui succombe<br>
Sous les coups du bélier infatigable et lourd.<br>
</p>

<p id="strophe3">
Il me semble, bercé par ce choc monotone,<br>
Qu'on cloue en grande hâte un cercueil quelque part.<br>
Pour qui ? - C'était hier l'été ; voici l'automne !<br>
Ce bruit mystérieux sonne comme un départ.<br>
</p>

Charles Baudelaire

<a href="javascript:lire()">lire</a>
<a href="javascript:speechSynthesis.pause(su);">pause</a>
<a href="javascript:speechSynthesis.resume(su);">reprendre</a>

<select id="voices">

</select>

<script>
var su = new SpeechSynthesisUtterance();

function lire()
{
  su.lang = "fr";
  su.text = document.getElementById("strophe3").textContent;
  speechSynthesis.speak(su);
}

function stop()
{
  speechSynthesis.speak(su);
}

function liste()
{
  var synth = window.speechSynthesis;
  var voices = synth.getVoices();

  let elt = document.getElementById("voices");

  for(voice of voices)
  {
    let option = document.createElement('option');
    option.textContent = `${voice.name} (${voice.lang})`;
    elt.appendChild(option);
  }
}

liste();

/*
default: false
​​lang: "en-US"
​​localService: true
​​name: "Microsoft David Desktop - English (United States)"
​​voiceURI: "urn:moz-tts:sapi:Microsoft David Desktop - English (United States)?en-US"
*/

</script>
