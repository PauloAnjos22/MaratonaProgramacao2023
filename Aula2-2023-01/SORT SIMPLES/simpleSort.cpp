#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    std::string input; // Declara uma string

    std::getline(std::cin, input); // Lê a linha inteira

    std::vector<int> sortString; // Declara um vetor de inteiros

    std::istringstream iss(input); // Lê a string

    int value;
    while (iss >> value) // Tokeniza a string e adiciona no vetor
    {
        sortString.push_back(value);
    }

    std::sort(sortString.begin(), sortString.end()); // Ordena o array
    for (const auto &n : sortString)
    {
        std::cout << n << "\n";
    }

    std::cout << std::endl;

    std::istringstream string(input); // Lê a string novamente
    while (string >> value)           // Printa ela tokenizada
    {
        std::cout << value << "\n";
    }

    return 0;
}
