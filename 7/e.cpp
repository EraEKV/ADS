#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

bool compareRows(const vector<int>& row1, const vector<int>& row2) {
    int sum1 = accumulate(row1.begin(), row1.end(), 0);
    int sum2 = accumulate(row2.begin(), row2.end(), 0);
    
    if (sum1 != sum2) return sum1 > sum2;
    
    return row1 < row2;
}

void merge(vector<vector<int>>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<vector<int>> leftVec(n1), rightVec(n2);

    for (int i = 0; i < n1; i++) {
        leftVec[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        rightVec[i] = arr[mid + i + 1];
    }

    int i = 0, j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (compareRows(leftVec[i], rightVec[j])) {
            arr[k] = leftVec[i];
            i++;
        } else {
            arr[k] = rightVec[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftVec[i];
        k++;
        i++;
    }

    while (j < n2) {
        arr[k] = rightVec[j];
        k++;
        j++;
    }
}

void mergeSort(vector<vector<int>>& arr, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> rows(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> rows[i][j];
        }
    }

    mergeSort(rows, 0, n - 1);

    for (const auto& row : rows) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
