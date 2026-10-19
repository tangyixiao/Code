#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int n, m, a[N], b[N], c[N];

inline void input() {
    char x[N], y[N];
    cin >> x >> y;
    n = strlen(x), m = strlen(y);
    for (int i = 0; i < n; i++) {
        a[i] = x[n - 1 - i] - '0';
    }
    for (int i = 0; i < m; i++) {
        b[i] = y[m - 1 - i] - '0';
    }
    return;
}

inline void solve() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            c[i + j] += a[i] * b[j];
        }
    }
    for (int i = 0; i < n + m; i++) {
        c[i + 1] += c[i] / 10;
        c[i] %= 10;
    }
    int i = n + m;
    while (i > 1 && c[i] == 0) {
        i--;
    }
    for (; i >= 0; i--) {
        cout << c[i];
    }
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