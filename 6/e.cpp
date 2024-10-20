#include <iostream>
#include <vector>

using namespace std;


int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] > pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    swap(arr[i + 1], arr[high]);  
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
  
    if (low < high) {
      
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void sortInit(vector<vector<int>> & sorted, int m, int n) {
    for(int i = 0; i < m; i++) {
        quickSort(sorted[i], 0, n - 1);
    }
}

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    vector<vector<int>> sorted(m, vector<int>(n));
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            sorted[j][i] = arr[i][j];
        }
    }

    sortInit(sorted, m, n);

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cout << sorted[j][i] << " ";
        }
        cout << endl;
    }

    return 0;
}