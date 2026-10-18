#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int k, f[N];

inline void input() {
    cin >> k;
}

inline void solve() {
    input();
    f[1] = f[2] = 1;
    for (int i = 3; i <= k; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    cout << f[k] << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}