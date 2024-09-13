#include <bits/stdc++.h>
using namespace std;

vector<list<int>> adjacencyList(25);
vector<int> visited(25, 0);
int currentLabel = 1;
int numVertices, numEdges, pathCounter = 0;

void depthFirstSearch(int currentNode, int indentation) {
    visited[currentNode] = currentLabel;
    pathCounter++;

    for (const auto& neighbor : adjacencyList[currentNode]) {
        if (visited[neighbor] != currentLabel) {
            visited[neighbor] = currentLabel;
            
            cout << string(indentation, ' ') << currentNode << '-' << neighbor << " pathR(G," << neighbor << ")" << endl;
            
            depthFirstSearch(neighbor, indentation + 2);
        } else {
            cout << string(indentation, ' ') << currentNode << '-' << neighbor << endl;
        }
    }
}

int main() {
    int testCases, startNode, endNode;

    cin >> testCases;

    while (testCases--) {
        if (testCases != 0)
            cout << endl;
        
        cin >> numVertices >> numEdges;
        
        pathCounter = 0;
        
        for (int i = 0; i < numVertices; i++)
            adjacencyList[i].clear();
        
        for (int i = 0; i < numEdges; i++) {
            cin >> startNode >> endNode;
            adjacencyList[startNode].push_back(endNode);
        }
        
        for (int i = 0; i < numVertices; i++)
            adjacencyList[i].sort();
        
        cout << "Caso " << (testCases + 1) << ":" << endl;
        
        for (int i = 0; i < numVertices; i++) {
            if (visited[i] != currentLabel) {
                depthFirstSearch(i, 2);
                
                if (!adjacencyList[i].empty() && pathCounter != numVertices)
                    cout << endl;
            }
        }
        
        currentLabel++;
    }

    return 0;
}
