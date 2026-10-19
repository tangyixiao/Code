#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int v[N], lc[N], rc[N], val[N], p, tot, st[N], top, cnt;

inline int bld() {
    int x = v[p++];
    if (!x) {
        return 0;
    }
    int u = ++tot;
    val[u] = x;
    lc[u] = bld();
    rc[u] = bld();
    return u;
}

inline void pr(int x) {
    if (cnt++) {
        cout << " ";
    }
    cout << x;
}

inline void ino() {
    top = 1, st[1] = 1;
    while (top) {
        int u = st[top--];
        if (u > 0) {
            st[++top] = rc[u], st[++top] = -u, st[++top] = lc[u];
        } else if (u < 0) {
            pr(val[-u]);
        } else {
            pr(0);
        }
    }
}

inline void input() {
    for (p = 1; cin >> v[p]; p++) {
    }
}

inline void solve() {
    p = 1, tot = 0, cnt = 0;
    bld();
    ino();
    cout << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}