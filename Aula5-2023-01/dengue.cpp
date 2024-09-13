#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int numVilas, v1, v2, menorDist, distAtual, distancia[105], teste = 0, vilaIdeal = 0; 
vector<int> conexoes[105];

int calcularDistancia(int vila) {
    if (distancia[vila] == -1) {
        distancia[vila] = 0;

        for (int vizinho : conexoes[vila]) {
            if (distancia[vizinho] == -1) {
                distancia[vila] = max(calcularDistancia(vizinho) + 1, distancia[vila]);
            }
        }
    }
    return distancia[vila];
}

int main() {
    while (true) {    
        cin >> numVilas;

        if (numVilas == 0) break;

        teste++;
        
        // Leitura das conexões entre vilas
        for (int i = 0; i < numVilas - 1; i++) {
            cin >> v1 >> v2;

            conexoes[v1].push_back(v2);
            conexoes[v2].push_back(v1);
        }

        // Calculando a vila com menor distância máxima
        for (int i = 1; i <= numVilas; i++) {
            fill(distancia, distancia + 105, -1);
            
            if (i == 1) {
                menorDist = calcularDistancia(i);
                distAtual = menorDist;
                vilaIdeal = i;
            } else {
                distAtual = calcularDistancia(i);

                if (distAtual < menorDist) {
                    menorDist = distAtual;
                    vilaIdeal = i;
                }
            }
        }

        cout << "Teste " << teste << endl;
        cout << vilaIdeal << "\n\n";

        // Limpar conexões para o próximo caso de teste
        for (int i = 1; i <= numVilas; i++) {
            conexoes[i].clear();
        }
    }

    return 0;
}
