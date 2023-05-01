#include <stdio.h>
#include <string.h>
#include <ctype.h>

// funcao que recebe os pares e retorna a quantidade encontrada
int totalPares(int tamanho[], char pe[], int qtd_botas);

int main()
{
    // inteiro N
    int qtd_botas;
    scanf("%d", &qtd_botas);
    // inteiro M
    int tam_botas[qtd_botas];
    // qual o pe da bota (L)
    char pe_bota[qtd_botas + 1];
    pe_bota[qtd_botas] = '\0';

    printf("%d\n", totalPares(tam_botas, pe_bota, qtd_botas));
    return 0;
}
int totalPares(int tamanho[], char pe[], int qtd_botas)
{
    int pares = 0;
    // recebendo as botas
    for (int i = 0; i < qtd_botas; i++)
    {
        scanf("%d %c", &tamanho[i], &pe[i]);
        // verificando quantos pares existem
        if (i > 0)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (tamanho[i] == tamanho[j] && pe[i] != pe[j])
                {
                    pares++;
                    tamanho[i] = -1;
                    tamanho[j] = -1;
                    pe[i] = '\0';
                    pe[j] = '\0';
                }
            }
        }
    }
    // retornando a quantidade de pares das botas recebidas
    return pares;
}