#include <iostream>
#include <vector>
using namespace std;

int marcados[105];
vector<int> adj[105];

void buscaProfundidade(int no) {
    if (!marcados[no]) {
        marcados[no] = 1;

        for (int vizinho : adj[no]) {
            buscaProfundidade(vizinho);
        }
    }
}

int main() {
    int numVertices, numArestas;
    bool desconexo = false;

    // Inicializar o vetor de visitados
    fill(marcados, marcados + 105, 0);

    cin >> numVertices >> numArestas;

    // Leitura das arestas e construção do grafo
    for (int i = 0; i < numArestas; i++) {
        int vertice1, vertice2;
        cin >> vertice1 >> vertice2;

        adj[vertice1].push_back(vertice2);
        adj[vertice2].push_back(vertice1);
    }

    // Se o número de arestas não for igual ao de vértices, já podemos considerar o grafo desconexo
    if (numVertices == numArestas) {
        buscaProfundidade(1);

        for (int i = 1; i <= numVertices; i++) {
            if (!marcados[i]) {
                desconexo = true;
                break;
            }
        }
    } else {
        desconexo = true;
    }

    // Resultado baseado na conectividade do grafo
    if (desconexo) {
        cout << "NO" << endl;
    } else {
        cout << "FHTAGN!" << endl;
    }

    return 0;
}
