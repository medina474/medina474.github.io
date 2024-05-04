<script>
    String.prototype.lpad = function(padString, length) {
        var str = this;
        while (str.length < length)
            str = padString + str;
        return str;
    }
    
    b=''
    if (typeof b != 'undefined' && b)
        console.log('true');
    else
        console.log('false');
</script>


#### précédence 20
Groupe ()
```javascript
5 * (4 + 2) = 5 * 6 = <script>document.write(5 * (4 + 2));</script>
```

#### précédence 19

#### précédence 18
Appel de fonction

new

#### précédence 17

Post Incrémentation

```javascript
5 + 3++ = 5 * 6 = <script>document.write(5 + 3++);</script>
```

Post Décrémentation

```javascript
5 + 3-- = 5 * 6 = <script>document.write(5 + 3--);</script>
```

#### précédence 16

#### précédence 15

Exponentiation, associativité à droite 	

```javascript
5 ** 3 ** 2 = 5 ** 9 = <script>document.write(5 ** 3 ** 2);</script>
```

#### précédence 14

Multiplication, associativité à gauche

```javascript
5 * 3 * 2 = 15 * 2 = <script>document.write(5 * 3 * 2);</script>
```

Division, associativité à gauche 	

```javascript
5 / 3 = <script>document.write(5 / 3);</script>
```

Reste, associativité à gauche 	

```javascript
5 % 3 = <script>document.write(5 % 3);</script>
```

#### précédence 13

Addition, associativité à gauche 	

```javascript
5 + 3 = <script>document.write(5 + 3);</script>
```

Soustraction, associativité à gauche

```javascript
5 - 3 = <script>document.write(5 - 3);</script>
```

#### précédence 12

Décalage binaire à gauche, associativité à gauche

```javascript
0b0000001001010001 << 1 = 
0b<script>document.write((0b0000001001010001 << 1).toString(2).lpad("0", 16));</script>
```

Décalage binaire à droite, associativité à gauche

```javascript
0b10000000000000001000001001010001 >> 1  = 
0b<script>document.write((0b10000000000000001000001001010001 >> 1).toString(2).lpad("0", 16));</script>
```

Décalage binaire à droite non-signé, associativité à gauche

```javascript
0b10000000000000001000001001010001 >>> 1  = 
0b<script>document.write((0b10000000000000001000001001010001 >>> 1).toString(2).lpad("0", 32));</script>
```

#### précédence 11

#### précédence 10

#### précédence 9

#### précédence 8

#### précédence 7

#### précédence 6

ET logique, associativité à gauche 	

```javascript
true && false = <script>document.write(true && false);</script>
```

#### précédence 5

OU logique, associativité à gauche 	

```javascript
true || false = <script>document.write(true || false);</script>
```

#### précédence 4

#### précédence 3
