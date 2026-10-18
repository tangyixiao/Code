#include <bits/stdc++.h>
using namespace std;

#define int long long
int b, p, k;

inline void input() {
    cin >> b >> p >> k;
    return;
}

inline void solve() {
    int ans = 1 % k, x = b % k, e = p;
    for (; e; e >>= 1) {
        if (e & 1) {
            ans = ans * x % k;
        }
        x = x * x % k;
    }
    cout << b << "^" << p << " mod " << k << "=" << ans << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}