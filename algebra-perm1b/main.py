def eea(a, b):
    if not b:
        return (a, 1, 0)
    else:
        (r, _x, _y) = eea(b, a % b)
        return (r,) + (_y, _x - a//b * _y)

print(eea(128, 134))
print(eea(331, 337))
print(eea(991, 997))
