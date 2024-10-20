#include <iostream>
#include <map>
#include <vector>

using namespace std;

int partition(vector<pair<string, string>>& arr, int low, int high) {
    string pivot = arr[high].first;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j].first < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<pair<string, string>>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n; cin >> n;
    map<string, string> nicknames;

    for (int i = 0; i < n; i++) {
        string oldNick, newNick;
        cin >> oldNick >> newNick;
        if (nicknames.count(oldNick) == 0) {
            nicknames[oldNick] = oldNick;
        }
        nicknames[newNick] = nicknames[oldNick];
        nicknames.erase(oldNick);
    }

    vector<pair<string, string>> result;
    for (const auto& pair : nicknames) {
        result.push_back({pair.second, pair.first});
    }

    quickSort(result, 0, result.size() - 1);

    cout << result.size() << endl;
    for (const auto& pair : result) {
        cout << pair.first << " " << pair.second << endl;
    }

    return 0;
}
