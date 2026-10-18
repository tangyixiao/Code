#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n, f[N], a[4] = {10, 20, 50, 100};

inline void input() {
    cin >> n;
    return;
}

inline void solve() {
    f[0] = 1;
    for (int i = 0; i < 4; i++) {
        for (int j = a[i]; j <= n; j++) {
            f[j] += f[j - a[i]];
        }
    }
    cout << f[n] << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}