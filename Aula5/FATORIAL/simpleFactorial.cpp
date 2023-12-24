#include <iostream>
#include <sstream>

int factorCalculation(int N);

int main()
{
    int N;
    std::cin >> N;

    std::cout << factorCalculation(N) << std::endl; // Calcula o fatorial de N
    return 0;
}

int factorCalculation(int N)
{
    if (N == 1)
        return 1;
    else
    {
        return N * factorCalculation(N - 1);
    }
}