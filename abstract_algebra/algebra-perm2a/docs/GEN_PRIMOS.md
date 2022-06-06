# GEN_PRIMOS

any content here

```python
from py.MILLER_RABIN import MILLER_RABIN

def GEN_PRIMOS(n):
    s = 0
    n = n + 1 - (n % 2)

    while (not MILLER_RABIN(n, s)):
        n += 2

    return n
```