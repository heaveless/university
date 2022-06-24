from utils.RANDOMBITS import RANDOMBITS
from utils.MILLER_RABIN import MILLER_RABIN
import random

configure_s = 40

def RANDOMGEN_PRIMOS(b):
    s = configure_s
    n = RANDOMBITS(b)
    while (not MILLER_RABIN(n, s)):
        n += 2
    return n

def main():
    p = RANDOMGEN_PRIMOS(32)
    q = RANDOMGEN_PRIMOS(32)
    n =  p*q 
    numeroPhi=(p-1)*(q-1)
    print(numeroPhi)

    # while (True):
    #     e=random.randint(2,n-1)
    #     if(euclides(e,phi_n )==1):
    #         break  

main()