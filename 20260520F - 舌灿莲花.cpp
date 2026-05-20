#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int n, m, a[N], b[N], vis[N];
char c[N];
vector<int> g[N];
inline bool check() {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) {
            cnt++;
        }
    }
    return cnt == n;
}
inline bool check2(string s) {
    for (int i = 0; i < s.size() / 2; i++) {
        if (s[i] != s[s.size() - i - 1]) {
            return false;
        }
    }
    return true;
}
inline void dfs(int st, string s, int u) {
    if (st >= n * n) {
        return;
    }
    if (check()) {
        if (check2(s)) {
            cout << st << "\n";
            exit(0);
        }
    }
    for (auto it : g[u]) {
        vis[it]++;
        dfs(st + 1, s + c[it], it);
        vis[it]--;
    }
    return;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("f.in", "r", stdin);
    freopen("f.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    for (int i = 1; i <= n; i++) {
        string s;
        s += c[i];
        vis[i]++;
        // dfs(1, s, i);
        vis[i]--;
    }
    cout << "-1\n";
    return 0;
}