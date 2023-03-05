#include <stdio.h>
#include <string.h>
#include <ctype.h>

// procedimento que converte uma string para maiusculo
void upper_case(char s1[], char s2[])
{
    int i = 0;
    while (s1[i] != '\0')
    {
        s2[i] = toupper(s1[i]);
        i++;
    }
    s2[i] = '\0'; // caracteer que indica o fim da string
}

int compar(char s1[], char s2[], int tam)
{
    int i = 0, qtd = 0;

    while (i < tam)
    {
        if (s1[i] == s2[i])
            qtd++;
        i++;
    }
    return qtd;
}

int main()
{
    // quantidade de caracteres a serem comparados
    int qtd_questoes;
    scanf("%d", &qtd_questoes);
    // sequencia de caracteres corretos
    char gabarito[qtd_questoes + 1];
    gabarito[qtd_questoes] = '\0';
    // sequencia de caracteres marcados pelo vestibulando
    char gabarito_candidato[qtd_questoes + 1];
    gabarito_candidato[qtd_questoes] = '\0';

    scanf("%s", gabarito);
    upper_case(gabarito, gabarito); // converte o caractere para maiusculo
    scanf("%s", gabarito_candidato);
    upper_case(gabarito_candidato, gabarito_candidato); // converte o caractere para maiusculo

    int result = compar(gabarito, gabarito_candidato, qtd_questoes);

    printf("%d\n", result);
    return 0;
}