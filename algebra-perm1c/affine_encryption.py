from utils import meta, euclidean, extendedEuclidean, inverse
    
def encrypt(a, b, text):
  result = ""
  
  for i in text:
    
    n = 0
    for j in meta:
      if i==j:
        break
      n += 1

    idx = (a * n + b ) % len(meta)
    result += meta[idx]
  
  return result

def decrypt(a, b, text):
  result=""
  
  for i in text:
    
    n = 0
    for j in meta:
      if i==j:
        break
      n += 1 
    idx = (inverse(a,len(meta)) * (n - b)) % len(meta)
    result += meta[idx]
  
  return result

'''
    CODE EXECUTION
'''

def run():
    a=2
    n=4

    key = 4, 7

    inverse_result = inverse(a, n)

    text="ELEMENTALMIQUERIDOWATSON"
    text_result = encrypt(*key,text)

    cipher_text="WXWBWFGHXBMUKWYMSNRHGCNF"
    cipher_text_result=decrypt(*key,cipher_text)

    print(inverse_result)
    print(text_result)
    print(cipher_text_result)

run()