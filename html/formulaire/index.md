---

title: Formulaires
---

## Case à cocher

<input type="checkbox" name="checkbox1">Case à cocher<br>
<input type="checkbox" name="checkbox2" checked>Case à cocher initiallement cochée<br>
<input type="checkbox" name="checkbox3" disabled>Case à cocher désactivée<br>
<label for="checkbox5"><input id="c5" type="checkbox" name="checkbox5">Case à cocher encapsulée dans un label</label>

## Bouton radio

<label for="f1"><input id="f1" type="radio" name="radio" value="1">Bouton radio 1</label><br>
<label for="f2"><input id="f2" type="radio" name="radio" value="2" checked>Bouton radio 2 (checked)</label><br>
<label for="f3"><input id="f3" type="radio" name="radio" value="3" disabled>Bouton radio 3 (disabled)</label><br>
<label for="f4"><input id="f4" type="radio" name="radio" value="4">Bouton radio 4</label>


## Liste déroulante

<select name="select1">
  <option>pomme</option>
  <option selected="selected">banane</option>
  <option>fraise</option>
  <option>framboise</option>
  <option>poire</option>
</select>

 <select>
  <optgroup label="Bourgogne">
    <option value="volvo">Volvo</option>
    <option value="saab">Saab</option>
  </optgroup>
  <optgroup label="Grand Est">
    <option value="mercedes">Mercedes</option>
    <option value="audi">Audi</option>
  </optgroup>
</select> 

<input list="ice-cream-flavors" id="ice-cream-choice" name="ice-cream-choice" />

<datalist id="ice-cream-flavors">
    <option value="Chocolate">
    <option value="Coconut">
    <option value="Mint">
    <option value="Strawberry">
    <option value="Vanilla">
</datalist>

## Champs date

```html
<input type="date">
```

<input type="date">


```html
<input type="time">
```

<input type="time">


```html
<input type="datetime">
```

<input type="datetime">

```html
<input type="datetime-local">
```

<input type="datetime-local">

```html
<input type="month">
```

<input type="month">

```html
<input type="week">
```

<input type="week">


```html
<input type="email">
```

<input type="email">

```html
<input type="tel">
```

<input type="tel">

```html
<input type="url">
```

<input type="url">

```html
<input type="search">
```

<input type="search">


```html
<input type="number">
```

<input type="number">


```html
<input type="range">
```

<input type="range">

```html
<input type="color">
```

<input type="color" value='#bb4711'>


<progress id="file" max="100" value="70"> 70% </progress>

<meter id="fuel"
       min="0" max="100"
       low="33" high="66" optimum="80"
       value="50">
    at 50/100
</meter>
