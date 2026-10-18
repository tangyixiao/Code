#include <bits/stdc++.h>
using namespace std;
const int N = 10 + 5;
int a[N] = {99, 200, 95, 87, 98, -12, 30, 87, 75, -25};
int n;

inline void input() {
    for (; !(cin >> n) || n < 1 || n > 10;) {
    }
}

inline void solve() {
    for (int i = 0; i < 10; i++) {
        int c = 0;
        for (int j = 0; j < 10; j++) {
            c += a[j] > a[i];
        }
        if (c == n - 1) {
            cout << a[i] << "\n";
            return;
        }
    }
    return;
}

signed main() {
    input(), solve();
    return 0;
}