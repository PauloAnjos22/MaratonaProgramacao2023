#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

struct Dragon // Struct para armazenar a força do inimigo e o bonus por derrotar
{
    int x; // força do inimigo
    int y; // bonus por derrotar

    // Usei isso aqui pra sobrebor o operador < e poder usar o sort para ordenar com base apenas no valor de x
    bool operator<(const Dragon &other) const
    {
        return x < other.x;
    }
};
int fight(int forceKirito, std::vector<Dragon> arrayEnemy, int n); // Função para simular a luta

int main()
{
    // s = força do kirito
    int s, n, result;
    // Array com a força do dragao e o bonus
    std::vector<Dragon> arrayEnemy;
    std::cin >> s >> n;

    for (int i = 0; i < n; i++)
    {
        int x, y; // x = força do inimigo y bonus do inimigo
        std::cin >> x >> y;
        arrayEnemy.push_back({x, y});                    // Adiciona o inimigo no array
        std::sort(arrayEnemy.begin(), arrayEnemy.end()); // Ordena o array de acordo com o valor de x
    }
    if (fight(s, arrayEnemy, n) > 0)
        std::cout << "YES" << std::endl;
    else
        std::cout << "NO" << std::endl;
    return 0;
}

int fight(int forceKirito, std::vector<Dragon> arrayEnemy, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (forceKirito > arrayEnemy[i].x)
        {
            forceKirito += arrayEnemy[i].y;
        }
        else // Não consegue derrotar o inimigo
        {
            return -1;
        }
    }
    return 1;
}
