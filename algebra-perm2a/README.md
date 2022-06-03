# algebra-perm2a

**Developers**

| Role      | Name |
| ----------- | ----------- |
| Developer   | Maycol Alexander Canaveri Taco |
| Developer   | Alberto Llamocca |

<br>

**Table of Contents**

- [Empezemos]()
  - [Ejecucion](#ejecución)
- [Ejercicios]()
  - [Generar todo los primos de 3,4 y 5 cifras](#ejercicio-1)
  - [Numeros primos aleatorios de 16,32 y 64 bits](#ejercicio-2)
- [Utilitarios]()
  - [ES_COMPUESTO](./docs/ES_COMPUESTO.md)
  - [GEN_PRIMOS](./docs/GEN_PRIMOS.md)
  - [MILLER_RABIN](./docs/MILLER_RABIN.md)
  - [POW_MOD](./docs/POW_MOD.md)
  - [RANDOMBITS](./docs/RANDOMBITS.md)
  - [RANDOMGEN_PRIMOS](./docs/RANDOMGEN_PRIMOS.md)
  - [RANDOMINTEGER](./docs/RANDOMINTEGER.md)

<br>

### Ejecución

Para ejecutar el programa, porfavor correr el siguente script en la terminal.

```bash
python main.py
```
### Ejercicio 1
*Generar todos los primos de 3, 4 y 5 cifras.*

any content here

```py
def allPrimeNumber():
    listaNum = [3,4,5]
    for i in listaNum:
        print(f"\nNumeros primos de {i} digitos:")
        numero = (10**(i-1))
        while(numero <= (10**i)):
            if MILLER_RABIN(numero,50):
                print(numero,end="--")
            numero += 1
    print("\n")
```
### Ejercicio 2
*Implementar un programa que genere de manera aleatoria al menos 10 primos distintos de 16, 32 y 64 bits.*

any content here

```python
def randomPrimeNumber():
    source = [ 
        16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
        32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
        64, 64, 64, 64, 64, 64, 64, 64, 64, 64
    ]

    for i in source:
        prime = RANDOMGEN_PRIMOS(i)
        print("{0}bits -> {1}".format(i, prime))
```
```bash
randomPrimeNumber:

16bits -> 33647
16bits -> 39499
16bits -> 59333
16bits -> 35797
16bits -> 46439
16bits -> 37633
16bits -> 47563
16bits -> 54709
16bits -> 36919
16bits -> 55171
32bits -> 2479449331
32bits -> 3943072037
32bits -> 3392485429
32bits -> 2668402537
32bits -> 4221862063
32bits -> 3054322699
32bits -> 3263909771
32bits -> 4293211151
32bits -> 3885413933
32bits -> 2329364221
64bits -> 12702557818905538561
64bits -> 17605323725312372737
64bits -> 9319588526910369793
64bits -> 11188507237998315521
64bits -> 13344054781187880961
64bits -> 10122845002879154177
64bits -> 13921347531788193793
64bits -> 12495984492930224129
64bits -> 13523977963399149569
64bits -> 9622235937478082561
```
