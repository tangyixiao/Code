#include <bits/stdc++.h>
using namespace std;

const int N = 3e1 + 5;

int n, r, a[N];

inline void input() {
    cin >> n >> r;
}

inline void dfs(int d, int x) {
    if (d > r) {
        for (int i = 1; i <= r; i++) {
            printf("%3d", a[i]);
        }
        printf("\n");
        return;
    }
    for (int i = x; i <= n; i++) {
        a[d] = i, dfs(d + 1, i + 1);
    }
}

inline void solve() {
    dfs(1, 1);
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
