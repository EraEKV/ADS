#include <iostream>

using namespace std;

struct Node {
    int val;
    Node * next;
    Node(int x) {
        val = x;
        next = NULL;
    }
};



struct queue {
private:
    Node * head;
    Node * tail;
    int len;
public:
    queue() {
        head = tail = NULL;
        len = 0;
    }

    void add(int x) {
        Node * n = new Node(x);
        len++;
        if (head == NULL) {
            head = tail = n;
        } else {
            tail->next = n;
            tail = n;
        }
    }

    void print() {
        Node* cur = head;
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