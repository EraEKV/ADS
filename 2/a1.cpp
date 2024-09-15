#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> numbers(n);

    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    int k;
    cin >> k;

    int ind = 0;
    int minDif = abs(numbers[0] - k);

    for (int i = 1; i < n; i++) {
        int curDif = abs(numbers[i] - k);
        if (curDif < minDif) {
            minDif = curDif;
            ind = i;
        }
    }

    cout << ind << endl;

    return 0;
}