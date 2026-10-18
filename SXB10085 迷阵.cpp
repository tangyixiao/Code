#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int n, m;
int a[N][N], rm[N], cm[N];
int cnt = 0;

inline int pc(int x) {
    int c = 0;
    for (; x; x >>= 1) {
        c += x & 1;
    }
    return c;
}

inline bool ok(int i, int j) {
    for (int r = 0; r < n; r++) {
        int rem = (r < i) ? 0 : ((r == i) ? (n - 1 - j) : n);
        if (m - pc(rm[r]) > rem) {
            return false;
        }
    }
    for (int c = 0; c < n; c++) {
        int rem = (c > j) ? (n - i) : (n - 1 - i);
        if (m - pc(cm[c]) > rem) {
            return false;
        }
    }
    return true;
}

inline bool dfs(int i, int j) {
    if (++cnt > 1e8) {
        return false;
    }
    if (i == n) {
        return true;
    }
    for (int v = 1; v <= m; v++) {
        int p = 1 << (v - 1), orm = rm[i], ocm = cm[j];
        a[i][j] = v, rm[i] |= p, cm[j] |= p;
        int ni = i, nj = j + 1;
        if (nj == n) {
            ni++, nj = 0;
        }
        if (ok(i, j) && dfs(ni, nj)) {
            return true;
        }
        rm[i] = orm, cm[j] = ocm;
    }
    return false;
}

inline void input() {
    cin >> n >> m;
}

inline void solve() {
    dfs(0, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << (j == n - 1 ? "\n" : " ");
        }
    }
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
