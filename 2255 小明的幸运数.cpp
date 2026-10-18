#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int k, l, r;

inline void input() {
    cin >> k >> l >> r;
}

inline void solve() {
    input();
    long long ans = 0;
    for (int i = l; i <= r; i++) {
        if (i % 10 == k || i % k == 0) {
            ans += i;
        }
    }
    cout << ans << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}