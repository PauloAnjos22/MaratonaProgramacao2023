#include <iostream>
#include <sstream>
#include <vector>

// Criando os vetores de inteiros
std::vector<int> evenArray;
std::vector<int> oddArray;

void evenArrayFunction(int N); // Função que adiciona os valores pares no vetor
void oddArrayFunction(int N);  // Função que adiciona os valores ímpares no vetor

int main()
{
    int N;
    for (int i = 0; i < 15; i++)
    {
        std::cin >> N;
        if (N % 2 == 0) // Se o número for par
        {
            evenArrayFunction(N);
        }
        else
        {
            oddArrayFunction(N);
        }
    }
    for (int i = 0; i < oddArray.size(); i++)
    {
        std::cout << "impar[" << i << "]"
                  << " = " << oddArray[i] << std::endl;
    }
    for (int i = 0; i < evenArray.size(); i++)
    {
        std::cout << "par[" << i << "]"
                  << " = " << evenArray[i] << std::endl;
    }
    return 0;
}

void evenArrayFunction(int N)
{
    evenArray.push_back(N);    // Adiciona o valor no vetor
    if (evenArray.size() == 5) // Printa todo o vetor e o limpa
    {
        for (int i = 0; i < 5; i++)
        {
            std::cout << "par[" << i << "]"
                      << " = " << evenArray[i] << std::endl;
        }
        evenArray.clear();
    }
}

void oddArrayFunction(int N)
{
    oddArray.push_back(N);    // Adiciona o valor no vetor
    if (oddArray.size() == 5) // Printa todo o vetor e o limpa
    {
        for (int i = 0; i < 5; i++)
        {
            std::cout << "impar[" << i << "]"
                      << " = " << oddArray[i] << std::endl;
        }
        oddArray.clear();
    }
}