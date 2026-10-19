#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
long long n, a[2][2], r[2][2], c[2][2];

inline void input() {
    cin >> n;
}

inline void solve() {
    a[0][0] = a[0][1] = a[1][0] = 1;
    r[0][0] = r[1][1] = 1;
    long long e = n;
    while (e) {
        if (e & 1) {
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    c[i][j] = 0;
                    for (int k = 0; k < 2; k++) {
                        c[i][j] = (c[i][j] + r[i][k] * a[k][j]) % 100000;
                    }
                }
            }
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    r[i][j] = c[i][j];
                }
            }
        }
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                c[i][j] = 0;
                for (int k = 0; k < 2; k++) {
                    c[i][j] = (c[i][j] + a[i][k] * a[k][j]) % 100000;
                }
            }
        }
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                a[i][j] = c[i][j];
            }
        }
        e >>= 1;
    }
    cout << r[0][0] << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
