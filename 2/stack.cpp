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



struct stack {
private:
    node * top;
    int len;
public:
    stack() {
        top = NULL;
        len = 0;
    }

    void add(int x) {
        node * n = new node(x);
        len++;
        if (top == NULL) {
            top = n;
        } else {
            n->next = top;
            top = n;
        }
    }

    void print() {
        node * cur = top;
        while (cur != NULL) {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }
};


int main() {
    stack s;
    s.add(1);
    s.add(2);
    s.add(3);
    s.print();
    return 0;
}   