#include <iostream>

using namespace std;

struct Node {
    char val;
    Node *next, *prev;
    Node(char s) {
        val = s;
        next = prev = NULL;
    }
};

struct dll {
    private:
    int length;
    Node *head, *tail;
    
    public:
    dll() {
        length = 0;
        head = tail = NULL;
    }

    int size() {
        return length;
    }

    bool empty() {
        return length == 0;
    }

    void make_empty() {
        Node *current = head;
        while (current != NULL) {
            Node *nextNode = current -> next;
            delete current;
            current = nextNode;
        }
        head = tail = NULL;
        length = 0;
    }

    void pop_front() {
        if (head != NULL) {
            Node *temp = head;
            if (head == tail) {
                head = tail = NULL;
            } else {
                head = head->next;
                head->prev = NULL;
            }
            delete temp;
            length--;
        }
    }

    void pop_back() {
        if (tail != NULL) {
            Node *temp = tail;
            if (head == tail) {
                head = tail = NULL;
            } else {
                tail = tail->prev;
                tail->next = NULL;
            }
            delete temp;
            length--;
        }
    }

    void push_front(char s) {
        Node *n = new Node(s);
        length++;
        if(head == NULL) {
            head = tail = n;
        } else {
            head -> prev = n;
            n -> next = head;
            head = n;
        }
    }

    void push_back(char s) {
        Node *n = new Node(s);
        length++;
        if(tail == NULL) {
            head = tail = n;
        } else {
            tail -> next = n;
            n -> prev = tail;
            tail = n;
        }
    }

    void process() {
        if(head == NULL) return;
        Node * cur = head -> next;
        Node * left = head;
        int len, test = 1;
        cout << head -> val << " ";
        while(cur -> next != NULL) {
            len = test;
            if(cur -> prev != NULL) left = cur -> prev;
            while(left != NULL) {
                len--;
                if(left -> val != cur -> val && len == 1) {
                    cout << -1 << " ";
                    pop_front();
                    break;
                } else {
                    cout << cur -> val << " ";
                    break;
                }
                left = left -> prev;                
            }
            test++;
            cur = cur -> next;
        }
    }


    void print() {
        Node *cur = head;
        cout << endl;
        while(cur != NULL) {
            cout << cur -> val << " ";
            cur = cur -> next;
        }
    }
    
};


int main() {
    int n, k; cin >> n;
    dll d;
    char s;
    for(int i = 0; i < n; i++) {
        cin >> k;
        for(int j = 0; j < k; j++) {
            cin >> s;
            d.push_back(s);
        }
        d.process();
        d.make_empty();
        cout << endl;
    }
    return 0;
}