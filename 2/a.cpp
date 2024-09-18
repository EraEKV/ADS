#include <iostream>

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
  Node *head;
  Node *tail;

public:
  List() {
    size = 0;
    head = tail = NULL;
  }

  void add(int x) {
    Node *n = new Node(x);
    size++;
    if (head == NULL) {
      head = tail = n;
    } else {
      tail->next = n;
      tail = n;
    }
  }

  int findNearest(int x) {
    int minDiff = 100000000, ind = 0, minInd = -1;
    Node *cur = head;
    while (cur != NULL) {
      if (abs(x - (cur->val)) < minDiff) {
        minDiff = abs(x - (cur->val));
        minInd = ind;
      }
      ind++;
      cur = cur->next;
    }
    return minInd;
  }
};

int main() {
  int n, k;
  cin >> n;
  List q;
  for (int i = 0; i < n; i++) {
    cin >> k;
    q.add(k);
  }
  cin >> k;
  cout << q.findNearest(k);
}
