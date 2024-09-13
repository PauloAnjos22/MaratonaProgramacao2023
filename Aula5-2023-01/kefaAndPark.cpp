#include <iostream>
#include <vector>
using namespace std;

int numVertices, limiteGatos, temGatos[100050], verticeA, verticeB, visitado[100050], totalRestaurantes = 0;
vector<int> grafo[100050];

void explorarCaminho(int gatosSeguidos, int verticeAtual) {
    if (!visitado[verticeAtual]) {
        visitado[verticeAtual] = 1;

        if (temGatos[verticeAtual])
            gatosSeguidos++;
        else
            gatosSeguidos = 0;

        if (gatosSeguidos > limiteGatos)
            return;

        for (int vizinho : grafo[verticeAtual])
            explorarCaminho(gatosSeguidos, vizinho);

        if (grafo[verticeAtual].size() == 1 && verticeAtual != 1)
            totalRestaurantes++;
    }
}

int main() {
    cin >> numVertices >> limiteGatos;

    for (int i = 1; i <= numVertices; i++) {
        cin >> temGatos[i];
        visitado[i] = 0;
    }

    for (int i = 1; i < numVertices; i++) {
        cin >> verticeA >> verticeB;

        grafo[verticeA].push_back(verticeB);
        grafo[verticeB].push_back(verticeA);
    }

    explorarCaminho(0, 1);

    cout << totalRestaurantes << endl;

    return 0;
}
