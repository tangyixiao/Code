#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, q, l, r, d;
long long a[N], b[N];

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> q;
    for (int i = 1; i <= q; i++) {
        cin >> l >> r >> d;
        b[l] += d, b[r + 1] -= d;
    }
}

inline void solve() {
    for (int i = 1; i <= n; i++) {
        b[i] += b[i - 1], a[i] += b[i];
        cout << a[i] << (i == n ? "\n" : " ");
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
