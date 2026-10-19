#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int n, a[N];
long long ans;

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
}

inline void solve() {
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i += 2) {
        ans += a[i + 1] - a[i];
    }
    cout << ans << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
