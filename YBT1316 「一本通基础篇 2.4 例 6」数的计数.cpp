#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n, f[N];

inline void input() {
    cin >> n;
    return;
}

inline void solve() {
    f[1] = 1;
    for (int i = 2; i <= n; i++) {
        f[i] = 1;
        for (int j = 1; j <= i / 2; j++) {
            f[i] += f[j];
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