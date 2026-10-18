#include <bits/stdc++.h>
using namespace std;
int n, len, a[35], b[35];
char s[35];

inline void input() {
    cin >> n >> s;
    for (int i = (int)strlen(s) - 1; i >= 0; i--) {
        a[len++] = s[i] - '0';
    }
    return;
}

inline bool ok() {
    for (int i = 0; i < len; i++) {
        if (a[i] != a[len - 1 - i]) {
            return false;
        }
    }
    return true;
}

inline void solve() {
    input();
    for (int k = 0; k <= 30; k++) {
        if (ok()) {
            cout << k << "\n";
            return;
        }
        for (int i = 0; i < len; i++) {
            b[i] = a[i];
        }
        int c = 0;
        for (int i = 0; i < len; i++) {
            int t = a[i] + b[len - 1 - i] + c;
            a[i] = t % n;
            c = t / n;
        }
        if (c) {
            a[len++] = c;
        }
    }
    cout << "Impossible\n";
    return;
}

signed main() {
    solve();
    return 0;
}