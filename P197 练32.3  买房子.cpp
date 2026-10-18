#include <bits/stdc++.h>
using namespace std;

int n, k;

inline void input() {
    cin >> n >> k;
}

inline void solve() {
    double p = 200;
    for (int i = 1; i <= 20; i++) {
        if (i * n >= p) {
            cout << i << "\n";
            return;
        }
        p = p * (100 + k) / 100;
    }
    cout << "Impossible\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
