#include <iostream>
#include <vector>

using namespace std;

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

void heapify(vector<char>& arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<char>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

string sortVowelsAndConsonants(string s) {
    vector<char> vowels, consonants;

    for (char c : s) {
        if (isVowel(c)) vowels.push_back(c);
        else consonants.push_back(c);
    }

    heapSort(vowels);
    heapSort(consonants);

    string result = "";
    for (char c : vowels) result += c;
    for (char c : consonants) result += c;

    return result;
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    cout << sortVowelsAndConsonants(s) << endl;

    return 0;
}
