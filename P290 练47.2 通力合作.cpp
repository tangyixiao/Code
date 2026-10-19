#include <bits/stdc++.h>
using namespace std;

inline void dfs(int x) {
    if (x > 100) {
        return;
    }
    printf("%5d", x);
    dfs(x + 1);
    return;
}

inline void input() {
    return;
}

inline void solve() {
    printf("%d", 1);
    dfs(2);
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
