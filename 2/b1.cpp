#include <iostream>

using namespace std;

struct node {
  string val;
  node *next;
  node *prev;
  node(string s) {
    val = s;
    next = prev = NULL;
  }
};

struct dll {
private:
  int size;
  node *head;
  node *tail;

public:
  dll() {
    size = 0;
    head = tail = NULL;
  }

  void push_front(string s) {
    node *n = new node(s);
    size++;
    if (head == NULL) {
      head = tail = n;
    } else {
      n->next = head;
      head->prev = n;
      head = n;
    }
  }

  void push_back(string s) {
    node *n = new node(s);
    size++;
    if (tail == NULL) {
      head = tail = n;
    } else {
      tail->next = n;
      n->prev = tail;
      tail = n;
    }
  }

  void shift(int k) {
    if (size <= 1 || k == 0)
      return;

    k = k % size - 1;

    tail->next = head;
    head->prev = tail;

    for (int i = 0; i < k; i++) {
      head = head->prev;
      tail = tail->prev;
    }

    head->prev = NULL;
    tail->next = NULL;
  }

  void print() {
    node *cur = head;
    while (cur != NULL) {
      cout << cur->val << " ";
      cur = cur->next;
    }
  }
};

int main() {
  int n, k;
  cin >> n >> k;
  dll d;
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    d.push_back(s);
  }
  d.shift(k);
  d.print();
  return 0;
}
