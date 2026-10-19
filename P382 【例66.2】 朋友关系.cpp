#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;

int n, m, a[N];
string s, t;
map<string, int> mp;

inline void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> s >> t;
        if (!mp.count(s)) {
            mp[s] = ++a[0];
        }
        if (!mp.count(t)) {
            mp[t] = ++a[0];
        }
        a[mp[s]]++, a[mp[t]]++;
    }
    return;
}

inline void solve() {
    int ans = 0;
    for (int i = 1; i <= a[0]; i++) {
        ans = max(ans, a[i]);
    }
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