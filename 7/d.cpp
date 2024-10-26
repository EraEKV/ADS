#include <iostream>
#include <vector>
#include <unordered_map>
#include <iomanip>

using namespace std;

struct Student {
    double gpa;
    string lname, fname;

    Student() : gpa(0.0), fname(""), lname("") {}

    Student(double gpa, string fname, string lname) {
        this->gpa = gpa;
        this->fname = fname;
        this->lname = lname;
    }
};

void merge(vector <Student> & arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector <Student> leftVec(n1), rightVec(n2);

    for(int i = 0; i < n1; i++) {
        leftVec[i] = arr[left + i];
    }
    for(int i = 0; i < n2; i++) {
        rightVec[i] = arr[mid + i + 1];
    }

    int i = 0, j = 0;
    int k = left;

    while(i < n1 && j < n2) {
        if(leftVec[i].gpa < rightVec[j].gpa) {
            arr[k] = leftVec[i];
            i++;
        } else if(leftVec[i].gpa > rightVec[j].gpa)  {
            arr[k] = rightVec[j];
            j++;
        } else {
            if(leftVec[i].fname < rightVec[j].fname) {
                arr[k] = leftVec[i];
                i++;
            } else if(leftVec[i].fname > rightVec[j].fname)  {
                arr[k] = rightVec[j];
                j++;
            } else {
                if(leftVec[i].lname < rightVec[j].lname) {
                    arr[k] = leftVec[i];
                    i++;
                } else if(leftVec[i].lname > rightVec[j].lname)  {
                    arr[k] = rightVec[j];
                    j++;
                }
            }
        }
        k++;
    }

    while(i < n1) {
        arr[k] = leftVec[i];
        k++;
        i++;
    }

    while(j < n2) {
        arr[k] = rightVec[j];
        k++;
        j++;
    }
}

void mergeSort(vector <Student> & arr, int left, int right) {
    if(left >= right) return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}

double calculateGPA(unordered_map<string, double>& grades, int credits) {
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
    unordered_map<string, double> grades = {
        {"F", 0.0}, {"D", 1.0}, {"D+", 1.5}, {"C", 2.0},
        {"C+", 2.5}, {"B", 3.0}, {"B+", 3.5}, {"A", 3.75}, {"A+", 4.0}
    };
    
    int n; cin >> n;

    vector <Student> students;

    for (int i = 0; i < n; i++) {
        string fname, lname; cin >> fname >> lname;
        int credits; cin >> credits;
        double gpa = calculateGPA(grades, credits);
        students.push_back(Student(gpa, fname, lname));
    }

    mergeSort(students, 0, n - 1);

    cout << fixed << setprecision(3);

    for(Student s : students) cout << s.fname << " " << s.lname << " " << s.gpa << endl;

    return 0;
}