from py.GEN_PRIMOS import GEN_PRIMOS
from py.RANDOMGEN_PRIMOS import RANDOMGEN_PRIMOS

def allPrimeNumber():
    print("\n{0}:\n".format(allPrimeNumber.__name__))
    
    listaNum = [3,4,5]
    for i in listaNum:
        print(f"\nNumeros primos de {i} digitos:")
        numero = (10**(i-1))
        while(numero <= (10**i)):
            if MILLER_RABIN(numero,50):
                print(numero,end="--")
            numero += 1
    print("\n")

def randomPrimeNumber():
    print("\n{0}:\n".format(randomPrimeNumber.__name__))

    source = [ 
        16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
        32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
        64, 64, 64, 64, 64, 64, 64, 64, 64, 64
    ]

    for i in source:
        prime = RANDOMGEN_PRIMOS(i)
        print("{0}bits -> {1}".format(i, prime))

def main():
    allPrimeNumber()
    randomPrimeNumber()

main()
