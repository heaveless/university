#include <iostream>
#include <stdexcept>
#include <string>
#include <tuple>

std::string meta = "ABCDEFGHIJKLMNÑOPQRSTUVWXYZ";

int euclidean(int a, int b) {
  return (b == 0) ? a : euclidean(b, a % b);
}

std::tuple<int, int, int> extendedEuclidean(int a, int b) {
  if (b == 0)
    return std::make_tuple(a, 1, 0);
  
  std::tuple<int, int, int> eu = extendedEuclidean(b, a % b);
  int x = std::get<2>(eu);
  int y = std::get<1>(eu) - std::get<2>(eu) * (int)(a / b);

  return std::make_tuple(std::get<0>(eu), x, y);
}

int inverse(int a, int n) {
  if (euclidean(a, n) == 1) {
    std::tuple<int, int, int> eu = extendedEuclidean(a, n);
    return std::get<1>(eu) % n;
  }
  else throw std::invalid_argument("has no inverse.");
}

std::string encrypt(int a, int b, std::string text) {
  std::string result = "";

  for(std::string::size_type i = 0; i < text.size() - 1; ++i) {
    int n = 0;

    for(std::string::size_type j = 0; j < meta.size() - 1; ++j) {
      std::cout << i << " " << j << std::endl;
      if (text[i] == meta[j]) break;
      n++;
    }

    int idx = (a * n + b) % (meta.size() - 1);
    result += meta[idx];
  }

  return result;
}

std::string decrypt(int a, int b, std::string text) {
  std::string result = "";

  for(char& c : text) {
    int n = 0;

    for(char& d : meta) {
      if (c == d) break;
      n++;
    }

    int idx = (reverse(a, meta.size()) * (n - b)) % meta.size();
    result += meta[idx];
  }

  return result;
}

int main() {

  int a = 4;
  int n = 7;

  // std::cout << inverse(a, n) << std::endl;

  std::string text = "ELEMENTALMIQUERIDOWATSON";
  std::string textResult = encrypt(4, 7, text);

  // std::string cipherText = "OKHFSNKFNWFCWJHSNCHQYWFSWF";
  // std::string cipherTextResult = decrypt(4, 7, text);

  std::cout << textResult << std::endl;
  // std::cout << cipherTextResult << std::endl;

  return 0;
}