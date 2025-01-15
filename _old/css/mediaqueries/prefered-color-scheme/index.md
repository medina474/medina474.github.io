---

title: Media Queries - Thème de couleur

---
   
<style>
.match {
  color: #3ed124;
  display: none;
}
@media (prefers-color-scheme: light) { .light { display: initial } }
@media (prefers-color-scheme: dark) { .dark { display: initial } }
</style>

```css
@media (prefers-color-scheme: light) { }
@media (prefers-color-scheme: dark) { }
```

Thème|actif
---|---
light|1<span class="match light">✓</span>
dark|<span class="match dark">✓</span>

## Utilisation dans les illustration SVG
