#include <bits/stdc++.h>
using namespace std;

const int N = 2e2 + 5;

int n, p[N], f[N], c[N];

inline void sieve() {
    c[0] = c[1] = 1;
    for (int i = 2; i < N; ++i) {
        if (!c[i]) {
            p[++n] = i;
            for (int j = i * i; j < N; j += i) {
                c[j] = 1;
            }
        }
    }
}

inline void input() {
    sieve();
    f[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = p[i]; j < N; ++j) {
            f[j] += f[j - p[i]];
        }
    }
}

inline void solve() {
    int x;
    while (cin >> x) {
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
