#include <iostream>
#include <vector>
#include <climits>

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

vector<pair<int, int>> findClosestPairs(vector<int>& points) {
    quickSort(points, 0, points.size() - 1);
    int minDiff = INT_MAX;
    vector<pair<int, int>> result;
    
    for (int i = 1; i < points.size(); i++) {
        int diff = points[i] - points[i - 1];
        if (diff < minDiff) {
            minDiff = diff;
            result.clear();
            result.push_back({points[i - 1], points[i]});
        } else if (diff == minDiff) {
            result.push_back({points[i - 1], points[i]});
        }
    }
    return result;
}

int main() {
    int n; cin >> n;
    vector<int> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i];
    }
    
    vector<pair<int, int>> closestPairs = findClosestPairs(points);
    
    for (const auto& p : closestPairs) {
        cout << p.first << " " << p.second << " ";
    }
    cout << endl;
    
    return 0;
}