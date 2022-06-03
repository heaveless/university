from py.RANDOMBITS import RANDOMBITS
from py.MILLER_RABIN import MILLER_RABIN

configure_s = 40

def RANDOMGEN_PRIMOS(b):
    s = configure_s
    n = RANDOMBITS(b)
    while (not MILLER_RABIN(n, s)):
        n += 2
  
    return n

