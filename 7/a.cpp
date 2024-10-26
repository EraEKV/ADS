#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>   

using namespace std;

void merge(vector <string> & arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector <string> leftVec(n1), rightVec(n2);

    for(int i = 0; i < n1; i++) {
        leftVec[i] = arr[left + i];
    }
    for(int i = 0; i < n2; i++) {
        rightVec[i] = arr[mid + i + 1];
    }

    int i = 0, j = 0;
    int k = left;

    while(i < n1 && j < n2) {
        if(leftVec[i].size() <= rightVec[j].size()) {
            arr[k] = leftVec[i];
            i++;
        } else if(leftVec[i].size() > rightVec[j].size()) {
            arr[k] = rightVec[j];
            j++;
        } 
        // else {
        //     if(leftVec[i] <= rightVec[j]) {
        //         arr[k] = leftVec[i];
        //         i++;
        //     } else {
        //         arr[k] = rightVec[j];
        //         j++;
        //     }
        // }
        
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

void mergeSort(vector <string> & arr, int left, int right) {
    if(left >= right) return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}

vector<string> split(string & str, char delimiter) { 
    vector<string> internal; 
    stringstream ss(str);
    string tok; 
    
    while(getline(ss, tok, delimiter)) { 
        internal.push_back(tok); 
    } 
    
    return internal; 
} 

int main() {
    int n; cin >> n;
    cin.ignore();
    
    for(int i = 0; i < n; i++) {
        string s; getline(cin, s);
        vector <string> arr = split(s, ' ');

        mergeSort(arr, 0, arr.size() - 1);
    
        for(string t : arr) cout << t << " ";
        cout << endl;
    }


    return 0;
}