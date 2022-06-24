# algebra-perm2a

**Developers**

| Role      | Name |
| ----------- | ----------- |
| Developer   | Maycol Alexander Canaveri Taco |
| Developer   | Alberto Llamocca |

### Ejecución

Para ejecutar el programa, porfavor correr el siguente script en la terminal.

```bash
python main.py
```

# RSA

*Generar dos primos p y q, tal que p 6= q. Cada uno de k/2 bits.*

```py
arg = bits // 2
p = RANDOMGEN_PRIMOS(arg)
q = RANDOMGEN_PRIMOS(arg)
while p == q:
    q = RANDOMGEN_PRIMOS(arg)
```

*Calcular n = p × q*

```py
n = p * q
```

*Calcular φ(n)*

```py
phiN = (p - 1) * (q - 1)
```

*Generar aleatoriamente e ∈ [2, n − 1], tal que gcd(e, φ(n)) = 1*

```py
e = RANDOMBITS(bits)
    while EUCLIDES(e, phiN) != 1:
        e = RANDOMBITS(bits)
```

*Hallar d tal que ed ≡ 1 (mod φ(n))*

```py
d = INVERSO(e, phiN)
```

*return {n, e, d}*

```py
return (e, n), (d, n)
```

# Result

```bash
e = 16737853537004977631
d = 5777247613090356671
n = 8079547236955587577

--------------------------------------------------------------
         m                c = P(m)           m' = S(c)      
--------------------------------------------------------------
     3474440807     2305176858429532926      3474440807     
     3468506039     5072458094590050686      3468506039     
     4120712199     1803319403314262518      4120712199     
     3240752145      483220722922694022      3240752145     
     2576444841      997420300546065909      2576444841     
     3962241617     1313599785152790631      3962241617     
     3133653501     1615802526452035652      3133653501     
     3088664633     6798302343315056423      3088664633     
     2649168315     3689129985035108274      2649168315     
     3231603467     3136911693775555053      3231603467     
```
