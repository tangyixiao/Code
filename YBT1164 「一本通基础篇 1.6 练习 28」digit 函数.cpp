#include <bits/stdc++.h>
using namespace std;

int n, k;

inline void input() {
    cin >> n >> k;
    return;
}

inline int digit(int x, int p) {
    for (int i = 1; i < p; i++) {
        x /= 10;
    }
    return x % 10;
}

inline void solve() {
    cout << digit(n, k) << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}