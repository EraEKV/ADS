#include <iostream>
#include <vector>

using namespace std;

void merge(vector <int> & arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector <int> leftVec(n1), rightVec(n2);

    for(int i = 0; i < n1; i++) {
        leftVec[i] = arr[left + i];
    }
    for(int i = 0; i < n2; i++) {
        rightVec[i] = arr[mid + i + 1];
    }

    int i = 0, j = 0;
    int k = left;

    while(i < n1 && j < n2) {
        if(leftVec[i] <= rightVec[j]) {
            arr[k] = leftVec[i];
            i++;
        } else {
            arr[k] = rightVec[j];
            j++;
        }
        k++;
    }

    while(i < n1) {
        arr[k] = leftVec[i];
        k++;
        i++;
    }

    while(j < n2) {
        arr[k] = rightVec[j];
        k++;
        j++;
    }
}

void mergeSort(vector <int> & arr, int left, int right) {
    if(left >= right) return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}

void duplicates(vector<int>& a, vector<int>& b) {
    int i = 0, j = 0;

    while (i < a.size() && j < b.size()) {
        if (a[i] == b[j]) {
            cout << a[i] << " ";
            i++;
            j++;
        } else if (a[i] < b[j]) {
            i++;
        } else {
            j++;
        }
    }
    cout << endl;
}


int main() {
    vector <int> a, b;
    int n, m, temp; cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        cin >> temp;
        a.push_back(temp);
    }
    for(int i = 0; i < m; i++) {
        cin >> temp;
        b.push_back(temp);
    }

    mergeSort(a, 0, n - 1);
    mergeSort(b, 0, m - 1);

    duplicates(a, b);

    return 0;
}