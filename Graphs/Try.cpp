#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <limits.h>
using namespace std;

class Graph {
public:

    int nodes, edges;
    vector<vector<int>> adjMatrix;
    unordered_map<int, list<int>> adjList;
    unordered_map<int, list<int>> adjListWeight;

    void createAdjaccencyMatrix() {
        cout << "Enter Nuber of Nodes: ";
        cin >> nodes;
        adjMatrix.assign(nodes, vector<int>(nodes, 0));

        cout << "Enter Number of Edges: ";
        cin >> edges;

        for(int i = 0; i < edges; i++) {
            int u, v;
            cout << "Enter Edge: ";
            cin >> u >> v;
            adjMatrix[u][v] = 1;
        }
    }

    void createAdjaccencyMatrixWithWeight() {
        cout << "Enter Nuber of Nodes: ";
        cin >> nodes;
        adjMatrix.assign(nodes, vector<int>(nodes, 0));

        cout << "Enter Number of Edges: ";
        cin >> edges;

        for(int i = 0; i < edges; i++) {
            int u, v, w;
            cout << "Enter Edge with Weight: ";
            cin >> u >> v;
            adjMatrix[u][v] = w;
        }
    }

    void createAdjacencyList() {

    }

    void printAdjacencyMatrix() {
        for(int i = 0; i < nodes; i++) {
            for(int j = 0; j < nodes; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {

    Graph g;

    g.createAdjaccencyMatrix();
    g.printAdjacencyMatrix();

    return 0;
}
