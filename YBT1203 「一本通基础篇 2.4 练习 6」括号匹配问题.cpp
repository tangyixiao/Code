#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

char s[N], t[N];

inline void input() {
    cin.getline(s, sizeof(s));
}

inline void solve() {
    int n = strlen(s), st[N], top = 0;
    memset(t, ' ', sizeof(t));
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            st[top++] = i;
        } else if (s[i] == ')') {
            if (top) {
                --top;
            } else {
                t[i] = '?';
            }
        }
    }
    for (int i = 0; i < top; ++i) {
        t[st[i]] = '$';
    }
    t[n] = 0;
    cout << s << "\n"
         << t << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (input(), strlen(s)) {
        solve();
    }
    return 0;
}
