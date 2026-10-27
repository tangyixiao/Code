#include <bits/stdc++.h>
using namespace std;

int n;

bool prime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

signed main() {
    for (int i = 1; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            n = i * 100 + j * 10 + i;
            if (prime(n)) {
                cout << n << "\n";
            }
        }
    }
    return 0;
}
