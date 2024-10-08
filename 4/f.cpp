#include <iostream>

using namespace std;

struct Node {
    Node * left;
    Node * right;
    int val;
    Node(int x){
        val = x;
        left = right = NULL;
    }
};

struct bst {
    public:
        bst() {
            root = NULL;
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

        int triangles() {
            return triangles(root, 0);
        }

    private:
        Node * root;
        Node * add(Node * cur, int x) {
            if(cur == NULL) {
                cur = new Node(x);
            } else if(cur -> val > x) {
                cur -> left = add(cur -> left, x);
            } else if(cur -> val < x) {
                cur -> right = add(cur -> right, x);
            } 
            
            return cur;
        }

        void print(Node * cur) {
            if(cur != NULL) {
                print(cur -> left);
                cout << cur -> val << " ";
                print(cur -> right);
            }
        }

        int triangles(Node * cur, int sum) {
            if (cur == NULL) {
                return sum;
            }

            if (cur->left != NULL && cur->right != NULL) {
                sum++;
            }

            sum = triangles(cur->left, sum);
            sum = triangles(cur->right, sum);

            return sum;
        }

        Node * search(Node * root, int val) {
            if(root == NULL || root -> val == val) {
                return root;
            }

            if(root -> val < val) {
                return search(root -> right, val);
            }

            return search(root -> left, val);
        }
};




int main() {
    int n, temp; cin >> n;

    bst * b = new bst();

    for(int i = 0; i < n; ++i) {
        cin >> temp;
        b -> add(temp);
    }

    cout << b -> triangles();
    // b -> print();

    return 0;
}