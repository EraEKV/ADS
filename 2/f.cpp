#include <iostream>

using namespace std;

struct node {
  int val;
  node *next;
  node(int x) {
    val = x;
    next = NULL;
  }
};

struct queue {
private:
  int size;
  node *head;
  node *tail;

public:
  queue() {
    size = 0;
    head = tail = NULL;
  }

  void add(int x) {
    size++;
    node *n = new node(x);
    if (head == NULL) {
      head = tail = n;
    } else {
      tail->next = n;
      tail = n;
    }
  }

  void print(int insert, int ind) {
    node *cur = head;
    while (cur != NULL) {
      cout << cur->val << " ";
      cur = cur->next;
    }
  }

  void print(int insert, int ind) {
    node *cur = head;
    int cnt = 0;
    while (cur != NULL) {
      if (cnt == ind)
        cout << insert << " ";
      cout << cur->val << " ";
      cur = cur->next;
      cnt++;
    }
  }
};

int main() {
  int n, insert, ind;
  cin >> n;
  queue q;
  for (int i = 0; i < n; i++) {
    cin >> insert;
    q.add(insert);
  }
  cin >> insert >> ind;
  q.print(insert, ind);
  return 0;
}
