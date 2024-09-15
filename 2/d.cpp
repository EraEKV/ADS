#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int val;
    Node *next;
    Node *prev;
    Node(int x) : val(x), next(nullptr), prev(nullptr) {}
};

class dll {
private:
    Node *head;
    Node *tail;
    unordered_map<int, int> mp;
    vector<int> elements;
    
    void all() {
        elements.clear();
        Node *cur = head;
        while (cur != nullptr) {
            elements.push_back(cur->val);
            cur = cur->next;
        }
    }

    void calc() {
        mp.clear();
        for (int x : elements) {
            mp[x]++;
        }
    }

    int get_max() {
        int max_freq = 0;
        for (const auto &p : mp) {
            max_freq = max(max_freq, p.second);
        }
        return max_freq;
    }

    vector<int> get_modes(int max_freq) {
        vector<int> modes;
        for (const auto &p : mp) {
            if (p.second == max_freq) {
                modes.push_back(p.first);
            }
        }
        return modes;
    }

public:
    dll() : head(nullptr), tail(nullptr) {}

    void push_back(int x) {
        Node *n = new Node(x);
        if (tail == nullptr) {
            head = tail = n;
        } else {
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
    }

    void modes() {
        all();
        calc();
        int max_freq = get_max();
        vector<int> modes = get_modes(max_freq);
        sort(modes.begin(), modes.end(), greater<int>());
        for (int x : modes) {
            cout << x << " ";
        }
    }
};

int main() {
    int n;
    cin >> n;

    dll d;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        d.push_back(x);
    }

    d.modes();
    return 0;
}
