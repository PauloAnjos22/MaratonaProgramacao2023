#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

void minThrowOut(int A, int KA, int B, int KB, int N);
void maxTrhowOut(int A, int KA, int B, int KB, int N);

int main()
{
    int a1, a2, k1, k2, N;
    std::cin >> a1 >> a2 >> k1 >> k2 >> N;

    minThrowOut(a1, k1, a2, k2, N);
    maxTrhowOut(a1, k1, a2, k2, N);

    return 0;
}

// Definição da função
void minThrowOut(int A, int KA, int B, int KB, int N)
{
    int yellowCards = N;

    if (A > B)
    {
        for (int i = 0; i < A; i++)
        {
            yellowCards -= KA - 1;
            if (yellowCards <= 0)
            {
                break;
            }
        }
        for (int i = 0; i < B; i++)
        {
            yellowCards -= KB - 1;
            if (yellowCards <= 0)
            {
                break;
            }
        }
        if (yellowCards > 0)
        {
            std::cout << yellowCards << " ";
        }
        else
        {
            std::cout << 0 << " ";
        }
    }
    else
    {
        for (int i = 0; i < B; i++)
        {
            yellowCards -= KB - 1;
            if (yellowCards <= 0)
            {
                break;
            }
        }
        for (int i = 0; i < A; i++)
        {
            yellowCards -= KA - 1;
            if (yellowCards <= 0)
            {
                break;
            }
        }
        if (yellowCards > 0)
        {
            std::cout << yellowCards << " ";
        }
        else
        {
            std::cout << 0 << " ";
        }
    }
}

void maxTrhowOut(int A, int KA, int B, int KB, int N)
{
    int yellowCards = N;
    int maxThrowOut = 0;

    if (KA > KB)
    {
        for (int i = 0; i < B; i++)
        {
            yellowCards -= KB;
            if (yellowCards >= 0)
            {
                maxThrowOut++;
            }
            else
            {
                break;
            }
        }
        for (int i = 0; i < A; i++)
        {
            yellowCards -= KA;
            if (yellowCards >= 0)
            {
                maxThrowOut++;
            }
            else
            {
                break;
            }
        }
        std::cout << maxThrowOut << std::endl;
    }
    else
    {
        for (int i = 0; i < A; i++)
        {
            yellowCards -= KA;
            if (yellowCards >= 0)
            {
                maxThrowOut++;
            }
            else
            {
                break;
            }
        }
        for (int i = 0; i < B; i++)
        {
            yellowCards -= KB;
            if (yellowCards >= 0)
            {
                maxThrowOut++;
            }
            else
            {
                break;
            }
        }
        std::cout << maxThrowOut << std::endl;
    }
}
