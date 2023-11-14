#include <iostream>
#include <vector>
#include <limits.h>
#include <unordered_map>
#include <list>
using namespace std;

class Graph {
public:

    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool undirected) {
        adj[u].push_back(v);
        if(undirected) {
            adj[v].push_back(u);
        }
    }

    void printAdjList() {
        for(auto node: adj) {
            cout << node.first << " -> ";
            for(auto neighbor: node.second) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }

};

int main() {

    Graph g;

    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(0, 2, 1);
    cout << endl;
    g.printAdjList();

    return 0;
}
