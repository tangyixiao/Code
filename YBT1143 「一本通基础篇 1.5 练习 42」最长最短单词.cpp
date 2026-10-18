#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
char s[N], w[N], mx[N], mn[N];

inline bool lt(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

inline void input() {
    cin.getline(s, N);
    return;
}

inline void solve() {
    int n = strlen(s), l = 0, a = 0, b = 0;
    if (n && s[n - 1] == '\r') {
        s[--n] = 0;
    }
    for (int i = 0; i <= n; i++) {
        if (!lt(s[i])) {
            w[l] = 0;
            if (l > a) {
                a = l, strcpy(mx, w);
            }
            if (!b || l < b) {
                b = l, strcpy(mn, w);
            }
            l = 0;
            continue;
        }
        w[l++] = s[i];
    }
    cout << mx << "\n"
         << mn << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}