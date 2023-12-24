#include <stdio.h>
#include <string.h>

// função que realiza a ordenação do vetor de elementos
void quick_sort(int array_elementos[], int inicio, int fim);
int divisao(int array_elementos[], int inicio, int fim);
void troca(int *a, int *b);

int main()
{
    // quantidade de elementos a serem ordenados
    int qtd_elementos;
    scanf("%d", &qtd_elementos);
    int array_elementos[qtd_elementos];
    // recebendo a sequência
    for (int i = 0; i < qtd_elementos; i++)
    {
        scanf("%d", &array_elementos[i]);
    }
    // ordenando o vetor de elementos
    quick_sort(array_elementos, 0, qtd_elementos - 1);
    // printando a sequência ordenada
    for (int j = 0; j < qtd_elementos; j++)
    {
        printf("%d ", array_elementos[j]);
    }

    printf("\n");
    return 0;
}

void quick_sort(int arr[], int inicio, int fim)
{
    if (inicio < fim)
    {
        int pi = divisao(arr, inicio, fim);
        quick_sort(arr, inicio, pi - 1);
        quick_sort(arr, pi + 1, fim);
    }
}

int divisao(int arr[], int inicio, int fim)
{
    int pivot = arr[fim];
    int i = (inicio - 1);

    for (int j = inicio; j <= fim - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            troca(&arr[i], &arr[j]);
        }
    }
    troca(&arr[i + 1], &arr[fim]);
    return (i + 1);
}

void troca(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
