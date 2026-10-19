#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int n;
__int128 f[N];

inline void input() {
    cin >> n;
}

inline void pr(__int128 v) {
    string s;
    for (; v; v /= 10) {
        s = char('0' + (int)(v % 10)) + s;
    }
    cout << (s.empty() ? "0" : s) << "\n";
}

inline void solve() {
    f[1] = 1, f[2] = 2;
    for (int i = 3; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    pr(f[n]);
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
