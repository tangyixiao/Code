#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 5;
int f[N], g[N];
char s[N], t[N];

inline void input() {
    cin >> s;
    cin >> t;
    return;
}

inline void solve() {
    int la = strlen(s), lb = strlen(t);
    int *p = f, *q = g;
    for (int j = 0; j <= lb; j++) {
        p[j] = j;
    }
    for (int i = 1; i <= la; i++) {
        q[0] = i;
        for (int j = 1; j <= lb; j++) {
            q[j] = min(min(p[j] + 1, q[j - 1] + 1), p[j - 1] + (s[i - 1] != t[j - 1]));
        }
        swap(p, q);
    }
    cout << p[lb] << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}