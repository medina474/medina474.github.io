---

title: Media Queries - Orientation

---

La page est orientée en portrait
{.match .portrait}

```css
@media screen and (orientation:portrait)
```

La page est orientée en paysage
{.match .landscape}

```css
@media screen and (orientation:landscape)
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

  @media screen and (orientation:portrait) {
    .portrait:after { display: initial }
  }

  @media screen and (orientation:landscape) {
    .landscape:after { display: initial }
  }
</style>
