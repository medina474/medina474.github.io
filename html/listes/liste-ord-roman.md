---
title: Alpha
---

```html
<ol style='list-style-type: upper-roman'>
```

<ol id="racine" style="list-style-type: upper-roman;">

</ol>

<script>
const racine = document.getElementById('racine');

for (i=1; i < 4020 ; i++) {
  const element = document.createElement("li");
  element.innerHTML = `Élément ${i}`;
  racine.appendChild(element);
}
</script>
