#include <bits/stdc++.h>
using namespace std;

const int N = 50;
int f[N], k;

inline void input() {
    cin >> k;
    return;
}

inline void solve() {
    f[1] = f[2] = 1;
    for (int i = 3; i <= k; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    cout << f[k] << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}