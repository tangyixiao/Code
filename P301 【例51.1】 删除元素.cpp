#include <bits/stdc++.h>
using namespace std;

const int N = 1e1 + 5;

int n, a[N], x;

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> x;
}

inline void solve() {
    for (int i = x; i < n; i++) {
        a[i] = a[i + 1];
    }
    for (int i = 1; i < n; i++) {
        cout << a[i] << (i == n - 1 ? "\n" : " ");
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
