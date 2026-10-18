#include <bits/stdc++.h>
using namespace std;

const int N = 5e2 + 5;
char s[N], w[N], mx[N];

inline void input() {
    cin.getline(s, N);
    return;
}

inline void solve() {
    int n = strlen(s), l = 0, a = 0;
    if (n && s[n - 1] == '\r') {
        s[--n] = 0;
    }
    for (int i = 0; i <= n; i++) {
        if (s[i] && s[i] != ' ' && s[i] != '.') {
            w[l++] = s[i];
            continue;
        }
        w[l] = 0;
        if (l > a) {
            a = l, strcpy(mx, w);
        }
        l = 0;
    }
    cout << mx << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}