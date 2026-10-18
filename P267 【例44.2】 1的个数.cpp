#include <bits/stdc++.h>
using namespace std;

long long n;

inline void input() {
    cin >> n;
}

inline void solve() {
    int ans = 0;
    for (; n; n >>= 1) {
        ans += n & 1;
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
