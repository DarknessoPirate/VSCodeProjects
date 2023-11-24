#include <iostream>
#include <vector>

unsigned int UseOperator(unsigned int a, unsigned int b, char op) {
  switch (op) {
    case '&': return a & b;
    case '|': return a | b;
    case '^': return a ^ b;
    case '*': return a * b;
    case '+': return a + b;
    case '-': return a - b;
  }
  return 0;
}

std::vector<unsigned int> Generator(char op, unsigned int m, std::vector<unsigned int> dane, int k, int n) {
  for (int i = dane.size() - 1; i + 1 < n; i++) {
    unsigned int a = dane[i];
    unsigned int b = dane[i - k];
    dane.push_back(UseOperator(a, b, op) % m);
  }
  return dane;
}

int main()
{
    char op;
  unsigned int m;
  int k, n, tmp;
  std::cout << "Podaj operacje\n op = ";
  std::cin >> op;
  std::cout << "Podaj zakres (od 0 do m)?\n m = ";
  std::cin >> m;
  std::cout << "Ile wyrazow wypisac?\n n = ";
  std::cin >> n;
  std::cout << "Ktory wyraz wstecz?\n k = ";
  std::cin >> k;
  std::vector<unsigned int> dane;
  std::cout << "Podaj " << (k + 1) << " pierwszych wyrazow:\n";
  for (unsigned int i = 0; i < k + 1; i++) {
    std::cin >> tmp;
    dane.push_back(tmp);
  }
  std::vector<unsigned int> wynik = Generator(op, m, dane, k, n);
  for(unsigned int x : wynik) 
    std::cout << x << " ";
  
}