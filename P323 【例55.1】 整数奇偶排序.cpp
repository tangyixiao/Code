#include <bits/stdc++.h>
using namespace std;

const int N = 1e1 + 5;

int a[N], b[N], c[N], m, t;

inline void input() {
    for (int i = 1; i <= 10; i++) {
        cin >> a[i];
        if (a[i] & 1) {
            b[++m] = a[i];
        } else {
            c[++t] = a[i];
        }
    }
}

inline void solve() {
    sort(b + 1, b + m + 1, greater<int>());
    sort(c + 1, c + t + 1);
    for (int i = 1; i <= m; i++) {
        cout << b[i] << " ";
    }
    for (int i = 1; i <= t; i++) {
        cout << c[i] << (i == t ? "\n" : " ");
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
