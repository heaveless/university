from py.GEN_PRIMOS import GEN_PRIMOS
from py.RANDOMGEN_PRIMOS import RANDOMGEN_PRIMOS

def allPrimeNumber():
    print("\n{0}:\n".format(allPrimeNumber.__name__))
    pass

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