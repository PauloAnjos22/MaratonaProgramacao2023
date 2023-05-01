#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    // sequencia de caracteres da risada
    char risada[50];

    scanf("%s", risada);

    char esqDir[50];

    char dirEsq[50];

    int count = 0;
    // laço para retirar as consoantes e guardar as vogais a serem lidas da esquerda -> direita
    for (int i = 0; i < 50; i++)
    {
        if (risada[i] == 'a' || risada[i] == 'e' || risada[i] == 'i' || risada[i] == 'o' || risada[i] == 'u')
        {
            esqDir[count] = risada[i];
            count++;
        }
    }

    // guarda as vogais da direita -> esquerda e faz a verificação se é uma boa risada
    int aux = count - 1;
    for (int j = 0; j < count; j++)
    {
        dirEsq[j] = esqDir[aux];
        aux--;

        if (dirEsq[j] != esqDir[j])
        {
            printf("N\n");
            break;
        }
        if (j + 1 == count)
        {
            printf("S\n");
        }
    }
    return 0;
}
