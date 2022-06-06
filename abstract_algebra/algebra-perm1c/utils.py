meta: str = "ABCDEFGHIJKLMNÑOPQRSTUVWXYZ"

def euclidean(a, b):
    return a if (b == 0) else euclidean(b, a % b)

def extendedEuclidean(a, b): 
    if (b == 0):
      return a,1,0
    d, _x, _y = extendedEuclidean(b, a % b)
    x = _y
    y = _x - _y * int(a / b)
    return d,x,y

def inverse(a, n):
  if (euclidean(a,n) == 1):
    d,x,y = extendedEuclidean(a, n)
    return(x % n)
  else:
    return "has no inverse."