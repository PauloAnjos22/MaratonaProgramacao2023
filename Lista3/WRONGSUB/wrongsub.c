#include <stdio.h>
#include <string.h>

// Retorna um inteiro referente à subtração, com base na lógica dada no exercício
int wrongSub(int *n, int k);

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);

    printf("%d\n", wrongSub(&n, k));
    return 0;
}

int wrongSub(int *n, int k)
{
    int ultimo_digito;

    for (int i = 0; i < k; i++)
    {
        ultimo_digito = *n % 10;
        if (ultimo_digito > 0)
        {
            (*n)--;
        }
        else
        {
            *n = *n / 10;
        }
    }
    return *n;
}
