#include <cmath>
#include <iostream>

using namespace std;

int primo(long long int num) {
  if (num <= 1)  // 1 e números menores não são primos
    return 0;
  if (num == 2)  // 2 é primo
    return 1;

  for (int i = 2; i <= sqrt(num); i++) {
    if (num % i == 0)
      return 0;  // Se encontrar um divisor, retorna 0 (não é primo)
  }
  return 1;  // Se não encontrar nenhum divisor, é primo
}

int main() {
  long long int num;

  cin >> num;

  if (!primo(num))
    cout << "S" << endl;  // Não é primo
  else
    cout << "N" << endl;  // É primo

  return 0;
}
