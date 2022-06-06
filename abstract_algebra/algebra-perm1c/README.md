# algebra perm1c

**Integratens:**

- Alberto Llamocca Ninaquispe

**Informacion Tecnica**

| Name      | Info |
| ----------- | ----------- |
| Language    | Python      |
| version     | 3.9.6       |


## Cifrado Afin

El cifrado afín también se le llama cifrado de transformación afín o cifrado monoalfabético genérico. Es un tipo de cifrado por sustitución en el que cada símbolo del alfabeto en claro (el alfabeto del texto en claro) es sustituido por un símbolo del alfabeto cifrado (el alfabeto del texto cifrado) siendo el número de símbolos del alfabeto en claro igual que el número de símbolos del alfabeto cifrado. Para hallar el símbolo del alfabeto cifrado que sustituye a un determinado símbolo del alfabeto en claro, se usa una función matemática afín en aritmética modular. Para poder aplicar la función matemática lo primero que hay que hacer es asignar un orden que a cada símbolo de cada uno de los alfabeto le asocie un número de orden. Una vez establecido esto, la fórmula matemática tiene la siguiente forma:

*Cifrado*

para el cifrado se requiere una clave, en este caso se utilizara. 
`{4, 7} = a, b` y el alfabeto local, que en total son 27, en caso del latinoamericano.
Y luego aplicaremos la formula mostrada en la siguente imagen.

![cifrado](https://user-images.githubusercontent.com/90937895/165886369-fed73f15-176d-4cdc-bd39-1259ffb90cd3.png)

```python
def encrypt(a, b, text):
  result = ""
  
  for i in text:
    
    n = 0
    for j in meta:
      if i==j:
        break
      n += 1

    idx = (a * n + b ) % len(meta)
    result += meta[idx]
  
  return result

```

*Decifrado*

Para decifrar haremos uso de lo mismo mencionado anteriormente aplicando esta nueva formula en el la funcion de decifrado, que generara una ligera variante.

![decifrado](https://user-images.githubusercontent.com/90937895/165885818-21ae22ec-ac84-43e3-80ee-04d72ca756cb.png)

```python
def decrypt(a, b, text):
  result=""
  
  for i in text:
    
    n = 0
    for j in meta:
      if i==j:
        break
      n += 1 
    idx = (inverse(a,len(meta)) * (n - b)) % len(meta)
    result += meta[idx]
  
  return result
```

*Ejecucion*

<h5 a><strong><code>affine_encryption.py</code></strong></h5>

``` python
def run():
    a=2
    n=4

    key = 4, 7

    inverse_result = inverse(a, n)

    text="ELEMENTALMIQUERIDOWATSON"
    text_result = encrypt(*key,text)

    cipher_text="WXWBWFGHXBMUKWYMSNRHGCNF"
    cipher_text_result=decrypt(*key,cipher_text)

    print(inverse_result)
    print(text_result)
    print(cipher_text_result)
```

``` sh
foo@bar:~$ python affine_encryption.py

has no inverse.
WXWBWFGHXBMUKWYMSNRHGCNF
ELEMENTALMIQUERIDOWATSON
```

## Decifrado por fuerza bruta

En este caso, como su nombre menciona, tendremos que buscar combinaciones hasta encontrar la adecuada de forma aleatoria utilizando un patron de busqueda.

*paso a paso*

- Agregar la cada de texto encriptada que se requiere vulnerar
- se utilizara la funcionar de `decrypt` y con parametros en sucesion para intentar buscar la palabra mas adecuada en el texto encriptado.
- se recorrera mediante una lista para buscar esas posiblidades.
- finalmente podra ser encontrado, esto dependera de que tan complicado o extenso es el texto. 

*Ejecucion*

<h5 a><strong><code>forced_decryption.py</code></strong></h5>

```python
cipher_message: str="SLBCMVRBSHZBTÑSRQVVMSZBVHÑBVRQVLALHZBTÑSRQVWQAXLZWÑAQFQV"
text = "{0},{1} = {msg}"

for x in range(len(meta)):
  if (x % 3 != 0):
    for y in range(len(meta)):
      print(text.format(x, y, msg=decrypt(x,y,cipher_message)))

found = 23, 17

print("".join(['-' for _ in range(len(meta) * 2)]))
print(text.format(*found, msg=decrypt(*found,cipher_message)))
```

``` sh
foo@bar:~$ python forced_decryption.py

26,21 = CKTSJZDTCÑVTBHCDEZZJCVTZÑHTZDEZKUKÑVTBHCDEZYEUXKVYHUEPEZ
26,22 = DLUTKAEUDOWUCIDEFAAKDWUAOIUAEFALVLOWUCIDEFAZFVYLWZIVFQFA
26,23 = EMVULBFVEPXVDJEFGBBLEXVBPJVBFGBMWMPXVDJEFGBAGWZMXAJWGRGB
26,24 = FNWVMCGWFQYWEKFGHCCMFYWCQKWCGHCNXNQYWEKFGHCBHXANYBKXHSHC
26,25 = GÑXWNDHXGRZXFLGHIDDNGZXDRLXDHIDÑYÑRZXFLGHIDCIYBÑZCLYITID
26,26 = HOYXÑEIYHSAYGMHIJEEÑHAYESMYEIJEOZOSAYGMHIJEDJZCOADMZJUJE
------------------------------------------------------
23,17 = NOEXISTENPREGUNTASSINRESPUESTASOLOPREGUNTASMALFORMULADAS
```