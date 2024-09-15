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
        node * n = new node(x);
        len++;
        if (head == NULL) {
            head = tail = n;
        } else {
            tail->next = n;
            tail = n;
        }
    }

    void print() {
        node* cur = head;
        while (cur != NULL) {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }
};


int main() {
    queue q;
    q.add(1);
    q.add(2);
    q.add(3);
    q.print();
    return 0;
}