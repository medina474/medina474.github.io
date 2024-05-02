---

title: Media Queries

---
    
<style>
table { border-collapse: collapse }
td { border:1px solid gray; }
	@media only screen and (device-width: 1024px) and (orientation : landscape)
   {
       .ipad:after {content: "ipad ?"  }
    }
	@media screen and (max-width: 640px) { .small:after { content: "\2713" } }
	@media screen and (min-width: 800px) { .medium:after { content: "\2713" } }
	@media screen and (min-width: 1024px) and (max-width: 1280px) { .wide:after { content: "\2713" } }
	@media screen and (max-device-width: 480px) { .maxdevice:after { content: "\2713" } }
	@media screen and (min-aspect-ratio: 16/9) { .aspect169:after { content: "\2713" } }
	@media screen and (min-aspect-ratio: 3/4) { .aspect34:after { content: "\2713" } }
	@media screen and (min-resolution: 2dppx) { .resolution2:after { content: "\2713" } }
	@media print and (max-width: 14.8cm) { .printA5:after { content: "\2713" } }
	@media print and (min-width: 19cm) { .printA4:after { content: "\2713" } }
</style>

- [La largeur de la zone d'affichage (viewport)](width) 
- [La hauteur de la zone d'affichage](height) 
- [L'orientation la zone d'affichage](orientation) 
- [Résolution](resolution) 
- [Hover](hover) 
- [Prefered Color Scheme](prefered-color-scheme) 
- Écrans [mononochrome](monochrome) 

width
height
aspect-ratio 	Le rapport largeur/hauteur de la zone d'affichage
orientation

scan 	Le processus de scan de l'appareil d'affichage
grid 	Le type d'écran de l'appareil : matriciel ou grille ?
update 	La fréquence de modification du contenu par l'appareil d'affichage 	Ajoutée avec le niveau 4 du module de spécification Media Queries.
overflow-block 	La façon dont l'appareil d'affichage gère le contenu qui dépasse de la zone d'affichage selon l'axe de bloc 	Ajoutée avec le niveau 4 du module de spécification Media Queries.
overflow-inline 	La possibilité de faire défiler (scroll) le contenu qui dépasse de la zone d'affichage sur l'axe en ligne 	Ajoutée avec le niveau 4 du module de spécification Media Queries.

color-gamut 	Un intervalle approximatif des couleurs prises en charge par l'agent utilisateur et l'appareil d'affichage 	Ajoutée avec le niveau 4 du module de spécification Media Queries.

display-mode 	Le mode d'affichage de l'application, tel qu'indiqué par la propriété display du manifeste 	Définie dans la spécification pour les manifestes des applications web.

light-level 	Le niveau de luminosité de l'environnement 	Reportée au niveau 5 du module de spécification Media Queries.
scripting 	La disponibilité des fonctions de script (JavaScript par exemple) 	Reportée au niveau 5 du module de spécification Media Queries.

<p id="viewport"></p>
<p>ipad <span class="ipad"></span></p>

<script>
window.addEventListener("resize", function() { document.getElementById('viewport').innerHTML = "Taille de la surface d'affichage " + window.innerWidth + "px de largeur sur " + window.innerHeight +"px de hauteur (ratio de " + (window.innerWidth/window.innerHeight).toFixed(2) + ")"; });

var ev = document.createEvent('Event');
ev.initEvent('resize', true, true);
window.dispatchEvent(ev);
</script>

<table border="1">
	<tr><td class="small"></td><td>La page fait 640px de largeur au maximum</td><td><code>@media screen and (max-width: 640px)</code></td></tr>
	<tr><td class="medium"></td><td>La page fait 800px de largeur au minimum</td><td><code>@media screen and (min-width: 800px)</code></td></tr>
	<tr><td class="wide"></td><td>La page fait entre 1024 et 1280px de largeur</td><td><code>@media screen and (min-width: 1024px) and (max-width: 1280px)</code></td></tr>
	<tr><td class="maxdevice"></td><td>L'appareil fait 480px de largeur au maximum</td><td><code>@media screen and (max-device-width: 480px)</code></td></tr>
	<tr><td class="aspect169"></td><td>La page a un ratio minimum de 16/9 (1.78)</td><td><code>@media screen and (min-aspect-ratio: 16/9)</code></td></tr>
	<tr><td class="aspect34"></td><td>La page a un ratio minimum de 3/4 (0.75)</td><td><code>@media screen and (aspect-ratio: 3/4)</code></td></tr>
	<tr><td class="resolution2"></td><td>La résolution de au minimum de 2</td><td><code>@media screen and (min-resolution: 2dppx)</code></td></tr>
	<tr><th colspan="3">Print</th></tr>
	<tr><td class="printA5"></td><td>La page est A5</td><td><code>@media print and (max-width: 14.8cm)</code></td></tr>
	<tr><td class="printA4"></td><td>La page est A4</td><td><code>@media screen and (orientation:landscape)</code></td></tr>
</table>

## Device ratio
<style>
@media screen and (device-aspect-ratio: 1) { .device1:after { content: "\2713" } }
@media screen and (device-aspect-ratio: 5/4) { .device54:after { content: "\2713" } }
@media screen and (device-aspect-ratio: 4/5) { .device45:after { content: "\2713" } }
@media screen and (device-aspect-ratio: 3/4) { .device34:after { content: "\2713" } }
@media screen and (device-aspect-ratio: 4/3) { .device43:after { content: "\2713" } }
@media screen and (device-aspect-ratio: 2/3) { .device23:after { content: "\2713" } }
@media screen and (device-aspect-ratio: 3/2) { .device32:after { content: "\2713" } }
@media screen and (device-aspect-ratio: 16/10) { .device1610:after { content: "\2713" } }
@media screen and (device-aspect-ratio: 10/16) { .device1016:after { content: "\2713" } }
@media screen and (device-aspect-ratio: 16/9) { .device169:after { content: "\2713" } }
@media screen and (device-aspect-ratio: 9/16) { .device916:after { content: "\2713" } }
@media screen and (device-aspect-ratio: 40/71) { .device4071:after { content: "\2713" } } /* iPhone 5 */
</style>


Bootstrap

	<div class="clearfix visible-xs">XS</div>
	<div class="clearfix visible-sm">SM > 768px container = 750px</div>
	<div class="clearfix visible-md">MD  viewport > 992px container = 970px</div>
	<div class="clearfix visible-lg">LG viewport > 1200px container = 1170px</div>

	<ul>
		<li><a href="full.html">Full</a></li>
	</ul>
	https://www.alsacreations.com/article/lire/1500-matchmedia-javascript-media-queries.html
<script>
var mql = window.matchMedia('(max-width: 600px)');

console.log(mql.media);
</script>

</body>
</html>
