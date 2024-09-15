#include <iostream> 
#include <deque>

using namespace std;

void process(int a) {
    deque<int> dq;
    while(a > 0) {
        dq.push_front(a);
        for(int i = 0; i < a; i++) {
            dq.push_front(dq.back());
            dq.pop_back();
        }

        a--;
    }

    while(!dq.empty()) {
        cout << dq.front() << " ";
        dq.pop_front();
    }
    cout << endl;
}

int main() {
    int n; cin >> n;
    
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        process(a);
    }
}