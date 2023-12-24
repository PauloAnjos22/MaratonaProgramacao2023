#include <iostream>
#include <vector>

using namespace std;

class UnionFind
{
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    void unionSets(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY)
            return;

        // Union by rank
        if (rank[rootX] < rank[rootY])
        {
            parent[rootX] = rootY;
        }
        else if (rank[rootX] > rank[rootY])
        {
            parent[rootY] = rootX;
        }
        else
        {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
};

int findMaxTeams(int N, const vector<pair<int, int>> &friendships)
{
    UnionFind uf(N + 1);

    // Construir as relações de amizade
    for (const auto &friendship : friendships)
    {
        int i = friendship.first;
        int j = friendship.second;
        uf.unionSets(i, j);
    }

    int maxTeams = 0;

    // Contar o número de conjuntos disjuntos (times)
    for (int i = 1; i <= N; ++i)
    {
        if (uf.find(i) == i)
        {
            ++maxTeams;
        }
    }

    return maxTeams;
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> friendships(M);
    for (int i = 0; i < M; ++i)
    {
        int I, J;
        cin >> I >> J;
        friendships[i] = make_pair(I, J);
    }

    int maxTeams = findMaxTeams(N, friendships);

    cout << maxTeams << endl;

    return 0;
}
