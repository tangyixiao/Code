#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n, m, a[N][N], b[N][N];
string s;

inline void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    cin >> s;
    return;
}

inline void cp() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = b[i][j];
        }
    }
    return;
}

inline void solve() {
    for (char c : s) {
        if (c == 'A') {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    b[j][n - 1 - i] = a[i][j];
                }
            }
            swap(n, m);
            cp();
        }
        if (c == 'B') {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    b[m - 1 - j][i] = a[i][j];
                }
            }
            swap(n, m);
            cp();
        }
        if (c == 'C') {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    b[i][m - 1 - j] = a[i][j];
                }
            }
            cp();
        }
        if (c == 'D') {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    b[n - 1 - i][j] = a[i][j];
                }
            }
            cp();
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << (j + 1 == m ? "\n" : " ");
        }
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