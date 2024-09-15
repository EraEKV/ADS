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
        int size;
        node * head;
        node * tail;
    public:
        queue() {
            size = 0;
            head = tail = NULL;
        }

        void add(int x) {
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
    queue q;
    for(int i = 0; i < 5; i++) {
        q.add(i * i);
    }
    q.print();
    return 0;
}