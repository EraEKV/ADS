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

        bool searchSteps(string moves) {
            return searchSteps(root, moves) != NULL;
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

        Node * search(Node * root, int val) {
            if(root == NULL || root -> val == val) {
                return root;
            }

            if(root -> val < val) {
                return search(root -> right, val);
            }

            return search(root -> left, val);
        }

        Node * searchSteps(Node * root, string moves) {
            int k = moves.size();
            Node * cur = root;
            for(int i = 0; i < k; i++) {
                if(moves[i] == 'L' && cur -> left != NULL) {
                    cur = cur -> left;
                } else if (moves[i] == 'R' && cur -> right != NULL) {
                    cur = cur -> right;
                } else {
                    return NULL;
                }
            }
            
            return cur;
        }
};




int main() {
    int n, m; cin >> n >> m;
    string moves;
    bst * b = new bst();
    for(int i = 0; i < n; i++) {
        int temp; cin >> temp;
        b -> add(temp);
    }

    for(int j = 0; j < m; j++) {
        cin >> moves;
        if(b -> searchSteps(moves)) {
            cout << "YES";
        } else {
            cout << "NO";
        }
        cout << endl;
    }

    return 0;
}