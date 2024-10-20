#include <iostream>
#include <vector>

using namespace std;


int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
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

void process(vector<int>& arr1, vector<int>& arr2) {
    for(int i = 0; i < arr1.size(); ++i) {
       for(int j = 0; j < arr2.size(); ++j) {
            if(arr1[i] == arr2[j]) {
                cout << arr1[i] << " ";
                arr1[i] = -1;
                arr2[j] = -2;
                break;
            }
        } 
    }
}

int main() {
    int n, m; cin >> n >> m;
    vector<int> arr1(n);
    vector<int> arr2(m);
    
    for(int i = 0; i < n; ++i) {
        cin >> arr1[i];
    }

    for(int i = 0; i < m; ++i) {
        cin >> arr2[i];
    }

    quickSort(arr1, 0, n - 1);
    quickSort(arr2, 0, m - 1);

    n < m ? process(arr1, arr2) : process(arr2, arr1);

    return 0;
}
