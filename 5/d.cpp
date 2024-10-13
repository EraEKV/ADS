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
                if(val[pos] > val[p1]) {
                    npos = p1;
                }
                if(p2 < size && val[npos] > val[p2]) {
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
            while(pos > 0 && val[p] > val[pos]) {
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

        long long get_min() {
            return val[0];
        }

        void cut_min() {
            sift_down();
        }

        int getSize() {
            return size;
        }
};


int main() {
    int n, m; cin >> n >> m;
    long long temp1, temp2;
    heap * h = new heap(n);

    for(int i = 0; i < n; ++i) {
        cin >> temp1;
        h -> add(temp1);
    }

    int cnt = 0;
    while(h -> getSize() > 0 && h -> get_min() < m) {
        if(h -> getSize() < 2) {
            cout << -1;
            return 0;
        }
        temp1 = h->get_min();
        h->cut_min();
        temp2 = h->get_min();
        h->cut_min();
        h->add(temp1 + 2 * temp2);
        cnt++;
    }

    cout << cnt;
    return 0;
}
