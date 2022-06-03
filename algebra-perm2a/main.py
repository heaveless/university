from py.GEN_PRIMOS import GEN_PRIMOS
from py.RANDOMGEN_PRIMOS import RANDOMGEN_PRIMOS

def allPrimeNumber():
    pass

def randomPrimeNumber():
    source = [ 
        16, 16, 16,
        32, 32, 32,
        64, 64, 64, 64
    ]

    for i in source:
        prime = RANDOMGEN_PRIMOS(i)
        print(prime)

def main():
    allPrimeNumber()
    randomPrimeNumber()

main()