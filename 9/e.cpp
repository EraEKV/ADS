#include <iostream>
#include <vector>
#include <string>

using namespace std;

void constructLps(const string &pat, vector<int> &lps) {
    int len = 0;
    lps[0] = 0;
    int i = 1;

    while (i < pat.length()) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int minTaskName(const string &pat, int k) {
    int n = pat.size();
    vector<int> lps(n);

    constructLps(pat, lps);

    int period = n - lps[n - 1];

    return n + period * (k - 1);
}

int main() {
    int t; cin >> t;

    while (t--) {
        string pat;
        int k;
        cin >> pat >> k;

        cout << minTaskName(pat, k) << endl;
    }

    return 0;
}
