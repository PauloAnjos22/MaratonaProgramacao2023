#include <stdio.h>
#include <string.h>

// função que retorna a altura máxima com base na quantidade de moedas passadas no parâmetro
int alturaMaxima(int moedas);

int main()
{
    int testes, moedas;
    scanf("%d", &testes);

    for (int i = 0; i < testes; i++)
    {
        scanf("%d", &moedas);
        // chama a função que irá trazer a altura máxima para a quantidade de moedas passadas
        int result = alturaMaxima(moedas);
        printf("%d\n", result);
    }
    return 0;
}

// função que retorna a altura máxima com base na quantidade de moedas passadas no parâmetro
int alturaMaxima(int moedas)
{
    int altura = 0;

    // a cada novo loop, a altura aumenta e as moedas diminuem com base no valor dessa altura
    // assim, no nível 1 as moedas serão, por exemplo, 3-1 = 2; no segundo nível 2-2 = 0, portanto, a altura máxima é o nível 2
    while (moedas > 0)
    {
        altura++;
        moedas = moedas - altura;
    }
    if (moedas < 0)
        altura--;
    return altura;
}