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
            sum = 0;
        }

        void add(int x) {
            root = add(root, x);
        }

        void process() {
            process(root);
            print(root);
            cout << endl;
        }

    private:
        Node * root;
        int sum = 0;

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

        void process(Node * cur) {
            if(cur == NULL) {
                return;
            }

            process(cur -> right);
            sum += cur -> val;
            cur -> val = sum;
            process(cur -> left);
        }

        void print(Node * cur) {
            if(cur != NULL) {
                print(cur -> right);
                cout << cur -> val << " ";
                print(cur -> left);
            }
        }
};

int main() {
    int n, temp; cin >> n;

    bst * b = new bst();

    for(int i = 0; i < n; ++i) {
        cin >> temp;
        b -> add(temp);
    }

    b -> process();

    return 0;
}
