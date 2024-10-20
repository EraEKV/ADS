#include <iostream>
#include <vector>
#include <map>
#include <iomanip>

using namespace std;

map<string, float> grades = {
    {"A+", 4.00},
    {"A", 3.75},
    {"B+", 3.50},
    {"B", 3.00},
    {"C+", 2.50},
    {"C", 2.00},
    {"D+", 1.50},
    {"D", 1.00},
    {"F", 0.0}
};

void heapify(vector<pair<float, string>>& arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && (arr[l].first > arr[largest].first || 
        (arr[l].first == arr[largest].first && arr[l].second < arr[largest].second)))
        largest = l;

    if (r < n && (arr[r].first > arr[largest].first || 
        (arr[r].first == arr[largest].first && arr[r].second < arr[largest].second)))
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<pair<float, string>>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

float evaluateTotalGPA() {
    int m;
    cin >> m;
    float sum1 = 0;
    float sum2 = 0;
    for (int i = 0; i < m; i++) {
        string grade;
        int credits;
        cin >> grade >> credits;
        sum1 += grades[grade] * credits;
        sum2 += credits;
    }
    return (sum2 > 0) ? (sum1 / sum2) : 0.0; // Избегаем деления на ноль
}

int main() {
    int n; 
    cin >> n;
    vector<pair<float, string>> students;

    for (int i = 0; i < n; ++i) {
        string firstname, lastname; 
        cin >> lastname >> firstname;
        float gpa = evaluateTotalGPA();
        students.push_back(make_pair(gpa, lastname + " " + firstname));
    }

    heapSort(students);

    for (const auto& s : students) {
        cout << s.second << " " << fixed << setprecision(3) << s.first << endl;
    }

    return 0;
}
