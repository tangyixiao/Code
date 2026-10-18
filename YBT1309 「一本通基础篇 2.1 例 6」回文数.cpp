#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
int n, a[N], l;
char s[N];

inline void input() {
    cin >> n >> s;
    l = strlen(s);
    for (int i = 0; i < l; i++) {
        char c = s[l - 1 - i];
        if (c >= '0' && c <= '9') {
            a[i] = c - '0';
        } else if (c >= 'A' && c <= 'F') {
            a[i] = c - 'A' + 10;
        } else {
            a[i] = c - 'a' + 10;
        }
    }
}

inline bool chk() {
    for (int i = 0; i < l / 2; i++) {
        if (a[i] != a[l - 1 - i]) {
            return false;
        }
    }
    return true;
}

inline void solve() {
    if (chk()) {
        cout << 0 << "\n";
        return;
    }
    for (int t = 1; t <= 30; t++) {
        int b[N], c = 0;
        for (int i = 0; i < l; i++) {
            b[i] = a[i];
        }
        for (int i = 0; i < l; i++) {
            int v = a[i] + b[l - 1 - i] + c;
            a[i] = v % n;
            c = v / n;
        }
        for (; c > 0; c /= n) {
            a[l++] = c % n;
        }
        if (chk()) {
            cout << t << "\n";
            return;
        }
    }
    cout << "Impossible\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}