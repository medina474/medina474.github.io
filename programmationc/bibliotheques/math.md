---
title: math
---

### Trigonométrie

fonction|description
---|---
cos|cosinus
sin|sinus
tan|tangente 
acos|arc cosinus 
asin|arc sinus 
atan|arc tangente 
atan2|arc tangente à 2 paramètres x et y

```c
printf("cos(π/3) = %f (1/2)\n", cos(3.141592 / 3));
printf("sin(π/3) = %f (√3/2)\n", sin(3.141592 / 3));
printf("tan(π/3) = %f (√3)\n", tan(3.141592 / 3));

printf("acos(√3/2) = %f (π/6)\n", acos(0.866025));
printf("asin(1) = %f (π/2)\n", asin(1));
printf("atan(1) = %f (π/4)\n", atan(1));
printf("atan2(-1, -1) = %f (-3π/4)\n", atan2(-1, -1));
```

fonction|description
---|---
cosh|cosinus hyperbolique
sinh|sinus hyperbolique
tanh|tangente hyperbolique 
acosh|arc cosinus hyperbolique
asinh|arc sinus hyperbolique
atah|arc tangente hyperbolique

fonction|description
---|---
pow|élever à la puissance 
sqrt|racine carée
cbrt|racine cubique
hypo|hypotenuse 
ceil|arrondi supérieur 
floor|arrondi inférieur
fmod|reste de la division 
trunc|tronque 
round|arrondi au plus proche
lround|arrondi au plus proche 
llround|arrondi au plus proche 
rint|arrondi 
lrint|arrondi 
llrint|arrondi
nearbyint|arrondi
remainder|reste
remquo|reste et quotient
copysign|signe 
nan|not a number 
nextafter|valeur suivante 
nexttoward|valeur suivante 
fdim|difference positive 
fmax|maximum 
fmin|minimum 
fabs|valeur absolue 
abs|valeur absolue 
fma|multiplication et addition 
exp|exponentiel 
frexp|exposant
ldexp|exposant 
log|logarithme naturel
log10|logarithme
modf|entier et partie décimale 
exp2|exponentielle binaire
expm1|exponentie - 1 
ilogb|logarithme binaire 
log1p|logarithme + 1
log2|logarithme binaire  
logb|logarithme 
scalbn|échelle
scalbln|échelle
