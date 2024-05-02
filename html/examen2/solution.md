---

title: Solution
---

Utilisation de filter map reduce

```js
 persons.filter(elt => countries.includes(elt.country)).map(elt => ({
```

```js
let total = filtered.reduce((acc, current, index) => ({
  "age": acc.age + (current.age - acc.age) / (index + 1),
  "nb_child": current.nb_child + acc.nb_child
}), ({ age: filtered[0].age, nb_child: 0 }));
```


```js
function Calcul()
{
  let countries = [...document.querySelectorAll("input[type='checkbox']:checked")].map(elt => elt.value);

  let filtered = persons.filter(elt => countries.includes(elt.country)).map(elt => ({
    "name": elt.name,
    "age": new Date(Date.now() - new Date(elt.birth)).getUTCFullYear() - 1970,
    "country": elt.country,
    "nb_child": elt.nb_child
  }));

  let body = document.getElementById("body");
  let template = document.getElementById("ligne");
  while (body.lastChild) body.removeChild(body.lastChild);

  filtered.forEach(elt => {
    let clone = document.importNode(template.content, true);
    clone.querySelector(".name").innerHTML = elt.name;
    clone.querySelector(".age").innerHTML = elt.age;
    clone.querySelector(".country").innerHTML = elt.country;
    clone.querySelector(".nb_child").innerHTML = elt.nb_child;
    body.appendChild(clone);
  });

  let total = filtered.reduce((acc, current, index) => ({
    "age": acc.age + (current.age - acc.age) / (index + 1),
    "nb_child": current.nb_child + acc.nb_child
  }), ({age:filtered[0].age, nb_child:0}));
      
  document.querySelector("tfoot .age_mean").innerHTML = total.age;
  document.querySelector("tfoot .children_count").innerHTML = total.nb_child;
}

document.querySelectorAll("input[type='checkbox']").forEach(elt => elt.addEventListener("click", Calcul));
Calcul();
```
