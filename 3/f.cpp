#include <iostream>
#include <algorithm>

using namespace std;

int fightClub(int* fighters, int n, int power) {
    return upper_bound(fighters, fighters + n, power) - fighters;
}

int enemyPower(int* fighters, int count) {
    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += fighters[i];
    }
    return sum;
}

int main() {
    int n; cin >> n;
    int fighters[n];
    
    for (int i = 0; i < n; i++) {
        cin >> fighters[i];
    }
    
    sort(fighters, fighters + n);
    
    int p; cin >> p;

    for (int i = 0; i < p; i++) {
        int power;
        cin >> power;

        int count = fightClub(fighters, n, power);
        int sum = enemyPower(fighters, count);

        cout << count << " " << sum << endl;
    }

    return 0;
}
