#include <stdio.h>
#include <string.h>

// Retorna o maior número dentro do array
int maiorNumero(int array_valores[]);

int main()
{
    int entrada[100];
    // Recebe a entrada
    for (int i = 0; i < 100; i++)
    {
        scanf("%d", &entrada[i]);
        if (entrada[i] == 0)
        {
            break;
        }
    }

    printf("%d\n", maiorNumero(entrada));

    return 0;
}

int maiorNumero(int array_valores[])
{
    int maior_numero = 0;

    for (int i = 0; array_valores[i] != 0; i++)
    {
        if (array_valores[i] > maior_numero)
        {
            maior_numero = array_valores[i];
        }
    }
    return maior_numero;
}