#include <iostream>
#include <vector>

using namespace std;

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

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

string sortVowelsAndConsonants(string s) {
    vector<char> vowels, consonants;

    for (char c : s) {
        if (isVowel(c)) vowels.push_back(c);
        else consonants.push_back(c);
    }

    quickSort(vowels, 0, vowels.size() - 1);
    quickSort(consonants, 0, consonants.size() - 1);

    string result = "";
    for (char c : vowels) result += c;
    for (char c : consonants) result += c;

    return result;
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    cout << sortVowelsAndConsonants(s);

    return 0;
}
