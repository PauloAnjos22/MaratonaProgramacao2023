#include <stdio.h>
#include <string.h>

// Retorna o caminho onde a bola irá cair nesse fliper simples
char fliper(int entrada[]);

int main()
{
    int arrayEntrada[2];
    // Recebe a entrada
    for (int i = 0; i < 2; i++)
    {
        scanf("%d", &arrayEntrada[i]);
    }

    printf("%c\n", fliper(arrayEntrada));

    return 0;
}

char fliper(int entrada[])
{
    if (entrada[0] == 0)
    {
        return 'C';
    }
    else
    {
        if (entrada[1] == 0)
        {
            return 'B';
        }
        else
        {
            return 'A';
        }
    }
}