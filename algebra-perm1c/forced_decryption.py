from utils import meta, euclidean, extendedEuclidean, inverse
from affine_encryption import encrypt, decrypt

cipher_message: str="SLBCMVRBSHZBTÑSRQVVMSZBVHÑBVRQVLALHZBTÑSRQVWQAXLZWÑAQFQV"
text = "{0},{1} = {msg}"

for x in range(len(meta)):
  if (x % 3 != 0):
    for y in range(len(meta)):
      print(text.format(x, y, msg=decrypt(x,y,cipher_message)))

found = 23, 17

print("".join(['-' for _ in range(len(meta) * 2)]))
print(text.format(*found, msg=decrypt(*found,cipher_message)))