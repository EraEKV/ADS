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

string sortLetters(string s) {
    vector <char> letters;

    for (char c : s) {
        letters.push_back(c);
    }
    quickSort(letters, 0, letters.size() - 1);

    string result = "";
    for (char c : letters) result += c;

    return result;
}

int main() {
    string s; cin >> s;

    cout << sortLetters(s);

    return 0;
}
