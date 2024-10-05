#include <iostream>
#include <string>

using namespace std;

struct Node {
    int val;
    int count;
    Node* left;
    Node* right;

    Node(int x) {
        val = x;
        count = 1;
        left = right = NULL;
    }
};

struct bst {
public:
    bst() {
        root = NULL;
    }

    void insert(int x) {
        root = insert(root, x);
    }

    void deleteKey(int x) {
        root = deleteKey(root, x);
    }

    int count(int x) {
        return count(root, x);
    }

private:
    Node* root;

    Node* insert(Node* cur, int x) {
        if (cur == NULL) {
            return new Node(x);
        } 
        if (cur->val == x) {
            cur->count++;
        } else if (cur->val > x) {
            cur->left = insert(cur->left, x);
        } else {
            cur->right = insert(cur->right, x);
        }
        return cur;
    }

    Node* deleteKey(Node* cur, int x) {
        if (cur == NULL) {
            return NULL;
        }
        if (cur->val == x) {
            cur->count--;
            if (cur->count == 0) {
                if (cur->left == NULL) {
                    Node* temp = cur->right;
                    delete cur;
                    return temp;
                } else if (cur->right == NULL) {
                    Node* temp = cur->left;
                    delete cur;
                    return temp;
                } else {
                    Node* minNode = findMin(cur->right);
                    cur->val = minNode->val;
                    cur->count = minNode->count;
                    cur->right = deleteKey(cur->right, minNode->val);
                }
            }
        } else if (cur->val > x) {
            cur->left = deleteKey(cur->left, x);
        } else {
            cur->right = deleteKey(cur->right, x);
        }
        return cur;
    }

    Node* findMin(Node* cur) {
        while (cur && cur->left != NULL) {
            cur = cur->left;
        }
        return cur;
    }

    int count(Node* cur, int x) {
        if (cur == NULL) {
            return 0;
        }
        if (cur->val == x) {
            return cur -> count;
        } else if (cur->val > x) {
            return count(cur->left, x);
        } else {
            return count(cur->right, x);
        }
    }
};

int main() {
    int q; cin >> q;
    bst* b = new bst();
    string command;
    int value;

    for (int i = 0; i < q; ++i) {
        cin >> command >> value;
        if (command == "insert") {
            b->insert(value);
        } else if (command == "delete") {
            b->deleteKey(value);
        } else if (command == "cnt") {
            cout << b->count(value);
        }
    }

    return 0;
}
