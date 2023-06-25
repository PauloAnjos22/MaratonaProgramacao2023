#include <stdio.h>
#include <string.h>

// Retorna um inteiro referente a quantidade de anos que levará para o urso ficar mais gordo que o irmao
int overTheYears(int a, int b);

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);

    printf("%d\n", overTheYears(a, b));
    return 0;
}

int overTheYears(int a, int b)
{
    int tempo = 0;

    while (a <= b)
    {
        a = a * 3;
        b = b * 2;
        tempo++;
    }
    return tempo;
}
