#include <iostream>
#include <sstream>
#include <stack>
#include <string>

int verifyString(std::string A); // Função para verificar se a cadeia é válida
int main()
{
    // s = força do kirito
    int T;
    std::cin >> T;
    std::string A;

    for (int i = 0; i < T; i++)
    {
        std::cin >> A;
        if (verifyString(A) > 0) // Verifica se a cadeia é válida
            std::cout << "S" << std::endl;
        else
            std::cout << "N" << std::endl;
    }

    return 0;
}

int verifyString(std::string A)
{
    // pilha de char
    std::stack<char> pilha;
    for (int i = 0; i < A.size(); i++) // Percorre a cadeia
    {
        if (A[i] == '(' || A[i] == '[' || A[i] == '{')
        {
            pilha.push(A[i]); // Adiciona o elemento no topo da pilha
        }
        else
        {
            if (pilha.empty()) // Se a pilha estiver vazia entao não há um par para a chave
            {
                return -1;
            }
            else
            {
                if (A[i] == ')')
                {
                    if (pilha.top() == '(')
                    {
                        pilha.pop(); // Remove o elemento do topo da pilha
                    }
                    else
                    {
                        return -1;
                    }
                }
                else if (A[i] == ']')
                {
                    if (pilha.top() == '[')
                    {
                        pilha.pop(); // Remove o elemento do topo da pilha
                    }
                    else
                    {
                        return -1;
                    }
                }
                else if (A[i] == '}')
                {
                    if (pilha.top() == '{')
                    {
                        pilha.pop(); // Remove o elemento do topo da pilha
                    }
                    else
                    {
                        return -1;
                    }
                }
            }
        }
    }
    return 1;
}
