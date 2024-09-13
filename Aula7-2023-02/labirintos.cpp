#include <iostream>
#include <vector>

using namespace std;

int main() {
    int numTests, numVertices, numEdges, start, end, totalMovements;

    cin >> numTests;

    while (numTests--) {
        cin >> numVertices >> numVertices >> numEdges;
        totalMovements = 0;

        vector<vector<bool>> maze(numVertices, vector<bool>(numVertices, false));

        for (int i = 0; i < numEdges; i++) {
            cin >> start >> end;
            maze[start][end] = true;
            maze[end][start] = true;
        }

        for (const auto& row : maze) {
            for (bool cell : row) {
                totalMovements += cell;
            }
        }

        cout << totalMovements << endl;
    }
    
    return 0;
}
