#include <iostream>
#include <algorithm>

using namespace std;

bool possible(int bags[], int n, int h, int k) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (bags[i] + k - 1) / k;
    }
    return sum <= h;
}

int binarySearch(int bags[], int n, int h) {
    int left = 1;
    int right = *max_element(bags, bags + n);
    int k = right;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (possible(bags, n, h, mid)) {
            k = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return k;
}

int main() {
    int n, h;
    cin >> n >> h;
    int bags[n];

    for (int i = 0; i < n; i++) {
        cin >> bags[i];
    }

    cout << binarySearch(bags, n, h);

    return 0;
}
