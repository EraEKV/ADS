#include <iostream>
#include <vector>

using namespace std;

int partition(vector<char>& arr, int low, int high) {
    char pivot = arr[high];
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

void quickSort(vector<char>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

char findBalanced(vector <char> & letters, int n, char c) {
    quickSort(letters, 0, n - 1);

    for(int i = 0; i < n; i++) {
        if(c < letters[i]) return letters[i];
    }

    return letters[0];
}

int main() {
    int n; cin >> n;
    vector <char> letters(n);
    char c;

    for(int i = 0; i < n; i++) {
        cin >> letters[i];
    }
    cin >> c;

    cout << findBalanced(letters, n, c);

    return 0;
}
