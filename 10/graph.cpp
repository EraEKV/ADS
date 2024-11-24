#include <iostream>
#include <vector>

using namespace std;


// Adjacency list
void addEdge(vector<vector<int>>& adj, int i, int j) {
    adj[i].push_back(j);
    adj[j].push_back(i);
}

void displayAdjList(const vector<vector<int>>& adj) {
    for (int i = 0; i < adj.size(); i++) {
        cout << i << ": ";
        for (int j : adj[i]) {
            cout << j << " ";
        }
        cout << endl; 
    }
}

int main() {
    int V = 4;
    vector<vector<int>> adj(V); 

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);

    cout << "Adjacency List Representation:" << endl;
    displayAdjList(adj);

    return 0;
}


// Adjacency matrix 
// void addEdge(vector<vector<int>> &mat, int i, int j) {
//     mat[i][j] = 1;
//     mat[j][i] = 1;
// }

// void displayMatrix(vector<vector<int>> &mat) {
//     int V = mat.size();
//     for (int i = 0; i < V; i++)
//     {
//         for (int j = 0; j < V; j++)
//             cout << mat[i][j] << " ";
//         cout << endl;
//     }
// }

// int main() {
//     int V = 4;
//     vector<vector<int>> mat(V, vector<int>(V, 0));

//     addEdge(mat, 0, 1);
//     addEdge(mat, 0, 2);
//     addEdge(mat, 1, 2);
//     addEdge(mat, 2, 3);

//     cout << "Adjacency Matrix Representation" << endl;
//     displayMatrix(mat);

//     return 0;
// }