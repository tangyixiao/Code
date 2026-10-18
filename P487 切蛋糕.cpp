#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5, M = 1e4 + 5;
int l, p, n, m, h[N], v[N], xb[N], yb[N], nx, ny, mat[N][N], vis[N][N];
int stx[M], sty[M];
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

inline int rd(string s, int *a) {
    int c = 0, i = 0, w = s.size();
    while (i < w) {
        if (s[i] == '-' || (s[i] >= '0' && s[i] <= '9')) {
            int sg = 1;
            if (s[i] == '-') {
                sg = -1, i++;
            }
            int x = 0;
            while (i < w && s[i] >= '0' && s[i] <= '9') {
                x = x * 10 + s[i] - '0', i++;
            }
            a[++c] = x * sg;
        } else {
            i++;
        }
    }
    return c;
}

inline void input() {
    string s;
    cin >> l >> p;
    cin >> ws;
    getline(cin, s);
    n = rd(s, h);
    getline(cin, s);
    m = rd(s, v);
    return;
}

inline bool has(int a[], int k, int x) {
    for (int i = 1; i <= k; i++) {
        if (a[i] == x) {
            return true;
        }
    }
    return false;
}

inline void build(int a[], int k, int b[], int &t) {
    t = 0;
    b[++t] = -l, b[++t] = l, b[++t] = -p, b[++t] = p;
    for (int i = 1; i <= k; i++) {
        b[++t] = a[i];
    }
    for (int i = 1; i <= t; i++) {
        for (int j = i + 1; j <= t; j++) {
            if (b[j] < b[i]) {
                swap(b[i], b[j]);
            }
        }
    }
    int c = 1;
    for (int i = 2; i <= t; i++) {
        if (b[i] != b[c]) {
            b[++c] = b[i];
        }
    }
    t = c;
    return;
}

inline void solve() {
    int tx, ty;
    build(v, m, xb, tx), build(h, n, yb, ty);
    nx = tx - 1, ny = ty - 1;
    for (int i = 1; i <= nx; i++) {
        for (int j = 1; j <= ny; j++) {
            mat[i][j] = (xb[i] >= -l && xb[i + 1] <= l && yb[j] >= -l && yb[j + 1] <= l) && !(xb[i] >= -p && xb[i + 1] <= p && yb[j] >= -p && yb[j + 1] <= p);
        }
    }
    int ans = 0;
    for (int i = 1; i <= nx; i++) {
        for (int j = 1; j <= ny; j++) {
            if (vis[i][j] || !mat[i][j]) {
                continue;
            }
            ans++;
            int top = 0;
            stx[++top] = i, sty[top] = j, vis[i][j] = 1;
            while (top) {
                int x = stx[top], y = sty[top--];
                for (int k = 0; k < 4; k++) {
                    int a = x + dx[k], b = y + dy[k];
                    if (a < 1 || a > nx || b < 1 || b > ny || vis[a][b] || !mat[a][b]) {
                        continue;
                    }
                    int ax = max(x, a), ay = max(y, b);
                    if (dx[k] && has(v, m, xb[ax])) {
                        continue;
                    }
                    if (dy[k] && has(h, n, yb[ay])) {
                        continue;
                    }
                    vis[a][b] = 1, stx[++top] = a, sty[top] = b;
                }
            }
        }
    }
    cout << ans << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
