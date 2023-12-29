#include <iostream>
#include <sstream>
#include <map>

class Candidato
{
public:
    int id;
    int votos;
    // Função para incrementar votos
    void incrementarVotos()
    {
        votos++;
    }
};

void imprimirResultado(std::map<int, Candidato> candidatos);

int main()
{
    int N, X;
    std::cin >> N;
    std::map<int, Candidato> candidatos; // Associamdp cada objeto candidato com um ID

    for (int i = 0; i < N; i++)
    {
        std::cin >> X;
        // Verificar se o candidato com o ID X já existe no mapa
        auto it = candidatos.find(X); // Se o find nao achar ele retorna o end do map
        if (it != candidatos.end())
        {
            // Candidato já existe, incrementar votos
            it->second.incrementarVotos();
        }
        else
        {
            // Candidato não existe, criar novo candidato
            Candidato c;
            c.id = X;
            c.votos = 1;
            candidatos.insert(std::pair<int, Candidato>(X, c));
        }
    }
    imprimirResultado(candidatos);
    return 0;
}

void imprimirResultado(std::map<int, Candidato> candidatos)
{
    int maxVotos = 0; // Guardara a quantidade maxima de vots
    int vencedor;     // Guardara o id do vencedor
    // Percorrer o map de candidatos
    for (auto it = candidatos.begin(); it != candidatos.end(); it++)
    {
        if (it->second.votos > maxVotos)
        {
            maxVotos = it->second.votos; // Atualiza o valor maximo de votos
            vencedor = it->first;        // Atualiza o vencedor
        }
    }
    std::cout << vencedor << std::endl;
}
