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


int main() {
    vector <int> arr = { 12, 11, 13, 5, 6, 7 };
    int n = arr.size();

    cout << "Given vector is \n";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";

    mergeSort(arr, 0, n - 1);

    cout << "\nSorted vector is \n";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}