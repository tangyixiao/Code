#include <bits/stdc++.h>
using namespace std;

const int N = 3e2 + 5;

int n, a[N], b[N], x, y;

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    cin >> x >> y;
}

inline void solve() {
    int m = 0;
    for (int i = 1; i <= n; i++) {
        a[++m] = b[i];
        if (i == x) {
            a[++m] = y;
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << a[i] << (i == m ? "\n" : " ");
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
