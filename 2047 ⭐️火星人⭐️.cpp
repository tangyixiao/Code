#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;

int n, m, a[N];

inline void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
}

inline void solve() {
    for (int i = 1; i <= m; i++) {
        next_permutation(a + 1, a + n + 1);
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << (i == n ? "\n" : " ");
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
