#include <iostream>
#include <algorithm>

using namespace std;


bool binarySearch(int arr[], int left, int right, int x) { 
    while (left <= right) { 
        int mid = left + (right - left) / 2; 

        if (arr[mid] == x) 
            return true;

        if (arr[mid] < x) 
            left = mid + 1; 
        else
            right = mid - 1; 
    } 

    return false; 
}


int main() {
    int n, target; cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> target;
    cout << (binarySearch(arr, 0, n - 1, target) ? "Yes" : "No");

    return 0;
}
