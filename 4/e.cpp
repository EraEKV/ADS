#include <iostream>

using namespace std;

struct Node {
    Node* left;
    Node* right;
    int val;
    Node(int x) {
        val = x;
        left = right = NULL;
    }
};

struct bst {
public:
    bst() {
        root = new Node(1);
    }

    void add(int x) {
        root = add(root, x);
    }

    void addLaw(int x, int y, int z) {
        Node* cur = dfs(root, x);
        if (cur != NULL) {
            if (z == 0 && dfs(root, y) == NULL) {
                cur->left = new Node(y);
            } else if (z == 1 && dfs(root, y) == NULL) {
                cur->right = new Node(y);
            }
        }
    }

    int getMaxWidth() {
        return getMaxWidth(root);
    }

    void print() {
        print(root);
    }

    Node* search(int x) {
        return search(root, x);
    }

    int getWidth() {
        return getMaxWidth(root);
    }

private:
    Node* root;

    Node* add(Node* cur, int x) {
        if (cur == NULL) {
            cur = new Node(x);
        } else if (cur->val > x) {
            cur->left = add(cur->left, x);
        } else if (cur->val < x) {
            cur->right = add(cur->right, x);
        }
        return cur;
    }

    void print(Node* cur) {
        if (cur != NULL) {
            cout << cur->val << " ";
            print(cur->left);
            print(cur->right);
        }
    }

    int getHeight(Node* cur) {
        if (cur == NULL) { 
            return 0;
        }
        return 1 + max(getHeight(cur->left), getHeight(cur->right));
    }


    int calculateWidth(Node* cur, int level) {
        if (cur == NULL) {
            return 0;
        }
        if (level == 1) {
            return 1;
        }
        return calculateWidth(cur->left, level - 1) + calculateWidth(cur->right, level - 1);
    }

    int getMaxWidth(Node* cur) {
        int maxWidth = 0;
        int h = getHeight(cur);
        
        for (int i = 1; i <= h; i++) {
            int width = calculateWidth(cur, i);
            if (width > maxWidth) 
                maxWidth = width;
        }
        return maxWidth;
    }

    Node* search(Node* root, int val) {
        if (root == NULL || root->val == val) {
            return root;
        }

        if (root->val < val) {
            return search(root->right, val);
        }

        return search(root->left, val);
    }

    Node* dfs(Node* cur, int target) {
        if (cur == NULL) return NULL;
        if (cur->val == target) {
            return cur;
        }

        Node* leftResult = dfs(cur->left, target);
        if (leftResult != NULL) {
            return leftResult;
        }

        return dfs(cur->right, target);
    }
};

int main() {
    int n, x, y, z; cin >> n;

    bst* b = new bst();

    for (int i = 0; i < n; ++i) {
        cin >> x >> y >> z;
        b->addLaw(x, y, z);
    }
    cout << b -> getWidth();

    return 0;
}
