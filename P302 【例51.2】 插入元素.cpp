#include <bits/stdc++.h>
using namespace std;

const int N = 2e1 + 5;

int n, a[N], x, y;

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> x >> y;
}

inline void solve() {
    for (int i = n; i >= x; i--) {
        a[i + 1] = a[i];
    }
    a[x] = y;
    for (int i = 1; i <= n + 1; i++) {
        cout << a[i] << (i == n + 1 ? "\n" : " ");
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
