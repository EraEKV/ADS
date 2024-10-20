#include <iostream>
#include <vector>

using namespace std;

int partition(vector<pair<int, string>>& arr, int low, int high) {
    int pivot = arr[high].first;
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].first < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<pair<int, string>>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void sortInit(vector<pair<int, string>>& dates) {
    quickSort(dates, 0, dates.size() - 1);
}

int main() {
    int n; cin >> n;
    vector<pair<int, string>> dates(n);
    string date;

    for(int i = 0; i < n; ++i) {
        cin >> date;

        int value = 0;
        int day = stoi(date.substr(0, 2));
        int month = stoi(date.substr(3, 2));
        int year = stoi(date.substr(6, 4));

        value += day;
        value += month * 100;
        value += year * 10000;
        
        dates.push_back(make_pair(value, date));
    }

    sortInit(dates);

    for(const auto& d: dates) {
        if(d.first != 0) cout << d.second << endl;
    }

    return 0;
}
