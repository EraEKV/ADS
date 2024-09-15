#include <iostream>

using namespace std;


struct node {
    int val;
    node * next;
    node(int x) {
        val = x;
        next = NULL;
    }
};

struct queue {
    private:
        node * head;
        node * tail;
        int len;

    public:
        queue() {
            head = tail = NULL;
            len = 0;
        }
        
        void add(int x) {
            len++;
            if(len % 2 != 0) {
                node * n = new node(x);
                if(head == NULL) {
                    head = tail = n;
                } else {
                    tail -> next = n;
                    tail = n;
                }
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
    int n; cin >> n;
    queue q;
    for(int i = 0; i < n; i++) {
        int k; cin >> k;
        q.add(k);
    }
    q.print();

    return 0;
}