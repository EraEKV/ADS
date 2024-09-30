#include <iostream>
#include <algorithm>

using namespace std;

bool canCover(int* arr, int n, int size, int k) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] <= size) {
            count++;
        }
    }
    return count >= k;
}

int binarySearch(int* arr, int n, int left, int right, int k) {
    int result = right;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (canCover(arr, n, mid, k)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return result;
}

int main() {
    int n, k; cin >> n >> k;

    int arr[n];
    int maxCoord = -1;

    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        arr[i] = max({x1, x2, y1, y2});
        maxCoord = max(maxCoord, arr[i]);
    }

    sort(arr, arr + n);

    int result = binarySearch(arr, n, 1, maxCoord, k);
    
    cout << result << endl;

    return 0;
}
