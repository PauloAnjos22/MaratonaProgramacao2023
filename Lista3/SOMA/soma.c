#include <stdio.h>
#include <string.h>

// Retorna a soma de dois números
int soma(int num1, int num2);

int main()
{
    // Recebe as variáveis a serem somadas
    int X, Y;

    scanf("%d%d", &X, &Y);

    printf("%d\n", soma(X, Y));

    return 0;
}

int soma(int num1, int num2)
{
    int resultado = num1 + num2;

    return resultado;
}