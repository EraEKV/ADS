#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool check(string& s, int m) {
    string ref = s;
    int i = 0;

    for (int j = 0; j < m; ++j) {
        s += s[i++];
    }

    return s.substr(m) == ref;
}

void kmp(string& text) {
    int n = text.size();
    vector<int> lps(n, 0);
    
    int prev = 0;
    int i = 1;

    while (i < n) {
        if (text[i] == text[prev]) {
            lps[i] = prev + 1;
            prev++;
            i++;
        } else if (prev != 0) {
            prev = lps[prev - 1];
        } else {
            lps[i] = 0;
            i++;
        }
    }
    
    int j = 0, k = 1, cnt = 0;
    bool isValid = true;
    while (k < n) {
        if (lps[k] == 0) {
            j = (isValid) ? j + 1 : k;
            isValid = true;
        } else if (j + 1 == lps[k] || (lps[k] % 2 == 0 && ((lps[k] / 2) % (j + 1)) == 0)) {
            isValid = false;
            cnt++;
        }
        k++;
    }

    if (j != n - 1 && check(text, j + 1)) {
        cnt--;
    }
    
    cout << cnt;
}

int main() {
    string s; cin >> s;

    if (s.size() < 3) {
        cout << 0;
        return 0;
    }

    kmp(s);
    
    return 0;
}
