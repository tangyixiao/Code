#include <bits/stdc++.h>
using namespace std;

const int N = 30 + 5;
char s[N];
int a[N], n, c, r[10];

inline void input() {
    cin >> s;
    return;
}

inline void solve() {
    for (int i = 0; s[i]; i++) {
        a[++n] = s[i] - '0';
    }
    for (int k = 2; k <= 9; k++) {
        int t = 0;
        for (int i = 1; i <= n; i++) {
            t = (t * 10 + a[i]) % k;
        }
        if (!t) {
            r[c++] = k;
        }
    }
    if (!c) {
        cout << "none\n";
        return;
    }
    for (int i = 0; i < c; i++) {
        cout << r[i] << " \n"[i == c - 1];
    }
    return;
}

signed main() {
    input();
    solve();
    return 0;
}