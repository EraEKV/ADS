#include <iostream>
#include <deque>

using namespace std;

int main() {
    deque<int> boris;
    deque<int> nursik;

    int card;
    for (int i = 0; i < 5; ++i) {
        cin >> card;
        boris.push_back(card);
    }
    for (int i = 0; i < 5; ++i) {
        cin >> card;
        nursik.push_back(card);
    }

    int moves = 0;
    const int max_moves = 1000000;

    while (moves < max_moves) {
        if (boris.empty()) {
            cout << "Nursik " << moves;
            return 0;
        }
        if (nursik.empty()) {
            cout << "Boris " << moves;
            return 0;
        }

        int borisCard = boris.front();
        int nursikCard = nursik.front();
        boris.pop_front();
        nursik.pop_front();

        if (borisCard == 0 && nursikCard == 9) {
            boris.push_back(borisCard);
            boris.push_back(nursikCard);
        } else if (borisCard == 9 && nursikCard == 0) {
            nursik.push_back(borisCard);
            nursik.push_back(nursikCard);
        } else if (borisCard > nursikCard) {
            boris.push_back(borisCard);
            boris.push_back(nursikCard);
        } else {
            nursik.push_back(borisCard);
            nursik.push_back(nursikCard);
        }

        ++moves;
    }

    cout << "blin nichya";
    return 0;
}
