#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n; cin >> n;
    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    stack <int> st;
    st.push(-1);
    for (int i = 0; i < n; i++){
        while (st.top() > a[i]) st.pop();
        cout << st.top() << " ";
        st.push(a[i]);
    }

    return 0;
}
