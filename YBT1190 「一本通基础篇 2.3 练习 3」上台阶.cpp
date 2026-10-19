#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e4 + 5;

int f[N], n;

inline void input() {
    f[0] = 1, f[1] = 1, f[2] = 2;
    for (int i = 3; i < N; ++i) {
        f[i] = f[i - 1] + f[i - 2] + f[i - 3];
    }
}

inline void solve() {
    while (cin >> n && n) {
        cout << f[n] << "\n";
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
