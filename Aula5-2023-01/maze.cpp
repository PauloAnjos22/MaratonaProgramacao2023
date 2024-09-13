#include <iostream>
#include <vector>
#include <cstring> // Para memset

using namespace std;

bool visitado[501][501];
int celulasLivres = 0;
int celulasVisitadas = 0;
int celulasNaoMarcadas;
char mapa[501][501];
int movX[] = {-1, 0, 0, 1}; // Movimentos nas direções: cima, esquerda, direita, baixo
int movY[] = { 0,-1, 1, 0};

void explorarLabirinto(int x, int y, int n, int m) {
    if (x >= 0 && x < n && y >= 0 && y < m && mapa[x][y] != '#' && !visitado[x][y]) {
        visitado[x][y] = true;

        if (celulasNaoMarcadas > 0)
            celulasNaoMarcadas--;
        else
            mapa[x][y] = 'X'; // Marca a célula como visitada demais
        
        for (int i = 0; i < 4; i++) {
            explorarLabirinto(x + movX[i], y + movY[i], n, m);
        }
    }
}

int main() {
    int linhas, colunas;

    cin >> linhas >> colunas >> celulasNaoMarcadas;
    memset(visitado, false, sizeof(visitado));

    // Leitura do mapa e contagem das células livres
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            cin >> mapa[i][j];
            if (mapa[i][j] == '.') 
                celulasLivres++;
        }
    }

    // Calcula o número de células a serem preenchidas com 'X'
    celulasNaoMarcadas = celulasLivres - celulasNaoMarcadas;

    // Inicia a exploração a partir das células livres
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (!visitado[i][j] && mapa[i][j] == '.') {
                explorarLabirinto(i, j, linhas, colunas);
            }
        }
    }

    // Exibe o mapa final
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            cout << mapa[i][j];
        }
        cout << endl;
    }

    return 0;
}
