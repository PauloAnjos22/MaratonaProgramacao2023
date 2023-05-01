#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    // inteiro N
    int dimensao;
    scanf("%d", &dimensao);
    // tabuleiro Xi
    int tabuleiro[dimensao][dimensao], array_coluna[dimensao], array_linha[dimensao];
    // Inicializa todas as posições do vetor como 0
    memset(array_coluna, 0, sizeof(array_coluna));
    memset(array_linha, 0, sizeof(array_linha));
    // vetores auxiliares para guardar o valor total da maior soma e o indice da linha e coluna em que ela aparece
    int soma_linha[2], soma_coluna[2];
    soma_linha[0] = 0;
    soma_coluna[0] = 0;
    // recebendo o tabuleiro
    for (int i = 0; i < dimensao; i++)
    {
        for (int j = 0; j < dimensao; j++)
        {
            scanf("%d", &tabuleiro[i][j]);
            // recebendo a soma total da linha e da coluna
            array_linha[i] = array_linha[i] + tabuleiro[i][j];
            array_coluna[j] = array_coluna[j] + tabuleiro[i][j];
        }
    }
    // verificando qual a soma maxima possivel no tabuleiro
    int soma = 0, soma_aux = 0;
    for (int k = 0; k < dimensao; k++)
    {
        for (int l = 0; l < dimensao; l++)
        {
            soma_aux = (array_coluna[l] + array_linha[k]) - (2 * tabuleiro[k][l]);
            if (soma_aux >= soma)
                soma = soma_aux;
        }
    }
    printf("%d\n", soma);
    return 0;
}
