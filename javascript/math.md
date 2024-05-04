---
title: API Math
---

### Nombres

```javascript
Number.NaN = ;
Number.NEGATIVE_INFINITY = ;
Number.POSITIVE_INFINITY = ;
Number.EPSILON = ;
Number.MIN_SAFE_INTEGER = ;
Number.MAX_SAFE_INTEGER = ;
```

```javascript
// Plus grand nombre
Number.MAX_VALUE = ;

// Plus petit nombre
Number.MIN_VALUE = ;
```

### Constantes

```javascript
Math.PI = ;
Math.E = ;
Math.LN10 = ;
Math.LN2 = ;
Math.LOG10E = ;
Math.LOG2E = ;
Math.SQRT2 = ;
Math.SQRT1_2 = ;
```

### Mini - Maxi

```javascript
// Minimum
Math.min(5, 11 , 3, 4) = ;

// Maximum
Math.max(5, 11 , 3, 4) = ;
```

### Trigonométrie

```javascript
Math.cos(1.047) = ;
Math.acos(0.5) = ;
```

```javascript
Math.sin(1.047) = ;
Math.asin(0.5) = ;
```


```javascript
Math.tan(1.047) = ;
Math.atan(0.5) = ;
Math.atan2(1, 2) = ;
```

#### Hyperbolique

```javascript
Math.cosh(1) = ;
Math.acosh(1.5) = ;

Math.sinh(1) = ;
Math.asinh(0.5) = ;

Math.tanh(1) = ;
Math.atanh(0.5) = ;
```

### Arrondi

```javascript
Math.ceil(2.51) = ;
Math.floor(2.51) = ;
Math.round(2.51)= ;
Math.trunc(2.51)= ;

Math.ceil(-2.51) = ;
Math.floor(-2.51) = ;
Math.round(-2.51)= ;
Math.trunc(-2.51)= ;

Math.fround(2.51)= ;
```

### Signes

```javascript
Math.abs(-5.3) = ;
Math.sign(-5.3) = ;
```

### Puissances / Racines

```javascript
//Puissance : 2 puissance 5
Math.pow(2, 5) = ;

// Racine carrée
Math.sqrt(144) = ;

// Racine cubique
Math.cbrt(27) = ;
```


### Logarithme / Exponentielle

```javascript
Math.log(7.39) = ;
Math.log10(100) = ;
Math.log2(16) = ;
Math.log1p(6.39) = ;

Math.exp(2) = ;
Math.expm1(2) = ;
```

### Autres

```javascript
Math.random() = ;
Math.clz32(58) = ;
Math.hypot(3, 4) = ;
Math.imul(3, 4) = ;
```


