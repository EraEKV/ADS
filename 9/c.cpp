#include <iostream>
#include <string>
#include <vector>

using namespace std;

int computeKMP(string &txt, string &pat) {
    if (pat.empty()) {
        return 0;
    }

    vector<int> lps(pat.size(), 0);
    int prev = 0, k = 1;

    while (k < pat.size()) {
        if (pat[k] == pat[prev]) {
            lps[k] = prev + 1;
            prev++;
            k++;
        } else if (prev == 0) {
            lps[k] = 0;
            k++;
        } else {
            prev = lps[prev - 1];
        }
    }

    int i = 0, j = 0;

    while (i < txt.size()) {
        if (txt[i] == pat[j]) {
            i++;
            j++;
        } else {
            if (j == 0) {
                i++;
            } else {
                j = lps[j - 1];
            }
        }

        if (j == pat.size()) {
            return i - pat.size();
        }
    }

    return -1;
}

int main() {
    string txt, pat;
    cin >> txt >> pat;

    pat += pat;

    cout << computeKMP(pat, txt) << endl;
    return 0;
}
