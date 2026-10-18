#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int n, a[N], len, f[N];

inline void input() {
    cin >> n;
    return;
}

inline bool chk(int x) {
    while (x % 2 == 0) {
        x /= 2;
    }
    while (x % 3 == 0) {
        x /= 3;
    }
    while (x % 5 == 0) {
        x /= 5;
    }
    return x == 1;
}

inline void solve() {
    len = 0;
    for (int i = 1; i <= n; ++i) {
        if (chk(i)) {
            a[len++] = i;
        }
    }
    for (int i = 0; i < len; ++i) {
        f[i] = (int)log10(a[i]) + 1;
        cout << a[i];
        for (int j = 0; j < 6 - f[i]; j++) {
            cout << " ";
        }
        if (i % 10 == 9) {
            cout << "\n";
        }
    }
    if (len % 10 != 0) {
        cout << "\n";
    }
    cout << len;
    return;
}

signed main() {
    input();
    solve();
    return 0;
}