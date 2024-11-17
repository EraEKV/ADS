#include <iostream>
#include <vector>

using namespace std;

void constructLps(string & pat, vector <int> &lps) {
    int len = 0;
    lps[0] = 0;
    
    int i = 1;

    while(i < pat.length()) {
        if(pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if(len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
} 

vector<int> search(string &pat, string &txt) {
    int m = pat.length();
    int n = txt.length();

    vector<int> lps(m);
    vector<int> res;

    constructLps(pat, lps);

    int i = 0, j = 0;

    while(i < n) {
        if(txt[i] == pat[j]) {
            i++;
            j++;

            if(j == m) {
                res.push_back(i - j);
                j = lps[j - 1];
            }
        } else {
            if(j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    return res;
}


int main() {
    int k;
    string pat, txt; cin >> pat >> k >> txt;
    
    vector<int> res = search(pat, txt);
    // for(int i : res) {
    //     cout << i << " ";
    // }
    
    cout << (res.size() >= k ? "YES" : "NO");
    
    return 0;
}