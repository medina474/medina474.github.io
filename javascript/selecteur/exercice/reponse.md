---

title: Taille

---


 1. à tous les éléments de type rect.
    
```javascript
let collection = document.getElementsByTagName("rect");
for (let c of collection) {
  c.classList.toggle("occupe");
}
```

```javascript
[...document.getElementsByTagName("rect")].forEach(elt => elt.classList.toggle("occupe"));
```

```javascript
document.querySelectorAll("rect").forEach(elt => elt.classList.toggle("occupe"));
```
 
2. à l'élément machine41664.
   
```javascript
document.getElementById("machine41664").classList.toggle("occupe");
```

```javascript
document.querySelector("#machine41664").classList.toggle("occupe");
```
 

3. plusieurs éléments

```javascript
document.querySelectorAll("#machine41664,#machine20125").forEach(elt => elt.classList.toggle("occupe"));
```

4.

```javascript
document.querySelectorAll(".indisponible").forEach(elt => elt.classList.toggle("occupe"));
```

## Attributs

5. présence d'un attribut

```javascript
document.querySelectorAll("[data-inventaire]").forEach(elt => elt.classList.toggle("occupe"));
```

6. égalité sur un attribut

```javascript
document.querySelectorAll("rect[width='35']").forEach(elt => elt.classList.toggle("occupe"));
```

7. égalité sur un attribut sans tenir compte de la casse (minuscules/majuscules)

```javascript
document.querySelectorAll(".machine[data-fabricant='billon'i]").forEach(elt => elt.classList.toggle("occupe"));
```

8. contient le mot

```javascript
document.querySelectorAll(".stock[data-articles~='vis'i]").forEach(elt => elt.classList.toggle("occupe"));
```

9. contient la suite de lettres

```javascript
document.querySelectorAll(".stock[data-articles*='vis'i]").forEach(elt => elt.classList.toggle("occupe"));
```

10. commence

```javascript
document.querySelectorAll(".stock[data-inventaire^='2019'i]").forEach(elt => elt.classList.toggle("occupe"));
```

11. Un élément à l'intérieur d'un autre

```javascript
document.querySelectorAll(".zoneB .moulage").forEach(elt => elt.classList.toggle("occupe"));
```

12. Un élément contenant 2 classes

```javascript
document.querySelectorAll(".zoneC .moulage.indisponible").forEach(elt => elt.classList.toggle("occupe"));
```

13. inversion

```javascript
document.querySelectorAll(".stock:not([data-inventaire])").forEach(elt => elt.classList.toggle("occupe"));
```

14. Premier élément

```javascript
document.querySelectorAll(".ZoneA :first-child").forEach(elt => elt.classList.toggle("occupe"));
```
 

directement enfant

```javascript
document.querySelectorAll(".IlotC>:last-child").forEach(elt => elt.classList.toggle("occupe"));
```

tous les éléments

```javascript
document.querySelectorAll(".IlotC *").forEach(elt => elt.classList.toggle("occupe"));
```

tous les éléments de premier niveau

```javascript
document.querySelectorAll(".IlotC>*").forEach(elt => elt.classList.toggle("occupe"));
```

18. voisin direct

```javascript
document.querySelectorAll(".machine.injection+.stock").forEach(elt => elt.classList.toggle("occupe"));
```

19. voisin

```javascript
document.querySelectorAll(".machine.injection.indisponible~.machine.moulage").forEach(elt => elt.classList.toggle("occupe"));
```
  
```javascript
document.querySelectorAll("g .machine:only-child").forEach(elt => elt.classList.toggle("occupe"));
```

```javascript
document.querySelectorAll(".IlotA .machine:not(.indisponible)").forEach(elt => elt.classList.toggle("occupe"));
```


    document.getElementById("reset").addEventListener("click", evt => {
      document.querySelectorAll("use").forEach(elt => elt.classList.remove("occupe", "libre", "reglage"));
    });

    document.getElementById("btn15").addEventListener("click", evt => {
      document.querySelectorAll(".IlotC>:last-child").forEach(elt => elt.classList.toggle("occupe"));
    });

    document.getElementById("btn16").addEventListener("click", evt => { document.querySelectorAll(".IlotC *").forEach(elt => elt.classList.toggle("occupe")); });
    document.getElementById("btn17").addEventListener("click", evt => { document.querySelectorAll(".IlotC>*").forEach(elt => elt.classList.toggle("occupe")); });
    document.getElementById("btn19").addEventListener("click", evt => { document.querySelectorAll(".machine.injection.indisponible~.machine.moulage").forEach(elt => elt.classList.toggle("occupe")); });
        
    document.getElementById("btn25").addEventListener("click", evt => {
      let vide = document.querySelector(".IlotC g:empty");
      let machines = document.querySelectorAll(".machine.moulage");
      machines.forEach(elt => vide.appendChild(elt))
    });

  