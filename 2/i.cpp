# include <iostream>

using namespace std;

struct Node {
    int val;
    Node *next;

    Node(int x) {
        val = x;
        next = NULL;
    }
};

struct List {
    private:
    int size;
    Node *head, *tail;

    public:
    List() {
        size = 0;
        head = tail = NULL;
    }

    void add(int x) {
        size++;
        Node * n = new Node(x);
        if(head == NULL) {
            head = tail = n;
        } else {
            tail -> next = n;
            tail = n;
        }
    }

    int findMaxSum() {
        if (head == NULL) return 0;
        Node * cur = head;
        int curSum = 0;
        int maxSum = head -> val;
        
        while(cur != NULL) {
            curSum += cur->val;
            if (curSum > maxSum) {
                maxSum = curSum;
            }
            if (curSum < 0) {
                curSum = 0;
            }
            cur = cur->next;
        }

        return maxSum;
    }
};


int main() {
    int n; cin >> n;
    List ll;
    
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        ll.add(x);
    }

    cout << ll.findMaxSum();
    return 0;
}