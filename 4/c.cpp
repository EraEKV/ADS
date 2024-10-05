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

        void christmasTree(int x) {
            Node * cur = search(root, x);
            preOrder(cur);
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

        void preOrder(Node * cur) {
            if(cur != NULL) {
                cout << cur -> val << " ";
                preOrder(cur -> left);
                preOrder(cur -> right);
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
    int n, target; cin >> n;
    bst * b = new bst();

    for(int i = 0; i < n; ++i){
       cin >> target;
       b -> add(target);
    }

    cin >> target;
    b -> christmasTree(target);

    return 0;
}