#include <iostream>

using namespace std;

struct heap {
    private:
        long long* val;
        int size;
        void sift_down() {
            val[0] = val[--size];
            int pos = 0;
            while(2 * pos + 1 < size) {
                int p1 = 2 * pos + 1;
                int p2 = 2 * pos + 2;
                int npos = pos;
                if(val[pos] < val[p1]) {
                    npos = p1;
                }
                if(p2 < size && val[npos] < val[p2]) {
                    npos = p2;
                }
                if(npos != pos) {
                    swap(val[npos], val[pos]);
                    pos = npos;
                } else break;
            }
        }

        void sift_up(int pos) {
            int p = (pos - 1) / 2;
            while(pos > 0 && val[p] < val[pos]) {
                swap(val[p], val[pos]);
                pos = p;
                p = (pos - 1) / 2;
            }
        }

    public:
        heap(int n) {
            size = 0;
            val = new long long[n];
        }

        void add(long long v) {
            val[size++] = v;
            sift_up(size-1);
        }

        long long cut_max() {
            long long result = val[0];
            sift_down();
            return result;
        }

        int getSize() {
            return size;
        }
};


int main() {
    int n, x, temp1; cin >> n >> x;
    long long sum = 0;

    heap * h = new heap(n);

    for(int i = 0; i < n; ++i) {
        cin >> temp1;
        h -> add(temp1);
    }

    while(x > 0) {
        temp1 = h->cut_max();
        h->add(temp1 - 1);
        sum += temp1;
        x--;
    }

    // cout << (h -> getSize() == 0 ? 0 : h -> cut_max());
    cout << sum;

    return 0;
}