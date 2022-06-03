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

```c++
void allPrimeNumber() {
  std::cout << __func__ << std::endl;

  int source[] = { 3, 4, 5 };
  int length = sizeof(source) / sizeof(*source);

  for (int* i = source; i < source + length; i++) {
    int prime = GEN_PRIMOS(*i);
    std::cout << prime << std::endl;
  }
}
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
