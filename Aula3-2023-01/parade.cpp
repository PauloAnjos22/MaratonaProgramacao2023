#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
#include <algorithm>

int main()
{
    int n, x, lower, possible;
    std::stack<int> pilha;

    while (true)
    {
        std::cin >> n;
        lower = 1;
        possible = 1;
        if (n == 0)
        {
            break;
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                std::cin >> x;
                if (x == lower) // Se o valor lido for igual ao valor esperado, incrementa o valor esperado
                {
                    lower++;
                }
                else if (!pilha.empty() && pilha.top() == lower) // Esvazia a pilha conforme a ordem
                {
                    while (!pilha.empty() && pilha.top() == lower)
                    {
                        lower++;
                        pilha.pop();
                    }
                    pilha.push(x);
                }
                else if (!pilha.empty() && pilha.top() < x) // Tratando o caso de erro de ordem
                {
                    possible = -1;
                }
                else
                {
                    pilha.push(x);
                }
            }
            while (!pilha.empty()) // Esvazia a pilha para a proxima entrada
            {
                pilha.pop();
            }
            if (possible > 0)
            {
                std::cout << "yes\n";
            }
            else
            {
                std::cout << "no\n";
            }
        }
    }

    return 0;
}
