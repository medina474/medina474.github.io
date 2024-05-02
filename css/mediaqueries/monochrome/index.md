---

title: Media Queries - Monochrome

---

Le nombre de bits par pixel pour représenter la nuance monochrome de l'appareil.\
0 si l'appareil n'est pas monochrome.

Les écrans monochrome se trouvent dans les écrans E-Ink des liseuses. Si un écran monochrome peut paraître moins attaractif que les couleurs éclatantes des dalles LCD ou Amoled des tablettes, le confort oculaire de l'encre électronique est proche du papier, alors que la tablette peut vite fatiguer les yeux.

L'appareil n'est pas monochrome
```css
@media (monochrome:0) {  }
```

L'appareil est monochrome
```css
@media (monochrome) {  }
```

4 bits pour la nuance soit 16 niveaus de gris
```css
@media (monochrome:4) {  }
```

8 bits pour la nuance soit 256 niveaus de gris 
```css
@media (monochrome:8) {  }
```

<style>
.match:after {
  background-color:#3ed124;
  color: white;
  padding: 2px 5px;
  margin-left:6px;
  content: "\2713";
  display: none;
}
@media (monochrome: 0) { .monochrome0:after { display: initial } }
@media (monochrome) { .monochrome:after { display: initial } }
@media (monochrome:4) { .monochrome4:after { display: initial } }
@media (monochrome:8) { .monochrome8:after { display: initial } }
</style>

monochrome||
---|---
non|<span class="match monochrome0"></span>
oui|<span class="match monochrome"></span>
16 niveaux|<span class="match monochrome4"></span>
256 niveaux|<span class="match monochrome8"></span>
