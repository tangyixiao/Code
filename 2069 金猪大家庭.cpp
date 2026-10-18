#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int n;
long long f[N], g[N];

inline void input() {
    cin >> n;
}

inline void solve() {
    f[1] = 1;
    for (int y = 2; y <= n; y++) {
        for (int b = 1; b < y; b++) {
            int k = y - b + 1 == 2 ? 2 : 4;
            if (k && y - b + 1 <= 6) {
                f[y] += f[b] * k, g[y] += f[b] * k;
            }
        }
    }
    long long r = 0;
    for (int b = 1; b <= n; b++) {
        int a = n - b + 1;
        if (a <= 6) {
            r += f[b];
        }
        if (a <= 1) {
            r += g[b];
        }
    }
    cout << r << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}