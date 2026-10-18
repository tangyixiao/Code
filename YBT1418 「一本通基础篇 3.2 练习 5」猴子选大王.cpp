#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
int m, n;

inline void input() {
    cin >> m >> n;
}

inline void solve() {
    int f = 0;
    for (int i = 2; i <= m; i++) {
        f = (f + n) % i;
    }
    cout << f + 1 << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
