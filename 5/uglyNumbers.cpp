#include <iostream>
#include <map>

using namespace std;

struct heap{
    private:
        long long val[3000];
        int hs;
        std::map<long long, bool> used;
        void sift_down(){
            val[0] = val[--hs];
            int pos = 0;
            while(2 * pos + 1 < hs){
                int p1 = 2 * pos + 1;
                int p2 = 2 * pos + 2;
                int npos = pos;
                if(val[pos] > val[p1]){
                    npos = p1;
                }
                if(p2 < hs && val[npos] > val[p2]){
                    npos = p2;
                }
                if(npos != pos){
                    std::swap(val[npos], val[pos]);
                    pos = npos;
                }else break;
            }
        }

        void sift_up(int pos){
            int p = (pos-1)/2;
            while(pos > 0 && val[p] > val[pos]){
                std::swap(val[p], val[pos]);
                pos = p;
                p = (pos-1)/2;
            }
        }

    public:
        heap() {
            hs = 0;
        }

        void add(int v){
            if(!used[v]){
                used[v] = true;
                val[hs++] = v;
                sift_up(hs-1);
            }
        }

        long long cut_min(){
            long long result = val[0];
            sift_down();
            return result;
        }

};


int main() {
    int n; cin >> n;

    heap * h = new heap();
    h->add(1);

    long long val = -1;

    while(n--){
        val = h->cut_min();
        h->add(val * 2);
        h->add(val * 3);
        h->add(val * 5);
    }

    cout << val;

    return 0;
}