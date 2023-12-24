#include <iostream>
#include <sstream>
#include <cmath>

float notesDecomposion(float N); // Função que adiciona os valores pares no vetor
void coinsDecomposion(float N);  // Função que adiciona os valores ímpares no vetor

int main()
{
    float N;
    std::cin >> N;
    std::cout << "NOTAS:" << std::endl;
    N = notesDecomposion(N);
    std::cout << "MOEDAS:" << std::endl;
    coinsDecomposion(N);
    return 0;
}

float notesDecomposion(float N)
{
    int div = 0;

    div = N / 100;
    if (div > 0)
    {
        std::cout << div << " nota(s) de R$ 100.00" << std::endl;
        N -= div * 100;
    }
    else
    {
        std::cout << div << " nota(s) de R$ 100.00" << std::endl;
    }
    div = N / 50;
    if (div > 0)
    {
        std::cout << div << " nota(s) de R$ 50.00" << std::endl;
        N -= div * 50;
    }
    else
    {
        std::cout << div << " nota(s) de R$ 50.00" << std::endl;
    }
    div = N / 20;
    if (div > 0)
    {
        std::cout << div << " nota(s) de R$ 20.00" << std::endl;
        N -= div * 20;
    }
    else
    {
        std::cout << div << " nota(s) de R$ 20.00" << std::endl;
    }
    div = N / 10;
    if (div > 0)
    {
        std::cout << div << " nota(s) de R$ 10.00" << std::endl;
        N -= div * 10;
    }
    else
    {
        std::cout << div << " nota(s) de R$ 10.00" << std::endl;
    }
    div = N / 5;
    if (div > 0)
    {
        std::cout << div << " nota(s) de R$ 5.00" << std::endl;
        N -= div * 5;
    }
    else
    {
        std::cout << div << " nota(s) de R$ 5.00" << std::endl;
    }
    div = N / 2;
    if (div > 0)
    {
        std::cout << div << " nota(s) de R$ 2.00" << std::endl;
        N -= div * 2;
    }
    else
    {
        std::cout << div << " nota(s) de R$ 2.00" << std::endl;
    }
    return N;
}

void coinsDecomposion(float N)
{
    N = std::round(N * 100.0) / 100.0; // Arredonda o valor para duas casas decimais
    N = N * 100;                       // Multiplica por 100 para evitar erros de precisão
    int div = 0;
    div = N / 100;
    if (div > 0)
    {
        std::cout << div << " moeda(s) de R$ 1.00" << std::endl;
        N -= div * 100;
    }
    else
    {
        std::cout << div << " moeda(s) de R$ 1.00" << std::endl;
    }
    div = N / 50;
    if (div > 0)
    {
        std::cout << div << " moeda(s) de R$ 0.50" << std::endl;
        N -= div * 50;
    }
    else
    {
        std::cout << div << " moeda(s) de R$ 0.50" << std::endl;
    }
    div = N / 25;
    if (div > 0)
    {
        std::cout << div << " moeda(s) de R$ 0.25" << std::endl;
        N -= div * 25;
    }
    else
    {
        std::cout << div << " moeda(s) de R$ 0.25" << std::endl;
    }
    div = N / 10;
    if (div > 0)
    {
        std::cout << div << " moeda(s) de R$ 0.10" << std::endl;
        N -= div * 10;
    }
    else
    {
        std::cout << div << " moeda(s) de R$ 0.10" << std::endl;
    }
    div = N / 5;
    if (div > 0)
    {
        std::cout << div << " moeda(s) de R$ 0.05" << std::endl;
        N -= div * 5;
    }
    else
    {
        std::cout << div << " moeda(s) de R$ 0.05" << std::endl;
    }
    div = N / 1;
    if (div > 0)
    {
        std::cout << div << " moeda(s) de R$ 0.01" << std::endl;
        N -= div * 1;
    }
    else
    {
        std::cout << div << " moeda(s) de R$ 0.01" << std::endl;
    }
}