#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canRoadblock(const long int* ghouls, int n, long int mid, int k) {
    int cnt = 1;
    long int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += ghouls[i];
        if (sum > mid) {
            cnt++;
            if (cnt > k) {
                return false;
            }
            sum = ghouls[i];
        }
    }

    return true;
}

long int binarySearch(long int* ghouls, int n, int k, long int sum) {
    long int left = *max_element(ghouls, ghouls + n);
    long int right = sum;
    long int res = sum;

    while (left <= right) {
        long int mid = (left + right) / 2;

        if (canRoadblock(ghouls, n, mid, k)) {
            res = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return res;
}

int main() {
    int n, k;
    cin >> n >> k;

    long int sum = 0;
    long int ghouls[n];

    for (int i = 0; i < n; i++) {
        cin >> ghouls[i];
        sum += ghouls[i];
    }

    long int result = binarySearch(ghouls, n, k, sum);

    cout << result << endl;

    return 0;
}
