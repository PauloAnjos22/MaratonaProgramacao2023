#include <stdio.h>
#include <string.h>
#include <ctype.h>

// funcao que recebe os pares e retorna a quantidade encontrada
// int totalPares(int tamanho[], char pe[], int qtd_botas);

int main()
{
    // inteiro N
    int dimensao;
    scanf("%d", &dimensao);
    // tabuleiro Xi
    int tabuleiro[dimensao][dimensao], array_result[4];
    array_result[0] = 0;
    array_result[2] = 0;
    // recebendo o tabuleiro
    for (int i = 0; i < dimensao; i++)
    {
        for (int j = 0; j < dimensao; j++)
        {
            scanf("%d", &tabuleiro[i][j]);
        }
    }
    // procurando o maior peso
    int soma_linha = 0, soma_coluna = 0;
    for (int k = 0; k < dimensao; k++)
    {
        for (int l = 0; l < dimensao; l++)
        {
            soma_linha = soma_linha + tabuleiro[k][l];
            soma_coluna = soma_coluna + tabuleiro[l][k];
            // atualizando o array com a maior sequencia de somas de linhas e colunas e o indice delas na matriz
            if (soma_linha > array_result[0])
            {
                array_result[0] = soma_linha;
                array_result[1] = k;
            }
            if (soma_coluna > array_result[2])
            {
                array_result[2] = soma_coluna;
                array_result[3] = k;
            }
        }
    }
    // realizando a soma
    int soma = 0, indice_aux = 0;
    for (int m = array_result[1]; m < dimensao; m++)
    {
        if (array_result[3] != indice_aux)
        {
            soma = soma + tabuleiro[m][indice_aux];
            indice_aux++;
        }
    }
    return 0;
}
// int totalPares(int tamanho[], char pe[], int qtd_botas)
// {
//     int pares = 0;
//     // recebendo as botas
//     for (int i = 0; i < qtd_botas; i++)
//     {
//         scanf("%d %c", &tamanho[i], &pe[i]);
//         // verificando quantos pares existem
//         if (i > 0)
//         {
//             for (int j = i - 1; j >= 0; j--)
//             {
//                 if (tamanho[i] == tamanho[j] && pe[i] != pe[j])
//                 {
//                     pares++;
//                     tamanho[i] = -1;
//                     tamanho[j] = -1;
//                 }
//             }
//         }
//     }
//     // retornando a quantidade de pares das botas recebidas
//     return pares;
// }