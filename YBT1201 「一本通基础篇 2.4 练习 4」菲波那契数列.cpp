#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 5;

int f[N], n, x;

inline void input() {
    cin >> n;
    f[1] = f[2] = 1;
    for (int i = 3; i < N; ++i) {
        f[i] = f[i - 1] + f[i - 2];
    }
}

inline void solve() {
    while (n--) {
        cin >> x;
        cout << f[x] << "\n";
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
