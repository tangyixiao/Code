#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, f[N];

inline void input() {
    cin >> n;
}

inline void dfs(int r, int s, int m) {
    if (!r) {
        cout << n << "=";
        for (int i = 1; i <= s; ++i) {
            cout << f[i] << (i == s ? "\n" : "+");
        }
        return;
    }
    for (int i = m; i <= n - 1 && i <= r; ++i) {
        f[++s] = i;
        dfs(r - i, s, i);
        --s;
    }
}

inline void solve() {
    dfs(n, 0, 1);
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
