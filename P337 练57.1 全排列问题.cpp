#include <bits/stdc++.h>
using namespace std;
const int N = 10 + 5;
int n, a[N], vis[N];

inline void input() { cin >> n; }

inline void dfs(int p) {
    if (p > n) {
        for (int i = 1; i <= n; i++) {
            if (i == 1) {
                printf("%d", a[i]);
            } else {
                printf("%5d", a[i]);
            }
        }
        printf("\n");
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i]) {
            continue;
        }
        vis[i] = 1, a[p] = i, dfs(p + 1), vis[i] = 0;
    }
    return;
}

inline void solve() {
    dfs(1);
    return;
}

signed main() {
    input(), solve();
    return 0;
}