#include <stdio.h>
#include <string.h>
#include <ctype.h>

// percorre um array (arr_int) com base nos indice passados em s1 e s2
int compar(int s1, int s2, int arr_int[]);

int main()
{
    // quantidade de numeros inteiros na lista
    int N;
    scanf("%d", &N);
    // array com os numeros que cabem dentro de um inteiro
    int arr_int[N];
    for (int i = 0; i < N; i++)
        scanf("%d", &arr_int[i]);
    // quantidade de consultas
    int Q;
    scanf("%d", &Q);
    // arrays para guardarem os indices da consulta
    int arr_aux1[Q];
    int arr_aux2[Q];
    // recebendo as consultas
    for (int i = 0; i < Q; i++)
    {
        scanf("%d %d", &arr_aux1[i], &arr_aux2[i]);
        // funcao que retorna a soma da consulta
        int result = compar(arr_aux1[i], arr_aux2[i], arr_int);
        printf("%d\n", result);
    }
    return 0;
}
int compar(int s1, int s2, int arr_int[])
{
    int soma = 0, i = s1;
    while (s1 <= s2)
    {
        soma = soma + arr_int[i];
        s1++;
        i++;
    }
    return soma; // retorna a soma do intervalo
}