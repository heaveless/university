# RANDOMBITS

any content here

```python
import math
from py.RANDOMINTEGER import RANDOMINTEGER

def RANDOMBITS(b):
    max = pow(2, b) - 1
    n = RANDOMINTEGER(0, max)
    m = pow(2, b - 1) + 1
    n = n | m

    return n
```