#include <iostream>
using namespace std;

bool isPrime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    int n, count = 0, num = 2; cin >> n;

    while (count < n) {
        if (isPrime(num)) {
            count++;
            if (count == n) {
                cout << num;
                return 0;
            }
        }
        num++;
    }
}
