#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int n, a[N];

inline void input() {
    cin >> n;
}

inline void dfs(int d) {
    if (d > n) {
        for (int i = 1; i <= n; i++) {
            cout << a[i] << (i == n ? "\n" : " ");
        }
        return;
    }
    for (int i = 1; i <= n; i++) {
        a[d] = i, dfs(d + 1);
    }
}

inline void solve() {
    dfs(1);
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
