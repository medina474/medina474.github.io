---
title: Orientation
---

Portrait ou paysage.

```javascript
window.screen.orientation.type = ;
window.screen.orientation.angle = °;
```

Media queries

```javascript
(orientation: portrait) = ;
```


<script type="application/javascript">
function Load(evt)
{
  let i = 0;
  let operators = document.querySelectorAll(".token.operator");
  operators[i++].nextSibling.textContent = ` "${window.screen.orientation.type}"`;
  operators[i++].nextSibling.textContent = ` ${window.screen.orientation.angle}°`;
  if (evt.matches) { console.log(evt); }
}

window.addEventListener("load", Load);
window.matchMedia("(orientation: portrait)").addListener(evt => {
  let operators = document.querySelectorAll(".token.operator");
  operators[3].nextSibling.textContent = ` ${evt.matches}`;
});
</script>
