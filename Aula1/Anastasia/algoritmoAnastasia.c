#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    // quantidade de seixos e quantidade que podera colocar em cada bolso
    int tipos_seixos, nro_seixos;
    scanf("%d %d", &tipos_seixos, &nro_seixos);
    // array para armazenar o numeros de pedras de cada tipo
    int array_pedras[tipos_seixos + 1];
    for (int i = 0; i < tipos_seixos; i++)
        scanf("%d", &array_pedras[i]);
    // indicando na ultima posicao do array quantos elementos existem (sera util posteriormente)
    array_pedras[tipos_seixos] = tipos_seixos;
    // variaveis auxiliares para orientacao
    int qtd_dias = 0, bolso_esq = 0, bolso_dir = tipos_seixos - 1;
    // laco para adicionar as pedras nos bolsos e contar os dias
    while (array_pedras[tipos_seixos] != 0)
    {
        // verifica se eh possivel guardar pedras no bolso esquerdo
        if (array_pedras[bolso_esq] > 0)
        {
            array_pedras[bolso_esq] = array_pedras[bolso_esq] - nro_seixos;
            // acabou as pedras daquele tipo
            if (array_pedras[bolso_esq] <= 0)
            {
                bolso_esq++;
                array_pedras[tipos_seixos]--;
            }
        }
        // verifica se eh possivel guardar pedras no bolso direito
        if (array_pedras[bolso_dir] > 0)
        {
            array_pedras[bolso_dir] = array_pedras[bolso_dir] - nro_seixos;
            // acabou as pedras daquele tipo
            if (array_pedras[bolso_dir] <= 0)
            {
                bolso_dir--;
                array_pedras[tipos_seixos]--;
            }
        }
        qtd_dias++;
    }
    printf("%d\n", qtd_dias);
    return 0;
}
