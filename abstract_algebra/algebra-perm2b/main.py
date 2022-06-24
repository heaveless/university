from utils.RANDOMGEN_PRIMOS import RANDOMGEN_PRIMOS
from utils.RANDOMBITS import RANDOMBITS
from utils.EUCLIDES import EUCLIDES
from utils.INVERSO import INVERSO
from utils.EXP_MOD import EXP_MOD

def genKey(bits):
    b_instance = bits // 2
    p_prime = RANDOMGEN_PRIMOS(b_instance)
    q_prime = RANDOMGEN_PRIMOS(b_instance)
    while p_prime == q_prime:
        q_prime = RANDOMGEN_PRIMOS(b_instance)

    prime_value = p_prime * q_prime
    phiN = (p_prime - 1) * (q_prime - 1)

    random_value = RANDOMBITS(bits)
    while EUCLIDES(random_value, phiN) != 1:
        random_value = RANDOMBITS(bits)
    
    inverse_value = INVERSO(random_value, phiN)
    return ([random_value, prime_value], [inverse_value, prime_value])

def rsaCipher(m, k):
    return EXP_MOD(m, k[0], k[1])

def main():
    (P, S) = genKey(64)
    m_list=[]
    # print(P, S)
    print('{:^20}{:^20}{:^20}'.format('m', 'c', 'm\''))
    for i in range(10):
        m = RANDOMBITS(32)
        while m in m_list:
            m = RANDOMBITS(32)
        m_list.append(m)
        c = rsaCipher(m, P)
        print('{:^20}{:^20}{:^20}'.format(m, c, rsaCipher(c, S)))

main()