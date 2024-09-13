#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
int toca[1005][1005]; // Matriz representando as salas
bool visitado[1005][1005]; // Marca se a sala foi visitada
pair<int, int> inicio, saida; // Coordenadas da sala de início e de saída
int dx[] = {-1, 1, 0, 0}; // Movimentos possíveis (cima, baixo, esquerda, direita)
int dy[] = {0, 0, -1, 1};

int bfs() {
    queue<pair<int, int>> fila;
    fila.push(saida); // Começamos da saída
    visitado[saida.first][saida.second] = true;

    int qtdSalas = 0;

    while (!fila.empty()) {
        int tam = fila.size();
        for (int i = 0; i < tam; i++) {
            pair<int, int> atual = fila.front();
            fila.pop();

            if (atual == inicio) {
                return qtdSalas; // Retorna a quantidade de salas percorridas
            }

            // Tenta se mover para as 4 direções
            for (int d = 0; d < 4; d++) {
                int novoX = atual.first + dx[d];
                int novoY = atual.second + dy[d];

                if (novoX >= 0 && novoX < n && novoY >= 0 && novoY < m && !visitado[novoX][novoY] && toca[novoX][novoY] != 0) {
                    visitado[novoX][novoY] = true;
                    fila.push({novoX, novoY});
                }
            }
        }
        qtdSalas++; // Aumenta o contador de salas
    }

    return -1; // Caso não encontre um caminho
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> toca[i][j];

            if (toca[i][j] == 2) {
                inicio = {i, j}; // Ponto inicial
            }
            else if (toca[i][j] == 3) {
                saida = {i, j}; // Ponto de saída
            }
        }
    }

    int resultado = bfs();

    if (resultado != -1) {
        cout << resultado << endl;
    } else {
        cout << "Não há caminho disponível." << endl;
    }

    return 0;
}
