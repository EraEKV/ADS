#include <iostream>

using namespace std;


struct node {
    string val;
    node * next;
    node(string x) {
        val = x;
        next = NULL;
    }
};


struct queue {
    private:
        int size;
        node * head;
        node * tail;
    public:
        queue() {
            size = 0;
            head = tail = NULL;
        }

        void add(string x) {
            size++;
            node * n = new node(x);
            if (head == NULL) {
                head = tail = n;
            } else {
                tail -> next = n;
                tail = n;
            }
        }
    
        void print() {
            node * cur = head;
            while(cur != NULL) {
                cout << cur -> val << " ";
                cur = cur -> next;
            }
        }
};


int main() {
    queue q1, q2;
    int n, k; cin >> n >> k;
    string s;
    for(int i = 0; i < k; i++) {
        cin >> s;
        q2.add(s);
    }

    for(int i = k; i < n; i++) {
        cin >> s;
        q1.add(s);
    }

    q1.print();
    q2.print();
    return 0;
}