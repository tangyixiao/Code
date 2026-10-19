#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;

int n;
__int128 x[N], y[N], c[N], k[N], d[N];
bool v[N];

inline void read(__int128 *a) {
    long long t = 0;
    cin >> t, *a = t;
    return;
}

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        read(&x[i]), read(&y[i]);
    }
    for (int i = 1; i <= n; i++) {
        read(&c[i]);
    }
    for (int i = 1; i <= n; i++) {
        read(&k[i]);
    }
    return;
}

inline __int128 w(int i, int j) {
    if (!i || !j) {
        return c[i + j];
    }
    __int128 dx = x[i] - x[j], dy = y[i] - y[j];
    if (dx < 0) {
        dx = -dx;
    }
    if (dy < 0) {
        dy = -dy;
    }
    return (k[i] + k[j]) * (dx + dy);
}

inline void print(__int128 a) {
    if (!a) {
        cout << 0;
        return;
    }
    string s;
    while (a) {
        s += char('0' + a % 10), a /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s;
    return;
}

inline void solve() {
    d[0] = 0;
    for (int i = 1; i <= n; i++) {
        d[i] = (__int128)1 << 120;
    }
    __int128 ans = 0;
    for (int t = 0; t <= n; t++) {
        int u = -1;
        for (int i = 0; i <= n; i++) {
            if (!v[i] && (u == -1 || d[i] < d[u])) {
                u = i;
            }
        }
        v[u] = 1, ans += d[u];
        for (int i = 0; i <= n; i++) {
            if (!v[i]) {
                __int128 e = w(u, i);
                if (e < d[i]) {
                    d[i] = e;
                }
            }
        }
    }
    print(ans);
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}