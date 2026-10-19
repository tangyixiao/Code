#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int n, m, k, a[N][N], b[N][N], c[N][N];

inline void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    cin >> m >> k;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            cin >> b[i][j];
        }
    }
}

inline void solve() {
    input();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            int s = 0;
            for (int t = 0; t < m; t++) {
                s += a[i][t] * b[t][j];
            }
            c[i][j] = s;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cout << c[i][j] << (j == k - 1 ? "\n" : " ");
        }
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}