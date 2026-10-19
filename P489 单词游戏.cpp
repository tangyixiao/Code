#include <bits/stdc++.h>
using namespace std;

const int N = 16 + 5;

int n, a[N], b[N], len[N], ans;

inline int id(char c) {
    const string v = "AEIOU";
    for (int i = 0; i < 5; ++i) {
        if (v[i] == c) {
            return i;
        }
    }
    return 0;
}

inline void input() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        len[i] = s.size();
        a[i] = id(s.front()), b[i] = id(s.back());
    }
}

inline void dfs(int m, int last, int cur) {
    ans = max(ans, cur);
    for (int i = 0; i < n; ++i) {
        if ((m >> i & 1) == 0 && b[last] == a[i]) {
            dfs(m | 1 << i, i, cur + len[i]);
        }
    }
}

inline void solve() {
    for (int i = 0; i < n; ++i) {
        dfs(1 << i, i, len[i]);
    }
    cout << ans << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
