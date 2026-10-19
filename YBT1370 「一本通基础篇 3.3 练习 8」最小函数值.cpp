#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
int n, m, a[N], b[N], c[N];

struct node {
    int a, b, c, x, f;
} t[N];

inline void input() { cin >> n >> m; }

inline void solve() {
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i] >> c[i];
    }
    for (int i = 1; i <= n; ++i) {
        int x = 1, f = (a[i] + b[i]) + c[i];
        for (int j = 2; j <= 4; ++j) {
            int v = (a[i] * j + b[i]) * j + c[i];
            if (v < f) {
                x = j, f = v;
            }
        }
        t[i] = {a[i], b[i], c[i], x, f};
    }
    for (int i = 1; i <= m; ++i) {
        int p = 1;
        for (int j = 2; j <= n; ++j) {
            if (t[j].f < t[p].f) {
                p = j;
            }
        }
        cout << (i == 1 ? "" : " ") << t[p].f;
        int nx = t[p].x + 1;
        t[p].f = (t[p].a * nx + t[p].b) * nx + t[p].c;
        t[p].x = nx;
    }
    cout << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}