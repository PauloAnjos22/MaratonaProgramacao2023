#include <stdio.h>

// Retorna o n-ésimo termo da sequência
int n_esimoSequencia(int array[], int n);

int main()
{
    int n, array[31];

    scanf("%d", &n);

    printf("%d\n", n_esimoSequencia(array, n));

    return 0;
}

int n_esimoSequencia(int array[], int n)
{
    for (int i = 0; i <= n; i++)
    {
        if (i < 2)
        {
            array[i] = 1;
        }
        else
        {
            array[i] = array[i - 1] + array[i - 2];
        }
    }
    return array[n];
}