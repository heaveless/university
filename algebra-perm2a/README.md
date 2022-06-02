#Algebra Abstracta perm2a

**All prime numbers [3, 4, 5]length**

any content here

```c++
void allPrimeNumber() {
  std::cout << __func__ << std::endl;

  int source[] = { 3, 4, 5 };
  int length = sizeof(source) / sizeof(*source);

  for (int* i = source; i < source + length; i++) {
    int prime = GEN_PRIMOS(*i);
    std::cout << prime << std::endl;
  }
}
```

**Random Prime Numbers [16, 32, 64]bits**

any content here

```c++
void randomPrimeNumber() {
  std::cout << __func__ << std::endl;

  int source[] = { 
    16, 16, 16,
    32, 32, 32,
    64, 64, 64, 64
  };

  int length = sizeof(source) / sizeof(*source);

  for (int* i = source; i < source + length; i++) {
    int prime = RANDOMGEN_PRIMOS(*i);
    std::cout << prime << std::endl;
  }
}
```
