#include <iostream>
#include <limits>

using namespace std;

struct heap {
    private:
        long long int *val;
        int size;
        int sum = 0;
        void sift_down() {
            val[0] = val[--size];
            int pos = 0;
            while (2 * pos + 1 < size) {
                int p1 = 2 * pos + 1;
                int p2 = 2 * pos + 2;
                int npos = pos;
                if (val[pos] > val[p1]) {
                    npos = p1;
                }
                if (p2 < size && val[npos] > val[p2]) {
                    npos = p2;
                }
                if (npos != pos) {
                    swap(val[npos], val[pos]);
                    pos = npos;
                } else break;
            }
        }

        void sift_up(int pos) {
            int p = (pos - 1) / 2;
            while (pos > 0 && val[p] > val[pos]) {
                swap(val[p], val[pos]);
                pos = p;
                p = (pos - 1) / 2;
            }
        }

    public:
        heap(int q) {
            size = 0;
            val = new long long int [q];
        }

        void add(long long int v) {
            val[size++] = v;
            sum += v;
            sift_up(size - 1);
        }

        long long int cut_min() {
            if (size == 0) return -1;
            long long int result = val[0];
            val[0] = val[--size]; 
            sift_down();
            return result;
        }

        int getSize() {
            return size;
        }

        long long int getElement(int index) {
            return val[index];
        }

        long long int getSum() {
            return sum;
        }
};

int main() {
    int n, q;
    cin >> q >> n;
    heap *h = new heap(n);

    for (long long int i = 0; i < q; i++) {
        string cmd;
        cin >> cmd;
        long long int num;
        if (cmd == "print") {
            long long int sum = 0;
            if (h->getSize() == 0) {
                cout << '0' << endl;
            } else {
                cout << h -> getSum() << endl;
            }
        } else if (cmd == "insert") {
            cin >> num;
            if (h->getSize() == n) {
                h->cut_min();
            }
            h->add(num);
        }
    }

    delete h;
}
