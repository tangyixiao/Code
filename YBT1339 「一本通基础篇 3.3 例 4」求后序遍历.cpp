#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
string s, t;
int po[128], n, m, cur;

inline void input() { cin >> s >> t; }

inline void dfs(int l, int r) {
    if (l > r) {
        return;
    }
    char c = s[cur++];
    int k = po[c - '0'];
    dfs(l, k - 1);
    dfs(k + 1, r);
    cout << c;
    return;
}

inline void solve() {
    n = s.size(), m = t.size();
    for (int i = 0; i < m; ++i) {
        po[t[i] - '0'] = i;
    }
    dfs(0, n - 1);
    cout << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}