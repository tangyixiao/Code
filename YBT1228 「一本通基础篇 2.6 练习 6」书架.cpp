#include <bits/stdc++.h>
using namespace std;

const int N = 2e4 + 5;

int a[N], n, b;

inline void input() {
    cin >> n >> b;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    return;
}

inline void solve() {
    sort(a, a + n);
    int s = 0;
    for (int i = n - 1; i >= 0; --i) {
        s += a[i];
        if (s >= b) {
            cout << n - i << "\n";
            return;
        }
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
