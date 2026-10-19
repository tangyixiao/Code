#include <bits/stdc++.h>
using namespace std;

int m, n;

inline long long akm(int m, int n) {
    if (m == 0) {
        return n + 1;
    }
    if (n == 0) {
        return akm(m - 1, 1);
    }
    return akm(m - 1, akm(m, n - 1));
}

inline void input() { cin >> m >> n; }

inline void solve() {
    cout << akm(m, n) << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}