<script type="application/javascript">
function Load()
{
  let i = 0;
  let operators = document.querySelectorAll("code .o");

  operators[i++].nextSibling.textContent  = ` ${Number.NaN}`;
  operators[i++].nextSibling.textContent  = ` ${Number.NEGATIVE_INFINITY}`;
  operators[i++].nextSibling.textContent  = ` ${Number.POSITIVE_INFINITY}`;
  operators[i++].nextSibling.textContent  = ` ${Number.EPSILON}`;
  operators[i++].nextSibling.textContent  = ` ${Number.MIN_SAFE_INTEGER}`;
  operators[i++].nextSibling.textContent  = ` ${Number.MAX_SAFE_INTEGER}`;

  operators[i++].nextSibling.textContent  = ` ${Number.MAX_VALUE}`;
  operators[i++].nextSibling.textContent  = ` ${Number.MIN_VALUE}`;

  operators[i++].nextSibling.textContent  = ` ${Math.PI}`;
  operators[i++].nextSibling.textContent  = ` ${Math.E}`;
  operators[i++].nextSibling.textContent  = ` ${Math.LN10}`;
  operators[i++].nextSibling.textContent  = ` ${Math.LN2}`;
  operators[i++].nextSibling.textContent  = ` ${Math.LOG10E}`;
  operators[i++].nextSibling.textContent  = ` ${Math.LOG2E}`;
  operators[i++].nextSibling.textContent  = ` ${Math.SQRT2}`;
  operators[i++].nextSibling.textContent  = ` ${Math.SQRT1_2}`;

  operators[i++].nextSibling.textContent  = ` ${Math.min(5, 11 , 3, 4)}`;
  operators[i++].nextSibling.textContent  = ` ${Math.max(5, 11 , 3, 4)}`;

  operators[i++].nextSibling.textContent  = ` ${Math.cos(1.047)}`;
  operators[i++].nextSibling.textContent  = ` ${Math.acos(0.5)}`;

  operators[i++].nextSibling.textContent  = ` ${Math.sin(1.047)}`;
  operators[i++].nextSibling.textContent  = ` ${Math.asin(0.5)}`;

  operators[i++].nextSibling.textContent  = ` ${Math.tan(1.047)}`;
  operators[i++].nextSibling.textContent  = ` ${Math.atan(0.5)}`;
  operators[i++].nextSibling.textContent  = ` ${Math.atan2(1, 2)}`;

  operators[i++].nextSibling.textContent  = ` ${Math.cosh(1)}`;
  operators[i++].nextSibling.textContent  = ` ${Math.acosh(1.5)}`;

  operators[i++].nextSibling.textContent  = ` ${Math.asinh(1)}`;
  operators[i++].nextSibling.textContent  = ` ${Math.asinh(0.5)}`;

  operators[i++].nextSibling.textContent  = ` ${Math.tanh(1)}`;
  operators[i++].nextSibling.textContent  = ` ${Math.atanh(0.5)}`;

  operators[i++].nextSibling.textContent  = ` ${Math.ceil(2.51)}`;
  operators[i++].nextSibling.textContent  = ` ${Math.floor(2.51)}`;
  operators[i++].nextSibling.textContent  = ` ${Math.round(2.51)}`;
  operators[i++].nextSibling.textContent  = ` ${Math.trunc(2.51)}`;

  i++;
  operators[i++].nextSibling.textContent  = ` ${Math.ceil(-2.51)}`;
  i++;
  operators[i++].nextSibling.textContent  = ` ${Math.floor(-2.51)}`;
  i++;
  operators[i++].nextSibling.textContent  = ` ${Math.round(-2.51)}`;
  i++;
  operators[i++].nextSibling.textContent  = ` ${Math.trunc(-2.51)}`;

  operators[i++].nextSibling.textContent  = ` ${Math.fround(2.51)}`;

  i++;
  operators[i++].nextSibling.textContent  = ` ${Math.abs(-5.3)}`;
  i++;
  operators[i++].nextSibling.textContent  = ` ${Math.sign(-5.3)}`;

  operators[i++].nextSibling.textContent  = ` ${Math.pow(2, 5)}`;
  operators[i++].nextSibling.textContent  = ` ${Math.sqrt(144)}`;
  operators[i++].nextSibling.textContent  = ` ${Math.cbrt(27)}`;

  operators[i++].nextSibling.textContent  = ` ${Math.log(7.39)}`;
  operators[i++].nextSibling.textContent  = ` ${Math.log10(100)}`;
  operators[i++].nextSibling.textContent  = ` ${Math.log2(16)}`;
  operators[i++].nextSibling.textContent  = ` ${Math.log1p(6.39)}`;

  operators[i++].nextSibling.textContent  = ` ${Math.exp(2)}`;
  operators[i++].nextSibling.textContent  = ` ${Math.expm1(2)}`;

  operators[i++].nextSibling.textContent  = ` ${Math.random()}`;
  operators[i++].nextSibling.textContent  = ` ${Math.clz32(58)}`;
  operators[i++].nextSibling.textContent  = ` ${Math.hypot(3, 4)}`;
  operators[i++].nextSibling.textContent  = ` ${Math.imul(3, 4)}`;



}

window.addEventListener("load", Load);

</script>
