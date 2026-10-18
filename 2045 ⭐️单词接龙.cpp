#include <bits/stdc++.h>
using namespace std;

const int N = 55;

int n, v[N], ans;
string s[N];

inline void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
}

inline void dfs(int u, int d) {
    v[u] = 1;
    ans = max(ans, d);
    for (int i = 0; i < n; i++) {
        if (!v[i] && s[u][1] == s[i][0]) {
            dfs(i, d + 1);
        }
    }
    v[u] = 0;
}

inline void solve() {
    dfs(0, 1);
    cout << ans << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
