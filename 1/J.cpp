#include <iostream> 
#include <deque> 
 
using namespace std; 
 
int main() { 
    char c; 
    int n; 
    deque<int> dq; 
 
    while (cin >> c) { 
        if (c == '!') { 
            break; 
        } 
 
        if (c == '+') { 
            cin >> n; 
            dq.push_front(n); 
        } else if (c == '-') { 
            cin >> n; 
            dq.push_back(n); 
        } else if (c == '*') { 
            if (dq.empty()) { 
                cout << "error" << endl; 
            } else if (dq.size() == 1) { 
                cout << (2 * dq.front()) << endl; 
                dq.pop_front(); 
 
            } else { 
                cout << dq.front() + dq.back() << endl; 
                dq.pop_front(); 
                dq.pop_back(); 
            } 
        } 
    } 
    return 0; 
}