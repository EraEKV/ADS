#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int shortestPath(const vector<vector<int>>& adj, int a, int b) {
    int n = adj.size();
    vector<int> d(n, -1);
    queue<int> q;

    q.push(a);
    d[a] = 0;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int neighbor = 0; neighbor < n; ++neighbor) {
            if(adj[cur][neighbor] == 1 && d[neighbor] == -1) {
                d[neighbor] = d[cur] + 1;
                q.push(neighbor);

                if(neighbor == b) {
                    return d[neighbor];
                }
            }
        }
    }

    return -1;
}

int main() {
    int n; cin >> n;

    vector<vector<int>> adj(n, vector<int>(n));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> adj[i][j];
        }
    }

    int a, b;
    cin >> a >> b;

    a--; 
    b--;

    int res = shortestPath(adj, a, b);
    cout << res;

    return 0;
}