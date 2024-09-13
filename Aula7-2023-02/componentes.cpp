#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> adjList[26];
bool visited[26];
vector<char> component;

void depthFirstSearch(int node, vector<int> graph[]) {
    visited[node] = true;
    component.push_back(node + 'a');  // Adiciona o caractere correspondente ao vetor de componentes

    for (auto neighbor : graph[node]) {
        if (!visited[neighbor])
            depthFirstSearch(neighbor, graph);
    }
}

int main() {
    int numTests, numVertices, numEdges, vertex1, vertex2;
    char startVertex, endVertex;

    cin >> numTests;

    for (int testCase = 1; testCase <= numTests; ++testCase) {
        cin >> numVertices >> numEdges;

        // Inicializa os vetores e variáveis para cada caso de teste
        fill(begin(visited), end(visited), false);
        for (int i = 0; i < 26; ++i) {
            adjList[i].clear();
        }
        component.clear();

        // Leitura das arestas
        for (int edge = 0; edge < numEdges; ++edge) {
            cin >> startVertex >> endVertex;
            vertex1 = startVertex - 'a';
            vertex2 = endVertex - 'a';

            adjList[vertex1].push_back(vertex2);
            adjList[vertex2].push_back(vertex1);
        }

        cout << "Case #" << testCase << ":" << endl;

        int componentCount = 0;
        for (int vertex = 0; vertex < numVertices; ++vertex) {
            if (!visited[vertex]) {
                depthFirstSearch(vertex, adjList);
                sort(component.begin(), component.end());

                for (const auto& ch : component)
                    cout << ch << ',';

                cout << endl;
                componentCount++;
                component.clear();
            }
        }

        cout << componentCount << " connected components\n\n";
    }

    return 0;
}
