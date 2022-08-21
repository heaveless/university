# algebra-perm2c

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

# Ataques al algoritmo RSA

## Ataque 1

*Para hallar el mensaje <kbd>m</kbd> primero encontraremos cúales son los números primos <kbd>p</kbd> y <kbd>q</kbd> que multiplicados dan <kbd>n</kbd>. En este caso específico, es posible dado que el número no es muy grande. Podemos entonces hallar <kbd>phi(n)</kbd> con estos dos números <kbd>p</kbd>, <kbd>q</kbd>. Hallando <kbd>phi(n)</kbd> podemos hallar la llave secreta y descifrar <kbd>c</kbd>.*

```py
def __generate_primes(n):
    primes = ()
    for i in range(1, n):
        if EUCLIDES(i, n) != 1 and MILLER_RABIN(i, 500):
            primes += (i,)
            if len(primes) == 2:
                break

    return primes

def attack1():
    e = 65537
    n = 999630013489
    P = e, n
    c = 747120213790

    first, second = __generate_primes(n)
    
    phiN = (first - 1) * (second - 1)
    S = INVERSO(e, phiN), n

    m = CIPHER(c, S)
    cx = CIPHER(m, P)
```
## Ataque 2

*Podemos hacer un ataque de módulo común ya que tenemos un mensaje cifrado dos veces con diferentes exponentes pero mismo módulo. Hallaremos los valores x , y mediante el algoritmo Extendido de Euclides, ya que los necesitamos. Como <kbd>e_1 * x + e_2 * y = 1 --> c1^x * c2^y mod n = m --> (x es menor que 0) --> c1_inversa^x * c2^y mod n</kbd>.*

```py
def attack2():
    e = 7
    n = 35794234179725868774991807832568455403003778024228226193532908190484670252364677411513516111204504060317568667
    P = e, n
    c = 35794234179725868774991807832568455403003778024228226193532908190484670252364677411513516052471686245831933544
    
    e_ = 11
    P_ = e_, n
    c_ = 35794234179725868774991807832568455403003778024228226193532908190484670252364665786748759822531352444533388184

    if (EUCLIDES(e, e_ == 1) and EUCLIDES(c_, n)):
        __message_module_attack()

        z, x, y = EUCLIDES_EXTEND(e, e_)

        a = EXP_MOD(INVERSO(c, n), -x, n) if x < 0 else EXP_MOD(c, x, n)
        b = EXP_MODBITS(INVERSO(c_, n), -y, n) if y < 0 else EXP_MODBITS(c_, y, n)

        m = (a * b) % n
        cx = CIPHER(m, P)
```
## Ataque 3

*Se comprueba que <kbd>P(S(m)) = HASH(M)</kbd>, siendo M un mensaje, la función HASH sha1, la función P RSA con la clave pública y la funcion S RSA con la clave secreta. Primero se generan dos claves <kbd>RSA (P y S)</kbd> y se asigna <kbd>m = HASH(M) % P[1] (n)</kbd> luego se usa RSA para cifrar m (y luego descifrarlo). Este procedimiento es común en firmas digitales para revisar la autenticidad de un archivo.*

```py
def attack3():
    k = 32
    P, S = RSA_KEY_GENERATOR(k)
    _, n = P
    M = b'Hello World!'

    h = sha1()
    h.update(M)
    m = int(h.hexdigest(), 16)
    m %= n

    sign = CIPHER(m, S)
    u = CIPHER(sign, P)
```

# Result

```bash
----------- ATTACK 1 -----------

m: 100000000001
c: 747120213790
P(m) = cx: True

----------- ATTACK 2 -----------

Posible ataque de modulo comun

m: 35794234179725868774991807832568455403003778024228226193532908190484670252364677411513516111204504060317568000
cx: 35794234179725868774991807832568455403003778024228226193532908190484670252364677411513516052471686245831933544
c: 35794234179725868774991807832568455403003778024228226193532908190484670252364677411513516052471686245831933544
cx = c: True

----------- ATTACK 3 -----------

M: b'Hello World!'
m: 475123918
sign: 417705249
u: 475123918
u = m: True  
```
