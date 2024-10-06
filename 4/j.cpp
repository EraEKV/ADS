#include <iostream>
#include <vector>

using namespace std;

vector<int> balanced;

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int x) {
        val = x;
        left = right = NULL;
    }
};

struct bst {
    Node* root;
    vector<int> nums;

    bst() {
        root = NULL;
    }

    Node* add(Node* cur, int x) {
        if (cur == NULL) {
            cur = new Node(x);
        } else if (cur->val > x) {
            cur->left = add(cur->left, x);
        } else {
            cur->right = add(cur->right, x);
        }
        return cur;
    }

    void print(Node* cur) {
        if (cur != NULL) {
            print(cur->left);
            nums.push_back(cur->val);
            print(cur->right);
        }
    }

    void toBalanced(int left, int right) {
        if (left > right) return;

        int mid = left + (right - left) / 2;
        balanced.push_back(nums[mid]);
        toBalanced(left, mid - 1);
        toBalanced(mid + 1, right);
    }
};

int main() {
    bst* b = new bst();
    int n; cin >> n;
    n = (1 << n) - 1;
    
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        b->root = b->add(b->root, x);
    }

    b->print(b->root);
    b->toBalanced(0, n - 1);

    for (int i = 0; i < n; ++i) {
        cout << balanced[i] << " ";
    }

    return 0;
}
