from utils.RANDOMGEN_PRIMOS import RANDOMGEN_PRIMOS
from utils.RANDOMBITS import RANDOMBITS
from utils.EUCLIDES import EUCLIDES
from utils.INVERSO import INVERSO
from utils.EXP_MOD import EXP_MOD

def RSA_KEY_GENERATOR(bits):
    arg = bits // 2
    p = RANDOMGEN_PRIMOS(arg)
    q = RANDOMGEN_PRIMOS(arg)
    while p == q:
        q = RANDOMGEN_PRIMOS(arg)

    n = p * q
    phiN = (p - 1) * (q - 1)
    
    e = RANDOMBITS(bits)
    while EUCLIDES(e, phiN) != 1:
        e = RANDOMBITS(bits)
    
    d = INVERSO(e, phiN)
    return (e, n), (d, n)

def CIPHER(m, k: tuple):
    arg1, arg2 = k
    return EXP_MOD(m, arg1, arg2)

def main():
    k = 64
    P, S = RSA_KEY_GENERATOR(k)
    e, n = P
    d, _ = S

    tab = 62
    print('e = {:}\nd = {:}\nn = {:}\n'.format(e, d, n))
    print('-' * tab)
    print('{:^20}{:^20}{:^20}'.format('m', 'c = P(m)', 'm\' = S(c)'))
    print('-' * tab)

    stack = []
    for i in range(10):
        m = RANDOMBITS(32)
        while m in stack:
            m = RANDOMBITS(32)
        stack.append(m)
        c = CIPHER(m, P)
        print('{:^20}{:^20}{:^20}'.format(m, c, CIPHER(c, S)))

main()