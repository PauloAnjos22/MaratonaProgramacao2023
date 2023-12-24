#include <stdio.h>
#include <string.h>

// Lê o array com a sequência de apertos e altera o estado das lâmpadas
void estadoFinalLampada(int array_valores[], int qtd, int *A, int *B);
// Altera o estado da lâmpada passada no parâmetro
void trocaEstado(int *lampada);

int main()
{
    int apertos, lampada_A = 0, lampada_B = 0;
    scanf("%d", &apertos);
    int sequencia[apertos];
    // Recebe a entrada
    for (int i = 0; i < apertos; i++)
    {
        scanf("%d", &sequencia[i]);
    }
    estadoFinalLampada(sequencia, apertos, &lampada_A, &lampada_B);
    printf("%d\n%d\n", lampada_A, lampada_B);

    return 0;
}

void estadoFinalLampada(int array_valores[], int qtd, int *A, int *B)
{
    for (int i = 0; i < qtd; i++)
    {
        if (array_valores[i] == 1)
        {
            trocaEstado(A);
        }
        else
        {
            trocaEstado(A);
            trocaEstado(B);
        }
    }
}
void trocaEstado(int *lampada)
{
    if (*lampada == 0)
    {
        *lampada = 1;
    }
    else
    {
        *lampada = 0;
    }
}
