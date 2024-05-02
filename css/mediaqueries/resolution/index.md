---

title: Media Queries - Resolution

---

<style>
.match:after {
  background-color:#3ed124;
  color: white;
  padding: 2px 5px;
  margin-left:6px;
  content: "\2713";
  display: none;
}
</style>

La densité de pixel pour l'appareil d'affichage.
http://pieroxy.net/blog/2012/10/18/media_features_of_the_most_common_devices.html


```css
@media screen and (resolution: 72dpi)
```

résolution||
--:|---
72 dpi|<div class="match r72"></div>
96 dpi|<div class="match r96"></div>
120 dpi|<div class="match r120"></div>
150 dpi|<div class="match r150"></div>
150 dpi|<div class="match r150"></div>
160 dpi|<div class="match r160"></div>
200 dpi|<div class="match r200"></div>
240 dpi|<div class="match r240"></div>
300 dpi|<div class="match r300"></div>
320 dpi|<div class="match r320"></div>
600 dpi|<div class="match r600"></div>

## Densité

```css
@media screen and (resolution: 1dppx)
```

densité||
--:|---
1 dppx|<div class="match d1"></div>
1.5 dppx|<div class="match d15"></div>
2 dppx|<div class="match d2"></div>
3 dppx|<div class="match d3"></div>


## Pointeur de saisie

La fonctionnalité pointer est utilisée pour interroger la présence et la précision d'un périphérique de pointage tel qu'une souris.
Si plusieurs périphériques de pointage sont présents, la fonctionnalité pointer doit refléter les caractéristiques du périphérique
de pointage «principal», telles que déterminées par le navigateur.\
Pour interroger les capacités de tous les périphériques de pointage disponibles, voir la fonctionnalité any-pointeur.\
Ajoutée avec le niveau 4 du module de spécification Media Queries.

```css
@media (pointer: none)
```

pointer||
---|---
none|<div class="match pnone"></div>
fine|<div class="match pfine"></div>
coarse|<div class="match pcoarse"></div>

any pointer||
---|---
none|<div class="match apnone"></div>
fine|<div class="match apfine"></div>
coarse|<div class="match apcoarse"></div>

thème de couleur||
---|---
none|<div class="match hnone"></div>
fine|<div class="match hfine"></div>
coarse|<div class="match hcoarse"></div>
none|<div class="match ahnone"></div>
fine|<div class="match ahfine"></div>
coarse|<div class="match ahcoarse"></div>


## Orientation

orientation||
---|---
portrait|<div class="match portrait"></div>
landscape|<div class="match landscape"></div>


## Couleurs


### monochrome



### color

Le nombre de bits pour chaque composante de couleur pour l'appareil d'affichage (ou 0 si l'appareil ne gère pas la couleur).

```css
@media (color:0) { /* pas de prise en charge de la couleur */ }
@media (color) { /* prise en chage de la couleur */  }
@media (min-color:8) { /* au moins 8 bits par composante de couleur RVB */ }
```
<style>
@media (color:0) { .color0:after { display: initial } }
@media (color) { .color:after { display: initial } }
@media (min-color:8) { .color8:after { display: initial } }
</style>

couleur||
---|---
sans|<div class="match color0"></div>
avec|<div class="match color"></div>
8 bits / canal|<div class="match color8"></div>

### color-index

Le nombre d'éléments dans la palette de couleur de l'appareil  (ou 0 si l'appareil ne dispose pas d'un tel tableau)

```css
@media (color-index:0) { /* pas de prise en charge de la couleur */ }
@media (color-index) { /* prise en chage de la couleur */  }
@media (color-index:8) { /* au moins 8 bits par composante de couleur RVB */ }
```
<style>
@media (color-index:0) { .colorindex0:after { display: initial } }
@media (color-index) { .colorindex:after { display: initial } }
@media (color-index:8) { .colorindex8:after { display: initial } }
</style>

couleur||
---|---
sans|<div class="match colorindex0"></div>
avec|<div class="match colorindex"></div>
256 couleurs|<div class="match colorindex8"></div>

### inverted-colors

L'inversion des couleurs par l'agent utilisateur ou le système d'exploitation.

```css
@media (inverted-colors:0) { /* pas d'inversion des couleurs */ }
@media (inverted-colors) { /* prise en chage de la couleur */  }
```
<style>
@media (inverted-colors:0) { .inverted0:after { display: initial } }
@media (inverted-colors) { .inverted:after { display: initial } }
</style>

inversion||
---|---
sans|<div class="match inverted0"></div>
avec|<div class="match inverted"></div>


## Ratio

```css
@media (device-aspect-ratio: 40/71)
```

ratio|||
--:|--:|---
40/71|0,563|<div class="match device4071"></div>
2/3|0,667|<div class="match device23"></div>
3/4|0,75|<div class="match device34"></div>
4/3|1,333|<div class="match device43"></div>
3/2|1,5|<div class="match device32"></div>
16/10|1,6|<div class="match device1610"></div>
16/9|1,778|<div class="match device169"></div>

<style>
@media screen and (resolution: 72dpi) { .r72:after { display: initial } }
@media screen and (resolution: 96dpi) { .r96:after { display: initial } }
@media screen and (resolution: 120dpi) { .r120:after { display: initial } }
@media screen and (resolution: 144dpi) { .r144:after { display: initial } }
@media screen and (resolution: 150dpi) { .r150:after { display: initial } }
@media screen and (resolution: 160dpi) { .r160:after { display: initial } }
@media screen and (resolution: 200dpi) { .r200:after { display: initial } }
@media screen and (resolution: 240dpi) { .r240:after { display: initial } }
@media screen and (resolution: 300dpi) { .r300:after { display: initial } }
@media screen and (resolution: 320dpi) { .r300:after { display: initial } }
@media screen and (resolution: 600dpi) { .r600:after { display: initial } }

@media screen and (resolution: 1dppx) { .d1:after { display: initial } }
@media screen and (resolution: 1.5dppx) { .d15:after { display: initial } }
@media screen and (resolution: 2dppx) { .rd2:after { display: initial } }
@media screen and (resolution: 3dppx) { .rd3:after { display: initial } }

@media (orientation:portrait) { .portrait:after { display: initial } }
@media (orientation:landscape) { .landscape:after { display: initial } }

@media (pointer: none) { .pnone:after { display: initial } }
@media (pointer: fine) { .pfine:after { display: initial } }
@media (pointer: coarse) { .pcoarse:after { display: initial } }

@media (any-pointer: none) { .apnone:after { display: initial } }
@media (any-pointer: fine) { .apfine:after { display: initial } }
@media (any-pointer: coarse) { .apcoarse:after { display: initial } }

@media (hover: none) { .hnone:after { display: initial } }
@media (hover: fine) { .hfine:after { display: initial } }
@media (hover: coarse) { .hcoarse:after { display: initial } }

@media (any-hover: none) { .ahnone:after { display: initial } }
@media (any-hover: fine) { .ahfine:after { display: initial } }
@media (any-hover: coarse) { .ahcoarse:after { display: initial } }

@media (device-aspect-ratio: 40/71) { .device4071:after { display: initial } }
@media (device-aspect-ratio: 3/4) { .device34:after { display: initial } }
@media (device-aspect-ratio: 4/3) { .device43:after { display: initial } }
@media (device-aspect-ratio: 2/3) { .device23:after { display: initial } }
@media (device-aspect-ratio: 16/10) { .device1610:after { display: initial } }
@media (device-aspect-ratio: 16/9) { .device169:after { display: initial } }
</style>
