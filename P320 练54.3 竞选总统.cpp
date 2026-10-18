#include <bits/stdc++.h>
using namespace std;

const int N = 2e2 + 5;

int n, a[N], ans;

inline void input() {
    while (cin >> n, n) {
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        ans = 0;
        for (int i = 1; i <= n / 2 + 1; i++) {
            ans += a[i] / 2 + 1;
        }
        cout << ans << "\n";
    }
}

inline void solve() {
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
