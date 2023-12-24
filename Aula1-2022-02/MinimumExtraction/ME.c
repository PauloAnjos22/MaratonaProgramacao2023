#include <stdio.h>
#include <string.h>
#include <ctype.h>

int comparador(const void *a, const void *b);

int main()
{
    int qtd_testes, i = 0, qtd_elementos;
    scanf("%d", &qtd_testes);
    while (qtd_testes > i)
    {
        scanf("%d", &qtd_elementos);
        int array_elementos[qtd_elementos];
        for (int i = 0; i < qtd_elementos; i++)
        {
            scanf("%d", &array_elementos[i]);
            if (i > 0)
                // ordena o array
                qsort(array_elementos, qtd_elementos, sizeof(int), comparador);
        }
    }

    // printf("%d\n", soma);
    return 0;
}
int comparador(const void *a, const void *b)
{

    if (*(int *)a > *(int *)b)
    {
        return 1;
    }
    else if (*(int *)a < *(int *)b)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}