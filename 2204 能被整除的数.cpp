#include <bits/stdc++.h>
using namespace std;

const int N = 1e1 + 5;

int m;
long long n, p[N], ans;

inline void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> p[i];
    }
    sort(p, p + m);
}

inline void dfs(int i, long long c, int s) {
    for (int j = i; j < m; j++) {
        if (c > n / p[j]) {
            break;
        }
        ans += s * (n / (c * p[j]));
        dfs(j + 1, c * p[j], -s);
    }
}

inline void solve() {
    input();
    ans = 0;
    dfs(0, 1, 1);
    cout << ans << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}