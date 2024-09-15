#include <iostream>
#include <string>
using namespace std;

string processString(const string& s) {
    string result;
    for (char ch : s) {
        if (ch == '#') {
            if (!result.empty()) {
                result.pop_back();
            }
        } else {
            result.push_back(ch);
        }
    }
    return result;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    string S1 = processString(s1);
    string S2 = processString(s2);

    cout << (S1 == S2 ? "Yes" : "No");

    return 0;
}
