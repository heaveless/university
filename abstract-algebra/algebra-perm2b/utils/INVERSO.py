from utils.EUCLIDES_EXTEND import EUCLIDES_EXTEND

def INVERSO(a, n):
    (mcd, x, y) = EUCLIDES_EXTEND(a, n)
    if mcd == 1:
        return x % n
    else:
        return None