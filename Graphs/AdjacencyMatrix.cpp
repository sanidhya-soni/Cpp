#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int main() {

    int n;
    cout << "Enter Number of Nodes: ";
    cin >> n;

    int e;
    cout << "Enter Number of Edges: ";
    cin >> e;

    vector<vector<int>> matrix(n, vector<int>(n,0));

    for(int i = 0; i < e; i++) {
        int u, v;
        cout << "Enter Edge: ";
        cin >> u >> v;
        matrix[u-1][v-1] = 1;
    }
    // cout << "Here" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
