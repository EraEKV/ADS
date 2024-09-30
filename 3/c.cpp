#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int binarySearch(vector <int> v, int right, int r, int l) {
    int sum = 0, left = 0;

    while(left <= right) {
        int mid = left + (right - left) / 2;

        if(v[mid] >= r && v[mid] <= l) {
            sum++;
        }
    }

    return sum;
}


int main() {
    int n, m, r, l, sum;
    cin >> n;
    
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    return 0;
}