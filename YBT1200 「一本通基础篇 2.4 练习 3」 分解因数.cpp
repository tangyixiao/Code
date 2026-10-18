#include <bits/stdc++.h>
using namespace std;

const int N = 3e4 + 5;
int t, a;

inline int dfs(int x, int s) {
    if (s > x) {
        return 0;
    }
    int r = 1;
    for (int i = s; i * i <= x; ++i) {
        if (x % i == 0) {
            r += dfs(x / i, i);
            if (i != x / i) {
                r += dfs(i, x / i);
            }
        }
    }
    return r;
}

inline void solve() {
    for (; t--;) {
        cin >> a;
        cout << dfs(a, 2) << "\n";
    }
    return;
}

signed main() {
    cin >> t;
    solve();
    return 0;
}