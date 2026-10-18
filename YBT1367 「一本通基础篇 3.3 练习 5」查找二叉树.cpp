#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
int n, x, val[N], ls[N], rs[N];

void dfs(int p, int &cnt) {
    if (!p) {
        return;
    }
    dfs(ls[p], cnt);
    ++cnt;
    if (val[p] == x) {
        x = cnt;
    }
    dfs(rs[p], cnt);
    return;
}

inline void input() {
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> val[i] >> ls[i] >> rs[i];
    }
}

inline void solve() {
    int cnt = 0;
    dfs(1, cnt);
    cout << x << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}