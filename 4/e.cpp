#include <iostream>

using namespace std;

struct Node {
    Node *left;
    Node *right;
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

        void print() {
            print(root);
        }

        bool search(int x) {
            return search(root, x) != NULL;
        }

        void levels() {
            int height = getHeight(root);
            cout << height << endl;
            for (int level = 0; level < height; level++) {
                int sum = getLevelSum(root, level, 0);
                cout << sum << " ";
            }
        }

    private:
        Node *root;

        Node *add(Node *cur, int x) {
            if (cur == NULL) {
                cur = new Node(x);
            } else if (cur->val > x) {
                cur->left = add(cur->left, x);
            } else if (cur->val < x) {
                cur->right = add(cur->right, x);
            }
            return cur;
        }

        void print(Node *cur) {
            if (cur != NULL) {
                print(cur->left);
                cout << cur->val << " ";
                print(cur->right);
            }
        }

        Node *search(Node *root, int val) {
            if (root == NULL || root->val == val) {
                return root;
            }

            if (root->val < val) {
                return search(root->right, val);
            }

            return search(root->left, val);
        }

        int getHeight(Node *root) {
            if (root == NULL) {
                return 0;
            }
            int left = getHeight(root->left);
            int right = getHeight(root->right);
            return max(left, right) + 1;
        }

        int getLevelSum(Node *node, int targetLevel, int currentLevel) {
            if (node == NULL) {
                return 0;
            }

            if (currentLevel == targetLevel) {
                return node->val;
            }

            return getLevelSum(node->left, targetLevel, currentLevel + 1) + 
            getLevelSum(node->right, targetLevel, currentLevel + 1);
        }
};

int main() {
    int n; cin >> n;

    bst *b = new bst();
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        b->add(temp);
    }

    b->levels();

    return 0;
}
