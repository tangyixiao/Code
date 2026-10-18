#include <bits/stdc++.h>
using namespace std;

int n;
long long a, s = 0, ans;

inline void input() {
    cin >> n;
}

inline void solve() {
    for (int i = 1; i <= n; i++) {
        cin >> a;
        s = max(a, s + a), ans = max(ans, s);
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
