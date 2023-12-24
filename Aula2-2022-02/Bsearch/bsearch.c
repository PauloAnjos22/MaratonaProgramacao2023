#include <stdio.h>
#include <string.h>

// funcao para buscar a posicao do elemento da consulta
int busca_binaria(int array_elementos[], int inicio, int fim, int elemento);

int main()
{
    int qtd_elementos, qtd_consultas;
    scanf("%d%d", &qtd_elementos, &qtd_consultas);
    // array com a sequencia
    int array_elementos[qtd_elementos], consulta;
    // recebendo a sequência
    for (int i = 0; i < qtd_elementos; i++)
    {
        scanf("%d", &array_elementos[i]);
    }
    // realizando as consultas
    for (int j = 0; j < qtd_consultas; j++)
    {
        scanf("%d", &consulta);
        // fazendo a busca binaria da consulta no array de elementos
        int result = busca_binaria(array_elementos, 0, qtd_elementos - 1, consulta);
        printf("%d\n", result);
    }
    return 0;
}

int busca_binaria(int array_elementos[], int inicio, int fim, int elemento)
{
    if (fim >= inicio)
    {
        // posição central do array
        int meio = inicio + (fim - inicio) / 2;

        // verifica se a posição central do array é o elemento a ser buscado
        // caso seja, vai verificando se é a menor posição que este elemento aparece
        if (array_elementos[meio] == elemento)
        {
            int aux = meio;
            while (array_elementos[aux] == elemento)
            {
                aux = aux - 1;
                if (array_elementos[aux] == elemento)
                    meio = aux;
            }
            return meio;
        }

        // elemento está na primeira metade
        if (array_elementos[meio] > elemento)
        {
            return busca_binaria(array_elementos, inicio, meio - 1, elemento);
        }
        // elemento está na segunda metade
        return busca_binaria(array_elementos, meio + 1, fim, elemento);
    }
    // não encontrado
    return -1;
}