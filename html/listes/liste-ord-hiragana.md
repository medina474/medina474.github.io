---
title: Alpha
---

```html
<ol style='list-style-type: hiragana'>
```


<ol id="racine" style="list-style-type: hiragana;">

</ol>

<script>
var racine = document.getElementById('racine');

for (i=1; i < 4020 ; i++) {
    var element = document.createElement("li");
    element.innerHTML = "Élément" + i;
    racine.appendChild(element);
}
</script>
