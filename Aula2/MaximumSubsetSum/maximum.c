#include <stdio.h>
#include <string.h>

// funcao para descobrir a maior soma dos subconjuntos do array
int maiorSoma(int array_teste[], int qtd_elementos);

int main()
{
    int testes, qtd_elementos, result;
    scanf("%d", &testes);

    for (int i = 0; i < testes; i++)
    {
        // recebendo os elementos dos subconjuntos
        scanf("%d", &qtd_elementos);
        int array_teste[qtd_elementos];
        for (int j = 0; j < qtd_elementos; j++)
        {
            scanf("%d", &array_teste[j]);
        }
        // descobrindo a maior soma dos subconjuntos
        result = maiorSoma(array_teste, qtd_elementos);
        printf("%d\n", result);
    }
    return 0;
}

// função que retorna a soma do maior subconjunto
int maiorSoma(int array_teste[], int qtd_elementos)
{
    int i, soma = array_teste[0];
    for (i = 1; i < qtd_elementos; i++)
    {
        // verifica se o elemento na posicao é positivo
        // caso o elemento seja positivo, é preciso verificar se a soma até o momento é positiva
        // caso essa soma seja positiva, significa que devo somar com o valor da posição atual do laço
        // caso a soma seja negativa, significa que aquele subconjunto não é o maior, e portanto, devo descartá-lo e pegar o elemento atual do laço (que é positivo)
        if (array_teste[i] > 0)
            if (soma < 0)
                soma = array_teste[i];
            else
                soma = soma + array_teste[i];
        else
        {
            soma = soma + array_teste[i];
        }
    }
    return soma;
}