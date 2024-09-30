#include <iostream>

using namespace std;

int binarySearch(int* array, int n, int k) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (k == array[mid]) {
            return mid + 1;
        }
        if (array[mid] < k) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left + 1;
}

int main() {
    int n, m, error; cin >> n >> m;

    int array[n];
    int endings[n];

    for (int i = 0; i < n; i++) {
        cin >> array[i];
        if (i == 0) {
            endings[i] = array[i];
        } else {
            endings[i] = array[i] + endings[i - 1];
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> error;
        cout << binarySearch(endings, n, error) << endl;
    }

    return 0;
}
