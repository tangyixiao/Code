#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int l, r, ans;

inline void input() {
    cin >> l >> r;
}

inline void solve() {
    for (int i = l; i <= r; i++) {
        for (int x = i; x; x /= 10) {
            if (x % 10 == 7) {
                ans++;
            }
        }
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
