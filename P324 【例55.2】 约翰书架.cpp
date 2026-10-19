#include <bits/stdc++.h>
using namespace std;

const int N = 2e4 + 5;

int n, b, a[N], ans;
long long s;

inline void input() {
    cin >> n >> b;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
}

inline void solve() {
    sort(a + 1, a + n + 1, greater<int>());
    for (int i = 1; i <= n && s < b; i++) {
        s += a[i], ans++;
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
