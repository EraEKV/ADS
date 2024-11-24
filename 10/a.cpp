#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int mario(int m, int n, vector<vector<int>>& grid) {
    queue<pair<int, int>> q;
    int mushrooms = 0;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 2) {
                q.push({i, j});
            } else if (grid[i][j] == 1) {
                ++mushrooms;
            }
        }
    }

    if (mushrooms == 0) return 0;

    int res = 0;

    while (!q.empty()) {
        int sz = q.size();
        bool killed = false;

        for (int i = 0; i < sz; ++i) {
            pair<int, int> cur = q.front();
            int x = cur.first;
            int y = cur.second;
            q.pop();

            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    q.push({nx, ny});
                    killed = true;
                    --mushrooms;
                }
            }
        }

        if (killed) ++res;
    }

    return mushrooms == 0 ? res : -1;
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }

    int result = mario(m, n, grid);
    cout << result;

    return 0;
}
