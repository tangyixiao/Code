#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int k, x;
bool f[N];

inline void dfs(int y) {
    if (y > x) {
        return;
    }
    f[y] = 1;
    dfs(y * 2 + 1);
    dfs(y * 3 + 1);
}

inline void input() {
    char c;
    cin >> k >> c >> x;
}

inline void solve() {
    dfs(k);
    cout << (f[x] ? "YES" : "NO") << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
