#include <iostream>
#include <algorithm>

using namespace std;

bool canDeliver(int* array, int n, int f, int max) {
    int flights = 0;
    for (int i = 0; i < n; i++) {
        flights += (array[i] + max - 1) / max;
    }
    return flights <= f;
}

int binarySearch(int* array, int n, int f) {
    int left = 1;
    int right = *max_element(array, array + n);
    int min = left;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (canDeliver(array, n, f, mid)) {
            right = mid - 1;
            min = mid;
        } else {
            left = mid + 1;
        }
    }

    return min;
}

int main() {
    int n, f; cin >> n >> f;
    int array[n];

    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    cout << binarySearch(array, n, f);

    return 0;
}