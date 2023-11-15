#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <limits.h>
using namespace std;

class Graph {
public:

    int nodes, edges;
    bool undirected;
    vector<vector<int>> adjMatrix;
    unordered_map<int, list<int>> adjList;
    unordered_map<int, list<pair<int, int>>> adjListWeight;

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

        int u, v;
        cout << "If the graph undirected then enter 1 else 0 for directed: ";
        cin >> undirected;
        cout << "Enter the number of edges: ";
        cin >> edges;

        for(int i = 0; i < edges; i++) {
            cout << "Enter edge: ";
            cin >> u >> v;
            addEdgeToAdjList(u, v);
        }
    }

    void addEdgeToAdjList(int u, int v) {
        adjList[u].push_back(v);
        if(undirected)
        adjList[v].push_back(u);
    }

    void createAdjacencyListWithWeight() {

        int u, v, w;
        cout << "If the graph undirected then enter 1 else 0 for directed: ";
        cin >> undirected;
        cout << "Enter the number of edges: ";
        cin >> edges;

        for(int i = 0; i < edges; i++) {
            cout << "Enter edge with weight: ";
            cin >> u >> v >> w;
            addEdgeWithWeightToAdjList(u, v, w);
        }
    }

    void addEdgeWithWeightToAdjList(int u, int v, int w) {
        adjListWeight[u].push_back(make_pair(v, w));
        if(undirected)
            adjListWeight[v].push_back(make_pair(u, w));
    }

    void printAdjacencyMatrix() {
        for(int i = 0; i < nodes; i++) {
            for(int j = 0; j < nodes; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void printAdjacencyListWithWeight() {
        for(auto node: adjListWeight) {
            cout << node.first << " -> ";
            for(auto neighbor: node.second) {
                cout << "{ " << neighbor.first << ", " << neighbor.second << " }, ";
            }
            cout << endl;
        }
    }
};

int main() {

    Graph g;

    g.createAdjacencyListWithWeight();
    g.printAdjacencyListWithWeight();

    return 0;
}
