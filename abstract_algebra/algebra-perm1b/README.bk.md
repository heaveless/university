---
Title:    Laboratorio 3  
Author:   Jose Chavez  
Date:     01/04/2022
---

**:fire: La sucesión de Fibonacci :fire:**

<center>
    <div>
      <img src="https://render.githubusercontent.com/render/math?math={0,1,1,2,3,5,8,13,21,\dots}#gh-light-mode-only">
      <img src="https://render.githubusercontent.com/render/math?math={\color{white}0,1,1,2,3,5,8,13,21,\dots}#gh-dark-mode-only">
    <div>
</center>

Donde
<img src="https://render.githubusercontent.com/render/math?math={F_{2}=1,F_{3}=2,F_{4}=3}#gh-light-mode-only">
<img src="https://render.githubusercontent.com/render/math?math={\color{white}F_{2}=1,F_{3}=2,F_{4}=3}#gh-dark-mode-only"> 
, entonces la sucesión queda definida por

<center>
    <div>
      <img src="https://render.githubusercontent.com/render/math?math={F_{k%2B2}=F_{k%2B1}%2BF_{k}(k\ge0)}#gh-light-mode-only">
      <img src="https://render.githubusercontent.com/render/math?math={\color{white}F_{k%2B2}=F_{k%2B1}%2BF_{k}(k\ge0)}#gh-dark-mode-only">
    </div>
</center>

De esta manera se producen los números
<img src="https://render.githubusercontent.com/render/math?math={F_{2}=1,F_{3}=2,F_{4}=3}#gh-light-mode-only">
<img src="https://render.githubusercontent.com/render/math?math={\color{white}F_{2}=1,F_{3}=2,F_{4}=3}#gh-dark-mode-only"> 
y así hasta el infinito. Un resultado interesante surge al dividir cada termino 
<img src="https://render.githubusercontent.com/render/math?math={F_{n}}#gh-light-mode-only">
<img src="https://render.githubusercontent.com/render/math?math={\color{white}F_{n}}#gh-dark-mode-only"> 
entre el inmediatamente anterior
<img src="https://render.githubusercontent.com/render/math?math={F_{n-1}}#gh-light-mode-only">
<img src="https://render.githubusercontent.com/render/math?math={\color{white}F_{n-1}}#gh-dark-mode-only">
.

* <img src="https://render.githubusercontent.com/render/math?math={F_{2}/F_{1}=1/1=1}#gh-light-mode-only"><img src="https://render.githubusercontent.com/render/math?math={\color{white}F_{2}/F_{1}=1/1=1}#gh-dark-mode-only">
* <img src="https://render.githubusercontent.com/render/math?math={F_{3}/F_{2}=2/1=2}#gh-light-mode-only"><img src="https://render.githubusercontent.com/render/math?math={\color{white}F_{3}/F_{2}=2/1=2}#gh-dark-mode-only">
* <img src="https://render.githubusercontent.com/render/math?math={F_{4}/F_{3}=3/2=1.5}#gh-light-mode-only"><img src="https://render.githubusercontent.com/render/math?math={\color{white}F_{4}/F_{3}=3/2=1.5}#gh-dark-mode-only">
* <img src="https://render.githubusercontent.com/render/math?math={F_{5}/F_{4}=5/3{\simeq}1.67}#gh-light-mode-only"><img src="https://render.githubusercontent.com/render/math?math={\color{white}F_{5}/F_{4}=5/3{\simeq}1.67}#gh-dark-mode-only">
* <img src="https://render.githubusercontent.com/render/math?math={F_{6}/F_{5}=8/5=1.6}#gh-light-mode-only"><img src="https://render.githubusercontent.com/render/math?math={\color{white}F_{6}/F_{5}=8/5=1.6}#gh-dark-mode-only">

El resultado oscila al rededor de un valor—el número áureo. Es decir

<center>
    <div>
      <img src="https://render.githubusercontent.com/render/math?math={\displaystyle\lim_{x\to\infty}F_{n}/F_{n-1}=\varphi}#gh-light-mode-only">
      <img src="https://render.githubusercontent.com/render/math?math={\color{white}\displaystyle\lim_{x\to\infty}F_{n}/F_{n-1}=\varphi}#gh-dark-mode-only">
    </div>
</center>

donde 
<img src="https://render.githubusercontent.com/render/math?math={\varphi = \frac{1 k%2B \sqrt{5}}{2} = 1.61803 \dots}#gh-light-mode-only">
<img src="https://render.githubusercontent.com/render/math?math={\color{white}\varphi = \frac{1 k%2B \sqrt{5}}{2} = 1.61803 \dots}#gh-dark-mode-only">
, y ademas

<center>
    <div>
      <img src="https://render.githubusercontent.com/render/math?math={F_{k} = \frac{1}{\sqrt{5}}[\varphi ^{k} - (1 - \varphi) ^{k}] \simeq \frac{\varphi ^{k}}{\sqrt{5}}}#gh-light-mode-only">
      <img src="https://render.githubusercontent.com/render/math?math={\color{white}F_{k} = \frac{1}{\sqrt{5}}[\varphi ^{k} - (1 - \varphi) ^{k}] \simeq \frac{\varphi ^{k}}{\sqrt{5}}}#gh-dark-mode-only">
    </div>
</center>

