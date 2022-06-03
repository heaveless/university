from RANDOMBITS import RANDOMBITS
from MILLER_RABIN import MILLER_RABIN

def RANDOMGEN_PRIMOS(b):
    s = 0
    n = RANDOMBITS(b)
    while (not MILLER_RABIN(n, s)):
        n += 2
  
    return n

