#include <iostream>

using namespace std;


struct node {
    int val;
    node * next;
    node * prev;
    node(int x) {
        val = x;
        next = prev = NULL;
    }
};


struct dll {
private:
    int size;
    node * head;
    node * tail;
public:
    dll() {
        size = 0;
        head = tail = NULL;
    }

    void push_front(int x) {
        size++;
        node * n = new node(x);
        if (head == NULL) {
            head = tail = n;
        } else {
            n -> next = head;
            head -> prev = n;
            head = n;  
        }
    }

    void push_back(int x) {
        size++;
        node * n = new node(x);
        if (tail == NULL) {
            head = tail = n;
        } else {
            tail -> next = n;
            n -> prev = tail;
            tail = n;
        }
    }

    void insert(int x, int ind) {
        node * temp = new node(x);
        node * cur = head;
        if(head == NULL) {
            head = tail = temp;
        } else if(ind == 0) {
            push_front(x);
        } else if(ind == size) {
            push_back(x);
        } else {
            for(int i = 0; i < ind; i++) {
                cur = cur -> next;
            }
            temp -> prev = cur -> prev;
            temp -> next = cur;
            cur -> prev -> next = temp;
            cur -> prev = temp;
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
    int n, insert, ind; cin >> n;
    dll d;
    for(int i = 0; i < n; i++) {
        cin >> insert;
        d.push_back(insert);
    }
    cin >> insert >> ind;
    d.insert(insert, ind);
    d.print();
    return 0;
}