#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, a[N], x[N], y[N], tx, ty;

inline void input() {
    int v;
    while (cin >> v) {
        a[++n] = v;
    }
}

inline void solve() {
    for (int i = 1; i <= n; i++) {
        int k = lower_bound(x + 1, x + tx + 1, a[i]) - x;
        x[k] = a[i];
        if (k > tx) {
            tx = k;
        }
        k = lower_bound(y + 1, y + ty + 1, -a[i]) - y;
        y[k] = -a[i];
        if (k > ty) {
            ty = k;
        }
    }
    cout << ty << "\n"
         << tx << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
