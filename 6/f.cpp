#include <iostream>
#include <map>
#include <iomanip>
#include <vector>

using namespace std;

struct Student {
    double gpa;
    string firstName, lastName;

    Student(double gpa, string firstName, string lastName) {
        this->gpa = gpa;
        this->firstName = firstName;
        this->lastName = lastName;
    }

    bool check(string a, string b) {
        int size = min(a.size(), b.size());
        for (int i = 0; i < size; i++) {
            if (a[i] < b[i]) return true;
            else if (a[i] > b[i]) return false;
        }
        return a.size() < b.size();
    }

    bool main_check(Student b) {
        if (this->gpa < b.gpa) return true;
        if (this->gpa == b.gpa) {
            if (this->firstName == b.firstName) {
                return check(this->lastName, b.lastName);
            }
            return check(this->firstName, b.firstName);
        }
        return false;
    }
};

struct Heap {
    vector<Student> heap;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return (i * 2) + 1; }
    int right(int i) { return (i * 2) + 2; }

    void add(Student val) {
        heap.push_back(val);
        int i = heap.size() - 1;
        while (i != 0 && heap[i].main_check(heap[parent(i)])) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    Student heapDown() {
        if (heap.empty()) return Student(0, "", "");
        if (heap.size() == 1) {
            Student min = heap[0];
            heap.pop_back();
            return min;
        }
        Student min = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapify(0);
        return min;
    }

    void heapify(int i) {
        int smallest = i;
        int l = left(i);
        int r = right(i);

        if (l < heap.size() && heap[l].main_check(heap[smallest])) smallest = l;
        if (r < heap.size() && heap[r].main_check(heap[smallest])) smallest = r;

        if (smallest != i) {
            swap(heap[smallest], heap[i]);
            heapify(smallest);
        }
    }

    void print() {
        while (!heap.empty()) {
            Student student = heapDown();
            cout << student.firstName << " " << student.lastName << " " << fixed << setprecision(3) << student.gpa << '\n';
        }
    }
};

double calculateGPA(map<string, double>& grades, int credits) {
    double totalScore = 0;
    int totalCredits = 0;
    
    for (int j = 0; j < credits; j++) {
        string grade; 
        int credit;
        cin >> grade >> credit;
        totalScore += grades[grade] * credit;
        totalCredits += credit;
    }
    
    return (totalCredits > 0) ? totalScore / totalCredits : 0.0;
}

int main() {
    int n; cin >> n;
    map<string, double> grades = {
        {"F", 0.0}, {"D", 1.0}, {"D+", 1.5}, {"C", 2.0},
        {"C+", 2.5}, {"B", 3.0}, {"B+", 3.5}, {"A", 3.75}, {"A+", 4.0}
    };

    Heap h;

    for (int i = 0; i < n; i++) {
        string firstName, lastName; cin >> firstName >> lastName;
        int credits; cin >> credits;
        double gpa = calculateGPA(grades, credits);
        h.add(Student(gpa, firstName, lastName));
    }

    h.print();
}
