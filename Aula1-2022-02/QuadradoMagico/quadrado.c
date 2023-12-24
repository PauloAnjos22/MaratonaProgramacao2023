#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    // ordem da matriz
    int N, somaLinha = 0, somaColuna = 0, somaDiagonalPrincipal = 0, somaDiagonalSecundaria = 0;
    scanf("%d", &N);
    // matriz com os valores
    int quadrado_magico[N][N], linha[N], coluna[N];
    // laco para receber a matriz
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &quadrado_magico[i][j]);
        }
    }
    // laco para fazer a soma e verificar se eh um quadrado magico
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            somaLinha = somaLinha + quadrado_magico[i][j];
            somaColuna = somaColuna + quadrado_magico[j][i];
            somaDiagonalPrincipal = somaDiagonalPrincipal + quadrado_magico[j][j];
            somaDiagonalSecundaria = somaDiagonalSecundaria + quadrado_magico[j][(N - 1) - j];
        }
        linha[i] = somaLinha;
        coluna[i] = somaColuna;
        // fazendo a verificacao
        if (i > 0)
        {
            if (linha[i] != linha[i - 1] || coluna[i] != coluna[i - 1] || linha[i] != coluna[i] || linha[i] != somaDiagonalPrincipal || coluna[i] != somaDiagonalPrincipal || linha[i] != somaDiagonalSecundaria || coluna[i] != somaDiagonalSecundaria || somaDiagonalPrincipal != somaDiagonalSecundaria)
            {
                printf("-1\n");
                return 0;
            }
        }
        else
        {
            if (linha[i] != coluna[i])
            {
                printf("-1\n");
                return 0;
            }
        }
        somaColuna = 0;
        somaDiagonalPrincipal = 0;
        somaDiagonalSecundaria = 0;
        somaLinha = 0;
    }
    // caso saia do laco de repeticao, todos os valores foram iguais e a matriz eh um quadrado magico
    printf("%d\n", linha[0]);
    return 0;
}
