#include <bits/stdc++.h>
using namespace std;

int n, m;

inline void input() {
    cin >> n >> m;
}

inline void solve() {
    for (int i = 1; i <= n; i++) {
        if (i % m != 0) {
            cout << i << "\n";
        }
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}