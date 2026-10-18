#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, tp[N], pr[N], tt[N], mx[N * 4], hd = 1;
long long ans;

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> tp[i] >> pr[i] >> tt[i];
    }
}

inline void upd(int x, int l, int r, int p, int v) {
    if (l == r) {
        mx[x] = v;
        return;
    }
    int m = (l + r) / 2;
    if (p <= m) {
        upd(x * 2, l, m, p, v);
    } else {
        upd(x * 2 + 1, m + 1, r, p, v);
    }
    mx[x] = max(mx[x * 2], mx[x * 2 + 1]);
}

inline int fnd(int x, int l, int r, int p) {
    if (mx[x] < p) {
        return 0;
    }
    if (l == r) {
        return l;
    }
    int m = (l + r) / 2, t = fnd(x * 2, l, m, p);
    if (t) {
        return t;
    }
    return fnd(x * 2 + 1, m + 1, r, p);
}

inline void solve() {
    for (int i = 1; i <= n; ++i) {
        while (hd < i && tt[i] - tt[hd] > 45) {
            upd(1, 1, n, hd, 0);
            ++hd;
        }
        int j = 0;
        if (!tp[i]) {
            ans += pr[i], upd(1, 1, n, i, pr[i]);
        } else {
            j = fnd(1, 1, n, pr[i]);
            if (j) {
                upd(1, 1, n, j, 0);
            } else {
                ans += pr[i];
            }
        }
    }
    cout << ans << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}