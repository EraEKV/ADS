#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int computeLPS(const string &hay, int m, const string &s) {
    vector<int> lps(m, 0);

    int len = 0;
    int i = 1;
    
    while (i < m) {
        if (s[i] == hay[len]) {
            lps[i] = len + 1;
            len++;
            i++;
        } else if (len != 0) {
            len = lps[len - 1];
        } else {
            i++;
        }
    }

    return lps[m - 1];
}

int main() {
    string s; cin >> s;
    s[0] = tolower(s[0]);

    int n; cin >> n;
    int max = -1;

    vector<string> cities;

    for (int i = 0; i < n; ++i) {
        string current; cin >> current;

        string modified = current;
        modified[0] = tolower(modified[0]);

        int length = computeLPS(modified, s.size(), s);

        if (length > max) {
            max = length;
            cities.clear();
            cities.push_back(current);
        } else if (length == max) {
            cities.push_back(current);
        }
    }

    if (max == 0) {
        cout << 0;
    } else {
        cout << cities.size() << endl;
        for (const string &city : cities) {
            cout << city << endl;
        }
    }

    return 0;
}
