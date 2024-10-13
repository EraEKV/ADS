#include <iostream>

using namespace std;

struct heap {
    private:
        int* val;
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
            val = new int[n];
        }

        void add(int v) {
            val[size++] = v;
            sift_up(size-1);
        }

        int cut_max() {
            int result = val[0];
            sift_down();
            return result;
        }

        int getSize() {
            return size;
        }
};



int main() {

    int arr[] = {1, 50, 2, 4, 3, 17};
    int n = sizeof(arr) / sizeof(int);

    heap * h = new heap(6);

    for(int i = 0; i < n; ++i) {
        h->add(arr[i]);
    }

    for(int i = 0; i < n; ++i) {
        cout << h->cut_max() << " ";
    }

    return 0;
}