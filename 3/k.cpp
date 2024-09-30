#include <iostream>
#include <climits>

using namespace std;

int subArraysNum(int arr[], int n, int k) {
    int left = 0;
    int sum = 0;
    int length = INT_MAX;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        while(sum >= k) {
            length = min(length, i - left + 1);
            sum -= arr[left];
            left++;
        }
    }

    return length;
    
}

int main() {
    int n, k; cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    cout << subArraysNum(a, n, k);

    return 0;
}