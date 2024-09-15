#include <iostream>
#include <stack> 

using namespace std;

int main()
{
    stack <char> st;
    string s; cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (!st.empty() && st.top() == s[i]) 
            st.pop(); 
        else 
            st.push(s[i]);
    }
    s = "";
    while (!st.empty()) {
        s += st.top();
        st.pop();
    }
    if(s.size() % 2 == 1) {
        cout << "NO";
        return 0;
    }
    int len = s.size();
    for (int i = 0; i < len / 2; i++) {
        if (s[i] != s[len - i - 1]) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    
    return 0;
}