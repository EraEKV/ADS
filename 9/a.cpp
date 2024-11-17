#include <iostream>
#include <vector>

using namespace std;

vector<int> prefix_function(string &s) {
    size_t n = s.length();
    vector<int> pi(n);
    for (size_t i = 1; i < n; ++i) {
        size_t j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            ++j;
        pi[i] = j;
    }
    return pi;
}

int kmp(vector<int> &v, string &s, string &sub) {
    int i = 0, j = 0, cnt = 0;
    while(i < s.size()) {
        if (s[i] == sub[j]) {
            i++;
            j++;
            if(j == sub.size()) {
                cnt++;
                j = 0;
            }
        }
        else{
            if (j > 0) {
                j = v[j - 1];
            }
            else{
                i += 1;
            }
        }
    }
    return cnt;

}


int main() {
    string s; cin >> s;
    string temp = s;
    string sub; cin >> sub;
    int cnt = 1;

    while (s.size() < sub.size()) {
        s += temp;
        cnt++;
    }

    vector<int> v = prefix_function(sub);

    if (kmp(v, s, sub)) {
        cout << cnt;
    } else {
        s += temp;
        cnt++;
        if (kmp(v, s, sub)) {
            cout << cnt;
        } else {
            cout << -1;
        }
    }

    return 0;
}