#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int n, h[N], f[N], t[N], k;

inline void input() {
    while (cin >> h[n]) {
        ++n;
    }
    return;
}

inline void solve() {
    for (int i = 1; i <= n; ++i) {
        f[i] = 1;
        for (int j = 1; j < i; ++j) {
            if (h[j] >= h[i] && f[j] + 1 > f[i]) {
                f[i] = f[j] + 1;
            }
        }
    }
    int mx = 0;
    for (int i = 1; i <= n; ++i) {
        mx = f[i] > mx ? f[i] : mx;
    }
    k = 0;
    for (int i = 1; i <= n; ++i) {
        int j = 0;
        for (; j < k && t[j] < h[i]; ++j) {
        }
        t[j] = h[i], k = j + 1 > k ? j + 1 : k;
    }
    cout << mx << "\n"
         << k << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
