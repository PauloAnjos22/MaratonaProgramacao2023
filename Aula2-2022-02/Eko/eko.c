#include <stdio.h>

long long int max_h(int trees[], int n, int m);

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int trees[n];
    // recebendo o array de arvores
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &trees[i]);
    }
    printf("%d\n", max_h(trees, n, m));

    return 0;
}

long long int max_h(int trees[], int n, int m)
{

    int inicio = 1, fim = m, meio, i;
    while (inicio < fim)
    {
        meio = (inicio + fim + 1) / 2;
        long long int sum = 0;
        for (i = 0; i < n; i++)
        {
            if (trees[i] > meio)
            {
                sum += trees[i] - meio;
            }
        }
        if (sum >= m)
        {
            inicio = meio;
        }
        else
        {
            fim = meio - 1;
        }
    }
    return inicio;
}