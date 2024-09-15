#include <iostream>

using namespace std;

struct Node {
    int val;
    Node *next, *prev;
    Node(int s) {
        val = s;
        next = prev = NULL;
    }
};

struct deque {
    private:
    int size;
    Node *front, *back;
    
    public:
    deque() {
        size = 0;
        front = back = NULL;
    }

    int size() {
        return size;
    }

    void pop_front() {
        if(front != NULL) {
            if(front == back) {
                delete front;
                front = back = NULL;
            } else {
                front = front -> next;
                front -> prev = NULL;
            }
            size--;
        }
    }

    void pop_back() {
        if(back != NULL) {
            if(front == back) {
                delete back;
                front = back = NULL;
            } else {
                back = back -> prev;
                back -> next = NULL;
            }
            size--;
        }
    }

    void push_front(int s) {
        Node *n = new Node(s);
        size++;
        if(front == NULL) {
            front = back = n;
        } else {
            front -> prev = n;
            n -> next = front;
            front = n;
        }
    }

    void push_back(int s) {
        Node *n = new Node(s);
        size++;
        if(back == NULL) {
            front = back = n;
        } else {
            back -> next = n;
            n -> prev = back;
            back = n;
        }
    }

    void print_back() {
        Node * cur = back;
        while (cur != NULL) {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }

    void print_front() {
        Node * cur = front;
        while (cur != NULL) {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }
};


int main() {
    deque d;
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    d.push_front(4);
    d.push_front(5);
    d.push_front(6);
    d.print_front();
    d.print_back();
    return 0;
}