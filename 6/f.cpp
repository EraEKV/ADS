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

int partition(vector<pair<float, string>>& arr, int low, int high) {
    float pivot = arr[high].first;
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

void quickSort(vector<pair<float, string>>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void sortInit(vector<pair<float, string>>& students) {
    quickSort(students, 0, students.size() - 1);
}

float evaluateTotalGPA() {
    int m; cin >> m;
    float sum1 = 0;
    float sum2 = 0;
    for(int i = 0; i < m; i++) {
        string grade;
        int credits;
        cin >> grade >> credits;
        sum1 += grades[grade] * credits;
        sum2 += credits;
    }
    return (float) sum1 / sum2;
}

int main() {
    int n; cin >> n;
    vector<pair<float, string>> students(n);
    
    for(int i = 0; i < n; ++i) {
        string name1, name2; cin >> name1 >> name2;
        string name = name1 + " " + name2; 
        float value = evaluateTotalGPA();
        
        students.push_back(make_pair(value, name));
    }

    sortInit(students);

    for(const auto& s: students) {
        if(s.first != 0) cout << s.second << " " << fixed << setprecision(3) << s.first << endl;
    }

    return 0;
}
