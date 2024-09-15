#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    string students;
    cin >> n >> students;

    queue<int> s, k;

    for (int i = 0; i < n; i++) {
        students[i] == 'S' ? s.push(i) : k.push(i);
    }

    while (!s.empty() && !k.empty()) {
        int i = s.front();
        int j = k.front();
        s.pop();
        k.pop();

        if (i < j) {
            s.push(i + n);
        } else {
            k.push(j + n);
        }
    }

    cout << (s.empty() ? "KATSURAGI" : "SAKAYANAGI");

    return 0;
}