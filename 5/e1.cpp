#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    priority_queue<int, vector<int>, greater<int>> minHeap;
    long long totalSum = 0;

    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;

        if (command == "insert") {
            int cookieCount;
            cin >> cookieCount;

            if (minHeap.size() < k) {
                minHeap.push(cookieCount);
                totalSum += cookieCount;
            } else if (minHeap.size() == k && cookieCount > minHeap.top()) {
                totalSum += cookieCount - minHeap.top();
                minHeap.pop();
                minHeap.push(cookieCount);
            }
        } else if (command == "print") {
            cout << totalSum << endl;
        }
    }

    return 0;
}