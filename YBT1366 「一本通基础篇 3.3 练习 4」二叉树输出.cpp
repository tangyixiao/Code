#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
char s[N], t[N];
int po[128], m, cur;

inline void input() { cin >> s >> t; }

inline void dfs(int l, int r) {
    if (l > r) {
        return;
    }
    char c = s[cur++];
    int k = po[c];
    dfs(l, k - 1);
    dfs(k + 1, r);
    for (int i = 1; i <= r - l + 1; ++i) {
        cout << c;
    }
    cout << "\n";
    return;
}

inline void solve() {
    m = strlen(s);
    for (int i = 0; i < m; ++i) {
        po[t[i]] = i;
    }
    dfs(0, m - 1);
    return;
}

signed main() {
    input();
    solve();
    return 0;
}