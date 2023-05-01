#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    // inteiro para o numero de paineis que consegue pressionar de uma vez
    int pressiona;
    scanf("%d", &pressiona);
    pressiona = pressiona * 2;
    // painel
    char painel[4][4];
    // Inicializa todas as posições do vetor como 0
    memset(painel, 0, sizeof(painel));

    // recebendo o painel
    for (int linha = 0; linha < 4; linha++)
    {
        scanf("%4s", painel[linha]);
    }
    int aux, digitos = 0;
    // Percorrendo as linhas da matriz de acordo com a ordem desejada
    for (int i = 1; i <= 9; i++)
    {
        aux = 0;
        char time[2];
        time[1] = '\0';
        sprintf(time, "%d", i);
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                if (time[0] == painel[j][k])
                    aux++;
            }
        }
        if (aux > pressiona)
        {
            printf("NO\n");
            break;
        }
    }
    if (aux <= pressiona)
        printf("YES\n");

    return 0;
}
