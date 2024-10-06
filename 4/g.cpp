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

        int diameter() {
            return diameter(root);
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

        int getHeight(Node * cur) {
            if(cur == NULL) {
                return 0;
            }

            return 1 + max(getHeight(cur -> left), 
            getHeight(cur -> right));
        }

        int diameter(Node * cur) {
            if(cur == NULL) return 0;

            int lheight = getHeight(cur -> left);
            int rheight = getHeight(cur -> right);

            int ldiameter = diameter(cur -> left);
            int rdiameter = diameter(cur -> right);

            return max(lheight + rheight + 1, max(ldiameter, rdiameter));
        }

        void print(Node * cur) {
            if(cur != NULL) {
                cout << cur -> val << " ";
                print(cur -> left);
                // cout << cur -> val << " ";
                print(cur -> right);
            }
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

    cout << b -> diameter();
    return 0;
}