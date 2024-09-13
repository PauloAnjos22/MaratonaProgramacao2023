#include <iostream>
#include <vector>
using namespace std;

int marcado[1005], numAlunos, numRelacoes, numTimes = 0;
vector<int> relacoes[5005];

void agrupaTime(int aluno) {
    if (!marcado[aluno]) {
        marcado[aluno] = 1;

        for (int amigo : relacoes[aluno]) {
            agrupaTime(amigo);
        }
    }
}

int main() {
    cin >> numAlunos >> numRelacoes;

    // Inicializa o vetor de alunos como não visitados
    fill(marcado, marcado + 1005, 0);

    // Leitura das relações de amizade
    for (int i = 0; i < numRelacoes; i++) {
        int aluno1, aluno2;
        cin >> aluno1 >> aluno2;

        relacoes[aluno1].push_back(aluno2);
        relacoes[aluno2].push_back(aluno1);
    }

    // Contagem dos grupos de amizade
    for (int i = 1; i <= numAlunos; i++) {
        if (!marcado[i]) {
            agrupaTime(i);
            numTimes++;
        }
    }

    cout << numTimes << endl;

    return 0;
}
